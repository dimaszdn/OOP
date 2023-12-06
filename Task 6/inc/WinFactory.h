#pragma once

#include<Factory.h>

class WinFactory : public Factory
{
public:
    Form* createForm(Position pos) override
    {
        return new WinForm(pos);
    }
    TextBox* createTextBox(const std::string& text, Position pos) override
    {
        return new WinTextBox(text, pos);
    }
    Button* createButton(const std::string& buttonName, Position pos) override
    {
        return new WinButton(buttonName, pos);
    }
};