#include "Income.h"
#include "SupportMethods.h"

void Income :: setupDate (int newDate) {
    if (newDate >= 0) {
        this -> incomeDate = newDate;
    }
}
void Income :: setupStringDate (string newDate) {
    incomeDate = newDate;
}
void Income :: setupIncomeId (int newIncomeId) {
    if (newIncomeId >= 0) {
        this -> incomeId = newIncomeId;
    }
}
void Income :: setupUserId (int newUserId) {
    if (newUserId >= 0) {
        this -> userId = newUserId;
    }
}
void Income :: setupIncomeName (string newIncomeName) {
    this -> incomeName = newIncomeName;
}

void Income :: setupIncomeAmount (float newIncomeAmount) {
    if(newIncomeAmount >= 0) {
        this -> incomeAmount = newIncomeAmount;
    }
}
int Income :: getIncomeId() {
    return this -> incomeId;
}

string Income :: getIncomeName() {
    return  this -> incomeName;
}

float Income :: getIncomeAmount() {
    return this -> incomeAmount;
}

string Income :: getIncomeDate() {
    return this -> incomeDate;
}

int Income :: getUserId() {
    return this -> userId;
}

int Income :: getIntDate() {
    return SupportMethods :: convertStringToInt (SupportMethods :: removeDashFromDate(incomeDate));
}
