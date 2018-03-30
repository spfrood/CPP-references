
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 31, 2017, 1:02 PM
 * Purpose: Gaddis, 8thEd, Chap6, Prob1
 * 1. Markup
 * Write a program that asks the user to enter an item’s wholesale cost and 
 * its markup percentage. It should then display the item’s retail price. For 
 * example:
 * • If an item’s wholesale cost is 5.00 and its markup percentage is 100%, then
 * the item’s retail price is 10.00.
 * • If an item’s wholesale cost is 5.00 and its markup percentage is 50%, then
 * the item’s retail price is 7.50.
 * The program should have a function named calculateRetail that receives the 
 * wholesale cost and the markup percentage as arguments and returns the retail
 * price of the item.
 * Input Validation: Do not accept negative values for either the wholesale 
 * cost of the item or the markup percentage.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes
float calculateRetail(float, float); //Name is specified in book! Too many chars

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float wholCst=0.00f, markUp=0.00f;
    
    //Input Values
    do{
        cout<<"Enter the item's wholesale price: "<<endl;
        cin>>wholCst;
        cout<<"Enter the item's markup percentage (enter percentage value,"<<endl;
        cout<<"no decimal. Value less than 1.0 will return less than 1%)"<<endl;
        cin>>markUp;
        //Outputting instructions if negative value entered
        if (wholCst<0||markUp<0) cout<<"Do not enter negative values!"<<endl;
    } while (wholCst<0||markUp<0);
    
    //Process by mapping inputs to outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The retail price is $"<<calculateRetail(wholCst, markUp)<<endl;
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//Function to calculate the retail price of the item
float calculateRetail(float cost, float margin){
    //Convert the markup value to a percentage
    float marPer=margin/100;
    return (cost*marPer+cost);
}