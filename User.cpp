#include "User.h"

void User :: setupUserId (int newUserId) {
    if (newUserId >= 0)
        userId = newUserId;
}

void User :: setupLogin (string newLogin) {
        login = newLogin;
}

void User :: setupPassword (string newPassword) {
        password = newPassword;
}

void User :: setupUserName (string newUserName) {
        userName = newUserName;
}

void User :: setupUserSurname (string newUserSurname) {
        userSurname = newUserSurname;
}

int User :: getUserId() {
    return userId;
}

string User :: getLogin() {
    return login;
}

string User :: getPassword() {
    return password;
}

string User :: getUserName() {
    return userName;
}

string User :: getUserSurname() {
    return userSurname;
}
