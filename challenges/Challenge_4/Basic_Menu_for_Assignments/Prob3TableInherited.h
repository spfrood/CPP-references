/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3TableInherited.h
 * Author: scott_r_parker
 *
 * Created on June 7, 2017, 2:28 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

#include "Prob3Table.h"


template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
    protected:
    T *augTable;                                  //Augmented Table with sums
public:
    Prob3TableInherited(char *,int,int);          //Constructor
    ~Prob3TableInherited(){delete [] augTable;};  //Destructor
    const T *getAugTable(void){return augTable;}; 
};

template <class T>
Prob3TableInherited<T>::Prob3TableInherited(char *fname, int rows, int cols):Prob3Table<T>::Prob3Table(fname, rows, cols) {
    augTable=new T[(rows+1)*(cols+1)];
    for (int i=0;i<(rows+1)*(cols+1);i++) { //setting values on augTable
        if (i<6) {
            augTable[i]=this->table[i]; //Setting values for first row of table
        } else if (i==6) {
            augTable[i]=this->rowSum[0]; //row total
        } else if (i<13) {
            augTable[i]=this->table[i-1]; //2nd row values
        } else if (i==13) {
            augTable[i]=this->rowSum[1]; //2nd row total
        } else if (i<20) {
            augTable[i]=this->table[i-2]; //3rd row values
        } else if (i==20) {
            augTable[i]=this->rowSum[2]; //3rd row total
        } else if (i<27) {
            augTable[i]=this->table[i-3]; //4th row values
        } else if (i==27) {
            augTable[i]=this->rowSum[3]; //4th row total
        } else if (i<34) {
            augTable[i]=this->table[i-4]; //5th (final) row values
        } else if (i==34) {
            augTable[i]=this->rowSum[4]; //5th row total
        } else if (i<41) {
            augTable[i]=this->colSum[i-35]; //values for column sums
        } else {
            augTable[i]=this->grandTotal; //grand total
        }
    }
}


#endif /* PROB3TABLEINHERITED_H */

