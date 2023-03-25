#include "headers\ManagerFunctions.h"
#include "headers\PatientFunctions.h"
#include "headers\PersonalFunctions.h"
#include "headers\DirectorFunctions.h"

void countTreatedPeople(vector<Account>& data, int peopleCount, int &beingTreatedCount, int &wasTreatedCount) {
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].type == "patient"){
            wasTreatedCount++;
            if (data[i].client.beingTreated == true) {
                beingTreatedCount++;
            }
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
    string todaysDate;
    determinateTodaysDate(todaysDate);
    int peopleCount = 12; //initial amount !!!IF YOU ADDING NEW PEOPLE TO DATABASE UPDATE THE VALUE OF IT!!!
    int diseasesCount = 9; //initial amount !!!IF YOU ADDING NEW DISEASES TO DATABASE UPDATE THE VALUE OF IT!!!
    vector <Account> data(peopleCount); 
    vector <Diseases> diseases(diseasesCount);
    fillDiseases(diseases); //filling diseases database
    dataBase(data, diseases); //filling personal database
    //showPersonal(peopleCount, data);
    bool typeStatus;
    bool loginStatus;
    bool programStatus;
    char access;
    string enterType, enterLogin, enterPassword;
    int actualId;
    int userEnter;
    int beingTreatedCount = 0;
    int wasTreatedCount = 0;
    int personalCount = 0;
    string strUserEnter;
    bool systemOn = true;

    while (systemOn == true) {  
        
        system("cls");

        bool typeStatus = false;
        bool loginStatus = false;
        int actualId = -1;

        countTreatedPeople(data, peopleCount, beingTreatedCount, wasTreatedCount);
        personalCount = peopleCount - wasTreatedCount;
        
        cout << "Введите пожалуйста тип аккаунта: "; enterLine();
        while (typeStatus == false) {
            
            cin >> enterType;
            system("cls");
            
            enterType.erase(remove(enterType.begin(), enterType.end(), ' '), enterType.end()); //deleting possible accidental spaces from type
            
            if (isTypeCorrect(enterType, access)) {
                typeStatus = true;
            }
            else {
                cout << "Неверный тип аккаунта! Повторите еще раз: "; enterLine();
            }
        }
        
        while (loginStatus == false) {
            
            cout << "Введите логин: "; enterLine();
            cin >> enterLogin;
            cout << endl << "Введите пароль: "; enterLine();
            cin >> enterPassword;
            system("cls");
            
            enterLogin.erase(remove(enterLogin.begin(), enterLogin.end(), ' '), enterLogin.end()); //deleting possible accidental spaces from login
            enterType.erase(remove(enterType.begin(), enterType.end(), ' '), enterType.end()); //deleting possible accidental spaces from password
            
            if (isLoginCorrect(enterType, enterLogin, enterPassword, data, peopleCount, actualId)) {
                loginStatus = true;
            }
            else {
                cout << "Неверный логин или пароль" << endl;
            }
            
        } 
        
        system("cls");
        cout << "Добро пожаловать в систему, " << data[actualId].surname << " " << data[actualId].name << "!" << endl;
        programStatus = true;
        switch(access) {
            case '1':  
            { 
                directorMenu(programStatus, data, userEnter, peopleCount, beingTreatedCount, strUserEnter, personalCount, diseases, todaysDate); 
                break; 
            }            
            case '2':  
            { 
                managerMenu(programStatus, data, userEnter, peopleCount, beingTreatedCount, strUserEnter, personalCount, diseases); 
                break; 
            }
            case '3':  
            { 
                personalMenu(programStatus, data, userEnter, peopleCount, beingTreatedCount, strUserEnter, personalCount, diseases, actualId, todaysDate); 
                break; 
            }
            case '4':  
            { 
                patientMenu(programStatus, data, userEnter, peopleCount, beingTreatedCount, strUserEnter, personalCount, diseases, actualId, todaysDate); 
                break; 
            }
            default:
            {
                cout << "Error";
            }
        }
        if (programStatus == false) {
            bool typeStatus = false;
            bool loginStatus = false;
        }
        system("pause");
    }
    return 0;
}