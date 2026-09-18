#pragma once

#include <filesystem>
#include <string>

struct MMDB_s;
struct sockaddr;

namespace pt
{
namespace Core
{
    // Thin wrapper around libmaxminddb, reading the country of an address from
    // a MaxMind DB (.mmdb) file - the format both MaxMind and DB-IP publish.
    class MaxMindDatabase
    {
    public:
        MaxMindDatabase();
        ~MaxMindDatabase();

        MaxMindDatabase(MaxMindDatabase const&) = delete;
        MaxMindDatabase& operator=(MaxMindDatabase const&) = delete;

        bool Open(std::filesystem::path const& databaseFile);
        void Close();

        // Returns the ISO 3166-1 alpha-2 country code, or an empty string when
        // no database is open or it has no entry for the address.
        std::string LookupCountryCode(sockaddr const* address) const;

        static char const* LibraryVersion();

    private:
        MMDB_s* m_db;
        bool m_isOpen = false;
    };
}
}
