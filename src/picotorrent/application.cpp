#include "application.hpp"

#include <boost/log/trivial.hpp>
#include <nlohmann/json.hpp>
#include <wx/cmdline.h>
#include <wx/ipc.h>
#include <wx/msw/darkmode.h>
#include <wx/persist.h>
#include <wx/renderer.h>
#include <wx/snglinst.h>
#include <wx/taskbarbutton.h>

#include "api/libpico_impl.hpp"
#include "crashpadinitializer.hpp"
#include "persistencemanager.hpp"
#include "core/configuration.hpp"
#include "core/database.hpp"
#include "core/environment.hpp"
#include "core/utils.hpp"
#include "ui/mainframe.hpp"
#include "ui/translator.hpp"

using json = nlohmann::json;
using pt::Application;

static const char* SingleInstanceName = "584c8e47-d8a5-4e52-9165-c0650a85723a";

namespace
{
    // wx paints the menu bar (0x6d6d6d) and the outlines of notebook tabs
    // (0x626262) light gray, which glares next to the 0x202020 windows.
    class DarkModeSettings : public wxDarkModeSettings
    {
    public:
        wxColour GetColour(wxSystemColour index) override
        {
            // Only used for the notebook tab outlines.
            if (index == wxSYS_COLOUR_MENUBAR) { return wxColour(0x3c3c3c); }
            return wxDarkModeSettings::GetColour(index);
        }

        wxColour GetMenuColour(wxMenuColour which) override
        {
            switch (which)
            {
            case wxMenuColour::StandardBg: return wxColour(0x2b2b2b);
            case wxMenuColour::HotBg: return wxColour(0x404040);
            default: return wxDarkModeSettings::GetMenuColour(which);
            }
        }

        wxPen GetBorderPen() override { return wxPen(wxColour(0x3c3c3c)); }
    };

    // The native PROGRESS theme has no dark variant and draws a white bar in
    // every list with a progress column.
    class DarkGaugeRenderer : public wxDelegateRendererNative
    {
    public:
        void DrawGauge(wxWindow*, wxDC& dc, const wxRect& rect, int value, int max, int) override
        {
            wxDCPenChanger pen(dc, wxColour(0x3c3c3c));
            wxDCBrushChanger brush(dc, wxColour(0x2b2b2b));
            dc.DrawRectangle(rect);

            if (max <= 0 || value <= 0) { return; }

            wxRect fill(rect);
            fill.Deflate(1);
            fill.width = static_cast<int>(static_cast<long long>(fill.width) * std::min(value, max) / max);

            dc.SetPen(*wxTRANSPARENT_PEN);
            dc.SetBrush(wxColour(48, 140, 70));
            dc.DrawRectangle(fill);
        }
    };

    // wxBORDER_THEME - the default for lists, text fields and the property
    // grid - draws the light EDIT theme frame even in dark mode, and the
    // sunken 3D edge of list boxes is light too: a white outline around every
    // one of them. A simple border is drawn in a dim gray instead.
    void darkenThemeBorders(wxWindow* window)
    {
        wxBorder const border = window->GetBorder();

        if (border == wxBORDER_THEME || border == wxBORDER_SUNKEN)
        {
            window->SetWindowStyleFlag((window->GetWindowStyleFlag() & ~wxBORDER_MASK) | wxBORDER_SIMPLE);
        }

        for (wxWindow* child : window->GetChildren())
        {
            darkenThemeBorders(child);
        }
    }
}

Application::Application()
    : wxApp(),
    m_singleInstance(std::make_unique<wxSingleInstanceChecker>(SingleInstanceName))
{
    SetProcessDPIAware();
}

Application::~Application()
{
    for (auto plugin : m_plugins)
    {
        delete plugin;
    }
}

int Application::FilterEvent(wxEvent& event)
{
    // Every dialog and frame passes through here right before it appears,
    // with all its controls created.
    if (m_darkMode
        && event.GetEventType() == wxEVT_SHOW
        && static_cast<wxShowEvent&>(event).IsShown())
    {
        if (auto tlw = wxDynamicCast(event.GetEventObject(), wxTopLevelWindow))
        {
            darkenThemeBorders(tlw);
        }
    }

    return Event_Skip;
}

bool Application::OnCmdLineParsed(wxCmdLineParser& parser)
{
    long waitForPid = -1;
    wxString save_path = "";

    if (parser.Found("wait-for-pid", &waitForPid))
    {
        m_options.pid = waitForPid;
    }

    m_options.silent = parser.Found("silent");

    if (parser.Found("save-path", &save_path))
    {
        m_options.save_path = Utils::toStdString(save_path.ToStdWstring());
    }

    for (size_t i = 0; i < parser.GetParamCount(); i++)
    {
        std::string arg = Utils::toStdString(parser.GetParam(i).ToStdWstring());

        if (arg.rfind("magnet:?xt", 0) == 0)
        {
            m_options.magnets.push_back(arg);
        }
        else
        {
            m_options.files.push_back(std::filesystem::absolute(arg).string());
        }
    }

    return true;
}

bool Application::OnInit()
{
    if (!wxApp::OnInit()) { return false; }

    if (m_options.pid > 0)
    {
        WaitForPreviousInstance(m_options.pid);
    }

    if (m_singleInstance->IsAnotherRunning()
        && ActivateOtherInstance())
    {
        return false;
    }

    auto env = pt::Core::Environment::Create();
    pt::CrashpadInitializer::Initialize(env);

    auto db = std::make_shared<pt::Core::Database>(env);


    if (!db->Migrate())
    {
        wxMessageBox(
            "Failed to run database migrations. Please check log file.",
            "PicoTorrent",
            wxICON_ERROR);
        return false;
    }

    auto cfg = std::make_shared<pt::Core::Configuration>(db);

    // Load current locale
    pt::UI::Translator& translator = pt::UI::Translator::GetInstance();
    translator.LoadDatabase(env->GetCoreDbFilePath());
    translator.SetLocale(
        cfg->Get<std::string>("locale_name")
            .value_or(env->GetCurrentLocale()));
    
    // Load theme
    if (cfg->IsDarkMode())
    {
        m_darkMode = wxApp::MSWEnableDarkMode(0, new DarkModeSettings());

        // The renderer slot initializes itself on first use and replaces
        // whatever was Set() before that - initialize it first.
        wxRendererNative::Get();
        wxRendererNative::Set(new DarkGaugeRenderer());
    }

    // Load plugins
    for (auto& p : fs::directory_iterator(env->GetApplicationPath()))
    {
        if (p.path().extension() != ".dll") { continue; }

        auto const& filename = p.path().filename().string();

        if (filename.size() < 6) { continue; }
        if (filename.substr(0, 6) != "Plugin") { continue; }

        BOOST_LOG_TRIVIAL(info) << "Loading plugin from " << p.path();

        auto plugin = API::IPlugin::Load(p, env.get(), cfg.get());

        if (plugin != nullptr)
        {
            m_plugins.push_back(plugin);
        }
    }

    // Set up persistence manager
    m_persistence = std::make_unique<PersistenceManager>(db);
    wxPersistenceManager::Set(*m_persistence);

    auto mainFrame = new UI::MainFrame(env, db, cfg, m_options);

    std::for_each(
        m_plugins.begin(),
        m_plugins.end(),
        [mainFrame](auto plugin) { plugin->EmitEvent(libpico_event_mainwnd_created, mainFrame); });

    auto windowState = static_cast<pt::Core::Configuration::WindowState>(cfg->Get<int>("start_position").value_or(0));

    switch (windowState)
    {
    case pt::Core::Configuration::WindowState::Hidden:
        // Only valid if we have a notify icon
        if (cfg->Get<bool>("show_in_notification_area").value_or(true))
        {
            if (auto button = mainFrame->MSWGetTaskBarButton()) { button->Hide(); }
        }
        else
        {
            mainFrame->Show(true);
        }

        break;

    case pt::Core::Configuration::WindowState::Maximized:
        mainFrame->Show(true);
        mainFrame->Maximize();
        break;

    case pt::Core::Configuration::WindowState::Minimized:
        mainFrame->Iconize();
        mainFrame->Show(true);
        break;

    case pt::Core::Configuration::WindowState::Normal:
        mainFrame->Show(true);
        break;
    }

    mainFrame->HandleParams(m_options);

    return true;
}

void Application::OnInitCmdLine(wxCmdLineParser& parser)
{
    static const wxCmdLineEntryDesc cmdLineDesc[] =
    {
        { wxCMD_LINE_OPTION, NULL, "wait-for-pid",  NULL,   wxCMD_LINE_VAL_NUMBER, wxCMD_LINE_PARAM_OPTIONAL },
        { wxCMD_LINE_SWITCH, NULL, "silent",        NULL,   wxCMD_LINE_VAL_NONE ,  wxCMD_LINE_PARAM_OPTIONAL },
        { wxCMD_LINE_OPTION, NULL, "save-path",     NULL,   wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
        { wxCMD_LINE_PARAM,  NULL, NULL,           "params",wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL | wxCMD_LINE_PARAM_MULTIPLE },
        { wxCMD_LINE_NONE }
    };

    parser.SetDesc(cmdLineDesc);
    parser.SetSwitchChars("-");
}

bool Application::ActivateOtherInstance()
{
    json j;
    j["files"] = m_options.files;
    j["magnet_links"] = m_options.magnets;
    j["silent"] = m_options.silent;
    j["save_path"] = m_options.save_path;

    // The other instance holds the mutex long before its IPC server exists
    // (the server comes with the main frame, after the database and the
    // session have loaded) and long after it is gone (the process lingers
    // for up to 30 seconds saving resume data on exit). A single attempt made
    // every other launch fail with a DDE error box and quit. Keep trying,
    // quietly, and start normally once the other instance has exited.
    wxLogNull noDdeErrors;

    for (int attempt = 0; attempt < 60; attempt++)
    {
        wxClient client;

        if (auto conn = client.MakeConnection("localhost", "PicoTorrent", "ApplicationOptions"))
        {
            conn->Execute(j.dump());
            conn->Disconnect();
            delete conn;
            return true;
        }

        // Our own handle keeps the named mutex alive - drop it before asking.
        m_singleInstance.reset();
        m_singleInstance = std::make_unique<wxSingleInstanceChecker>(SingleInstanceName);

        if (!m_singleInstance->IsAnotherRunning())
        {
            return false;
        }

        wxMilliSleep(500);
    }

    // ponytail: gives up silently after 30 seconds; a hung instance would
    // need a message here.
    return true;
}

void Application::WaitForPreviousInstance(long pid)
{
    HANDLE hProc = OpenProcess(SYNCHRONIZE, FALSE, pid);
    if (hProc == NULL) { return; }
    WaitForSingleObject(hProc, 10000);
    CloseHandle(hProc);
}
