#include "torrentdetailspeerspanel.hpp"

#include <algorithm>

#include <fmt/format.h>
#include <fmt/xchar.h>
#include <libtorrent/peer_info.hpp>
#include <wx/dataview.h>
#include <wx/sizer.h>

#include "../bittorrent/torrenthandle.hpp"
#include "../bittorrent/torrentstatus.hpp"
#include "models/peerlistmodel.hpp"
#include "translator.hpp"

using pt::UI::TorrentDetailsPeersPanel;
using pt::UI::Models::PeerListModel;

TorrentDetailsPeersPanel::TorrentDetailsPeersPanel(wxWindow* parent, wxWindowID id, pt::Core::GeoIP const* geoip)
    : wxPanel(parent, id),
    m_peersView(new wxDataViewCtrl(this, wxID_ANY)),
    m_peersModel(new PeerListModel(geoip)),
    m_summary(new wxStaticText(this, wxID_ANY, wxEmptyString))
{
    m_peersView->AppendTextColumn(i18n("ip"), PeerListModel::Column::IP, wxDATAVIEW_CELL_INERT, FromDIP(110));
    m_peersView->AppendTextColumn(i18n("country"), PeerListModel::Column::Country, wxDATAVIEW_CELL_INERT, FromDIP(50));
    m_peersView->AppendTextColumn(i18n("type"), PeerListModel::Column::Type, wxDATAVIEW_CELL_INERT, FromDIP(60));
    m_peersView->AppendTextColumn(i18n("client"), PeerListModel::Column::Client, wxDATAVIEW_CELL_INERT, FromDIP(140));
    m_peersView->AppendTextColumn(i18n("flags"), PeerListModel::Column::Flags, wxDATAVIEW_CELL_INERT, FromDIP(80));
    m_peersView->AppendTextColumn(i18n("dl"), PeerListModel::Column::DownloadRate, wxDATAVIEW_CELL_INERT, FromDIP(80), wxALIGN_RIGHT);
    m_peersView->AppendTextColumn(i18n("ul"), PeerListModel::Column::UploadRate, wxDATAVIEW_CELL_INERT, FromDIP(80), wxALIGN_RIGHT);
    m_peersView->AppendTextColumn(i18n("downloaded"), PeerListModel::Column::Downloaded, wxDATAVIEW_CELL_INERT, FromDIP(80), wxALIGN_RIGHT);
    m_peersView->AppendTextColumn(i18n("uploaded"), PeerListModel::Column::Uploaded, wxDATAVIEW_CELL_INERT, FromDIP(80), wxALIGN_RIGHT);
    m_peersView->AppendProgressColumn(i18n("progress"), PeerListModel::Column::Progress, wxDATAVIEW_CELL_INERT, FromDIP(100), wxALIGN_LEFT);

    // Ugly hack to prevent the last "real" column from stretching.
    m_peersView->AppendColumn(new wxDataViewColumn(wxEmptyString, new wxDataViewTextRenderer(), PeerListModel::Column::_Max, 0));

    m_peersView->AssociateModel(m_peersModel);
    m_peersModel->DecRef();

    auto mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(m_summary, 0, wxEXPAND | wxALL, FromDIP(4));
    mainSizer->Add(m_peersView, 1, wxEXPAND);
    this->SetSizerAndFit(mainSizer);
}

void TorrentDetailsPeersPanel::Refresh(pt::BitTorrent::TorrentHandle* torrent)
{
    if (!torrent->IsValid())
    {
        this->Reset();
        return;
    }

    std::vector<lt::peer_info> peers;
    torrent->GetPeerInfo(peers);

    m_peersModel->Update(peers);

    // libtorrent can only list the peers we are connected to. The rest of the
    // swarm is known by count only - from the tracker and our peer list.
    auto const seeds = std::count_if(
        peers.begin(),
        peers.end(),
        [](lt::peer_info const& p) { return static_cast<bool>(p.flags & lt::peer_info::seed); });

    auto const& status = torrent->Status();

    m_summary->SetLabel(
        fmt::format(
            i18n("peers_summary"),
            seeds,
            status.swarmSeeds,
            static_cast<std::ptrdiff_t>(peers.size()) - seeds,
            status.swarmLeechers));
}

void TorrentDetailsPeersPanel::Reset()
{
    m_peersModel->ResetPeers();
    m_summary->SetLabel(wxEmptyString);
}
