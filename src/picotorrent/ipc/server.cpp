#include "server.hpp"

#include "applicationoptionsconnection.hpp"
#include "../ui/mainframe.hpp"

using pt::IPC::Server;

Server::Server(pt::UI::MainFrame* mainFrame)
    : m_frame(mainFrame)
{
    Create(InstanceName());
}

wxString Server::InstanceName()
{
    wchar_t exe[MAX_PATH];
    GetModuleFileNameW(nullptr, exe, MAX_PATH);

    std::wstring dir(exe);
    dir = dir.substr(0, dir.find_last_of(L'\\'));
    CharLowerW(dir.data());

    return wxString::Format("RePicoTorrent-%zx", std::hash<std::wstring>{}(dir));
}

Server::~Server()
{
}

wxConnectionBase* Server::OnAcceptConnection(const wxString& topic)
{
    if (topic == "ApplicationOptions")
    {
        return new ApplicationOptionsConnection(m_frame);
    }

    return nullptr;
}
