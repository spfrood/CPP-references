
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 24, 2017, 12:23 PM
 * Purpose: Biased Coin two coins at a time
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const unsigned int MAXRND = pow(2,31)-1;

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seeed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    float pTails,pHeads;
    unsigned int nTT=0,nTH=0,nHT=0,nHH=0,nCoins;
    
    //Input Values
    cout<<"Coin Flipping Problem"<<endl;
    cout<<"Input probability of Tails"<<endl;
    cin>>pTails;
    cout<<"Input number of times to flip the coin"<<endl;
    cin>>nCoins;
    
    //Process by mapping inputs to outputs
    pHeads=1-pTails;
    for(unsigned int flip=1;flip<=nCoins;flip++){
        float prob1=rand()/static_cast<float>(MAXRND);
        float prob2=rand()/static_cast<float>(MAXRND);
        if(prob1<=pTails&&prob2<=pTails)nTT++;
        else if (prob1<=pTails&&prob2>pTails)nTH++;
        else if (prob1>pTails&&prob2>pTails)nHH++;
        else nHT++;
    }
    
    //Output values
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"Percentage input for probability of tails = "<<pTails<<endl;
    cout<<"Percentage input for probability of heads = "<<pHeads<<endl;
    cout<<"Percentage output for probability of 2 tails: "
            <<static_cast<float>(nTT)/nCoins<<endl;
    cout<<"Percentage output for probability of 2 heads: "
            <<static_cast<float>(nHH)/nCoins<<endl;
    cout<<"Percentage output for probability of 1 Tail 1 Head: "
            <<static_cast<float>(nTH)/nCoins<<endl;
    cout<<"Percentage output for probability of 1 Head 1 Tail: "
            <<static_cast<float>(nHT)/nCoins<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

