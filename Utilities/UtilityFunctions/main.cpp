
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 3, 2017, 9:56 AM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

//User Libraries
#include "uts.h"


//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    cout<<"Random word, rWord()"<<endl;
    cout<<"0123456789"<<endl;
    for (int i=0;i<5;i++){
        cout<<uts::rWord()<<endl;
    }
    cout<<endl;
    cout<<"Random word, rWord(10)"<<endl;
    cout<<"0123456789"<<endl;
    for (int i=0;i<5;i++){
        cout<<uts::rWord(10)<<endl;
    }
    cout<<endl;
    
    cout<<"Pause test..."<<endl;
    uts::pauser();
    
    cout<<"5 sentences:"<<endl;
    cout<<"012345678901234567890123456789012345678901234567890123456789012345678901234"<<endl;
    uts::lorem(5);
    cout<<endl;
    
    cout<<"Pause test..."<<endl;
    uts::pauser();
    
    cout<<"Random first name"<<endl;
    cout<<"0123456789"<<endl;
    for (int i=0;i<5;i++){
        cout<<uts::rNameF()<<endl;
    }
    cout<<endl;
    
    cout<<"Pause test..."<<endl;
    uts::pauser();
    
    cout<<"Random full name"<<endl;
    cout<<"012345678901234567890123456789"<<endl;
    for (int i=0;i<5;i++){
        cout<<uts::rName()<<endl;
    }
    cout<<endl;
    
    cout<<"Pause test..."<<endl;
    uts::pauser();
    
    cout<<"Testing input validation functions:"<<endl;
    unsigned short ush=0;
    short ssh=0;
    unsigned int uin=0;
    int sin=0;
    float sfl=0.0f;
    
    cout<<"Enter an unsigned short:"<<endl;
    ush = uts::unSho();
    cin.ignore(256, '\n');
    cout<<"You entered: "<<ush<<endl;
    cout<<"Enter a signed short between -10000 and 10000:"<<endl;
    ssh = uts::siSho(-10000, 10000);
    cin.ignore(256, '\n');
    cout<<"You entered: "<<ssh<<endl;
    
    cout<<"Pause test..."<<endl;
    uts::pauser();
    
    cout<<"Enter an unsigned int: "<<endl;
    uin = uts::unInt();
    cin.ignore(256, '\n');
    cout<<"You entered: "<<uin<<endl;
    cout<<"Enter a signed int between -100000 and 100000:"<<endl;
    sin = uts::siInt(-100000, 100000);
    cin.ignore(256, '\n');
    cout<<"You entered: "<<sin<<endl;
    
    cout<<"Pause test..."<<endl;
    uts::pauser();
    
    cout<<"Enter a float between -12345.6 and 12345.6: "<<endl;
    sfl = uts::siFlo(-12345.6, 12345.6);
    cin.ignore(256, '\n');
    cout<<"You entered: "<<sfl<<endl;
    cout<<endl;
    
    cout<<"Pause test..."<<endl;
    uts::pauser();
    
    char choice;
    cout<<"Character validation testing:"<<endl;
    cout<<"Enter a character: "<<endl;
    choice=uts::inChar();
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    choice='\0';
    cout<<"Enter the character 'y': "<<endl;
    choice=uts::inChar('y');
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    cout<<"Enter the character 'y' or 'n': "<<endl;
    choice=uts::inChar('y', 'n');
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    cout<<"Enter the character 'y' or 'Y' or '^': "<<endl;
    choice=uts::inChar('y', 'Y', '^');
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    cout<<"Enter the character 'y' or '@' or '^' or '/': "<<endl;
    choice=uts::inChar('y', '@', '^', '/');
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    cout<<endl;
    
    cout<<"Testing pause function: "<<endl;
    uts::pauser();
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

