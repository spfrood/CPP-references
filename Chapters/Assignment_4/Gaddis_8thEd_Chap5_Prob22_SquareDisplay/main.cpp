
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 19, 2017, 4:30 PM
 * Purpose: Gaddis, 8th Ed, Chapter 5, Prob 22, Draw a Square
 * Draw a square with user provided info for the side.
 * !!Modified program to draw a rectangle with user provided height
 * and width. 
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
    short height, width;
    
    //Input Values
    while (height < 1 || height > 15 || width < 1 || width > 15) {
        cout<<"Please enter the height between 1 and 15: "<<endl;
        cin>>height;
        cout<<"Please enter the width between 1 and 15: "<<endl;
        cin>>width;
        if (height < 1 || height > 15){
            cout<<"Invalid Height!"<<endl;
        }
        if (width < 1 || width > 15){
            cout<<"Invalid Width!"<<endl;
        }
    } 
    cout<<endl;
    
    //Process by mapping inputs to outputs
    
    //Output values
    for (int rows = 1; rows <= height; rows++) {
        for (int cols = 1; cols <= width; cols++) {
            cout<<" X ";
        }
        cout<<endl;
    }
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

