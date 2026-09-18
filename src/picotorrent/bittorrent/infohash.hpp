#pragma once

#include <sstream>
#include <string>

#include <libtorrent/info_hash.hpp>

namespace pt::BitTorrent
{
    // The database - and every map keyed on a torrent's identity - uses the v1
    // info hash whenever the torrent has one. A torrent added from a v1-only
    // magnet link learns its v2 hash once metadata arrives, so a v2-preferring
    // key would change identity mid-flight. The v1 hash never changes.
    inline std::string infoHashKey(libtorrent::info_hash_t const& ih)
    {
        std::stringstream ss;

        if (ih.has_v1())
        {
            ss << ih.v1;
        }
        else
        {
            ss << ih.v2;
        }

        return ss.str();
    }

    // Look up a container keyed on a torrent's add-time info_hash_t. A hybrid
    // torrent gains its v2 hash when metadata arrives (libtorrent reassigns
    // torrent::m_info_hash in on_metadata and remaps its own table), so alerts
    // start reporting an info_hash_t which no longer equals the key we stored.
    // Fall back to looking up the individual hashes.
    template<typename Map>
    typename Map::iterator findInfoHash(Map& map, libtorrent::info_hash_t const& hash)
    {
        auto it = map.find(hash);
        if (it != map.end()) { return it; }

        if (hash.has_v1())
        {
            it = map.find(libtorrent::info_hash_t(hash.v1));
            if (it != map.end()) { return it; }
        }

        if (hash.has_v2())
        {
            it = map.find(libtorrent::info_hash_t(hash.v2));
            if (it != map.end()) { return it; }
        }

        return map.end();
    }
}
