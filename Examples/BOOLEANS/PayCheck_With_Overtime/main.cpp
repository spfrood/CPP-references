
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 11, 2017
 * Purpose: Calculate a paycheck with optional overtime
 *          using conditional statements
 */

//System Libraries
#include <iostream>
#include <iomanip>
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
    float payChck, payTwo, hours, rate;
    
    //Input Values
    cout<<"Input the hours did you work this week:"<<endl;
    cin>>hours;
    cout<<"Please input your rate of pay per hour:"<<endl;
    cin>>rate;
    
    //Process by mapping inputs to outputs
    //if more than 40 hours then double time for the additional
    //hours (Double the rate)
    payChck = (hours<=40?hours*rate:((40*rate)+((hours-40)*2*rate)));
    
    if (hours>40)
    {
        payTwo = (40*rate)+(((hours-40)*2*rate));
    }
    else
    {
        payTwo = hours*rate;
    }
    
    //Output values
    
    cout<<setprecision(2)<<fixed;
    cout<<"Your Total Pay is: $"<<payChck;  //calcualted with ? : if else
    cout<<endl;
    cout<<"Your Total Pay is: $"<<payTwo;   //using if else code blocks
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

