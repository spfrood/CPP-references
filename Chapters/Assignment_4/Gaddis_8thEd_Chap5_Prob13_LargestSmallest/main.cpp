
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 19, 2017, 1:25 PM
 * Purpose: Gaddis, 8th Edition, Chapter 5, Problem 13, The Greatest 
 * and Least of These
 * Write a program with a loop that lets the user enter a series of integers. 
 * The user should enter −99 to signal the end of the series. After all the 
 * numbers have been entered, the program should display the largest and 
 * smallest numbers entered.
 * 
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
    int largest=0, least=0, holding=0; 
    
    //Input Values and check for validations
    cout<<"Enter a series of integers until you are done."<<endl;
    cout<<"Enter the integer -99 to stop entering input."<<endl;
    do {
        cout<<"Enter an integer:"<<endl;
        cin>>holding;
        largest = holding>largest?holding:largest;
        least = holding<least?holding:least;
    } while (holding != -99);
    
    //Output
    
    cout<<"The largest integer input was: "<<largest<<endl;
    cout<<"The smallest integer input was: "<<least<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

