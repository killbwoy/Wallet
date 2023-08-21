#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int userId;
    string login;
    string password;
    string userName;
    string userSurname;

public:
    User(int userId = 0, string login = "", string password = "", string userName = "", string userSurname = "")
    {
        this->userId = userId;
        this->login = login;
        this->password = password;
        this->userName = userName;
        this->userSurname = userSurname;
    }

    void setupUserId (int newUserId);
    void setupLogin (string newLogin);
    void setupPassword (string newPassword);
    void setupUserName (string newUserName);
    void setupUserSurname (string newUserSurname);

    int getUserId();
    string getLogin();
    string getPassword();
    string getUserName();
    string getUserSurname();
};

#endif
