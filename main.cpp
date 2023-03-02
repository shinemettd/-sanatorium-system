#include "headers\database.h"

bool isTypeCorrect(string enterType) {
    
    if (enterType == "director" ||  enterType == "manager" || enterType == "personal" || enterType == "patient") {
        return true;
    }
    else {
        return false;
    }
}

bool loginCorrect (string enterType, string enterLogin, string enterPassword, vector<Account>& data, int peopleCount) {
    for (int i = 0; i < peopleCount; i++) {
        if (enterLogin == data[i].login) {
            if (enterType == data[i].type && enterPassword == data[i].password){
                cout << "Добро пожаловать в систему!" << endl;
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}


void showPersonal (int peopleCount, vector<Account>& data) {
    for (int i = 0; i < peopleCount; i++) {
        cout << data[i].type << " " << data[i].login << " " << data[i].password << " " << data[i].name << " " << data[i].surname << " " << data[i].height << " "<< data[i].birthday << " " << data[i].weight << " " << data[i].ID << " " << endl;
    }
}

bool isLoginCorrect(string type, string login, vector<Account>& data) {
    return true;
}

int main()
{
    int peopleCount = 11; //just for primary code testing.
    vector <Account> data(peopleCount); 
    dataBase(data);
    showPersonal(peopleCount, data);
    
    bool typeStatus = false;
    bool loginStatus = false;
    bool passwordStatus = false;
    string enterType, enterLogin, enterPassword;
    int checkId;
    
    cout << "Приветствуем вас! Введите пожалуйста тип аккаунта:" << endl;
    while (typeStatus == false) {
        
        cin >> enterType;
        
        enterType.erase(remove(enterType.begin(), enterType.end(), ' '), enterType.end()); //deleting possible accidental spaces from type
        
        if (isTypeCorrect(enterType)) {
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
        
        enterLogin.erase(remove(enterLogin.begin(), enterLogin.end(), ' '), enterLogin.end()); //deleting possible accidental spaces from login
        enterType.erase(remove(enterType.begin(), enterType.end(), ' '), enterType.end()); //deleting possible accidental spaces from password
        
        if (loginCorrect(enterType, enterLogin, enterPassword, data, peopleCount)) {
            loginStatus = true;
        }
        else {
            cout << "Неверный логин или пароль!" << endl;
        }
        
    } 

    return 0;
}