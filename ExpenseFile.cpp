#include "ExpenseFile.h"
#include "Markup.h"
#include "ItemManager.h"
#include "SupportMethods.h"


void ExpenseFile :: addExpenseToFile(Expense expense) {

    string amount = SupportMethods :: convertFloatToString (expense.getExpenseAmount());
    CMarkup xml;
    string fileNameWithExpenses = getFileName();
    bool fileExists = xml.Load(fileNameWithExpenses);
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(fileNameWithExpenses);
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem( "ExpenseId", expense.getExpenseId());
    xml.AddElem( "UserId", expense.getUserId() );
    xml.AddElem( "Date", expense.getExpenseDate() );
    xml.AddElem( "Item", expense.getExpenseName() );
    xml.AddElem( "Amount", amount );

    xml.OutOfElem();
    xml.OutOfElem();

    xml.Save(fileNameWithExpenses);
    lastExpenseId++;
}

vector <Expense> ExpenseFile :: getExpenseFromFile(int ID_LOGGED_USER) {
    int userId = 0;
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;
    string fileNameWithExpenses = getFileName();

    if (!xml.Load(fileNameWithExpenses)) {
        cout << "Error: Cant load XML file." << endl;
    }
    if (xml.Load(fileNameWithExpenses)) {
        xml.FindElem();
        xml.IntoElem();

        while ( xml.FindElem("Expense")) {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            lastExpenseId = atoi(xml.GetData().c_str());
            xml.FindElem("UserId");
            userId = atoi(xml.GetData().c_str());


            if (userId != ID_LOGGED_USER) {
                xml.OutOfElem();
                continue;
            }
            expense.setupUserId(userId);
            expense.setupExpenseId(lastExpenseId);

            xml.FindElem("Date");
            string expenseDate = xml.GetData();
            expense.setupStringDate(expenseDate);

            xml.FindElem("Item");
            string expenseName = xml.GetData();
            expense.setupExpenseName(expenseName);

            xml.FindElem("Amount");
            float expenseAmount = atoi(xml.GetData().c_str());
            expense.setupExpenseAmount(expenseAmount);
            xml.OutOfElem();

            expenses.push_back(expense);
        }
    }
    return expenses;
}

int ExpenseFile :: getLastExpenseId() {
         return lastExpenseId;
}

