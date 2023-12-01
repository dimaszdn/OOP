#pragma once
#include<iostream>

void form1(int value)
{
    std::cout << "[form1]-->";
    std::cout << "The parameter has been changed to " << "{" << value << "}" << "\n";
}

void form2(int oldVal, int newVal, bool& cancel)
{
//    std::cout << "[form2]-->";
    if (oldVal <= newVal)
    {
        cancel = true;
//        std::cout << "The parameter value remains the old" << "\n";
        std::cout << "[form2] remains the same!" << "\n";
    }
    else
    {
        cancel = false;
//        std::cout << "Parameter value changed from " << "{" << oldVal << "}" << " to " << "{" << newVal << "}" << "\n";
        std::cout << "[form2] has been changed!" << "\n";
    }
}

void form3(int oldVal, int newVal, bool& cancel)
{
//    std::cout << "[form3]-->";
    if (std::max(oldVal, newVal) / std::min(oldVal, newVal) == 2)
    {
        cancel = true;
//        std::cout << "The parameter value remains the old" << "\n";
        std::cout << "[form3] remains the same!" << "\n";
    }
    else
    {
        cancel = false;
//        std::cout << "Parameter value changed from " << "{" << oldVal << "}" << " to " << "{" << newVal << "}" << "\n";
        std::cout << "[form3] has been changed!" << "\n";
    }
}

void form4(int index, int value, Status status)
{
    std::cout << "[form4]-->";
    switch (status)
    {
        case Status::Added:
            std::cout << "Add element " << "{" << value << "}" << "\n";
            break;

        case Status::ItemChanged:
            std::cout << "The element at index " << "{" << index << "}" << " has been changed. ";
            std::cout << "The new value is " << "{" << value << "}" << "\n";
            break;

        case Status::Removed:
            std::cout << "The element at index " << "{" << index << "}" << " has been deleted." << "\n";
            break;
    }
}