#include <Text.h>
#include <iostream>
#include<string>

int main()
{
    std::string s = "WELCOME";
    std::string s1 = "HOTLINE MIAMI";
    std::string s2 = "ENEMIES";

    txt::Text text7(s2, 7, txt::Color::YELLOW, {9, 16}); //5 5
    txt::Text text5(s1, 5, txt::Color::PINK, {6, 8}); //20 20
    txt::Text text1(s, 1, txt::Color::RED, {5, 5}); //15 15
    try
    {
        text1.print();
        text5.print();
        text7.print();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    system("pause");
    return 0;
}
