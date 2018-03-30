
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 30, 2017, 11:35 AM
 * Purpose: Calculate Sin Series
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
float lehrWay(float, int);
float stdtWay(float, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int nTerms; //Number of terms in series
    float x; //value in the series
    float myRes; //Lehr's result
    float sdntRes; //Student method result
    
    //Input Values
    cout<<"Calculate a series"<<endl;
    cout<<"Input 2 terms"<<endl;
    cout<<"The value and number of terms"<<endl;
    cin>>x>>nTerms;
    
    //Process by mapping inputs to outputs
    myRes=lehrWay(x,nTerms);
    sdntRes=stdtWay(x,nTerms);
    //Output values
    cout<<"Lehr Result  = "<<myRes<<" compared to exact result = "<<sin(x)<<endl;
    cout<<"Stdnt Result = "<<sdntRes<<" compared to exact result = "<<sin(x)<<endl;
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

// Calculate student's way
float stdtWay(float x, int nTerms){
    //Declare and intialize
    float series=x;
    int sign=1;
    
    //Series for loop
    for(int cnt=2,n=3;cnt<=nTerms;cnt++,n+=2){
        //calculate the factorial
        int fact=1;
        for (int i=1;i<=n;i++){
            fact*=i;
        }
        //calculate the series
        sign*=-1;
        series+=(sign*pow(x,n)/fact);
    }
    return series;
}




//Function to calculate SIN Lehr's way
float lehrWay(float rad,int nTerms){
    //Declare variable
    float sin=rad,delta=rad;
    //Loop for the series
    for (int cnt=2,fact=3;cnt<=nTerms;cnt++,fact+=2){
        delta*=-rad*rad/(fact*(fact-1));//-x^2/(i*(i-1))
        sin+=delta; 
        
    }
    return sin;
}
