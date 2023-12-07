#pragma once

#include<ScrollBar.h>

class MacOsScrollBar : public ScrollBar
{
public:
    MacOsScrollBar(Orientation orientation, Position pos) : ScrollBar{orientation, pos}
    {

    }
    std::string className() override
    {
        return "[MacOsScrollBar]";
    }
};