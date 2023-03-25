#pragma once
#include "Libraries.h"

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
        string bloodType;
    } client;
};

struct Diseases {
    string diseasesName;
    int diseasesPrice;
    string diseasesTime;
    string bloodType;
};