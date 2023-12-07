#pragma once

#include<Form.h>
#include<TextBox.h>
#include<Button.h>
#include<ScrollBar.h>

class Factory
{
public:
    virtual ~Factory() = default;

    virtual Form* createForm(Position pos) = 0;

    virtual TextBox* createTextBox(const std::string& text, Position pos) = 0;

    virtual Button* createButton(const std::string& buttonName, Position pos) = 0;

    virtual ScrollBar* createScrollBar(Orientation orientation, Position pos) = 0;
};