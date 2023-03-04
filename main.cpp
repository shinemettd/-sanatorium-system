#include "headers\manager.h"

void countBeingTreated(vector<Account>& data, int peopleCount, int &beingTreatedCount) {
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].type == "patient" && data[i].client.beingTreated == true){
            beingTreatedCount++;
        }
    }
}

void showPersonal (int peopleCount, vector<Account>& data) {
    for (int i = 0; i < peopleCount; i++) {
        cout << "\t"
            << data[i].ID << " | "
            << data[i].type << " | " 
            << data[i].login << " | " 
            << data[i].password << " | " 
            << data[i].name << " | " 
            << data[i].surname << " | " 
            << data[i].height << " | "
            << data[i].weight << " | " 
            << data[i].birthday << " | " 
            << endl;
    }
    cout << endl << endl;
}

int main()
{
    int peopleCount = 11; //just for primary code testing.
    vector <Account> data(peopleCount); 
    dataBase(data);
    //showPersonal(peopleCount, data);
    bool typeStatus = false;
    bool loginStatus = false;
    bool programStatus = true;
    char access;
    string enterType, enterLogin, enterPassword;
    int actualId;
    int userEnter;
    int clientCount = 5;
    int beingTreatedCount = 0;

    countBeingTreated(data, peopleCount, beingTreatedCount);
    
    cout << "Введите пожалуйста тип аккаунта:" << endl;
    while (typeStatus == false) {
        
        cin >> enterType;
        system("cls");
        
        enterType.erase(remove(enterType.begin(), enterType.end(), ' '), enterType.end()); //deleting possible accidental spaces from type
        
        if (isTypeCorrect(enterType, access)) {
            typeStatus = true;
        }
        else {
            cout << "Неверный тип аккаунта! Повторите еще раз: " << endl;
        }
    }
    
    while (loginStatus == false) {
        
        cout << "Введите логин: " << endl;
        cin >> enterLogin;
        cout << "Введите пароль: " << endl;
        cin >> enterPassword;
        system("cls");
        
        enterLogin.erase(remove(enterLogin.begin(), enterLogin.end(), ' '), enterLogin.end()); //deleting possible accidental spaces from login
        enterType.erase(remove(enterType.begin(), enterType.end(), ' '), enterType.end()); //deleting possible accidental spaces from password
        
        if (loginCorrect(enterType, enterLogin, enterPassword, data, peopleCount, actualId)) {
            loginStatus = true;
        }
        else {
            cout << "Неверный логин или пароль" << endl;
        }
        
    } 
    
    system("cls");
    cout << "Добро пожаловать в систему, " << data[actualId].surname << " " << data[actualId].name << "!" << endl;
    cout << "Ваш доступ: " << access << endl;

    switch(access) {
        case '2': 
        {
            managerMenu(programStatus, data, userEnter, peopleCount, beingTreatedCount);
            break;
        }
        default:
        {
            cout << "Error";
        }
    }
    system("pause");
    return 0;
}