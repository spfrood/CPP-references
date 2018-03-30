
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 9, 2017
 * Purpose: Gaddis, Chapter 3, Prob 3, Test Average
 *          Write a program that asks for five test scores. The program
 *          should calculate the average test score and display it. The
 *          number displayed should be formatted in fixed-point notation
 *          with one decimal point of precision. 
 */

//System Libraries
#include <iostream>
#include <iomanip>  //To manipulate the format of data

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
    short score1, score2, score3, score4, score5;
    float average, totScor;
    
    
    //Input Values
    cout<<"This program will calculate the average of 5 test scores."<<endl;
    cout<<"Please input the 5 test scores:"<<endl;
    cout<<"Score 1: "<<endl;
    cin>>score1;
    cout<<"Score 2: "<<endl;
    cin>>score2;
    cout<<"Score 3: "<<endl;
    cin>>score3;
    cout<<"Score 4: "<<endl;
    cin>>score4;
    cout<<"Score 5: "<<endl;
    cin>>score5;
    
    //Process by mapping inputs to outputs
    totScor = score1+score2+score3+score4+score5; //change int to float
    average = totScor/5;   //calculating average score
    
    //Output values
    cout<<setprecision(1)<<fixed; //required format for average
    cout<<"\n\nThe average of the 5 test scores is:  "<<average;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

