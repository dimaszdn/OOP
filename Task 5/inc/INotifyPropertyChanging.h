#pragma once
#include<functional>

class INotifyPropertyChanging
{
    virtual void addINotifyPropertyChangedListener(const std::function<void(int, int, bool&)>& listener)
    {

    }

    virtual void removeINotifyPropertyChangedListener()
    {

    }
};