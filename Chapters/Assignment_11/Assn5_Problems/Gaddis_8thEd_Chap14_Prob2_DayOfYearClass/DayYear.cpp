/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayYear.cpp
 * Author: scott_r_parker
 * 
 * Created on May 9, 2017, 4:55 PM
 */

#include "DayYear.h"

//constructor pass number into class
DayYear::DayYear(unsigned short n) {
    number = n;
}

//Print the month and day based on the number
string DayYear::print() {
    string month="", date="";
    unsigned short day;
    if (number<=31) { //if january
        month="January ";
        day=number;
    } else if (number<=59) { //if february
        month="February ";
        day=number-31;
    } else if (number<=90) { //if march
        month="March ";
        day=number-59;
    } else if (number<=120) { //if april
        month="April ";
        day=number-90;
    } else if (number<=151) { //if may
        month="May ";
        day=number-120;
    } else if (number<=181) { //if june
        month="June ";
        day=number-151;
    } else if (number<=212) { //if july
        month="July ";
        day=number-181;
    } else if (number<=243) { //if august
        month="August ";
        day=number-212;
    } else if (number<=273) { //if september
        month="September ";
        day=number-243;
    } else if (number<=304) { //if october
        month="October ";
        day=number-273;
    } else if (number<=334) { //if november
        month="November ";
        day=number-304;
    } else {
        month="December "; //december
        day=number-334;
    }
    date=month+std::to_string(day);
    return date;
}


