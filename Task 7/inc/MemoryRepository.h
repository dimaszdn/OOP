#pragma once

#include<vector>
#include<iostream>
#include<IRepository.h>

template<class T>
class MemoryRepository : public IRepository<T>
{
protected:
    std::vector<T*> mRepository;

public:
    MemoryRepository() = default;

     ~MemoryRepository()
     {
         if (!mRepository.empty())
         {
             for (auto item : mRepository)
             {
                 delete item;
             }
         }
     }

     void Add(const T* item) override
     {
         T* tmpItem = new T(*item);
         mRepository.push_back(tmpItem);
     }

     void Update(T* oldItem, T* newItem) override
     {
         if (*oldItem == *newItem)
             throw std::logic_error("oldItem == newItem");

         for (int i = 0; i < mRepository.size(); ++i)
         {
             if (*oldItem == *mRepository[i])
             {
                 delete mRepository[i];
                 T* tmpItem = new T(*newItem);
                 mRepository[i] = tmpItem;
                 return;
             }
         }
         throw std::logic_error("Error updating the object!");
     }

     void Delete(T* item) override
     {
         for (int i = 0; i < mRepository.size(); ++i)
         {
             if (*item == *mRepository[i])
             {
                 delete mRepository[i];
                 mRepository.erase(mRepository.begin() + i);
                 return;
             }
         }
     }

     std::vector<T*> Get() override
     {
         return mRepository;
     }
};