#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <windows.h>

#include "Date.h"

using namespace std;

class DateManager{

    time_t calculatedTime;
    struct tm * data;
    int year, month, day;

    const int MIN_VALID_YR = 2000; //2000-01-01

    bool isLeap(int year);

public:
    int getCurrentDate();
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();

    bool isDateCorrect (string date);
    bool isValidYear(int year);
    bool isValidMonth (int month);
    bool isValidDay (int dayConverted, int monthConverted, int yearConverted);
    bool isValidFormatDate(string date);

    void showDate(Date dateOb);

    //string getSelectedPeriod();
    //void sortByDateFromOldest(); // vector?

};

#endif
