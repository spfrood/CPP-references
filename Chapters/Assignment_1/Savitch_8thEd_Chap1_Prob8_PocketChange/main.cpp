
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 5, 2017
 * Purpose: Calculate pocket change 
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
    const char quarter=25,  //number of cents in coinage
               dime=10,
               nickle=5,
               penny=1;
    char nQrtr,nDime,nNickl,nPenny;
    unsigned short total; //Total pocket change in cents
    
    //Input Values
    cout<<"This calculates the amount of your pocket change"<<endl;
    cout<<"how many Quarters, Nickles, Dimes, and Pennies do"<<endl;
    cout<<"you have in your pocket?"<<endl;
    cout<<"Type in all on the same line. i.e. 3 4 0 2"<<endl;
    cout<<"Maximum of any value must be less than 10"<<endl;
    cin>>nQrtr>>nDime>>nNickl>>nPenny;
    
    
    //Process by mapping inputs to outputs
    total = (nQrtr-48)*quarter +
            (nDime-48)*dime    +
            (nNickl-48)*nickle +
            (nPenny-48)*penny;
    
    //Output values
    cout<<"The coins in your pocket = "<<total<<" cents"<<endl;
    cout<<"The coins in your pocket = $"<<total/100.0f<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

