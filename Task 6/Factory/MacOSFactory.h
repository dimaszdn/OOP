#pragma once

#include<Factory.h>
#include<MacOSTextBox.h>
#include<MacOSButton.h>
#include<MacOSForm.h>
#include<MacOsScrollBar.h>

class MacOSFactory : public Factory
{
public:
    Form* createForm(Position pos) override
    {
        return new MacOSForm(pos);
    }
    TextBox* createTextBox(const std::string& text, Position pos) override
    {
        return new MacOSTextBox(text, pos);
    }
    Button* createButton(const std::string& buttonName, Position pos) override
    {
        return new MacOSButton(buttonName, pos);
    }
    ScrollBar* createScrollBar(Orientation orientation, Position pos) override
    {
        return new MacOsScrollBar(orientation, pos);
    }
};