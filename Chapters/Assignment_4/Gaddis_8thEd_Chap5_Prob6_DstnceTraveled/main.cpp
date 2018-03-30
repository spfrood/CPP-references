
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 10:28 PM
 * Purpose: Gaddis, 8th Edition, Chapter 5, Problem 6, Distance Traveled
 * The distance a vehicle travels can be calculated as follows: 
 * distance = speed * time
 * For example, if a train travels 40 miles per hour for 3 hours, the distance 
 * traveled is 120 miles. Write a program that asks the user for the speed of 
 * a vehicle (in miles per hour) and how many hours it has traveled. The 
 * program should then use a loop to display the distance the vehicle has 
 * traveled for each hour of that time period. Here is an example of the 
 * output:

 * What is the speed of the vehicle in mph? 40 
 * How many hours has it traveled? 3
 * Hour Distance Traveled 
 * --------------------------------
 *   1          40 
 *   2          80 
 *   3         120
 * 
 * Input Validation: Do not accept a negative number for speed and do not 
 * accept any value less than 1 for time traveled.
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
    int hours = 0, speed = -1, dstnce = 0; 
    
    //Input Values and check for validations
    do {
    cout<<"What is the speed of the vehicle in MPH? ";
    cin>>speed;
    cout<<"How many hours did the vehicle travel? ";
    cin>>hours;
    cout<<endl;
    if (hours < 1) cout<<"Travel time must be 1 or more hours!"<<endl;
    if (speed < 0) cout<<"Speed may not be negative!"<<endl;
    } while (hours < 1 || speed < 0);
    
    //Loop to calculate and display distance
    
    cout<<"Hour          Distance Traveled"<<endl;
    cout<<"-------------------------------"<<endl;
    for (int time = 1; time <= hours; time++) {
        dstnce = dstnce + speed;
        cout<<" "<<time<<"                  "<<setw(4)<<right<<dstnce<<endl;
    }
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

