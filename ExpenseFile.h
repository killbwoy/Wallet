#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "XmlFile.h"
#include "Expense.h"
#include "SupportMethods.h"

using namespace std;

class ExpenseFile : public XmlFile {

    string fileNameWithExpenses;
    int lastExpenseId;

public:
    ExpenseFile(string fileNameWithExpenses) : XmlFile(fileNameWithExpenses){
        lastExpenseId = 0;
    };

    void addExpenseToFile(Expense expense);
    vector <Expense> getExpenseFromFile(int ID_LOGGED_USER);
    int getLastExpenseId();
};

#endif
