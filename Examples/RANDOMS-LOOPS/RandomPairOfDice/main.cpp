
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 9, 2017
 * Purpose: Using random number generator
 *          To use rand and srand must include cstdlib and ctime 
 *          libraries
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned char die1, die2, sum;
    
    //Input Values
    die1=rand()%6+1; //Give value 1-6 
    die2=rand()%6+1; //give value 1-6
    
    //Process by mapping inputs to outputs
    sum=die1+die2;
    
    //Output values
    cout<<"Die 1 = "<<static_cast<int>(die1)<<endl;
    cout<<"Die 2 = "<<static_cast<int>(die2)<<endl;
    cout<<"sum   = "<<static_cast<int>(sum)<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

