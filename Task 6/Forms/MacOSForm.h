#pragma once

#include<Form.h>

class MacOSForm : public Form
{
public:
    MacOSForm(Position pos) : Form(pos)
    {
        std::cout << "������� ����� ��� MacOS!" << "\n";
    }
};