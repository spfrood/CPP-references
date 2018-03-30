/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob1Random.cpp
 * Author: scott_r_parker
 * 
 * Created on June 5, 2017, 9:32 PM
 */

#include "Prob1Random.h"

Prob1Random::Prob1Random(const char size, const char *values) {
    set = new char[size];
    freq=new int [size];
    nset=size;
    numRand=0;
    for (int i=0;i<size;i++) {
        set[i]=values[i];
        freq[i]=0;
    }
    
}

Prob1Random::~Prob1Random() {
    delete [] set;
    delete [] freq;
}

char Prob1Random::randFromSet(void) { //Returns a random number from the set
    numRand++;
    int val=rand()%5;
    freq[val]++;
    return set[rand()%5];
}

//Returns the frequency histogram
int *Prob1Random::getFreq(void) const{ 
    int *temp= new int[nset];
    for (int i=0;i<nset;i++) {
        temp[i]=freq[i];
    }
    return temp;
//    return freq;
}

//Returns the set used
char *Prob1Random::getSet(void) const{ 
    char *temp= new char[nset];
    for (int i=0;i<nset;i++) {
        temp[i]=set[i];
    }
    return temp;
//    return set;
}

//Gets the number of times randFromSet has been called
int Prob1Random::getNumRand(void) const{ 
    return numRand;
}
		                                          
