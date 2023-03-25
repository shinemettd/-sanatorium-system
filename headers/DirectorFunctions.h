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
        << "6. " << endl 
        << "7. " << endl
        << "8. " << endl 
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
                addPersonal(data, strUserEnter, userEnter, peopleCount, todaysDate);
                break;
            }
            case 2:
            {
                system("cls");
                
                break;
            }
            case 3:
            {
                system("cls");
                
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
                showClientList(data, strUserEnter, peopleCount);
                break;
            }
            case 6:  
            { 
                system("cls"); 
                
                break;
            }
            case 7:
            {
                system("cls");
                
                break;
            }
            case 8:
            {
                system("cls");
                
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