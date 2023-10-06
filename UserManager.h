#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "FileWithUsers.h"
#include "User.h"

using namespace std;

class UserManager {

    int idLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User provideNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);

public:
    UserManager (string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
        idLoggedUser = 0;
        users = fileWithUsers.loadUserFromFile();
    };

    void userRegistration();
    void showAllUsers();
    void logOffUser();
    void changePasswordLoggedUser();
    bool ifUserIsLogged();
    int getIdLoggedUser();
    int userLogIn();
    char chooseOptionFromUserMenu();

};

#endif
