#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Account {
    string type;
    string login;
    string password;
    string name;
    string surname;
    int height;
    int weight;
    string birthday;
    int ID;
    vector <string> visitHistory;
    vector <string> payingHistory;
    vector <string> diseaseName;
    vector <string> diseaseDate;
    int stayDay;
};

void dataBase (vector<Account>& data) {
    
    data[0].type = "director";
    data[0].login = "eleonora71";
    data[0].password = "12345678";
    data[0].name = "Eleonora";
    data[0].surname = "Galanova";
    data[0].height = 164;
    data[0].weight = 58;
    data[0].birthday = "20.04.1971";
    data[0].ID = 0;
    
    data[1].type = "manager";
    data[1].login = "olegskai";
    data[1].password = "lilstupidpig";
    data[1].name = "Oleg";
    data[1].surname = "Savcheko";
    data[1].height = 185;
    data[1].weight = 74;
    data[1].birthday = "10.06.1989";
    data[1].ID = 1;
    
    data[2].type = "personal";
    data[2].login = "victorold";
    data[2].password = "sashaimanya";
    data[2].name = "Victor";
    data[2].surname = "Oldenov";
    data[2].height = 179;
    data[2].weight = 69;
    data[2].birthday = "28.02.1965";
    data[2].ID = 2;

    data[3].type = "personal";
    data[3].login = "kochegarov2001";
    data[3].password = "Ko4egg4r0v2001";
    data[3].name = "Alexey";
    data[3].surname = "Kochegarov";
    data[3].height = 168;
    data[3].weight = 52;
    data[3].birthday = "13.06.2001";
    data[3].ID = 3;

    data[4].type = "personal";
    data[4].login = "lenasamolova87";
    data[4].password = "smlv8787";
    data[4].name = "Elena";
    data[4].surname = "Samolova";
    data[4].height = 167;
    data[4].weight = 67;
    data[4].birthday = "21.05.1987";
    data[4].ID = 4;   

    data[5].type = "personal";
    data[5].login = "mihalkovnik";
    data[5].password = "nikita1960";
    data[5].name = "Nikita";
    data[5].surname = "Mihalkov";
    data[5].height = 175;
    data[5].weight = 80;
    data[5].birthday = "22.11.1960";
    data[5].ID = 5;

    data[6].type = "client";
    data[6].login = "lepsthebest";
    data[6].password = "ktoeslineleps";
    data[6].name = "Grigory";
    data[6].surname = "Leps";
    data[6].height = 178;
    data[6].weight = 81;
    data[6].birthday = "16.07.1962";
    data[6].ID = 6;

    data[7].type = "client";
    data[7].login = "katerina_s";
    data[7].password = "serebrykova1984";
    data[7].name = "Ekaterina";
    data[7].surname = "Serebryakova";
    data[7].height = 186;
    data[7].weight = 72;
    data[7].birthday = "02.09.1984";
    data[7].ID = 7;

    data[8].type = "client";
    data[8].login = "sneax98";
    data[8].password = "limon2004";
    data[8].name = "Aman";
    data[8].surname = "Nazarkulov";
    data[8].height = 192;
    data[8].weight = 74;
    data[8].birthday = "14.02.2004";
    data[8].ID = 8;    

    data[9].type = "client";
    data[9].login = "homelander";
    data[9].password = "hero_of_the_world";
    data[9].name = "John";
    data[9].surname = "Vought";
    data[9].height = 179;
    data[9].weight = 75;
    data[9].birthday = "04.07.1981";
    data[9].ID = 9;    

    data[10].type = "client";
    data[10].login = "natsuki1998";
    data[10].password = "emilia-tan-maji-tenshi";
    data[10].name = "Subaru";
    data[10].surname = "Natsuki";
    data[10].height = 173;
    data[10].weight = 66;
    data[10].birthday = "01.04.1998";
    data[10].ID = 10; 
}

bool isTypeCorrect(string enterType) {
    if (enterType == "director" ||  enterType == "manager" || enterType == "personal" || enterType == "patient") {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    vector <Account> data(11);
    dataBase(data);
    for (int i = 0; i < 11; i++) {
        cout << data[i].type << " " << data[i].login << " " << data[i].password << " " << data[i].name << " " << data[i].surname << " " << data[i].birthday << " " << data[i].ID << " " << endl;
    }
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