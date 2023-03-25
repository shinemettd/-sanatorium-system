#pragma once
#include "Database.h"
#include "InterfaceFunctions.h"

//giving valid types of account
bool isTypeCorrect(string enterType, char &access) {
    if (enterType == "director") {
        access = '1';
        return true;
    } 
    else if (enterType == "manager") {
        access = '2';
        return true;
    }
    else if (enterType == "personal") {
        access = '3';
        return true;
    }
    else if (enterType == "patient") {
        access = '4';
        return true;
    }
    else {
        return false;
    }
}

//checking the correct input data and also comparing status of entered type of account and actual type of account 
bool isLoginCorrect (string enterType, string enterLogin, string enterPassword, vector<Account>& data, int peopleCount, int &actualId) {
    for (int i = 0; i < peopleCount; i++) {
        if (enterLogin == data[i].login) {
            if (enterType == data[i].type && enterPassword == data[i].password){
                actualId = data[i].ID;
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}