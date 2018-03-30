
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 12, 2017
 * Purpose: Grade with ternary operators 
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
    cout<<"input the score from 0 to 100"<<endl;
    cin>>score;
    
    //Process by mapping inputs to outputs
    grade = (score>=90)?'A':
            (score>=80)?'B':
            (score>=70)?'C':
            (score>=60)?'C':'F';
    
    //Output values
    cout<<"Your score of "<<score<<" = "<<grade<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

