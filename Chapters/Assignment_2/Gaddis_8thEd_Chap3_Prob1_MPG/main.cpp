
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 9, 2017
 * Purpose: Gaddis Chap 3 Prob 1 - Calculate MPG of a car 
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
    short gasUsed, mileDrv, mpg, lftOver; 
    
    //Input Values
    cout<<"How many gallons of gas did you use?"<<endl;
    cin>>gasUsed;
    cout<<"How many miles did you drive?"<<endl;
    cin>>mileDrv;
    
    //Process by mapping inputs to outputs
    mpg=mileDrv/gasUsed;  //Calculating miles per gallon of gas
    lftOver=mileDrv%gasUsed; //To display fractional MPG
    
    //Output values
    cout<<"You averaged "<<mpg<<"."<<lftOver<<" miles per gallon."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

