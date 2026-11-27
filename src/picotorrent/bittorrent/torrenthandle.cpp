#include "torrenthandle.hpp"

#include <algorithm>
#include <filesystem>

#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/announce_entry.hpp>
#include <libtorrent/session.hpp>
#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/torrent_info.hpp>
#include <libtorrent/torrent_status.hpp>

#include "../core/utils.hpp"
#include "session.hpp"
#include "torrentstatus.hpp"

namespace lt = libtorrent;
using pt::BitTorrent::TorrentHandle;
using pt::BitTorrent::TorrentStatus;

TorrentStatus::State getTorrentStatusState(lt::torrent_status const& ts)
{
    bool paused = ((ts.flags & lt::torrent_flags::paused)
        && !(ts.flags & lt::torrent_flags::auto_managed));

    bool seeding = (ts.state == lt::torrent_status::state_t::seeding
        || ts.state == lt::torrent_status::state_t::finished);

    bool queued = ((ts.flags & lt::torrent_flags::paused)
        && (ts.flags & lt::torrent_flags::auto_managed));

    bool checking = (ts.state == lt::torrent_status::state_t::checking_files
        || ts.state == lt::torrent_status::state_t::checking_resume_data);

    if (ts.errc)
    {
        return TorrentStatus::State::Error;
    }

    // Waiting for its turn: libtorrent checks active_checking torrents at
    // a time.
    if (queued && ts.state == lt::torrent_status::state_t::checking_files)
    {
        return TorrentStatus::State::CheckingQueued;
    }

    if (paused)
    {
        if (seeding)
        {
            return TorrentStatus::State::UploadingPaused;
        }

        return TorrentStatus::State::DownloadingPaused;
    }
    else
    {
        if (queued && !checking)
        {
            return seeding
                ? TorrentStatus::State::UploadingQueued
                : TorrentStatus::State::DownloadingQueued;
        }
        else
        {
            switch (ts.state)
            {
            case lt::torrent_status::state_t::finished:
            case lt::torrent_status::state_t::seeding:
                return paused
                    ? TorrentStatus::State::UploadingPaused
                    : TorrentStatus::State::Uploading;

            case lt::torrent_status::state_t::checking_resume_data:
                return TorrentStatus::State::CheckingResumeData;

            case lt::torrent_status::state_t::checking_files:
                return TorrentStatus::State::DownloadingChecking;

            case lt::torrent_status::state_t::downloading_metadata:
                return TorrentStatus::State::DownloadingMetadata;

            case lt::torrent_status::state_t::downloading:
                return TorrentStatus::State::Downloading;
            }
        }
    }

    return TorrentStatus::State::Unknown;
}

TorrentHandle::TorrentHandle(pt::BitTorrent::Session* session, lt::torrent_handle const& th)
    : m_session(session),
    m_infoHash(th.info_hashes())
{
    m_th = std::make_unique<lt::torrent_handle>(th);
    m_status = Update(th.status());

    if (m_flags & lt::torrent_flags::sequential_download) { m_downloadOrder = DownloadOrder::Sequential; }
}

TorrentHandle::~TorrentHandle()
{
}

void TorrentHandle::AddTracker(lt::announce_entry const& entry)
{
    m_th->add_tracker(entry);
}

void TorrentHandle::FileProgress(std::vector<std::int64_t>& progress, int flags) const
{
    m_th->file_progress(
        progress,
        flags >= 1
            ? lt::torrent_handle::piece_granularity
            : lt::file_progress_flags_t{});
}

void TorrentHandle::ForceReannounce()
{
    m_th->force_reannounce();
}

void TorrentHandle::ForceReannounce(int seconds, int trackerIndex)
{
    m_th->force_reannounce(seconds, trackerIndex);
}

void TorrentHandle::ForceRecheck()
{
    bool autoManaged = static_cast<bool>(m_flags & lt::torrent_flags::auto_managed);
    // Stopped by the user - not queued, and not stopped by an error.
    bool stopped = (m_flags & lt::torrent_flags::paused) && !autoManaged && !m_hasError;

    // Checking a missing folder is asking for the data to be downloaded
    // again - which is what a recheck is for. Afterwards it goes the way it
    // was waiting to go.
    if (m_missing)
    {
        m_missing = false;
        autoManaged = m_resumeWhenFound && m_autoManagedWhenFound;
        stopped = !m_resumeWhenFound;
    }

    // libtorrent checks one torrent at a time (active_checking), but only
    // auto-managed ones; the others were all checked at once. Auto-managed
    // for the check, then back to what it was.
    if (!autoManaged)
    {
        m_session->RestoreAfterRecheck(this, stopped);
    }

    m_th->set_flags(lt::torrent_flags::auto_managed);
    m_th->force_recheck();
    m_status = Update(m_th->status());
}

std::vector<lt::download_priority_t> TorrentHandle::GetFilePriorities() const
{
    return m_th->get_file_priorities();
}

void TorrentHandle::GetPeerInfo(std::vector<lt::peer_info>& peers) const
{
    m_th->get_peer_info(peers);
}

lt::info_hash_t TorrentHandle::InfoHash()
{
    return m_infoHash;
}

TorrentHandle::DownloadOrder TorrentHandle::GetDownloadOrder() const
{
    return m_downloadOrder;
}

bool TorrentHandle::IsFilesMissing() const
{
    return m_missing;
}

bool TorrentHandle::IsValid()
{
    return m_th->is_valid();
}

void TorrentHandle::MoveStorage(std::string const& newPath)
{
    m_th->move_storage(newPath);
}

void TorrentHandle::Pause()
{
    m_resumeWhenFound = false;
    if (m_missing) { m_status->paused = true; }
    m_th->unset_flags(lt::torrent_flags::auto_managed);
    m_th->pause(lt::torrent_handle::graceful_pause);
}

void TorrentHandle::QueueUp()
{
    m_th->queue_position_up();
}

void TorrentHandle::QueueDown()
{
    m_th->queue_position_down();
}

void TorrentHandle::QueueTop()
{
    m_th->queue_position_top();
}

void TorrentHandle::QueueBottom()
{
    m_th->queue_position_bottom();
}

void TorrentHandle::ReplaceTrackers(std::vector<lt::announce_entry> const& trackers)
{
    m_th->replace_trackers(trackers);
}

void TorrentHandle::Remove()
{
    m_session->RemoveTorrent(this);
}

void TorrentHandle::RemoveFiles()
{
    m_session->RemoveTorrent(this, lt::session_handle::delete_files);
}

void TorrentHandle::Resume()
{
    // Started once the data is back; started now it would download into
    // a folder which is not there, or recreate it.
    if (m_missing) { m_resumeWhenFound = true; m_autoManagedWhenFound = true; m_status->paused = false; return; }

    m_th->set_flags(lt::torrent_flags::auto_managed);
    m_th->clear_error();
    m_th->resume();
}

void TorrentHandle::ResumeForce()
{
    if (m_missing) { m_resumeWhenFound = true; m_autoManagedWhenFound = false; m_status->paused = false; return; }

    m_th->unset_flags(lt::torrent_flags::auto_managed);
    m_th->clear_error();
    m_th->resume();
}

void TorrentHandle::ScrapeTracker(int trackerIndex)
{
    m_th->scrape_tracker(trackerIndex);
}

void TorrentHandle::SetFilePriorities(std::vector<lt::download_priority_t> priorities)
{
    m_th->prioritize_files(priorities);
    m_filePriorities.clear();
    m_firstLast.clear();
    m_deadlines.clear();
}

void TorrentHandle::SetFilePriority(lt::file_index_t index, lt::download_priority_t priority)
{
    m_th->file_priority(index, priority);
    m_filePriorities.clear();
    m_firstLast.clear();
    m_deadlines.clear();
}

void TorrentHandle::SetDownloadOrder(DownloadOrder order)
{
    if (order == m_downloadOrder) { return; }

    if (order == DownloadOrder::Sequential || order == DownloadOrder::FirstLastSequential)
    {
        m_th->set_flags(lt::torrent_flags::sequential_download);
    }
    else
    {
        m_th->unset_flags(lt::torrent_flags::sequential_download);
    }

    ResetPieceDeadlines();
    m_downloadOrder = order;

    // The order is kept in the resume data only (see Session).
    m_th->save_resume_data(lt::torrent_handle::save_info_dict);
}

void TorrentHandle::ResetPieceDeadlines()
{
    if (!m_deadlines.empty())
    {
        m_th->clear_piece_deadlines();

        // Dropping a deadline leaves the piece at low priority instead of
        // the one it had; the file priorities set them all over again.
        m_th->prioritize_files(m_th->get_file_priorities());
    }

    m_deadlines.clear();
    m_filePriorities.clear();
    m_firstLast.clear();
    m_cursor.clear();
}

void TorrentHandle::ApplyDownloadOrder(lt::torrent_status const& ts)
{
    if (m_downloadOrder == DownloadOrder::Normal || m_downloadOrder == DownloadOrder::Sequential) { return; }
    if (ts.state != lt::torrent_status::state_t::downloading) { return; }
    if (ts.flags & lt::torrent_flags::paused) { return; }

    auto ti = ts.torrent_file.lock();
    if (!ti) { return; }

    auto const& fs = ti->layout();
    if (ts.pieces.size() != fs.num_pieces()) { return; }

    if (m_filePriorities.size() != static_cast<size_t>(fs.num_files()))
    {
        m_filePriorities = m_th->get_file_priorities();
        if (m_filePriorities.size() != static_cast<size_t>(fs.num_files())) { return; }
    }

    // A deadline raises a piece to the top priority, so pieces of skipped
    // files must never get one.
    auto wanted = [&](lt::file_index_t f)
    {
        return !fs.pad_file_at(f)
            && fs.file_size(f) > 0
            && m_filePriorities[static_cast<int>(f)] > lt::dont_download;
    };

    auto firstPiece = [&](lt::file_index_t f) { return fs.map_file(f, 0, 1).piece; };
    auto lastPiece = [&](lt::file_index_t f) { return fs.map_file(f, fs.file_size(f) - 1, 1).piece; };

    std::vector<std::pair<lt::piece_index_t, int>> want;

    if (m_downloadOrder == DownloadOrder::FirstLast || m_downloadOrder == DownloadOrder::FirstLastSequential)
    {
        if (m_firstLast.empty())
        {
            for (lt::file_index_t f : fs.file_range())
            {
                if (!wanted(f)) { continue; }

                int const first = static_cast<int>(firstPiece(f));
                int const last = static_cast<int>(lastPiece(f));
                // 1% of the file at either end, at least one piece: enough for
                // a player to read the header and the index.
                int const span = std::max(1, (last - first + 1) / 100);

                for (int p = first; p < std::min(first + span, last + 1); p++) { m_firstLast.push_back(lt::piece_index_t{ p }); }
                for (int p = std::max(first, last - span + 1); p <= last; p++) { m_firstLast.push_back(lt::piece_index_t{ p }); }
            }

            std::sort(m_firstLast.begin(), m_firstLast.end());
            m_firstLast.erase(std::unique(m_firstLast.begin(), m_firstLast.end()), m_firstLast.end());
        }

        for (lt::piece_index_t p : m_firstLast) { want.push_back({ p, 0 }); }
    }
    else
    {
        // ponytail: a fixed window per file and overall; the files past the
        // budget wait for the ones before them to finish.
        int constexpr perFile = 4;
        int budget = 32;

        if (m_cursor.size() != static_cast<size_t>(fs.num_files()))
        {
            m_cursor.assign(fs.num_files(), lt::piece_index_t{ -1 });
        }

        for (lt::file_index_t f : fs.file_range())
        {
            if (budget <= 0) { break; }
            if (!wanted(f)) { continue; }

            lt::piece_index_t& p = m_cursor[static_cast<int>(f)];
            lt::piece_index_t const last = lastPiece(f);

            if (p < firstPiece(f)) { p = firstPiece(f); }
            while (p <= last && ts.pieces.get_bit(p)) { ++p; }

            int taken = 0;

            for (lt::piece_index_t q = p; q <= last && taken < perFile; ++q)
            {
                if (ts.pieces.get_bit(q)) { continue; }

                // Earlier pieces of a file get earlier deadlines.
                want.push_back({ q, taken * 1000 });
                taken++;
            }

            budget -= taken;
        }
    }

    for (auto const& [piece, deadline] : want)
    {
        if (ts.pieces.get_bit(piece)) { continue; }
        if (m_deadlines.insert(piece).second) { m_th->set_piece_deadline(piece, deadline); }
    }
}

TorrentStatus const& TorrentHandle::Status() const
{
    return *m_status;
}

std::vector<lt::announce_entry> TorrentHandle::Trackers() const
{
    return m_th->trackers();
}

void TorrentHandle::ClearLabel()
{
    m_labelId = -1;
    m_session->UpdateTorrentLabel(this);
}

int TorrentHandle::Label()
{
    return m_labelId;
}

std::string const& TorrentHandle::LabelName() const
{
    return m_labelName;
}

void TorrentHandle::BuildStatus(libtorrent::torrent_status const& ts)
{
    m_status = Update(ts);
    ApplyDownloadOrder(ts);
}

std::string TorrentHandle::DataRoot() const
{
    TorrentStatus const& s = *m_status;
    if (s.pieces.none_set() && !m_missing) { return {}; }

    // A recheck clears the pieces of missing files and downloads them again,
    // which is what it was asked for.
    if (s.state == TorrentStatus::State::CheckingFiles
        || s.state == TorrentStatus::State::CheckingResumeData
        || s.state == TorrentStatus::State::DownloadingChecking)
    {
        return {};
    }


    auto ti = s.torrentFile.lock();
    if (!ti) { return {}; }

    auto const& fs = ti->layout();

    for (lt::file_index_t f : fs.file_range())
    {
        if (fs.pad_file_at(f)) { continue; }

        // <save path>/<torrent folder> or <save path>/<file>
        std::filesystem::path rel(Utils::toStdWString(fs.file_path(f)));
        std::filesystem::path root = std::filesystem::path(Utils::toStdWString(s.savePath)) / *rel.begin();
        return Utils::toStdString(root.wstring());
    }

    return {};
}

void TorrentHandle::SetFilesMissing(std::string const& path, bool wasRunning, bool autoManaged)
{
    m_missing = true;
    m_missingPath = path;
    m_resumeWhenFound = wasRunning;
    m_autoManagedWhenFound = autoManaged;

    m_th->unset_flags(lt::torrent_flags::auto_managed);
    m_th->pause();

    m_status = Update(m_th->status());
}

void TorrentHandle::SetFilesFound()
{
    m_missing = false;
    m_th->clear_error();

    if (m_resumeWhenFound)
    {
        if (m_autoManagedWhenFound) { m_th->set_flags(lt::torrent_flags::auto_managed); }
        m_th->resume();
    }

    m_status = Update(m_th->status());
}

bool TorrentHandle::WasRunning() const
{
    // Queued (paused by the auto manager) counts as running; an error has
    // paused it, but it was running when the error hit.
    return m_hasError
        || !(m_flags & lt::torrent_flags::paused)
        || (m_flags & lt::torrent_flags::auto_managed);
}

bool TorrentHandle::WasAutoManaged() const
{
    return static_cast<bool>(m_flags & lt::torrent_flags::auto_managed);
}

void TorrentHandle::PatchResumeData(lt::add_torrent_params& params) const
{
    if (!m_missing) { return; }

    if (m_resumeWhenFound) { params.flags &= ~lt::torrent_flags::paused; }
    else { params.flags |= lt::torrent_flags::paused; }

    if (m_resumeWhenFound && m_autoManagedWhenFound) { params.flags |= lt::torrent_flags::auto_managed; }
    else { params.flags &= ~lt::torrent_flags::auto_managed; }
}


void TorrentHandle::SetComment(std::string const& comment)
{
    m_comment = comment;
}

void TorrentHandle::SetLabel(int id, std::string const& name, bool muted)
{
    m_labelId = id;
    m_labelName = name;

    if (!muted)
    {
        m_session->UpdateTorrentLabel(this);
    }
}

std::unique_ptr<TorrentStatus> TorrentHandle::Update(lt::torrent_status const& ts)
{
    std::stringstream hash;

    if (ts.info_hashes.has_v2())
    {
        hash << ts.info_hashes.v2;
    }
    else
    {
        hash << ts.info_hashes.v1;
    }

    std::string v1Hash;
    std::string v2Hash;

    if (ts.info_hashes.has_v1()) { std::stringstream ss; ss << ts.info_hashes.v1; v1Hash = ss.str(); }
    if (ts.info_hashes.has_v2()) { std::stringstream ss; ss << ts.info_hashes.v2; v2Hash = ss.str(); }

    if (!m_th->is_valid())
    {
        TorrentStatus invalid;
        invalid.infoHash = hash.str();
        invalid.v1Hash = v1Hash;
        invalid.v2Hash = v2Hash;
        invalid.comment = m_comment;
        return std::make_unique<TorrentStatus>(invalid);
    }

    auto eta = std::chrono::seconds(0);

    if ((ts.total_wanted - ts.total_wanted_done > 0) && ts.download_payload_rate > 0)
    {
        eta = std::chrono::seconds((ts.total_wanted - ts.total_wanted_done) / ts.download_payload_rate);
    }

    float ratio = 0;
    auto ti = ts.torrent_file.lock();

    if (ti && ts.all_time_upload > 0)
    {
        ratio = static_cast<float>(ts.all_time_upload) / static_cast<float>(ti->total_size());
    }

    std::string error;
    std::string error_details;

    if (ts.errc)
    {
        error = ts.errc.message();

        // If we have an error in a file, get file info

        if (ts.error_file >= lt::file_index_t{ 0 } && ti)
        {
            error_details = ti->layout().file_path(ts.error_file);
        }
    }

    TorrentStatus nts;
    nts.addedOn = wxDateTime(ts.added_time);
    nts.allTimeDownload = ts.all_time_download;
    nts.allTimeUpload = ts.all_time_upload;
    nts.availability = ts.distributed_copies;
    nts.completedFilesSize = CompletedFilesSize(ts);
    nts.completedOn = ts.completed_time > 0 ? wxDateTime(ts.completed_time) : wxDateTime();
    nts.downloadPayloadRate = ts.download_payload_rate;
    nts.error = error;
    nts.errorDetails = error_details;
    nts.eta = eta;
    nts.forced = (!(ts.flags & lt::torrent_flags::paused) && !(ts.flags & lt::torrent_flags::auto_managed));
    nts.infoHash = hash.str();
    nts.v1Hash = v1Hash;
    nts.v2Hash = v2Hash;
    nts.comment = m_comment;
    nts.labelName = m_labelName;
    nts.lastDownload = ts.last_download.time_since_epoch().count() > 0 ? std::chrono::seconds(lt::total_seconds(lt::clock_type::now() - ts.last_download)) : std::chrono::seconds(-1);
    nts.lastUpload = ts.last_upload.time_since_epoch().count() > 0 ? std::chrono::seconds(lt::total_seconds(lt::clock_type::now() - ts.last_upload)) : std::chrono::seconds(-1);
    nts.name = ts.name.empty() ? nts.infoHash : ts.name;
    // ts.flags is the same value torrent_handle::flags() would return, except
    // that flags() is a blocking round-trip to the session thread - once per
    // torrent per second, from the UI thread.
    nts.paused = (ts.flags & lt::torrent_flags::paused) == lt::torrent_flags::paused;
    nts.peersCurrent = ts.num_peers - ts.num_seeds;
    nts.pieces = ts.pieces;
    nts.progress = ts.progress;
    nts.queuePosition = static_cast<int>(ts.queue_position);
    nts.ratio = ratio;
    nts.savePath = ts.save_path;
    // Not seeding_duration: that only runs while every piece is there, so it
    // stood still for torrents with skipped files, and it leaves out the time
    // spent downloading, while allTimeUpload counts the uploads made then.
    nts.activeTime = std::chrono::duration_cast<std::chrono::seconds>(ts.active_duration);
    nts.seedsCurrent = ts.num_seeds;

    // The tracker's scrape counts the whole swarm but is -1 until it answers,
    // and misses peers only DHT/PeX told us about - take whichever is larger.
    nts.swarmSeeds = std::max(ts.num_complete, ts.list_seeds);
    nts.swarmLeechers = std::max(ts.num_incomplete, ts.list_peers - ts.list_seeds);
    nts.state = getTorrentStatusState(ts);
    nts.torrentFile = ts.torrent_file;
    nts.totalWanted = ts.total_wanted;
    nts.totalWantedRemaining = ts.total_wanted - ts.total_wanted_done;
    nts.uploadPayloadRate = ts.upload_payload_rate;

    m_flags = ts.flags;
    m_hasError = static_cast<bool>(ts.errc);

    if (m_missing)
    {
        nts.state = TorrentStatus::State::FilesMissing;
        nts.missingPath = m_missingPath;
        // Whether it starts once the data is back - what Resume, Pause and
        // the Space key look at.
        nts.paused = !m_resumeWhenFound;
    }

    return std::make_unique<TorrentStatus>(nts);
}

std::int64_t TorrentHandle::CompletedFilesSize(lt::torrent_status const& ts)
{
    if (ts.num_pieces == m_completedPieces) { return m_completedSize; }

    auto ti = ts.torrent_file.lock();
    if (!ti) { return 0; }

    auto const& fs = ti->layout();
    if (ts.pieces.size() != fs.num_pieces()) { return 0; }

    // A file is complete when every piece it touches is. The pieces come
    // with the status anyway, so no round-trip to the session thread.
    // ponytail: skipped files fully covered by pieces of wanted ones count
    // too; filter by file priority if that ever shows.
    std::int64_t total = 0;

    for (lt::file_index_t f : fs.file_range())
    {
        std::int64_t const size = fs.file_size(f);
        if (size == 0 || fs.pad_file_at(f)) { continue; }

        lt::piece_index_t const first = fs.map_file(f, 0, 1).piece;
        lt::piece_index_t const last = fs.map_file(f, size - 1, 1).piece;
        bool complete = true;

        for (lt::piece_index_t p = first; p <= last; ++p)
        {
            if (!ts.pieces.get_bit(p)) { complete = false; break; }
        }

        if (complete) { total += size; }
    }

    m_completedPieces = ts.num_pieces;
    m_completedSize = total;
    return total;
}

lt::torrent_handle& TorrentHandle::WrappedHandle()
{
    return *m_th.get();
}
