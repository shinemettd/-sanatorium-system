#include "LoginSystem.h"

//1
void showProcedureHistory(vector<Account>& data, int actualId, string strUserEnter) {
    if (data[actualId].client.visitHistory.size() % 10 == 2 || data[actualId].client.visitHistory.size() % 10 == 3  
        || data[actualId].client.visitHistory.size() % 10 == 4 && data[actualId].client.visitHistory.size() / 10 != 1) 
    {
        cout << "Вы посещали нас " << data[actualId].client.visitHistory.size() << " раза: " << endl << endl;//склонение слова раз
    }
    else 
    {
        cout << "Вы посещали нас " << data[actualId].client.visitHistory.size() << " раз: " << endl << endl;
    }
    for (int i = 0; i < data[actualId].client.visitHistory.size(); i++) {
        cout << data[actualId].client.visitHistory[i] << endl;
    }
    goBack(strUserEnter);
}

//2
void showLastProcedureDate(vector<Account>& data, int actualId, string strUserEnter){
    cout << "Вы были последний раз на процедуре: " << endl << endl << data[actualId].client.visitHistory[data[actualId].client.visitHistory.size() - 1] << endl;
    goBack(strUserEnter);
}

//3
void showPayList(vector<Account>& data, int actualId, string strUserEnter){
    cout << "Ваша история оплат: " << endl << endl;
    for (int i = 0; i < data[actualId].client.visitHistory.size(); i++) {
        cout << data[actualId].client.payingHistory[i] << "$ за " << data[actualId].client.visitHistory[i] << endl;
    }
    goBack(strUserEnter);
}

//4
void showSchedule(vector<Account>& data, int actualId, string strUserEnter) {
    if (data[actualId].client.beingTreated == false) {
        cout << "Вы уже прошли курс лечения!" << endl;
        goBack(strUserEnter);
    }
    else {
        int countProceduresDone = 0;
        for (int i = 1; i < data[actualId].client.visitHistory.size(); i++) {
            if (data[actualId].client.visitHistory[i] == data[actualId].client.diseaseDate[i-1]) {
                countProceduresDone++;
            }
        }
        cout << "Ваше расписание на будущие процедуры: " << endl << endl;
        for (int i = countProceduresDone; i < data[actualId].client.diseaseDate.size(); i++) {
            cout << data[actualId].client.diseaseDate[i] << endl << endl;
        }
        goBack(strUserEnter);
    }
}

//5
void showPatientInfo(vector<Account>& data, int actualId, string strUserEnter) {
    cout << data[actualId].name << " " << data[actualId].surname << endl << "Рост: " << data[actualId].height << " см" << endl 
         << "Вес: " << data[actualId].weight << " кг" << endl << "Дата рождения: " << data[actualId].birthday << endl 
         << "Группа крови: " << data[actualId].client.bloodType << endl;
    goBack(strUserEnter);
}

//6
void showSanatoryDay (vector<Account>& data, int actualId, string strUserEnter) {
    if (data[actualId].client.beingTreated == true) {
        if (data[actualId].client.stayDay % 10 == 2 || data[actualId].client.stayDay % 10 == 3  
        || data[actualId].client.stayDay % 10 == 4 && data[actualId].client.stayDay / 10 != 1) 
        {
            cout << "Вы пребываете в нашем санатории уже " << data[actualId].client.stayDay << " дня!" << endl;
        }
        else if (data[actualId].client.stayDay % 10 == 1) {
            cout << "Вы пребываете в нашем санатории уже " << data[actualId].client.stayDay << " день!" << endl;
        }
        else 
        {
            cout << "Вы пребываете в нашем санатории уже " << data[actualId].client.stayDay << " дней" << endl;
        }
        goBack(strUserEnter);
    }
    else {
        if (data[actualId].client.stayDay % 10 == 2 || data[actualId].client.stayDay % 10 == 3  
        || data[actualId].client.stayDay % 10 == 4 && data[actualId].client.stayDay / 10 != 1) 
        {
            cout << "Вы пробыли у нас " << data[actualId].client.stayDay << " дня, однако на данный момент вы уже окончили лечение!" << endl;
        }
        else if (data[actualId].client.stayDay % 10 == 1) {
            cout << "Вы пробыли у нас " << data[actualId].client.stayDay << " день, однако на данный момент вы уже окончили лечение!" << endl;
        }
        else 
        {
            cout << "Вы пробыли у нас " << data[actualId].client.stayDay << " дней, однако на данный момент вы уже окончили лечение!" << endl;
        }
        goBack(strUserEnter);
    }
}


void patientMenu(bool programStatus, vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount, 
                string strUserEnter, int personalCount, vector<Diseases> &diseases, int actualId, string todaysDate) {
    
    while(programStatus) {
        system("cls");

        strUserEnter = "null";
        userEnter = 0;

        cout << "Пожалуйста наберите номер меню для работы с программой: " << endl
        << "1. Показать историю посещений процедур" << endl 
        << "2. Показать последнюю дату посещения процедур" << endl 
        << "3. Показать историю оплаты процедур" << endl 
        << "4. Показать расписание к процедурам" << endl
        << "5. Показать мою информацию " << endl 
        << "6. Показать мой день проживания в Санатории" << endl 
        << "7. Выход"; enterLine();
        
        cin >> userEnter; 

        if ((userEnter >= 1) && (userEnter <= 7)) {
            userEnter = userEnter;
        }
        else {
            userEnter = 7;
        }

        switch(userEnter) {
            case 1: 
            {
                system("cls");
                showProcedureHistory(data, actualId, strUserEnter);
                break;
            }
            case 2:
            {
                system("cls");
                showLastProcedureDate(data, actualId, strUserEnter);
                break;
            }
            case 3:
            {
                system("cls");
                showPayList(data, actualId, strUserEnter);
                break;
            }
            case 4:
            {
                system("cls");
                showSchedule(data, actualId, strUserEnter);
                break;
            }
            case 5:  
            { 
                system("cls"); 
                showPatientInfo(data, actualId, strUserEnter);
                break;
            }
            case 6:  
            { 
                system("cls"); 
                showSanatoryDay(data, actualId, strUserEnter);
                break;
            }
            case 7:
            {
                programStatus = false;
                break;
            }
            default:
            {
                cout << "Error";
            }
        }
    }
}