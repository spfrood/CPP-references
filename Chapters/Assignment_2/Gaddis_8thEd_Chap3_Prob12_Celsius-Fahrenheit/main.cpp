/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 11, 2017
 * Purpose: Gaddis, 8thEd, Chapter 3, Problem 12
 * Write a program to convert Celsius to Fahrenheit using the formula
 * F=9/5C + 32
 * F is the degrees F, C is the degrees C
 */

//System Libraries
#include <iostream>
#include <iomanip>
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
    float fahTemp, celTemp;
    
    //Input Values
    cout<<"This program will convert Celsius to Fahrenheit."<<endl;
    cout<<"What is the temperature in Celsius?"<<endl;
    cin>>celTemp;
    
    //Process by mapping inputs to outputs
    fahTemp = celTemp * 9 / 5 + 32;
    
    //Output values
    cout<<setprecision(2)<<fixed;
    cout<<celTemp<<" degrees Celsius is the same as"<<endl;
    cout<<fahTemp<<" degrees in Fahrenheit."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

