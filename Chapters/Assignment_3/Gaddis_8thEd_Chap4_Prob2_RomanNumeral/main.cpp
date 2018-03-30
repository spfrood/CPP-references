
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 12, 2017
 * Purpose: Gaddis, 8th edition, chapter 4, problem 2
 * Write a program that asks the user to enter a number within the range of
 * 1 through 10. Use a switch statement to display the Roman Numeral version
 * of that number. Input Validation - Do not accept a number less than 1 or
 * greater than 10.
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
    short romNum;
    
    
    //Input Values
    cout<<"This program will convert a number you enter into Roman "
            "numerals."<<endl;
    cout<<"Please input a number between 1 and 10 to begin."<<endl;
    cin>>romNum;
    
    //Process by mapping inputs to outputs
    
    //Output values
    if (romNum > 10 || romNum < 1) cout<<"Invalid Input! Try Again!"<<endl;  //Check for valid input range of 1 to 10
    else {
        switch (romNum){     //Assigning the Roman value for the integer.
            case 10:cout<<"10 is X in Roman numerals.";break;
            case 9:cout<<"9 is IX in Roman numerals.";break;
            case 8:cout<<"8 is VIII in Roman numerals.";break;
            case 7:cout<<"7 is VII in Roman numerals.";break;
            case 6:cout<<"6 is VI in Roman numerals.";break;
            case 5:cout<<"5 is V in Roman numerals.";break;
            case 4:cout<<"4 is IV in Roman numerals.";break;
            case 3:cout<<"3 is III in Roman numerals.";break;
            case 2:cout<<"2 is II in Roman numerals.";break;
            case 1:cout<<"1 is I in Roman numerals.";break;       
            default:cout<<"Something didn't work somewhere! ERROR!"<<endl;
            }
        }
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

