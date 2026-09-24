#pragma once

#include <cctype>
#include <sstream>
#include <string>

class wxFrame;

namespace pt
{
    class UpdateInstaller
    {
    public:
        // Downloads the release zip, checks it against the SHA256SUMS.txt
        // line for its file name, puts its files next to the running exe
        // and restarts. The files being replaced are kept as *.old until
        // the next start.
        static void Install(wxFrame* frame, std::string const& zipUrl, std::string const& sumsUrl);

        // Removes the *.old files a previous update left behind.
        static void CleanUp();

        // The SHA-256 (lowercase hex) listed for fileName in a sha256sum
        // style file ("<hash>  <name>" per line), or empty when missing.
        static std::string FindChecksum(std::string const& sums, std::string const& fileName)
        {
            std::istringstream lines(sums);
            std::string hash;
            std::string name;

            while (lines >> hash >> name)
            {
                if (!name.empty() && name[0] == '*') { name.erase(0, 1); } // binary mode marker

                if (name == fileName && hash.size() == 64)
                {
                    for (auto& c : hash) { c = static_cast<char>(tolower(static_cast<unsigned char>(c))); }
                    return hash;
                }
            }

            return {};
        }
    };
}
