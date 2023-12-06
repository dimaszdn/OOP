#pragma once
#include<iostream>
#include<string>

struct Position
{
    float mX;
    float mY;

    void print()
    {
        std::cout << "x: " << mX << " y: " << mY << "\n";
    }
};

class Control
{
protected:
    Position mPos{};

public:
    Control(Position pos) : mPos{pos}
    {}

    void setPosition(Position pos)
    {
        mPos = pos;
    }

    Position getPosition()
    {
        return mPos;
    }

    virtual std::string className()
    {
        return {};
    }
};
