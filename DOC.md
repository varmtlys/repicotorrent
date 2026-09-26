# RePicoTorrent documentation

**English** · [العربية](doc/DOC.ar-SA.md) · [Български](doc/DOC.bg-BG.md) · [Català](doc/DOC.ca-ES.md) · [Čeština](doc/DOC.cs-CZ.md) · [Deutsch](doc/DOC.de-DE.md) · [Ελληνικά](doc/DOC.el-GR.md) · [Español](doc/DOC.es-ES.md) · [Eesti](doc/DOC.et-EE.md) · [Suomi](doc/DOC.fi-FI.md) · [Français](doc/DOC.fr-FR.md) · [עברית](doc/DOC.he-IL.md) · [हिन्दी](doc/DOC.hi-IN.md) · [Hrvatski](doc/DOC.hr-HR.md) · [Magyar](doc/DOC.hu-HU.md) · [Հայերեն](doc/DOC.hy-AM.md) · [Bahasa Indonesia](doc/DOC.id-ID.md) · [Italiano](doc/DOC.it-IT.md) · [日本語](doc/DOC.ja-JP.md) · [ქართული](doc/DOC.ka-GE.md) · [한국어](doc/DOC.ko-KR.md) · [Lietuvių](doc/DOC.lt-LT.md) · [Latviešu](doc/DOC.lv-LV.md) · [Norsk bokmål](doc/DOC.nb-NO.md) · [Nederlands](doc/DOC.nl-NL.md) · [Polski](doc/DOC.pl-PL.md) · [Português (Brasil)](doc/DOC.pt-BR.md) · [Português (Portugal)](doc/DOC.pt-PT.md) · [Română](doc/DOC.ro-RO.md) · [Русский](doc/DOC.ru-RU.md) · [සිංහල](doc/DOC.si-LK.md) · [Slovenčina](doc/DOC.sk-SK.md) · [Srpski](doc/DOC.sr-SP.md) · [Svenska](doc/DOC.sv-SE.md) · [Türkçe](doc/DOC.tr-TR.md) · [Українська](doc/DOC.uk-UA.md) · [Tiếng Việt](doc/DOC.vi-VN.md) · [简体中文](doc/DOC.zh-CN.md) · [繁體中文](doc/DOC.zh-TW.md)

- [Getting started](#getting-started)
- [Main window](#main-window)
- [Adding torrents](#adding-torrents)
- [Managing torrents](#managing-torrents)
- [Labels](#labels)
- [Filters and the console](#filters-and-the-console)
- [Creating torrents](#creating-torrents)
- [Preferences](#preferences)
- [Moving from PicoTorrent or qBittorrent](#moving-from-picotorrent-or-qbittorrent)
- [Updates](#updates)
- [Keyboard shortcuts](#keyboard-shortcuts)
- [Files and command line](#files-and-command-line)


## Getting started

Download the zip for your Windows from the
[releases page](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` for 64-bit Windows, `arm64` for Windows on ARM, `x86` for 32-bit
Windows. Unpack it into any folder you can write to and run
`RePicoTorrent.exe`. Nothing is installed: settings, the torrent list and
logs are kept next to the exe, so the folder can be moved or copied
to a USB drive.

Each folder is a separate copy of the program. Two copies in different
folders can run at the same time if they use different ports.


## Main window

![Main window](doc/images/en-US/main.png)

The upper part is the torrent list. Every column can be sorted by clicking
its header; right-click the header to show or hide columns.

- **Progress** and **Done**: how much of the wanted data is downloaded.
- **ETA**, **DL**, **UL**: time left, download and upload rates.
- **Availability**: how many full copies the connected peers have together.
- **Seeds**, **Peers**, **Leechers**: connected, and in brackets the number
  in the whole swarm as reported by the trackers.

The lower part shows the details of the selected torrent:

- **Overview**: name, info hashes (v1 and v2), size, save path,
  comment and totals. Links in the comment open in the browser. The bar on
  top shows the pieces: every downloaded piece is painted where it lies in
  the torrent. Pieces are fetched out of order (rarest first), so a
  torrent in progress has gaps.
- **Files**: the files and folders with their progress. Right-click to
  set a priority or skip a file; double-click opens a downloaded file.
- **Peers**: connected peers with their country, client, rates and
  connection flags written out in words.
- **Trackers**: tracker status, seeds and leeches it reports and the
  next announce. Right-click to add, remove or re-announce.

The status bar shows the number of torrents, DHT nodes, the current rates,
whether the IP filter is on and the amount transferred in this session.
**View** hides or shows the details panel, the status bar and the
console.


## Adding torrents

- **File > Add torrent** (Ctrl+O): pick one or more
  `.torrent` files.
- **File > Add magnet link(s)** (Ctrl+U): paste magnet links,
  one per line.
- Open a `.torrent` file or a magnet link with `RePicoTorrent.exe`; if the
  program is already running in that folder, the torrent is passed to it.

Before a torrent is added you can choose the save path, the files to
download and a label. To add torrents at once with the default settings,
turn on **Skip 'Add torrent' dialog** in the preferences.


## Managing torrents

Right-click one or more torrents:

- **Resume**, **Resume (force)** (ignores the queue), **Pause**.
- **Force reannounce**, **Force recheck** (verifies the data on disk).
- **Sequential download**: fetch pieces in order, useful for watching a
  video while it downloads.
- **Label**: assign a label.
- **Export**: the magnet link or the `.torrent` file.
- **Move**: move the data to another folder.
- **Remove**: remove the torrent (Del), or the torrent and its files
  (Shift+Del).
- **Queuing**: move up or down in the download queue.
- **Copy info hash**, **Open in Explorer**.


## Labels

Labels group torrents. They are created in **Preferences > Labels**:

- **Color**: the label color; with **Use label color as background in torrent list** (**General**) the rows are painted in it.
- **Save path**: torrents added with this label are saved here.
- **Apply filter**: a regular expression; a new torrent whose name
  matches it gets this label automatically. Example: `ubuntu|debian|fedora`.

**View > Labels** shows only the torrents with one label.


## Filters and the console

**View > Filter** has saved filters, for example the torrents
that are downloading right now. **View > Console** opens a
line under the list: type a query and press Enter to show only the matching
torrents; clear it to show all again.

| Field | Type | Meaning |
|---|---|---|
| `name` | text | torrent name |
| `label` | text | label name |
| `status` | text | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | number | percent done |
| `size` | size | wanted size: `b` (default), `kb`, `mb`, `gb` |
| `dl`, `ul` | speed | rates: bytes per second (default), `kbps`, `mbps`, `gbps` |

Operators: `=`, `<`, `<=`, `>`, `>=` and `~` (contains, case-insensitive),
joined with `and` and `or`. Text goes in double quotes, units are written in
lower case.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Creating torrents

**File > Create torrent**:

![Create torrent](doc/images/en-US/create-torrent.png)

- Pick a file or a folder.
- **Mode**: v1, v2 or v1 + v2 hybrid. Hybrid works with every client and
  is the default.
- **Comment** and **Creator** are optional.
- **Private**: peers come only from the trackers, not from DHT, PeX or
  local discovery.
- **Add to session**: start seeding the new torrent right away.
- **Trackers (one per line)**: each tracker goes to its own tier, which
  are tried in order.
- **URL seeds (one per line)**: web servers with the same data. For a
  folder, the URL must point to the folder that contains it.


## Preferences

**View > Preferences**. **Restore defaults** resets
every setting. Some changes (language, theme, ports) need a restart; the
program offers it.

### General

![General](doc/images/en-US/preferences-general.png)

- **Language** and **Theme** (system or light; the dark theme
  follows the Windows setting).
- **Skip 'Add torrent' dialog**, **Start RePicoTorrent with Windows**,
  **Start position** of the window.
- **Show RePicoTorrent in notification area**, and whether minimizing or
  closing the window hides it there.

### Downloads

![Downloads](doc/images/en-US/preferences-downloads.png)

- **Save path**, **Move completed downloads** to another folder.
- **Pause when disk space is low**.
- **Limits**: download and upload rate limits in KB/s, how many
  torrents may be active at once and the total number of connections.

### Labels

![Labels](doc/images/en-US/preferences-labels.png)

See [Labels](#labels).

### Connection

![Connection](doc/images/en-US/preferences-connection.png)

- **Listen interface**: addresses and ports for incoming connections.
  `0.0.0.0` and `[::]` mean all IPv4 and IPv6 addresses.
- **Encryption**: require encrypted incoming or outgoing connections.
- **Privacy**: DHT, local peer discovery (LSD), peer exchange (PeX),
  WebTorrent and the peer country column. The country database (DB-IP
  Lite) is downloaded once a month while the country column is on.
- **IP filter**: block addresses from an eMule-format filter in a zip
  file, for example from emule-security.org.

### Proxy

![Proxy](doc/images/en-US/preferences-proxy.png)

HTTP or SOCKS4/5 proxy, with or without a password, and what goes through
it: host name lookups, peer and tracker connections.

### Advanced

![Advanced](doc/images/en-US/preferences-advanced.png)

Every libtorrent setting. Select one to read its description below the
list. Change these only if you know what they do; **Restore defaults**
brings them back.


## Moving from PicoTorrent or qBittorrent

- **File > Import from PicoTorrent**: pick `PicoTorrent.sqlite`
  (next to a portable PicoTorrent, or in `%LOCALAPPDATA%\PicoTorrent`).
  Torrents and their labels are added; the file is only read. To take over
  everything, settings included, copy `PicoTorrent.sqlite` next to
  `RePicoTorrent.exe` before the first start: it is renamed to
  `RePicoTorrent.sqlite`.
- **File > Import from qBittorrent**: pick qBittorrent's
  `BT_backup` folder (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Progress,
  trackers, counters, save paths and comments are kept.

Torrents already in the list are skipped. Do not seed the same torrents
from both clients at once.


## Updates

On every start the program asks GitHub for the latest release, and
**Help > Check for update** asks at any time. When there is a
newer version, **Download and install** downloads the zip for your Windows,
checks it against the release's SHA-256 checksums, replaces the program
files and restarts. Settings and torrents stay.


## Keyboard shortcuts

| Keys | Action |
|---|---|
| Ctrl+O | add torrent |
| Ctrl+U | add magnet links |
| Ctrl+A | select all torrents |
| Del | remove the selected torrents, keep the data |
| Shift+Del | remove the selected torrents and their data |
| F1 | open this documentation |


## Files and command line

Next to `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: settings, torrents and their resume data;
- `coredb.sqlite`: translations (part of the program);
- `logs`: log files;
- `Crashpad`: crash dumps, never uploaded;
- `dbip-country-lite.mmdb`: the country database.

Command line:

```
RePicoTorrent.exe [--silent] [--save-path=<folder>] [file.torrent | magnet:?xt=...]...
```

`--silent` adds the given torrents without the add dialog, `--save-path`
sets where they are saved.
