/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 5, 2017, 1:15 PM
  Purpose:  Free Fall
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another
const float GRAVITY=3.2174e1f;//Gravity on the earth sea level ft/sec^2

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float time,   //Time in seconds
          distnce;//Distance in feet
    
    //Input values
    cout<<"This problem solves the distance traveled"<<endl;
    cout<<"in free-fall under earth gravity"<<endl;
    cout<<"Input the time during Free-Fall in seconds"<<endl;
    cin>>time;
    
    //Process by mapping inputs to outputs
    distnce=GRAVITY*time*time/2;
    int id=distnce*100+0.5;//Rounding to 2 decimals
    distnce=id/100.0f;
    
    //Output values
    cout<<"The distance fallen = "<<distnce<<" ft"<<endl;

    //Exit stage right!
    return 0;
}