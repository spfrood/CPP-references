
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
    char grade, grade2;
    
    //Input Values
    cout<<"This program takes the score and outputs the grade"<<endl;
    cout<<"Input the score from 0 to 100"<<endl;
    cin>>score;
    
    //Process by mapping inputs to outputs
    
    if (score > 100) score=100;
    switch (score) {   //This only works because of integer division
        case 100:case 99:case 98:case 97:case 96:case 95:grade = 'A';break;
        case 87 ... 94:grade='B';break;
        case 86:grade='C';break;
        case 85:grade='C';break;
        case 84:grade='C';break;
        case 83:grade='C';break; 
        case 82:grade='C';break;     
        case 81:grade='C';break;
        case 80:grade='C';break;
        case 79:grade='D';break;
        case 78:grade='D';break;
        case 77:grade='D';break;
        case 76:grade='D';break; 
        case 75:grade='D';break;        
        default: grade='F';
    }
    
    switch(score>94){
        case true:grade2='A';break;
        default: switch(score>86){
            case true:grade2='B';break;
            default: switch(score>79){
                case true:grade2='C';break;
                default: switch(score>74){
                    case true:grade2='D';break;
                    default: grade2='F';
                }
            }
        }
    }

    //Output values
    cout<<"Your score of "<<score<<" = "<<grade<<endl<<endl;
    cout<<"Your score of "<<score<<" = "<<grade2<<" for nested BOOL"<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

