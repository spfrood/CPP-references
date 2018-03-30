
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 1:00 PM
 * Purpose: 1. Largest/Smallest Array Values
 * Write a program that lets the user enter 10 values into an array. The 
 * program should then display the largest and smallest values stored in 
 * the array.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int const SIZE=20;
    int cntAray [20]={};
    int lowest;
    int highest;
    int lowTie=1;
    int highTie=1;
    
    //Input Values
    cout<<"Input 20 values... "<<endl;
    for (int i=0;i<20;i++){
        cin>>cntAray[i];
    }
    
    //Process by mapping inputs to output
    lowest=cntAray[0];
    highest=cntAray[0];
    for (int i=1;i<20;i++){
        if (cntAray[i]<lowest){
            lowest=cntAray[i];
            lowTie=1;
        } else if (cntAray[i]==lowest){
            lowTie++;
        }
        if (cntAray[i]>highest){
            highest=cntAray[i];
            highTie=1;
        } else if (cntAray[i]==highest){
            highTie++;
        }
    }
    
    //Output values
    cout<<"The lowest value entered was "<<lowest<<endl;
    if (lowTie>1)
        cout<<"     There were "<<lowTie<<" numbers with this value."<<endl;
    cout<<"The highest value entered was "<<highest<<endl;
    if (highTie>1)
        cout<<"     There were "<<highTie<<" numbers with this value."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

