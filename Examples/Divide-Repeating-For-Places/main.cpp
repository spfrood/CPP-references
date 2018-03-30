
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 12:12 PM
 * Purpose: Savitch, 8th Ed, Chapter 3, Problem 12
 * Calculate PI 
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

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
    unsigned short piCalc, piHold, piDiv, num1, num2;
    unsigned long piRuns;
    
    //Input Values
    piCalc = 0, piHold = 0, piDiv = 0;
    cout<<"How many places would you like to calculate?"<<endl;
    cin>>piRuns;
    cout<<"What numbers would you like to divide?"<<endl;
    cin>>num1>>num2;
    
    cout<<num1/num2;
    piHold = num1 % num2;
    
    //Process by mapping inputs to outputs
    for (int piTemp = 1; piTemp <= piRuns; piTemp++){
        piCalc = (piHold*10) / 7;
        cout<<piCalc;
        piDiv = (piHold*10) % 7;
        piHold = piDiv;
        
        
        if ((piTemp%51)==0)cout<<endl;
    }
    
    //Output values
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

