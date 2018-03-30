/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayYer2.cpp
 * Author: scott_r_parker
 * 
 * Created on May 9, 2017, 4:55 PM
 */

#include <string>
using namespace std;
#include "DayYer2.h"

//constructor pass number into class
DayYer2::DayYer2(string m, unsigned short d) {
    valid=true;
    if (m=="January") {
        if (d>31) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=d;
        }
    } else if (m=="February") {
        if (d>28) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=d+31;
        }
    } else if (m=="March") {
        if (d>31) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=59+d;
        }
    } else if (m=="April") {
        if (d>30) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=90+d;
        }
    } else if (m=="May") {
        if (d>31) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=120+d;
        }
    } else if (m=="June") {
        if (d>30) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=151+d;
        }
    } else if (m=="July") {
        if (d>31) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=181+d;
        }
    } else if (m=="August") {
        if (d>31) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=212+d;
        }
    } else if (m=="September") {
        if (d>30) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=243+d;
        }
    } else if (m=="October") {
        if (d>31) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=273+d;
        }
    } else if (m=="November") {
        if (d>30) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=304+d;
        }
    } else if (m=="December") {
        if (d>31) {
            month="ERR! Too Many Days!";
            valid=false;
        } else {
            number=334+d;
        }
    } else {
        month="ERROR! Not a valid month!";
        valid=false;
    }
}

//Return the status of valid or not
bool DayYer2::getValid () {
    return valid;
}
//print function to return the day of the 
string DayYer2::pStatus () {
    string retVal="";
    if (valid) {
        retVal = std::to_string(number);
    } else {
        retVal=month;
    }
    return retVal;
}

//Print the txtMont and day based on the number
string DayYer2::pMonDay() {
    string txtMont="", txtDate="";
    unsigned short day;
    if (number<=31) { //if january
        txtMont="January";
        day=number;
    } else if (number<=59) { //if february
        txtMont="February";
        day=number-31;
    } else if (number<=90) { //if march
        txtMont="March";
        day=number-59;
    } else if (number<=120) { //if april
        txtMont="April";
        day=number-90;
    } else if (number<=151) { //if may
        txtMont="May";
        day=number-120;
    } else if (number<=181) { //if june
        txtMont="June";
        day=number-151;
    } else if (number<=212) { //if july
        txtMont="July";
        day=number-181;
    } else if (number<=243) { //if august
        txtMont="August";
        day=number-212;
    } else if (number<=273) { //if september
        txtMont="September";
        day=number-243;
    } else if (number<=304) { //if october
        txtMont="October";
        day=number-273;
    } else if (number<=334) { //if november
        txtMont="November";
        day=number-304;
    } else {
        txtMont="December"; //december
        day=number-334;
    }
    if (valid) {
        txtDate=txtMont+" "+std::to_string(day);
        month=txtMont;
        dOfMon=day;
    } else {
        txtDate="Invalid Date Entered";
    }
    return txtDate;
}

//prefix opeartor ++ overload
DayYer2 DayYer2::operator ++ ()
{
    if (valid) {
        ++number;
        if (number>365) {
            number=1;
        }
        return *this;
    } else {
        return *this;
    }
}

//postfix opeartor ++ overload
DayYer2 DayYer2::operator ++ (int)
{
    if (valid) {
        DayYer2 temp(month, dOfMon);
    
        number++;
        if (number>365) {
            number=1;
        }
        pMonDay();
        return temp;
    } else {
        return *this;
    }
}

//postfix opeartor -- overload
DayYer2 DayYer2::operator -- ()
{
    if (valid) {
        --number;
        if (number<1) {
            number=365;
        }
        return *this;
    } else {
        return *this;
    }
}

//postfix opeartor -- overload
DayYer2 DayYer2::operator -- (int)
{
    if (valid) {
        DayYer2 temp(month, dOfMon);
    
        number--;
        if (number<1) {
            number=365;
        }
        pMonDay();
        return temp;
    } else {
        return *this;
    }
}