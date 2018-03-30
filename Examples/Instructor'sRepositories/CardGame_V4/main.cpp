/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on May 13th, 2017, 1:15 PM
  Purpose:  Card Game using Abstraction, Derived and Polymorphism
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Deck.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare a deck of cards
    Deck deck;
    
    //Deal
    int fiveCrd=5;
    deck.shuffle();
    Card **hand=deck.deal(fiveCrd);
    
    //Take a look at the hand contents
    for(int i=0;i<fiveCrd;i++){
        cout<<hand[i]->getFVal()<<hand[i]->getSuit()<<endl;
    }
    
    //Clean up
    deck.cleanup(hand,fiveCrd);
    
    //Testing Derived card properties
    DrvCard test(3);
    cout<<test.getFN()<<endl;
    
    //Testing Polymorphic behavior
    Card *testP=new DrvCard(3);
    cout<<testP->getFVal()<<testP->getSuit()<<endl;
    
    
    //Exit stage right!
    return 0;
}