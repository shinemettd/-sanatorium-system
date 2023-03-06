#include "loginsystem.h"

//first function of manager menu
void showClientList(vector<Account>& data, int userEnter, int peopleCount) {
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].type == "patient" && data[i].client.beingTreated == true){
            cout << data[i].name << " " 
                << data[i].surname << endl
                << "Рост: " << data[i].height << " см " << endl
                << "Вес: " << data[i].weight << " кг " << endl
                << "Дата рождения: "<< data[i].birthday << endl << endl;
        }
    }
    cout << "Напишите 0 чтобы вернуться назад: " << endl << endl << ">> ";
    cin >> userEnter;
    if (userEnter == 0) {
        system("cls");
    }
    else {
        cout << "Чтобы вернуться назад, введите 0: " << endl << endl << ">> ";
    }
}

//second function of manager menu
void showClientCount(vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount) {
    cout << "Всего на данный момент лечящихся: " << beingTreatedCount  << endl << endl;
    cout << "Напишите 0 чтобы вернуться назад: " << endl << endl << ">> ";
    cin >> userEnter;
    if (userEnter == 0) {
        system("cls");
    }
    else {
        cout << "Чтобы вернуться назад, введите 0: " << endl << ">> ";
    }
}

//function for third function, that allow run recursion
void findFunction (vector<Account>& data, string &strUserEnter, int peopleCount) {
    int successFind = 0;
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].name == strUserEnter) {
            successFind++;
            cout << endl << data[i].name << " " << data[i].surname << endl
            << "Рост: " << data[i].height << " см " << endl
            << "Вес: " << data[i].weight << " кг " << endl
            << "Дата рождения: "<< data[i].birthday << endl << endl
            << "Список болезней: " << endl;
            for (int j = 0; j < data[i].client.diseaseName.size(); j++) {
                cout << data[i].client.diseaseName[j] << endl;
            }
        }
    }
    if (successFind == 0) {
        cout << "Данный пользователь не найден! Попробуйте еще раз, или напишите 0, чтобы выйти в меню: " << endl << endl << ">> ";
    }
    else {
        cout << endl << "Чтобы узнать информацию о другом пользователе, напишите его имя. " << endl << "Если же вы хотите вернуться в главное меню, введите 0: " << endl << endl << ">> ";
    }
    cin >> strUserEnter;
    system("cls");
}

//third function of manager menu
void findClient(vector<Account>& data, string strUserEnter, int peopleCount) {
    cout << "Чтобы узнать всю информацию о пользователе, введите его имя: " << endl << ">> ";
    cin >> strUserEnter;
    system("cls");
    findFunction(data, strUserEnter, peopleCount);
    if (strUserEnter != "0") {
        while (strUserEnter != "0") {
            findFunction(data, strUserEnter, peopleCount);
        }
    }
}

//4
void changePrice(){

}

//5
void changeTimeOrProcedure(){

}

//sixth function of manager menu
void showMaxPersonVisits(vector<Account>& data, int &userEnter, int peopleCount){
    int maxVisits = data[6].client.visitHistory.size();
    int tempInt;
    for (int i = 7; i < peopleCount; i++) {
        if (data[i].type == "patient" && maxVisits < data[i].client.visitHistory.size()) {
            maxVisits = data[i].client.visitHistory.size();
            tempInt = i;
        }
    }
    if (userEnter != 0) {
        while (userEnter != 0) {
            system("cls");
            cout << "Наибольшее количество посещений у пользователя " << data[tempInt].name  << " " << data[tempInt].surname << endl << "Всего посещений: " << maxVisits << endl << endl
                << "Чтобы вернуться в главное меню, напишите 0: " << endl << ">> ";
            cin >> userEnter;
            system ("cls");
        } 
    }
}

//seventh function of manager menu
void showMinPersonVisits(vector<Account>& data, int &userEnter, int peopleCount){
    int minVisits = data[6].client.visitHistory.size();
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
                << "Чтобы вернуться в главное меню, напишите 0: " << endl << ">> ";
            cin >> userEnter;
            system ("cls");
        } 
    }
}

//main manager menu
void managerMenu(bool programStatus, vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount, string strUserEnter) {
    while(programStatus) {
        
        userEnter = 0;

        cout << "Пожалуйста наберите номер меню для работы с программой: " << endl
        << "1. Показать список посетителей" << endl //(Показывает список посетителей, которые получают на данный момент свое лечение)
        << "2. Показать количество посетителей" << endl 
        << "3. Поиск посетителя" << endl 
        << "4. Изменить цену для процедур" << endl 
        << "5. Изменить время/название процедур" << endl 
        << "6. Показать посетителя с максимальным количеством посещений" << endl
        << "7. Показать посетителя с минимальным количеством посещений" << endl 
        << "8. Выход" << endl << endl << ">> ";
        
        cin >> userEnter; 

        if ((userEnter >= 1) && (userEnter <= 8)) {
            userEnter = userEnter;
        }
        else {
            userEnter = 8;
        }

        switch(userEnter) {
            case 0:
            {

            }
            case 1: 
            {
                system("cls");
                showClientList(data, userEnter, peopleCount);
                break;
            }
            case 2:
            {
                system("cls");
                showClientCount(data, userEnter, peopleCount, beingTreatedCount);
                break;
            }
            case 3:
            {
                system("cls");
                findClient(data, strUserEnter, peopleCount); //for now does not work with russian names
                break;
            }
            case 6:
            {
                system("cls");
                showMaxPersonVisits(data, userEnter, peopleCount);
                break;
            }
            case 7:
            {
                system("cls");
                showMinPersonVisits(data, userEnter, peopleCount);
                break;                
            }
            case 8:
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