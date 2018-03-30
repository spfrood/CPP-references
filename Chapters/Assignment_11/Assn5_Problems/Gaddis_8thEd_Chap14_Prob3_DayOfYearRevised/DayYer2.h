/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayYer2.h
 * Author: scott_r_parker
 *
 * Created on May 9, 2017, 4:55 PM
 */

#ifndef DAYYER2_H
#define DAYYER2_H

#include <string>
using namespace std;

class DayYer2 {
private:
    bool valid=true;
    unsigned short number;
    string month="";
    unsigned short dOfMon=0;
    
public:
    //Constructor
    DayYer2(string, unsigned short);
    
    //Print functions (getters)
    string pMonDay ();
    string pStatus ();
    bool getValid ();
    
    //Operator overloads
    DayYer2 operator ++ ();
    DayYer2 operator ++ (int);
    DayYer2 operator -- ();
    DayYer2 operator -- (int);
};

#endif /* DAYYER2_H */

