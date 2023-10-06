#include "ItemManager.h"

using namespace std;

void ItemManager :: addIncome() {
    Income income;
    income = provideIncomeDetails();
    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);
    cout << endl << "Income added to the file" << endl << endl;
    showAllIncomes();
    system("pause");
}

void ItemManager :: addExpense() {
    Expense expense;
    expense = provideExpenseDetails();
    expenses.push_back(expense);
    expenseFile.addExpenseToFile(expense);
    cout << endl << "Expense added to the file" << endl << endl;
    showAllExpenses();
    system("pause");
}

Income ItemManager :: provideIncomeDetails() {
    Income income;
    DateManager dateManager;
    string incomeName = "", userSurname = "", otherDate = "", stringDatewithoutDash = "", currentStringDate = "", stringAmount = "";
    int currentDate = 0;
    float amount = 0;
    char choice;

    income.setupIncomeId(incomeFile.getLastIncomeId() + 1);
    income.setupUserId(ID_LOGGED_USER);

    do
        {
    cout << "Do you want to add income with current date? [y/n] .If you want to chose other date, please press 'n': " << endl;
    choice = SupportMethods :: getCharacter();
    cout << endl;
    }while(choice != 'y' && choice != 'n');

    if (choice == 'y') {
        currentDate = dateManager.getCurrentDate();
        currentStringDate = SupportMethods :: convertIntToString(currentDate);
        currentStringDate = SupportMethods :: addDashToDate (currentStringDate);
        income.setupStringDate(currentStringDate);
    } else if (choice == 'n') {
        bool stayInLoop = false;
        do {
            stayInLoop = false;
            cout << "Provide date in format YYYY-MM-DD: ";
            otherDate = SupportMethods :: loadLine();
            if (dateManager.isDateCorrect(otherDate) == false) {
                stayInLoop = true;
                cout << "Invalid date format." << endl;
            }
        } while (stayInLoop);
        stringDatewithoutDash = SupportMethods :: removeDashFromDate(otherDate);
        income.setupStringDate(otherDate);
    } else {
        cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
    }
    cout << "Provide income description: ";
    incomeName = SupportMethods :: loadLine();
    income.setupIncomeName(incomeName);
    cout << "Provide amount: ";
    amount = SupportMethods :: loadFloat();
    income.setupIncomeAmount(amount);

    return income;
}

Expense ItemManager :: provideExpenseDetails() {
    Expense expense;
    DateManager dateManager;
    string expenseName = "", userSurname = "", otherDate = "", stringDatewithoutDash = "", currentStringDate = "", stringAmount = "";
    int currentDate = 0;
    float amount = 0;
    char choice;

    expense.setupExpenseId(expenseFile.getLastExpenseId() + 1);
    expense.setupUserId(ID_LOGGED_USER);

    cout << "Do you want to add expense with current date? [y/n] .If you want to chose other date, please click 'n': " << endl;
    choice = SupportMethods :: getCharacter();
    cout << endl;

    if (choice == 'y') {
        currentDate = dateManager.getCurrentDate();
        currentStringDate = SupportMethods :: convertIntToString(currentDate);
        currentStringDate = SupportMethods :: addDashToDate (currentStringDate);
        expense.setupStringDate(currentStringDate);
    } else if (choice == 'n') {

        do {
            cout << "Provide date in format YYYY-MM-DD: ";
            otherDate = SupportMethods :: loadLine();
            if (dateManager.isDateCorrect(otherDate) == false) {
                cout << "Invalid date format." << endl;
            }
        } while (dateManager.isDateCorrect(otherDate) == false);
        stringDatewithoutDash = SupportMethods :: removeDashFromDate(otherDate);
        expense.setupStringDate(otherDate);
    } else {
        cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
    }
    cout << "Provide expense description: ";
    expenseName = SupportMethods :: loadLine();
    expense.setupExpenseName(expenseName);
    cout << "Provide amount: ";
    amount = SupportMethods :: loadFloat();
    expense.setupExpenseAmount(amount);

    return expense;
}

void ItemManager :: viewIncome(vector <Income> :: iterator income) {

    cout << "Description: " << income -> getIncomeName() << endl;
    cout << "Date:        " << income -> getIncomeDate() << endl;
    cout << "Amount:      " << income -> getIncomeAmount() << endl;
}

void ItemManager :: viewExpense(vector <Expense> :: iterator expense) {

    cout << "Description: " << expense -> getExpenseName() << endl;
    cout << "Date:        " << expense -> getExpenseDate() << endl;
    cout << "Amount:      " << expense ->getExpenseAmount() << endl;
}

void ItemManager :: showAllIncomes() {

    for (unsigned int i = 0; i < incomes.size(); i++) {
        cout << "Income Id: " << incomes[i].getIncomeId() << endl;
        cout << "User Id: " << incomes[i].getUserId() << endl;
        cout << "Income date: " << incomes[i].getIncomeDate() << endl;
        cout << "Income name: " << incomes[i].getIncomeName() << endl;
        cout << "Income amount: " << incomes[i].getIncomeAmount() << endl << endl;
    }
}

void ItemManager :: showAllExpenses() {

    for (unsigned int i = 0; i < expenses.size(); i++) {
        cout << "Expense Id: " << expenses[i].getExpenseId() << endl;
        cout << "User Id: " << expenses[i].getUserId() << endl;
        cout << "Expense date: " << expenses[i].getExpenseDate() << endl;
        cout << "Expense name: " << expenses[i].getExpenseName() << endl;
        cout << "Expense amount: " << expenses[i].getExpenseAmount() << endl << endl;
    }
}

void ItemManager :: displayBalanceForCurrentMonth() {
    int todaysDate = dateManager.getCurrentDate();
    int minDate = (todaysDate/100)*100 + 1;
    int maxDate = (todaysDate/100 + 1)*100;
    cout << fixed << setprecision(2);
    system("cls");
    sortByDateIncomes();
    cout << "Incomes in current month:  " << endl;
    cout << "--------------------------" << endl;
    viewSelectedIncomes(minDate, maxDate);
    sortByDateExpenses();
    cout << endl << "Expenses in current month: " << endl;
    cout << "--------------------------" << endl;
    viewSelectedExpenses(minDate, maxDate);
    cout << "------------------------------" << endl;
    cout << endl <<  "\t>>> Summary <<<  " << endl;
    cout << "------------------------------" << endl;
    if(sumOfIncomes == 0) {
        cout << "Sum of incomes: none" << endl;
    } else
        cout << "Sum of incomes:  " << "\t" << sumOfIncomes << endl;

    if(sumOfExpenses == 0) {
        cout << "Sum of expenses: none" << endl;
    } else
        cout << "Sum of expenses: \t" << sumOfExpenses << endl;
    cout << "----------------------------------" << endl;
    cout << "Balance of current month: \t" << showpos << sumOfIncomes - sumOfExpenses << endl;
    cout << "----------------------------------" << endl;
    cout << noshowpos << endl;
    sumOfIncomes = 0;
    sumOfExpenses = 0;
    system("pause");
}
void ItemManager :: sortByDateIncomes() {
    sort(incomes.begin(), incomes.end(), [] (auto& lhs, auto& rhs) {
    return lhs.getIntDate() < rhs.getIntDate();
});
}

void ItemManager :: sortByDateExpenses() {
    sort(expenses.begin(), expenses.end(), [] (auto& lhs, auto& rhs) {
    return lhs.getIntDate() < rhs.getIntDate();
});
}

void ItemManager :: viewSelectedIncomes(int minDate, int maxDate) {
    bool incomeExist = false;
    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        int date = SupportMethods :: convertStringToInt(SupportMethods :: removeDashFromDate(itr -> getIncomeDate()));
        if(date >= minDate && date <= maxDate) {
            incomeExist = true;
            sumUpIncomes(itr);
            viewIncome(itr);
            cout << endl;
        }
    }
    if (!incomeExist)
        cout << "No incomes were introduced" << endl;
}

void ItemManager :: sumUpIncomes (vector <Income> :: iterator itr) {
    sumOfIncomes += itr -> getIncomeAmount();
}

void ItemManager :: viewSelectedExpenses(int minDate, int maxDate) {
    bool expenseExist = false;
    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        int date = SupportMethods :: convertStringToInt(SupportMethods :: removeDashFromDate(itr -> getExpenseDate()));
        if(date >= minDate && date <= maxDate) {
            expenseExist = true;
            sumUpExpenses(itr);
            viewExpense(itr);
            cout << endl;
        }
    }
    if (!expenseExist)
        cout << "No expenses were introduced." << endl;
}

void ItemManager :: sumUpExpenses (vector <Expense> :: iterator itr) {
    sumOfExpenses += itr -> getExpenseAmount();
}

void ItemManager :: displayBalanceForPreviousMonth() {
    int todaysDate = dateManager.getCurrentDate();
    int minDate = (todaysDate/100 - 1)*100 + 1;
    int maxDate = (todaysDate/100)*100;
    cout << fixed << setprecision(2);
    system("cls");
    sortByDateIncomes();
    cout << "Incomes in previous month:  " << endl;
    cout << "--------------------------" << endl;
    viewSelectedIncomes(minDate, maxDate);
    sortByDateExpenses();
    cout << endl << "Expenses in previous month: " << endl;
    cout << "--------------------------" << endl;
    viewSelectedExpenses(minDate, maxDate);
    cout << "------------------------------" << endl;
    cout << "\t>>> Summary <<<  " << endl;
    cout << "------------------------------" << endl;
    if(sumOfIncomes == 0) {
        cout << "Sum of incomes: none" << endl;
    } else
        cout << "Sum of incomes:  " << "\t" << sumOfIncomes << endl;

    if(sumOfExpenses == 0) {
        cout << "Sum of expenses: none" << endl;
    } else
        cout << "Sum of expenses: \t" << sumOfExpenses << endl;
    cout << "----------------------------------" << endl;
    cout << "Balance of previous month: \t" << showpos << sumOfIncomes - sumOfExpenses << endl;
    cout << "----------------------------------" << endl;
    cout << noshowpos << endl;
    sumOfIncomes = 0;
    sumOfExpenses = 0;
    system("pause");
}

void ItemManager :: displayBalanceForSelectedPeriod() {
    system("cls");
    string firstDate = "", secondDate = "", stringDatewithoutDash = "";
    int minDate = 0, maxDate = 0, firstIntDateWithoutDash = 0, secondIntDateWithoutDash = 0;
    cout << fixed << setprecision(2);

    do {
        cout << "Enter first date in format YYYY-MM-DD: " << endl;
        firstDate = SupportMethods :: loadLine();
        if (dateManager.isDateCorrect(firstDate) == false) {
            cout << "Invalid date format." << endl;
        }
    } while (dateManager.isDateCorrect(firstDate) == false);
    stringDatewithoutDash = SupportMethods :: removeDashFromDate(firstDate);
    firstIntDateWithoutDash = SupportMethods :: convertStringToInt(stringDatewithoutDash);

    do {
        cout << "Enter last date in format YYYY-MM-DD: " << endl;
        secondDate = SupportMethods :: loadLine();
        if (dateManager.isDateCorrect(secondDate) == false) {
            cout << "Invalid date format." << endl;
        }
    } while (dateManager.isDateCorrect(secondDate) == false);
    stringDatewithoutDash = SupportMethods :: removeDashFromDate(secondDate);
    secondIntDateWithoutDash = SupportMethods :: convertStringToInt(stringDatewithoutDash);

    if (firstIntDateWithoutDash < secondIntDateWithoutDash) {
        minDate = firstIntDateWithoutDash;
        maxDate = secondIntDateWithoutDash;
    } else {
        minDate = secondIntDateWithoutDash;
        maxDate = firstIntDateWithoutDash;
    }
    system("cls");
    sortByDateIncomes();
    cout << "Incomes in selected time period:" << endl;
    cout << "--------------------------" << endl;
    viewSelectedIncomes(minDate, maxDate);
    sortByDateExpenses();
    cout << "Expenses in selected time period:" << endl;
    cout << "--------------------------" << endl;
    viewSelectedExpenses(minDate, maxDate);
    cout << "------------------------------" << endl;
    cout << "\t>>> Summary <<<  " << endl;
    cout << "------------------------------" << endl;
    if(sumOfIncomes == 0) {
        cout << "Sum of incomes: none" << endl;
    } else
        cout << "Sum of incomes:  " << "\t" << sumOfIncomes << endl;

    if(sumOfExpenses == 0) {
        cout << "Sum of expenses: none" << endl;
    } else
        cout << "Sum of expenses: \t" << sumOfExpenses << endl;
    cout << "----------------------------------" << endl;
    cout << "Balance of selected time period: \t" << showpos << sumOfIncomes - sumOfExpenses << endl;
    cout << "----------------------------------" << endl;
    cout << noshowpos << endl;
    sumOfIncomes = 0;
    sumOfExpenses = 0;
    system("pause");
}
