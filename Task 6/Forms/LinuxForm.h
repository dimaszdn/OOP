#pragma once

#include<Form.h>

class LinuxForm : public Form
{
public:
    LinuxForm(Position pos) : Form(pos)
    {
        std::cout << "������� ����� ��� Linux!" << "\n";
    }
};