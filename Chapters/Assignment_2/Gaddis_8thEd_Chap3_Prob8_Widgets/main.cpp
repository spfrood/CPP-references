
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 11, 2017
 * Purpose: Gaddis, 8thEd, Chapter 3, Problem 8, Widgets
 * Calculate the number of widgets on a pallet based on the weight of the
 * loaded pallet and the weight of the pallet itself if widgets weigh 12.5 
 * pounds each 
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
const float WIDGET = 1.25e1;

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float numWidg, palWght, totWght;
    
    //Input Values
    cout<<"To calculate the number of widgets on the pallet please"<<endl;
    cout<<"provide the following information..."<<endl;
    cout<<"What is the weight of the pallet itself in pounds?"<<endl;
    cin>>palWght;
    cout<<"What is the total weight of the loaded pallet in pounds?"<<endl;
    cin>>totWght;
    
    //Process by mapping inputs to outputs
    numWidg = ((totWght-palWght)/WIDGET);
    
    //Output values
    cout<<setprecision(0)<<fixed;
    cout<<"The pallet contains: "<<numWidg<<" widgets."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

