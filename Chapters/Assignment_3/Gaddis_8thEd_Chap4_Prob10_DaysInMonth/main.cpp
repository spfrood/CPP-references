
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 12, 2017
 * Purpose: Display the number of days in a given month in a given year.
 * Correctly account for leap years with following info: 
 * If year/100 and year/400 then leap year. Else, if !year/100 then year/4 
 * is a leap year. 2000 is leap, 2100, 2200, 2300 are not, 2400 is a leap.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int month, year, days;
    
    //Input Values
    cout<<"Enter a month as a number from 1-12: ";
    cin>>month;
    cout<<"Enter a year: ";
    cin>>year;
    
    //Process by mapping inputs to outputs
    days =  (month == 1)?31:
            (month == 3)?31:
            (month == 5)?31:
            (month == 7)?31:
            (month == 8)?31:
            (month == 10)?31:
            (month == 12)?31:
            (month == 4)?30:
            (month == 6)?30:
            (month == 9)?30:
            (month == 11)?30:
            (!(year % 100)&&!(year % 400))?29:
            (!(year % 100)&&!(year % 400))&&(!(year % 4))?29:28;
    
    
    //Output values
    cout<<"That month had "<<days<<" days"<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

