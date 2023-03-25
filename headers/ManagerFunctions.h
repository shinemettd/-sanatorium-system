#pragma once
#include "LoginSystem.h"

//first function of manager menu
void showClientList(vector<Account>& data, string strUserEnter, int peopleCount) {
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].type == "patient" && data[i].client.beingTreated == true){
            cout << data[i].name << " " 
                << data[i].surname << endl
                << "Рост: " << data[i].height << " см " << endl
                << "Вес: " << data[i].weight << " кг " << endl
                << "Дата рождения: "<< data[i].birthday << endl << endl;
        }
    }
    goBack(strUserEnter);
}

//second function of manager menu
void showClientCount(vector<Account>& data, string strUserEnter, int peopleCount, int &beingTreatedCount) {
    beingTreatedCount = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i].type == "patient" && data[i].client.beingTreated == true) {
            beingTreatedCount++;
        }
    }
    cout << "Всего на данный момент лечящихся: " << beingTreatedCount << endl;
    goBack(strUserEnter);
}

void findWithSurname(vector<Account>& data, string &strUserEnter, int peopleCount) {
    string tempUserEnter;
    int successSurnameFind = 0;
        cin >> tempUserEnter;
        if (tempUserEnter == "0") {
            strUserEnter = "0";
            return ;
        }
        for (int i = 0; i < peopleCount; i++) {
            if (strUserEnter == data[i].name && tempUserEnter == data[i].surname) {
                successSurnameFind++;
                system("cls");
                cout << data[i].name << " " << data[i].surname << endl
                << "Рост: " << data[i].height << " см " << endl
                << "Вес: " << data[i].weight << " кг " << endl
                << "Дата рождения: "<< data[i].birthday << endl << endl
                << "Список болезней: " << endl;
            for (int j = 0; j < data[i].client.diseaseName.size(); j++) {
                cout << data[i].client.diseaseName[j] << endl;
            }
            break;
            }
        }
        if (successSurnameFind == 0) {
            system("cls");
            cout << "Неправильно введена фамилия!" << endl << "Попробуйте ввести фамилию еще раз: " << endl;
        }
        else {
            cout << endl << "Введите 0, чтобы вернуться назад: "; enterLine();
            while (strUserEnter!="0") {
                cin >> strUserEnter;
                if (strUserEnter != "0") {
                    strUserEnter = "0";
                    return ;
                }
            }
        }
}

//function for third function, that allow run recursion
void findFunction (vector<Account>& data, string &strUserEnter, int peopleCount) {
    int successFind = 0;
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].name == strUserEnter) {
            successFind++;
        }
    }
    if (successFind == 0) {
        cout << "Данный пользователь не найден! Попробуйте еще раз, или напишите 0, чтобы выйти в меню: "; enterLine();
    }
    else if (successFind == 1) {
        for (int i = 0; i < peopleCount; i++) {
            if (data[i].name == strUserEnter) {
                cout << data[i].name << " " << data[i].surname << endl
                << "Рост: " << data[i].height << " см " << endl
                << "Вес: " << data[i].weight << " кг " << endl
                << "Дата рождения: "<< data[i].birthday << endl << endl
                << "Список болезней: " << endl;
                for (int j = 0; j < data[i].client.diseaseName.size(); j++) {
                    cout << data[i].client.diseaseName[j] << endl;
                }
            }
        }
        cout << endl << "Чтобы узнать информацию о другом пользователе, напишите его имя. " << endl 
        << "Если же вы хотите вернуться в главное меню, введите 0: "; enterLine();
    }
    else  {
        cout << "По запросу имени " << strUserEnter << " было найдено " << successFind << " пользователя: " << endl;
        for (int i = 0; i < peopleCount; i++) {
            if (strUserEnter == data[i].name) {
                cout << data[i].name << " " << data[i].surname << endl;
            }
        } 
        cout << endl << "Введите фамилию нужного вам пользователя: "; enterLine();
        while (strUserEnter != "0") { 
            findWithSurname(data, strUserEnter, peopleCount);
        }
        return;
    }
    cin >> strUserEnter;
    system("cls");
}

//third function of manager menu
void findClient(vector<Account>& data, string strUserEnter, int peopleCount) {
    cout << "Чтобы узнать всю информацию о пользователе, введите его имя: "; enterLine();
    cin >> strUserEnter;
    system("cls");
    findFunction(data, strUserEnter, peopleCount);
    if (strUserEnter != "0") {
        while (strUserEnter != "0") {
            findFunction(data, strUserEnter, peopleCount);
        }
    }
}
//fourth function of manager menu
void showAllDiseases (vector <Diseases> &diseases, string &strUserEnter) {
    for (int i = 0; i < diseases.size(); i++) {
        cout << diseases[i].diseasesName << endl << "Цена: " << diseases[i].diseasesPrice << "$" << endl << "Время назначения: " << diseases[i].diseasesTime << endl << endl;
    }
    goBack(strUserEnter);
}

//function for fifth function, that allow run recursion
void findDisease(vector <Diseases> &diseases, string &strUserEnter, int peopleCount) { 
    int tempId; 
    int tempInput; 
    bool successFind = false; 
    for (int i = 0; i < diseases.size(); i++) { 
        if (strUserEnter == diseases[i].diseasesName)  { 
            tempId = i; 
            successFind = true; 
            system("cls"); 
            break; 
        } 
    } 
    if (successFind == true) { 
        cout << "Нынешняя цена процедуры " << diseases[tempId].diseasesName << " - " << diseases[tempId].diseasesPrice << "$" << endl << "Введите новую цену: " << endl 
        << "Если же вы хотите вернуться в главное меню, введите 0: "; enterLine();
        cin >> tempInput; 
        if (tempInput <= 0) { 
            strUserEnter = "0";  
            system("cls"); 
        } 
        else { 
            diseases[tempId].diseasesPrice = tempInput; 
            system("cls");
            cout << "Новая цена процедуры " << diseases[tempId].diseasesName << ": " << tempInput << "$" << endl 
            << "Если вы хотите изменить цену для другой процедуры, введите ее название: " << endl << "Или напишите 0 чтобы вернуться в главное меню: "; enterLine();
            cin >> strUserEnter;
            system("cls");
        } 
    } 
    else { 
        cout << "Данная процедура не найдена, попробуйте еще раз: "; enterLine();
        cin >> strUserEnter;
        system("cls");
    } 
} 
 
//fifth function of manager menu
void changePrice(vector <Diseases> &diseases, string &strUserEnter, int peopleCount){ 
    cout << "Введите название процедуры, которой хотите изменить цену: " << endl << "Если же вы хотите вернуться в главное меню, введите 0: "; enterLine();
    cin >> strUserEnter; 
    system("cls"); 
    while (strUserEnter!="0") { 
        findDisease(diseases, strUserEnter, peopleCount); 
    } 
}
//function for sixth function of manager menu 1
void changeProcedureTime (vector <Diseases> &diseases, string &strUserEnter, int peopleCount) {
    int tempId; 
    bool successFind = false;
    system("cls");
    for (int i = 0; i < peopleCount; i++) {
        if (strUserEnter ==  diseases[i].diseasesName) {
            successFind = true;
            tempId = i;
            break;
        }
    }
    if (successFind == true) {
        cout << "Введите новое время в формате ЧЧ:ММ для процедуры " << diseases[tempId].diseasesName << ": " << endl << "Если вы передумали, напишите 0:"; enterLine();
        cin >> strUserEnter;
        if (strUserEnter != "0") {
            diseases[tempId].diseasesTime = strUserEnter;
            system("cls");
            cout << "Новое время для процедуры было успешно установлено!" << endl << "Введите 0, если хотите вернуться в главное меню" << endl 
            << "Введите 1, если вы хотите сменить время другой процедуре: "; enterLine();
            while (strUserEnter != "0" || strUserEnter != "1") {
                cin >> strUserEnter;
                if (strUserEnter == "1") {
                    strUserEnter = "null";
                    return ;
                }
                else if (strUserEnter == "0") {
                    return ;
                }
                else {
                    cout << "Неверно введено число! Попробуйте еще раз: "; enterLine();
                }
            }
        }
        else {
            strUserEnter = "0";
            system("cls");
        }
    }
    else {
        if (strUserEnter == "null") {
            cin >> strUserEnter;
            system("cls");
        }
        else {
            cout << "Данная процедура не была найдена! Попробуйте еще раз: " << endl << "Или введите 0, чтобы вернуться в главное меню"; enterLine();
            cin >> strUserEnter;
            system("cls");
        }
    }
}

//function for sixth function of manager menu 2
void changeProcedureName(vector <Diseases> &diseases, string &strUserEnter, int peopleCount) {
    int tempId; 
    bool successFind = false;
    system("cls");
    for (int i = 0; i < peopleCount; i++) {
        if (strUserEnter ==  diseases[i].diseasesName) {
            successFind = true;
            tempId = i;
            break;
        }
    }
    if (successFind == true) {
        cout << "Введите новое название для процедуры " << diseases[tempId].diseasesName << ": " << endl << "Если вы передумали, напишите 0:"; enterLine();
        cin >> strUserEnter;
        if (strUserEnter != "0") {
            diseases[tempId].diseasesName = strUserEnter;
            system("cls");
            cout << "Новое название процедуры было успешно установлено!" << endl << "Введите 0, если хотите вернуться в главное меню" << endl 
            << "Введите 1, если вы хотите сменить название другой процедуры: "; enterLine();
            while (strUserEnter != "0" || strUserEnter != "1") {
                cin >> strUserEnter;
                if (strUserEnter == "0") {
                    return ;
                }
                else if (strUserEnter == "1") {
                    strUserEnter = "null";
                    return ;
                }
                else {
                    cout << "Неверно введено число! Попробуйте еще раз: "; enterLine();
                }
            }
        }
        else {
            strUserEnter = "0";
            system("cls");
        }
    }
    else {
        if (strUserEnter == "null") {
            cin >> strUserEnter;
            system("cls");
        }
        else {
            cout << "Данная процедура не была найдена! Попробуйте еще раз: " << endl << "Или введите 0, чтобы вернуться в главное меню"; enterLine();
            cin >> strUserEnter;
            system("cls");
        }
    }
}

//main sixth function of manager menu
void changeTimeOrProcedureName(vector <Diseases> &diseases, string &strUserEnter, int peopleCount){
    while (strUserEnter != "0") {  
        cin >> strUserEnter;
        if (strUserEnter == "1") {
            system("cls");
            cout << "Введите название процедуры: "; enterLine();
            cin >> strUserEnter;
            system("cls");
            while (strUserEnter != "0") {
                changeProcedureTime(diseases, strUserEnter, peopleCount);
            }
        }
        else if (strUserEnter == "2") {
            system("cls");
            cout << "Введите название процедуры: "; enterLine();
            cin >> strUserEnter;
            system("cls");
            while (strUserEnter != "0") {
                changeProcedureName(diseases, strUserEnter, peopleCount);
            }
        }
        else {
            cout << "Неверно введено число, попробуйте еще раз: "; enterLine();
        }
    }
}

//seventh function of manager menu
void showMaxPersonVisits(vector<Account>& data, int &userEnter, int peopleCount, int personalCount){
    int maxVisits = data[personalCount].client.visitHistory.size();
    int tempInt;
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].type == "patient" && maxVisits < data[i].client.visitHistory.size()) {
            maxVisits = data[i].client.visitHistory.size();
            tempInt = i;
        }
    }
    if (userEnter != 0) {
        while (userEnter != 0) {
            system("cls");
            cout << "Наибольшее количество посещений у пользователя " << data[tempInt].name  << " " << data[tempInt].surname << endl << "Всего посещений: " << maxVisits << endl << endl
                << "Чтобы вернуться в главное меню, напишите 0: " ; enterLine();
            cin >> userEnter;
            system ("cls");
        } 
    }
}

//eighth function of manager menu
void showMinPersonVisits(vector<Account>& data, int &userEnter, int peopleCount, int personalCount){
    int minVisits = data[personalCount].client.visitHistory.size();
    int tempInt;
    for (int i = 7; i < peopleCount; i++) {
        if (data[i].type == "patient" && minVisits > data[i].client.visitHistory.size()) {
            minVisits = data[i].client.visitHistory.size();
            tempInt = i;
        }
    }
    if (userEnter != 0) {
        while (userEnter != 0) {
            system("cls");
            cout << "Наименьшее количество посещений у пользователя " << data[tempInt].name  << " " << data[tempInt].surname << endl << "Всего посещений: " << minVisits << endl << endl
                << "Чтобы вернуться в главное меню, напишите 0: "; enterLine();
            cin >> userEnter;
            system ("cls");
        } 
    }
}

//main manager menu
void managerMenu(bool programStatus, vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount, string strUserEnter, int personalCount, vector<Diseases> &diseases) {
    while(programStatus) {
        system("cls");

        strUserEnter = "null";
        userEnter = 0;

        cout << "Пожалуйста наберите номер меню для работы с программой: " << endl
        << "1. Показать список посетителей" << endl //(Показывает список посетителей, которые получают на данный момент свое лечение)
        << "2. Показать количество посетителей" << endl 
        << "3. Поиск посетителя" << endl 
        << "4. Показать список процедур" << endl
        << "5. Изменить цену для процедур" << endl 
        << "6. Изменить время/название процедур" << endl 
        << "7. Показать посетителя с максимальным количеством посещений" << endl
        << "8. Показать посетителя с минимальным количеством посещений" << endl 
        << "9. Выход"; enterLine();
        
        cin >> userEnter; 

        if ((userEnter >= 1) && (userEnter <= 9)) {
            userEnter = userEnter;
        }
        else {
            userEnter = 9;
        }

        switch(userEnter) {
            case 1: 
            {
                system("cls");
                showClientList(data, strUserEnter, peopleCount);
                break;
            }
            case 2:
            {
                system("cls");
                showClientCount(data, strUserEnter, peopleCount, beingTreatedCount);
                break;
            }
            case 3:
            {
                system("cls");
                findClient(data, strUserEnter, peopleCount); 
                break;
            }
            case 4:
            {
                system("cls");
                showAllDiseases (diseases, strUserEnter);
                break;
            }
            case 5:  
            { 
                system("cls"); 
                changePrice(diseases, strUserEnter, peopleCount); 
                break;
            }
            case 6:  
            { 
                system("cls"); 
                cout << "Введите 1, чтобы изменить время процедуры:" << endl << "Введите 2, чтобы изменить название процедуры: " << endl 
                << "Введите 0, чтобы вернуться в главное меню: "; enterLine();
                changeTimeOrProcedureName(diseases, strUserEnter, peopleCount); 
                break;
            }
            case 7:
            {
                system("cls");
                showMaxPersonVisits(data, userEnter, peopleCount, personalCount);
                break;
            }
            case 8:
            {
                system("cls");
                showMinPersonVisits(data, userEnter, peopleCount, personalCount);
                break;                
            }
            case 9:
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