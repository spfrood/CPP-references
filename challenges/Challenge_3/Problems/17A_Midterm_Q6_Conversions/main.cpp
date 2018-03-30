
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: 6) a)  Convert the following 2 numbers to binary, octal and hex.
	2.325, 0.1453125
        When done, convert the following to a float representation
        by the definition in class. In other words, I want an 8 digit hex 
	    number representation using the 4 byte float specification
        defined in class.  
   b)  Do the same for a) given they are negative values.
   c)  Convert the float representations of the following into 
	the decimal number given the definition in class.
	59999901, 59999902, A66667FE

Note:  This doesn't require a program, however, I want you to write a 
simple function that outputs the answers you did by hand with "cout". 
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
void outA06(); //function to output the answers for question 6 in a simple cout

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    
    
    //Input Values
    
    
    //Process by mapping inputs to outputs
    
    //Output values
    outA06();
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to output the answers for question 6 in a simple cout
void outA06() {
    cout<<"Convert 2.325 from base 10 to base 2, 8, and 16."<<endl;
    cout<<"Also output in float notation."<<endl;
    cout<<"Base 16: 2.AC"<<endl;
    cout<<"Base 8: 2.246"<<endl;
    cout<<"Base 2: 10.0101"<<UNDERLINE<<"0011"<<RESET<<endl;
    cout<<"Float Notation: 4A666602"<<endl;
    cout<<"Negative Float Value: B5999A02"<<endl;
    cout<<endl;
    cout<<"Convert 0.1453125 from base 10 to base 2, 8, and 16."<<endl;
    cout<<"Also output in float notation."<<endl;
    cout<<"Base 16: 0.4AC"<<endl;
    cout<<"Base 8: 0.4426"<<endl;
    cout<<"Base 2: 0.00100101"<<UNDERLINE<<"0011"<<RESET<<endl;
    cout<<"Float Notation: 4A6666FE"<<endl;
    cout<<"Negative Float Value: B5999AFE"<<endl;
    cout<<endl;
    cout<<"Convert 59999901 from Float Notation to Decimal"<<endl;
    cout<<"010110011001100110011001|00000001"<<endl;
    cout<<"Decimal value: 1.66101074"<<endl;
    cout<<"Convert 59999902 from Float Notation to Decimal"<<endl;
    cout<<"010110011001100110011001|00000010"<<endl;
    cout<<"Decimal value: 2.79998779"<<endl;
    cout<<"Convert 59999901 from Float Notation to Decimal"<<endl;
    cout<<"101001100110011001100111|11111110"<<endl;
    cout<<"Decimal value: -0.006000061"<<endl;
} 