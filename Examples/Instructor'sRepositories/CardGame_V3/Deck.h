/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on May 13th, 2017, 1:15 PM
  Purpose:  Deck Class Specification
 */

#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck{
    private:
        int *index;   //Index of the 52 cards
        Card **card;  //Array of cards in the deck
        int delt;     //Count of how many cards have been delt
        int nCrds;    //Number of cards in the deck
        float pctShuf;//Percentage cards delt, when to Shuffle
        int nShufle;  //Number of shuffles to give random results
    public:
        Deck();                    //Construct the Deck
        ~Deck();                   //Destroy the Deck
        Card **deal(int);          //Deal the cards
        void shuffle();            //Shuffle the index
        void cleanup(Card **,int); //Clean up the cards delt
};

#endif /* DECK_H */

