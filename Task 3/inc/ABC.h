#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<vector>

using namespace std::literals::string_literals;

namespace alp
{
    class ABC
    {
    private:
        std::string m_path;
        std::ifstream abc_file;
        std::vector<std::string> m_alphabet;
        int widthLetter;
        int m_characterSize;

    public:
        explicit ABC(int characterSize) : m_characterSize{characterSize}
        {

        }

        ~ABC() {
            abc_file.close();
        }

        //ширина буквы это количество символов в верхней строке буквы z
        void setWidthLetter()
        {
            int count = 0;
            for (int i = m_alphabet[0].size() - 1; i > 0; --i)
            {
                if (m_alphabet[0][i] == ' ')
                    break;
                ++count;
            }
            widthLetter = count;
        }

        //считывает буквы в вектор строк и попутно устанавливает ширину буквы
        void readFile()
        {
            this->setPath();
            abc_file.open(m_path);
            std::string tmp;
            if (!abc_file.is_open())
                throw std::exception("abc_file not found!");
            else {
                while (!abc_file.eof()) {
                    tmp = "";
                    std::getline(abc_file, tmp);
                    m_alphabet.push_back(tmp);
                }
            }
            this->setWidthLetter();
        }

        //считывает часть нужной буквы
        void addPartLetter(int indexRow, int indexLetter, std::string& partText)
        {
            partText += m_alphabet[indexRow].substr(0 + (widthLetter * indexLetter + indexLetter), widthLetter) + " ";
        }

        void setPath()
        {
            m_path = "files/"s + "abc"s + std::to_string(m_characterSize) + ".txt"s;
        }
    };
}