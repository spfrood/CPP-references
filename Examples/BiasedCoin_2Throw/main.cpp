/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 24, 2017, 12:23 PM
  Purpose:  Biased Coint 2 at a time
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
    unsigned int nTT=0,nTH=0,nHT=0,nHH=0,nCoins;
    
    //Input values
    cout<<"Coin Flipping Problem"<<endl;
    cout<<"Input the probability of Tails"<<endl;
    cin>>pTails;
    cout<<"Input the number of coin flips"<<endl;
    cin>>nCoins;
    
    //Process by mapping inputs to outputs
    pHeads=1-pTails;
    for(unsigned int flip=1;flip<=nCoins;flip++){
        float prob1=rand()/static_cast<float>(MAXRND);
        float prob2=rand()/static_cast<float>(MAXRND);
        if(prob1<=pTails&&prob2<=pTails)nTT++;
        else if(prob1<=pTails&&prob2>pTails)nTH++;
        else if(prob1>pTails&&prob2>pTails)nHH++;
        else nHT++;
    }
    
    //Output values
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"Percentage input for Prob of Tails = "<<pTails<<endl;
    cout<<"Percentage input for Prob of Heads = "<<pHeads<<endl;
    cout<<"Percentage output for 2 Tails = "
            <<static_cast<float>(nTT)/nCoins<<endl;
    cout<<"Percentage output for 1 Tail 1 Head = "
            <<static_cast<float>(nTH)/nCoins<<endl;
    cout<<"Percentage output for 1 Head 1 Tail = "
            <<static_cast<float>(nHT)/nCoins<<endl;
    cout<<"Percentage output for 2 Heads = "
            <<static_cast<float>(nHH)/nCoins<<endl;
    
    //Exit stage right!
    return 0;
}