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
    virtual ~ICommand() = default;
    virtual void Execute(std::string& action, const std::string& keyName) = 0;
    virtual void Undo() = 0;

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
    void Execute(std::string& action, const std::string& keyName) override
    {
        this->setCommandType(CommandType::KeyCharCommand);
        action = keyName;
    }
    void Undo() override
    {
        int maxLenNameKey = 20;
        for (int i = 0; i < maxLenNameKey; ++i)
            std::cout << " ";
    }
};

class CapsLockCommand : public ICommand
{
public:
    void Execute(std::string& action, const std::string& keyName) override
    {
        this->setCommandType(CommandType::CapsLockCommand);
        action = "Register changed";
    }
    void Undo() override
    {
        std::cout << "[UNDO] Register changed";
    }
};

class CalcCommand : public ICommand
{
public:
    void Execute(std::string& action, const std::string& keyName) override
    {
        this->setCommandType(CommandType::CalcCommand);
        action = "Calculator is open";
    }
    void Undo() override
    {
        std::cout << "[UNDO] Calculator is open";
    }
};