/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MthCls7.cpp
 * Author: Scott Parker
 * 
 * Created on May 10, 2017, 11:25 AM
 */

#include "MthCls7.h"

//Constructors
MthCls7::MthCls7() {
    mName="January"; 
    mNumber=1;
}

MthCls7::MthCls7(string month){
    setData(month);
}

MthCls7::MthCls7(int month){
    setData(month);
}

//Setters & Mutators
//setter for integer type input
void MthCls7::setData () {
    if (mNumber==1) {
        mName="January";
    } else if (mNumber==2) {
        mName="February";
    } else if (mNumber==3) {
        mName="March";
    } else if (mNumber==4) {
        mName="April";
    } else if (mNumber==5) {
        mName="May";
    } else if (mNumber==6) {
        mName="June";
    } else if (mNumber==7) {
        mName="July";
    } else if (mNumber==8) {
        mName="August";
    } else if (mNumber==9) {
        mName="September";
    } else if (mNumber==10) {
        mName="October";
    } else if (mNumber==11) {
        mName="November";
    } else if (mNumber==12) {
        mName="December";
    } else {
        mName="ERROR! SOMETHING BROKE!";
    }
}

void MthCls7::setData (string month) { 
    if (month=="January" || month=="Jan" || month=="january" || month=="jan") {
        mName="January";
        mNumber=1;
    } else if (month=="February" || month=="Feb" || month=="february" || month=="feb") {
        mName="February";
        mNumber=2;
    } else if (month=="March" || month=="Mar" || month=="march" || month=="mar") {
        mName="March";
        mNumber=3;
    } else if (month=="April" || month=="Apr" || month=="april" || month=="apr") {
        mName="April";
        mNumber=4;
    } else if (month=="May" || month=="may") {
        mName="May";
        mNumber=5;
    } else if (month=="June" || month=="Jun" || month=="june" || month=="jun") {
        mName="June";
        mNumber=6;
    } else if (month=="July" || month=="Jul" || month=="july" || month=="jul") {
        mName="July";
        mNumber=7;
    } else if (month=="August" || month=="Aug" || month=="august" || month=="aug") {
        mName="August";
        mNumber=8;
    } else if (month=="September" || month=="Sept" || month=="september" || month=="sept" || month=="Sep" || month=="sep") {
        mName="September";
        mNumber=9;
    } else if (month=="October" || month=="Oct" || month=="october" || month=="oct") {
        mName="October";
        mNumber=10;
    } else if (month=="November" || month=="Nov" || month=="november" || month=="nov") {
        mName="November";
        mNumber=11;
    } else if (month=="December" || month=="Dec" || month=="december" || month=="dec") {
        mName="December";
        mNumber=12;
    } else {
        mName="ERROR! INVALID DATA ENTERED!";
    }
}

//setter for integer type input
void MthCls7::setData (int month) {
    if (month==1) {
        mName="January";
        mNumber=1;
    } else if (month==2) {
        mName="February";
        mNumber=2;
    } else if (month==3) {
        mName="March";
        mNumber=3;
    } else if (month==4) {
        mName="April";
        mNumber=4;
    } else if (month==5) {
        mName="May";
        mNumber=5;
    } else if (month==6) {
        mName="June";
        mNumber=6;
    } else if (month==7) {
        mName="July";
        mNumber=7;
    } else if (month==8) {
        mName="August";
        mNumber=8;
    } else if (month==9) {
        mName="September";
        mNumber=9;
    } else if (month==10) {
        mName="October";
        mNumber=10;
    } else if (month==11) {
        mName="November";
        mNumber=11;
    } else if (month==12) {
        mName="December";
        mNumber=12;
    } else {
        mName="ERROR! INVALID DATA ENTERED!";
        mNumber=month;
    }
}

//Data checker
bool MthCls7::badTxt(string mText) {
    bool retVal=true;
    if (mText=="January" || mText=="Jan" || mText=="january" || mText=="jan") {
        retVal=false;
    } else if (mText=="February" || mText=="Feb" || mText=="february" || mText=="feb") {
        retVal=false;
    } else if (mText=="March" || mText=="Mar" || mText=="march" || mText=="mar") {
        retVal=false;
    } else if (mText=="April" || mText=="Apr" || mText=="april" || mText=="apr") {
        retVal=false;
    } else if (mText=="May" || mText=="may") {
        retVal=false;
    } else if (mText=="June" || mText=="Jun" || mText=="june" || mText=="jun") {
        retVal=false;
    } else if (mText=="July" || mText=="Jul" || mText=="july" || mText=="jul") {
        retVal=false;
    } else if (mText=="August" || mText=="Aug" || mText=="august" || mText=="aug") {
        retVal=false;
    } else if (mText=="September" || mText=="Sept" || mText=="september" || mText=="sept" || mText=="Sep" || mText=="sep") {
        retVal=false;
    } else if (mText=="October" || mText=="Oct" || mText=="october" || mText=="oct") {
        retVal=false;
    } else if (mText=="November" || mText=="Nov" || mText=="november" || mText=="nov") {
        retVal=false;
    } else if (mText=="December" || mText=="Dec" || mText=="december" || mText=="dec") {
        retVal=false;
    } else {
        retVal=true;
    }
    return retVal;
}
    
//Getters
string MthCls7::getName () const {
    return mName;
}

int MthCls7::getNumb () const {
    return mNumber;
}

//Operator overloads
//prefix operator ++ overload
MthCls7 MthCls7::operator ++ ()
{
    ++mNumber;
    if (mNumber>12) {
        mNumber=1;
    }
    setData(mNumber);
    return *this;
}

//postfix operator ++ overload
MthCls7 MthCls7::operator ++ (int)
{
    MthCls7 temp(mNumber);
    
    mNumber++;
    if (mNumber>12) {
        mNumber=1;
    }
    setData(mNumber);
    return temp;

}

//prefix operator -- overload
MthCls7 MthCls7::operator -- ()
{
    --mNumber;
    if (mNumber<1) {
        mNumber=12;
    }
    setData(mNumber);
    return *this;
}

//postfix operator -- overload
MthCls7 MthCls7::operator -- (int)
{
    MthCls7 temp(mNumber);
    
    mNumber--;
    if (mNumber<1) {
        mNumber=12;
    }
    setData(mNumber);
    return temp;
}

// Friends operator overloads
// Overloaded << operator for direct use with cout
ostream &operator<<(ostream &strm, const MthCls7 &obj)
{
    strm << obj.getName() << " is month number: " << obj.getNumb();
    return strm;
}

// Overloaded >> operator for direct use with cin
istream &operator >> (istream &strm, MthCls7 &obj)
{
    // Prompt the user for the month.
    cout << "Enter the number of the month (1-12): "<<endl;
    strm >> obj.mNumber;

    // Set all the values.
    obj.setData();
    
    return strm;
}