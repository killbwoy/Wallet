#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "User.h"
#include "UserManager.h"
#include "DateManager.h"
#include "IncomeFile.h"
#include "Income.h"
#include "ExpenseFile.h"
#include "Expense.h"

using namespace std;

class ItemManager {

    IncomeFile incomeFile;
    ExpenseFile expenseFile;
    vector <Income> incomes;
    vector <Expense> expenses;
    const int ID_LOGGED_USER;

    Income provideIncomeDetails();
    Expense provideExpenseDetails();

    int getNewIncomeId();
    int getNewExpenseId();
    float sumOfIncomes;
    float sumOfExpenses;

    void viewIncome(vector <Income> :: iterator);
    void viewExpense(vector <Expense> :: iterator);
    void sortByDateIncomes();
    void sortByDateExpenses();
    void viewSelectedIncomes(int fromDate, int toDate);
    void viewSelectedExpenses(int FromDate, int ToDate);
    void sumUpIncomes(vector <Income> :: iterator);
    void sumUpExpenses(vector <Expense> :: iterator);

public:
    ItemManager (string fileNameWithIncomes, string fileNameWithExpenses, int idLoggedUser) : incomeFile (fileNameWithIncomes), expenseFile(fileNameWithExpenses), ID_LOGGED_USER(idLoggedUser) {
        idLoggedUser = 0;
        incomes = incomeFile.getIncomeFromFile(ID_LOGGED_USER);
        expenses = expenseFile.getExpenseFromFile(ID_LOGGED_USER);
        sumOfIncomes = 0;
        sumOfExpenses = 0;
    };
    DateManager dateManager;

    void addIncome();
    void addExpense();
    void showAllIncomes();
    void showAllExpenses();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    void displayBalanceForSelectedPeriod();
};

#endif
