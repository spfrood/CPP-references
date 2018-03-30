
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 5, 2017, 12:19 PM
 * Purpose: Savitch 8th Edition Chap. 1 Problem 10
 * Draw a big C on the screen with a character of the
 * user's choosing. 
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
    char c;
    
    //Input Values
    cout<<"This program draws a large ASCII C"<<endl;
    cout<<"using a letter of the user's choosing."<<endl;
    cout<<"Which letter would you like to use?"<<endl;
    cin>>c;
    
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<" "<<endl<<endl;
    cout<<"    "<<c<<c<<c<<endl;
    cout<<"   "<<c<<"   "<<c<<endl;
    cout<<"   "<<c<<endl;
    cout<<"   "<<c<<endl;
    cout<<"   "<<c<<endl;
    cout<<"   "<<c<<endl;
    cout<<"   "<<c<<endl;
    cout<<"   "<<c<<"   "<<c<<endl;
    cout<<"    "<<c<<c<<c<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

