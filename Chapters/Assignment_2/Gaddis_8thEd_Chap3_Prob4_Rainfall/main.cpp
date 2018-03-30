
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 9, 2017
 * Purpose: Gaddis, Chapter 3, Prob 4 Average Rainfall
 *          Write a program that calculates the average rainfall for
 *          three months. THe program should ask the user to enter the
 *          name of each month, such as Jun or July, and the amount of 
 *          rain (in inches) that fell each month. The program should 
 *          display a message similar to the following:
 *          "The average rainfall for June, July, and August is 6.72 inches."
 */

//System Libraries
#include <iostream>
#include <iomanip>  //To manipulate the format of data
#include <string>  //to input names of months

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
    float rain1, rain2, rain3, average, totRain;
    string month1, month2, month3;
    
    //Input Values
    cout<<"This program will calculate the average rainfall for 3 months."<<endl;
    cout<<"Please input the name of the first month:"<<endl;
    cin>>month1;
    cout<<"Please input the inches of rain that fell in "<<month1<<endl;
    cin>>rain1;
    cout<<"Please input the name of the next month:"<<endl;
    cin>>month2;
    cout<<"Please input the inches of rain that fell in "<<month2<<endl;
    cin>>rain2;
    cout<<"Please input the name of the final month:"<<endl;
    cin>>month3;
    cout<<"Please input the inches of rain that fell in "<<month3<<endl;
    cin>>rain3;
    
    //Process by mapping inputs to outputs
    totRain = rain1+rain2+rain3;
    average = totRain/3;
    
    //Output values
    cout<<setprecision(2)<<fixed; //to format output with 2 decimal points
    cout<<totRain<<" inches of rain fell in "<<month1<<", "<<month2<<", and "<<month3<<endl;
    cout<<"The average rainfall for "<<month1<<", "<<month2<<", and "<<month3<<" is "<<average<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

