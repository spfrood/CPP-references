
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 1:19 PM
 * Purpose: Gaddis, 8th Edition, Chapter 5, Problem 2, ASCII Codes
 * Write a program that uses a loop to display the characters for the  
 * ASCII codes 0 through 127. Display 16 characters on each line.
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
    
    
    //Input Values
    for (int counter = 0; counter <= 127; counter++) {
        cout<<static_cast<char>(counter);
        if ((counter%16)==0)cout<<endl;
    }
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

