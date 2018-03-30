/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 3, 2017, 12:15 PM
  Purpose:  Calculate the paycheck
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float hrsWrkd,//Hours worked in (hrs)
          payRate,//Pay rate in $'s/hr
          payChck;//Pay check in $'s
    
    //Input values
    cout<<"This program calculates your Paycheck"<<endl;
    cout<<"Your hours worked and pay rate are required"<<endl;
    cout<<"Input your hours worked in hours"<<endl;
    cin>>hrsWrkd;
    cout<<"Input your pay rate in $'s/hr"<<endl;
    cin>>payRate;
    
    //Process by mapping inputs to outputs
    payChck=payRate*hrsWrkd;
    
    //Output values
    cout<<"Your paycheck = $"<<payChck<<endl;

    //Exit stage right!
    return 0;
}