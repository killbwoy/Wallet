#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {
    int itemId;
    int userId;
    string itemDate;
    string itemName;
    float itemAmount;
    int intDate;

public:
        Item(int itemId = 0, int userId = 0, string itemDate = "", string itemName = "", float itemAmount = 0.0)
    {
        this->itemId = itemId;
        this->userId = userId;
        this->itemDate = itemDate;
        this->itemName = itemName;
        this->itemAmount = itemAmount;
    }

    void setupDate (int newDate);
    void setupStringDate (string newDate);
    void setupUserId (int newUserId);
    void setupItemId (int newItemId);
    void setupItemName(string newItemName);
    void setupItemAmount(float newItemAmount);

    int getItemId();
    int getUserId();
    string getItemName();
    float getItemAmount();
    string getItemDate();
    int getIntDate();

};

#endif
