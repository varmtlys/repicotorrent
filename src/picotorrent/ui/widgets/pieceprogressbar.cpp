#include "pieceprogressbar.hpp"

#include <algorithm>
#include <cmath>

#include "../../core/configuration.hpp"

#include <wx/dcbuffer.h>
#include <wx/colour.h>

namespace lt = libtorrent;
using pt::UI::Widgets::PieceProgressBar;

PieceProgressBar::PieceProgressBar(wxWindow* parent, wxWindowID id, bool isDarkMode, lt::typed_bitfield<lt::piece_index_t> field)
    : wxPanel(parent, id, wxDefaultPosition, wxSize(-1, parent->FromDIP(15)), wxTAB_TRAVERSAL | wxNO_BORDER | wxBG_STYLE_PAINT),
    m_bitfield(field)
{
    Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(PieceProgressBar::OnEraseBackground));
    Connect(wxEVT_PAINT, wxPaintEventHandler(PieceProgressBar::OnPaint));
    Connect(wxEVT_SIZE, wxSizeEventHandler(PieceProgressBar::OnSize));
    m_bgColor = isDarkMode ? wxColour(32,32,32) : wxColour(255,255,255);
}

void PieceProgressBar::UpdateBitfield(lt::typed_bitfield<lt::piece_index_t> const& field)
{
    m_bitfield = field;
    Refresh();
}

void PieceProgressBar::OnEraseBackground(wxEraseEvent&)
{
}

void PieceProgressBar::OnSize(wxSizeEvent&)
{
    Refresh();
}

void PieceProgressBar::OnPaint(wxPaintEvent&)
{
    wxBufferedPaintDC dc(this);
    RenderProgress(dc);
}

void PieceProgressBar::RenderProgress(wxDC& dc)
{
    static wxColor bar("#35b1e1");
    static wxColor darkBorder(50, 50, 50);

    if (m_bitfield.size() > 0)
    {
        wxSize clientSize = this->GetClientSize();

        // Aggregate pieces per pixel column instead of building one bitmap
        // bitmap (and running one DrawLine per piece) sized to the piece
        // count - a 100k-piece torrent used to allocate a 6 MB bitmap and
        // issue 100k draws per second. innerWidth columns map the whole
        // piece range onto the widget.
        int innerWidth = clientSize.GetWidth() - 2;
        float piecesPerColumn = static_cast<float>(m_bitfield.size()) / std::max(innerWidth, 1);

        wxBitmap prg(clientSize);
        wxMemoryDC memDC;

        memDC.SelectObject(prg);
        memDC.SetBrush(m_bgColor);
        memDC.SetPen(darkBorder);
        memDC.DrawRectangle({ 0, 0 }, prg.GetSize());

        memDC.SetPen(bar);

        for (int col = 0; col < innerWidth; col++)
        {
            int firstIdx = static_cast<int>(std::floor(col * piecesPerColumn));
            int lastIdx = static_cast<int>(std::ceil((col + 1) * piecesPerColumn));

            lastIdx = std::min(lastIdx, static_cast<int>(m_bitfield.size()));
            firstIdx = std::min(firstIdx, lastIdx);

            // Pieces partially in this column gate the column: a column
            // only lights up when every piece it touches is here.
            bool complete = true;

            for (int idx = firstIdx; idx < lastIdx; idx++)
            {
                if (!m_bitfield[lt::piece_index_t(idx)])
                {
                    complete = false;
                    break;
                }
            }

            if (complete)
            {
                memDC.DrawLine(col + 1, 1, col + 1, prg.GetHeight() - 1);
            }
        }

        dc.StretchBlit(
            { 0, 0 },
            this->GetClientSize(),
            &memDC,
            { 0, 0 },
            prg.GetSize());
    }
    else
    {
        dc.SetBrush(m_bgColor);
        dc.SetPen(wxColor(190, 190, 190));
        dc.DrawRectangle(this->GetClientRect());
    }
}
