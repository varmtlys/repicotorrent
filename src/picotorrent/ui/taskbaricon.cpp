#include "taskbaricon.hpp"

#include <fmt/format.h>
#include <fmt/xchar.h>

#include "ids.hpp"
#include "translator.hpp"
#include "../core/utils.hpp"

using pt::UI::TaskBarIcon;

TaskBarIcon::TaskBarIcon(wxWindow* parent)
    : m_parent(parent),
    m_icon(wxIcon(wxICON(AppIcon)))
{
}

void TaskBarIcon::Hide()
{
    RemoveIcon();
}

void TaskBarIcon::Show()
{
    SetIcon(m_icon, m_tooltip);
}

void TaskBarIcon::SetRates(int64_t down, int64_t up)
{
    m_down = down;
    m_up = up;
    UpdateTooltip();
}

void TaskBarIcon::SetSessionTotals(int64_t downloaded, int64_t uploaded)
{
    m_downloaded = downloaded;
    m_uploaded = uploaded;
    UpdateTooltip();
}

void TaskBarIcon::UpdateTooltip()
{
    wxString const tooltip = wxString("RePicoTorrent\n")
        + fmt::format(i18n("dl_s_ul_s"), pt::Utils::toHumanFileSize(m_down), pt::Utils::toHumanFileSize(m_up)) + "\n"
        + fmt::format(i18n("session_totals"), pt::Utils::toHumanFileSize(m_downloaded), pt::Utils::toHumanFileSize(m_uploaded));

    // Once a second each; only touch the shell when the text changed.
    if (tooltip == m_tooltip) { return; }
    m_tooltip = tooltip;

    if (IsIconInstalled()) { SetIcon(m_icon, m_tooltip); }
}

wxMenu* TaskBarIcon::CreatePopupMenu()
{
    wxMenu* menu = new wxMenu();
    menu->Append(ptID_EVT_ADD_TORRENT, i18n("amp_add_torrent"));
    menu->Append(ptID_EVT_ADD_MAGNET_LINK, i18n("amp_add_magnet_link_s"));
    menu->AppendSeparator();
    menu->Append(ptID_EVT_VIEW_PREFERENCES, i18n("preferences"));
    menu->AppendSeparator();
    menu->Append(ptID_EVT_EXIT, i18n("amp_exit"));
    return menu;
}
