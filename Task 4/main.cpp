#include<VirtualKeyboard.h>

#include <iostream>
#include<chrono>
#include<thread>

using namespace consUtils;

void drawWorkSpace()
{
    TextConsole splitCol;
    TextConsole splitRow;
    splitRow.setStr("-");
    splitCol.setStr("|");
    for (short i = 0; i < windowRow; i++)
    {
        splitCol.setPosition({windowCol / 2, i});
        splitCol.print();
    }
    for (short i = 0; i < windowCol / 2; ++i)
    {
        splitRow.setPosition({i, 5});
        splitRow.print();
    }
}

void workFlow1(Keyboard& keyboard)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
    keyboard.pressKey("W");
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

    keyboard.pressKey("Caps Lock");
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

    keyboard.pressKey("e");
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

    keyboard.pressKey("Shift");
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

    keyboard.pressKey("Fn + C");
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

    keyboard.Undo();
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
}

void workFlow2(Keyboard& keyboard)
{
    keyboard.rebindKey("Shift", new CapsLockCommand());
    keyboard.rebindKey("Caps Lock", new CalcCommand());

    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
    keyboard.pressKey("Shift");
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

    keyboard.pressKey("e");
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

    keyboard.pressKey("Caps Lock");
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
}

int main()
{
    drawWorkSpace();

    auto* keyW = new Key("W", new KeyCharCommand());
    auto* keyS = new Key("s", new KeyCharCommand());
    auto* keyD = new Key("D", new KeyCharCommand());
    auto* keyE = new Key("e", new KeyCharCommand());
    auto* keyFnC = new Key("Fn + C", new CalcCommand());
    auto* keyCaps = new Key("Caps Lock", new CapsLockCommand());
    auto* keyShift = new Key("Shift", new KeyCharCommand());

    Keyboard keyboard;
    keyboard.addKey(keyW);
    keyboard.addKey(keyS);
    keyboard.addKey(keyD);
    keyboard.addKey(keyE);
    keyboard.addKey(keyFnC);
    keyboard.addKey(keyCaps);
    keyboard.addKey(keyShift);

    try
    {
//        workFlow1(keyboard);
        workFlow2(keyboard);
    }

    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }

    system("pause");
    return 0;
}