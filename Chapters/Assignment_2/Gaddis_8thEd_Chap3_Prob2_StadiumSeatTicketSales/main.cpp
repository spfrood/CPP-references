
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 9, 2017
 * Purpose: Gaddis Chapter 3 Problem 2 - Find ticket sales for each
 *          type of ticket, display total income from ticket sales. 
 *          Force output in fixed-point notation with two decimal places
 *          always displayed - ala displaying currency 
 */

//System Libraries
#include <iostream>
#include <iomanip>   //To force output formatting

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
    unsigned short classA=15, classB=12, classC=9;
    unsigned int numA, numB, numC;
    float revA, revB, revC, totRev;
    
    //Input Values
    cout<<"This program will calculate the revenue of a stadium"<<endl;
    cout<<"based on the price of ticket sales for each class of"<<endl;
    cout<<"of ticket."<<endl;
    cout<<"How many A-Class tickets were sold?"<<endl;
    cin>>numA;
    cout<<"How many B-Class tickets were sold?"<<endl;
    cin>>numB;
    cout<<"How many C-Class tickets were sold?"<<endl;
    cin>>numC;
    
    //Process by mapping inputs to outputs
    revA = numA*classA;
    revB = numB*classB;
    revC = numC*classC;
    totRev = revA+revB+revC;
    
    //Output values
    cout<<left<<setprecision(2)<<fixed;
    cout<<"The total revenue from each class of ticket is:"<<endl;
    cout<<"Class A:        $"<<setw(14)<<revA<<endl;
    cout<<"Class B:        $"<<setw(14)<<revB<<endl;
    cout<<"Class C:        $"<<setw(14)<<revC<<endl;
    cout<<"Total Revenue:  $"<<setw(14)<<totRev<<endl;
    
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

