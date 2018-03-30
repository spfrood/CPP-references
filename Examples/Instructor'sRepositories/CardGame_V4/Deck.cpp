/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on May 13th, 2017, 1:15 PM
  Purpose:  Deck Class Implementation
 */

#include "Deck.h"
#include <cstdlib>

Deck::Deck(){
    nCrds=52;
    pctShuf=0.8;
    nShufle=7;
    index=new int[nCrds];
    card=new Card*[nCrds];
    for(int i=0;i<nCrds;i++){
        index[i]=i;
        card[i]=new Card(i);
    }
    delt=0;
}

Deck::~Deck(){
    delete []index;
    for(int i=0;i<nCrds;i++){
        delete card[i];
    }
    delete []card;
}

Card **Deck::deal(int toDeal){
    if(delt>pctShuf*nCrds)shuffle();
    Card **hand=new Card*[toDeal];
    for(int i=1;i<=toDeal;i++){
        hand[i-1]=new Card(index[delt++]);
    }
    return hand;
}
        
void Deck::shuffle(){
    //Shuffle
    for(int shuffle=1;shuffle<=nShufle;shuffle++){
        for(int eachCrd=0;eachCrd<nCrds;eachCrd++){
            int rnd=rand()%nCrds;
            int temp=index[eachCrd];
            index[eachCrd]=index[rnd];
            index[rnd]=temp;
        }
    }
}

void Deck::cleanup(Card **hand,int nCrds){
    for(int i=0;i<nCrds;i++){
        delete hand[i];
    }
    delete []hand;
}