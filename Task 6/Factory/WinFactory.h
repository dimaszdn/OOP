#pragma once

#include<Factory.h>
#include<WinForm.h>
#include<WinTextBox.h>
#include<WinButton.h>
#include<WinScrollBar.h>

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
    ScrollBar* createScrollBar(Orientation orientation, Position pos) override
    {
        return new WinScrollBar(orientation, pos);
    }
};