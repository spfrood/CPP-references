
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 1, 2017  11:40 AM
 * Purpose: 1. Date Class
Design a class called Date . The class should store a date in three integers: 
month , day , and year . There should be member functions to print the date in 
the following forms:
12/25/2014
December 25, 2014
25 December 2014
Demonstrate the class by writing a complete program implementing it.
Input Validation: Do not accept values for the day greater than 31 or less than
1. Do not accept values for the month greater than 12 or less than 1.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "P1DtCls.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    P1DtCls today;
    
    //Input Values
    today.sDate(); //Set the date value
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    today.outputs(); //output the dates 
    
    //Clean up memory
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

