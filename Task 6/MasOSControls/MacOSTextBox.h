#pragma once

#include<TextBox.h>

class MacOSTextBox : public TextBox
{
public:
    MacOSTextBox(const std::string& text, Position pos = {}) : TextBox(text, pos)
    {}

    std::string className() override
    {
        return "[MacOSTextBox]";
    };
};