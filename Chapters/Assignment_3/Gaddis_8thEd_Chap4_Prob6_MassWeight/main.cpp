
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 12, 2017
 * Purpose: Gaddis, 8thEd, Chap4, Prob6
 *  Display an objects weight in newtons given it's mass.
 * Weight = mass * 9.8
 * Write a program that asks the user to enter an object's mass, and then
 * calculates and displays its weight. If the object weights more than 1,000 
 * newtons, display a message indicating that it is too heavy. If the object
 * weights less than 10 newtons, display a message indicating that the object
 * is too light.
 * 
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
    float weight, mass;
        
    //Input Values
    cout<<"This program will calculate an objects weight in newtons when"
            <<endl;
    cout<<"provided the mass in kilograms."<<endl;
    cout<<"Please input the objects mass in kilograms:"<<endl;
    cin>>mass;
    
    //Process by mapping inputs to outputs
    weight = mass*9.8f;  //calculating areas
    
    //Output values
    //Check to see if values were input within range.
    if (weight > 1000)
        cout<<"The object is too heavy."<<endl;
    else if (weight<10)
        cout<<"The object is too light."<<endl;
    else cout<<"The object weighs "<<weight<<" newtons."<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

