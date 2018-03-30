
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 17, 2017
 * Purpose: Grade with While Loop
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char numStd = 20;
    unsigned short average=0;
    
    //Input Values
    cout<<"This program takes the score and outputs the grade for "
            <<static_cast<int>(numStd)<<" students"<<endl;
    for (char student = 1; student<= numStd; student++) {
        //Assign a grade and add to the average
        //score and grade are local to the loop
        unsigned short score = rand()%50+50; //random score from 50 to 99
        average+=score;  //average = average+score
        //Process by mapping inputs to outputs
        char grade = (score>=90)?'A':
                (score>=80)?'B':
                (score>=70)?'C':
                (score>=60)?'C':'F';
    
    //Output values
        cout<<"Student "<<setw(2)<<static_cast<int>(student)
            <<", your score of "<<score<<" = "<<grade<<endl;
        
    } 
    
    //calculate and output the average
    average/=numStd;  //average = average/numStd;
    cout<<"The average test score = "<<average<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

