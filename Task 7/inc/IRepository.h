#pragma once
#include<vector>
#include<string>

template<class T>
class IRepository
{
public:
    virtual void Add(const T* item) = 0;

    virtual void Update(T* oldItem, T* newItem) = 0;

    virtual void Delete(T* item) = 0;

    virtual std::vector<T*> Get() = 0;
};