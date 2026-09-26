#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <Windows.h>
#include <winhttp.h>

#include <cstdint>
#include <functional>
#include <memory>

namespace pt
{
namespace Http
{
    struct HttpResponse
    {
        std::string body;
        int statusCode;
    };

    class HttpClient : public wxEvtHandler
    {
    public:
        HttpClient();
        virtual ~HttpClient();

        // Called on the UI thread as the body arrives; total is 0 when the
        // server sends no Content-Length.
        using ProgressCallback = std::function<void(int64_t received, int64_t total)>;

        void Get(
            wxString const& url,
            std::function<void(int, std::string const&)> const& callback,
            ProgressCallback const& progress = nullptr);
    private:
        static std::wstring ReadHeader(HINTERNET hRequest, DWORD dwHeader);
        static void CALLBACK StatusCallbackProxy(HINTERNET hInternet, DWORD_PTR dwContext, DWORD dwInternetStatus, LPVOID lpStatusInformation, DWORD dwStatusInformationLength);

        HINTERNET m_session;
    };
}
}
