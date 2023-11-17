#pragma once

#include<Global.h>
#include<TextConsole.h>
#include<Key.h>
#include<vector>

using namespace consUtils;

class Keyboard
{
private:
    std::vector<Key*> keys;
    std::string action;
    std::string command;
    TextConsole textAction;
    TextConsole textCommand;

    Point pointRTop{windowCol / 2 + 10, 2};
    Point pointLTop{2, 2};
    Point pointLBottom{2, 8};

    int lastPressKey;
    bool capsLock = false;

public:
    ~Keyboard()
    {
        if (!keys.empty())
        {
            for (auto key : keys)
                delete key;
        }
    }

    void pressKey(const std::string& keyName)
    {
        lastPressKey = this->searchKey(keyName);
        if (lastPressKey == -1)
            throw std::logic_error("There is no such button!");
        else
        {
            keys[lastPressKey]->Execute(command, action); //вызов нужной кнопки
            this->status();
        }
    }

    void addKey(Key* key)
    {
        keys.push_back(key);
    }

    void rebindKey(const std::string& key, ICommand* newCommand)
    {
        keys[this->searchKey(key)]->setCommand(newCommand);
    }

    void Undo()
    {
        //Изменили command и зачистили action
        command = "Undo";

        for (int i = 0; i < action.size(); ++i)
            action[i] = ' ';

        //Сместили курсоры обратно в нужные позиции
        if (keys[lastPressKey]->getCommand() == CommandType::KeyCharCommand)
            pointLTop.shiftX(static_cast<short>(-(1 + action.size())));
        else
            pointLBottom.shiftY(-1);

        //Вызвали статус клавиатуры
        this->status();
    }

private:
    int searchKey(const std::string& keyName)
    {
        for (int i = 0; i < keys.size(); ++i)
            if (keys[i]->getKeyName() == keyName)
                return i;
        return -1;
    }

    void status()
    {
        //передаем action и command в предназначенные им тексты и проверяем нажат ли Caps Lock
        textCommand.setStr(command);

        this->setCapsLock();
        if (this->checkCapsLockPressed() && action.size() == 1)
            action[0] = static_cast<char>(std::toupper(action[0]));
        textAction.setStr(action);

        //выводим команду
        textCommand.setPosition(pointRTop);
        textCommand.print();
        pointRTop.shiftY(1);

        //выводим действие
        if (keys[lastPressKey]->getCommand() == CommandType::KeyCharCommand)
        {
            textAction.setPosition(pointLTop);
            if (command != "Undo")
                pointLTop.shiftX(static_cast<short>(action.size() + 1));
        }
        else
        {
            textAction.setPosition(pointLBottom);
            if (command != "Undo")
                pointLBottom.shiftY(1);
        }
        textAction.print();
    }

    [[nodiscard]] bool checkCapsLockPressed() const { return capsLock; }

    void setCapsLock()
    {
        if (keys[lastPressKey]->getCommand() == CommandType::CapsLockCommand)
        {
            if (!capsLock)
                capsLock = true;
            else
                capsLock = false;
        }
    }
};