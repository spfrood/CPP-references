
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 9, 2017, 4:00 PM
 * Purpose: 2. Day of the Year
Assuming that a year has 365 days, write a class named DayOfYear that takes an 
integer representing a day of the year and translates it to a string consisting 
of the month followed by day of the month. For example,
Day 2 would be January 2.
Day 32 would be February 1. 
Day 365 would be December 31.
The constructor for the class should take as parameter an integer representing 
the day of the year, and the class should have a member function print() that 
prints the day in the month–day format. The class should have an integer member 
variable to represent the day and should have static member variables holding 
string objects that can be used to assist in the translation from the integer 
format to the month-day format.
Test your class by inputting various integers representing days and printing out 
their representation in the month–day format.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "DayYear.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short number;
    
    //Input Values
    cout<<"Enter a number from 1 to 365"<<endl;
    cin>>number; //input number to convert to day
    while (cin.fail() || number<1 || number>365) {
        cout<<"Error! Enter correct input!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>number;
    }
    
    //Process by mapping inputs to outputs
    DayYear date(number); //create object 
    
    
    //Output values
    cout<<date.print()<<endl; //output conversion
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

