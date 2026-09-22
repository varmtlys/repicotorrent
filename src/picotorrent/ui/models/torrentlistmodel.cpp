#include "torrentlistmodel.hpp"

#include <boost/log/trivial.hpp>
#include <fmt/format.h>
#include <fmt/xchar.h>
#include <wx/graphics.h>

#include "../../bittorrent/torrenthandle.hpp"
#include "../../bittorrent/torrentstatus.hpp"
#include "../../core/utils.hpp"
#include "../filters/torrentfilter.hpp"
#include "../translator.hpp"

using pt::BitTorrent::TorrentHandle;
using pt::BitTorrent::TorrentStatus;
using pt::UI::Models::TorrentListModel;

namespace
{
    enum class Shape { ArrowDown, ArrowUp, Pause, Dot, Ring, Error };

    // Drawn rather than loaded so the icons stay crisp at any DPI and read
    // the same on light and dark backgrounds. Coordinates are in a 16x16 box.
    wxIcon makeStateIcon(int size, Shape shape, wxColour const& color)
    {
        wxImage img(size, size);
        img.InitAlpha();
        std::fill(img.GetAlpha(), img.GetAlpha() + size * size, static_cast<unsigned char>(0));

        {
            std::unique_ptr<wxGraphicsContext> gc(wxGraphicsContext::Create(img));
            gc->Scale(size / 16.0, size / 16.0);
            gc->SetPen(*wxTRANSPARENT_PEN);
            gc->SetBrush(wxBrush(color));

            switch (shape)
            {
            case Shape::ArrowDown:
            case Shape::ArrowUp:
            {
                wxPoint2DDouble const down[] =
                {
                    { 6, 2 }, { 10, 2 }, { 10, 8 }, { 14, 8 }, { 8, 14.5 }, { 2, 8 }, { 6, 8 }
                };

                wxGraphicsPath path = gc->CreatePath();

                for (size_t i = 0; i < std::size(down); i++)
                {
                    double const y = shape == Shape::ArrowUp ? 16 - down[i].m_y : down[i].m_y;
                    if (i == 0) { path.MoveToPoint(down[i].m_x, y); }
                    else { path.AddLineToPoint(down[i].m_x, y); }
                }

                path.CloseSubpath();
                gc->FillPath(path);
                break;
            }
            case Shape::Pause:
                gc->DrawRectangle(3.5, 2.5, 3.5, 11);
                gc->DrawRectangle(9, 2.5, 3.5, 11);
                break;
            case Shape::Dot:
                gc->DrawEllipse(2.5, 2.5, 11, 11);
                break;
            case Shape::Ring:
                gc->SetPen(wxPen(color, 2));
                gc->SetBrush(*wxTRANSPARENT_BRUSH);
                gc->DrawEllipse(3, 3, 10, 10);
                break;
            case Shape::Error:
                gc->DrawEllipse(1, 1, 14, 14);
                gc->SetBrush(*wxWHITE_BRUSH);
                gc->DrawRectangle(7, 3.5, 2, 6.5);
                gc->DrawEllipse(6.8, 11, 2.4, 2.4);
                break;
            }
        }

        wxIcon icon;
        icon.CopyFromBitmap(wxBitmap(img));
        return icon;
    }
}

TorrentListModel::TorrentListModel()
    : m_filter(nullptr),
    m_filterLabelId(-1)
{
}

TorrentListModel::~TorrentListModel()
{
}

void TorrentListModel::AddTorrent(pt::BitTorrent::TorrentHandle* torrent)
{
    m_torrents.insert({ torrent->InfoHash(), torrent });

    // Only this torrent can have changed. Re-filtering everything made loading
    // a session quadratic in the number of torrents (each ApplyFilter() scans
    // m_filtered once per torrent).
    ApplyFilter({ torrent });
}

void TorrentListModel::ClearFilter()
{
    m_filter = nullptr;
    ApplyFilter();
}

void TorrentListModel::ClearLabelFilter()
{
    m_filterLabelId = -1;
    ApplyFilter();
}

void TorrentListModel::SetFilter(std::unique_ptr<pt::UI::Filters::TorrentFilter> filter)
{
    m_filter = std::move(filter);
    ApplyFilter();
}

void TorrentListModel::SetLabelFilter(int labelId)
{
    m_filterLabelId = labelId;
    ApplyFilter();
}

TorrentHandle* TorrentListModel::GetTorrentFromItem(wxDataViewItem const& item)
{
    uint32_t row = this->GetRow(item);

    if (row >= m_filtered.size()) { return nullptr; }

    auto find = m_torrents.find(m_filtered.at(row));

    return find == m_torrents.end()
        ? nullptr
        : find->second;
}

void TorrentListModel::RemoveTorrent(lt::info_hash_t const& hash)
{
    m_torrents.erase(hash);

    auto iter = std::find(
        m_filtered.begin(),
        m_filtered.end(),
        hash);

    if (iter != m_filtered.end())
    {
        auto dist = std::distance(m_filtered.begin(), iter);
        m_filtered.erase(iter);
        RowDeleted(dist);
    }
}

void TorrentListModel::UpdateTorrents(std::vector<TorrentHandle*> torrents)
{
    ApplyFilter(torrents);
}

void TorrentListModel::SetStateIconSize(int size)
{
    wxColour const green(46, 160, 67);
    wxColour const blue(47, 128, 237);
    wxColour const gray(140, 140, 140);
    wxColour const amber(224, 160, 32);
    wxColour const red(215, 58, 50);

    wxIcon const checking = makeStateIcon(size, Shape::Dot, amber);
    wxIcon const paused = makeStateIcon(size, Shape::Pause, gray);

    m_stateIcons =
    {
        { TorrentStatus::State::Unknown,             makeStateIcon(size, Shape::Ring, gray) },
        { TorrentStatus::State::Error,               makeStateIcon(size, Shape::Error, red) },
        { TorrentStatus::State::CheckingFiles,       checking },
        { TorrentStatus::State::CheckingResumeData,  checking },
        { TorrentStatus::State::Downloading,         makeStateIcon(size, Shape::ArrowDown, green) },
        { TorrentStatus::State::DownloadingChecking, checking },
        { TorrentStatus::State::DownloadingMetadata, makeStateIcon(size, Shape::Ring, green) },
        { TorrentStatus::State::DownloadingPaused,   paused },
        { TorrentStatus::State::DownloadingQueued,   makeStateIcon(size, Shape::ArrowDown, gray) },
        { TorrentStatus::State::Uploading,           makeStateIcon(size, Shape::ArrowUp, blue) },
        { TorrentStatus::State::UploadingPaused,     paused },
        { TorrentStatus::State::UploadingQueued,     makeStateIcon(size, Shape::ArrowUp, gray) },
    };
}

void TorrentListModel::SetBackgroundColorEnabled(bool enabled)
{
    m_backgroundColorEnabled = enabled;
    Reset(m_filtered.size());
}

int TorrentListModel::Compare(const wxDataViewItem& item1, const wxDataViewItem& item2, unsigned int column, bool ascending) const
{
    unsigned int const row1 = GetRow(item1);
    unsigned int const row2 = GetRow(item2);

    if (row1 >= m_filtered.size() || row2 >= m_filtered.size())
    {
        return 0;
    }

    auto const& lfind = m_torrents.find(m_filtered.at(row1));
    auto const& rfind = m_torrents.find(m_filtered.at(row2));

    if (lfind == m_torrents.end()
        || rfind == m_torrents.end())
    {
        BOOST_LOG_TRIVIAL(warning) << "Invalid compare";
        return 0;
    }

    auto const& lhs = lfind->second->Status();
    auto const& rhs = rfind->second->Status();

    auto hashSort = [](bool ascending, TorrentStatus const& l, TorrentStatus const& r) -> int
    {
        if (l.infoHash < r.infoHash) { return ascending ? -1 :  1; }
        if (l.infoHash > r.infoHash) { return ascending ?  1 : -1; }
        return 0;
    };

    auto nameSort = [&hashSort](bool ascending, TorrentStatus const& l, TorrentStatus const& r) -> int
    {
        auto compvalue = _strcmpi(l.name.c_str(),r.name.c_str());
        if (compvalue < 0) { return ascending ? -1 : 1; }
        else if (compvalue == 0) { return hashSort(ascending, l, r); }
        else{ return ascending ? 1 : -1; }
    };

    auto cmp = [&](auto l, auto r) -> int
    {
        if (l < r) { return ascending ? -1 : 1; }
        if (l > r) { return ascending ? 1 : -1; }
        return hashSort(ascending, lhs, rhs);
    };

    switch (column)
    {
    case Columns::Name:
    {
        return nameSort(ascending, lhs, rhs);
    }
    case Columns::SizeRemaining:
    {
        if (lhs.totalWantedRemaining < rhs.totalWantedRemaining) { return ascending ? -1 : 1; }
        if (lhs.totalWantedRemaining > rhs.totalWantedRemaining) { return ascending ? 1 : -1; }
        if (lhs.totalWantedRemaining == rhs.totalWantedRemaining) { return hashSort(ascending, lhs, rhs); }
        break;
    }
    case Columns::Status:
    {
        if (lhs.state < rhs.state) { return ascending ? -1 : 1; }
        if (lhs.state > rhs.state) { return ascending ? 1 : -1; }
        if (lhs.state == rhs.state) { return hashSort(ascending, lhs, rhs); }
        break;
    }
    case Columns::Progress:
    case Columns::Percent:
    {
        if (lhs.progress < rhs.progress) { return ascending ? -1 : 1; }
        if (lhs.progress > rhs.progress) { return ascending ? 1 : -1; }
        if (lhs.progress == rhs.progress) { return hashSort(ascending, lhs, rhs); }
        break;
    }
    case Columns::ETA:
    {
        if (lhs.eta < rhs.eta) { return ascending ? -1 : 1; }
        if (lhs.eta > rhs.eta) { return ascending ? 1 : -1; }
        if (lhs.eta == rhs.eta) { return hashSort(ascending, lhs, rhs); }
        break;
    }
    case Columns::Size:
        return cmp(lhs.totalWanted, rhs.totalWanted);
    case Columns::Downloaded:
        return cmp(lhs.allTimeDownload, rhs.allTimeDownload);
    case Columns::DownloadSpeed:
        return cmp(lhs.downloadPayloadRate, rhs.downloadPayloadRate);
    case Columns::Uploaded:
        return cmp(lhs.allTimeUpload, rhs.allTimeUpload);
    case Columns::UploadSpeed:
        return cmp(lhs.uploadPayloadRate, rhs.uploadPayloadRate);
    case Columns::Availability:
    {
        if (lhs.availability < rhs.availability) { return ascending ? -1 : 1; }
        if (lhs.availability > rhs.availability) { return ascending ? 1 : -1; }
        if (lhs.availability == rhs.availability) { return hashSort(ascending, lhs, rhs); }
        break;
    }
    case Columns::Ratio:
    {
        if (lhs.ratio < rhs.ratio) { return ascending ? -1 : 1; }
        if (lhs.ratio > rhs.ratio) { return ascending ? 1 : -1; }
        if (lhs.ratio == rhs.ratio) { return hashSort(ascending, lhs, rhs); }
        break;
    }
    case Columns::Seeds:
    case Columns::Peers:
    case Columns::Leechers:
    {
        // Connected first, the swarm size breaks ties.
        auto key = [column](BitTorrent::TorrentStatus const& s)
        {
            switch (column)
            {
            case Columns::Seeds: return std::make_pair(s.seedsCurrent, s.swarmSeeds);
            case Columns::Peers: return std::make_pair(s.seedsCurrent + s.peersCurrent, s.swarmSeeds + s.swarmLeechers);
            default: return std::make_pair(s.peersCurrent, s.swarmLeechers);
            }
        };

        if (key(lhs) < key(rhs)) { return ascending ? -1 : 1; }
        if (key(lhs) > key(rhs)) { return ascending ? 1 : -1; }
        return hashSort(ascending, lhs, rhs);
    }
    case Columns::AddedOn:
    {
        if (lhs.addedOn < rhs.addedOn) { return ascending ? -1 : 1; }
        if (lhs.addedOn > rhs.addedOn) { return ascending ? 1 : -1; }
        if (lhs.addedOn == rhs.addedOn) { return hashSort(ascending, lhs, rhs); }
        break;
    }
    case Columns::CompletedOn:
    {
        if (lhs.completedOn < rhs.completedOn) { return ascending ? -1 : 1; }
        if (lhs.completedOn > rhs.completedOn) { return ascending ? 1 : -1; }
        if (lhs.completedOn == rhs.completedOn) { return hashSort(ascending, lhs, rhs); }
        break;
    }
    case Columns::Label:
    {
        if (lhs.labelName < rhs.labelName) { return ascending ? -1 : 1; }
        if (lhs.labelName > rhs.labelName) { return ascending ? 1 : -1; }
        if (lhs.labelName == rhs.labelName) { return nameSort(ascending, lhs, rhs); }
        break;
    }
    }

    return 0;
}

bool TorrentListModel::GetAttrByRow(unsigned int row, unsigned int col, wxDataViewItemAttr& attr) const
{
    if (row >= m_filtered.size()) { return false; }

    auto findTorrent = m_torrents.find(m_filtered.at(row));

    if (findTorrent == m_torrents.end()) { return false; }

    BitTorrent::TorrentHandle* torrent = findTorrent->second;

    // torrent has a label and a color
    if (torrent->Label() > 0
        && m_labelsColors.find(torrent->Label()) != m_labelsColors.end()
        && m_backgroundColorEnabled)
    {
        attr.SetBackgroundColour(
            m_labelsColors.at(
                torrent->Label()));
    }

    switch (col)
    {
    case Columns::Status:
    {
        BitTorrent::TorrentStatus const& status = torrent->Status();

        if (status.state == TorrentStatus::State::Error)
        {
            attr.SetColour(*wxRED);
            return true;
        }

        return false;
    }
    }

    return false;
}

wxString TorrentListModel::GetColumnType(unsigned int) const
{
    return "string";
}

unsigned int TorrentListModel::GetCount() const
{
    return m_filtered.size();
}

void TorrentListModel::GetValueByRow(wxVariant& variant, uint32_t row, uint32_t col) const
{
    if (row >= m_filtered.size())
    {
        BOOST_LOG_TRIVIAL(warning) << "Row out of range (" << row << ", size: " << m_filtered.size() << ")";
        return;
    }

    auto const& hash = m_filtered.at(row);
    auto findTorrent = m_torrents.find(hash);

    if (findTorrent == m_torrents.end())
    {
        BOOST_LOG_TRIVIAL(warning) << "Could not find torrent by hash";
        return;
    }

    BitTorrent::TorrentHandle* torrent = findTorrent->second;
    BitTorrent::TorrentStatus const& status = torrent->Status();

    // "-" for anything that is zero.
    auto amount = [](std::int64_t bytes) -> std::wstring
    {
        return bytes > 0 ? Utils::toHumanFileSize(bytes) : L"-";
    };

    auto rate = [](int bytes) -> std::wstring
    {
        return bytes > 0
            ? fmt::format(i18n("per_second_format"), Utils::toHumanFileSize(bytes))
            : L"-";
    };

    switch (col)
    {
    case Columns::Name:
    {
        auto icon = m_stateIcons.find(status.state);

        variant << wxDataViewIconText(
            Utils::toStdWString(status.name),
            icon == m_stateIcons.end() ? wxNullIcon : icon->second);

        break;
    }
    case Columns::SizeRemaining:
    {
        variant = status.totalWantedRemaining <= 0
            ? L"-"
            : Utils::toHumanFileSize(status.totalWantedRemaining);
        break;
    }
    case Columns::Status:
    {
        switch (status.state)
        {
        case TorrentStatus::State::CheckingFiles:
        case TorrentStatus::State::DownloadingChecking:
            variant = i18n("state_downloading_checking");
            break;

        case TorrentStatus::State::CheckingResumeData:
            variant = i18n("state_checking_resume_data");
            break;

        case TorrentStatus::State::Downloading:
            variant = i18n("state_downloading");
            break;

        case TorrentStatus::State::DownloadingMetadata:
            variant = i18n("state_downloading_metadata");
            break;

        case TorrentStatus::State::DownloadingPaused:
            variant = i18n("state_downloading_paused");
            break;

        case TorrentStatus::State::DownloadingQueued:
            variant = i18n("state_downloading_queued");
            break;

        case TorrentStatus::State::Error:
            if (status.errorDetails.empty())
            {
                variant = fmt::format(
                    i18n("state_error"),
                    Utils::toStdWString(status.error).c_str());
            }
            else
            {
                variant = fmt::format(
                    i18n("state_error_details"),
                    Utils::toStdWString(status.error).c_str(),
                    Utils::toStdWString(status.errorDetails).c_str());
            }

            break;

        case TorrentStatus::State::Unknown:
            variant = i18n("state_unknown");
            break;

        case TorrentStatus::State::Uploading:
            variant = i18n("state_uploading");
            break;

        case TorrentStatus::State::UploadingPaused:
            variant = i18n("state_uploading_paused");
            break;

        case TorrentStatus::State::UploadingQueued:
            variant = i18n("state_uploading_queued");
            break;
        default:
            variant = "-";
            break;
        }

        break;
    }
    case Columns::Progress:
    {
        variant = static_cast<long>(status.progress * 100);
        break;
    }
    case Columns::Percent:
    {
        variant = fmt::format(L"{:.1f}%", status.progress * 100);
        break;
    }
    case Columns::ETA:
    {
        variant = "-";

        if (status.paused || status.eta.count() <= 0)
        {
            break;
        }

        std::chrono::hours hours_left = std::chrono::duration_cast<std::chrono::hours>(status.eta);
        std::chrono::minutes min_left = std::chrono::duration_cast<std::chrono::minutes>(status.eta - hours_left);
        std::chrono::seconds sec_left = std::chrono::duration_cast<std::chrono::seconds>(status.eta - hours_left - min_left);

        if (hours_left.count() <= 0)
        {
            if (min_left.count() <= 0)
            {
                variant = fmt::format(i18n("eta_s_format"), sec_left.count());
                break;
            }

            variant = fmt::format(i18n("eta_ms_format"), min_left.count(), sec_left.count());
            break;
        }

        variant = fmt::format(
            i18n("eta_hms_format"),
            hours_left.count(),
            min_left.count(),
            sec_left.count());

        break;
    }
    case Columns::Size:
        variant = amount(status.totalWanted);
        break;
    case Columns::Downloaded:
        variant = amount(status.allTimeDownload);
        break;
    case Columns::DownloadSpeed:
        variant = rate(status.downloadPayloadRate);
        break;
    case Columns::Uploaded:
        variant = amount(status.allTimeUpload);
        break;
    case Columns::UploadSpeed:
        variant = rate(status.uploadPayloadRate);
        break;
    case Columns::Availability:
    {
        variant = "-";

        if (status.paused || status.availability < 0)
        {
            break;
        }

        variant = fmt::format("{:.3f}", status.availability);

        break;
    }
    case Columns::Ratio:
    {
        variant = fmt::format("{:.3f}", status.ratio);
        break;
    }
    case Columns::Seeds:
    case Columns::Peers:
    case Columns::Leechers:
    {
        // <connected> (<in swarm>): connected against what the tracker
        // scrape or the peer list knows.
        variant = "-";

        if (status.paused)
        {
            break;
        }

        int connected = status.peersCurrent;
        int swarm = status.swarmLeechers;

        if (col == Columns::Seeds) { connected = status.seedsCurrent; swarm = status.swarmSeeds; }
        if (col == Columns::Peers) { connected += status.seedsCurrent; swarm += status.swarmSeeds; }

        variant = fmt::format("{} ({})", connected, swarm);

        break;
    }
    case Columns::AddedOn:
    {
        variant = wxDateTime(status.addedOn).FormatISOCombined(' ');
        break;
    }
    case Columns::CompletedOn:
    {
        variant = status.completedOn.IsValid()
            ? wxDateTime(status.completedOn).FormatISOCombined(' ')
            : "-";

        break;
    }
    case Columns::Label:
    {
        auto lbl = m_labels.find(torrent->Label());

        if (torrent->Label() < 0 || lbl == m_labels.end())
        {
            variant << wxDataViewIconText("-");
            break;
        }

        wxIcon ic = wxNullIcon;
        auto [name, _] = lbl->second;
        auto labelIcon = m_labelsIcons.find(torrent->Label());

        if (labelIcon != m_labelsIcons.end())
        {
            ic = labelIcon->second;
        }

        variant << wxDataViewIconText(
            Utils::toStdWString(name), ic);

        break;
    }
    }
}

void TorrentListModel::UpdateLabels(std::map<int, std::tuple<std::string, std::string>> const& labels, int size)
{
    std::vector<BitTorrent::TorrentHandle*> torrents;

    for (auto const& infoHash : m_filtered)
    {
        // if this torrent has a label which have changed color, we need to update it
        auto find = m_torrents.find(infoHash);

        if (find == m_torrents.end()) { continue; }

        auto torrent = find->second;

        // skip torrent if no label
        if (torrent->Label() < 0) { continue; }

        auto oldLabel = m_labels.find(torrent->Label());
        auto label = labels.find(torrent->Label());

        // color has changed
        if (oldLabel != m_labels.end()
            && label != labels.end()
            && oldLabel->second != label->second)
        {
            torrents.push_back(torrent);
            continue;
        }

        // color was removed
        if (oldLabel != m_labels.end()
            && label == labels.end())
        {
            torrents.push_back(torrent);
            continue;
        }

        // color was added
        if (oldLabel == m_labels.end()
            && label != labels.end())
        {
            torrents.push_back(torrent);
            continue;
        }
    }

    m_labels = labels;
    m_labelsColors.clear();
    m_labelsIcons.clear();

    for (auto const& [id, nv] : m_labels)
    {
        auto [name, color] = nv;

        if (color.empty()) { continue; }

        m_labelsColors.insert({ id, wxColor(color) });

        wxBitmap bmp(size, size);

        {
            wxMemoryDC dc;
            wxDCBrushChanger dcbc(dc, m_labelsColors.at(id));
            dc.SelectObject(bmp);
            dc.Clear();
        }

        wxIcon ic;
        ic.CopyFromBitmap(bmp);

        m_labelsIcons.insert({ id, ic });
    }

    for (auto const& torrent : torrents)
    {
        auto iter = std::find(
            m_filtered.begin(),
            m_filtered.end(),
            torrent->InfoHash());

        auto dist = std::distance(
            m_filtered.begin(),
            iter);

        RowChanged(dist);
    }
}

void TorrentListModel::ApplyFilter()
{
    std::vector<TorrentHandle*> filter;
    for (auto const& [hash, torrent] : m_torrents)
    {
        filter.push_back(torrent);
    }
    ApplyFilter(filter);
}

void TorrentListModel::ApplyFilter(std::vector<pt::BitTorrent::TorrentHandle*> torrents)
{
    const std::function<bool(TorrentHandle*)> show = [this](TorrentHandle* torrent)
    {
        // if both label id and filter function is set - this function must check that
        // the torrent both has the label and is included in the filter function
        // otherwise, check each
        if (m_filter && m_filterLabelId > 0)
        {
            return m_filter->Includes(*torrent) && torrent->Label() == m_filterLabelId;
        }
        else if (m_filter)
        {
            return m_filter->Includes(*torrent);
        }
        else if (m_filterLabelId > 0)
        {
            return torrent->Label() == m_filterLabelId;
        }

        return true;
    };

    for (auto torrent : torrents)
    {
        auto iter = std::find(
            m_filtered.begin(),
            m_filtered.end(),
            torrent->InfoHash());

        auto dist = std::distance(
            m_filtered.begin(),
            iter);

        // the torrent is not in the list of filtered torrents
        if (iter == m_filtered.end())
        {
            // but we want to show it according to the filters
            if (show(torrent))
            {
                // so show it
                m_filtered.push_back(torrent->InfoHash());
                RowAppended();
            }
        }
        // the torrent *is* in the list of filtered torrents
        else
        {
            // but we don't want to show it
            if (!show(torrent))
            {
                // so delete it
                m_filtered.erase(iter);
                RowDeleted(dist);
            }
            // and we still want to show it
            else
            {
                // so update it
                RowChanged(dist);
            }
        }
    }
}
