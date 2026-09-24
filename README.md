# RePicoTorrent

[![Build](https://github.com/varmtlys/repicotorrent/actions/workflows/build.yml/badge.svg)](https://github.com/varmtlys/repicotorrent/actions/workflows/build.yml)

A tiny BitTorrent client for Windows written in modern C++, built on
Rasterbar-libtorrent. RePicoTorrent restarts
[PicoTorrent](https://github.com/picotorrent/picotorrent), which is no
longer developed, on libtorrent 2.1 with fixes and new features.

<p align="center">
    <img src="res/screenshot1.png?raw=true" width="614" />
</p>


## Quick facts

- Full support for BitTorrent 2.0 ([BEP-52](http://bittorrent.org/beps/bep_0052.html)), v1, v2 and v1+v2 hybrid torrents.
- Supports DHT, PeX, LSD, UPnP, WebTorrent.
- Imports torrents from qBittorrent with their progress and statistics.
- Portable: settings and torrents are kept next to the exe.
- Updates itself from the GitHub releases, verified by SHA-256.
- Identifies to trackers as PicoTorrent, so client whitelists keep
  working: peer ID `-PI-` (e.g. `-PI0260-` for 0.26.0), user agent
  `PicoTorrent/x.y.z`.


## Download

Get the latest zip for your Windows from
[Releases](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` for 64-bit Windows, `arm64` for Windows on ARM, `x86` for 32-bit.
New releases are offered in the app and install with one click.
See [CHANGELOG.md](CHANGELOG.md) for what changed and how to move from
PicoTorrent.


## Building

You need Visual Studio 2022 with the C++ workload (it includes CMake) and
Git. Dependencies come from the vcpkg submodule.

```
git clone --recursive https://github.com/varmtlys/repicotorrent
cd repicotorrent
cmake -S . -B build-x64 -G "Visual Studio 17 2022" -A x64 -DVCPKG_TARGET_TRIPLET=x64-windows-static-md-rel
cmake --build build-x64 --config Release --target PicoTorrent Plugin_Updater
```

For 32-bit use `-A Win32` and the `x86-windows-static-md-rel` triplet,
for ARM64 `-A ARM64` and `arm64-windows-static-md-rel` (built on an ARM64
machine, without Crashpad).
The first build compiles the dependencies and takes a while.


## Versions and releases

Versions follow [Semantic Versioning](https://semver.org) and come from
the latest `vX.Y.Z` tag. A build on the tag is that release; a build `N`
commits later is the next patch with a `-dev.N` suffix, for example
`0.26.1-dev.3`.

To release: add a `## X.Y.Z` section to [CHANGELOG.md](CHANGELOG.md),
commit, then tag and push:

```
git tag vX.Y.Z
git push origin vX.Y.Z
```

The Build workflow compiles every platform, runs the tests and publishes
a GitHub release with the zips, symbols, checksums and the changelog
section as notes.


## License

Copyright (c) Viktor Elofsson and contributors, RePicoTorrent contributors.
Provided as-is under the MIT license. For more information see
[LICENSE](LICENSE).
