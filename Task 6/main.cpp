#include <iostream>
#include<WinFactory.h>
#include<LinuxFactory.h>
#include<MacOSFactory.h>
#include<OS.h>

//Добавить ещё один control и на этом всё

int main()
{
    setlocale(LC_ALL, "RUS");

    Factory* factory = nullptr;
    Form* form = nullptr;
    OS systemType = OS::MacOs;
    switch (systemType)
    {
        case OS::Windows:
            factory = new WinFactory;
            break;
        case OS::Linux:
            factory = new LinuxFactory;
            break;
        case OS::MacOs:
            factory = new MacOSFactory;
            break;
    }
    form = factory->createForm({4, 4});
    form->addControl(factory->createButton("Enter", {10, 10}));
    form->addControl(factory->createButton("Esc", {12, 12}));
    form->addControl(factory->createTextBox("Let's", {5, 5}));
    form->addControl(factory->createTextBox("Go", {20, 20}));

    for (auto* control : form->controls)
    {
        std::cout << control->className() << " ";
        if (auto* button = dynamic_cast<Button*>(control))
            button->press();
        else if (auto* textBox = dynamic_cast<TextBox*>(control))
            textBox->print();
    }

    delete factory;
    delete form;

    return 0;
}