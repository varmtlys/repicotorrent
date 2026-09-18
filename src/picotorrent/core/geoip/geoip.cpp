#include "geoip.hpp"

#include <chrono>
#include <cstdio>
#include <ctime>
#include <system_error>
#include <vector>

#include <Windows.h>
#include <winhttp.h>

#include <boost/log/trivial.hpp>
#include <wx/mstream.h>
#include <wx/wfstream.h>
#include <wx/zstream.h>

#include "../configuration.hpp"
#include "../environment.hpp"

namespace fs = std::filesystem;
using pt::Core::GeoIP;

static auto const MaxDatabaseAge = std::chrono::hours(24 * 30);

// Both come off the network. The real files are ~4 MB compressed, ~8 MB not.
static std::size_t const MaxDownloadSize = 64 * 1024 * 1024;
static std::size_t const MaxDatabaseSize = 256 * 1024 * 1024;

// Inflates a .gz download into target. Refuses anything that expands past
// MaxDatabaseSize rather than filling the disk.
static bool Gunzip(std::string const& input, fs::path const& target)
{
    wxMemoryInputStream compressed(input.data(), input.size());
    wxZlibInputStream gzip(compressed, wxZLIB_GZIP);
    wxFileOutputStream out(target.wstring());

    if (!gzip.IsOk() || !out.IsOk())
    {
        return false;
    }

    std::vector<char> buffer(64 * 1024);
    std::size_t total = 0;

    while (true)
    {
        gzip.Read(buffer.data(), buffer.size());

        std::size_t read = gzip.LastRead();

        if (read == 0)
        {
            break;
        }

        total += read;

        if (total > MaxDatabaseSize || !out.WriteAll(buffer.data(), read))
        {
            return false;
        }
    }

    // Stopping anywhere but the end of the stream is a corrupt download.
    return gzip.GetLastError() == wxSTREAM_EOF && out.Close();
}

GeoIP::GeoIP(std::shared_ptr<pt::Core::Environment> env, std::shared_ptr<pt::Core::Configuration> cfg)
    : m_databaseFile(env->GetApplicationDataPath() / "dbip-country-lite.mmdb")
{
    if (!cfg->Get<bool>("geoip.enabled").value_or(true))
    {
        return;
    }

    std::error_code ec;
    bool exists = fs::exists(m_databaseFile, ec);

    if (exists)
    {
        m_db.Open(m_databaseFile);
    }

    bool stale = !exists
        || fs::last_write_time(m_databaseFile, ec) + MaxDatabaseAge < fs::file_time_type::clock::now();

    if (stale)
    {
        m_updater = std::thread(&GeoIP::Update, this);
    }
}

GeoIP::~GeoIP()
{
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_cancelled = true;

        // Closing the request handle aborts the blocking WinHTTP call on the
        // updater thread, so exiting never waits on a slow download.
        if (m_request != nullptr)
        {
            WinHttpCloseHandle(m_request);
            m_request = nullptr;
        }
    }

    if (m_updater.joinable())
    {
        m_updater.join();
    }
}

std::string GeoIP::LookupCountryCode(sockaddr const* address) const
{
    return m_db.LookupCountryCode(address);
}

bool GeoIP::IsCancelled()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_cancelled;
}

void GeoIP::Update()
{
    // Runs on m_updater. It only touches the network and the temporary file;
    // the database swap is handed back to the UI thread with CallAfter. The
    // destructor joins this thread before wxEvtHandler drops pending calls,
    // so a CallAfter never reaches a destroyed object.

    std::time_t now = std::time(nullptr);
    std::tm utc = {};
    gmtime_s(&utc, &now);

    std::string body;
    int status = 0;

    // Early on the first of the month the new file may not be published yet,
    // so fall back to last month's.
    for (int monthsBack = 0; monthsBack < 2 && status != 200 && !IsCancelled(); monthsBack++)
    {
        int year = utc.tm_year + 1900;
        int month = utc.tm_mon + 1 - monthsBack;

        if (month < 1)
        {
            month += 12;
            year -= 1;
        }

        // DB-IP publishes the free country database on the first of every month.
        wchar_t url[128];
        swprintf_s(url, L"https://download.db-ip.com/free/dbip-country-lite-%04d-%02d.mmdb.gz", year, month);

        body.clear();
        status = Download(url, body);
    }

    if (IsCancelled())
    {
        return;
    }

    if (status != 200)
    {
        BOOST_LOG_TRIVIAL(warning) << "Failed to download GeoIP database (HTTP " << status << ")";
        return;
    }

    fs::path tmp = m_databaseFile;
    tmp += ".tmp";

    std::error_code ec;

    if (!Gunzip(body, tmp))
    {
        BOOST_LOG_TRIVIAL(warning) << "Failed to decompress GeoIP database";
        fs::remove(tmp, ec);
        return;
    }

    // Never replace a working database with one libmaxminddb cannot read.
    {
        MaxMindDatabase check;

        if (!check.Open(tmp))
        {
            fs::remove(tmp, ec);
            return;
        }
    }

    this->CallAfter([this, tmp]()
        {
            // The open database is memory mapped, and Windows refuses to
            // replace a mapped file - close it first. Lookups only happen on
            // this (the UI) thread, so nothing reads it in between.
            m_db.Close();

            std::error_code renameError;
            fs::rename(tmp, m_databaseFile, renameError);

            if (renameError)
            {
                BOOST_LOG_TRIVIAL(warning) << "Failed to replace GeoIP database: " << renameError.message();
            }

            if (m_db.Open(m_databaseFile))
            {
                BOOST_LOG_TRIVIAL(info) << "GeoIP database updated";
            }
        });
}

int GeoIP::Download(wchar_t const* url, std::string& body)
{
    URL_COMPONENTS uc = { sizeof(URL_COMPONENTS) };
    uc.dwHostNameLength = DWORD(-1);
    uc.dwUrlPathLength = DWORD(-1);

    if (!WinHttpCrackUrl(url, 0, 0, &uc))
    {
        return 0;
    }

    std::wstring host(uc.lpszHostName, uc.dwHostNameLength);
    std::wstring path(uc.lpszUrlPath, uc.dwUrlPathLength);

    HINTERNET session = WinHttpOpen(
        L"PicoTorrent",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS,
        0);

    if (session == nullptr)
    {
        return 0;
    }

    // Resolve, connect, send, receive. Bounds a stalled connection even if
    // closing the handle from the destructor does not interrupt it.
    WinHttpSetTimeouts(session, 10000, 10000, 10000, 15000);

    HINTERNET connect = WinHttpConnect(session, host.c_str(), uc.nPort, 0);

    HINTERNET request = connect == nullptr
        ? nullptr
        : WinHttpOpenRequest(
            connect,
            L"GET",
            path.c_str(),
            nullptr,
            WINHTTP_NO_REFERER,
            WINHTTP_DEFAULT_ACCEPT_TYPES,
            WINHTTP_FLAG_SECURE);

    // Publish the request so the destructor can abort it.
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        if (m_cancelled && request != nullptr)
        {
            WinHttpCloseHandle(request);
            request = nullptr;
        }

        m_request = request;
    }

    int status = 0;

    if (request != nullptr
        && WinHttpSendRequest(request, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)
        && WinHttpReceiveResponse(request, nullptr))
    {
        DWORD code = 0;
        DWORD codeSize = sizeof(code);

        WinHttpQueryHeaders(
            request,
            WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
            WINHTTP_HEADER_NAME_BY_INDEX,
            &code,
            &codeSize,
            WINHTTP_NO_HEADER_INDEX);

        status = static_cast<int>(code);

        DWORD available = 0;

        while (status == 200
            && WinHttpQueryDataAvailable(request, &available)
            && available > 0)
        {
            if (body.size() + available > MaxDownloadSize)
            {
                status = 0;
                break;
            }

            std::size_t offset = body.size();
            body.resize(offset + available);

            DWORD read = 0;

            if (!WinHttpReadData(request, &body[offset], available, &read))
            {
                status = 0;
                break;
            }

            body.resize(offset + read);
        }
    }

    {
        // The destructor may already have closed it to abort us.
        std::lock_guard<std::mutex> lock(m_mutex);

        if (m_request != nullptr)
        {
            WinHttpCloseHandle(m_request);
            m_request = nullptr;
        }
    }

    if (connect != nullptr)
    {
        WinHttpCloseHandle(connect);
    }

    WinHttpCloseHandle(session);

    return status;
}
