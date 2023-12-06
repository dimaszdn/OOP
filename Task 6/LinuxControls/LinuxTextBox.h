#pragma once

#include<TextBox.h>

class LinuxTextBox : public TextBox
{
public:
    LinuxTextBox(const std::string& text, Position pos = {}) : TextBox(text, pos)
    {}

    std::string className() override
    {
        return "[LinuxTextBox]";
    };
};