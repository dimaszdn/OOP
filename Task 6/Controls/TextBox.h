#pragma once

#include<Controls.h>

class TextBox : public Control
{
protected:
    std::string mText;

public:
    TextBox(const std::string& text = "", Position pos = {}) : mText{text},
                                                               Control{pos}
    {}

    void print()
    {
        std::cout << mText << "\n";
    }
};