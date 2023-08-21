#include "UserManager.h"

void UserManager :: userRegistration()
{
    User user = provideNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "Account created" << endl << endl;
    system("pause");
}

User UserManager :: provideNewUserData()
{
    User user;

    user.setupUserId(getNewUserId());
    string login, userName, userSurname;
    do
    {
        cout << "Provide login: ";
        cin >> login;
        user.setupLogin(login);
    } while (isLoginExist(user.getLogin()) == true);

    string password;
    cout << "Provide password: ";
    cin >> password;
    user.setupPassword(password);
    cout << "Provide name: ";
    cin >> userName;
    userName = SupportMethods :: changeFirstLetterToCapitalAndOtherToLowercase(userName);
    user.setupUserName(userName);
    cout << "Provide surname: ";
    cin >> userSurname;
    userSurname = SupportMethods :: changeFirstLetterToCapitalAndOtherToLowercase(userSurname);
    user.setupUserSurname(userSurname);

    return user;
}

int UserManager :: getNewUserId()
{
        if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;

}

bool UserManager :: isLoginExist(string login)
{
    for (unsigned int i = 0; i < users.size(); i++){

        if (users[i].getLogin() == login)
        {
            cout << endl << "User with such login already exists." << endl;
             return true;
        }
    }
    return false;
}

void UserManager :: showAllUsers() {

    for (unsigned int i = 0; i < users.size(); i++) {
        cout << "User ID: " << users[i].getUserId() << endl;
        cout << "Login: " << users[i].getLogin() << endl;
        cout << "Password: " << users[i].getPassword() << endl;
        cout << "User name: " << users[i].getUserName() << endl;
        cout << "User surname: " << users[i].getUserSurname() << endl << endl;
    }
}

bool UserManager :: ifUserIsLogged() {
    if (idLoggedUser > 0)
        return true;
    else
        return false;
}

int UserManager :: getIdLoggedUser() {
    return idLoggedUser;
}

int UserManager :: userLogIn() {
    string providedLogin = "", providedPassword = "";

    cout << endl << "Provide login: ";
    cin >> providedLogin;

    for (unsigned int i = 0; i < users.size(); i++) {

        if (users[i].getLogin() == providedLogin) {
            for (int numberOfTrial = 3; numberOfTrial > 0; numberOfTrial--) {
                cout << "Provide password. You have " << numberOfTrial << " left: ";
                cin >> providedPassword;

                if (users[i].getPassword() == providedPassword) {
                    cout << endl << "You logged successfully" << endl << endl;
                    system("pause");
                    idLoggedUser = users[i].getUserId();
                    return idLoggedUser;
                }
            }
            cout << "You have provided 3 times incorrect password" << endl;
            system("pause");
            return 0;
        }
    }
    cout << "There is no user with this login" << endl << endl;
    system("pause");
    return 0;
}

void UserManager :: logOffUser() {
    idLoggedUser = 0;
}

char UserManager :: chooseOptionFromUserMenu()
{
    char choose;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display balance for current month" << endl;
    cout << "4. Display balance for previous month" << endl;
    cout << "5. Display balance for selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log off" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choose = SupportMethods :: getCharacter();

    return choose;
}
void UserManager :: changePasswordLoggedUser(){
    string newPassword = "";
    cout << "Enter new password: " ;
    newPassword = SupportMethods::loadLine();
    bool isPasswordChanged = false;
    for(vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
        if(itr -> getUserId() == idLoggedUser){
            itr -> setupPassword(newPassword);
            isPasswordChanged = fileWithUsers.changePasswordLoggedUser(itr);
            if(isPasswordChanged)
                cout << "Your password has been changed. " << endl;
            system("pause");
        }
    }
}
