

/* 
 * File:   MyHeaders.h
 * Author: Scott Parker
 *
 * Created on March 27, 2017, 2:28 PM
 */

#ifndef MYHEADERS_H
#define MYHEADERS_H

struct MonthlyBudget {
    float housing; //Housing
    float util; //Utilities
    float housExp; //Household Expenses
    float transpo; //Transportation
    float food; //Food
    float medical; //Medical
    float insur; //Insurance
    float enterta; //Entertainment
    float cloth;  //Clothing
    float misc; //Miscellaneous
};

struct Movie {
    string title;
    string direct;
    int relDate;
    int runTime;
};

struct MovieR {
    string title;
    string direct;
    int relDate;
    int runTime;
    int proCost;
    int relEarn;
};

struct DivData {
    string divName;
    int qOneSal;
    int qTwoSal;
    int qThrSal;
    int qFouSal;
    int totSale;
    float avgSale;
};

struct TempDat {
    float totRain;
    int hiTemp;
    int lowTemp;
    float avgTemp;
};

struct Pstats {
    string name;
    int number;
    int points;
};

struct Speaker {
    int spkrNum;
    string name;
    string telNum;
    string topic;
    int minFee;
};


#endif /* MYHEADERS_H */

