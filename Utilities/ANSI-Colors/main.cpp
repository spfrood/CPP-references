

/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "colors.h"


//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
    
    cout<<RED<<"RED"<<endl;
    cout<<GREEN<<"GREEN"<<endl;
    cout<<YELLOW<<"YELLOW"<<endl;
    cout<<BLUE<<"BLUE"<<endl;
    cout<<MAGENTA<<"MAGENTA"<<endl;
    cout<<CYAN<<"CYAN"<<endl;
    cout<<WHITE<<"WHITE"<<endl;
    cout<<BLACK<<"BLACK"<<endl;
    cout<<RESET<<"RESET     RESET"<<endl;
    
    cout<<endl;
    
    cout<<BOLDBLACK<<"BOLDBLACK"<<endl;
    cout<<BOLDRED<<"BOLDRED"<<endl;
    cout<<BOLDGREEN<<"BOLDGREEN"<<endl;
    cout<<BOLDYELLOW<<"BOLDYELLOW"<<endl;
    cout<<BOLDBLUE<<"BOLDBLUE"<<endl;
    cout<<BOLDMAGENTA<<"BOLDMAGENTA"<<endl;
    cout<<BOLDCYAN<<"BOLDCYAN"<<endl;
    cout<<BOLDWHITE<<"BOLDWHITE"<<endl;
    cout<<RESET<<"RESET   COLORS"<<endl<<endl;
    
    cout<<endl;
    
    cout<<INVERSE<<"INVERSE colors"<<RESET<<endl;
    cout<<UNDERLINE<<"UNDERLINE underline"<<RESET<<endl<<endl;   
    
    cout<<endl;
    
    cout<<BGBLACK<<WHITE<<"BLACK BACKGROUND WHITE TEXT"<<RESET<<endl;
    cout<<BGRED<<"RED BACKGROUND"<<endl;
    cout<<BGGREEN<<"GREEN BACKGROUND"<<endl;
    cout<<BGYELLOW<<"YELLOW BACKGROUND"<<endl;
    cout<<BGBLUE<<"BLUE BACKGROUND"<<endl;
    cout<<BGMAGENTA<<"MAGENTA BACKGROUND"<<endl;
    cout<<BGCYAN<<"CYAN BACKGROUND"<<endl;
    cout<<BGWHITE<<"WHITE BACKGROUND"<<endl;
    
    cout<<endl;
    
    cout<<RESET<<"Everything should be back to normal here."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}