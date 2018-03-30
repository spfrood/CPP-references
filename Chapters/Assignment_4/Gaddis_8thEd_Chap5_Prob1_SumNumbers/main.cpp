
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 17, 2017, 12:19 PM
 * Purpose: Gaddis, 8th Ed, Chap 5, Prob 1, Sum of Numbers
 * Write a program that asks the user for a positive integer value. The 
 * program should use a loop to get the sum of all the integers from 1 up to
 * the number entered. For example, if the user enters 50, the loop will find
 * the sum of 1, 2, 3, 4, ...50.
 * Input Validation: Do not accept a negative starting number.
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
    int granSum=0, totReps;
    
    //Input Values
    cout<<"Please enter a positive integer up to a value of 65,000."<<endl;
    cin>>totReps;  //Number to add the sums up to
    
    //Process by mapping inputs to outputs
    if (totReps < 0) cout<<"You must enter a positive value!"; //Input validation
    else if (totReps > 65000) cout<<"Number too large!"; //More input validation to prevent out of bounds
    else {
        for (int start = 0; start <= totReps; start++) {
            granSum += start;   
            cout<<"Total so far: "<<granSum<<endl;
        }
        cout<<"The total value of all numbers is: "<<granSum<<endl;
    }
   
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

