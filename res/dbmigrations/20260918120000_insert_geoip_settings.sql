/* Peer country lookups, backed by the DB-IP Lite country database */
INSERT OR IGNORE INTO setting (key, value, default_value)
VALUES ('geoip.enabled', NULL, 'true');
