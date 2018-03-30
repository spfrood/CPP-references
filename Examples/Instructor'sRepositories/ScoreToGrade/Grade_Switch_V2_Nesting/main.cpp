/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 12, 2017, 11:15 AM
  Purpose:  Grade Switch - Case  Nested with different ranges
        >=95 A, >=87 B, >=80 C, >= 75 D, F otherwise
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float score;
    char grade;
    
    //Input values
    cout<<"This program takes the score and outputs the grade"<<endl;
    cout<<"Input the score 0 to 100"<<endl;
    cin>>score;
    
    //Process by mapping inputs to outputs
    switch(score>94.2f){
        case true:grade='A';break;
        default: switch(score>86.4f){
            case true:grade='B';break;
            default: switch(score>79.6f){
                case true:grade='C';break;
                default: switch(score>74.2){
                    case true:grade='D';break;
                    default: grade='F';
                }
            }
        }
    }
    
    //Output values
    cout<<"Your score of "<<score<<" = "<<grade<<endl;

    //Exit stage right!
    return 0;
}