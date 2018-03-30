
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 1, 2017, 12:05 PM
 * Purpose: 4. Safest Driving Area 
Write a program that determines which of five geographic regions within a 
major city (north, south, east, west, and central) had the fewest reported 
automobile accidents last year. It should have the following two functions, 
which are called by main .
• int getNumAccidents() is passed the name of a region. It asks the user for 
the number of automobile accidents reported in that region during the last 
year, validates the input, then returns it. It should be called once for each 
city region.
• void findLowest() is passed the five accident totals. It determines which 
is the smallest and prints the name of the region, along with its accident 
figure.
 
Input Validation: Do not accept an accident number that is less than 0. 
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes
int getNumAccidents(string);
void findLowest(int, int, int, int, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    string nortRiv="North Riverside";
    string eastRiv="East Riverside";
    string soutRiv="South Riverside";
    string westRiv="West Riverside";
    string centRiv="Central Riverside";
    int noRiv, eaRiv, soRiv, weRiv, ceRiv;
    
    //Input Values
    noRiv=getNumAccidents(nortRiv);
    eaRiv=getNumAccidents(eastRiv);
    soRiv=getNumAccidents(soutRiv);
    weRiv=getNumAccidents(westRiv);
    ceRiv=getNumAccidents(centRiv);
    
    //Process by mapping inputs to outputs
    findLowest(noRiv,eaRiv,soRiv,weRiv,ceRiv);
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//Determine and output the lowest number 
void findLowest(int nRiv, int eRiv, int sRiv, int wRiv, int cRiv){
    int lowAcc=nRiv;
    string nortRiv="North Riverside";
    string eastRiv="East Riverside";
    string soutRiv="South Riverside";
    string westRiv="West Riverside";
    string centRiv="Central Riverside";
    string lowReg=nortRiv;
    if (lowAcc>eRiv){
        lowReg=eastRiv;
        lowAcc=eRiv;
    }
    if (lowAcc>sRiv){
        lowReg=soutRiv;
        lowAcc=sRiv;
    }
    if (lowAcc>wRiv){
        lowReg=westRiv;
        lowAcc=wRiv;
    }
    if (lowAcc>cRiv) {
        lowReg=centRiv;
        lowAcc=cRiv;
    }
    cout<<lowReg<<" had the lowest number at "<<lowAcc<<" accidents."<<endl;
    
}

//Input the number of accidents
int getNumAccidents(string region){
    int numAcc;
    do {
    cout<<"Input the number of accidents for "<<region<<endl;
    cin>>numAcc;
    if (numAcc<0) cout<<"Invalid Number of Accidents!"<<endl;
    }while (numAcc<0);
    return numAcc;
}