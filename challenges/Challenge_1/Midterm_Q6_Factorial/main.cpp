
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 26, 2017, 2:40 PM
 * Purpose:  6)  Just another sequence, 
 * 
 * sum = x - x^3/3! + x^5/5! - x^7/7! + ............
 * 
 * Input x and the number of terms=n, output the result.
 * Note:  x^1 = x,   x^2 = x*x,  x^3 = x*x*x
 *        3! = 1*2*3  5!=1*2*3*4*5
 */

//System Libraries
#include <iostream>
#include <cmath>

using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int nTerms=0, facBase=3; //iterations and base number for factorials 
    float valX=0.0, fResult=0.0, fDenom=1.0, answer=0.0;//inputs and calculations
    
    //Input values for number of terms and value of X
    cout<<"Calculate a factorial based on a chosen number of terms and"<<endl;
    cout<<"a chosen value for X"<<endl;
    cout<<"Input the number of Terms"<<endl;
    cin>>nTerms;
    cout<<"Input the value of X"<<endl;
    cin>>valX;
    answer = valX;
    
    //Process by mapping inputs to outputs
    //Set up iteration 
        for (int iter=1; iter<=nTerms; iter++) {
            //Get the value of the factorial denominator for the iteration
            for (int calFact=1; calFact<=facBase; calFact++) {
               fDenom *= calFact;
            }
            //assign cumulative value of equation to fResult for total 
            //iterations so far
            fResult = (pow(-1,iter))*(pow(valX,facBase)/fDenom);
            answer += fResult;
            fDenom=1.0;
            facBase=facBase+2;
        }
    
    //Output values
    cout<<"The answer is: "<<answer<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

