#pragma once
#include<string>

enum class Gender
{
    Male,
    Female
};

class User
{
private:
    int mId{};
    std::string mName{};
    std::string mEmail{};
    std::string mPhone{};
    std::string mCity{};
    Gender mGender{};

public:
    User() = default;

    void setId(int id)
    {
        mId = id;
    }

    int getId() const { return mId; }

    void setName(const std::string& name)
    {
        mName = name;
    }

    std::string getName() const { return mName; }

    void setEmail(const std::string& email)
    {
        mEmail = email;
    }

    std::string getEmail() const { return mEmail; }

    void setPhone(const std::string& phone)
    {
        mPhone = phone;
    }

    std::string getPhone() const { return mPhone; }

    void setCity(const std::string& city)
    {
        mCity = city;
    }

    std::string getCity() const { return mCity; }

    void setGender(Gender gender)
    {
        mGender = gender;
    }

    Gender getGender() const { return mGender; }

    friend bool operator==(const User& left, const User& right);
};

bool operator==(const User& left, const User& right)
{
    return ((left.mId == right.mId) && (left.mGender == right.mGender) && (left.mCity == right.mCity) &&
            (left.mPhone == right.mPhone) && (left.mEmail == right.mEmail) && (left.mName == right.mName));
}