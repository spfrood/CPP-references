
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 24, 2017, 12:23 PM
 * Purpose: Biased Coin 1 coin only
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
    unsigned int nTails=0,nHeads=0,nCoins;
    
    //Input Values
    cout<<"Coin Flipping Problem"<<endl;
    cout<<"Input probability of Tails"<<endl;
    cin>>pTails;
    cout<<"Input number of times to flip the coin"<<endl;
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
    cout<<"Percentage input for probability of tails = "<<pTails<<endl;
    cout<<"Percentage input for probability of heads = "<<pHeads<<endl;
    cout<<"Percentage output for probability of tails: "
            <<static_cast<float>(nTails)/nCoins<<endl;
    cout<<"Percentage output for probability of heads: "
            <<static_cast<float>(nHeads)/nCoins<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

