#pragma once
#include<functional>

enum class Status
{
    Added,
    Removed,
    ItemChanged
};

class INotifyCollectionChanged
{
public:
    virtual void addINotifyPropertyChangedListener(const std::function<void(int, int, Status)>& listener)
    {

    }

    virtual void removeINotifyPropertyChangedListener()
    {

    }
};