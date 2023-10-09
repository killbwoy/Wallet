#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income {
    int incomeId;
    int userId;
    string incomeDate;
    string incomeName;
    float incomeAmount;
    //int intDate;

public:
    Income(int incomeId = 0, int userId = 0, string incomeDate = "", string incomeName = "", float incomeAmount = 0.0) {
        this -> incomeId = incomeId;
        this -> userId = userId;
        this -> incomeDate = incomeDate;
        this -> incomeName = incomeName;
        this -> incomeAmount = incomeAmount;
    }

    void setupDate (int newDate);
    void setupStringDate (string newDate);
    void setupUserId (int newUserId);
    void setupIncomeId (int newIncomeId);
    void setupIncomeName(string newIncomemName);
    void setupIncomeAmount(float newIncomeAmount);

    int getIncomeId();
    int getUserId();
    string getIncomeName();
    float getIncomeAmount();
    string getIncomeDate();
    int getIntDate();

};

#endif
