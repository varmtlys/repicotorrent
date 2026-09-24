#include "utils.hpp"

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <sstream>
#include <vector>

#include <fmt/format.h>
#include <fmt/xchar.h>
#include <Windows.h>
#include <ShlObj.h>
#include <shlwapi.h>

#include "../ui/translator.hpp"

namespace fs = std::filesystem;

using pt::Utils;

void Utils::openAndSelect(fs::path path)
{
    std::wstringstream ss;
    ss << L"explorer.exe /select,\"" << path.native() << L"\"";
    wxExecute(ss.str());
}

std::wstring Utils::toHumanFileSize(int64_t bytes)
{
    // Units and the decimal point come from the translation, not from the
    // Windows locale, so sizes follow the language picked in the program.
    std::vector<std::wstring> units;
    std::wstringstream list(i18n("size_units"));

    for (std::wstring unit; std::getline(list, unit, L',');) { units.push_back(unit); }

    double value = static_cast<double>(bytes);
    size_t unit = 0;

    while (value >= 1024 && unit + 1 < units.size())
    {
        value /= 1024;
        unit++;
    }

    if (unit == 0)
    {
        return fmt::format(L"{} {}", bytes, units.empty() ? L"B" : units[0]);
    }

    // Three significant digits, like Explorer: 1.49 GB, 81.0 MB, 756 MB.
    int decimals = value < 10 ? 2 : value < 100 ? 1 : 0;
    std::wstring number = fmt::format(L"{:.{}f}", value, decimals);

    if (auto dot = number.find(L'.'); dot != std::wstring::npos)
    {
        number.replace(dot, 1, i18n("decimal_point"));
    }

    return number + L" " + units[unit];
}

std::string Utils::toStdString(std::wstring const& input)
{
    int size = WideCharToMultiByte(CP_UTF8, 0, input.data(), static_cast<int>(input.size()), NULL, 0, NULL, NULL);
    std::string result(size, 0);
    WideCharToMultiByte(CP_UTF8, 0, &input[0], (int)input.size(), &result[0], size, NULL, NULL);
    return result;
}

std::wstring Utils::toStdWString(std::string const& input)
{
    // An explicit length, not -1: with -1 the terminating NUL was converted
    // too and ended up inside the string, showing as a stray space wherever
    // a translation was formatted into a longer text.
    int size = MultiByteToWideChar(CP_UTF8, 0, input.data(), static_cast<int>(input.size()), NULL, 0);
    std::wstring result(size, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, input.data(), static_cast<int>(input.size()), result.data(), size);
    return result;
}
