#pragma once
#include<WinButton.h>
#include<WinTextBox.h>
#include<WinForm.h>

class Factory
{
public:
    virtual ~Factory()
    {}

    virtual Form* createForm(Position pos) = 0;

    virtual TextBox* createTextBox(const std::string& text, Position pos) = 0;

    virtual Button* createButton(const std::string& buttonName, Position pos) = 0;
};