#include "ItemManager.h"

void ItemManager :: addIncome() {
    Item income = provideIncomeDetails();
    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);
    cout << endl << "Income added to the file" << endl << endl;
    //showAllIncomes();
    system("pause");
}

int ItemManager :: getNewItemId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getItemId() + 1;
}

Item ItemManager :: provideIncomeDetails() {
    Item item;
    DateManager dateManager;
    string itemName, userSurname, otherDate, stringDatewithoutDash, currentStringDate, stringAmount;
    int currentDate, intDateWithoutDash;
    float amount;
    char choice;

    int itemId = getNewItemId();
    item.setupItemId(itemId);
    item.setupUserId(ID_LOGGED_USER);

    cout << "Do you want to add income with current date?" <<endl;
    cout << "If yes, please click 'y', if you want to chose other date, please click 'n': " << endl;
    choice = SupportMethods :: getCharacter();

    if (choice == 'y') {
        currentDate = dateManager.getCurrentDate();
        currentStringDate = SupportMethods :: convertIntToString(currentDate);
        currentStringDate = SupportMethods :: addDashToDate (currentStringDate);
        item.setupStringDate(currentStringDate);
    } else if (choice == 'n') {

        do {
            cout << "Provide date in format YYYY-MM-DD: ";
            otherDate = SupportMethods :: loadLine();
        } while (dateManager.isDateCorrect(otherDate) == false);
        stringDatewithoutDash = SupportMethods :: removeDashFromDate(otherDate);
        intDateWithoutDash = SupportMethods :: convertStringToInt (stringDatewithoutDash);
        item.setupStringDate(otherDate);
    }
    cout << "Provide income description: ";
    itemName = SupportMethods :: loadLine();
    item.setupItemName(itemName);
    cout << "Provide amount: ";
    amount = SupportMethods :: loadFloat();
    item.setupItemAmount(amount);

    return item;
}

void ItemManager :: showAllIncomes() {

    for (unsigned int i = 0; i < incomes.size(); i++) {
        cout << "Item Id: " << incomes[i].getItemId() << endl;
        cout << "User Id: " << incomes[i].getUserId() << endl;
        cout << "Item date: " << incomes[i].getItemDate() << endl;
        cout << "Item name: " << incomes[i].getItemName() << endl;
        cout << "Item amount: " << incomes[i].getItemAmount() << endl << endl;
    }
}
