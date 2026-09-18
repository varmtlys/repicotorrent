// Self-checks for the two pieces of pure logic behind the info hash and IP
// filter fixes. No framework: build PicoTorrent-tests and run it, or `ctest`.
//
// assert() is deliberately not used - the shipped configuration is Release,
// where NDEBUG would turn every check into a no-op.

#include <cstdio>
#include <map>
#include <string>

#include "../picotorrent/bittorrent/infohash.hpp"
#include "../picotorrent/bittorrent/ipfilterparser.hpp"

namespace lt = libtorrent;

using pt::BitTorrent::findInfoHash;
using pt::BitTorrent::infoHashKey;
using pt::BitTorrent::parseIPFilterLine;
using pt::BitTorrent::parseIPv4Address;

static int failures = 0;

#define CHECK(expr)                                                     \
    do {                                                                \
        if (!(expr))                                                    \
        {                                                               \
            std::printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #expr); \
            failures++;                                                 \
        }                                                               \
    } while (false)

// digest32(char const*) copies exactly size() bytes, so these literals are
// 20 and 32 characters long.
static lt::sha1_hash   const v1("aaaaaaaaaaaaaaaaaaaa");
static lt::sha256_hash const v2("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
static lt::sha1_hash   const unrelated("cccccccccccccccccccc");

static void testFindInfoHash()
{
    std::map<lt::info_hash_t, int> torrents;

    // A torrent added from a v1-only magnet link is keyed on {v1} ...
    torrents.insert({ lt::info_hash_t(v1), 1 });

    // ... but reports {v1, v2} once its metadata arrives.
    lt::info_hash_t const hybrid(v1, v2);

    // This is the lookup that used to throw std::out_of_range and kill the
    // process a second after a hybrid torrent got its metadata.
    CHECK(torrents.find(hybrid) == torrents.end());

    auto found = findInfoHash(torrents, hybrid);
    CHECK(found != torrents.end());
    CHECK(found != torrents.end() && found->second == 1);

    // A v2-only torrent is keyed on its v2 hash and found by it.
    torrents.insert({ lt::info_hash_t(v2), 2 });

    found = findInfoHash(torrents, lt::info_hash_t(v2));
    CHECK(found != torrents.end() && found->second == 2);

    // Exact matches keep working, unknown torrents are still not found.
    std::map<lt::info_hash_t, int> exact;
    exact.insert({ hybrid, 3 });

    auto exactFound = findInfoHash(exact, hybrid);
    CHECK(exactFound != exact.end() && exactFound->second == 3);
    CHECK(findInfoHash(exact, lt::info_hash_t(unrelated)) == exact.end());
}

static void testInfoHashKey()
{
    // The key is the v1 hash whenever there is one, because that is the only
    // hash a torrent cannot gain or lose while it is in the session.
    CHECK(infoHashKey(lt::info_hash_t(v1, v2)) == infoHashKey(lt::info_hash_t(v1)));
    CHECK(infoHashKey(lt::info_hash_t(v1)).size() == 40);
    CHECK(infoHashKey(lt::info_hash_t(v2)).size() == 64);
}

static bool parses(std::string const& input, std::string const& expected)
{
    lt::address out;

    return parseIPv4Address(input, out)
        && out.to_string() == expected;
}

static bool rejects(std::string const& input)
{
    lt::address out;
    return !parseIPv4Address(input, out);
}

static void testParseIPv4Address()
{
    CHECK(parses("1.2.3.4", "1.2.3.4"));
    CHECK(parses("0.0.0.0", "0.0.0.0"));
    CHECK(parses("255.255.255.255", "255.255.255.255"));

    // Zero padded octets are why this parser exists at all - eMule
    // ipfilter.dat files are written this way.
    CHECK(parses("001.002.123.020", "1.2.123.20"));

    // Each of these used to either leave octets uninitialized or throw out of
    // std::stoi, on a file downloaded from a third party.
    CHECK(rejects(""));
    CHECK(rejects("1.2.3"));
    CHECK(rejects("1.2.3.4.5"));
    CHECK(rejects("1.2.3."));
    CHECK(rejects("1..3.4"));
    CHECK(rejects("256.1.1.1"));
    CHECK(rejects("1.2.3.4444"));
    CHECK(rejects("1.2.3.a"));
    CHECK(rejects("999999999999"));
}

static void testParseIPFilterLine()
{
    lt::address start;
    lt::address end;
    int access = -1;

    CHECK(parseIPFilterLine("001.002.003.000 - 001.002.003.255 , 000 , Some organisation", start, end, access));
    CHECK(start.to_string() == "1.2.3.0");
    CHECK(end.to_string() == "1.2.3.255");
    CHECK(access == 0);

    CHECK(parseIPFilterLine("1.2.3.4-1.2.3.5,200,x", start, end, access));
    CHECK(access == 200);

    // Blank lines, comments and junk are skipped rather than crashing. The
    // empty line in particular used to index line[line.size() - 1].
    CHECK(!parseIPFilterLine("", start, end, access));
    CHECK(!parseIPFilterLine("# a comment", start, end, access));
    CHECK(!parseIPFilterLine("1.2.3.4-1.2.3.5", start, end, access));
    CHECK(!parseIPFilterLine("1.2.3.4-1.2.3.5,notanumber,x", start, end, access));

    // An access level too large for int must not throw out of std::stoi.
    CHECK(!parseIPFilterLine("1.2.3.4-1.2.3.5,99999999999999999999,x", start, end, access));
}

int main()
{
    testFindInfoHash();
    testInfoHashKey();
    testParseIPv4Address();
    testParseIPFilterLine();

    if (failures == 0)
    {
        std::printf("all checks passed\n");
        return 0;
    }

    std::printf("%d check(s) failed\n", failures);
    return 1;
}
