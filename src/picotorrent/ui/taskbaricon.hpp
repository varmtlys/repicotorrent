#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/taskbar.h>

namespace pt
{
namespace UI
{
    class TaskBarIcon : public wxTaskBarIcon
    {
    public:
        TaskBarIcon(wxWindow* parent);

        void Hide();
        void Show();

        // The tooltip shows the transfer rates and the session totals.
        void SetRates(int64_t down, int64_t up);
        void SetSessionTotals(int64_t downloaded, int64_t uploaded);

    private:
        wxMenu* CreatePopupMenu() wxOVERRIDE;
        void UpdateTooltip();

        wxWindow* m_parent;
        wxIcon m_icon;
        wxString m_tooltip = "RePicoTorrent";
        int64_t m_down = 0;
        int64_t m_up = 0;
        int64_t m_downloaded = 0;
        int64_t m_uploaded = 0;
    };
}
}
