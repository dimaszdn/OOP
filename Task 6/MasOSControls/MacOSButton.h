#pragma once

#include<Button.h>

class MacOSButton : public Button
{
public:
    MacOSButton(const std::string& buttonName, Position pos = {}) : Button(buttonName, pos)
    {}

    std::string className() override
    {
        return "[MacOSButton]";
    };
};