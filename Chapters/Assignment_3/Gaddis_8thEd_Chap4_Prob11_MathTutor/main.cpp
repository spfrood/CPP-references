
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 15, 2017
 * Purpose: Use the random number generator to input two numbers and 
 * calculate the sum. The user then has an opportunity to enter the
 * sum and the program will display whether the correct number was 
 * entered or not and display an appropriate message.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned int num1, num2, sum, guess;
    
    //Input Values
    num1=rand()%999+1; //Give value 1 to 1000
    num2=rand()%999+1; //give value 1 to 1000
    
    //Process by mapping inputs to outputs
    sum=num1+num2;
    
    //Output values
    cout<<"Enter the total of the following two numbers:"<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;
    cin>>guess;
    if (guess == sum) cout<<"Correct! Good job!"<<endl;
    else cout<<"Incorrect. The actual sum is: "<<sum<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

