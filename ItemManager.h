#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <iostream>
#include <vector>
#include <string>

#include "Item.h"
#include "User.h"
#include "UserManager.h"
#include "DateManager.h"
#include "IncomeFile.h"

using namespace std;

class ItemManager : public Item {

    const int ID_LOGGED_USER;
    //vector <Item> items;
    //vector <Item> expenses;
    vector <Item> incomes;
    IncomeFile incomeFile;
    //int idLoggedUser;

    Item provideIncomeDetails();
    int getNewItemId();

public:
    ItemManager (string fileNameWithIncomes, int idLoggedUser) : incomeFile (fileNameWithIncomes),ID_LOGGED_USER(idLoggedUser){// W nawiasach po nazwie konstruktora sa podane argumenty, ktore konstruktor przyjmuje przy tworzeniu obiektu. Lista inicjalizacyjna sluzy do inicjalizacji pol skladowych klasy (czyli zmiennych lub obiektów) w momencie tworzenia obiektu.

    incomes = incomeFile.getIncomeFromFile(ID_LOGGED_USER); // Funkcja pobiera dane o wplywach z pliku, przy uzyciu identyfikatora zalogowanego uzytkownika (ID_LOGGED_USER), i przypisuje je do zmiennej incomes
    };
    void addIncome();
    bool provideDate();
    void showAllIncomes();

};
#endif
