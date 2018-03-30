
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 5, 2017, 1:00 PM
 * Purpose: Savitch Homework to caluclate free-fall distance
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
const float GRAVITY = 3.217e1f;

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    
    //Declare Variables
    float time,        //Time in seconds
          distnce;    //Distance in feet
    
    //Input Values
    cout<<"This program solves distance traveled"<<endl;
    cout<<"in free-fall under earth gravity"<<endl;
    cout<<"Input the time during free-fall in seconds"<<endl;
    cin>>time;
    
    //Process by mapping inputs to outputs
    distnce = GRAVITY*time*time/2;
    
    //Output values
    cout<<"The distance fallen ="<<distnce<<" feet"<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

