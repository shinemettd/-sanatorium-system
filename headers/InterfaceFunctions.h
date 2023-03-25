#pragma once
#include "Libraries.h"

void enterLine() {
    cout << endl << endl << ">> ";
}

void goBack(string &strUserEnter) {
    cout << endl << "Чтобы вернуться назад, напишите 0: "; enterLine();
    cin >> strUserEnter;
    while (strUserEnter != "0") {
        system("cls");
        cout << "Чтобы вернуться назад, напишите 0: "; enterLine();
        cin >> strUserEnter;
    }
}

string determinateTodaysDate(string &todaysDate) {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    if (month < 10) { 
        todaysDate = to_string(day) + ".0" + to_string(month) + "." + to_string(year);
    }
    else {
        todaysDate = to_string(day) + "." + to_string(month) + "." + to_string(year);
    }

    return todaysDate;
}

bool isDateRight(string strUserEnter, string todaysDate) {
    if (strUserEnter.size() == 10) {
        tm tmUserEnter = {};
        istringstream ssUserEnter(todaysDate);
        ssUserEnter >> get_time(&tmUserEnter, "%d.%m.%Y");

        tm tmDate = {};
        istringstream ssDate(strUserEnter);
        ssDate >> get_time(&tmDate, "%d.%m.%Y");

        time_t timeUserEnter = mktime(&tmUserEnter);
        time_t timeDate = mktime(&tmDate);

        double diff = difftime(timeUserEnter, timeDate);
        double years = diff / 31536000;
        cout << years << "---";
        if (years >= 18) {
            return true;
        }
        else {
            cout << "Пользователю должно быть больше 18 лет! Попробуйте еще раз: "; enterLine();
            return false;
        }
    }
    else {
        cout << "Введена неверная дата, попробуйте еще раз: "; enterLine();
    }
    return false;
}