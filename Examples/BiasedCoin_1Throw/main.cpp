/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 24, 2017, 12:23 PM
  Purpose:  Template to be used in all programming
            projects!
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const unsigned int MAXRND=pow(2,31)-1;

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    float pTails,pHeads;
    unsigned int nTails=0,nHeads=0,nCoins;
    
    //Input values
    cout<<"Coin Flipping Problem"<<endl;
    cout<<"Input the probability of Tails"<<endl;
    cin>>pTails;
    cout<<"Input the number of coin flips"<<endl;
    cin>>nCoins;
    
    //Process by mapping inputs to outputs
    pHeads=1-pTails;
    for(unsigned int flip=1;flip<=nCoins;flip++){
        float prob=rand()/static_cast<float>(MAXRND);
        if(prob<=pTails)nTails++;
        else nHeads++;
    }
    
    //Output values
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"Percentage input for Prob of Tails = "<<pTails<<endl;
    cout<<"Percentage input for Prob of Heads = "<<pHeads<<endl;
    cout<<"Percentage output for Prob of Tails = "
            <<static_cast<float>(nTails)/nCoins<<endl;
    cout<<"Percentage output for Prob of Heads = "
            <<static_cast<float>(nHeads)/nCoins<<endl;

    //Exit stage right!
    return 0;
}