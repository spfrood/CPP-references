
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 2:06 PM
 * Purpose: 2. Rainfall Statistics
Write a program that lets the user enter the total rainfall for each of 12 
months into an array of doubles. The program should calculate and display the 
total rainfall for the year, the average monthly rainfall, and the months 
with the highest and lowest amounts.
Input Validation: Do not accept negative numbers for monthly rainfall figures.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int const SIZE=12;
    string mnthAry [SIZE]={"January", "February", "March", "April", "May", 
        "June", "July", "August", "September", "October", "November", "December"};
    float rainAry [SIZE]={};
    float lowest=0.000f, highest=0.000f, avgRain=0.0000f, totRain=0.0000f;
    string lowMon;
    string highMon;
    int lowTie=1;
    int highTie=1;
    
    //Input Values
    cout<<"Input the monthly rainfall amounts in inches... "<<endl;
    for (int i=0;i<12;i++){
        do{
        cout<<mnthAry[i]<<" rainfall was: ";
        cin>>rainAry[i];
        if (rainAry[i]<0) cout<<"Negative rainfall not possible! Re-enter month!"<<endl;
        } while (rainAry[i]<0);
    }
    
    //Process by mapping inputs to output
    lowest=rainAry[0];
    highest=rainAry[0];
    lowMon=mnthAry[0];
    highMon=mnthAry[0];
    for (int i=1;i<12;i++){
        if (rainAry[i]<lowest){
            lowest=rainAry[i];
            lowMon=mnthAry[i];
            lowTie=1;
        } 
        else if (rainAry[i]==lowest) {
            lowTie++;
        }
        if (rainAry[i]>highest){
            highest=rainAry[i];
            highMon=mnthAry[i];
            highTie=1;
        } else if (rainAry[i]==highest){
            highTie++;
        }
    }
    for (int i=0;i<12;i++){
        totRain+=rainAry[i];
    }
    avgRain=totRain/12;
    
    //Output values
    cout<<setprecision(2)<<fixed;
    cout<<"The lowest amount of rainfall was "<<lowest<<" inches in "<<lowMon<<"."<<endl;
    if (lowTie>1)
        cout<<"     There were "<<lowTie<<" months with this value."<<endl;
    cout<<"The highest amount of rainfall was "<<highest<<" inches in "<<highMon<<"."<<endl;
    if (highTie>1)
        cout<<"     There were "<<highTie<<" months with this value."<<endl;
    cout<<"The average rainfall for the year was "<<avgRain<<endl;
    cout<<"The total rainfall for the year was "<<totRain<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

