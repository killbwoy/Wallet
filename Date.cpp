#include "Date.h"

string Date :: getDate() {
    return date;
}

string Date :: getYear() {
    return year;
}
string Date :: getMonth() {
    return month;
}
string Date :: getDay() {
    return day;
}

void Date :: setYear (string newYear) {
    year = newYear;
}
void Date :: setMonth (string newMonth) {
    month = newMonth;
}

void Date :: setDay (string newDay) {
    day = newDay;
}
