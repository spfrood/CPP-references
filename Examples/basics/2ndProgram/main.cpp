/* 
   File:   main
   Author: Dr. Mark E. Lehr
   Created on August 29, 2016, 10:37 AM
   Purpose:  Computers can get wrong results
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    short a,b,c;
    
    //Set values
    a=30000;
    b=20000;
    
    //Process values -> Map inputs to Outputs
    c=a+b;
    
    //Display Output
    cout<<a<<" + "<<b<<" = "<<c<<endl;

    //Exit Program
    return 0;
}