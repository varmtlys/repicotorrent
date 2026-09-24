#pragma once

#include <cstdio>
#include <string>

namespace pt::Updater
{
    // True when release (X.Y.Z) is newer than current (X.Y.Z, or
    // X.Y.Z-dev.N for a build that is not a release).
    inline bool isNewer(std::string const& release, std::string const& current)
    {
        int r[3] = { 0, 0, 0 };
        int c[3] = { 0, 0, 0 };

        std::sscanf(release.c_str(), "%d.%d.%d", &r[0], &r[1], &r[2]);
        std::sscanf(current.c_str(), "%d.%d.%d", &c[0], &c[1], &c[2]);

        for (int i = 0; i < 3; i++)
        {
            if (r[i] != c[i]) { return r[i] > c[i]; }
        }

        // Same numbers: the release beats a pre-release build of it.
        return release.find('-') == std::string::npos
            && current.find('-') != std::string::npos;
    }
}
