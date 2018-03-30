
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 8, 2017
 * Purpose: Gaddis, Chap2, Prob 14 - personal info formatting
 *          cout formatting - Output multiple pieces of personal data, each
 *          on it's own line using only a single cout statement
 */

//System Libraries
#include <iostream>
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
    string name, address, phone, major; //Info to be displayed
    
    //Input Values
    name="Scott Parker";
    address="28900 Ironwood Ave., Moreno Valley, CA 92555";
    phone="510-364-7840";
    major="Psychology";
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<name<<endl<<address<<endl<<phone<<endl<<major<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

