/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 3, 2017, 12:15 PM
  Purpose:  Penny Doubling for Salary and pay
            31 days good for using integers
 */

//System Libraries
#include <iostream>//Input output library
#include <cmath>   //Math library for the power
#include <iomanip> //Formatting Library
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
    int salary=1,totPay=0,maxDays=31;//Salary and Pay in pennies
    
    //Process by mapping inputs to outputs
    for(int day=1;day<=maxDays;day++,salary*=2){//Multiply salary by 2
        int cents=salary%100;//Last 2 digits for pennies
        int dollars=(salary-cents)/100;//2 digits less for dollars
        //Format the output for dollars and cents
        cout<<"Salary for day "<<day<<" = $"<<dollars<<"."
                <<(cents<10?'0':'\0')<<cents<<endl;
        totPay+=salary;//Sum the salary
        cents=totPay%100;
        dollars=(totPay-cents)/100;
        cout<<"Total Pay for day "<<day<<" = $"<<dollars<<"."
                <<(cents<10?'0':'\0')<<cents<<endl<<endl;
    }
    //Predicting the result
    double salLDay=(pow(2,maxDays-1))/100;//Results in dollars
    double totLDay=(pow(2,maxDays)-1)/100;//Results in dollars
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Final Salary predicted = $"<<salLDay<<endl;
    cout<<"Final Total Pay predicted = $"<<totLDay<<endl;
    
    //Exit stage right!
    return 0;
}