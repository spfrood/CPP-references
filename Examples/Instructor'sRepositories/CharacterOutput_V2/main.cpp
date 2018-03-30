/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 23, 2017, 11:30 AM
  Purpose:  Investigate the character/cout ascii output with functions
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void repeat(char,int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Output a triangle 
    //Declare the base;
    int base=15,seprshn=15;
    cout<<endl<<endl;
    for(int nLines=1;nLines<=base;nLines++){
        repeat('*',nLines);
        repeat(' ',base-nLines);
        repeat(' ',seprshn);
        repeat('*',base-nLines+1);
        cout<<endl;
    }

    //Exit stage right!
    return 0;
}

void repeat(char c,int n){
    for(int col=1;col<=n;col++){
        cout<<c;
    }
}