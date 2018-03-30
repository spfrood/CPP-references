
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 11, 2017
 * Purpose: Gaddis 8th Edition Chapter 3 Problem 5
 *          Write a program that asks the user for the number of males
 *          and the number of females registered in a class. The program
 *          should display the percentage of males and females in the
 *          class. HINT: Suppose there are 8 males and 12  females in a
 *          class. There are 20 students in the class. The percentage of
 *          males can be calculated as 8/20=0.4, or 40%. The percentage
 *          of females can be calcualted as 12/20=0.6, or 60%.
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
    short males, females;
    float totStud, perMale, perFems;
    
    //Input Values
    cout<<"How many males are in the class?"<<endl;
    cin>>males;
    cout<<"How many females are in the class?"<<endl;
    cin>>females;
    
    //Process by mapping inputs to outputs
    totStud = males+females;
    perMale = (males/totStud)*100;
    perFems = (females/totStud)*100;
    
    //Output values
    cout<<setprecision(0)<<fixed;
    cout<<"The class is made up of "<<perMale<<"% male and "<<perFems
            <<"% female students."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

