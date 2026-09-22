#include "peerlistmodel.hpp"

#include <fmt/format.h>
#include <fmt/xchar.h>
#include <libtorrent/peer_info.hpp>

#include "../../core/geoip/geoip.hpp"
#include "../../core/utils.hpp"
#include "../translator.hpp"

namespace lt = libtorrent;
using pt::UI::Models::PeerListModel;

PeerListModel::PeerListModel(pt::Core::GeoIP const* geoip)
    : m_geoip(geoip)
{
}

PeerListModel::~PeerListModel()
{
}

void PeerListModel::ResetPeers()
{
    m_data.clear();
    Reset(0);
}

void PeerListModel::Update(std::vector<lt::peer_info> const& peers)
{
    // Remove old data
    for (auto it = m_data.begin(); it != m_data.end();)
    {
        auto f = std::find_if(
            peers.begin(),
            peers.end(),
            [it](lt::peer_info const& p)
            {
                // peer_info::ip was removed in libtorrent 2.1; the remote
                // endpoint replaces it for both matching and display.
                return p.remote_endpoint() == it->remote_endpoint();
            });

        if (f == peers.end())
        {
            it = m_data.erase(it);
            RowDeleted(std::distance(m_data.begin(), it));
        }
        else
        {
            ++it;
        }
    }

    // Add or update new data

    for (auto it = peers.begin(); it != peers.end(); it++)
    {
        auto f = std::find_if(m_data.begin(), m_data.end(), [it](lt::peer_info& p) { return p.remote_endpoint() == it->remote_endpoint(); });

        if (f == m_data.end())
        {
            m_data.push_back(*it);
            RowAppended();
        }
        else
        {
            auto distance = std::distance(m_data.begin(), f);
            m_data.at(distance) = *it;
            RowChanged(distance);
        }
    }
}

unsigned int PeerListModel::GetColumnCount() const
{
    return Column::_Max;
}

wxString PeerListModel::GetColumnType(unsigned int) const
{
    return "string";
}

void PeerListModel::GetValueByRow(wxVariant &variant, unsigned int row, unsigned int col) const
{
    lt::peer_info const& peer = m_data.at(row);

    switch (col)
    {
    case Column::IP:
        // std::ostringstream: the operator<< output is neither deprecated
        // (asio removed address::to_string with BOOST_ASIO_NO_DEPRECATED)
        // nor locale-formatted.
        {
            std::stringstream ss;
            ss << peer.remote_endpoint().address();
            variant = ss.str();
        }
        break;
    case Column::Country:
        variant = m_geoip == nullptr
            ? std::string()
            : m_geoip->LookupCountryCode(peer.remote_endpoint().data());
        break;
    case Column::Type:
        variant = (peer.flags & lt::peer_info::seed)
            ? i18n("peer_seed")
            : i18n("peer_leecher");
        break;
    case Column::Client:
        variant = wxString::FromUTF8(peer.client);
        break;
    case Column::Flags:
    {
        // Spelled out rather than the classic one-letter codes
        // (D d U u O S I K ? X H E e P L), which nobody remembers.
        std::vector<std::string> keys;

        if (peer.flags & lt::peer_info::interesting)
        {
            keys.push_back(peer.flags & lt::peer_info::remote_choked ? "peer_flag_download_choked" : "peer_flag_downloading");
        }

        if (peer.flags & lt::peer_info::remote_interested)
        {
            keys.push_back(peer.flags & lt::peer_info::choked ? "peer_flag_upload_choked" : "peer_flag_uploading");
        }

        if (peer.flags & lt::peer_info::optimistic_unchoke) { keys.push_back("peer_flag_optimistic"); }
        if (peer.flags & lt::peer_info::snubbed) { keys.push_back("peer_flag_snubbed"); }
        if (!(peer.flags & lt::peer_info::outgoing_connection)) { keys.push_back("peer_flag_incoming"); }
        if (!(peer.flags & lt::peer_info::remote_choked) && !(peer.flags & lt::peer_info::interesting)) { keys.push_back("peer_flag_not_interested"); }
        if (!(peer.flags & lt::peer_info::choked) && !(peer.flags & lt::peer_info::remote_interested)) { keys.push_back("peer_flag_not_interesting"); }
        if (peer.source & lt::peer_info::pex) { keys.push_back("peer_flag_pex"); }
        if (peer.source & lt::peer_info::dht) { keys.push_back("peer_flag_dht"); }
        if (peer.flags & lt::peer_info::rc4_encrypted) { keys.push_back("peer_flag_encrypted"); }
        if (peer.flags & lt::peer_info::plaintext_encrypted) { keys.push_back("peer_flag_header_encrypted"); }
        if (peer.flags & lt::peer_info::utp_socket) { keys.push_back("peer_flag_utp"); }
        if (peer.source & lt::peer_info::lsd) { keys.push_back("peer_flag_lsd"); }

        std::wstring flags;

        for (auto const& key : keys)
        {
            if (!flags.empty()) { flags += L", "; }
            flags += i18n(key);
        }

        variant = flags;

        break;
    }
    case Column::DownloadRate:
    {
        if (peer.payload_down_speed <= 0)
        {
            variant = "-";
        }
        else
        {
            variant = fmt::format(
                i18n("per_second_format"),
                Utils::toHumanFileSize(peer.payload_down_speed));
        }

        break;
    }
    case Column::UploadRate:
    {
        if (peer.payload_up_speed <= 0)
        {
            variant = "-";
        }
        else
        {
            variant = fmt::format(
                i18n("per_second_format"),
                Utils::toHumanFileSize(peer.payload_up_speed));
        }

        break;
    }
    case Column::Downloaded:
    {
        variant = peer.total_download <= 0
            ? std::wstring(L"-")
            : Utils::toHumanFileSize(peer.total_download);
        break;
    }
    case Column::Uploaded:
    {
        variant = peer.total_upload <= 0
            ? std::wstring(L"-")
            : Utils::toHumanFileSize(peer.total_upload);
        break;
    }
    case Column::Progress:
    {
        variant = static_cast<long>(peer.progress * 100);
        break;
    }
    }
}

bool PeerListModel::SetValueByRow(const wxVariant&, unsigned int, unsigned int)
{
    return false;
}
