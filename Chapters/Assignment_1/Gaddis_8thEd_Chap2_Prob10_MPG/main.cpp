
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 8, 2017
 * Purpose: Gaddis Chap 2 Prob 10 - Calculate MPG of a car 
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
    mpg=mileDrv/gasUsed;  
    lftOver=mileDrv%gasUsed;  //This returns odd values. Not sure why.
    
    //Output values
    cout<<"You averaged "<<mpg<<"."<<lftOver<<" miles per gallon."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

