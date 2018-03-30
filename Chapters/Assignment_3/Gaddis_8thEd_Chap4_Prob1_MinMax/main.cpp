
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 12, 2017
 * Purpose: Gaddis, 8thEd, Chap4, Prob1
 *   Write a program that asks the user to enter two numbers. The program
 *   should use the conditional operator to determine which number is the 
 *   smaller and which is larger.
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
    short num1, num2;
        
    //Input Values
    cout<<"Please input two integers. They can be any value between "<<endl;
    cout<<"-31000 and 31000"<<endl;
    cout<<"Please enter the first integer:"<<endl;
    cin>>num1;
    cout<<"Please enter the second integer:"<<endl;
    cin>>num2;
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    if (num1>num2)
        cout<<"The first number you entered, "<<num1<<" is larger."<<endl;
    else if (num2>num1)
        cout<<"The second number you entered, "<<num2<<" is larger."<<endl;
    else cout<<"The numbers you entered were the same, "<<num1<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

