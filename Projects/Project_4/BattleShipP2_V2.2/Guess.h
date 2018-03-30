/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Guess.h
 * Author: scott_r_parker
 *
 * Created on May 24, 2017, 4:54 PM
 */

#ifndef GUESS_H
#define GUESS_H

#include <iostream>
using namespace std;

class Guess; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const Guess &);
istream &operator >> (istream &, Guess &);

class Guess{
private:
    int targRow=11;
    int targCol=11;
    
public:
    Guess();
    
    void setRow(int); //set the row value manually
    void setCol(int); //set the column value manually
    int getRow(); //return the row guess
    int getCol(); //Return the column guess
    
    // Friends
    friend ostream &operator << (ostream &, const Guess &);
    friend istream &operator >> (istream &, Guess &);
    
};

#endif /* GUESS_H */

