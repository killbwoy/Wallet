#include "IncomeFile.h"
#include "Markup.h"
#include "ItemManager.h"
#include "SupportMethods.h"


void IncomeFile :: addIncomeToFile(Income income) {

    string amount = SupportMethods :: convertFloatToString (income.getIncomeAmount());
    CMarkup xml;
    string fileNameWithIncomes = getFileName();
    bool fileExists = xml.Load(fileNameWithIncomes);
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(fileNameWithIncomes);
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem( "IncomeId", income.getIncomeId());
    xml.AddElem( "UserId", income.getUserId() );
    xml.AddElem( "Date", income.getIncomeDate() );
    xml.AddElem( "Item", income.getIncomeName() );
    xml.AddElem( "Amount", amount );

    xml.OutOfElem();
    xml.OutOfElem();

    xml.Save(fileNameWithIncomes);
    lastIncomeId++;
}

vector <Income> IncomeFile :: getIncomeFromFile(int ID_LOGGED_USER) {
    int userId = 0;
    Income income;
    vector <Income> incomes;
    CMarkup xml;
    string fileNameWithIncomes = getFileName();

    if (!xml.Load(fileNameWithIncomes)) {
        cout << "Error: Cant load XML file." << endl;
    }
    if (xml.Load(fileNameWithIncomes)) {
        xml.FindElem();
        xml.IntoElem();

        while ( xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            lastIncomeId = atoi(xml.GetData().c_str());
            xml.FindElem("UserId");
            userId = atoi(xml.GetData().c_str());


            if (userId != ID_LOGGED_USER) {
                xml.OutOfElem();
                continue;
            }
            income.setupUserId(userId);
            income.setupIncomeId(lastIncomeId);

            xml.FindElem("Date");
            string incomeDate = xml.GetData();
            income.setupStringDate(incomeDate);

            xml.FindElem("Item");
            string incomeName = xml.GetData();
            income.setupIncomeName(incomeName);

            xml.FindElem("Amount");
            float incomeAmount = atoi(xml.GetData().c_str());
            income.setupIncomeAmount(incomeAmount);
            xml.OutOfElem();

            incomes.push_back(income);
        }
    }
    return incomes;
}

int IncomeFile :: getLastIncomeId() {
         return lastIncomeId;
}

