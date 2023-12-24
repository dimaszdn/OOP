#pragma once

#include<Commands.h>
#include<string>

class Key
{
private:
    std::string m_keyName;
    std::string m_action;
    ICommand* m_command;

public:
    Key(const std::string& keyName, ICommand* command) : m_keyName{keyName},
        m_command{command}
    {}

    ~Key()
    {
        delete m_command;
    }

    void Execute()
    {
        m_command->Execute(m_action, m_keyName);
    }

    void setCommand(ICommand* command)
    {
        m_command = command;
    }

    ICommand* getCommand() { return m_command; }

    const std::string& getKeyName() { return m_keyName; }

    const std::string& getAction() { return m_action; }
};