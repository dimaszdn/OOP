#pragma once

#include<TextBox.h>

class WinTextBox : public TextBox
{
public:
    WinTextBox(const std::string& text, Position pos = {}) : TextBox(text, pos)
    {}

    std::string className() override
    {
        return "[WinTextBox]";
    };
};