/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 31, 2017, 10:55 AM
  Purpose:  Savings Function
 
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
float save1(float,float,int);
float save2(float,float,int);
float save3(float,float,int);
float save4(float,float,int);
float save5(float,float,int=8);
float save1(float,float,float);
float save6(float,float,int,int &);
float save7(float,float,int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float pv,iRate;
    int nPeriod;
    
    //Input values
    pv=100.0f;//Dollars
    iRate=0.09f;//percent
    nPeriod=0.72/iRate+0.5;//Number of Compounding periods
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"Present value = $"<<pv<<endl;
    cout<<"Interest rate = "<<iRate*100<<"%"<<endl;
    cout<<"Number of Compounding Periods = "<<nPeriod<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Savings 1 = $"<<save1(pv,iRate,nPeriod)<<endl;
    cout<<"Savings 2 = $"<<save2(pv,iRate,nPeriod)<<endl;
    cout<<"Savings 3 = $"<<save3(pv,iRate,nPeriod)<<endl;
    cout<<"Savings 4 = $"<<save4(pv,iRate,nPeriod)<<endl;
    cout<<"Savings 5 = $"<<save5(pv,iRate)<<endl;
    cout<<"Savings 1 float = $"<<save1(pv,iRate,static_cast<float>(nPeriod))<<endl;
    int nCalls=-100;
    for(int j=1;j<=5;j++)save6(pv,iRate,nPeriod,nCalls);
    cout<<"Savings 6 = $"<<save6(pv,iRate,nPeriod,nCalls)<<endl;
    cout<<"How many times was Savings 6 called = "<<nCalls<<endl;
    cout<<"Savings 7 = $"<<save7(pv,iRate,nPeriod)<<endl;

    //Exit stage right!
    return 0;
}

float save7(float p,float i,int n){
    float fv=p;
    for(int year=1;year<=n;year++){
        fv*=(1+i);
        int ifv=fv*100;//no fractional pennies
        fv=ifv/100.0f;
    }
    return fv;
}

float save6(float p,float i,int n,int &nCalls){
    static int test=0;
    nCalls=++test;
    return p*pow(1+i,n);
}

float save1(float p,float i,float n){
    //cout<<"I am the floater"<<endl;
    return p*pow(1+i,n);
}

float save5(float p,float i,int n){
    if(n<=0)return p;
    return save4(p,i,n-1)*(1+i);
}

float save4(float p,float i,int n){
    if(n<=0)return p;
    return save4(p,i,n-1)*(1+i);
}

float save3(float p,float i,int n){
    float fv=p;
    for(int year=1;year<=n;year++){
        fv*=(1+i);
    }
    return fv;
}

float save2(float p,float i,int n){
    return p*exp(n*log(1+i));
}

float save1(float p,float i,int n){
    return p*pow(1+i,n);
}