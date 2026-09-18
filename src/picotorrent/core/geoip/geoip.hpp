#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <filesystem>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

#include "maxminddatabase.hpp"

namespace pt
{
namespace Core
{
    class Configuration;
    class Environment;

    // Country lookups for peer addresses, backed by the free DB-IP Lite country
    // database (CC BY 4.0 - attributed in the about dialog). The database lives
    // in the application data folder and is refreshed on startup once it is a
    // month old; lookups keep using the old file until the new one is in place.
    //
    // Create and use on the UI thread. Only the download runs elsewhere.
    class GeoIP : public wxEvtHandler
    {
    public:
        GeoIP(std::shared_ptr<Environment> env, std::shared_ptr<Configuration> cfg);
        virtual ~GeoIP();

        // Empty when GeoIP is disabled, no database has been downloaded yet or
        // the address is unknown to it.
        std::string LookupCountryCode(sockaddr const* address) const;

    private:
        void Update();
        int Download(wchar_t const* url, std::string& body);
        bool IsCancelled();

        std::filesystem::path m_databaseFile;
        MaxMindDatabase m_db;

        std::thread m_updater;
        std::mutex m_mutex;
        void* m_request = nullptr; // HINTERNET of the running download
        bool m_cancelled = false;
    };
}
}
