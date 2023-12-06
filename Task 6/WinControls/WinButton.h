#pragma once

#include<Button.h>

class WinButton : public Button
{
public:
    WinButton(const std::string& buttonName, Position pos = {}) : Button(buttonName, pos)
    {}

    std::string className() override
    {
        return "[WinButton]";
    };
};