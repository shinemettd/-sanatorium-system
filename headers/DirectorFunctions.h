#include "LoginSystem.h"
#include "ManagerFunctions.h"

bool isEnterTrue (string &strUserEnter) {
    if (strUserEnter == "director" || strUserEnter == "manager" || strUserEnter == "personal" || strUserEnter == "patient") {
        return true;
    }
    else {
        return false;
    }
}

void addPersonal (vector<Account>& data, string &strUserEnter, int userEnter, int &peopleCount, string todaysDate) 
{
    Account newAccount;
    bool fullRegistration;
    cout << "Вы можете в любой момент отменить регистрацию аккаунта, ведя 0" << endl 
         << "Обратите внимание, что ВСЕ данные должны быть записаны строго на латинице!" << endl
         << "Введите тип аккаунта(director/manager/personal/patient): "; enterLine();
    while (strUserEnter != "0") {
        fullRegistration = false;
        cin >> strUserEnter;

        if (isEnterTrue(strUserEnter)) {
            
            newAccount.type = strUserEnter;
            if (newAccount.type == "patient") {
                newAccount.client.beingTreated = true;
            }

            system("cls");
            cout << "Введите имя:"; enterLine();
            cin >> strUserEnter;
            newAccount.name = strUserEnter;
            
            system("cls");
            cout << "Введите фамилию:"; enterLine();
            cin >> strUserEnter;
            newAccount.surname = strUserEnter;

            system("cls");
            cout << "Введите логин:"; enterLine();
            cin >> strUserEnter;
            newAccount.login = strUserEnter;

            system("cls");
            cout << "Введите пароль:"; enterLine();
            cin >> strUserEnter;
            newAccount.password = strUserEnter;

            system("cls");
            cout << "Введите рост:"; enterLine();
            cin >> userEnter;
            if (userEnter == 0) break;
            newAccount.height = userEnter;

            system("cls");
            cout << "Введите вес:"; enterLine();
            cin >> userEnter;
            if (userEnter == 0) break;
            newAccount.weight = userEnter;

            system("cls");
            cout << "Введите дату рождения в формате ДД.ММ.ГГГГ:"; enterLine();
            
            do {
                cin >> strUserEnter;
                if (strUserEnter == "0") break;
                system("cls");
            } while (isDateRight(strUserEnter, todaysDate)!= true);
            newAccount.birthday = strUserEnter;

            newAccount.ID = peopleCount;

            fullRegistration = true;
        }
        else {
            system("cls");
            cout << "Неправильно введена должность, попробуйте еще раз, или введите 0, для возвращения в главное меню: "; enterLine();
        }

        if (fullRegistration == true) {
            system("cls");
            cout << "Данные аккаунта: " << endl << endl
            << newAccount.name << " " << newAccount.surname << endl
            << "Тип аккаунта: " << newAccount.type << endl
            << "Логин: " << newAccount.login << endl
            << "Пароль: " << newAccount.password << endl
            << "Рост: " << newAccount.height << " см"<< endl
            << "Вес: " << newAccount.weight << " кг" << endl
            << "Дата рождения: " << newAccount.birthday << endl 
            << "ID аккаунта: " << newAccount.ID << endl << endl
            << "Введите 1, чтобы внести аккаунт в базу данных, или 0, чтобы отменить регистрацию: "; enterLine();
            cin >> strUserEnter;
            if (strUserEnter != "1") {
                strUserEnter = "0";
                break;
            }
            else {
                data.push_back(newAccount);
                peopleCount++;
                break;
            }
        }
    }
}

void showAllAccounts(vector<Account>& data, string &strUserEnter, int peopleCount) {
    system("cls");
    for (int i = 0; i < peopleCount; i++) {
        cout << data[i].name << " " << data[i].surname << endl
        << "Тип аккаунта: " << data[i].type << endl
        << "ID: " << data[i].ID << endl << endl;
    }
    while (strUserEnter!="0") {
        cout << "Введите 0, чтобы вернуться в главное меню: "; enterLine();
        cin >> strUserEnter;
        if (strUserEnter != "0") {
            strUserEnter = "0";
        }
    }
}

void editAccountInfo (vector<Account>& data, string &strUserEnter, int userEnter, int &peopleCount) {
    system("cls");
    cout << "Введите ID аккаунта:" << endl << "Для выхода в меню, напишите -1:"; enterLine();
    int userId;
    cin >> userEnter;
    while (userEnter > 0) {
        userId = userEnter;
        if (userEnter > peopleCount) {
            while (userEnter < peopleCount) {
                system("cls");
                cout << "Введено неверное ID, попробуйте еще раз: "; enterLine();
                cin >> userEnter;
                userId = userEnter;
            }
        }
        else if (userEnter < 0) {
            return;
        }
        else {
            while (userEnter > 0 || userEnter <= 6) {
                system("cls");
                cout << "Поменять имя - 1" << endl << "Поменять фамилию - 2" << endl << "Поменять логин - 3" << endl 
                << "Поменять пароль - 4" << endl << "Вернуться в главное меню - 5"; enterLine();
                cin >> userEnter;
                if (userEnter == 1) {
                    system("cls");
                    cout << "Введите новое имя: "; enterLine();
                    cin >> strUserEnter;
                    data[userId].name = strUserEnter;
                    userEnter = 6;
                }
                else if (userEnter == 2) {
                    system("cls");
                    cout << "Введите новую фамилию: "; enterLine();
                    cin >> strUserEnter;
                    data[userId].surname = strUserEnter;
                    userEnter = 6;
                }
                else if (userEnter == 3) {
                    system("cls");
                    cout << "Введите новый логин: "; enterLine();
                    cin >> strUserEnter;
                    data[userId].login = strUserEnter;
                    userEnter = 6;
                }
                else if (userEnter == 4) {
                    system("cls");
                    cout << "Введите новый пароль: "; enterLine();
                    cin >> strUserEnter;
                    data[userId].password = strUserEnter;
                    userEnter = 6;
                }
                else {
                    userEnter = -1;
                    break;
                }
            }
        }
    }
}

void deleteAccount(vector<Account>& data, string &strUserEnter, int userEnter, int &peopleCount) {
    cout << "Введите ID аккаунта:" << endl << "Для выхода в меню, напишите -1:"; enterLine();
    cin >> userEnter;
    int userId;
    while (userEnter > 0) {
        userId = userEnter;
        if (userEnter > peopleCount) {
            while (userEnter < peopleCount) {
                system("cls");
                cout << "Введено неверное ID, попробуйте еще раз: "; enterLine();
                cin >> userEnter;
                userId = userEnter;
            }
        }
        else if (userEnter < 0) {
            return;
        }
        else {
            system("cls");
            cout << "Вы точно хотите удалить аккаунт " << data[userId].name << " " << data[userId].surname << "?" << endl << "Да - 1" << endl << "Нет - 2"; enterLine();
            cin >> userEnter;
            if (userEnter == 1) {
                data.erase(data.begin() + userId);
                peopleCount--;
                break;
            }
            else {
                break;
            }
        }
    }
}

void directorMenu(bool programStatus, vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount, string strUserEnter, int personalCount, vector<Diseases> &diseases,
                  string todaysDate) {
    while(programStatus) {
        system("cls");

        strUserEnter = "null";
        userEnter = -1;

        cout << "Пожалуйста наберите номер меню для работы с программой: " << endl
        << "1. Добавить новый аккаунт" << endl //(Показывает список посетителей, которые получают на данный момент свое лечение)
        << "2. Показать все аккаунты" << endl 
        << "3. Изменить данные аккаунта" << endl 
        << "4. Удалить существующий аккаунт" << endl
        << "5. Показать список посетителей" << endl 
        << "6. Показать количество посетителей" << endl 
        << "7. Поиск посетителя" << endl 
        << "8. Показать список процедур" << endl
        << "9. Изменить цену для процедур" << endl 
        << "10. Изменить время/название процедур" << endl 
        << "11. Показать посетителя с максимальным количеством посещений" << endl
        << "12. Показать посетителя с минимальным количеством посещений" << endl 
        << "13. Выход"; enterLine();
        
        cin >> userEnter; 

        if ((userEnter >= 1) && (userEnter <= 13)) {
            userEnter = userEnter;
        }
        else {
            userEnter = 13;
        }

        switch(userEnter) {
            case 1: 
            {
                system("cls");
                addPersonal(data, strUserEnter, userEnter, peopleCount, todaysDate);
                break;
            }
            case 2:
            {
                system("cls");
                showAllAccounts(data, strUserEnter, peopleCount);
                break;
            }
            case 3:
            {
                system("cls");
                editAccountInfo (data, strUserEnter, userEnter, peopleCount);
                break;
            }
            case 4:
            {
                system("cls");
                deleteAccount(data, strUserEnter, userEnter, peopleCount);
                break;
            }
            case 5:  
            { 
                system("cls"); 
                showClientList(data, strUserEnter, peopleCount);
                break;
            }
            case 6:
            {
                system("cls");
                showClientCount(data, strUserEnter, peopleCount, beingTreatedCount);
                break;
            }
            case 7:
            {
                system("cls");
                findClient(data, strUserEnter, peopleCount); 
                break;
            }
            case 8:
            {
                system("cls");
                showAllDiseases (diseases, strUserEnter);
                break;
            }
            case 9:  
            { 
                system("cls"); 
                changePrice(diseases, strUserEnter, peopleCount); 
                break;
            }
            case 10:  
            { 
                system("cls"); 
                cout << "Введите 1, чтобы изменить время процедуры:" << endl << "Введите 2, чтобы изменить название процедуры: " << endl 
                << "Введите 0, чтобы вернуться в главное меню: "; enterLine();
                changeTimeOrProcedureName(diseases, strUserEnter, peopleCount); 
                break;
            }
            case 11:
            {
                system("cls");
                showMaxPersonVisits(data, userEnter, peopleCount, personalCount);
                break;
            }
            case 12:
            {
                system("cls");
                showMinPersonVisits(data, userEnter, peopleCount, personalCount);
                break;                
            }
            case 13:
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