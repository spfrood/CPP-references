/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 23, 2017, 11:00 AM
 * Purpose:  6)  Just another sequence, 
 * 
 * sum = x - x^3/3! + x^5/5! - x^7/7! + ............
 * 
 * Input x and the number of terms=n, output the result.
 * Note:  x^1 = x,   x^2 = x*x,  x^3 = x*x*x
 *        3! = 1*2*3  5!=1*2*3*4*5
 * 
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int nTerms=0;
    float valX=0.0, result=0.0, fact=1.0;
    
    //Input values
    cout<<"Calculate a factorial based on a chosen number of terms and"<<endl;
    cout<<"a chosen value for X"<<endl;
    cout<<"Input the number of Terms"<<endl;
    cin>>nTerms;
    cout<<"Input the value of X"<<endl;
    cin>>valX;
    
    //Process by mapping inputs to outputs
    for (int itraton=1; itraton<=nTerms; itraton++){
        for (int clcFact=1; clcFact<=(itraton+2); clcFact++){
            fact = fact*clcFact;
            cout<<"fact "<<fact<<endl;
        }
        result+= valX-(pow(valX,itraton+2)/fact);
        cout<<"result "<<result<<endl;
    }
    
    //Output values
    cout<<"The factorial result is: "<<result<<endl;
    //Exit stage right!
    return 0;
}

