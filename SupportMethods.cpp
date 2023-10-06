#include "SupportMethods.h"


char SupportMethods :: getCharacter()
{
    string providedCharacter = "";
    char character  = {0};

    while (true)
    {
        getline(cin, providedCharacter);

        if (providedCharacter.length() == 1)
        {
            character = providedCharacter[0];
            break;
        }
        cout << "This is not one character. Please enter again." << endl;
    }
    return character;
}

string SupportMethods :: changeFirstLetterToCapitalAndOtherToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string SupportMethods :: getNumber(string text, int characterPosition)
{
    string number = "";
    while(isdigit(text[characterPosition]) == true)
    {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}

float SupportMethods :: loadFloat()
{
    string providedData = "";
    float number;

    while (true)
    {
        cin.clear();
        getline(cin, providedData);
        providedData = changeCommaToDot(providedData);
        stringstream myStream(providedData);
        if (myStream >> number)
            break;
        cout << "This is not the amount. Please add again. " << endl;
    }
    return number;
}

int SupportMethods :: convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string SupportMethods :: convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string SupportMethods :: loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string SupportMethods :: removeDashFromDate(string date) {

    string stringDatewithoutDash;

    for (unsigned int i = 0 ; i <= date.length(); i++) {
        if (date[i] != '-') {
            stringDatewithoutDash += date[i];
        }
    }
    return stringDatewithoutDash;
}

string SupportMethods :: addDashToDate(string date) {

    string stringDateWithDash;
    stringDateWithDash = date.insert (4,1,'-');
    stringDateWithDash = stringDateWithDash.insert (7,1,'-');
    cout << "Today date is: " << stringDateWithDash << endl;

    return stringDateWithDash;
}

string SupportMethods :: convertFloatToString( float amount )
{
    std::stringstream FloatToStr;
    std::string str;

    FloatToStr << amount;
    FloatToStr >> str;
    FloatToStr.clear();

    return str;
}

string SupportMethods :: changeCommaToDot(string input) {
    size_t foundComma = input.find(",");
    if(foundComma != string::npos) {
        input.replace(foundComma, 1, ".");
    }
    return input;
}
