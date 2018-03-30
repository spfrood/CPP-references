/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 9, 2017, 11:30 AM
  Purpose:  Using the random number generator
 */

//System Libraries
#include <iostream>//Input output
#include <cstdlib> //Random number generator and seed
#include <ctime>   //Time used for random seed
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned char die1,die2,sum;
    
    //Input values
    die1=rand()%6+1;//[1,6]
    die2=rand()%6+1;//[1,6]
    
    //Process by mapping inputs to outputs
    sum=die1+die2;
    
    //Output values
    cout<<"Die 1 = "<<static_cast<int>(die1)<<endl;
    cout<<"Die 2 = "<<static_cast<int>(die2)<<endl;
    cout<<"Sum   = "<<static_cast<int>(sum)<<endl;
    
    //Exit stage right!
    return 0;
}