#include "headers\database.h"

bool isTypeCorrect(string enterType) {
    if (enterType == "director" ||  enterType == "manager" || enterType == "personal" || enterType == "patient") {
        return true;
    }
    else {
        return false;
    }
}

void showPersonal (int peopleCount, vector<Account>& data) {
    for (int i = 0; i < peopleCount; i++) {
        cout << data[i].type << " " << data[i].login << " " << data[i].password << " " << data[i].name << " " << data[i].surname << " " << data[i].height << " "<< data[i].birthday << data[i].weight << " " << data[i].ID << " " << endl;
    }
}

int main()
{
    int peopleCount = 11; //just for primary code testing.
    vector <Account> data(peopleCount); 
    dataBase(data);
    showPersonal(peopleCount, data);
    /*
    bool typeStatus = false, loginStatus = false, passwordStatus = false;
    string enterType, enterLogin, enterPassword;
    int checkId;
    
    cout << "Приветствуем вас! Введите пожалуйста тип аккаунта:" << endl;
    while (typeStatus == false) {
        cin >> enterType;
        if (isTypeCorrect(enterType)) {
            typeStatus = true;
        }
        else {
            cout << "Неверный тип аккаунта! Повторите еще раз: " << endl;
        }
    }
    
    cout << "Введите логин: " << endl;
    while (loginStatus == false) {
        cin >> enterLogin;
        for (int i = 0; i < 5; i++){
            if (enterLogin == data[i].login) {
                cout << "Верный логин";
            }
        }
    } 
    
    cout << data[0].type;*/

    return 0;
}