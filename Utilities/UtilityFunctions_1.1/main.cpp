
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 3, 2017, 9:56 AM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "uts.h"
#include "val.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    
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
    double dbl=0.0f;
    
    cout<<"Testing variables with limits... signed -10000 to 10000"<<endl;
    cout<<"     unsigned 100 to 50000"<<endl;
    cout<<"enter signed short: ";
    ssh=val::inNum(ssh, -10000, 10000);
    cout<<"short: "<<ssh<<endl;
    cout<<"sizeof signed short: "<<sizeof(ssh)<<endl;
    
    cout<<"enter unsigned short: ";
    ush=val::inNum(ush, 100, 10000);
    cout<<"unsigned short: "<<ush<<endl;
    cout<<"sizeof unsigned short: "<<sizeof(ush)<<endl;
    
    cout<<"Enter signed int ";
    sin=val::inNum(sin, -10000, 10000);
    cout<<"signed int: "<<sin<<endl;
    cout<<"sizeof signed int: "<<sizeof(sin)<<endl;
    
    cout<<"Enter unsigned int ";
    uin=val::inNum(uin, 100, 10000);
    cout<<"unsigned int: "<<uin<<endl;
    cout<<"sizeof unsigned int: "<<sizeof(uin)<<endl;
    
    cout<<"Enter float ";
    sfl=val::inNum(sfl, -10000.0f, 10000.0f);
    cout<<"float: "<<sfl<<endl;
    cout<<"sizeof float: "<<sizeof(sfl)<<endl;
    
    cout<<"Enter double ";
    dbl=val::inNum(dbl, -10000.0f, 10000.0f);
    cout<<"double: "<<dbl<<endl;
    cout<<"sizeof double: "<<sizeof(dbl)<<endl;
    cout<<endl;
    
    cin.ignore(256, '\n');
    cout<<"Pause test..."<<endl;
    uts::pauser();
    
    cout<<"Testing variable input without limits"<<endl;
    cout<<"enter signed short: ";
    ssh=val::inNum(ssh);
    cout<<"short: "<<ssh<<endl;
    cout<<"sizeof short: "<<sizeof(ssh)<<endl;
    
    cout<<"enter unsigned short: ";
    ush=val::inNum(ush);
    cout<<"unsigned short: "<<ush<<endl;
    cout<<"sizeof unsigned short: "<<sizeof(ush)<<endl;
    
    cout<<"enter signed int: ";
    sin=val::inNum(sin);
    cout<<"signed int: "<<sin<<endl;
    cout<<"sizeof signed int: "<<sizeof(sin)<<endl;
    
    cout<<"enter unsigned int: ";
    uin=val::inNum(uin);
    cout<<"unsigned int: "<<uin<<endl;
    cout<<"sizeof unsigned int: "<<sizeof(uin)<<endl;
    
    cout<<"Enter float ";
    sfl=val::inNum(sfl);
    cout<<"float: "<<sfl<<endl;
    cout<<"sizeof float: "<<sizeof(sfl)<<endl;
    
    cout<<"Enter double ";
    dbl=val::inNum(dbl);
    cout<<"double: "<<dbl<<endl;
    cout<<"sizeof double: "<<sizeof(dbl)<<endl;
    cout<<endl;
    
    cin.ignore(256, '\n');
    cout<<"Pause test..."<<endl;
    uts::pauser();
    
    char choice;
    cout<<"Character validation testing:"<<endl;
    cout<<"Enter a character: "<<endl;
    choice=val::inChar();
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    choice='\0';
    cout<<"Enter the character 'y': "<<endl;
    choice=val::inChar('y');
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    cout<<"Enter the character 'y' or 'n': "<<endl;
    choice=val::inChar('y', 'n');
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    cout<<"Enter the character 'y' or 'Y' or '^': "<<endl;
    choice=val::inChar('y', 'Y', '^');
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    cout<<"Enter the character 'y' or '@' or '^' or '/': "<<endl;
    choice=val::inChar('y', '@', '^', '/');
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    cout<<endl;
    cout<<"Enter the character 'y' or '@' or '^' '/' or '*': "<<endl;
    choice=val::inChar('y', '@', '^', '/', '*');
    cin.ignore(256, '\n');
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    cout<<endl;
    
    cout<<"Testing pause function: "<<endl;
    uts::pauser();
    
    cout<<"Enter a letter: "<<endl;
    choice=val::inAlpha();
    cout<<"You entered the character: "<<choice<<" which has ascii value: "<<static_cast<int>(choice)<<endl;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

