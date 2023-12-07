#pragma once

#include<Factory.h>
#include<LinuxForm.h>
#include<LinuxButton.h>
#include<LinuxTextBox.h>
#include<LinuxScrollBar.h>

class LinuxFactory : public Factory
{
public:
    Form* createForm(Position pos) override
    {
        return new LinuxForm(pos);
    }
    TextBox* createTextBox(const std::string& text, Position pos) override
    {
        return new LinuxTextBox(text, pos);
    }
    Button* createButton(const std::string& buttonName, Position pos) override
    {
        return new LinuxButton(buttonName, pos);
    }
    ScrollBar* createScrollBar(Orientation orientation, Position pos) override
    {
        return new LinuxScrollBar(orientation, pos);
    }
};