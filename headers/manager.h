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
    cout << "Напишите 0 чтобы вернуться назад: " << endl;
    cin >> userEnter;
    if (userEnter == 0) {
        system("cls");
    }
    else {
        cout << "Чтобы вернуться назад, введите 0: " << endl;
    }
}

//second function of manager menu
void showClientCount(vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount) {
    cout << "Всего на данный момент лечящихся: " << beingTreatedCount  << endl << endl;
    cout << "Напишите 0 чтобы вернуться назад: " << endl;
    cin >> userEnter;
    if (userEnter == 0) {
        system("cls");
    }
    else {
        cout << "Чтобы вернуться назад, введите 0: " << endl;
    }
}


//main manager menu
void managerMenu(bool programStatus, vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount) {
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
        << "8. Выход" << endl;
        
        cin >> userEnter; 

        switch(userEnter) {
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