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
    const int ID_LOGGED_USER;       //Wartosc tej stalej jest inicjalizowana przy tworzeniu obiektu klasy ItemManager poprzez liste inicjalizacyjna konstruktora

    Income provideIncomeDetails();    //Metoda zwraca obiekt typu Income reprezentujacy szczegoly dotyczace przychodu
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
    ItemManager (string fileNameWithIncomes, string fileNameWithExpenses, int idLoggedUser) : incomeFile (fileNameWithIncomes), expenseFile(fileNameWithExpenses), ID_LOGGED_USER(idLoggedUser) { // W nawiasach po nazwie konstruktora sa podane argumenty, ktore konstruktor przyjmuje przy tworzeniu obiektu. Lista inicjalizacyjna sluzy do inicjalizacji pol skladowych klasy (czyli zmiennych lub obiektów) w momencie tworzenia obiektu.
        idLoggedUser = 0;
        incomes = incomeFile.getIncomeFromFile(ID_LOGGED_USER); // Funkcja pobiera dane o wplywach z pliku, przy uzyciu identyfikatora zalogowanego uzytkownika (ID_LOGGED_USER), i przypisuje je do zmiennej incomes
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
