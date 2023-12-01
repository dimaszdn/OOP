#pragma once
#include<INotifyPropertyChanging.h>

class MyClassB : INotifyPropertyChanging
{
private:
    int mParameter;
    std::vector<std::function<void(int, int, bool&)>> listeners;

public:
    MyClassB(int parameter) : mParameter{parameter} {}

    void setParameter(int parameter)
    {
        bool cancel;

        for (const auto& listener : listeners)
            listener(mParameter, parameter, cancel);

        if (cancel)
            return;

        mParameter = parameter;
    }

    void addINotifyPropertyChangedListener(const std::function<void(int, int, bool&)>& listener) override
    {
        listeners.push_back(listener);
    }

    void removeINotifyPropertyChangedListener() override
    {
        listeners.pop_back();
    }
};