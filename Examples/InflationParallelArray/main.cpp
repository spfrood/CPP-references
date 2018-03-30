/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on February 1st, 2017, 10:35 PM
  Purpose:  Calculate Inflation Rate
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void  savings(int [],float [],float,float,int);
void  prntAry(int [],float [],int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=102;
    int nYears=SIZE/2+1;
    int year[SIZE]={};//Initialize the entire array to 0
    float balance[SIZE]={};
    
    //Input values
    float infRate=0.065f;//Inflation Rate
    float item=10000.0f;
    
    //Process by mapping inputs to outputs
    savings(year,balance,item,infRate,nYears);
    
    //Output values
    prntAry(year,balance,nYears);

    //Exit stage right!
    return 0;
}

void  prntAry(int year[],float balance[],int n){
    cout<<"Year   Balance"<<endl;
    cout<<fixed<<setprecision(2);
    for(int i=0;i<n;i++){
        cout<<setw(3)<<year[i]<<"  $"<<setw(10)<<balance[i]<<endl;
    }
    cout<<endl;
}


void  savings(int y[],float b[],float p,float infRate,int nYears){
    //Initialize the array
    y[0]=0;
    b[0]=p;
    //Loop each year to fill the array
    for(int year=1;year<nYears;year++){
        y[year]=year;
        b[year]=b[year-1]*(1+infRate);
    }
}