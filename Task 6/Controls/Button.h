#pragma once

#include<Controls.h>

class Button : public Control
{
protected:
    std::string mButtonName;

public:
    Button(const std::string& buttonName = "", Position pos = {}) : mButtonName{buttonName},
                                                                    Control(pos)
    {}

    void press()
    {
        std::cout << "press " + this->mButtonName << "\n";
    }
};