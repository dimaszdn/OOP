#pragma once
#include<Windows.h>
#include<string>
#include<iostream>

namespace consUtils
{
    enum class Color
    {
        BLUE = 1,
        GREEN = 2,
        AQUA = 3,
        PURPLE = 5,
        RED = 4,
        YELLOW = 6,
        DEFAULT = 7,
        PINK = 13,
    };

    struct Point
    {
        short m_x;
        short m_y;

        void shiftX(short x) { m_x += x; }
        void shiftY(short y) { m_y += y; }
        void shiftXY(short x, short y) { m_x += x; m_y += y; }
    };

    class TextConsole
    {
    private:
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        Color m_color{Color::DEFAULT};
        Point m_point{0, 0};
        std::string m_str;

    public:
        void setPosition(Point point)
        {
            m_point = {point.m_x, point.m_y};
            this->setCursorPos({m_point.m_x, m_point.m_y});
        }

        void setColor(Color color)
        {
            m_color = color;
            SetConsoleTextAttribute(hStdOut, static_cast<int>(m_color));
        }

        void setStr(const std::string& str) { m_str = str; }

        void print()
        {
            std::cout << m_str;
            this->reset();
        }

        Point getPosition()
        {
            return m_point;
        }

    private:
        void reset()
        {
            this->setCursorPos({0, 0});
            this->setColor(Color::DEFAULT);
        }

        void setCursorPos(Point point)
        {
            SetConsoleCursorPosition(hStdOut, {point.m_x, point.m_y});
        }
    };
}