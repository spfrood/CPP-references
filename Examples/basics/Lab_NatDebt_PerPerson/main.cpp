
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 10, 2017
 * Purpose: Calculate the increase in the total debt per person 
 *          based on the increase in national debt from 2008 to 2016
 *          Nat. debt data from: 
 *          https://en.wikipedia.org/wiki/National_debt_of_the_United_States
 *          2008 Nat. debt:  10.0e12
 *          2016 Nat. debt:  19.4e12
 *          Population data from:
 *          http://www.worldometers.info/world-population/us-population/
 *          2008 population: 304.5e6
 *          2016 population: 324.1e6
 *          
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
    long int pop2008 = 304.5e6,
             pop2016 = 324.1e6,
             det2008 = 10.0e12,
             det2016 = 19.4e12;
    float per2008, per2016, perIncr;
    
    //Input Values
    
    
    //Process by mapping inputs to outputs
    per2008 = static_cast<float>(det2008) / pop2008;
    per2016 = static_cast<float>(det2016) / pop2016;
    perIncr = per2016 - per2008;
    
    //Output values
    cout<<setprecision(0)<<fixed;
    cout<<"This program details the national debt burden carried by"<<endl;
    cout<<"each member of the population in the year 2008 and 2016."<<endl;
    cout<<"The population in 2008:                  "<<pop2008<<endl;
    cout<<"The national debt in 2008:              $"<<det2008<<endl;
    cout<<"The national debt per persion in 2008:  $"<<per2008<<endl;
    cout<<"The population in 2016:                  "<<pop2016<<endl;
    cout<<"The national debt in 2016:              $"<<det2016<<endl;
    cout<<"The national debt per persion in 2016:  $"<<per2016<<endl;
    cout<<"The increase in debt per person is:     $"<<perIncr<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

