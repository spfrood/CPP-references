
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 12, 2017
 * Purpose: Grade with switch operators 
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
    unsigned short score;
    char grade;
    
    //Input Values
    cout<<"This program takes the score and outputs the grade"<<endl;
    cout<<"Input the score from 0 to 100"<<endl;
    cin>>score;
    
    //Process by mapping inputs to outputs
    switch (score/10){   //This only works because of integer division
        case 11:grade='A';break; //and grade levels break at the 10's point
        case 10:grade='A';break; 
        case 9:grade='A';break;     
        case 8:grade='B';break;
        case 7:grade='C';break;
        case 6:grade='D';break;
        default: grade='F';
    }
    
    //Output values
    cout<<"Your score of "<<score<<" = "<<grade<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

