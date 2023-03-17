#include "loginsystem.h"
#include "manager.h"

//1

//2 already exist at manager.h

//3 already exist at manager.h

//4 

//5

//for 6t 
void findingProcedureFunction (vector<Account>& data, vector<Diseases>& diseases, string& strUserEnter, int peopleCount) {
    cin >> strUserEnter;   
    int successFind = 0;
    bool someonesFound = false;
    system("cls");
    for (int i = 0; i < diseases.size(); i++) {
        if (strUserEnter == diseases[i].diseasesName) {
            successFind++;
            cout << diseases[i].diseasesName << endl << "Цена: " << diseases[i].diseasesPrice << "$" << endl << "Записаны на процедуру: " << endl;
            for (int j = 0; j < peopleCount; j++) {
                if (data[j].client.diseaseName.size() > 0) {
                    for (int l = 0; l < data[j].client.diseaseName.size(); l++) {
                        if (data[j].client.diseaseName[l] == strUserEnter) {
                            cout << data[j].name << " " << data[j].surname << endl;
                            someonesFound = true;
                            break;
                        }
                    }
                }
            }
            if (someonesFound == false) {
                cout << endl << "Пока никто не записан на данную процедуру." << endl;
            }
            break;
        }
    }
    if (successFind == 0) {
        cout << "Данная процедура не была найдена, попробуйте еще раз: " << endl << "Если вы хотите вернуться в главное меню, напишите 0." << endl << endl << ">> ";
    }
    else {
        cout << endl << "Чтобы вернуться назад, напишите 0: " << endl << endl << ">> ";
    }
}

//6 
void findProcedure(vector<Account>& data, vector<Diseases>& diseases, string& strUserEnter, int peopleCount) {
    cout << "Введите название процедуры, которую вы хотите найти: " << endl << endl << ">> ";
    while (strUserEnter != "0") {
        findingProcedureFunction(data, diseases, strUserEnter, peopleCount);
    }
}


void personalMenu(bool programStatus, vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount, 
                string strUserEnter, int personalCount, vector<Diseases> &diseases, int actualId, vector <int> todaysDate) {
    while(programStatus) {
        system("cls");

        strUserEnter = "null";
        userEnter = 0;

        cout << "Пожалуйста наберите номер меню для работы с программой: " << endl
        << "1. Показать список процедур" << endl //(Показывает весь список процедур с фамилиями посетителей)
        << "2. Найти посетителя " << endl 
        << "3. Показать все процедуры" << endl 
        << "4. Показать расписание к процедурам" << endl
        << "5. Купить процедуру" << endl //Показывает список платных процедур с ценами, после выбранной процедуры выходит сообщение о приобретенной процедуре и записывается в файл
        << "6. Найти процедуру" << endl 
        << "7. Выход" << endl << endl << ">> ";
        
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
                
                break;
            }
            case 2:
            {
                system("cls");
                findClient(data, strUserEnter, peopleCount);
                break;
            }
            case 3:
            {
                system("cls");
                showAllDiseases (diseases, strUserEnter);
                break;
            }
            case 4:
            {
                system("cls");
                
                break;
            }
            case 5:  
            { 
                system("cls"); 
                
                break;
            }
            case 6:  
            { 
                system("cls"); 
                findProcedure(data, diseases, strUserEnter, peopleCount);
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