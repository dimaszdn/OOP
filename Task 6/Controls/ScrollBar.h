#pragma once

#include<Controls.h>

enum class Orientation
{
    Horizontal,
    Vertical
};

class ScrollBar : public Control
{
protected:
    Orientation mOrientation;

public:
    ScrollBar(Orientation orientation, Position pos) : mOrientation{orientation},
                                                       Control{pos}
    {}

    void setOrientation(Orientation orientation)
    {
        mOrientation = orientation;
    }

    Orientation getOrientation()
    {
        return mOrientation;
    }

    void move()
    {
        std::cout << "Ползунок сдвинут" << "\n";
    }
};