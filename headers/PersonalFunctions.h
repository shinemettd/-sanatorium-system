#include "LoginSystem.h"
#include "ManagerFunctions.h"

//1
void showListProcedure(vector<Account>& data, vector<Diseases>& diseases, string& strUserEnter, int peopleCount) {
    bool extraSpace = false;
    bool someonesFound = false;
    for (int i = 0; i < diseases.size(); i++) {
        cout << diseases[i].diseasesName << ":" << endl;
        for (int j = 0; j < data.size(); j++) {
            for (int l = 0; l < data[j].client.diseaseName.size(); l++) {
                if (diseases[i].diseasesName == data[j].client.diseaseName[l]) {
                    cout << data[j].name << " " << data[j].surname << endl;
                    extraSpace = true;
                }
            }
        }
        if (extraSpace == true) {
            cout << endl;
            extraSpace = false;
        }
        else {
            cout << "-" << endl << endl;
        }
    }
    goBack(strUserEnter);
}
//2 already exist at manager.h

//3 already exist at manager.h

//4 
void showSchedule(vector <Diseases> &diseases, string &strUserEnter) {
    for (int i = 0; i < diseases.size(); i++) {
        cout << diseases[i].diseasesName << " - " << diseases[i].diseasesTime << endl << endl;
    }
    goBack(strUserEnter);
}

//5
void buyProcedure(vector<Account>& data, vector<Diseases>& diseases, string& strUserEnter) {
    cout << "Введите имя человека, которому вы хотите назначить процедуру: "; enterLine();
    cin >> strUserEnter;
    bool successFindPatient = false;
    bool successFindDisease = false;
    bool patientHadDisease = false;
    int nameId, diseaseId;
    while (strUserEnter != "0") {
        for (nameId = 0; data.size(); nameId++) {
            if (data[nameId].name == strUserEnter && data[nameId].client.beingTreated == true) {
                successFindPatient = true;
                break;
            }
        }
        if (successFindPatient == true) {
            while (strUserEnter != "0") {
                cout << endl << "Введите название процедуры, на которую вы хотите назначить пациента " << data[nameId].name << " " 
                    << data[nameId].surname << ":"; enterLine();
                cin >> strUserEnter;
                for (diseaseId = 0; diseases.size(); diseaseId++) {
                    if (diseases[diseaseId].diseasesName == strUserEnter) {
                        for (int k = 0; k < diseases[diseaseId].diseasesName.size(); k++) {
                            if (strUserEnter == data[nameId].client.diseaseName[k]) {
                                system("cls");
                                cout << "Такая процедура уже имеется у пациента!" << endl << endl << 
                                "Введите 0, чтобы вернуться в главное меню: "; enterLine();
                                patientHadDisease = true;
                                while (strUserEnter != "0") {
                                    cin >> strUserEnter; 
                                    if (strUserEnter != "0") {
                                        strUserEnter = "0";
                                    }
                                }
                            }
                            else {
                                patientHadDisease = false;
                            }
                        }
                        if (patientHadDisease == false) {
                            data[nameId].client.diseaseName.push_back(diseases[diseaseId].diseasesName);
                        }
                        successFindDisease = true;
                        break;
                    }
                }
                if (successFindDisease == true) {
                    system("cls");
                    cout << "Пациенту " << data[nameId].name << " " << data[nameId].surname << " была назначена процедура " << diseases[diseaseId].diseasesName <<
                        endl << endl << "Введите 0, чтобы вернуться в главное меню:"; enterLine();
                        while (strUserEnter != "0") {
                            cin >>  strUserEnter;
                            if (strUserEnter!="0") {
                                strUserEnter = "0";
                            }
                        }
                }
                else {
                    system("cls");
                    cout << "Данная процедура не найдена! Попробуйте еще раз: " << endl << "Или напишите 0, чтобы вернуться в главное меню"; enterLine();
                }
            }
        }
        else {
            system("cls");
            cout << "Данный пользователь не найден! Попробуйте еще раз: " << endl << "Или напишите 0, чтобы вернуться в главное меню"; enterLine();
        }
    }
}


//for 6th function
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
        cout << "Данная процедура не была найдена, попробуйте еще раз: " << endl << "Если вы хотите вернуться в главное меню, напишите 0."; enterLine();
    }
    else {
        cout << endl << "Чтобы вернуться назад, напишите 0: "; enterLine();
    }
}

//6 
void findProcedure(vector<Account>& data, vector<Diseases>& diseases, string& strUserEnter, int peopleCount) {
    cout << "Введите название процедуры, которую вы хотите найти: "; enterLine();
    while (strUserEnter != "0") {
        findingProcedureFunction(data, diseases, strUserEnter, peopleCount);
    }
}


void personalMenu(bool programStatus, vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount, 
                string strUserEnter, int personalCount, vector<Diseases> &diseases, int actualId, string todaysDate) {
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
                showListProcedure(data, diseases, strUserEnter, peopleCount);
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
                showSchedule(diseases, strUserEnter);
                break;
            }
            case 5:  
            { 
                system("cls"); 
                buyProcedure(data, diseases, strUserEnter);
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