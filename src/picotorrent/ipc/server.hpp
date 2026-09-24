#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/ipc.h>

namespace pt
{
namespace UI
{
    class MainFrame;
}
namespace IPC
{
    class Server : public wxServer
    {
    public:
        Server(UI::MainFrame* mainFrame);
        virtual ~Server();

        virtual wxConnectionBase* OnAcceptConnection(const wxString& topic) wxOVERRIDE;

        // One instance per program folder: copies in different folders
        // (a live one and a screenshot one, say) run side by side.
        static wxString InstanceName();

    private:
        UI::MainFrame* m_frame;
    };
}
}
