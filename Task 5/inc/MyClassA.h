#pragma once
#include<INotifyPropertyChanged.h>
#include<vector>

class MyClassA : INotifyPropertyChanged
{
private:
    int mParameter;
    std::vector<std::function<void(int)>> listeners;

public:
    MyClassA(int parameter) : mParameter{parameter} {}

    void setParameter(int parameter)
    {
        mParameter = parameter;
        for (const auto& listener : listeners)
            listener(mParameter);
    }

    void addINotifyPropertyChangedListener(const std::function<void(int)>& listener) override
    {
        listeners.push_back(listener);
    }

    void removeINotifyPropertyChangedListener() override
    {
        listeners.pop_back();
    }
};