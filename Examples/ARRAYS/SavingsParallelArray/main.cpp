
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 1st, 2017 10:35 AM
 * Purpose: Calculate bank savings per year
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
void savings(int [],float [],float,float,int);
void prntAry(int [],float [],int);


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=100;
    int nYears=SIZE/2+1;
    int year[SIZE]={}; //Initialize entire array to 0
    float balance[SIZE]={};
    
    //Input Values
    float intRate=0.06f;
    float gift=2.0e4f;
    
    //Process by mapping inputs to outputs
    savings(year,balance,gift,intRate,nYears);
    
    //Output values
    prntAry(year,balance,nYears);
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void prntAry(int year[],float balance[],int n){
    cout<<"Year  Balance"<<endl;
    for(int i=0;i<n;i++){
        cout<<setprecision(2)<<fixed;
        cout<<setw(3)<<year[i]<<" $ "<<right<<setw(11)<<balance[i]<<endl;
    }
}


void savings(int y[],float b[],float p,float intRate,int nYears){
    y[0]=0;
    b[0]=p;
    //Loop each year to fill the array
    for(int year=1;year<nYears;year++){
        y[year]=year;
        b[year]=b[year-1]*(1+intRate);
    }
}