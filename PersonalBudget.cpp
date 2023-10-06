#include "PersonalBudget.h"
#include "SupportMethods.h"
#include "User.h"

using namespace std;

char PersonalBudget :: chooseOptionFromMainMenu() {
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

bool PersonalBudget :: ifUserIsLogged() {
    return userManager.ifUserIsLogged();
}

void PersonalBudget :: userLogIn() {

    userManager.userLogIn();
    if (userManager.ifUserIsLogged()) {
        itemManager = new ItemManager (FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES, userManager.getIdLoggedUser()); //Jesli uzytkownik jest zalogowany, tworzony jest nowy obiekt klasy ItemManager. Ten obiekt przyjmuje dwa argumenty:
    }
}

void PersonalBudget :: logOffUser() {
    userManager.logOffUser();
    delete itemManager;
    itemManager = NULL;
}

char PersonalBudget :: chooseOptionFromUserMenu() {
    return userManager.chooseOptionFromUserMenu();
}

void PersonalBudget :: addIncome() {

    if (userManager.ifUserIsLogged()) {
        itemManager->addIncome();
    }
}
void PersonalBudget :: changePasswordLoggedUser() {
    userManager.changePasswordLoggedUser();
}
void PersonalBudget :: addExpense() {

    if (userManager.ifUserIsLogged()) {
        itemManager->addExpense();
    }
}
void PersonalBudget :: displayBalanceForCurrentMonth() {
    return itemManager -> displayBalanceForCurrentMonth();
}
void PersonalBudget :: displayBalanceForPreviousMonth() {
    return itemManager -> displayBalanceForPreviousMonth();
}

void PersonalBudget :: displayBalanceForSelectedPeriod(){
    return itemManager -> displayBalanceForSelectedPeriod();
}
