#pragma once

#include<Form.h>

class LinuxForm : public Form
{
public:
    LinuxForm(Position pos) : Form(pos)
    {
        std::cout << "Создана форма для Linux!" << "\n";
    }
};