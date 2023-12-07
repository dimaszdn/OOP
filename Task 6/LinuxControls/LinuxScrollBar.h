#pragma once

#include<ScrollBar.h>

class LinuxScrollBar : public ScrollBar
{
public:
    LinuxScrollBar(Orientation orientation, Position pos) : ScrollBar{orientation, pos}
    {

    }
    std::string className() override
    {
        return "[LinuxScrollBar]";
    }
};