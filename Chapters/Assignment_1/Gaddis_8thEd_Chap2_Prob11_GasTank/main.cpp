
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 8, 2017
 * Purpose: Gaddis Chap 2 Prob 11 - Distance traveled on a tank of gas
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    short tnkSize;
    float mpgCity, mpgHiwy, dstCity, dstHiwy;
    
    //Input Values
    cout<<"How many gallons of petrol does your tank hold?"<<endl;
    cin>>tnkSize;
    cout<<"What is the average city MPG of your car?"<<endl;
    cin>>mpgCity;
    cout<<"What is the average highway MPG of your car?"<<endl;
    cin>>mpgHiwy;
    
    //Process by mapping inputs to outputs
    dstCity=mpgCity*tnkSize;  //Calculating average city miles per tank
    dstHiwy=mpgHiwy*tnkSize;  //Calculating average highway miles per tank 
    
    //Output values
    cout<<"Your car will be able to drive "<<dstCity<<" city miles"<<endl;
    cout<<"     per "<<tnkSize<<" gallon tank of gas."<<endl;
    cout<<"Your car will be able to drive "<<dstHiwy<<" highway miles"<<endl;
    cout<<"     per "<<tnkSize<<" gallon tank of gas."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

