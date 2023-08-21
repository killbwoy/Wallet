#include "Item.h"

void Item :: setupDate (int newDate) {
    if (newDate >= 0)
        itemDate = newDate;
}

void Item :: setupStringDate (string newDate) {
        itemDate = newDate;
}
void Item :: setupItemId (int newItemId) {
    if (newItemId >= 0)
        itemId = newItemId;
}

void Item :: setupUserId (int newUserID) {
    if (newUserID >= 0)
        userId = newUserID;
}

void Item :: setupItemName (string newItemName) {
        itemName = newItemName;
}

void Item :: setupItemAmount (float newItemAmount) {
        itemAmount = newItemAmount;
}
int Item :: getItemId() {
    return itemId;
}

string Item :: getItemName() {
    return itemName;
}

float Item :: getItemAmount() {
    return itemAmount;
}

string Item :: getItemDate() {
    return itemDate;
}

int Item :: getUserId() {
    return userId;
}

int Item :: getIntDate() {
    return intDate;
}
