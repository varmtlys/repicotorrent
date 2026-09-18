/*
    WebTorrent (wss trackers, WebRTC swarms). libtorrent 2.1 builds it
    in; outgoing STUN traffic goes to a public server, so it is disabled by
    default - max_webtorrent_offers 0 turns WebTorrent offers off.
*/

INSERT OR IGNORE INTO setting (key, value, default_value)
    VALUES ('webtorrent.enabled', NULL, 'false');
