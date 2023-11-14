#pragma once

#include<TextConsole.h>
#include<Key.h>
#include<vector>

/*
 * После того как всё будет сделано, поменять
 * значения в виде чисел на переменные
 */

using namespace consUtils;

class Keyboard
{
private:
    std::vector<Key*> keys;
    std::string action;
    std::string command;
    TextConsole textAction;
    TextConsole textCommand;

    Point pointRTop{120 / 2 + 10, 2};
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

    void rebindKey()
    {

    }

    void Undo()
    {
        //Изменили command и зачистили action
        command = "Undo";

        action.clear();
        action.append(action.capacity(), ' ');

        //Сместили курсоры обратно в нужные позиции
        if (keys[lastPressKey]->getCommand() == CommandType::KeyCharCommand)
            pointLTop.shiftX(-2);
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
        //установка тексту строк
        textCommand.setStr(command);
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
                pointLTop.shiftX(2);
        }
        else
        {
            textAction.setPosition(pointLBottom);
            if (command != "Undo")
                pointLBottom.shiftY(1);
        }
        textAction.print();
    }
};

void drawSplit()
{
    TextConsole splitCol;
    TextConsole splitRow;
    splitRow.setStr("-");
    splitCol.setStr("|");
    for (short i = 0; i < 30; i++)
    {
        splitCol.setPosition({120 / 2, i});
        splitCol.print();
    }
    for (short i = 0; i < 120 / 2; ++i)
    {
        splitRow.setPosition({i, 5});
        splitRow.print();
    }
}