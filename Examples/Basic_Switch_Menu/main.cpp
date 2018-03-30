/* 
  File:   main.cpp
  Author: Dr. Scott Parker
  Created on February 5, 2017, 12:28 PM
  Purpose:  Assignment 5 Homework Menu
 */

//System Libraries
#include <iostream> //Input Output Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another and for
//2d array columns

//Function Prototypes 
//Delete void functions or add them as needed based on homework problems
void prob1();
void prob2();
void prob3();
void prob4();

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list <non-numeric data will be ignored>"<<endl;
        cout<<"Type 1 for Problem 1: "<<endl;
        cout<<"Type 2 for Problem 2: "<<endl;
        cout<<"Type 3 for Problem 3: "<<endl;
        cout<<"Type 4 for Problem 4: "<<endl;
        cout<<"Enter 0 (zero) or a number not listed to exit."<<endl;
        cin>>choice;
        while (cin.fail()) //Loop to validate input
            {
            cout<<"INPUT INVALID! "<<endl;
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter a valid choice!:"<<endl;
            cin>>choice;
            }

        //Switch to determine the Problem
        switch(choice){
            case 4:{prob4();break;}
            case 3:{prob3();break;}
            case 2:{prob2();break;}
            case 1:{prob1();break;}
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>=1&&choice<=10);
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************ Function for Problem 10  ****************************
//Description: Program for Book, Edition, Chapter, Question, Short Description
//
//Inputs: (what inputs passed to function)
//     
//Outputs:  (what is the output of this function)
//
//******************************************************************************
void prob10(){
    
    //Exit stage right! - This is the 'return 0' call
}

void prob9(){
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob8(){
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob7(){ 
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob6(){
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob5(){
    
    //Exit stage right! - This is the 'return 0' call
}

void prob4(){
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob3(){
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob2(){
    
    //Exit stage right! - This is the 'return 0' call
}

void prob1(){
    
    //Exit stage right! - This is the 'return 0' call
}
