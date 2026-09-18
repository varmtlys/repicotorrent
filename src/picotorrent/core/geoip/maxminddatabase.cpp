#include "maxminddatabase.hpp"

#include <boost/log/trivial.hpp>
#include <maxminddb/maxminddb.h>

#include "../utils.hpp"

namespace fs = std::filesystem;
using pt::Core::MaxMindDatabase;

MaxMindDatabase::MaxMindDatabase()
    : m_db(new MMDB_s())
{
}

MaxMindDatabase::~MaxMindDatabase()
{
    Close();
    delete m_db;
}

bool MaxMindDatabase::Open(fs::path const& databaseFile)
{
    Close();

    // libmaxminddb converts the path from UTF-8 and opens it with CreateFileW,
    // so non-ASCII profile folders work.
    std::string path = Utils::toStdString(databaseFile.wstring());

    int res = MMDB_open(path.c_str(), MMDB_MODE_MMAP, m_db);

    if (res != MMDB_SUCCESS)
    {
        BOOST_LOG_TRIVIAL(warning) << "Failed to open GeoIP database " << path << ": " << MMDB_strerror(res);
        return false;
    }

    m_isOpen = true;

    return true;
}

void MaxMindDatabase::Close()
{
    if (!m_isOpen)
    {
        return;
    }

    MMDB_close(m_db);
    m_isOpen = false;
}

std::string MaxMindDatabase::LookupCountryCode(sockaddr const* address) const
{
    if (!m_isOpen || address == nullptr)
    {
        return std::string();
    }

    // Looking up the socket address directly skips the string round-trip and
    // the getaddrinfo() call MMDB_lookup_string makes.
    int mmdbError = MMDB_SUCCESS;
    MMDB_lookup_result_s result = MMDB_lookup_sockaddr(m_db, address, &mmdbError);

    if (mmdbError != MMDB_SUCCESS || !result.found_entry)
    {
        return std::string();
    }

    MMDB_entry_data_s data;

    if (MMDB_get_value(&result.entry, &data, "country", "iso_code", nullptr) != MMDB_SUCCESS
        || !data.has_data
        || data.type != MMDB_DATA_TYPE_UTF8_STRING)
    {
        return std::string();
    }

    return std::string(data.utf8_string, data.data_size);
}

char const* MaxMindDatabase::LibraryVersion()
{
    return MMDB_lib_version();
}
