
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 1st, 2017 10:35 AM
 * Purpose: Calculate monthly savings deposit needed for retirement 
 *          savings monthly deposit as a percentage of salary 
 *          USING 2-D Array
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
//As well as multi-dimensional arrays
const int COLS=2;

//Function Prototypes
void  savings(float [][COLS],float,float,float,int);
void  prntAry(float [][COLS],int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=144;
    int nYears=SIZE/2+1;
    float balance[SIZE][COLS]={}; //Initialize the 2-D Array
    
    //Input Values
    float intRate=0.06f;
    float gift=2.0e4f;
    float salary=1.2e5f;
    float percSav=0.15f;
    
    //Process by mapping inputs to outputs
    float savReq=salary/intRate;
    float yDep=percSav*salary; //yearly deposit
    savings(balance,gift,intRate,yDep,nYears);
    
    //Output values
    cout<<"Our Salary = $"<<salary<<endl;
    cout<<"Yearly Savings Deposit = $"<<yDep<<endl;
    cout<<"Savings goal = $"<<savReq<<endl;
    prntAry(balance,nYears);
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}


void  prntAry(float balance[][COLS],int n){
    cout<<"Year   Balance"<<endl;
    cout<<fixed<<setprecision(2);
    for(int i=0;i<n;i++){
        cout<<setw(3)<<static_cast<int>(balance[i][0])<<"  $"<<setw(12)<<balance[i][1]<<endl;
    }
    cout<<endl;
}


void  savings(float b[][COLS],float p,float intRate,float yDep,int nYears){
    //initialize the array
    b[0][0]=0;//Year in column 1 which is index 0
    b[0][1]=p;//Balance in column 2 which is index 1
    //Loop each year to fill the array
    for(int year=1;year<nYears;year++){
        b[year][0]=year;
        b[year][1]=b[year-1][1]*(1+intRate);
        b[year][1]+=yDep;
    }
}

