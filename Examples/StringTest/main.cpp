
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Template to be used for all programming projects 
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
    string someTxt="";
    
    
    //Input Values
    cout<<"Enter a string:"<<endl;
    getline(cin, someTxt);
    cout<<someTxt<<endl;;
    
    
    //Process by mapping inputs to outputs
    cout<<"Trying to access string data like you would an array"<<endl;
    cout<<someTxt[5]<<endl;
    char temp='\n';
    temp=someTxt[5];
    someTxt[5]=someTxt[15];
    someTxt[15]=temp;
    cout<<someTxt<<endl;
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

