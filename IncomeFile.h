#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "XmlFile.h"
#include "Income.h"
#include "SupportMethods.h"

using namespace std;

class IncomeFile : public XmlFile {

    string fileNameWithIncomes;
    int lastIncomeId;

public:
    IncomeFile(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes){
        lastIncomeId = 0;
    };

    void addIncomeToFile(Income income);
    vector <Income> getIncomeFromFile(int ID_LOGGED_USER);
    int getLastIncomeId();
};

#endif
