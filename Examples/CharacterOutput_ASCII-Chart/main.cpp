/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 23, 2017, 11:30 AM
  Purpose:  Investigate the character/cout ascii output
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare variables
    int n=1;
    
    //Process by mapping inputs to outputs
    for(char c=0;c<127;c++){
        cout<<static_cast<int>(c)<<"  "<<c;
        cout<<endl;
    }
    

    //Exit stage right!
    return 0;
}