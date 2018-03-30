/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 30, 2017, 10:34 AM
  Purpose:  Sin Series
 
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
float myWay(float,int);
float yourWay(float,int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    int nTerms;//Number of terms in the series
    float x;//Value in the series
    float myRes;//My result
    float yourRes;//Your Result
    
    //Input values
    cout<<"Calculate a series"<<endl;
    cout<<"Input 2 terms"<<endl;
    cout<<"The value and number of terms"<<endl;
    cin>>x>>nTerms;
    
    //Process by mapping inputs to outputs
    myRes=myWay(x,nTerms);
    yourRes=yourWay(x,nTerms);
    
    //Output values
    cout<<"My Res = "<<myRes<<" compared to exact result = "<<sin(x)<<endl;
    cout<<"Your Res = "<<yourRes<<" compared to exact result = "<<sin(x)<<endl;

    //Exit stage right!
    return 0;
}

float yourWay(float x,int nTerms){
    //Declare an initialize
    float series=x;
    int sign=1;
    
    //Series for loop
    for(int cnt=2,n=3;cnt<=nTerms;cnt++,n+=2){
        //Calculate the factorial
        int fact=1;
        for(int i=1;i<=n;i++){
            fact*=i;
        }
        //Calculate the series
        sign*=-1;
        series+=(sign*pow(x,n)/fact);
    }
    return series;
}

float myWay(float rad,int nTerms){
    //Declare Variable
    float sin=rad,delta=rad;
    //Loop for the series
    for(int cnt=2,fact=3;cnt<=nTerms;cnt++,fact+=2){
        delta*=-rad*rad/(fact*(fact-1));//-x^2/(i*(i-1))
        sin+=delta;
    }
    return sin;
}