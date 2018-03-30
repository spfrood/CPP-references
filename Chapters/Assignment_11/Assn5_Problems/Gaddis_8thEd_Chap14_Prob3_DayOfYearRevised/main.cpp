
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 9, 2017, 4:00 PM
 * Purpose: 3. Day of the Year Modification
Modify the DayOfYear class, written in Programming Challenge 2, to add a 
constructor that takes two parameters: a string object representing a month and 
an integer in the range 0 through 31 representing the day of the month. The 
constructor should then initialize the integer member of the class to represent 
the day specified by the month and day of month parameters. The constructor 
should terminate the program with an appropriate error message if the number 
entered for a day is outside the range of days for the month given. Add the 
following overloaded operators:
++ prefix and postfix increment operators. 
    These operators should modify the DayOfYear object so that it represents the 
    next day. If the day is already the end of the year, the new value of the 
    object will represent the first day of the year.
−− prefix and postfix decrement operators. 
    These operators should modify the DayOfYear object so that it represents the 
    previous day. If the day is already the first day of the year, the new value 
    of the object will represent the last day of the year.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "DayYer2.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short day;
    string month="";
    
    //Input Values
    cout<<"Enter the month (January, February, etc):"<<endl;
    getline(cin, month);
    cout<<"Enter the day of the month:"<<endl;
    cin>>day; //input number to convert to day
    while (cin.fail()) {
        cout<<"Error! Enter a positive number!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>day;
    }
    
    //Process by mapping inputs to outputs
    DayYer2 date(month, day); //create object 
    if (!date.getValid()) {
        cout<<date.pStatus()<<endl;
        cout<<date.pMonDay()<<endl;
        exit(0);
    }
    
    //Output values
    cout<<"That is day: "<<date.pStatus()<<endl;
    cout<<"Date is: "<<date.pMonDay()<<endl<<endl;
    date++;
    cout<<"After date++ number: "<<date.pStatus()<<endl;
    cout<<"After date++ is: "<<date.pMonDay()<<endl<<endl;
    ++date; 
    cout<<"After ++date number: "<<date.pStatus()<<endl;
    cout<<"After ++date is: "<<date.pMonDay()<<endl<<endl;
    date--;
    cout<<"After date-- number: "<<date.pStatus()<<endl;
    cout<<"After date-- is: "<<date.pMonDay()<<endl<<endl;
    --date; 
    cout<<"After --date number: "<<date.pStatus()<<endl;
    cout<<"After --date is: "<<date.pMonDay()<<endl<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

