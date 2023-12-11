#pragma once

#include<MemoryRepository.h>
#include<IUserRepository.h>

class MemoryUserRepository : public IUserRepository, public MemoryRepository<User>
{
public:
    void Add(const User* item) override
    {
        MemoryRepository<User>::Add(item);
    }

    void Update(User* oldItem, User* newItem) override
    {
        MemoryRepository<User>::Update(oldItem, newItem);
    }

    void Delete(User* item) override
    {
        MemoryRepository<User>::Delete(item);
    }

    std::vector<User*> Get() override
    {
        return MemoryRepository<User>::Get();
    }

    User* getById(int id) override
    {
        for (auto user : mRepository)
        {
            if (user->getId() == id)
                return user;
        }
        return nullptr;
    }

    User* getByName(const std::string& name) override
    {
        for (auto user : mRepository)
        {
            if (user->getName() == name)
                return user;
        }
        return nullptr;
    }

    User* getByEmail(const std::string& email) override
    {
        for (auto user : mRepository)
        {
            if (user->getEmail() == email)
                return user;
        }
        return nullptr;
    }

    std::vector<User*> getByCity(const std::string& city) override
    {
        std::vector<User*> tmpVec;
        for (auto user : mRepository)
        {
            if (user->getCity() == city)
                tmpVec.push_back(user);
        }
        return tmpVec;
    }

    std::vector<User*> getByGender(Gender gender) override
    {
        std::vector<User*> tmpVec;
        for (auto user : mRepository)
        {
            if (user->getGender() == gender)
                tmpVec.push_back(user);
        }
        return tmpVec;
    }
};