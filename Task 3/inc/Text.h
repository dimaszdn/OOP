#pragma once
#include<ABC.h>
#include<Windows.h>

namespace txt
{
    enum class Color
    {
        BLUE = 1,
        GREEN = 2,
        AQUA = 3,
        PURPLE = 5,
        RED = 4,
        YELLOW = 6,
        WHITE = 7,
        PINK = 13,
    };

    struct Point
    {
        short m_x;
        short m_y;
    };

    class Text
    {
    private:
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        alp::ABC m_abc;
        Color m_color;
        int m_characterSize;
        std::string m_str;
        Point m_point;
        std::vector<std::string> m_text;

    public:
        Text(const std::string &str, int characterSize, Color color, Point point) :
                m_str{str},
                m_characterSize{characterSize},
                m_color{color},
                m_abc(characterSize),
                m_point{point}
        {

        }

        void setPosition(Point point)
        {
            m_point = {point.m_x, point.m_y};
            SetConsoleCursorPosition(hStdOut, {m_point.m_x, m_point.m_y});
        }

        void setColor(Color color)
        {
            m_color = color;
            SetConsoleTextAttribute(hStdOut, static_cast<int>(m_color));
        }

        void print()
        {
            this->setup();
            if (m_characterSize == 1)
                std::cout << m_str << "\n";
            else
            {
                for (int i = 0; i < m_text.size(); ++i)
                {
                    this->setPosition({m_point.m_x, m_point.m_y});
                    std::cout << m_text[i] << "\n";
                    ++m_point.m_y;
                }
            }
            this->reset(); //сбросили параметры в 0
        }

    private:
        void recordText()
        {
            std::string partText;
            for (int i = 0; i < m_characterSize; ++i)
            {
                for (int j = 0; j < m_str.size(); ++j)
                {
                    if (m_str[j] == ' ')
                    {
                        partText += "  ";
                        continue;
                    }
                    m_abc.addPartLetter(i, m_str[j] - (int)'A', partText);
                }
                m_text.push_back(partText);
                partText = "";
            }
        }

        void reset()
        {
            this->setPosition({0, 0});

            this->setColor(Color::WHITE);
        }

        void setup()
        {
            if (m_characterSize != 1 && m_text.empty())
            {
                m_abc.readFile();
                this->recordText();
            }
            this->setColor(m_color);
            this->setPosition({m_point.m_x, m_point.m_y});
        }
    };
}
