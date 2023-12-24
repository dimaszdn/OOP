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
    int lastPressKey;
    bool capsLock = false;
    bool undo = false;

    //исключительно для вывода
    TextConsole textAction;
    TextConsole textCommand;
    Point pointRTop{windowCol / 2 + 10, 2};
    Point pointLTop{2, 2};
    Point pointLBottom{2, 8};

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
            keys[lastPressKey]->Execute(); //вызов нужной кнопки
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
        undo = true;
        if (keys[lastPressKey]->getCommand()->getCommandType() == CommandType::KeyCharCommand)
        {
            //передвинули указатель обратно
            pointLTop.shiftX(static_cast<short>(-(1 + keys[lastPressKey]->getAction().size())));
            //установили курсор в нужную позицию
            textAction.setPosition(pointLTop);
            //вызвали undo и затёрли напечатанную букву
            keys[lastPressKey]->getCommand()->Undo();
        }
        else
        {
            //установили курсор в нужную позицию
            textAction.setPosition(pointLBottom);
            //вызвали undo и отменили системное действие, которое произошло
            keys[lastPressKey]->getCommand()->Undo();
            //сместили курсор
            pointLBottom.shiftY(1);
        }
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
        //----вывод в правую часть----
        std::string command;

        //формируем строку command для вывода
        if (undo)
            command = "Undo";
        else if (keys[lastPressKey]->getCommand()->getCommandType() == CommandType::KeyCharCommand)
            command = "Pressed " + keys[lastPressKey]->getKeyName();
        else
            command = keys[lastPressKey]->getKeyName();

        //Устанавливаем textCommand, его позицию, выводим, смещаем указатель
        textCommand.setStr(command);
        textCommand.setPosition(pointRTop);
        textCommand.print();
        pointRTop.shiftY(1);

        //----вывод в левую верхнюю и нижние части----
        std::string action = keys[lastPressKey]->getAction();

        //проверяем на Caps Lock
        this->setCapsLock();
        if (this->checkCapsLockPressed() && action.size() == 1)
            action[0] = static_cast<char>(std::toupper(action[0]));

        //если undo, то action уже печатать не нужно
        if (!undo)
        {
            //Устанавливаем textAction
            textAction.setStr(action);

            //устанавливаем позицию
            if (keys[lastPressKey]->getCommand()->getCommandType() == CommandType::KeyCharCommand)
            {
                textAction.setPosition(pointLTop);
                pointLTop.shiftX(static_cast<short>(action.size() + 1));
            }
            else
            {
                textAction.setPosition(pointLBottom);
                pointLBottom.shiftY(1);
            }
            //выводим textAction
            textAction.print();
        }
        //отмена произошла => возвращаем undo в false
        undo = false;
    }

    [[nodiscard]] bool checkCapsLockPressed() const { return capsLock; }

    void setCapsLock()
    {
        if (keys[lastPressKey]->getCommand()->getCommandType() == CommandType::CapsLockCommand)
        {
            if (!capsLock)
                capsLock = true;
            else
                capsLock = false;
        }
    }
};