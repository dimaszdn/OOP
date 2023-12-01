#pragma once
#include<INotifyCollectionChanged.h>

class MyCollection : INotifyCollectionChanged
{
private:
    std::vector<int> items;
    std::vector<std::function<void(int, int, Status)>> listeners;

public:
    void addItem(int value)
    {
        items.push_back(value);
        for (const auto& listener : listeners)
            listener(0, value, Status::Added);
    }

    void changeItem(int index, int newValue)
    {
        items.at(index) = newValue;
        for (const auto& listener : listeners)
            listener(index, newValue, Status::ItemChanged);
    }

    void removeItem(int index)
    {
        int tmp = items.at(index);
        items.erase(items.begin() + index);
        for (const auto& listener : listeners)
            listener(index, tmp, Status::Removed);
    }

    void addINotifyPropertyChangedListener(const std::function<void(int, int, Status)>& listener) override
    {
        listeners.push_back(listener);
    }

    void removeINotifyPropertyChangedListener() override
    {
        listeners.pop_back();
    }

    /*(void print()
    {
        for (auto el : items)
            std::cout << el << " ";
        std::cout << "\n";
    }*/
};