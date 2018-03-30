/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on April 17th, 2017, 1:15 PM
  Purpose:  Deck Class Specification
 */

#ifndef DECK_H
#define DECK_H

class Deck{
    private:
        int *index;
        int delt;
        int nCrds;
        float pctShuf;
        int nShufle;
    public:
        Deck();
        ~Deck(){delete []index;};
        int *deal(int);
        void shuffle();
};

#endif /* DECK_H */

