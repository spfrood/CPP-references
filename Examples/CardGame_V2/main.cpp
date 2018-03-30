/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on April 5th, 2017, 1:15 PM
  Purpose:  Card Game
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Card.h"
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
    int *hand=deck.deal(fiveCrd);
    
    
    //Process by mapping inputs to outputs
    for(int i=1;i<=fiveCrd;i++){
        Card card(hand[i-1]);
        cout<<card.getFVal()<<card.getSuit()<<endl;
    }
    
    //Clean up
    delete []hand;
    
    //Exit stage right!
    return 0;
}