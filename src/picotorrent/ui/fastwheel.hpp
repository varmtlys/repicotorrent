#pragma once

#include <memory>

#include <wx/dataview.h>

namespace pt::UI
{
    // wxDataViewCtrl turns every wheel notch into one line scroll per line,
    // each followed by a synchronous repaint. A fast spinning wheel (Logitech
    // hyper scroll) queues hundreds of those. Sum the notches instead and
    // scroll once, after the queued wheel messages have been read.
    inline void EnableFastWheel(wxDataViewCtrl* ctrl)
    {
        auto pending = std::make_shared<int>(0);
        auto rotation = std::make_shared<int>(0);

        ctrl->GetMainWindow()->Bind(
            wxEVT_MOUSEWHEEL,
            [ctrl, pending, rotation](wxMouseEvent& evt)
            {
                if (evt.GetWheelAxis() != wxMOUSE_WHEEL_VERTICAL
                    || evt.IsPageScroll()
                    || evt.HasAnyModifiers())
                {
                    evt.Skip();
                    return;
                }

                *rotation += evt.GetWheelRotation();
                int const notches = *rotation / evt.GetWheelDelta();
                *rotation -= notches * evt.GetWheelDelta();

                if (notches == 0) { return; }

                bool const scheduled = *pending != 0;
                *pending += notches * evt.GetLinesPerAction();

                if (scheduled) { return; }

                ctrl->CallAfter(
                    [ctrl, pending]()
                    {
                        int x, y;
                        ctrl->GetViewStart(&x, &y);
                        // Scroll units are rows; Scroll() clamps to the range.
                        ctrl->Scroll(x, y - *pending);
                        *pending = 0;
                    });
            });
    }
}
