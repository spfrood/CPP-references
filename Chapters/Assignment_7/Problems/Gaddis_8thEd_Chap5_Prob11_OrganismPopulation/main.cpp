
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 23, 2017, 10:33 PM
 * Purpose: 11. Population
 * Write a program that will predict the size of a population of organisms. The 
 * program should ask the user for the starting number of organisms, their average 
 * daily population increase (as a percentage), and the number of days they will 
 * multiply. A loop should display the size of the population for each day.
 * Input Validation: Do not accept a number less than 2 for the starting size of 
 * the population. Do not accept a negative number for average daily population 
 * increase. Do not accept a number less than 1 for the number of days they will 
 * multiply.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short dayMult=0; //How many days will the population grow
    float popSize=0.0f;  //Initial population size
    float incrPer=0.0f;  //percentage of daily population growth
    
    //Input Values
    cout<<"This program will output the daily population growth of a group of"<<endl;
    cout<<"organisms. Please provide the following relevant details: "<<endl;
    cout<<"What is the starting population size? (minimum of 2)"<<endl;
    cin>>popSize; //get initial population from user
    while (cin.fail()||popSize<2) //validate input type and range
        {
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter a number! (minimum of 2)"<<endl;
            cin>>popSize;
        }
    cout<<"What is the daily population increase? (1% minimum)"<<endl;
    cin>>incrPer; //input percentage of growth
    while (cin.fail()||incrPer<1) //validate input type and range
        {
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter the percentage! (minimum of 1)"<<endl;
            cin>>incrPer;
        }
    cout<<"How many days will the population breed? (whole number 1 or larger)"<<endl;
    cin>>dayMult; //input days of growth
    while (cin.fail()||dayMult<1) //validate input type and range
        {
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter the days! (whole number 1 or larger)"<<endl;
            cin>>dayMult;
        }
    
    //Process by mapping inputs to outputs
    incrPer=incrPer*1.0e-2f; //convert input percentage to decimal
    for (int i=1;i<=dayMult;i++){
        popSize=(popSize+popSize*incrPer); //calculate new daily population
        cout<<setprecision(0)<<fixed; //format output
        cout<<"After "<<i<<" days the new population is: "<<popSize<<"."<<endl;
    }
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

