/* 
  File:   P1DtCls.cpp
  Author: Scott Parker
  Created on May 1st, 2017, 12:05 PM
  Purpose:  Date Class Functions
 */

#include "P1DtCls.h"

//Set the value of the private data members
void P1DtCls::sDate () {
    cout<<"Enter the year:"<<endl;
    cin>>year;
    while (cin.fail()) {
        cout<<"Year range out of bounds! Re-enter year!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>year;
    }
    cout<<"Enter the day (range of 1 to 31):"<<endl;
    cin>>day;
    while (cin.fail() || day<1 || day>31) {
        cout<<"Day range out of bounds! Re-enter day!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>day;
    }
    cout<<"Enter the month (range of 1-12 for Jan, Feb... Dec)"<<endl;
    cin>>month;
    while (cin.fail() || month<1 || month>12) {
        cout<<"Month range out of bounds! Re-enter month!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>month;
    }
}

//returns string with the text value of the month
string P1DtCls::gMonTxt() {
    string tMonth;
    switch(month){
        case 12:{tMonth="December";break;}
        case 11:{tMonth="November";break;}
        case 10:{tMonth="October";break;}
        case 9:{tMonth="September";break;}
        case 8:{tMonth="August";break;}
        case 7:{tMonth="July";break;}
        case 6:{tMonth="June";break;}
        case 5:{tMonth="May";break;}
        case 4:{tMonth="April";break;}
        case 3:{tMonth="March";break;}
        case 2:{tMonth="February";break;}
        case 1:{tMonth="January";break;}
        default:
            cout<<"Something went wrong! ERROR!"<<endl;
    }
    return tMonth;
}

//returns the month data member
int P1DtCls::gMonI() {
    return month;
}

//Returns the day data member
int P1DtCls::gDay() {
    return day;
}

//Get the year (outputs zeros but returns the year data member)
int P1DtCls::gYear() {
    if (year<10) cout<<"000";
    else if (year<100) cout<<"00";
    else if (year<1000) cout<<"0";
    return year;
}

//Function to output the dates in the 3 formats
void P1DtCls::outputs () {
    cout<<"Format 1: "<<gMonI()<<"/"<<gDay()<<"/"<<gYear()<<endl;
    cout<<"Format 2: "+gMonTxt()<<" "<<gDay()<<", "<<gYear()<<endl;
    cout<<"Format 3: "<<gDay()<<" "+gMonTxt()<<" "<<gYear()<<endl;
}