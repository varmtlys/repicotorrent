#include "crashpadinitializer.hpp"

#include <filesystem>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include <Windows.h>
#include <CommCtrl.h>

#include <boost/log/trivial.hpp>

#ifndef PICO_NO_CRASHPAD
#pragma warning(push)
#pragma warning(disable: 4100)
#include <client/crash_report_database.h>
#include <client/settings.h>
#include <client/crashpad_client.h>
#pragma warning(pop)
#endif

#include "buildinfo.hpp"
#include "core/environment.hpp"
#include "core/utils.hpp"

namespace fs = std::filesystem;
using pt::CrashpadInitializer;

#ifdef PICO_NO_CRASHPAD
void CrashpadInitializer::Initialize(std::shared_ptr<pt::Core::Environment>)
{
    BOOST_LOG_TRIVIAL(info) << "Built without Crashpad, crash dumps are not written";
}
#else
void CrashpadInitializer::Initialize(std::shared_ptr<pt::Core::Environment> env)
{
    auto databasePath = env->GetApplicationDataPath() / "Crashpad" / "db";
    auto handlerPath = env->GetApplicationPath() / "crashpad_handler.exe";

    BOOST_LOG_TRIVIAL(info) << "Initializing Crashpad (path: " << handlerPath << ", url: " << env->GetCrashpadReportUrl() << ")";

    if (!fs::exists(handlerPath))
    {
        BOOST_LOG_TRIVIAL(warning) << "Could not find crashpad_handler.exe, skipping initialization...";
        return;
    }

    std::error_code ec;
    bool exists = fs::exists(databasePath, ec);

    if (ec)
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to check if database path exists: " << ec;
        return;
    }

    if (!exists)
    {
        fs::create_directories(databasePath, ec);

        if (ec)
        {
            BOOST_LOG_TRIVIAL(error) << "Failed to create Crashpad database directories: " << ec;
            return;
        }
    }

    auto database = crashpad::CrashReportDatabase::Initialize(base::FilePath(databasePath.wstring()));

    if (database == nullptr || database->GetSettings() == nullptr)
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to initialize Crashpad database from path: " << databasePath;
        return;
    }

    // Dumps are always written locally; they are only uploaded when a
    // report URL is configured.
    if (!database->GetSettings()->SetUploadsEnabled(!env->GetCrashpadReportUrl().empty()))
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to set uploads in Crashpad database";
        return;
    }

    std::string environment = "Production";
    std::string release = "RePicoTorrent-" + std::string(pt::BuildInfo::version());

    if (strcmp(pt::BuildInfo::branch(), "master") != 0)
    {
        environment = "Experimental";
        release = "";
    }

    crashpad::CrashpadClient client;
    if (!client.StartHandler(base::FilePath(handlerPath.wstring()),
        base::FilePath(databasePath.wstring()),
        base::FilePath(databasePath.wstring()),
        env->GetCrashpadReportUrl(),
        // annotations
        {
            { "branch",              pt::BuildInfo::branch() },
            { "commitish",           pt::BuildInfo::commitish() },
            { "version",             pt::BuildInfo::semver() },
            { "sentry[environment]", environment },
            { "sentry[release]",     release },
        },
        {
#if _DEBUG
            "--no-rate-limit"
#endif
        },
        true,
        true))
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to start Crashpad";
        return;
    }

    if (!client.WaitForHandlerStart(10000))
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to wait for Crashpad handler start";
        return;
    }

    BOOST_LOG_TRIVIAL(info) << "Crashpad handler started";
}
#endif
