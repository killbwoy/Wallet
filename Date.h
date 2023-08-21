#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date{

    string date;
    string day;
    string month;
    string year;

public:
    Date(string date = "")
    {
        this->date = date;
    }

    string getDate();
    string getYear();
    string getMonth();
    string getDay();
    void setYear(string newYear);
    void setMonth(string newMonth);
    void setDay(string newDay);
};

#endif
