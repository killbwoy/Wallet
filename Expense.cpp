#include "Expense.h"

void Expense :: setupDate (int newDate) {
    if (newDate >= 0) {
        this -> expenseDate = newDate;
    }
}
void Expense :: setupStringDate (string newDate) {
    expenseDate = newDate;
}
void Expense :: setupExpenseId (int newExpenseId) {
    if (newExpenseId >= 0) {
        this -> expenseId = newExpenseId;
    }
}
void Expense :: setupUserId (int newUserId) {
    if (newUserId >= 0) {
        this -> userId = newUserId;
    }
}
void Expense :: setupExpenseName (string newExpenseName) {
    this -> expenseName = newExpenseName;
}

void Expense :: setupExpenseAmount (float newExpenseAmount) {
    if(newExpenseAmount >= 0) {
        this -> expenseAmount = newExpenseAmount;
    }
}
int Expense :: getExpenseId() {
    return this -> expenseId;
}

string Expense :: getExpenseName() {
    return  this -> expenseName;
}

float Expense :: getExpenseAmount() {
    return this -> expenseAmount;
}

string Expense :: getExpenseDate() {
    return this -> expenseDate;
}

int Expense :: getUserId() {
    return this -> userId;
}

int Expense :: getIntDate() {
    return this -> intDate;
}
