#pragma once
#include "struct.h"

//today is 17.03.2023

void dataBase (vector<Account>& data) {
    
    data[0].type = "director";
    data[0].login = "eleonora71";
    data[0].password = "12345678";
    data[0].name = "Элеонора";
    data[0].surname = "Галанова";
    data[0].height = 164;
    data[0].weight = 58;
    data[0].birthday = "20.04.1971";
    data[0].ID = 0;
    
    data[1].type = "manager";
    data[1].login = "olegskai";
    data[1].password = "lilstupidpig";
    data[1].name = "Олег";
    data[1].surname = "Савченко";
    data[1].height = 185;
    data[1].weight = 74;
    data[1].birthday = "10.06.1989";
    data[1].ID = 1;
    
    data[2].type = "personal";
    data[2].login = "victorold";
    data[2].password = "sashaimanya";
    data[2].name = "Виктор";
    data[2].surname = "Олденов";
    data[2].height = 179;
    data[2].weight = 69;
    data[2].birthday = "28.02.1965";
    data[2].ID = 2;

    data[3].type = "personal";
    data[3].login = "kochegarov2001";
    data[3].password = "Ko4egg4r0v2001";
    data[3].name = "Алексей";
    data[3].surname = "Кочегаров";
    data[3].height = 168;
    data[3].weight = 52;
    data[3].birthday = "13.06.2001";
    data[3].ID = 3;

    data[4].type = "personal";
    data[4].login = "lenasamolova87";
    data[4].password = "smlv8787";
    data[4].name = "Елена";
    data[4].surname = "Самолова";
    data[4].height = 167;
    data[4].weight = 67;
    data[4].birthday = "21.05.1987";
    data[4].ID = 4;   

    data[5].type = "personal";
    data[5].login = "mihalkovnik";
    data[5].password = "nikita1960";
    data[5].name = "Никита";
    data[5].surname = "Михалков";
    data[5].height = 175;
    data[5].weight = 80;
    data[5].birthday = "22.11.1960";
    data[5].ID = 5;

    data[6].type = "patient";
    data[6].login = "lepsthebest";
    data[6].password = "ktoeslineleps";
    data[6].name = "Григорий";
    data[6].surname = "Лепс";
    data[6].height = 178;
    data[6].weight = 81;
    data[6].birthday = "16.07.1962";
    data[6].ID = 6;
    data[6].client.stayDay = 23;
    data[6].client.beingTreated = false;
    data[6].client.visitHistory = {"21.01.2023", "27.01.2023", "04.02.2023"};
    data[6].client.payingHistory = {};
    data[6].client.diseaseName = {};
    data[6].client.diseaseDate = {};

    data[7].type = "patient";
    data[7].login = "katerina_s";
    data[7].password = "serebrykova1984";
    data[7].name = "Екатерина";
    data[7].surname = "Серябрякова";
    data[7].height = 186;
    data[7].weight = 72;
    data[7].birthday = "02.09.1984";
    data[7].ID = 7;
    data[7].client.stayDay = 6;
    data[7].client.beingTreated = true;
    data[7].client.visitHistory = {"02.03.2023", "12.03.2023"};
    data[7].client.payingHistory = {};
    data[7].client.diseaseName = {};
    data[7].client.diseaseDate = {};

    data[8].type = "patient";
    data[8].login = "sneax98";
    data[8].password = "limon2004";
    data[8].name = "Аман";
    data[8].surname = "Назаркулов";
    data[8].height = 192;
    data[8].weight = 74;
    data[8].birthday = "14.02.2004";
    data[8].ID = 8;
    data[8].client.stayDay = 17;
    data[8].client.beingTreated = true;
    data[8].client.visitHistory = {"01.03.2023", "04.03.2023", "11.03.2023"};
    data[8].client.payingHistory = {25, 25, 25};
    data[8].client.diseaseName = {"Бронхиальная астма"};
    data[8].client.diseaseDate = {"04.03.2023", "11.03.2023", "18.03.2023", "25.03.2023"};  

    data[9].type = "patient";
    data[9].login = "homelander";
    data[9].password = "hero_of_the_world";
    data[9].name = "Джон";
    data[9].surname = "Воут";
    data[9].height = 179;
    data[9].weight = 75;
    data[9].birthday = "04.07.1981";
    data[9].ID = 9;
    data[9].client.stayDay = 1;
    data[9].client.beingTreated = false;
    data[9].client.visitHistory = {"14.07.2021", "15.07.2021", "17.07.2021", "19.07.2021", "26.07.2021", "02.08.2021", "01.09.2021"};
    data[9].client.payingHistory = {30 + 35, 30 + 35, 30 + 35, 30 + 35, 30 + 35, 30 + 35, 30 + 35};
    data[9].client.diseaseName = {"Импотенция", "Кардиопатия"};
    data[9].client.diseaseDate = {"15.07.2021", "17.07.2021", "19.07.2021", "26.07.2021", "02.08.2021", "01.09.2021"};

    data[10].type = "patient";
    data[10].login = "natsuki1998";
    data[10].password = "emilia-tan-maji-tenshi";
    data[10].name = "Субару";
    data[10].surname = "Нацуки";
    data[10].height = 173;
    data[10].weight = 66;
    data[10].birthday = "01.04.1998";
    data[10].ID = 10;
    data[10].client.stayDay = 25;
    data[10].client.beingTreated = true;
    data[10].client.visitHistory = {"01.01.2023", "15.01.2023", "01.02.2023", "15.02.2023", "01.03.2023"};
    data[10].client.payingHistory = {};
    data[10].client.diseaseName = {};
    data[10].client.diseaseDate = {};
}

void fillDiseases(vector<Diseases>& diseases) {
    
    diseases[0].diseasesName = "Cardio";
    diseases[0].diseasesPrice = 35;
    diseases[0].diseasesTime = "11:00";

    diseases[1].diseasesName = "Ревматизм в неактивной фазе";
    diseases[1].diseasesPrice = 40;
    diseases[1].diseasesTime = "13:00";

    diseases[2].diseasesName = "Бронхиальная астма";
    diseases[2].diseasesPrice = 25;
    diseases[2].diseasesTime = "10:30";

    diseases[3].diseasesName = "Эндометрит";
    diseases[3].diseasesPrice = 40;
    diseases[3].diseasesTime = "15:00";

    diseases[4].diseasesName = "Хронический сальпингит";
    diseases[4].diseasesPrice = 30;
    diseases[4].diseasesTime = "14:30";

    diseases[5].diseasesName = "Ринит";
    diseases[5].diseasesPrice = 25;
    diseases[5].diseasesTime = "11:30";

    diseases[6].diseasesName = "Ларингит";
    diseases[6].diseasesPrice = 35;
    diseases[0].diseasesTime = "16:00";

    diseases[7].diseasesName = "Хронический простатит";
    diseases[7].diseasesPrice = 45;
    diseases[0].diseasesTime = "12:30";

    diseases[8].diseasesName = "Импотенция";
    diseases[8].diseasesPrice = 30;
    diseases[0].diseasesTime = "12:00";

}