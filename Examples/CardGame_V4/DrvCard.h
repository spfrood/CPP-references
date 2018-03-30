/* 
 * File:   DrvCard.h
 * Author: mlehrjava
 *
 * Created on May 13, 2017, 7:01 PM
 */

#ifndef DRVCARD_H
#define	DRVCARD_H

#include <string>
using namespace std;

#include "Card.h"

class DrvCard:public Card {
    private:
        string fileNme;
    public:
        DrvCard(unsigned char cNum):Card(cNum){
            fileNme=".jpg";
            fileNme=getSuit()+fileNme;
            fileNme=getFVal()+fileNme;
        }
        string getFN(){
            return fileNme;
        }
};

#endif	/* DRVCARD_H */

