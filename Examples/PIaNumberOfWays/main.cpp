/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 23, 2017, 11:00 AM
  Purpose:  PI Function comparison
 * 
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
const float PI=4*atan(1);//Geometric identity
const int MAXRND=pow(2,31)-1;//Largest random number

//Function Prototypes
float piSeres(int);
float piRand(int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int nTerms;
    float piRnd,piSrs;
    float pCntErC,pCntErS;
    
    //Input values
    cout<<"Estimate PI"<<endl;
    cout<<"Input the number of Terms"<<endl;
    cin>>nTerms;
    
    //Process by mapping inputs to outputs
    piSrs=piSeres(nTerms);
    pCntErS=(PI-piSrs)/PI*100;
    piRnd=piRand(nTerms);
    pCntErC=(PI-piRnd)/PI*100;
    
    //Output values
    cout<<"Pi from the Math Library = "<<PI<<endl;
    cout<<"Pi approximated using infinite Series = "<<piSrs<<endl;
    cout<<"Pi error = "<<pCntErS<<"%"<<endl;
    cout<<"Pi approximated using random numbers = "<<piRnd<<endl;
    cout<<"Pi error = "<<pCntErC<<"%"<<endl;

    //Exit stage right!
    return 0;
}

float piSeres(int nTerms){
    //Declare variables
    int sign=-1;
    float pi=1;
    //Loop the series
    for(int term=2,div=3;term<=nTerms;term++,div+=2){
        pi+=(sign/static_cast<float>(div));
        sign*=-1;
    }
    return 4*pi;
}

float piRand(int nDarts){
    //Declare variables
    int inCircl=0;
    //Loop and count how many darts fell inside circle
    for(int dart=1;dart<=nDarts;dart++){
        float x=static_cast<float>(rand())/MAXRND;//Random number (0,1)
        float y=static_cast<float>(rand())/MAXRND;//Random number (0,1)
        if(x*x+y*y<1)inCircl++;
    }
    //Return the pi estimate
    return 4.0f*inCircl/nDarts;
}