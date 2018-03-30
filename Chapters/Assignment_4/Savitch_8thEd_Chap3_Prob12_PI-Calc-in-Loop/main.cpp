
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 12:12 PM
 * Purpose: Savitch, 8th Ed, Chapter 3, Problem 12
 * Calculate PI 
 */

//System Libraries
#include <iostream>
#include <cmath>
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
    
    //pi = 4 [ 1 - 1/3 + 1/5 - 1/7 + 1/9 ... + ((-1)^n/2n+1) ]
    const unsigned int NUM_TERMS = 1000000000;
    float pi = 0.0;
    
    //Input Values
    
    
    //Process by mapping inputs to outputs
    for (int n=0; n < NUM_TERMS; ++n ) {
        pi += 4 * pow(-1,n) / (2*n +1); 
    }
    
    //Output values
    cout<<"PI = "<<setprecision(7)<<pi<<endl;
    cout<<"PI = "<<setprecision(12)<<pi<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

