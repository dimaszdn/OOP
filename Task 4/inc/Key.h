#pragma once

#include<Commands.h>
#include<string>

class Key
{
private:
    std::string m_keyName;
    ICommand* m_command;

public:
    Key(const std::string& keyName, ICommand* command) : m_keyName{keyName},
        m_command{command}
    {}

    ~Key()
    {
        delete m_command;
    }

    void Execute(std::string& command, std::string& action)
    {
        m_command->Execute(command, action, m_keyName);
    }

    void setCommand(ICommand* command)
    {
        m_command = command;
    }

    CommandType getCommand() { return m_command->getCommandType(); }

    const std::string& getKeyName() { return m_keyName; }
};