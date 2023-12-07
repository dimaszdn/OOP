#pragma once

#include<ScrollBar.h>

class WinScrollBar : public ScrollBar
{
public:
    WinScrollBar(Orientation orientation, Position pos) : ScrollBar{orientation, pos}
    {

    }

    std::string className() override
    {
        return "[WinScrollBar]";
    }
};