#include<VirtualKeyboard.h>

#include <iostream>
#include<chrono>
#include<thread>

/*
 * подумать как сделать так, чтобы:
 *  вывело сначала "а" например
 *  потом рядом "b"
 *  возможно для этого уже нужно продумать работу класса keyboard

   Undo - отменяет последнюю кнопку?
 */

using namespace consUtils;

const int SLEEP_TIME = 3000;

int main()
{
    drawSplit();

    auto* keyW = new Key("W", new KeyCharCommand());
    auto* keyS = new Key("S", new KeyCharCommand());
    auto* keyA = new Key("A", new KeyCharCommand());
    auto* keyD = new Key("D", new KeyCharCommand());
    auto keyFnC = new Key("Fn + C", new CalcCommand());

    Keyboard keyboard;
    keyboard.addKey(keyW);
    keyboard.addKey(keyS);
    keyboard.addKey(keyA);
    keyboard.addKey(keyD);
    keyboard.addKey(keyFnC);

    try
    {
        keyboard.pressKey("W");
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

        keyboard.pressKey("S");
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

        keyboard.pressKey("A");
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

        keyboard.pressKey("D");
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

        keyboard.pressKey("Fn + C");
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

        keyboard.Undo();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }

    system("pause");
    return 0;
}