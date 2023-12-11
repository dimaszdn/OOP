#include<User.h>
#include<MemoryUserRepository.h>

int main()
{
    User* user1 = new User;
    user1->setCity("Moscow");
    user1->setEmail("ty@mail.ru");
    user1->setGender(Gender::Male);
    user1->setId(1);
    user1->setName("Peter");
    user1->setPhone("+843534631");

    User* user2 = new User;
    user2->setCity("Saratov");
    user2->setEmail("gh@mail.ru");
    user2->setGender(Gender::Female);
    user2->setId(2);
    user2->setName("Maria");
    user2->setPhone("+892314323");

    User* user3 = new User;
    user3->setCity("SPB");
    user3->setEmail("rt@mail.ru");
    user3->setGender(Gender::Male);
    user3->setId(3);
    user3->setName("Anton");
    user3->setPhone("+823514565");

    User* user4 = new User;
    user4->setCity("Krasnodar");
    user4->setEmail("tgh@mail.ru");
    user4->setGender(Gender::Female);
    user4->setName("Katya");
    user4->setId(4);
    user4->setPhone("+974352812");

    User* user5 = new User;
    user5->setCity("Moscow");
    user5->setEmail("op@mail.ru");
    user5->setGender(Gender::Male);
    user5->setName("Ivan");
    user5->setId(5);
    user5->setPhone("+932456712");

    MemoryUserRepository repository;
    repository.Add(user1);
    repository.Add(user2);
    repository.Add(user3);
    repository.Add(user4);

    User* userTmp1 = repository.getById(3);
    User* userTmp2 = repository.getByEmail("tgh@mail.ru");
    User* userTmp3 = repository.getByName("Maria");
    std::vector<User*> moscowUsers = repository.getByCity("Moscow");
    std::vector<User*> femaleUsers = repository.getByGender(Gender::Female);
    repository.Delete(user1);
    repository.Update(user2, user5);
    std::vector<User*> users = repository.Get();

    delete user1;
    delete user2;
    delete user3;
    delete user4;
    delete user5;

    return 0;
}