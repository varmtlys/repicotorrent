#include "torrentdetailsview.hpp"

#include <wx/notebook.h>
#include <wx/sizer.h>

#include "../core/configuration.hpp"
#include "torrentdetailsfilespanel.hpp"
#include "torrentdetailsoverviewpanel.hpp"
#include "torrentdetailspeerspanel.hpp"
#include "torrentdetailstrackerspanel.hpp"
#include "translator.hpp"

using pt::UI::TorrentDetailsView;

TorrentDetailsView::TorrentDetailsView(wxWindow* parent, wxWindowID id, std::shared_ptr<pt::Core::Configuration> cfg)
    : wxNotebook(parent, id),
    m_cfg(cfg),
    m_overview(new TorrentDetailsOverviewPanel(this, wxID_ANY, cfg->IsDarkMode())),
    m_files(new TorrentDetailsFilesPanel(this, wxID_ANY)),
    m_peers(new TorrentDetailsPeersPanel(this, wxID_ANY)),
    m_trackers(new TorrentDetailsTrackersPanel(this, wxID_ANY))
{
    this->AddPage(m_overview, i18n("overview"));
    this->AddPage(m_files,    i18n("files"));
    this->AddPage(m_peers,    i18n("peers"));
    this->AddPage(m_trackers, i18n("trackers"));
    this->ReloadConfiguration();
}

TorrentDetailsView::~TorrentDetailsView()
{
}

void TorrentDetailsView::Refresh(std::map<lt::info_hash_t, pt::BitTorrent::TorrentHandle*> const& torrents)
{
    if (torrents.size() != 1)
    {
        this->Reset();
        return;
    }

    auto torrent = torrents.begin()->second;

    // Only the visible page. Refreshing all four every second meant two
    // get_peer_info() calls plus trackers() and file_progress() - each a
    // blocking round-trip to the session thread - for pages nobody is looking
    // at. Switching tabs refreshes the new page within the second.
    int const selected = this->GetSelection();

    if (selected == wxNOT_FOUND) { return; }

    wxWindow* page = this->GetPage(static_cast<size_t>(selected));

    if      (page == m_overview) { m_overview->Refresh(torrent); }
    else if (page == m_files)    { m_files->Refresh(torrent); }
    else if (page == m_peers)    { m_peers->Refresh(torrent); }
    else if (page == m_trackers) { m_trackers->Refresh(torrent); }
}

void TorrentDetailsView::ReloadConfiguration()
{
    auto showPieceProgress = m_cfg->Get<bool>("ui.torrent_overview.show_piece_progress");
    auto cols = m_cfg->Get<int>("ui.torrent_overview.columns");

    m_overview->UpdateView(
        cols.value_or(2),
        showPieceProgress.value_or(true));
}

void TorrentDetailsView::Reset()
{
    m_overview->Reset();
    m_files->Reset();
    m_peers->Reset();
    m_trackers->Reset();
}
