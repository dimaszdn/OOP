#pragma once

#include<Form.h>

class WinForm : public Form
{
public:
    WinForm(Position pos) : Form(pos)
    {
        std::cout << "������� ����� ��� Windows!" << "\n";
    }
};