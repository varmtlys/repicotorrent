#pragma once

#include <string>

#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/announce_entry.hpp>
#include <libtorrent/magnet_uri.hpp>
#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/torrent_status.hpp>

namespace pt::BitTorrent
{
    // make_magnet_uri(torrent_handle) is deprecated in libtorrent 2.1, and the
    // add_torrent_params overload prints only what is in atp - it no longer
    // reads the name and trackers out of atp.ti. Without these the link is
    // a bare hash that has to be found through DHT alone.
    inline std::string makeMagnetUri(libtorrent::torrent_handle const& th)
    {
        libtorrent::torrent_status const ts = th.status(libtorrent::torrent_handle::query_name);

        libtorrent::add_torrent_params atp;
        atp.info_hashes = ts.info_hashes;
        atp.name = ts.name;

        for (libtorrent::announce_entry const& ae : th.trackers())
        {
            atp.trackers.push_back(ae.url);
        }

        for (std::string const& s : th.url_seeds())
        {
            atp.url_seeds.push_back(s);
        }

        return libtorrent::make_magnet_uri(atp);
    }
}
