/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on February 1st, 2017, 10:35 PM
  Purpose:  Calculate Retirement with vectors
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void  savings(vector<int> &,vector<float> &,float,float,float,int);
void  prntAry(vector<int> &,vector<float> &,int);
void  find(vector<int> &,vector<float> &,int,int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=144;
    int nYears=SIZE/2+1;
    vector<int> year(SIZE);//Initialize the entire array to 0
    vector<float> balance(SIZE);
    
    //Input values
    float intRate=0.06f;
    float gift=2.0e4f;
    float salary=1.2e5f;
    float percSav=0.15f;
    
    //Process by mapping inputs to outputs
    float savReq=salary/intRate;
    float yDep=percSav*salary;
    savings(year,balance,gift,intRate,yDep,nYears);
    
    //Output values
    cout<<"Our Salary = $"<<salary<<endl;
    cout<<"Yearly Savings Deposit = $"<<yDep<<endl;
    cout<<"Savings goal = $"<<savReq<<endl;
    prntAry(year,balance,nYears);
    int val=50;
    find(year,balance,nYears,val);

    //Exit stage right!
    return 0;
}

void  find(vector<int> &year,vector<float> &balance,int n,int val){
    for(int i=1;i<=n;i++){
        if(year[i]==val){
            cout<<"Found val = "<<val<<" where balance = $"<<balance[i]<<endl;
        }
    }
}

void  prntAry(vector<int> &year,vector<float> &balance,int n){
    cout<<"Year   Balance"<<endl;
    cout<<fixed<<setprecision(2);
    for(int i=0;i<n;i++){
        cout<<setw(3)<<year[i]<<"  $"<<setw(11)<<balance[i]<<endl;
    }
    cout<<endl;
}


void  savings(vector<int> &y,vector<float> &b,float p,float intRate,float yDep,int nYears){
    //Initialize the array
    y[0]=0;
    b[0]=p;
    //Loop each year to fill the array
    for(int year=1;year<nYears;year++){
        y[year]=year;
        b[year]=b[year-1]*(1+intRate);
        b[year]+=yDep;
    }
}