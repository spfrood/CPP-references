
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 21, 2017, 11:30 AM
 * Purpose: 17. Math Tutor
Write a program that can be used as a math tutor for a young student. The 
program should display two random numbers to be added, such as
  247  
 +129
 ----
The program should then pause while the student works on the problem. When 
the student is ready to check the answer, he or she can press a key and the 
program will display the correct solution:
  247
 +129
 ----
  376
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes
void inWait(); //Call this to pause until enter pressed

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned short numOne=0, numTwo=0, sumNum=0; //Two numbers to be added, sum 
    unsigned short userNum=0; //Chance for user to enter a number
    
    //Input Values
    
    //Process by mapping inputs to outputs
    numOne=rand()%899+100; //assign 3 digit number to numOne
    numTwo=rand()%899+100; //assign 3 digit number to numTwo
    sumNum=numOne+numTwo;  //Sum of numOne and numTwo  
    
    //Output values
    //Display the numbers to be added
    cout<<"Find the sum of the following numbers: "<<endl;
    cout<<"   "<<numOne<<endl; //number one
    cout<<"  +"<<numTwo<<endl; //Number two
    cout<<"  ----"<<endl;
    inWait(); //Pause while user calculates problem
    cout<<"Enter your solution: "<<endl;
    cin>>userNum; //Get user's number 
    while (cin.fail()) //Loop to validate input type
        {
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter your solution as a number!"<<endl;
            cin>>userNum;
        }
    if (userNum==sumNum) cout<<"Your answer is correct!"<<endl; //If user is correct
    else cout<<"Incorrect! The correct answer is: "<<sumNum<<endl; //User entered wrong answer
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//Function to pause until user hits the enter key 
void inWait(){
    char pauser=0;
    cout<<"Press <ENTER> to continue"<<endl;
    //cin.get(pauser); //inputting character or something to pause
    cin.ignore(256, '\n');  //ignore entire buffer in case multiple keys pressed
    cin.clear();  //resetting flags for cin to avoid conflict with future input
}