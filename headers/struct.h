#pragma once
#include "libraries.h"

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

    struct Client {
    int stayDay;
    bool beingTreated;
    vector <string> visitHistory;
    vector <int> payingHistory;
    vector <string> diseaseName;
    vector <string> diseaseDate;
    } client;
};

