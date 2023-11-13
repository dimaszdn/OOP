#pragma once
#include<iostream>

class ICommand
{
public:
    virtual void Execute(std::string& command, std::string& action, const std::string& keyName) = 0;
    virtual ~ICommand() = default;
};

class KeyCharCommand : public ICommand
{
public:
    void Execute(std::string& command, std::string& action, const std::string& keyName) override
    {
        command = "Pressed " + keyName;
        action = keyName;
    }
};

class AltShiftCommand : public ICommand
{
public:

};

class CalcCommand : public ICommand //калькулятор открывается
{
public:
    void Execute(std::string& command, std::string& action, const std::string& keyName) override
    {
        command = "Fn + C";
        action = "Calculator is open";
    }
};