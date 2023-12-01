#pragma once
#include<iostream>
#include<functional>

class INotifyPropertyChanged
{
public:
    virtual void addINotifyPropertyChangedListener(const std::function<void(int)>& listener)
    {

    }

    virtual void removeINotifyPropertyChangedListener()
    {

    }
};