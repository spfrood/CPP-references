/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 24, 2017, 1:35 PM
  Purpose:  Query the digits
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
bool qryDigt(int,int);//Query the digits

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char digit;//See if you understand why and how this character works
    int number;//Number is any random number in the range 
    
    //Input values
    cout<<"This program finds a digit"<<endl;
    cout<<"Input a single digit"<<endl;
    cin>>digit;
    
    //Generate a random number
    number=rand();
    
    //Output the Roman Numeral
    if(qryDigt(number,digit-48)){//Remember digit is a character ascii
        cout<<digit<<" was found in "<<number<<endl;
    }else{
        cout<<digit<<" was not found in "<<number<<endl;
    }    

    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************** Find a Digit in the Number ******************************
//Description:  Query a number and compare results
//Inputs:
//     number -> Year from 1000 to 3000
//Outputs:
//     true ->  If the digit is found 
//******************************************************************************
bool qryDigt(int number,int digit){
    //Loop until you find the digit or exit
    do{
        if(number%10==digit)return true;
        number/=10;
    }while(number!=0);
    return false;
}