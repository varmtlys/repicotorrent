# Changelog

Versions follow [Semantic Versioning](https://semver.org). A release is a
`vX.Y.Z` tag; its notes are the matching section below.

## 0.26.2

### Changed

- New icon: the drop in purple, inside an update ring.
- The client identifies as RePicoTorrent: peer id `-RP0262-`, user agent
  `RePicoTorrent/0.26.2` (was PicoTorrent's `-PI`). Private trackers with
  a client whitelist may not know it yet.
- The window title shows the version.
- Sizes (KB, MB, GB) follow the language picked in the program instead
  of the Windows language.
- Copies in different folders run side by side, each with its own
  single instance.
- The database is now `RePicoTorrent.sqlite`. An existing
  `PicoTorrent.sqlite` next to the exe is renamed on the first start, so
  moving from PicoTorrent is just copying it into the RePicoTorrent
  folder. Log files are named `RePicoTorrent.<date>.log`.

## 0.26.1

### Downloads

- `RePicoTorrent-0.26.1-x64.zip` for 64-bit Windows 10/11.
- `RePicoTorrent-0.26.1-x86.zip` for 32-bit Windows.
- `RePicoTorrent-0.26.1-arm64.zip` for Windows on ARM (new). This build
  has no crash dump handler: the bundled Crashpad does not support ARM64.

### New

- Updates install from the app: when a new release is out, **Download
  and install** fetches the zip for your Windows from GitHub, checks it
  against `SHA256SUMS.txt`, replaces the program files and restarts.
  Settings and torrents are kept. Replaced files stay as `*.old` until
  the next start.
- Native Windows on ARM64 build.

### Fixed

- The Russian "new version available" title showed `{0}` instead of the
  version.
- Restarting after a settings change failed when the program folder had
  a space in its path.

## 0.26.0

The first RePicoTorrent release: PicoTorrent 0.25 restarted on
libtorrent 2.1.

### Downloads

- `RePicoTorrent-0.26.0-x64.zip` for 64-bit Windows 10/11, including
  Windows on ARM through its built-in x64 emulation.
- `RePicoTorrent-0.26.0-x86.zip` for 32-bit Windows.

Unpack and run `RePicoTorrent.exe`. The build is portable: settings and
torrents are kept next to the exe, and the Visual C++ runtime is included.
`SHA256SUMS.txt` lists the checksums of the archives.

### Moving from PicoTorrent

- Copy `PicoTorrent.sqlite` from your PicoTorrent folder next to
  `RePicoTorrent.exe`. Torrents, settings and labels are picked up as they
  are.
- To bring torrents over from qBittorrent, use **File > Import from
  qBittorrent**. Progress, trackers, upload/download counters, save paths
  and comments are kept, and qBittorrent's own files are only read. Do not
  seed the same torrents from both clients at the same time.
- Trackers still see the client as PicoTorrent (`PicoTorrent/0.26.0`,
  peer id `-PI0260-`), so client whitelists keep working.

### New

- Import from qBittorrent.
- Torrent list: state icons, separate size, downloaded, download rate,
  uploaded and upload rate columns, a percent done column, and separate
  seeds, peers and leechers columns shown as connected (in swarm).
- Peers tab: country (DB-IP Lite), seed/leecher, downloaded and uploaded
  columns, and flags spelled out in words.
- Files tab: percent done, folder totals, double click opens a file.
- Comments with a link open it in the browser.
- v1 and v2 info hashes of hybrid torrents are both shown.
- Status bar: totals downloaded and uploaded since start.
- Dark theme reworked: menus, tabs, lists and progress bars.
- WebTorrent option (off by default).
- Update checks against the RePicoTorrent releases on GitHub.

### Changed

- libtorrent 2.1.1, Boost 1.92, OpenSSL 3.6.
- DHT hardened by default (BEP 42, BEP 43), IPv6 listening next to IPv4,
  a working DHT bootstrap node.
- Crash dumps are written locally only and never uploaded.

### Fixed

- Torrent comments disappearing after a restart.
- Crashes on startup with databases from older releases, on exporting v2
  and hybrid torrents, and with missing settings.
- Lost resume data when libtorrent's alert queue overflowed.
- Hybrid torrents found twice (v1 and v2) failing both copies.
- Exported and stored magnet links without trackers.
- Torrents created without their trackers.
- Details tabs staying empty after switching tabs on an idle torrent.
- DDE errors when starting while another instance was still closing.
- Lag when scrolling lists with a fast mouse wheel.
