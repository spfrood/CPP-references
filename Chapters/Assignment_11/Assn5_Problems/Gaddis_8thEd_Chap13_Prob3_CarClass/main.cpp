
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 3, 2017, 5:03 PM
 * Purpose: 3. Car Class
Write a class named Car that has the following member variables:
• yearModel. An int that holds the car’s year model.
• make. A string that holds the make of the car.
• speed. An int that holds the car’s current speed.
In addition, the class should have the following constructor and other member 
    functions.
• Constructor. The constructor should accept the car’s year model and make as 
    arguments. These values should be assigned to the object’s year Model and 
    make member variables. The constructor should also assign 0 to the speed 
    member variables.
• Accessor. Appropriate accessor functions to get the values stored in an 
    object’s yearModel, make, and speed member variables.
• accelerate. The accelerate function should add 5 to the speed member variable 
    each time it is called.
• brake. The brake function should subtract 5 from the speed member variable 
    each time it is called.
Demonstrate the class in a program that creates a Car object, and then calls 
    the accelerate function five times. After each call to the accelerate 
    function, get the current speed of the car and display it. Then, call the 
    brake function five times. After each call to the brake function, get the 
    current speed of the car and display it.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "CarCls.h" //car class

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int year;
    string make;
    
    //Input Values for make and year
    cout<<"Enter the make: ";
    getline(cin, make);
    cout<<"Enter the year: ";
    cin>>year;
    CarCls car(year, make);
    
    //Process by mapping inputs to outputs
    
    //Output values 
    //call getter member functions to ouptout class data
    cout<<"Your "<<car.getYear()<<" "<<car.getMake()<<" is moving "<<car.getSpd()<<" MPH."<<endl;
    for (int i=0;i<5;i++) {
        car.accel(); //call accel member function
    }
    cout<<endl;
    cout<<"Your car is now traveling at: "<<car.getSpd()<<" MPH."<<endl;
    for (int i=0;i<5;i++) {
        car.decel(); //call decel member function
    }
    cout<<endl;
    cout<<"Your car is now traveling at: "<<car.getSpd()<<" MPH."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

