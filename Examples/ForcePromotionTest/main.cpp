
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Template to be used for all programming projects 
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
    short a, b, c;
    float g, h, i, j;
    
    //Input Values
    g = 10, h = 12.5, i = 95000;
    
    cout<<"Short variables:       a = "<<sizeof a<<endl;
    cout<<"                       b = "<<sizeof b<<endl;
    cout<<"                       c = "<<sizeof c<<endl;
    cout<<"Float variables :      g = "<<sizeof g<<endl;
    cout<<"                       h = "<<sizeof h<<endl;
    cout<<"                       i = "<<sizeof i<<endl;
    cout<<"                       j = "<<sizeof j<<endl;
    
    //Process by mapping inputs to outputs
    a = g*3;
    b = h*3;
    c = i*3;
    j = i*3;
    
    //Output values
    cout<<"Short variables:       a = "<<sizeof a<<endl;
    cout<<"                       b = "<<sizeof b<<endl;
    cout<<"                       c = "<<sizeof c<<endl;
    cout<<"Float variables :      g = "<<sizeof g<<endl;
    cout<<"                       h = "<<sizeof h<<endl;
    cout<<"                       i = "<<sizeof i<<endl;
    cout<<"                       j = "<<sizeof j<<endl;
    cout<<"int values now: "<<a<<" "<<b<<" "<<c<<endl;
    cout<<"value of j = "<<j<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

