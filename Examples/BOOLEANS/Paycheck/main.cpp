
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Calculate gross paycheck amount
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
    float hrsWrkd, //Hours worked in (hrs)
          payRate, //Pay rate in $'s/hr
          payChck; //Pay check amount in $'s
    
    //Input Values
    cout<<"This program calculates your paycheck"<<endl;
    cout<<"Your hours worked and rate of pay are required"<<endl;
    cout<<"Input your hours worked in hours"<<endl;
    cin>>hrsWrkd;
    cout<<"Input your pay rate in $'s per hour (dollars per hour)"<<endl;
    cin>>payRate;
    
    
    //Process by mapping inputs to outputs
    payChck=payRate*hrsWrkd;
            
    //Output values
    cout<<"Your paycheck = $"<<payChck<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

