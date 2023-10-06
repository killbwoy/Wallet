#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "ItemManager.h"
#include "DateManager.h"

using namespace std;

class PersonalBudget {


    UserManager userManager;
    ItemManager *itemManager;
    const string FILE_NAME_WITH_USERS;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    PersonalBudget(string fileNameWithUsers, string FileNameWithIncomes, string FileNameWithExpenses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(FileNameWithIncomes), FILE_NAME_WITH_EXPENSES (FileNameWithExpenses) {
        itemManager = NULL;
    }
    ~PersonalBudget() {
        delete itemManager;
        itemManager = NULL;
    };

    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void userRegistration();
    void showAllUsers();
    bool ifUserIsLogged();
    void userLogIn();
    void logOffUser();
    void addIncome();
    void addExpense();
    void changePasswordLoggedUser();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    void displayBalanceForSelectedPeriod();
};


#endif
