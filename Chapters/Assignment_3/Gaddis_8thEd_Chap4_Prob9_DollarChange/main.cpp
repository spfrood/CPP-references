
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 12, 2017
 * Purpose: Gaddis, 8thEd, Chap4, Prob9
 *   Create a change-counting game that gets the user to enter the number
 * of coins required to make exactly one dollar. The program should ask the
 * user to enter the number of pennies, nickels, dimes, and quarters. If 
 * the total value of the coins entered is equal to one dollar, the program
 * should congratulate the user for winning the game. Otherwise, the 
 * program should display a message indicating whether the amount entered 
 * was more than or less than one dollar.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const short PENNY = 1;
const short NICKEL = 5;
const short DIME = 10;
const short QUARTER = 25;

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    short numP, numN, numD, numQ, total;
        
    //Input Values
    cout<<"This program will play a game where you input coins to"<<endl;
    cout<<"try to get the total to add up to exactly one dollar."<<endl;
    cout<<"Please input the number of coins requested at the prompt."<<endl;
    cout<<"How many pennies are there?"<<endl;
    cin>>numP;
    cout<<"How many nickels are there?"<<endl;
    cin>>numN;
    cout<<"How many dimes are there?"<<endl;
    cin>>numD;
    cout<<"How many quarters are there?"<<endl;
    cin>>numQ;
    
    //Process by mapping inputs to outputs
    total = (numP*PENNY)+(numN*NICKEL)+(numD*DIME)+(numQ*QUARTER);
    
    //Output values
    if (total>100)
        cout<<"The total you entered is worth more than $1.00, sorry."<<endl;
    else if (total<100)
        cout<<"The total you entered is worth less than $1.00, sorry."<<endl;
    else cout<<"The total comes out to $1.00! You Win!"<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

