/* 
  File:   main.cpp
  Author: Scott Parker
  Created on February 1, 2017, 9:45 PM
  Purpose:  10. Future Value
Suppose you have a certain amount of money in a savings account that earns 
compound monthly interest, and you want to calculate the amount that you will 
have after a specific number of months. The formula, which is known as the 
future value formula, is:
 * FV = PV * (1 + i)^t
The terms in the formula are as follows:
• F is the future value of the account after the specified time period.
• P is the present value of the account.
• i is the monthly interest rate.
• t is the number of months.
Write a program that prompts the user to enter the account’s present value, 
monthly interest rate, and the number of months that the money will be left 
in the account. The program should pass these values to a function named 
futureValue that returns the future value of the account, after the specified 
number of months. The program should display the account’s future value.
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
float futValu(float,float,int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float presVal,iRate,iRatPer;
    int nMonth;
    
    //Input values
    cout<<"Please enter your present value:"<<endl;
    cin>>presVal;
    cout<<"Please enter the monthly interest rate (percentage):"<<endl;
    cin>>iRatPer;
    iRate=iRatPer*0.01;
    cout<<"Please enter the number of months this will compound:"<<endl;
    cin>>nMonth;
 
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"If you deposit : $"<<setprecision(2)<<fixed<<showpoint
            <<presVal<<" right now"<<endl;
    cout<<"you will have $"<<setprecision(2)<<fixed<<showpoint<<futValu(presVal,iRate,nMonth)
            <<" after "<<nMonth<<" months at "<<iRatPer<<"% interest."<<endl;

    //Exit stage right!
    return 0;
}

float futValu(float value,float intRate,int months){
    //Formula is FV = PV * (1 + i)^t
    return (value*(pow((1+intRate),months)));
}
