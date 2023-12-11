#pragma once

#include<string>
#include<IRepository.h>
#include<User.h>

class IUserRepository : public IRepository<User>
{
public:
    virtual User* getById(int id) = 0;

    virtual User* getByName(const std::string& name) = 0;

    virtual User* getByEmail(const std::string& email) = 0;

    virtual std::vector<User*> getByCity(const std::string& city) = 0;

    virtual std::vector<User*> getByGender(Gender gender) = 0;
};