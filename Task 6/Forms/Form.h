#pragma once
#include<Controls.h>
#include<vector>

class Form
{
private:
    Position mPos{};

public:
    std::vector<Control*> controls;

    Form(Position pos) : mPos{pos}
    {}

    ~Form()
    {
        if (!controls.empty())
        {
            for (auto control : controls)
                delete control;
        }
    }

    void addControl(Control* control)
    {
        controls.push_back(control);
    }
};