/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3Classes.h
 * Author: scott_r_parker
 *
 * Created on June 6, 2017, 8:23 PM
 */

#ifndef PROB3CLASSES_H
#define PROB3CLASSES_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<class T>
class Prob3Table
{
protected:
    int rows;                                 //Number of rows in the table
    int cols;                                 //Number of cols in the table
    T *rowSum;                                //RowSum array
    T *colSum;                                //ColSum array
    T *table;                                 //Table array
    T grandTotal;                             //Grand total
    void calcTable(void);                     //Calculate all the sums
public:
    Prob3Table(char *,int,int);               //Constructor then Destructor
    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
    const T *getTable(void){return table;};
    const T *getRowSum(void){return rowSum;};
    const T *getColSum(void){return colSum;};
    T getGrandTotal(void){return grandTotal;};
};

template <class T>
Prob3Table<T>::Prob3Table(char *fname, int rows, int cols) 
{
    grandTotal=0;
    table=new T[rows*cols];
    rowSum=new T[rows];
    colSum=new T[cols];
    ifstream in;
    in.open("Problem3.txt"); //opening data file
    for (int i=0;i<rows;i++){  //inputting data 
        for (int j=0;j<cols;j++){ 
            in>>table[i*cols+j];
        }
    }
    in.close();  //closing data file
    
    for (int i=0;i<rows;i++) { //Setting values of T *rowSum; 
        T temp=0;
        for (int j=0;j<cols;j++) {
            if (i==0) {
                temp+=table[j];
                rowSum[i]=temp;
            } else if (i==1) {
                temp+=table[j+6];
                rowSum[i]=temp;
            } else if (i==2) {
                temp+=table[j+12];
                rowSum[i]=temp;
            } else if (i==3) {
                temp+=table[j+18];
                rowSum[i]=temp;
            } else {
                temp+=table[j+24];
                rowSum[i]=temp;
            }
        }
    }
    
    for (int i=0;i<cols;i++) { //Setting values of T *colSum; 
        colSum[i]=(table[i]+table[i+6]+table[i+12]+table[i+18]+table[i+24]);
    }
    
    for (int i=0;i<rows;i++) { //Getting value for T grandTotal
        grandTotal+=rowSum[i];
    }
}


#endif /* PROB3CLASSES_H */

