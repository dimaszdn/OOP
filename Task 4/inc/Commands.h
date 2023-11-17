#pragma once
#include<iostream>

enum class CommandType
{
    KeyCharCommand,
    CalcCommand,
    CapsLockCommand
};

class ICommand
{
protected:
    CommandType m_commandType;

public:
    virtual void Execute(std::string& command, std::string& action, const std::string& keyName) = 0;
    virtual ~ICommand() = default;

    CommandType getCommandType()
    {
        return m_commandType;
    }

    void setCommandType(CommandType commandType)
    {
        m_commandType = commandType;
    }
};

class KeyCharCommand : public ICommand
{
public:
    void Execute(std::string& command, std::string& action, const std::string& keyName) override
    {
        this->setCommandType(CommandType::KeyCharCommand);
        command = "Pressed " + keyName;
        action = keyName;
    }
};

class CapsLockCommand : public ICommand
{
public:
    void Execute(std::string& command, std::string& action, const std::string& keyName) override
    {
        this->setCommandType(CommandType::CapsLockCommand);
        command = keyName;
        action = "Register changed";
    }
};

class CalcCommand : public ICommand
{
public:
    void Execute(std::string& command, std::string& action, const std::string& keyName) override
    {
        this->setCommandType(CommandType::CalcCommand);
        command = keyName;
        action = "Calculator is open";
    }
};