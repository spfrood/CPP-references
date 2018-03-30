
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 11, 2017
 * Purpose: Prob 6 in Gaddis, Chapter 3. Ingredient Adjuster
 *      A cookie recipe calls for the following ingredients:
 * 1.5 cups of sugar
 * 1 cup of butter
 * 2.75 cups of flour
 * The recipe produces 48 cookeis with this amount of the ingredients.
 * Write a program that asks the user how many cookeis he or she wants 
 * to make, and then displays the number of cups of each ingredient 
 * needed for the specified number of cookies.
 */

//System Libraries
#include <iostream>
#include <iomanip>
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
    short cookies;
    float sugarC, butterC, flourC;
    
    
    //Input Values
    cout<<"How many cookies would you like to make?"<<endl;
    cin>>cookies;
    sugarC = 1.5/48;
    butterC = 1.0/48;
    flourC = 2.75/48;
    
    //Process by mapping inputs to outputs
    cout<<setprecision(2)<<fixed;
    cout<<"In order to make "<<cookies<<" cookies you will need"<<endl;
    cout<<"the following amounts of ingredients:"<<endl;
    cout<<sugarC*cookies<<" cups of sugar"<<endl;
    cout<<butterC*cookies<<" cups of butter"<<endl;
    cout<<flourC*cookies<<" cups of flour"<<endl;
    
    
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

