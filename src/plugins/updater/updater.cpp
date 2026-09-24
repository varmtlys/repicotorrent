#include <libpico.h>

#include <cstring>
#include <string>
#include <Windows.h>
#include <CommCtrl.h>
#include <shellapi.h>

#include "versioncompare.hpp"

#pragma warning(push)
#pragma warning(disable: 4200)
#pragma warning(disable: 4996)
#include "sajson.h"
#pragma warning(pop)

#define DEFAULT_I18N_BUFFER_SIZE 256

struct updater_request_data_t
{
    bool force;
    libpico_config_t* config;
    libpico_mainwnd_t* wnd;
};

// The release zip for this build's architecture.
#if defined(_M_ARM64)
#define UPDATER_ASSET_SUFFIX "-arm64.zip"
#elif defined(_M_X64)
#define UPDATER_ASSET_SUFFIX "-x64.zip"
#else
#define UPDATER_ASSET_SUFFIX "-x86.zip"
#endif

void show_available_update(libpico_mainwnd_t* wnd, libpico_config_t* config, const char* version, const char* url, std::string const& zipUrl, std::string const& sumsUrl)
{
    HWND hWnd = nullptr;
    libpico_mainwnd_native_handle(wnd, reinterpret_cast<void**>(&hWnd));

    // get wide version
    wchar_t versionw[100];
    libpico_string_towide(version, versionw, 100);

    wchar_t content[DEFAULT_I18N_BUFFER_SIZE];
    size_t content_len = DEFAULT_I18N_BUFFER_SIZE;
    libpico_i18n("new_version_available", content, &content_len);

    wchar_t main[DEFAULT_I18N_BUFFER_SIZE];
    wchar_t main_format[DEFAULT_I18N_BUFFER_SIZE];
    size_t main_len = DEFAULT_I18N_BUFFER_SIZE;
    libpico_i18n("picotorrent_v_available", main, &main_len);
    swprintf(main_format, DEFAULT_I18N_BUFFER_SIZE, main, versionw);

    wchar_t verification[DEFAULT_I18N_BUFFER_SIZE];
    size_t verification_len = DEFAULT_I18N_BUFFER_SIZE;
    libpico_i18n("ignore_update", verification, &verification_len);

    wchar_t show[DEFAULT_I18N_BUFFER_SIZE];
    size_t show_len = DEFAULT_I18N_BUFFER_SIZE;
    libpico_i18n("show_on_github", show, &show_len);

    wchar_t install[DEFAULT_I18N_BUFFER_SIZE];
    size_t install_len = DEFAULT_I18N_BUFFER_SIZE;
    libpico_i18n("update_install", install, &install_len);

    // Installing needs the zip for this architecture and the checksums
    // to verify it; otherwise only the release page is offered.
    bool canInstall = !zipUrl.empty() && !sumsUrl.empty();

    const TASKDIALOG_BUTTON pButtons[] =
    {
        { 1001, install },
        { 1000, show },
    };

    TASKDIALOGCONFIG tdf = { sizeof(TASKDIALOGCONFIG) };
    tdf.cButtons = canInstall ? 2 : 1;
    tdf.pszContent = content;
    tdf.dwCommonButtons = TDCBF_CLOSE_BUTTON;
    tdf.dwFlags = TDF_POSITION_RELATIVE_TO_WINDOW | TDF_USE_COMMAND_LINKS;
    tdf.hwndParent = hWnd;
    tdf.pButtons = canInstall ? pButtons : pButtons + 1;
    tdf.pszMainIcon = TD_INFORMATION_ICON;
    tdf.pszMainInstruction = main_format;
    tdf.pszVerificationText = verification;
    tdf.pszWindowTitle = TEXT("RePicoTorrent");

    int pnButton = -1;
    int pnRadioButton = -1;
    BOOL pfVerificationFlagChecked = FALSE;

    TaskDialogIndirect(&tdf, &pnButton, &pnRadioButton, &pfVerificationFlagChecked);

    if (pnButton == 1001)
    {
        libpico_update_install(wnd, zipUrl.c_str(), sumsUrl.c_str());
    }
    else if (pnButton == 1000)
    {
        wchar_t urlw[255];
        libpico_string_towide(url, urlw, 255);

        SHELLEXECUTEINFO sei;
        ZeroMemory(&sei, sizeof(SHELLEXECUTEINFO));

        sei.cbSize = sizeof(SHELLEXECUTEINFO);
        sei.lpFile = urlw;
        sei.lpVerb = TEXT("open");
        sei.nShow = SW_SHOWNORMAL;
        sei.fMask = SEE_MASK_FLAG_NO_UI;

        ::ShellExecuteEx(&sei);
    }

    if (pfVerificationFlagChecked)
    {
        libpico_config_string_set(
            config,
            "update_checks.ignored_version",
            version,
            (size_t)-1);
    }
}

void show_no_update(libpico_mainwnd_t* wnd)
{
    HWND hWnd = nullptr;
    libpico_mainwnd_native_handle(wnd, reinterpret_cast<void**>(&hWnd));

    wchar_t main[DEFAULT_I18N_BUFFER_SIZE];
    size_t main_len = DEFAULT_I18N_BUFFER_SIZE;
    libpico_i18n("no_update_available", main, &main_len);

    TASKDIALOGCONFIG tdf = { sizeof(TASKDIALOGCONFIG) };
    tdf.dwCommonButtons = TDCBF_OK_BUTTON;
    tdf.dwFlags = TDF_POSITION_RELATIVE_TO_WINDOW;
    tdf.hwndParent = hWnd;
    tdf.pszMainIcon = TD_INFORMATION_ICON;
    tdf.pszMainInstruction = main;
    tdf.pszWindowTitle = L"RePicoTorrent";

    TaskDialogIndirect(&tdf, nullptr, nullptr, nullptr);
}

libpico_result_t parse_response(
    libpico_http_response_t* response,
    libpico_http_status_t status,
    libpico_param_t* user)
{
    updater_request_data_t* data = reinterpret_cast<updater_request_data_t*>(user);

    switch (status)
    {
    case libpico_http_ok:
    {
        size_t len;
        libpico_http_response_body_len(response, &len);

        if (len > 0)
        {
            std::string body(len, '\0');
            libpico_http_response_body(response, body.data(), body.size());

            const sajson::document& doc = sajson::parse(
                sajson::dynamic_allocation(),
                sajson::mutable_string_view(body.size(), body.data()));

            if (!doc.is_valid())
            {
                // TODO: log
                break;
            }

            const sajson::value& root = doc.get_root();

            auto str = [&root](const char* key)
            {
                sajson::value v = root.get_value_of_key(sajson::string(key, strlen(key)));
                return v.get_type() == sajson::TYPE_STRING ? v.as_string() : std::string();
            };

            // Either {version, url} or a GitHub latest release
            // ({tag_name: "vX.Y.Z", html_url}).
            std::string version = str("version");
            std::string url = str("url");

            if (version.empty())
            {
                version = str("tag_name");
                url = str("html_url");
                if (!version.empty() && version[0] == 'v') { version.erase(0, 1); }
            }

            if (version.empty())
            {
                break;
            }

            std::string zipUrl;
            std::string sumsUrl;
            sajson::value assets = root.get_value_of_key(sajson::literal("assets"));

            if (assets.get_type() == sajson::TYPE_ARRAY)
            {
                std::string const suffix = UPDATER_ASSET_SUFFIX;

                for (size_t i = 0; i < assets.get_length(); i++)
                {
                    sajson::value asset = assets.get_array_element(i);
                    if (asset.get_type() != sajson::TYPE_OBJECT) { continue; }

                    sajson::value name = asset.get_value_of_key(sajson::literal("name"));
                    sajson::value link = asset.get_value_of_key(sajson::literal("browser_download_url"));
                    if (name.get_type() != sajson::TYPE_STRING || link.get_type() != sajson::TYPE_STRING) { continue; }

                    std::string n = name.as_string();

                    if (n == "SHA256SUMS.txt")
                    {
                        sumsUrl = link.as_string();
                    }
                    else if (n.size() > suffix.size() && n.compare(n.size() - suffix.size(), suffix.size(), suffix) == 0)
                    {
                        zipUrl = link.as_string();
                    }
                }
            }

            char ignoredVersion[100];
            size_t ignoredVersionLen = 100;

            libpico_config_string_get(
                data->config,
                "update_checks.ignored_version",
                ignoredVersion,
                &ignoredVersionLen);

            if (version == std::string(ignoredVersion, ignoredVersionLen) && !data->force)
            {
                break;
            }

            if (pt::Updater::isNewer(version, libpico_version()))
            {
                show_available_update(
                    data->wnd,
                    data->config,
                    version.c_str(),
                    url.c_str(),
                    zipUrl,
                    sumsUrl);
            }
            else if (data->force)
            {
                show_no_update(data->wnd);
            }
        }
        break;
    }
    }

    return libpico_ok;
}

void make_request(libpico_config_t* config, libpico_mainwnd_t* wnd, bool force)
{
    updater_request_data_t* data = new updater_request_data_t();
    data->config = config;
    data->force = force;
    data->wnd = wnd;

    char url[255];
    size_t url_len = 255;

    libpico_config_string_get(config, "update_checks.url", url, &url_len);
    libpico_http_get(url, parse_response, reinterpret_cast<libpico_param_t*>(data));
}

libpico_result_t check(libpico_menuitem_t* item, libpico_param_t* param)
{
    updater_request_data_t* data = reinterpret_cast<updater_request_data_t*>(param);
    make_request(data->config, data->wnd, data->force);
    return libpico_ok;
}

libpico_result_t on_events(
    libpico_event_t event,
    libpico_param_t* param,
    libpico_param_t* user)
{
    libpico_plugin_t* plugin = reinterpret_cast<libpico_plugin_t*>(user);

    switch (event)
    {
    case libpico_event_mainwnd_created:
    {
        libpico_config_t* config = nullptr;
        libpico_config_get(plugin, &config);

        bool enabled = false;
        libpico_config_bool_get(config, "update_checks.enabled", &enabled);

        if (enabled)
        {
            make_request(
                config,
                reinterpret_cast<libpico_mainwnd_t*>(param),
                false);
        }

        // Insert item in about menu to force a check for update
        libpico_menu_t* help;
        libpico_menu_get(reinterpret_cast<libpico_mainwnd_t*>(param), libpico_menu_help, &help);

        wchar_t check_for_update[DEFAULT_I18N_BUFFER_SIZE];
        size_t check_for_update_len = DEFAULT_I18N_BUFFER_SIZE;
        libpico_i18n("amp_check_for_update", check_for_update, &check_for_update_len);

        updater_request_data_t* data = new updater_request_data_t();
        data->config = config;
        data->force = true;
        data->wnd = reinterpret_cast<libpico_mainwnd_t*>(param);

        libpico_menu_insert_item(
            help,
            0,
            check_for_update,
            check_for_update_len,
            check,
            reinterpret_cast<libpico_param_t*>(data),
            nullptr);

        libpico_menu_insert_separator(
            help,
            1);

        break;
    }
    }

    return libpico_ok;
}

libpico_result_t init_updater(int version, libpico_plugin_t* plugin)
{
    if (version != LIBPICO_API_VERSION)
    {
        return libpico_version_mismatch;
    }

    return libpico_register_hook(plugin, on_events, reinterpret_cast<libpico_param_t*>(plugin));
}

LIBPICO_DEFINE_PLUGIN(
    "updater",
    "1.0",
    init_updater);
