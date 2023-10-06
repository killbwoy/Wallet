#include "DateManager.h"

int DateManager :: getCurrentDate() {
    int currentDate = 0;
    year = getCurrentYear();
    currentDate = (year * 10000);
    month = getCurrentMonth();
    currentDate += (month * 100);
    day = getCurrentDay();
    currentDate += day;

    return currentDate;
}

int DateManager :: getCurrentYear() {
    time(&calculatedTime); //Wywolana jest funkcja time(&calculatedTime), ktora pobiera aktualny czas w postaci liczby sekund od pewnej stalej daty (czasu Unix).Zmienna calculatedTime przechowuje wynik tej funkcji.
    data = localtime(&calculatedTime); //funkcja localtime(&calculatedTime) przeksztalca wartosc liczbowa reprezentujaca czas w strukture tm
    year = data -> tm_year+1900; //odnosimy sie do pola tm_year struktury data, ktore przechowuje liczbe lat od 1900 roku. Dodajac 1900 do tej liczby otrzymujemy wlasciwy rok.

    return year;
}

int DateManager :: getCurrentMonth() {
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    month = data -> tm_mon+1; //odnosimy sie do pola tm_mon struktury data, ktore przechowuje numer miesiaca od 0 (styczen) do 11 (grudzien). Dodajac 1 do tej liczby otrzymujemy wlasciwy numer miesiaca (1 - styczen, 2 - luty, ...)

    return month;
}

int DateManager :: getCurrentDay() {
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    day = data -> tm_mday;

    return day;
}

bool DateManager :: isDateCorrect(string date) {

    int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
    int month = (date[5]-'0')*10 + (date[6]-'0');
    int day = (date[8]-'0')*10 + (date[9]-'0');

    if (!isValidFormatDate(date)) {
        return false;
    }
    if (!isValidYear (year)) {
        return false;
    }
    if (!isValidMonth(month) || month > getCurrentMonth()) {
        return false;
    }
    if (day >= 1 && day <= 31) {
        if (isValidDay(day, month, year) == true) {
            if (isFutureDate(date)) {
                return false;
            }
            return true;
        } else {
            return false;
        }
    }

    return false;
}

bool DateManager :: isValidYear (int year) {

    if (year > getCurrentYear() || year < MIN_VALID_YR) {
        return false;
    }
    return true;
}

bool DateManager :: isValidMonth(int month) {
    if (month < 1 || month > 12) {
        return false;
    }
    return true;
}

bool DateManager :: isValidDay (int day, int month, int year) {

    if (month == 2) {
        if ((isLeap(year) == true) && (day == 29)) {
            return true;
        } else if (day >= 1 && day <= 28) {
            return true;
        } else if (day < 1 || day > 29) {
            return false;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day >= 1 && day <= 30) {
            return true;
        } else return false;
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day >= 1 && day <= 31) {
            return true;
        } else return false;
    }
    return false;
}
bool DateManager :: isFutureDate(string stringDate) {
    int date = SupportMethods :: convertStringToInt (SupportMethods :: removeDashFromDate(stringDate));
    return date > getCurrentDate();
}

bool DateManager :: isValidFormatDate (string date) {

    if ((date.size() != 10) || (date[4] != '-') || (date[7] != '-')) {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (!isdigit(date[i])) {
            return false;
        }
    }
    return true;
}
bool DateManager :: isLeap(int year) {
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return true;
    } else return false;
}
void DateManager :: showDate(Date dateOb) {
    cout << endl << "Year: " << dateOb.getYear() << endl;
    cout << "Month: " << dateOb.getMonth() << endl;
    cout << "Day: " << dateOb.getDay() << endl;
}
