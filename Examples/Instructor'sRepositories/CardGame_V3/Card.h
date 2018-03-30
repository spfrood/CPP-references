/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on April 5th, 2017, 1:15 PM
  Purpose:  Card Class Specification
 */

#ifndef CARD_H
#define CARD_H

class Card{
    private:
        unsigned char cNumber;
    public:
        Card(unsigned char);
        char getSuit();
        char getFVal();
        char getNum();
        char getCNum();
};

#endif /* CARD_H */