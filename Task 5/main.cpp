#include <iostream>
#include<MyClassA.h>
#include<MyClassB.h>
#include<MyCollection.h>
#include<Func.h>

int main()
{
    std::cout << "-----------" << "Test 1" << "-----------" << "\n";
    MyClassA A(40);
    std::function<void(int)> listener1 = form1;
    A.addINotifyPropertyChangedListener(listener1);
    A.setParameter(60);

    std::cout << "\n";

    std::cout << "-----------" << "Test 2" << "-----------" << "\n";
    MyClassB B(60);
    std::function<void(int, int, bool &)> listener2 = form2;
    std::function<void(int, int, bool &)> listener3 = form3;
    B.addINotifyPropertyChangedListener(listener2);
    B.addINotifyPropertyChangedListener(listener3);
    B.setParameter(30);
    std::cout << "\n";

    std::cout << "-----------" << "Test 3" << "-----------" << "\n";

    MyCollection collection;
    std::function<void(int, int, Status)> listener4 = form4;
    collection.addINotifyPropertyChangedListener(listener4);

    for (int i = 0; i < 10; ++i)
        collection.addItem(i);

    try
    {
        collection.changeItem(3, 20);
        collection.removeItem(3);
    }
    catch (const std::exception& ex) { std::cout << ex.what(); }

//    collection.removeINotifyPropertyChangedListener();
    collection.addItem(20000);
    std::cout << "\n";

    return 0;
}
