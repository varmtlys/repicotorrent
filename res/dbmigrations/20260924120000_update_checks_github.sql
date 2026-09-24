/*
    Update checks ask the RePicoTorrent GitHub releases instead of the
    upstream PicoTorrent API. A user-set URL is kept.
*/

UPDATE setting
    SET value = CASE
            WHEN value IS NULL OR value = default_value
            THEN '"https://api.github.com/repos/varmtlys/repicotorrent/releases/latest"'
            ELSE value
        END,
        default_value = '"https://api.github.com/repos/varmtlys/repicotorrent/releases/latest"'
    WHERE key = 'update_checks.url';
