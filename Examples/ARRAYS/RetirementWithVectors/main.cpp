
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 1st, 2017 10:35 AM
 * Purpose: Calculate monthly savings deposit needed for retirement 
 *          savings monthly deposit as a percentage of salary 
 *          USING VECTORS
 *          Dropping in vectors from the previous RetirementWithArray
 *          program we made.
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void savings(vector<int> &,vector<float> &,float,float, float,int);
void prntAry(vector<int> &,vector<float> &,int);
void find(vector<int> &,vector<float> &,int,int);


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=100;
    int nYears=SIZE/2+1;
    vector<int> year(SIZE); //Initialize entire array to 0
    vector<float> balance(SIZE);
    
    //Input Values
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
    cout<<"Our yearly deposit = $"<<setprecision(2)<<fixed<<showpoint<<yDep<<endl;
    cout<<"Our savings goal = $"<<setprecision(2)<<fixed<<showpoint<<savReq<<endl;
    prntAry(year,balance,nYears);
    int val=47;
    find(year,balance,nYears,val);
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void find(vector<int> &year,vector<float> &balance,int n,int val){
    for (int i=1;i<=n;i++){
        if (year[i]==val){
            cout<<"Found val = "<<val<<" where balance = $"<<balance[i]<<endl;
        }
    }
}

void prntAry(vector<int> &year,vector<float> &balance,int n){
    cout<<"Year  Balance"<<endl;
    for(int i=0;i<n;i++){
        cout<<setprecision(2)<<fixed;
        cout<<setw(3)<<year[i]<<" $ "<<right<<setw(15)<<balance[i]<<endl;
    }
}


void savings(vector<int> &y,vector<float> &b,float p,float intRate,float yDep,int nYears){
    y[0]=0;
    b[0]=p;
    //Loop each year to fill the array
    for(int year=1;year<nYears;year++){
        y[year]=year;
        b[year]=b[year-1]*(1+intRate);
        b[year]+=yDep;
    }
}