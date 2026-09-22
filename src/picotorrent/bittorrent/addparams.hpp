#pragma once

namespace pt::BitTorrent
{
    struct AddParams
    {
        int labelId;
        std::string labelName;
        // libtorrent 2.1 leaves the comment out of add_torrent_alert::params,
        // so it travels here instead.
        std::string comment;
    };
}
