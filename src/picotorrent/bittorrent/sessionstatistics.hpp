#pragma once

#include <cstdint>

namespace pt
{
namespace BitTorrent
{
    struct SessionStatistics
    {
        int dhtNodes = 0;
        // Payload bytes since the session started.
        int64_t totalDownloaded = 0;
        int64_t totalUploaded = 0;
    };
}
}
