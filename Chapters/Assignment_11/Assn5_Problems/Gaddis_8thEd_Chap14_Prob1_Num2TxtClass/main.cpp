/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 8th, 2017, 11:06 AM
 * Purpose: 1. Numbers Class
Design a class Numbers that can be used to translate whole dollar amounts in the
range 0 through 9999 into an English description of the number. For example, the 
number 713 would be translated into the string seven hundred thirteen , and 8203 
would be translated into eight thousand two hundred three . The class should have 
a single integer member variable:
int number;
and a static array of string objects that specify how to translate key dollar 
amounts into the desired format. For example, you might use static strings such 
as string lessThan20[20] = {"zero", "one", ..., "eighteen", "nineteen"};
string hundred = "hundred";
string thousand = "thousand";
The class should have a constructor that accepts a nonnegative integer and uses 
it to initialize the Numbers object. It should have a member function print() 
that prints the English description of the Numbers object. Demonstrate the class 
by writing a main program that asks the user to enter a number in the proper 
range and then prints out its English description.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
#include "TxtNum.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const int THOSNDS=1000;   //Conversion to   1,000
const int HUNDRDS=100;    //Conversion to     100
const int TENS=10;        //Conversion to      10

//Function Prototypes


//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    int conNum; 
    string numText="";
    //Input data on the company
    
    cout<<"Enter the number to convert to text (0 to 9999): "<<endl;
    cin>>conNum;
    while (cin.fail() || conNum<0 || conNum>9999){ //validate data type and range
        cout<<"Entry not valid! Enter a number from 0 to 9999!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>conNum;
    }
    
    TxtNum a(conNum);
    
    //Process the data
    numText = a.txtVal();
    //Outputs
    cout<<"The text returned for "<<a.getNum()<<" is: "<<numText<<endl;
    
    //Clean up memory
    
    //Exit stage right!
    return 0;
}
