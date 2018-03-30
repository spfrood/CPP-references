
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 10, 2017, 11:21 AM
 * Purpose: 7. Month Class
Design a class named Month . The class should have the following private members:
• name A string object that holds the name of a month, such as “January,”
“February,” etc.
• monthNumber An integer variable that holds the number of the month. For example,
January would be 1, February would be 2, etc. Valid values for this variable are
1 through 12.
In addition, provide the following member functions:
• A default constructor that sets monthNumber to 1 and name to “January.”
• A constructor that accepts the name of the month as an argument. It should set name
to the value passed as the argument and set monthNumber to the correct value.
• A constructor that accepts the number of the month as an argument. It should set
monthNumber to the value passed as the argument and set name to the correct month
name.
• Appropriate set and get functions for the name and monthNumber member variables.
• Prefix and postfix overloaded ++ operator functions that increment monthNumber
and set name to the name of next month. If monthNumber is set to 12 when these
functions execute, they should set monthNumber to 1 and name to “January.”
• Prefix and postfix overloaded −− operator functions that decrement monthNumber
and set name to the name of previous month. If monthNumber is set to 1 when these
functions execute, they should set monthNumber to 12 and name to “December.”
Also, you should overload cout ’s << operator and cin ’s >> operator to work with the
Month class. Demonstrate the class in a program.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "MthCls7.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes
bool badTxt(string); //function to determine if text input is a month name


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int mNum=0;
    string mName="";
    MthCls7 month;
    
    //Input values
    cout<<"Enter the month as a value from 1 to 12: "<<endl;
    cin>>mNum;
    while (cin.fail() || mNum<1 || mNum>12) {
        cout<<"Error! Enter a number from 1 - 12!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>mNum;
    }
    
    cout<<"Enter the month as a text value (January, February, etc):"<<endl;
    cin.ignore(256, '\n');
    getline(cin, mName);
    while (badTxt(mName)) {
        cout<<"Not a month! Try again!"<<endl;
        cin.clear();
//        cin.ignore(256, '\n');
        getline(cin, mName);
    }
    
    //Process by mapping inputs to outputs
    cout<<"Setting month info using the integer "<<mNum<<" as the month."<<endl;
    month.setData(mNum); //Set class data with the month integer input earlier
    cout<<month<<endl; //output with overloaded cout
    cout<<"Incrementing with month++"<<endl;
    month++; //test month++ overload * 
    cout<<month<<endl;
    cout<<"Incrementing with ++month"<<endl;
    ++month; //test ++month overload
    cout<<month<<endl;
    cout<<"Decrementing with month--"<<endl;
    month--;
    cout<<month<<endl;
    cout<<"Decrementing with --month"<<endl;
    --month;
    cout<<month<<endl<<endl;
    cout<<"Resetting values with the input: "<<mName<<" input as a text value."<<endl;
    month.setData(mName);
    cout<<month<<endl;
    cout<<"Incrementing with month++"<<endl;
    month++;
    cout<<month<<endl;
    cout<<"Incrementing with ++month"<<endl;
    ++month;
    cout<<month<<endl;
    cout<<"Decrementing with month--"<<endl;
    month--;
    cout<<month<<endl;
    cout<<"Decrementing with --month"<<endl;
    --month;
    cout<<month<<endl<<endl;
    
    cout<<"Enter the month using direct cin:"<<endl;
    cin>>month;
    while (cin.fail() || month.getNumb()<1 || month.getNumb()>12) {
        cout<<"Enter a month number from 1 to 12!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>month;
    }
    cout<<month<<endl;
    cout<<"Incrementing with month++"<<endl;
    cout<<month++<<endl;
    cout<<"Incrementing with ++month"<<endl;
    cout<<++month<<endl;
    cout<<"Decrementing with month--"<<endl;
    cout<<month--<<endl;
    cout<<"Decrementing with --month"<<endl;
    cout<<--month<<endl;
    cout<<"Outputting plain old month"<<endl;
    cout<<month<<endl;
    
    //Output values
    
    
    //Clean up memory
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

bool badTxt(string mText) {
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