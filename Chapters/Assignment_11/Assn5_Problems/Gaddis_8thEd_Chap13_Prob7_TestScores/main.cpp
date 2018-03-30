
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 3, 2017, 5:03 PM
 * Purpose: 7. TestScores Class
Design a TestScores class that has member variables to hold three test scores. 
The class should have a constructor, accessor, and mutator functions for the 
test score fields and a member function that returns the average of the test 
scores. Demonstrate the class by writing a separate program that creates an 
instance of the class. The program should ask the user to enter three test 
scores, which are stored in the TestScores object. Then the program should 
display the average of the scores, as reported by the TestScores object.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Tests.h" //test scores class

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    Tests scores; //create object
    
    //Input Values 
    scores.setTest(); //check score values
    //Process by mapping inputs to outputs
    cout<<"The average is: "<<scores.avgTest()<<endl; //output average
    
    //Output values 
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

