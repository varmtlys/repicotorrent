#include "preferencesgeneralpage.hpp"

#include <Shlwapi.h>
#include <ShlObj.h>
#include <shellapi.h>
#include <strsafe.h>

#include <vector>

#include <boost/log/trivial.hpp>

#include "../clientdata.hpp"
#include "../../core/configuration.hpp"
#include "../../core/utils.hpp"
#include "../translator.hpp"

struct AutoRunKey
{
    AutoRunKey()
    {
        RegCreateKeyEx(
            HKEY_CURRENT_USER,
            TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"),
            0,
            NULL,
            0,
            KEY_READ | KEY_WRITE,
            NULL,
            &m_key,
            NULL);
    }

    void Create()
    {
        TCHAR path[MAX_PATH];
        TCHAR quoted[MAX_PATH];
        GetModuleFileName(NULL, path, ARRAYSIZE(path));
        StringCchPrintf(quoted, ARRAYSIZE(quoted), L"\"%s\"", path);

        std::wstring p(quoted);

        UINT res = RegSetValueEx(
            m_key,
            L"RePicoTorrent",
            0,
            REG_SZ,
            (const BYTE*)p.c_str(),
            (DWORD)((p.size() + 1) * sizeof(wchar_t)));

        if (res != ERROR_SUCCESS)
        {
            BOOST_LOG_TRIVIAL(warning) << "RePicoTorrent could not be registered to run at start-up. Error: " << GetLastError();
        }
    }

    void Delete()
    {
        RegDeleteValue(
            m_key,
            TEXT("RePicoTorrent"));
    }

    bool Exists()
    {
        return RegQueryValueEx(
            m_key,
            TEXT("RePicoTorrent"),
            NULL,
            NULL,
            NULL,
            NULL) == ERROR_SUCCESS;;
    }

    ~AutoRunKey()
    {
        if (m_key != NULL)
        {
            RegCloseKey(m_key);
        }
    }

private:
    HKEY m_key;
};

// Per-user registration (HKCU, no admin) of .torrent files or magnet links.
// It makes Windows list RePicoTorrent in "Open with" and in Default apps; it
// becomes the default only while the user has not picked another program
// there - Windows does not let programs take a picked default over.
struct Association
{
    // ext: ".torrent" or "magnet"
    explicit Association(std::wstring ext)
        : m_ext(std::move(ext)),
        m_isProtocol(m_ext == L"magnet"),
        m_progId(m_isProtocol ? L"RePicoTorrent.magnet" : L"RePicoTorrent.torrent")
    {
        wchar_t exe[MAX_PATH];
        GetModuleFileName(NULL, exe, ARRAYSIZE(exe));
        m_exe = exe;
    }

    // Whether Windows opens them with this copy of the program.
    bool IsDefault()
    {
        wchar_t exe[MAX_PATH];
        DWORD size = ARRAYSIZE(exe);

        // 0x1000 is ASSOCF_IS_PROTOCOL (Windows 8), hidden by our _WIN32_WINNT.
        return AssocQueryString(m_isProtocol ? 0x1000 : ASSOCF_NONE, ASSOCSTR_EXECUTABLE,
            m_ext.c_str(), L"open", exe, &size) == S_OK
            && _wcsicmp(exe, m_exe.c_str()) == 0;
    }

    void Register()
    {
        std::wstring const command = L"\"" + m_exe + L"\" \"%1\"";
        std::wstring const icon = L"\"" + m_exe + L"\",0";

        // Magnet links go to the protocol key itself as well: browsers look
        // there when no default is picked.
        for (auto const& key : m_isProtocol ? std::vector{ m_progId, m_ext } : std::vector{ m_progId })
        {
            Set(Classes + key, L"", m_isProtocol ? L"URL:Magnet link" : L"BitTorrent file");
            if (m_isProtocol) { Set(Classes + key, L"URL Protocol", L""); }
            Set(Classes + key + L"\\DefaultIcon", L"", icon);
            Set(Classes + key + L"\\shell\\open\\command", L"", command);
        }

        if (!m_isProtocol)
        {
            Set(Classes + m_ext, L"", m_progId);
            Set(Classes + m_ext + L"\\OpenWithProgids", m_progId, L"");
        }

        Set(Capabilities, L"ApplicationName", L"RePicoTorrent");
        Set(Capabilities, L"ApplicationDescription", L"BitTorrent client");
        Set(CapabilitiesList(), m_ext, m_progId);
        Set(L"Software\\RegisteredApplications", L"RePicoTorrent", Capabilities);

        SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, nullptr, nullptr);
    }

    // Takes back what Register wrote, leaving keys of other programs alone.
    void Unregister()
    {
        RegDeleteTree(HKEY_CURRENT_USER, (Classes + m_progId).c_str());

        if (m_isProtocol)
        {
            if (Get(Classes + m_ext + L"\\shell\\open\\command") == L"\"" + m_exe + L"\" \"%1\"")
            {
                RegDeleteTree(HKEY_CURRENT_USER, (Classes + m_ext).c_str());
            }
        }
        else
        {
            if (Get(Classes + m_ext) == m_progId) { RegDeleteKeyValue(HKEY_CURRENT_USER, (Classes + m_ext).c_str(), nullptr); }
            RegDeleteKeyValue(HKEY_CURRENT_USER, (Classes + m_ext + L"\\OpenWithProgids").c_str(), m_progId.c_str());
            SHDeleteEmptyKey(HKEY_CURRENT_USER, (Classes + m_ext + L"\\OpenWithProgids").c_str());
            SHDeleteEmptyKey(HKEY_CURRENT_USER, (Classes + m_ext).c_str());
        }

        RegDeleteKeyValue(HKEY_CURRENT_USER, CapabilitiesList().c_str(), m_ext.c_str());

        // The other kind may still be registered.
        if (Get(Classes + L"RePicoTorrent.torrent").empty() && Get(Classes + L"RePicoTorrent.magnet").empty())
        {
            RegDeleteTree(HKEY_CURRENT_USER, L"Software\\RePicoTorrent");
            RegDeleteKeyValue(HKEY_CURRENT_USER, L"Software\\RegisteredApplications", L"RePicoTorrent");
        }

        SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, nullptr, nullptr);
    }

private:
    static inline std::wstring const Classes = L"Software\\Classes\\";
    static inline std::wstring const Capabilities = L"Software\\RePicoTorrent\\Capabilities";

    std::wstring CapabilitiesList()
    {
        return Capabilities + (m_isProtocol ? L"\\URLAssociations" : L"\\FileAssociations");
    }

    static void Set(std::wstring const& key, std::wstring const& name, std::wstring const& value)
    {
        RegSetKeyValue(HKEY_CURRENT_USER, key.c_str(), name.empty() ? nullptr : name.c_str(), REG_SZ,
            value.c_str(), static_cast<DWORD>((value.size() + 1) * sizeof(wchar_t)));
    }

    // The default value of a key, or "".
    static std::wstring Get(std::wstring const& key)
    {
        wchar_t value[MAX_PATH * 2];
        DWORD size = sizeof(value);

        return RegGetValue(HKEY_CURRENT_USER, key.c_str(), nullptr, RRF_RT_REG_SZ, nullptr, value, &size) == ERROR_SUCCESS
            ? value
            : L"";
    }

    std::wstring m_ext;
    bool m_isProtocol;
    std::wstring m_progId;
    std::wstring m_exe;
};

using pt::Core::Configuration;
using pt::UI::Dialogs::PreferencesGeneralPage;

PreferencesGeneralPage::PreferencesGeneralPage(wxWindow* parent, std::shared_ptr<pt::Core::Configuration> cfg)
    : wxPanel(parent),
    m_cfg(cfg)
{
    wxStaticBoxSizer* uiSizer = new wxStaticBoxSizer(wxVERTICAL, this, i18n("user_interface"));
    wxFlexGridSizer* uiGrid = new wxFlexGridSizer(2, FromDIP(10), FromDIP(10));
    m_language = new wxChoice(uiSizer->GetStaticBox(), wxID_ANY);
    m_theme = new wxChoice(uiSizer->GetStaticBox(), wxID_ANY);
    uiGrid->AddGrowableCol(1, 1);
    uiGrid->Add(new wxStaticText(uiSizer->GetStaticBox(), wxID_ANY, i18n("language")), 0, wxALIGN_CENTER_VERTICAL);
    uiGrid->Add(m_language, 1, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
    uiGrid->Add(new wxStaticText(uiSizer->GetStaticBox(), wxID_ANY, i18n("theme")), 0, wxALIGN_CENTER_VERTICAL);
    uiGrid->Add(m_theme, 1, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
    uiSizer->Add(uiGrid, 1, wxEXPAND | wxALL, FromDIP(5));

    wxStaticBoxSizer* miscSizer = new wxStaticBoxSizer(wxVERTICAL, this, i18n("miscellaneous"));
    wxFlexGridSizer* miscGrid = new wxFlexGridSizer(2, FromDIP(10), FromDIP(10));

    m_labelColor = new wxCheckBox(miscSizer->GetStaticBox(), wxID_ANY, i18n("use_label_color_as_background_in_torrent_list"));
    m_skipAddTorrentDialog = new wxCheckBox(miscSizer->GetStaticBox(), wxID_ANY, i18n("skip_add_torrent_dialog"));
    m_autoStart = new wxCheckBox(miscSizer->GetStaticBox(), wxID_ANY, i18n("start_with_windows"));
    m_startPosition = new wxChoice(miscSizer->GetStaticBox(), wxID_ANY);
    m_associateTorrents = new wxCheckBox(miscSizer->GetStaticBox(), wxID_ANY, i18n("associate_torrent_files"));
    m_associateMagnets = new wxCheckBox(miscSizer->GetStaticBox(), wxID_ANY, i18n("associate_magnet_links"));

    miscGrid->AddGrowableCol(1, 1);
    miscGrid->Add(m_labelColor, 0, wxALIGN_CENTER_VERTICAL);
    miscGrid->Add(0, 0);
    miscGrid->Add(m_skipAddTorrentDialog, 0, wxALIGN_CENTER_VERTICAL);
    miscGrid->Add(0, 0);
    miscGrid->Add(m_autoStart, 0, wxALIGN_CENTER_VERTICAL);
    miscGrid->Add(0, 0);
    miscGrid->Add(m_associateTorrents, 0, wxALIGN_CENTER_VERTICAL);
    miscGrid->Add(0, 0);
    miscGrid->Add(m_associateMagnets, 0, wxALIGN_CENTER_VERTICAL);
    miscGrid->Add(0, 0);
    miscGrid->Add(new wxStaticText(miscSizer->GetStaticBox(), wxID_ANY, i18n("start_position")), 0, wxALIGN_CENTER_VERTICAL);
    miscGrid->Add(m_startPosition, 1, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
    miscSizer->Add(miscGrid, 1, wxEXPAND | wxALL, FromDIP(5));

    wxStaticBoxSizer* notifSizer = new wxStaticBoxSizer(wxVERTICAL, this, i18n("notification_area"));
    wxFlexGridSizer* notifGrid = new wxFlexGridSizer(1, FromDIP(10), FromDIP(10));

    m_showNotificationIcon = new wxCheckBox(notifSizer->GetStaticBox(), wxID_ANY, i18n("show_picotorrent_in_notification_area"));
    m_minimizeNotification = new wxCheckBox(notifSizer->GetStaticBox(), wxID_ANY, i18n("minimize_to_notification_area"));
    m_closeNotification = new wxCheckBox(notifSizer->GetStaticBox(), wxID_ANY, i18n("close_to_notification_area"));

    notifGrid->AddGrowableCol(0, 1);
    notifGrid->Add(m_showNotificationIcon);
    notifGrid->Add(m_minimizeNotification, 0, wxLEFT, FromDIP(15));
    notifGrid->Add(m_closeNotification, 0, wxLEFT, FromDIP(15));
    notifSizer->Add(notifGrid, 1, wxEXPAND | wxALL, FromDIP(5));

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(uiSizer, 0, wxEXPAND);
    sizer->AddSpacer(10);
    sizer->Add(miscSizer, 0, wxEXPAND);
    sizer->AddSpacer(10);
    sizer->Add(notifSizer, 0, wxEXPAND);
    sizer->AddStretchSpacer();

    this->SetSizerAndFit(sizer);

    for (auto& lang : Translator::GetInstance().Languages())
    {
        int pos = m_language->Append(lang.name, new ClientData<std::string>(lang.locale));

        if (lang.locale == Translator::GetInstance().GetLocale())
        {
            m_language->SetSelection(pos);
        }
    }
    
    m_theme->Append(i18n("follow_system_theme"), new ClientData<std::string>("system"));
    m_theme->Append(i18n("light_theme"), new ClientData<std::string>("light"));
    if (m_cfg->Get<std::string>("theme_id").value_or("system") == "light")
    {
        m_theme->SetSelection(1);
    }
    else
    {
        m_theme->SetSelection(0);
    }

    m_labelColor->SetValue(m_cfg->Get<bool>("use_label_as_list_bgcolor").value_or(false));
    m_skipAddTorrentDialog->SetValue(m_cfg->Get<bool>("skip_add_torrent_dialog").value_or(false));

    AutoRunKey key;
    if (key.Exists())
    {
        m_autoStart->SetValue(true);
    }

    m_associateTorrents->SetValue(Association(L".torrent").IsDefault());
    m_associateMagnets->SetValue(Association(L"magnet").IsDefault());

    m_startPosition->Append(i18n("normal"), new ClientData<Configuration::WindowState>(Configuration::WindowState::Normal));
    m_startPosition->Append(i18n("minimized"), new ClientData<Configuration::WindowState>(Configuration::WindowState::Minimized));
    m_startPosition->Append(i18n("hidden"), new ClientData<Configuration::WindowState>(Configuration::WindowState::Hidden));
    m_startPosition->Append(i18n("maximized"), new ClientData<Configuration::WindowState>(Configuration::WindowState::Maximized));
    m_startPosition->SetSelection(m_cfg->Get<int>("start_position").value_or(0));

    // Notification area
    m_showNotificationIcon->SetValue(m_cfg->Get<bool>("show_in_notification_area").value_or(true));
    m_minimizeNotification->SetValue(m_cfg->Get<bool>("minimize_to_notification_area").value_or(false));
    m_closeNotification->SetValue(m_cfg->Get<bool>("close_to_notification_area").value_or(false));

    m_showNotificationIcon->Bind(wxEVT_CHECKBOX, [this](wxCommandEvent&)
        {
            m_minimizeNotification->Enable(m_showNotificationIcon->IsChecked());
            m_closeNotification->Enable(m_showNotificationIcon->IsChecked());
        });

    m_minimizeNotification->Enable(m_showNotificationIcon->IsChecked());
    m_closeNotification->Enable(m_showNotificationIcon->IsChecked());
}

PreferencesGeneralPage::~PreferencesGeneralPage()
{
}

bool PreferencesGeneralPage::IsValid()
{
    return true;
}

void PreferencesGeneralPage::Save(bool* restartRequired)
{
    int langIndex = m_language->GetSelection();
    ClientData<std::string>* langData = langIndex >= 0
        ? reinterpret_cast<ClientData<std::string>*>(m_language->GetClientObject(langIndex))
        : nullptr;

    int themeIndex = m_theme->GetSelection();
    ClientData<std::string> *themeData = themeIndex >= 0
        ? reinterpret_cast<ClientData<std::string> *>(m_theme->GetClientObject(themeIndex))
        : nullptr;

    int startPosIndex = m_startPosition->GetSelection();
    ClientData<Configuration::WindowState>* startPosData = reinterpret_cast<ClientData<Configuration::WindowState>*>(m_startPosition->GetClientObject(startPosIndex));

    if (langData != nullptr)
    {
        if (langData->GetValue() != m_cfg->Get<std::string>("locale_name"))
        {
            *restartRequired = true;
        }

        m_cfg->Set("locale_name", langData->GetValue());
    }

    if (themeData != nullptr)
    {
        if (themeData->GetValue() != m_cfg->Get<std::string>("theme_id"))
        {
            *restartRequired = true;
        }
        m_cfg->Set("theme_id", themeData->GetValue());
    }

    if (startPosData != nullptr)
    {
        m_cfg->Set("start_position", static_cast<int>(startPosData->GetValue()));
    }

    {
        AutoRunKey key;

        if (key.Exists() && !m_autoStart->GetValue())
        {
            key.Delete();
        }

        if (!key.Exists() && m_autoStart->GetValue())
        {
            key.Create();
        }
    }

    // Only a change is applied: another copy of the program may be the
    // registered one, and merely saving here must not take that over.
    bool notDefault = false;

    for (auto [box, ext] : { std::pair{ m_associateTorrents, L".torrent" }, std::pair{ m_associateMagnets, L"magnet" } })
    {
        Association assoc(ext);

        if (box->GetValue() == assoc.IsDefault()) { continue; }

        if (box->GetValue())
        {
            assoc.Register();
            notDefault = notDefault || !assoc.IsDefault();
        }
        else
        {
            assoc.Unregister();
        }
    }

    // Registered, but the user had picked another program in Windows.
    if (notDefault
        && wxMessageBox(i18n("associate_pick_in_windows"), "RePicoTorrent", wxYES_NO | wxICON_INFORMATION, this) == wxYES)
    {
        ShellExecute(NULL, L"open", L"ms-settings:defaultapps?registeredAppUser=RePicoTorrent", NULL, NULL, SW_SHOWNORMAL);
    }

    m_cfg->Set("use_label_as_list_bgcolor", m_labelColor->GetValue());
    m_cfg->Set("skip_add_torrent_dialog", m_skipAddTorrentDialog->GetValue());
    m_cfg->Set("show_in_notification_area", m_showNotificationIcon->GetValue());
    m_cfg->Set("minimize_to_notification_area", m_minimizeNotification->GetValue());
    m_cfg->Set("close_to_notification_area", m_closeNotification->GetValue());
}
