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

    bool undo = 0;

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
        int indexKey = this->searchKey(keyName);
        if (indexKey == -1)
            throw std::logic_error("There is no such button!");
        else
        {
            keys[indexKey]->Execute(command, action); //вызов нужной кнопки
            this->status(indexKey);
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
        textCommand.setStr("Undo");
        textCommand.setPosition(pointRTop);
        textCommand.print();
        pointRTop.shiftY(1);

        textAction.clear();
        if (textAction.getPosition().m_x != pointLTop.m_x - 2)
        {
            pointLTop.shiftY(-1);
            textAction.setPosition(pointLTop);
        }
        else
        {
            pointLBottom.shiftX(-2);
            textAction.setPosition(pointLBottom);
        }
        textAction.print();
//        //Распечатали команду отмены
//        command = "Undo";
//        textCommand.setStr(command);
//        textCommand.setPosition(pointRTop);
//        pointRTop.shiftY(1);
//
//        //Убираем последнее выведенное действие
//        action = "";
//        textAction.setStr(action);
//        if (action.size() > 1)
//        {
//            pointLBottom.shiftY(-1);
//            textAction.setPosition(pointLBottom);
//        }
//        else
//        {
//            pointLTop.shiftX(-2);
//            textAction.setPosition(pointLTop);
//        }
//        textAction.print

    }

private:
    int searchKey(const std::string& keyName)
    {
        for (int i = 0; i < keys.size(); ++i)
            if (keys[i]->getKeyName() == keyName)
                return i;
        return -1;
    }

    void status(int indexKey)
    {
        textCommand.setStr(command);
        textAction.setStr(action);
        if (keys[indexKey]->getCommand() == CommandType::KeyCharCommand)
        {
            textCommand.setPosition(pointRTop);
            textCommand.print();

            textAction.setPosition(pointLTop);
            textAction.print();

            pointRTop.shiftY(1); //перевели сразу возможную команду на новую строку
            pointLTop.shiftX(2); //передвинули клавишу нажатую
        }
        else
        {
            textCommand.setPosition(pointRTop);
            textCommand.print();

            textAction.setPosition(pointLBottom);
            textAction.print();

            pointRTop.shiftY(1);
            pointLBottom.shiftY(1);
        }
        if (undo)
        {

        }
    }
    /*
    void status()
    {
        textCommand.setStr(command);
        textAction.setStr(action);
        if (command.find("Pressed") != std::string::npos)
        {
            textCommand.setPosition(pointRTop);
            textCommand.print();

            textAction.setPosition(pointLTop);
            textAction.print();

            pointRTop.shiftY(1); //перевели сразу возможную команду на новую строку
            pointLTop.shiftX(2); //передвинули клавишу нажатую
        }
        else
        {
            textCommand.setPosition(pointRTop);
            textCommand.print();

            textAction.setPosition(pointLBottom);
            textAction.print();

            pointRTop.shiftX(1);
            pointLBottom.shiftY(1);
        }
    }*/
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