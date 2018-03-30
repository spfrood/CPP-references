
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 10:20 PM
 * Purpose: Gaddis, 8th Edition, Chapter 5, Problem 4, Calories Burned
 * Running on a particular treadmill you burn 3.6 calories per minute. Write
 * a program that uses a loop to display the number of calories burned after 
 * 5, 10, 15, 20, 25, and 30 minutes.
 * 
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
    float calBurn = 0; //initializing ocean level at 0mm
    
    //Input Values
    for (int minutes = 0; minutes <= 30; minutes++) {
        calBurn = minutes * 3.6;
        if ((minutes % 5)==0) cout<<"You have burned "<<calBurn<<" calories "
                "after running for "<<minutes<<" minutes."<<endl;
                
    }
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

