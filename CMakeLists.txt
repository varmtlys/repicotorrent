cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
cmake_policy(SET CMP0092 NEW) # don't add /W3 as default
cmake_policy(SET CMP0115 OLD) # Source file extensions must be explicit.

# set(VCPKG_OVERLAY_PORTS    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/vcpkg-overlays/ports)
set(VCPKG_OVERLAY_TRIPLETS ${CMAKE_CURRENT_SOURCE_DIR}/vendor/vcpkg-overlays/triplets)
set(CMAKE_TOOLCHAIN_FILE   ${CMAKE_CURRENT_SOURCE_DIR}/vendor/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

project("RePicoTorrent")

set(CMAKE_CXX_STANDARD 17)

# --------- version
# Taken from the latest vX.Y.Z tag at configure time. A build on the tag is
# that release; a build N commits later is the next patch with a -dev.N
# suffix, so trackers and the updater never mistake it for a release.
find_package(Git QUIET)

execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --tags --long --match "v[0-9]*.[0-9]*.[0-9]*"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE PICO_GIT_DESCRIBE
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET)

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --short=7 HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GITVERSION_VAR_SHORTSHA
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET)

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GITVERSION_VAR_BRANCHNAME
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET)

if(PICO_GIT_DESCRIBE MATCHES "^v([0-9]+)\\.([0-9]+)\\.([0-9]+)-([0-9]+)-g[0-9a-f]+$")
    set(GITVERSION_VAR_VERSION_MAJOR ${CMAKE_MATCH_1})
    set(GITVERSION_VAR_VERSION_MINOR ${CMAKE_MATCH_2})
    set(GITVERSION_VAR_VERSION_PATCH ${CMAKE_MATCH_3})
    set(PICO_COMMITS_SINCE_TAG ${CMAKE_MATCH_4})
else()
    set(GITVERSION_VAR_VERSION_MAJOR 0)
    set(GITVERSION_VAR_VERSION_MINOR 0)
    set(GITVERSION_VAR_VERSION_PATCH 0)
    set(PICO_COMMITS_SINCE_TAG 1)
endif()

if(NOT PICO_COMMITS_SINCE_TAG EQUAL 0)
    math(EXPR GITVERSION_VAR_VERSION_PATCH "${GITVERSION_VAR_VERSION_PATCH} + 1")
endif()

set(GITVERSION_VAR_VERSION "${GITVERSION_VAR_VERSION_MAJOR}.${GITVERSION_VAR_VERSION_MINOR}.${GITVERSION_VAR_VERSION_PATCH}")
set(GITVERSION_VAR_SEMVER ${GITVERSION_VAR_VERSION})

if(NOT PICO_COMMITS_SINCE_TAG EQUAL 0)
    set(GITVERSION_VAR_SEMVER "${GITVERSION_VAR_VERSION}-dev.${PICO_COMMITS_SINCE_TAG}")
endif()

message(STATUS "RePicoTorrent version: ${GITVERSION_VAR_SEMVER} (${GITVERSION_VAR_SHORTSHA})")

# Reconfigure when a commit, checkout or tag changes the version, so a
# plain rebuild never carries a stale one.
execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --absolute-git-dir --symbolic-full-name HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE PICO_GIT_PATHS
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET)

if(PICO_GIT_PATHS)
    string(REPLACE "\n" ";" PICO_GIT_PATHS "${PICO_GIT_PATHS}")
    list(GET PICO_GIT_PATHS 0 PICO_GIT_DIR)
    list(LENGTH PICO_GIT_PATHS PICO_GIT_PATHS_LENGTH)

    set(PICO_GIT_WATCH HEAD packed-refs refs/tags)
    if(PICO_GIT_PATHS_LENGTH GREATER 1)
        list(GET PICO_GIT_PATHS 1 PICO_GIT_REF) # refs/heads/<branch>
        list(APPEND PICO_GIT_WATCH ${PICO_GIT_REF})
    endif()

    foreach(f ${PICO_GIT_WATCH})
        if(EXISTS "${PICO_GIT_DIR}/${f}")
            set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${PICO_GIT_DIR}/${f}")
        endif()
    endforeach()
endif()
# -----------------------

# --------- antlr4 options
option(WITH_STATIC_CRT "" Off)
# -----------------------

# --------- wx options
set(wxBUILD_SHARED        OFF   CACHE BOOL   "" FORCE)
set(wxBUILD_COMPATIBILITY "3.2" CACHE STRING "" FORCE)
set(wxUSE_EXCEPTIONS      OFF   CACHE BOOL   "" FORCE)
# --------------------

# vendor libs
# The vendored Crashpad predates ARM64 support; ARM64 builds go without
# crash dumps.
if(CMAKE_CXX_COMPILER_ARCHITECTURE_ID STREQUAL "ARM64")
    set(PICO_WITH_CRASHPAD OFF)
else()
    set(PICO_WITH_CRASHPAD ON)
    add_subdirectory(vendor/sentry-crashpad)
endif()
add_subdirectory(vendor/wx)

# pico components
add_subdirectory(src/pql)

# vcpkg packages
find_package(Boost                      REQUIRED COMPONENTS log)
find_package(fmt                 CONFIG REQUIRED)
find_package(LibtorrentRasterbar CONFIG REQUIRED)
find_package(nlohmann_json       CONFIG REQUIRED)
find_package(unofficial-sqlite3  CONFIG REQUIRED)
find_package(maxminddb           CONFIG REQUIRED)

# Generate buildinfo file
configure_file("${CMAKE_SOURCE_DIR}/src/picotorrent/buildinfo.cpp.in" "${CMAKE_SOURCE_DIR}/src/picotorrent/buildinfo.cpp" @ONLY)

# Debug flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi")

# Release flags
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/DEBUG /INCREMENTAL:NO /MAP /OPT:REF /OPT:ICF")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/DEBUG /INCREMENTAL:NO /MAP /OPT:REF /OPT:ICF")

add_executable(
    PicoTorrent-coredb
    src/l10n/main
    lang/ca-ES.json
    lang/de-DE.json
    lang/el-GR.json
    lang/en-US.json
    lang/es-ES.json
    lang/fi-FI.json
    lang/fr-FR.json
    lang/hu-HU.json
    lang/hy-AM.json
    lang/id-ID.json
    lang/it-IT.json
    lang/ka-GE.json
    lang/ko-KR.json
    lang/lt-LT.json
    lang/lv-LV.json
    lang/nl-NL.json
    lang/pl-PL.json
    lang/pt-BR.json
    lang/ro-RO.json
    lang/ru-RU.json
    lang/sv-SE.json
    lang/tr-TR.json
    lang/uk-UA.json
    lang/zh-CN.json
)

target_link_libraries(
    PicoTorrent-coredb
    PRIVATE
    nlohmann_json::nlohmann_json
    unofficial::sqlite3::sqlite3
)

add_executable(
    PicoTorrent
    WIN32

    src/picotorrent/application
    src/picotorrent/buildinfo
    src/picotorrent/crashpadinitializer
    src/picotorrent/main
    src/picotorrent/persistencemanager
    src/picotorrent/updateinstaller
    src/picotorrent/resources.rc

    # API
    src/picotorrent/api/libpico

    # BitTorrent
    src/picotorrent/bittorrent/session
    src/picotorrent/bittorrent/torrenthandle

    # Core
    src/picotorrent/core/configuration
    src/picotorrent/core/database
    src/picotorrent/core/environment
    src/picotorrent/core/utils

    # GeoIP
    src/picotorrent/core/geoip/geoip
    src/picotorrent/core/geoip/maxminddatabase

    # Http
    src/picotorrent/http/httpclient

    # IPC
    src/picotorrent/ipc/applicationoptionsconnection
    src/picotorrent/ipc/server

    # Dialogs
    src/picotorrent/ui/dialogs/aboutdialog
    src/picotorrent/ui/dialogs/addmagnetlinkdialog
    src/picotorrent/ui/dialogs/addtrackerdialog
    src/picotorrent/ui/dialogs/addtorrentdialog
    src/picotorrent/ui/dialogs/createtorrentdialog
    src/picotorrent/ui/dialogs/listeninterfacedialog
    src/picotorrent/ui/dialogs/preferencesadvancedpage
    src/picotorrent/ui/dialogs/preferencesconnectionpage
    src/picotorrent/ui/dialogs/preferencesdialog
    src/picotorrent/ui/dialogs/preferencesdownloadspage
    src/picotorrent/ui/dialogs/preferencesgeneralpage
    src/picotorrent/ui/dialogs/preferenceslabelspage
    src/picotorrent/ui/dialogs/preferencesproxypage
    src/picotorrent/ui/dialogs/textoutputdialog

    # Filters
    src/picotorrent/ui/filters/pqltorrentfilter

    # Models
    src/picotorrent/ui/models/filestoragemodel
    src/picotorrent/ui/models/peerlistmodel
    src/picotorrent/ui/models/torrentlistmodel
    src/picotorrent/ui/models/trackerlistmodel

    # Persistence
    src/picotorrent/ui/persistence/persistenttorrentlistview

    # UI
    src/picotorrent/ui/console
    src/picotorrent/ui/mainframe
    src/picotorrent/ui/statusbar
    src/picotorrent/ui/taskbaricon
    src/picotorrent/ui/torrentcontextmenu
    src/picotorrent/ui/torrentdetailsfilespanel
    src/picotorrent/ui/torrentdetailsoverviewpanel
    src/picotorrent/ui/torrentdetailspeerspanel
    src/picotorrent/ui/torrentdetailstrackerspanel
    src/picotorrent/ui/torrentdetailsview
    src/picotorrent/ui/torrentfilelistview
    src/picotorrent/ui/torrentlistview
    src/picotorrent/ui/translator

    # Widgets
    src/picotorrent/ui/widgets/pieceprogressbar

    # Win32 specific stuff
    src/picotorrent/ui/win32/openfiledialog
)

target_compile_definitions(
    PicoTorrent
    PRIVATE
    -D_UNICODE
    -D_WIN32
    -D_WIN32_WINNT=0x0600
    -DBOOST_USE_WINAPI_VERSION=0x0602
    -DNOMINMAX
    -DPICOJSON_USE_INT64
    -DUNICODE
    -DWIN32
    -DWIN32_LEAN_AND_MEAN

    -DLIBPICO_API_EXPORT

    -DPICO_GIT_COMMITISH=${GITVERSION_VAR_SHORTSHA}
    -DPICO_VERSION_MAJOR=${GITVERSION_VAR_VERSION_MAJOR}
    -DPICO_VERSION_MINOR=${GITVERSION_VAR_VERSION_MINOR}
    -DPICO_VERSION_PATCH=${GITVERSION_VAR_VERSION_PATCH}

    -DPICO_WX_GIT_COMMITISH=${PICO_WX_GIT_COMMITISH}
)

target_compile_options(PicoTorrent PRIVATE /guard:cf /W4 /WX)

target_include_directories(
    PicoTorrent
    PRIVATE

    include
)

target_link_libraries(
    PicoTorrent

    PRIVATE

    # boost
    Boost::boost
    Boost::log

    # wxWidgets
    wxcore wxbase wxpropgrid

    # Windows
    Comctl32
    crypt32
    iphlpapi
    legacy_stdio_definitions
    propsys
    shlwapi
    wininet
    winhttp

    # fmt
    fmt::fmt

    # nlohmann-json
    nlohmann_json::nlohmann_json

    # Rasterbar-libtorrent
    LibtorrentRasterbar::torrent-rasterbar

    # libmaxminddb (static, needs Winsock)
    maxminddb::maxminddb
    ws2_32

    # PQL
    PicoTorrentPQL

    unofficial::sqlite3::sqlite3
)

set_property(TARGET PicoTorrent PROPERTY ENABLE_EXPORTS 1)
set_property(TARGET PicoTorrent PROPERTY OUTPUT_NAME RePicoTorrent)

# Self-checks for the pure logic in src/picotorrent/bittorrent (no wx, no UI).
enable_testing()

add_executable(PicoTorrent-tests src/tests/main)

target_link_libraries(
    PicoTorrent-tests
    PRIVATE
    Boost::boost
    LibtorrentRasterbar::torrent-rasterbar
)

add_test(NAME PicoTorrent-tests COMMAND PicoTorrent-tests)

# Plugins
add_library(
    Plugin_Updater
    SHARED
    src/plugins/updater/updater
)

target_compile_definitions(Plugin_Updater PRIVATE -D_WIN32 -DUNICODE -DWIN32_LEAN_AND_MEAN)
target_include_directories(Plugin_Updater PRIVATE include)
target_link_libraries(Plugin_Updater PRIVATE PicoTorrent Comctl32)

if(PICO_WITH_CRASHPAD)
    target_link_libraries(PicoTorrent PRIVATE crashpad_client crashpad_util mini_chromium)

    # Copy Crashpad handler
    add_custom_command(
        TARGET PicoTorrent POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:crashpad_handler>
            $<TARGET_FILE_DIR:PicoTorrent>
    )
else()
    target_compile_definitions(PicoTorrent PRIVATE -DPICO_NO_CRASHPAD)
endif()

# Generate coredb
add_custom_command(
    TARGET PicoTorrent POST_BUILD
    COMMAND PicoTorrent-coredb "${CMAKE_SOURCE_DIR}/lang" $<TARGET_FILE_DIR:PicoTorrent>
)
