
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    bool setter=true;
    
    //Input Values
    for (bool a=true;a;a=setter){
        int blah=rand()%50;
        cout<<"BLAH = "<<blah<<" so ";
        if (blah<=1) {
            setter=false;
            cout<<"Ending Loop."<<endl;
        } else {
            setter=true;
            cout<<"Looping..."<<endl;
        }
    }
    
    //Process by mapping inputs to outputs
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

