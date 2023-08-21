#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "XmlFile.h"
#include "Item.h"
#include "SupportMethods.h"

using namespace std;

class IncomeFile : public XmlFile {

    string fileNameWithIncomes;
    int lastItemId;
    int idLoggedUser;
    vector <Item> incomes;

public:
    IncomeFile(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes){
     idLoggedUser = 0;
     //lastItemId = 0;
    };
    void addIncomeToFile(Item income);
    vector <Item> getIncomeFromFile(int idLoggedUser);
    Item changeIntDateFormat(Item income);
    //int getLastItemId();
};

#endif
