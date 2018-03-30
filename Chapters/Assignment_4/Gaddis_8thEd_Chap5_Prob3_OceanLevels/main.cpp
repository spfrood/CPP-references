
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 1:19 PM
 * Purpose: Gaddis, 8th Edition, Chapter 5, Problem 3, Ocean Levels
 * Assuming the ocean's level is currently rising at about 1.5 millimeters
 * per year, write a program that displays a table showing the number of 
 * millimeters that the ocean will have risen each year for the next 25
 * years.
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
    float oLevel = 0; //initializing ocean level at 0mm
    
    //Input Values
    for (int year = 1; year <= 25; year++) {
        oLevel += 1.5;
        cout<<"The ocean level after "<<year<<" years will increase by "<<oLevel
            <<" millimeters"<<endl;
    }
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

