
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 25, 2017, 8:25 PM
 * Purpose: 2)  Read a 4 character number.  Output the result in the 
 * following format.
 * input = 9873
 * 3 ***
 * 7 *******
 * 8 ********
 * 9 *********
 * 
 * If one of the digits is not a number, then put a ? mark in output
 * input = 98a3
 * 3 ***
 * a ?
 * 8 ********
 * 9 *********
 */

//System Libraries
#include <iostream>
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
    char digit1, digit2, digit3, digit4; //The 4 digits of the number
    
    //Input Values
    cout<<"This program will display output for a 4 digit number."<<endl;
    cout<<"It will change the format of the output based on the digit"<<endl;
    cout<<"that is entered. Please input 4 digits: "<<endl;
    cin>>digit1>>digit2>>digit3>>digit4;
    
    //Process by mapping inputs to outputs
    
    //Output values
    if (static_cast<int>(digit4)<48||static_cast<int>(digit4)>57) 
        cout<<"?"<<endl; //determining if digit4 is number 
    else { //Outputting * equal to value of digit. Looks weird if 0 entered.
        for (int drwLine = 0; drwLine<(digit4-48); drwLine++){
        cout<<"*";
        }
    cout<<endl;
    }
    if (static_cast<int>(digit3)<48||static_cast<int>(digit3)>57) 
        cout<<"?"<<endl; //determining if digit4 is number
    else { //Outputting * equal to value of digit. Looks weird if 0 entered.
        for (int drwLine = 0; drwLine<(digit3-48); drwLine++){
        cout<<"*";
        }
    cout<<endl;
    }
    if (static_cast<int>(digit2)<48||static_cast<int>(digit2)>57) 
        cout<<"?"<<endl; //determining if digit4 is number
    else { //Outputting * equal to value of digit. Looks weird if 0 entered.
        for (int drwLine = 0; drwLine<(digit2-48); drwLine++){
        cout<<"*";
        }
    cout<<endl;
    }
    if (static_cast<int>(digit1)<48||static_cast<int>(digit1)>57) 
        cout<<"?"<<endl; //determining if digit4 is number
    else { //Outputting * equal to value of digit. Looks weird if 0 entered.
        for (int drwLine = 0; drwLine<(digit1-48); drwLine++){
        cout<<"*";
        }
    cout<<endl;
    }
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

