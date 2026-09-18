#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <libtorrent/fwd.hpp>
#include <wx/dataview.h>

#include <vector>

namespace pt
{
namespace Core
{
    class GeoIP;
}
namespace UI
{
namespace Models
{
    class PeerListModel : public wxDataViewVirtualListModel
    {
    public:
        enum Column
        {
            IP,
            Country,
            Type,
            Client,
            Flags,
            DownloadRate,
            UploadRate,
            Downloaded,
            Uploaded,
            Progress,
            _Max
        };

        // geoip may be null, in which case the country column stays empty.
        PeerListModel(Core::GeoIP const* geoip);
        virtual ~PeerListModel();

        void ResetPeers();
        void Update(std::vector<libtorrent::peer_info> const&);

    private:
        unsigned int GetColumnCount() const wxOVERRIDE;
        wxString GetColumnType(unsigned int col) const wxOVERRIDE;
        void GetValueByRow(wxVariant &variant, unsigned row, unsigned col) const wxOVERRIDE;
        bool SetValueByRow(const wxVariant &variant, unsigned row, unsigned col) wxOVERRIDE;

        Core::GeoIP const* m_geoip;
        std::vector<libtorrent::peer_info> m_data;
    };
}
}
}
