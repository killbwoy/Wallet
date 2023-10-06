#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {
    int expenseId;
    int userId;
    string expenseDate;
    string expenseName;
    float expenseAmount;
    int intDate;

public:
    Expense(int expenseId = 0, int userId = 0, string expenseDate = "", string expenseName = "", float expenseAmount = 0.0) {
        this -> expenseId = expenseId;
        this -> userId = userId;
        this -> expenseDate = expenseDate;
        this -> expenseName = expenseName;
        this -> expenseAmount = expenseAmount;
    }

    void setupDate (int newDate);
    void setupStringDate (string newDate);
    void setupUserId (int newUserId);
    void setupExpenseId (int newExpenseId);
    void setupExpenseName(string newExpenseName);
    void setupExpenseAmount(float newExpenseAmount);

    int getExpenseId();
    int getUserId();
    string getExpenseName();
    float getExpenseAmount();
    string getExpenseDate();
    int getIntDate();

};

#endif
