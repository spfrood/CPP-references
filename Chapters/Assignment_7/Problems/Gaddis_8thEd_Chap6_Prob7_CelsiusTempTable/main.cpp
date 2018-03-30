/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 11, 2017
 * Purpose: Gaddis, 8thEd, Chapter 6, Problem 7
 Celsius Temperature Table
The formula for converting a temperature from Fahrenheit to Celsius is
C   59(F   32)
where F is the Fahrenheit temperature and C is the Celsius temperature. Write 
a function named celsius that accepts a Fahrenheit temperature as an 
argument. The function should return the temperature, converted to Celsius. 
Demonstrate the function by calling it in a loop that displays a table of the 
Fahrenheit temperatures 0 through 20 and their Celsius equivalents.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#define C_RED     "\x1b[31m"  //For red text
#define C_GREEN   "\x1b[32m"  //for green text
#define C_CYAN    "\x1b[36m"  //for cyan text
#define C_RESET   "\x1b[0m"   //rest color to black

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes
float celsius(float);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float fahTemp=0.0f;
    //Input Values
    cout<<"This program accepts a Fahrenheit temperature as input and will"<<endl;
    cout<<"Convert it to Celsius. It will also give the conversions of the"<<endl;
    cout<<"temperatures 10 degrees Fahrenheit below the provided temperature"<<endl;
    cout<<"and conversions for temperatures 10 degrees above the provided"<<endl;
    cout<<"temperature. What temperature would you like to convert to Celsius?"<<endl;
    cin>>fahTemp;
    
    //Process by mapping inputs to outputs
    
    //Output values
    for (int i=(fahTemp-10);i<=(fahTemp+10);i++){
        if (i<fahTemp){
            cout<<C_CYAN<<setprecision(2)<<fixed<<showpoint<<i
                    <<" F  =  "<<celsius(i)<<" C"<<C_RESET<<endl;
        }
        else if (i==fahTemp){
            cout<<C_GREEN<<setprecision(2)<<fixed<<showpoint<<i
                    <<" F  =  "<<celsius(i)<<" C"<<C_RESET<<endl;
        }
        else {
            cout<<C_RED<<setprecision(2)<<fixed<<showpoint<<i
                    <<" F  =  "<<celsius(i)<<" C"<<C_RESET<<endl;
        }
    }
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float celsius(float fahTemp){
    float celTemp;
    celTemp = ((fahTemp-32)*5)/9;
    return celTemp;
}