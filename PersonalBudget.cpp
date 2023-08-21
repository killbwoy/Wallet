#include "PersonalBudget.h"

char PersonalBudget :: chooseOptionFromMainMenu()
{
    char choose;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. End " << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choose = SupportMethods :: getCharacter();

    return choose;
}

void PersonalBudget :: userRegistration() {

    userManager.userRegistration();
}

void PersonalBudget :: showAllUsers() {

    userManager.showAllUsers();
}

bool PersonalBudget :: ifUserIsLogged(){
    userManager.ifUserIsLogged();
}

int PersonalBudget :: userLogIn() {

    userManager.userLogIn();
    if (userManager.ifUserIsLogged())
    {
        itemManager = new ItemManager (FILE_NAME_WITH_INCOMES, userManager.getIdLoggedUser()); //Jesli uzytkownik jest zalogowany, tworzony jest nowy obiekt klasy ItemManager. Ten obiekt przyjmuje dwa argumenty:
    }
}

void PersonalBudget :: logOffUser(){
    userManager.logOffUser();
    delete itemManager;
    itemManager = NULL;
}

char PersonalBudget :: chooseOptionFromUserMenu(){
    userManager.chooseOptionFromUserMenu();
}

void PersonalBudget :: addIncome() {

    if (userManager.ifUserIsLogged()) {
        itemManager->addIncome();
    } else {

        cout << "You need to login " << endl;
        system ("pause");
    }
}
void PersonalBudget :: changePasswordLoggedUser(){
    userManager.changePasswordLoggedUser();
}
