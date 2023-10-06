#include <iostream>
#include "PersonalBudget.h"


using namespace std;

int main() {
    PersonalBudget personalBudget ("Users.xml", "Incomes.xml", "Expenses.xml");
    char choose = 0;

    while (true) {
        if (!personalBudget.ifUserIsLogged()) {
            choose = personalBudget.chooseOptionFromMainMenu();

            switch (choose) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choose = personalBudget.chooseOptionFromUserMenu();
            switch (choose) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayBalanceForCurrentMonth();
                break;
            case '4':
                personalBudget.displayBalanceForPreviousMonth();
                break;
            case '5':
                personalBudget.displayBalanceForSelectedPeriod();
                break;
            case '6':
                personalBudget.changePasswordLoggedUser();
                break;
            case '7':
                personalBudget.logOffUser();
                break;
            default:
                cout << endl << "No such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
