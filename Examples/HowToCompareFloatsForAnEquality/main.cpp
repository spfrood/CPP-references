/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 3, 2017, 12:15 PM
  Purpose:  How to compare a float for an equality
          Never use an equality.  Always a difference and a tolerance within the
          significant number of digits or accuracy of the data type.
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const float MILLION=1.0e6f;//Significant digits associated with a float

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv){
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and initialize Variables
    float nmratr,dnmintr,answer;//Variables for numerator and denominator
    dnmintr=rand()%10+1; //A number between 1 and 10
    nmratr=dnmintr*(rand()%10+1);//A number that produces a result from 1 and 10
    
    //Input values and do a minor validation
    do{
        cout<<"What is "<<nmratr<<" divided by "<<dnmintr<<" ? "<<endl;
        cin>>answer;
    }while(answer<0 and answer>11);
    
    //Create a tolerance around the data types accuracy.
    float tol=abs((nmratr/dnmintr)/MILLION);//Tolerance within significant digits
    
    //Proper way to test for a float equality.  Not ==
    if(abs(answer-nmratr/dnmintr)<tol)cout<<"Correct"<<endl;
    else cout<<"Incorrect"<<endl;

    //Exit stage right!
    return 0;
}