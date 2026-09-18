#pragma once

#include <regex>
#include <string>

#include <libtorrent/address.hpp>

namespace pt::BitTorrent
{
    // eMule ipfilter.dat files zero-pad their octets ("001.002.123.020"), which
    // the boost parser rejects, so the four octets are parsed by hand. Rejects
    // anything that is not exactly four octets of 0-255, and never throws - the
    // input is an untrusted third party file.
    inline bool parseIPv4Address(std::string const& input, libtorrent::address& output)
    {
        boost::asio::ip::address_v4::bytes_type bytes = { 0, 0, 0, 0 };

        std::size_t off = 0;

        for (std::size_t i = 0; i < bytes.size(); i++)
        {
            std::size_t const pos = input.find_first_of('.', off);
            bool const isLast = (i + 1 == bytes.size());

            if (isLast != (pos == std::string::npos)) { return false; }

            std::size_t const len = (isLast ? input.size() : pos) - off;

            if (len < 1 || len > 3) { return false; }

            int octet = 0;

            for (std::size_t c = off; c < off + len; c++)
            {
                if (input[c] < '0' || input[c] > '9') { return false; }
                octet = octet * 10 + (input[c] - '0');
            }

            if (octet > 255) { return false; }

            bytes[i] = static_cast<unsigned char>(octet);
            off = pos + 1;
        }

        output = libtorrent::address_v4(bytes);

        return true;
    }

    // Parses a single line of an eMule ipfilter.dat file, ie.
    //
    //   001.002.003.000 - 001.002.003.255 , 000 , Some organisation
    //
    // Returns false for blank lines, comments and malformed ranges.
    inline bool parseIPFilterLine(
        std::string const& line,
        libtorrent::address& start,
        libtorrent::address& end,
        int& access)
    {
        static std::regex const filter(
            R"(\s*([\d\.]+)\s*-\s*([\d\.]+)\s*,\s*(\d+).*)",
            std::regex_constants::ECMAScript | std::regex_constants::icase);

        std::smatch m;

        if (!std::regex_match(line, m, filter)) { return false; }

        // Keep the access level parse away from any chance of overflowing
        if (m[3].length() > 9) { return false; }

        if (!parseIPv4Address(m[1], start)) { return false; }
        if (!parseIPv4Address(m[2], end)) { return false; }

        access = std::stoi(m[3]);

        return true;
    }
}
