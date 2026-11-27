#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <memory>
#include <set>
#include <string>
#include <vector>

#include <libtorrent/download_priority.hpp>
#include <libtorrent/fwd.hpp>
#include <libtorrent/info_hash.hpp>
#include <libtorrent/sha1_hash.hpp>
#include <libtorrent/torrent_flags.hpp>
#include <libtorrent/units.hpp>

namespace pt
{
namespace BitTorrent
{
    class Session;
    struct TorrentStatus;

    class TorrentHandle : public wxEvtHandler
    {
        friend class Session;

    public:
        // Stored in the resume data, keep the values.
        enum class DownloadOrder
        {
            // Rarest pieces first, libtorrent's default.
            Normal = 0,
            // The whole torrent in piece order.
            Sequential = 1,
            // Every wanted file front to back, the files side by side.
            FilesSequential = 2,
            // The first and the last pieces of every file first, then the rest.
            FirstLast = 3,
            // The first and the last pieces of every file, then in piece order.
            FirstLastSequential = 4,
        };

        virtual ~TorrentHandle();

        void AddTracker(libtorrent::announce_entry const& entry);
        void FileProgress(std::vector<std::int64_t>& progress, int flags) const;
        std::vector<libtorrent::download_priority_t> GetFilePriorities() const;
        void GetPeerInfo(std::vector<libtorrent::peer_info>& peers) const;
        libtorrent::info_hash_t InfoHash();
        DownloadOrder GetDownloadOrder() const;
        bool IsFilesMissing() const;
        bool IsValid();
        void ReplaceTrackers(std::vector<libtorrent::announce_entry> const& trackers);
        void ScrapeTracker(int trackerIndex);

        // Returned by reference: the status holds a piece bitfield, and this is
        // read once per visible cell per repaint plus O(n log n) times per sort.
        // The reference is invalidated by the next status update, so do not hold
        // on to it across event handlers.
        TorrentStatus const& Status() const;
        std::vector<libtorrent::announce_entry> Trackers() const;

        void ForceReannounce();
        void ForceReannounce(int seconds, int trackerIndex);
        void ForceRecheck();
        void MoveStorage(std::string const& newPath);
        void Pause();
        void QueueUp();
        void QueueDown();
        void QueueTop();
        void QueueBottom();
        void Remove();
        void RemoveFiles();
        void Resume();
        void ResumeForce();
        void SetFilePriorities(std::vector<libtorrent::download_priority_t> priorities);
        void SetFilePriority(libtorrent::file_index_t index, libtorrent::download_priority_t priority);
        void SetDownloadOrder(DownloadOrder order);

        // Labels
        int Label();
        std::string const& LabelName() const;
        void ClearLabel();
        void SetLabel(int id, std::string const& name, bool muted = false);

        void SetComment(std::string const& comment);

        libtorrent::torrent_handle& WrappedHandle();

    private:
        TorrentHandle(Session* session, libtorrent::torrent_handle const& th);

        void BuildStatus(libtorrent::torrent_status const& ts);
        std::unique_ptr<TorrentStatus> Update(libtorrent::torrent_status const& ts);
        std::int64_t CompletedFilesSize(libtorrent::torrent_status const& ts);
        void ApplyDownloadOrder(libtorrent::torrent_status const& ts);
        void ResetPieceDeadlines();

        // The folder (multi-file torrent) or the file the data lives in, empty
        // when nothing is downloaded yet - then there is nothing to miss.
        std::string DataRoot() const;
        // Stops the torrent until its data shows up again. wasRunning and
        // autoManaged are what it goes back to then.
        void SetFilesMissing(std::string const& path, bool wasRunning, bool autoManaged);
        void SetFilesFound();
        bool WasRunning() const;
        bool WasAutoManaged() const;
        // Writes the state the torrent had before its data went missing, so a
        // restart while it is missing does not leave it stopped for good.
        void PatchResumeData(libtorrent::add_torrent_params& params) const;

        Session* m_session;
        std::unique_ptr<libtorrent::torrent_handle> m_th;
        std::unique_ptr<TorrentStatus> m_status;

        // The info hash the torrent was added with. A hybrid torrent's live
        // info_hash_t gains its v2 hash when metadata arrives, which would
        // silently invalidate every map keyed on this value.
        libtorrent::info_hash_t m_infoHash;

        int m_labelId = -1;
        std::string m_labelName;
        std::string m_comment;

        // CompletedFilesSize() is only recomputed when the piece count changes.
        int m_completedPieces = -1;
        std::int64_t m_completedSize = 0;

        // From the last status, so callers need no blocking flags() call.
        libtorrent::torrent_flags_t m_flags{};
        bool m_hasError = false;

        DownloadOrder m_downloadOrder = DownloadOrder::Normal;
        // Pieces given a deadline (time-critical) by ApplyDownloadOrder().
        std::set<libtorrent::piece_index_t> m_deadlines;
        // Cached; invalidated whenever the file priorities change.
        std::vector<libtorrent::download_priority_t> m_filePriorities;
        // FirstLast*: the pieces at both ends of every wanted file.
        std::vector<libtorrent::piece_index_t> m_firstLast;
        // FilesSequential: per file, the first piece which may still be missing.
        std::vector<libtorrent::piece_index_t> m_cursor;

        bool m_missing = false;
        bool m_resumeWhenFound = false;
        bool m_autoManagedWhenFound = true;
        std::string m_missingPath;
    };
}
}
