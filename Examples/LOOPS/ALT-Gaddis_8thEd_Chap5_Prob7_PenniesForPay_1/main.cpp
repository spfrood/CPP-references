
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 11:08 PM
 * Purpose: Gaddis, 8th Edition, Chapter 5, Problem 7, Pennies for Pay
 * calculating salary penny a day doubled for 31 days
 */

//System Libraries
#include <iostream> //input output library
#include <iomanip> //formatting library
#include <cmath> //math library for power

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
    int salary = 1, totPay = 0, maxDays = 31; //salary and pay in pennies
    
    cout<<"Pay for Day      Total Salary"<<endl;
    cout<<"-----------------------------"<<endl;
    //Process by mapping inputs to outputs
    for (int day=1; day<=maxDays; day++, salary*=2) {
int cents = salary%100; //last 2 digits for cents
        int dollars = (salary-cents)/100; //2 digits less for dollars
        totPay+=salary; //sum the salary
        cout<<day<<" $"<<left<<dollars<<"."
                <<left<<(cents<10?'0':'\0')<<cents;
        cents = totPay%100;
        dollars=(totPay-cents)/100;
        cout<<"      $"<<dollars<<"."
                <<(cents<10?'0':'\0')<<cents<<endl;
    }
    
    //Predicting the result
    double salLDay=(pow(2,maxDays-1))/100; //Results in dollars
    double totLDay=(pow(2,maxDays)-1)/100; //Results in dollars
    cout<<endl<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Predictions"<<endl;
    cout<<"Final Salary ------------- Total Pay"<<endl;
    cout<<"$"<<salLDay<<"         $"<<totLDay<<endl;
    
    //Output Values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

