#include "updateinstaller.hpp"

#include <filesystem>
#include <memory>
#include <sstream>
#include <vector>

#include <boost/log/trivial.hpp>
#include <fmt/format.h>
#include <fmt/xchar.h>
#include <libtorrent/hasher.hpp>
#include <wx/mstream.h>
#include <wx/utils.h>
#include <wx/wfstream.h>
#include <wx/wx.h>
#include <wx/zipstrm.h>

#include "http/httpclient.hpp"
#include "ui/translator.hpp"

namespace fs = std::filesystem;
using pt::UpdateInstaller;

static fs::path AppDir()
{
    wchar_t exe[MAX_PATH];
    GetModuleFileNameW(nullptr, exe, MAX_PATH);
    return fs::path(exe).parent_path();
}

static void Fail(wxFrame* frame, std::string const& reason)
{
    BOOST_LOG_TRIVIAL(error) << "Update failed: " << reason;

    wxMessageBox(
        fmt::format(i18n("update_failed"), wxString::FromUTF8(reason).ToStdWstring()),
        "RePicoTorrent",
        wxOK | wxICON_ERROR,
        frame);
}

// Writes every file of the zip's top folder as <app dir>/<file>.new, then
// swaps them in: the current file becomes <file>.old (a running exe or a
// loaded DLL can be renamed, not overwritten). Returns an error or "".
static std::string Apply(std::string const& zipData)
{
    fs::path const dir = AppDir();

    wxMemoryInputStream mem(zipData.data(), zipData.size());
    wxZipInputStream zip(mem);
    std::vector<fs::path> files;

    for (std::unique_ptr<wxZipEntry> entry(zip.GetNextEntry()); entry; entry.reset(zip.GetNextEntry()))
    {
        if (entry->IsDir()) { continue; }

        // RePicoTorrent-<version>-<arch>/<file> -> <file>
        fs::path name(entry->GetName(wxPATH_UNIX).ToStdWstring());
        fs::path rel;

        for (auto it = std::next(name.begin()); it != name.end(); ++it) { rel /= *it; }

        if (rel.empty()) { continue; }

        for (auto const& part : rel)
        {
            if (part == "..") { return "unexpected path in the archive: " + name.u8string(); }
        }

        fs::path target = dir / rel;
        std::error_code ec;
        fs::create_directories(target.parent_path(), ec);

        wxFileOutputStream out(target.wstring() + L".new");

        if (!out.IsOk() || !out.Write(zip).IsOk() || !out.Close())
        {
            return "could not write " + target.u8string() + ".new";
        }

        files.push_back(target);
    }

    if (files.empty()) { return "the archive is empty"; }

    for (auto const& target : files)
    {
        std::error_code ec;
        fs::path old = target.wstring() + L".old";

        fs::remove(old, ec);
        if (fs::exists(target)) { fs::rename(target, old, ec); }
        if (!ec) { fs::rename(target.wstring() + L".new", target, ec); }
        if (ec) { return "could not replace " + target.u8string() + ": " + ec.message(); }
    }

    return {};
}

void UpdateInstaller::Install(wxFrame* frame, std::string const& zipUrl, std::string const& sumsUrl)
{
    BOOST_LOG_TRIVIAL(info) << "Installing update from " << zipUrl;

    std::string const zipName = zipUrl.substr(zipUrl.find_last_of('/') + 1);
    // Outlives the requests: a client released from inside its own
    // response callback would be destroyed while handling that event.
    static Http::HttpClient* http = new Http::HttpClient();

    wxBeginBusyCursor();

    http->Get(sumsUrl, [=](int status, std::string const& sums)
    {
        std::string expected = FindChecksum(sums, zipName);

        if (status != 200 || expected.empty())
        {
            wxEndBusyCursor();
            return Fail(frame, "no checksum for " + zipName);
        }

        http->Get(zipUrl, [=](int status, std::string const& zipData)
        {
            wxEndBusyCursor();

            if (status != 200 || zipData.empty())
            {
                return Fail(frame, "download failed (HTTP " + std::to_string(status) + ")");
            }

            libtorrent::hasher256 hasher;
            hasher.update(zipData.data(), static_cast<int>(zipData.size()));
            std::stringstream actual;
            actual << hasher.final();

            if (actual.str() != expected)
            {
                return Fail(frame, "checksum mismatch for " + zipName);
            }

            if (std::string error = Apply(zipData); !error.empty())
            {
                return Fail(frame, error);
            }

            BOOST_LOG_TRIVIAL(info) << "Update installed, restarting";

            // The new instance waits for this one to save its state and exit.
            wchar_t exe[MAX_PATH];
            GetModuleFileNameW(nullptr, exe, MAX_PATH);
            wxExecute(fmt::format(L"\"{}\" --wait-for-pid={}", exe, GetCurrentProcessId()), wxEXEC_ASYNC);

            frame->Close(true);
        });
    });
}

void UpdateInstaller::CleanUp()
{
    std::error_code ec;

    for (auto const& entry : fs::directory_iterator(AppDir(), ec))
    {
        if (entry.path().extension() == ".old" || entry.path().extension() == ".new")
        {
            fs::remove(entry.path(), ec);
        }
    }
}
