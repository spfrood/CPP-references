/* 
  File:   main.cpp
  Author: Scotyt Parker
  Created on February 1, 2017, 8:32 PM
  Purpose:  9. Present Value
Suppose you want to deposit a certain amount of money into a savings account 
and then leave it alone to draw interest for the next 10 years. At the end 
of 10 years you would like to have $10,000 in the account. How much do you 
need to deposit today to make that happen? You can use the following formula, 
which is known as the present value formula, to find out:
 * P=F/(1+r)^n
The terms in the formula are as follows:
• P is the present value, or the amount that you need to deposit today.
• F is the future value that you want in the account. (In this case, F is 
     $10,000.)
• r is the annual interest rate.
• n is the number of years that you plan to let the money sit in the account.
Write a program that has a function named presentValue that performs this 
calculation. The function should accept the future value, annual interest 
rate, and number of years as arguments. It should return the present value, 
which is the amount that you need to deposit today. Demonstrate the function 
in a program that lets the user experiment with different values for the 
formula’s terms.
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
float prValue(float,float,int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float futrVal,iRate,iRatPer;
    int nYears;
    
    //Input values
    cout<<"Please enter your desired future savings value:"<<endl;
    cin>>futrVal;
    cout<<"Please enter the interest rate (percentage):"<<endl;
    cin>>iRatPer;
    iRate=iRatPer*0.01;
    cout<<"Please enter the number of years this will compound:"<<endl;
    cin>>nYears;
 
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"If you deposit : $"<<setprecision(2)<<fixed<<showpoint
            <<prValue(futrVal,iRate,nYears)<<" right now"<<endl;
    cout<<"you will have $"<<setprecision(2)<<fixed<<showpoint<<futrVal
            <<" after "<<nYears<<" years at "<<iRatPer<<"% interest."<<endl;

    //Exit stage right!
    return 0;
}

float prValue(float futVal,float intRate,int years){
    return (futVal/(pow((1+intRate),years)));
}
