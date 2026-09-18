#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <cstdint>
#include <memory>
#include <string>

#include <libtorrent/bitfield.hpp>
#include <libtorrent/torrent_info.hpp>
#include <wx/datetime.h>

namespace pt
{
namespace BitTorrent
{
    struct TorrentStatus
    {
        enum State
        {
            Unknown,
            Error,
            CheckingFiles,
            CheckingResumeData,
            Downloading,
            DownloadingChecking,
            DownloadingMetadata,
            DownloadingPaused,
            DownloadingQueued,
            Uploading,
            UploadingPaused,
            UploadingQueued
        };

        // Every member is initialized here: a status built for an invalid
        // torrent handle only fills in infoHash, and the UI reads the rest.
        wxDateTime                                            addedOn;
        std::int64_t                                          allTimeDownload      = 0;
        std::int64_t                                          allTimeUpload        = 0;
        float                                                 availability         = 0;
        wxDateTime                                            completedOn;
        int                                                   downloadPayloadRate  = 0;
        bool                                                  forced               = false;
        std::string                                           error;
        std::string                                           errorDetails;
        std::chrono::seconds                                  eta{ 0 };
        std::string                                           infoHash;
        std::string                                           labelName;
        std::chrono::seconds                                  lastDownload{ -1 };
        std::chrono::seconds                                  lastUpload{ -1 };
        std::string                                           name;
        bool                                                  paused               = false;
        int                                                   peersCurrent         = 0;
        int                                                   peersTotal           = 0;
        libtorrent::typed_bitfield<libtorrent::piece_index_t> pieces;
        float                                                 progress             = 0;
        int                                                   queuePosition        = -1;
        float                                                 ratio                = 0;
        std::string                                           savePath;
        int                                                   seedsCurrent         = 0;
        int                                                   seedsTotal           = 0;
        int                                                   swarmSeeds           = 0;
        int                                                   swarmLeechers        = 0;
        State                                                 state                = State::Unknown;
        std::weak_ptr<const libtorrent::torrent_info>         torrentFile;
        std::int64_t                                          totalWanted          = 0;
        std::int64_t                                          totalWantedRemaining = 0;
        int                                                   uploadPayloadRate    = 0;
    };
}
}
