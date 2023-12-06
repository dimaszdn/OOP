#pragma once

#include<Button.h>

class LinuxButton : public Button
{
public:
    LinuxButton(const std::string& buttonName, Position pos = {}) : Button(buttonName, pos)
    {}

    std::string className() override
    {
        return "[LinuxButton]";
    };
};