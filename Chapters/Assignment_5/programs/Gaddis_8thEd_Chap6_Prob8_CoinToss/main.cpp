
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 1, 2017, 7:04 PM
 * Purpose: 8. Coin Toss
Write a function named coinToss that simulates the tossing of a coin. When 
you call the function, it should generate a random number in the range of 1 
through 2. If the random number is 1, the function should display “heads.” 
If the random number is 2, the function should display “tails.” Demonstrate 
the function in a program that asks the user how many times the coin should 
be tossed and then simulates the tossing of the coin that number of times. 
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
int coinToss();

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int heads=0, tails=0, flip=0, toss=0;
    
    //Input Values
    
    //Process by mapping inputs to outputs
    cout<<"How many times would you like to flip the coin?"<<endl;
    cin>>flip;
    for (int i=1;i<=flip;i++){
        cout<<i<<".  ";
        toss=coinToss();
        if (toss==1)heads++;
        if (toss==2)tails++; 
    }
    
    //Output values
    cout<<"Your coin came up heads "<<heads<<" times."<<endl;
    cout<<"Your coin came up tails "<<tails<<" times."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

int coinToss(){
    int coin = rand()%2+1; //value from 1 to 2
    if (coin==1)cout<<"Heads"<<endl;
    if (coin==2)cout<<"Tails"<<endl;
    return coin;
}
