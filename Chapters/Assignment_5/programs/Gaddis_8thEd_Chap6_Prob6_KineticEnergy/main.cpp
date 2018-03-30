
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 2, 2017, 9:47 AM
 * Purpose: 6. Kinetic Energy
In physics, an object that is in motion is said to have kinetic energy. The
following formula can be used to determine a moving object’s kinetic energy:
 *   KE = 1/2 m v^2
The variables in the formula are as follows: KE is the kinetic energy, m is 
the object’s mass in kilograms, and v is the object’s velocity, in meters per 
second. Write a function named kineticEnergy that accepts an object’s mass 
(in kilograms) and velocity (in meters per second) as arguments. The function 
should return the amount of kinetic energy that the object has. Demonstrate 
the function by calling it in a program that asks the user to enter values 
for mass and velocity.
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
float kinEner(float, float);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float mass=0.0f, velo=0.0f;
    
    //Input Values
    do{
    cout<<"Please input the mass of the object (kilograms):"<<endl;
    cin>>mass;
    if (mass<=0)cout<<"An object has to have mass to be an object!"<<endl;
    } while (mass<=0);
    do{
    cout<<"Please input the velocity of the object (meters per second):"<<endl;
    cin>>velo;
    if (velo<0) cout<<"Velocity must be a positive value!"<<endl;
    } while (velo<0);
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"The kinetic energy of the object is:"<<endl;
    cout<<setprecision(2)<<fixed<<kinEner(mass, velo)<<" joules."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float kinEner(float objMass, float objVelo){
    //Formula is  *   KE = 1/2 m v^2
    return ((objMass*(objVelo*objVelo))/2);
}