/* 
  File:   main.cpp
  Author: Scott Parker
  Created on January 24, 2017, 10:53 AM
  Purpose:  Query the Digits
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
bool qryDigt(int,int); //Query the digits

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char digit;
    int number;
    
    //Input values
    cout<<"Input a single digit"<<endl;
    cin>>digit;
    
    //Generate a random number
    number=rand();
    
    //Output the Roman Numeral
    if(qryDigt(number,digit-48)){  //Digit is char type so need numeric value of
        cout<<digit<<" was found in "<<number<<endl;
    }
    else{
        cout<<digit<<" was not found in "<<number<<endl;
    }

    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************** Querying Digits in Number *******************************
//Description:  Query a number to compare results 
//Inputs:
//     number -> 
//Outputs:
//     true if digit is found
//******************************************************************************
bool qryDigt(int number,int digit){
    //Loop until digit is found or exit
    do{
        if(number%10==digit)return true;
        number/=10;
    }while(number!=0);
    return false;
}