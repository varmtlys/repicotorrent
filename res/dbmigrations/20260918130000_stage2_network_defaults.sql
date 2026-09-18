/*
    Network defaults for protocol relevance:

    - an IPv6 listen interface (DHT over IPv6, BEP 32, and IPv6 peers),
      mirroring whatever port the IPv4 any-address entry uses;
    - the DHT bootstrap node list: dht.aelitis.com was Azureus/Vuze
      infrastructure which no longer exists, dht.libtorrent.org is the
      bootstrap shipped with libtorrent itself;
    - disk_write_mode 1 (always_mmap_write) is the libtorrent default and
      keeps reads and writes on the same code path - auto_mmap_write (2)
      may mix mmap reads with write() calls, which can corrupt data on
      Windows. hashing_threads 2 verifies the per-file hash trees of
      v2 torrents faster. Users who changed these values themselves are
      not touched - only default_value is updated.
*/

INSERT INTO listen_interface (address, port)
    SELECT '[::]', port
    FROM listen_interface
    WHERE address = '0.0.0.0'
      AND NOT EXISTS (SELECT 1 FROM listen_interface WHERE address = '[::]');

DELETE FROM dht_bootstrap_node WHERE hostname = 'dht.aelitis.com';

INSERT OR IGNORE INTO dht_bootstrap_node (hostname, port)
    VALUES ('dht.libtorrent.org', 25401);

UPDATE setting SET default_value = '1' WHERE key = 'libtorrent.disk_write_mode';
UPDATE setting SET default_value = '2' WHERE key = 'libtorrent.hashing_threads';
