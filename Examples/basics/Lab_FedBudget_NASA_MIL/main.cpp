
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 10, 2017
 * Purpose: Calculate the percentage of total federal budget
 *          spent on Military and NASA. Following info:
 *          Fed Budget:       3.54 trillion   or 3.54e12
 *          Nat. Def:         533 billion     or 533e9
 *          NASA budget:      19.3 billion    or 19.3e9
 *          Federal Budget numbers from:
 *          http://federal-budget.insidegov.com/l/119/2016-Estimate
 *          NASA numbers from:
 *          https://en.wikipedia.org/wiki/Budget_of_NASA
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
    long int totFed = 3.54e12,
             milBud = 533e9,
             nasaBud = 19.3e9;
    float milPer, nasaPer;
    
    //Input Values
    
    
    //Process by mapping inputs to outputs
    milPer = (static_cast<float>(milBud)/totFed) * 100;
    nasaPer = (static_cast<float>(nasaBud) / totFed) * 100;
    
    //Output values
    cout<<"The Total Federal Budget is:     $"<<totFed<<endl;
    cout<<"The Total Military Spending is:  $"<<milBud<<endl;
    cout<<"The Total NASA spending is:      $"<<nasaBud<<endl;
    cout<<setprecision(1)<<fixed;
    cout<<"\nMilitary spending is "<<milPer<<"% of the budget"<<endl;
    cout<<"NASA spending is "<<nasaPer<<"% of the budget"<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

