/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob2Sort.h
 * Author: scott_r_parker
 *
 * Created on June 6, 2017, 12:22 AM
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H

#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
class Prob2Sort
{
private:
    int *index;                                 //Index that is utilized in the sort
public:
    Prob2Sort(){index=NULL;};                   //Constructor
    ~Prob2Sort(){delete []index;};              //Destructor
    T * sortArray(const T*,int,bool);           //Sorts a single column array
    T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 

template<class T>
T *Prob2Sort<T>::sortArray(const T* a, int size, bool ascending) {
    index = new int[size];
    T *array = new T[size];
    
    for (int i=0;i<size;i++) { //Initialize the index
        index[i]=i;
        array[i]=a[i];
    }
    
    if (ascending) { //sort by index in ascending order
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
               if(a[index[i]]<a[index[j]]){
                   int temp=index[i];
                   index[i]=index[j];
                   index[j]=temp;
               }
            }
        }
    } else { //sort by index in descending order
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
               if(a[index[i]]>a[index[j]]){
                   int temp=index[i];
                   index[i]=index[j];
                   index[j]=temp;
               }
            }
        }
    }
    for (int i=0;i<size;i++) {
        array[i]=a[index[i]];
    }
    return array;
}

template<class T>
T *Prob2Sort<T>::sortArray(const T* a, int rows, int cols, int sortBy, bool ascending) {
    T *array = new T[rows*cols]; //create array to be passed out of function
    int h=sortBy-1;
    if (h>=cols-1) {
        h=14;
    } else if (h<=0) {
        h=0;
    }
    
    if (ascending) { //sort by faux row with index in ascending order
        index = new int[rows*cols+20]; //create index with buffer to swap rows
        for (int i=0;i<(rows*cols+20);i++) { //Fill the index with a buffer for swapping rows
            index[i]=i;
        }
        bool swap;
        do{
            swap=false;
            for(int i=0;i<rows*cols-1;i+=cols){
                int f=0;
                int k=i+h;
                if(a[index[k]]<a[index[k+cols]]){ //compare 1st element and swap row if true
                    //Swap rows
                    int temp=0;  //set initial temp value to one not used in the alpha array
                    for (int j=0;j<cols-1;j++){ //exchange elements in rows one at a time
                        temp=index[i+j];
                        index[i+j]=index[i+cols+j];
                        index[i+cols+j]=temp;
                    }
                    swap=true; //set bool to true to initiate another run-through
                } else if (a[index[k]]==a[index[k+cols]]){ //if first element is same in both rows
                    do{ //increment to next element until elements are not same
                        f++;
                        if ((k+f)%(cols)==0) {
                            f-=cols;
                        }
                    } while (a[index[k+f]]==a[index[k+cols+f]]);
                
                    if (a[index[k+f]]<a[index[k+cols+f]]){ //if current row less than next swap row
                        //Swap rows
                        int temp=0;  //set initial temp value to one not used in the alpha array
                        for (int j=0;j<cols-1;j++){ //exchange elements in rows one at a time
                            temp=index[i+j];
                            index[i+j]=index[i+cols+j];
                            index[i+cols+j]=temp;
                        }
                        swap=true; //set bool to true to initiate another run-through
                    }
                }
            }
        }while(swap); 
    } else { //sort by faux row in descending order
        
        index = new int[rows*cols+20]; //create index with buffer to swap rows
        for (int i=0;i<(rows*cols+20);i++) { //Fill the index with a buffer for swapping rows
            index[i]=i;
        }
        bool swap;
        do{
            swap=false;
            for(int i=0;i<rows*cols-1;i+=cols){
                int f=0;
                int k=i+h;
                if(a[index[k]]>a[index[k+cols]]){ //compare 1st element and swap row if true
                    //Swap rows
                    int temp=0;  //set initial temp value to one not used in the alpha array
                    for (int j=0;j<cols;j++){ //exchange elements in rows one at a time
                        temp=index[i+j];
                        index[i+j]=index[i+cols+j];
                        index[i+cols+j]=temp;
                    }
                    swap=true; //set bool to true to initiate another run-through
                } else if (a[index[k]]==a[index[k+cols]]){ //if first element is same in both rows
                    do{ //increment to next element until elements are not same
                        f++;
                        if ((k+f)%(cols)==0) {
                            f-=cols;
                        }
                    } while (a[index[k+f]]==a[index[k+cols+f]]);
                
                    if (a[index[k+f]]>a[index[k+cols+f]]){ //if current row less than next swap row
                        //Swap rows
                        int temp=0;  //set initial temp value to one not used in the alpha array
                        for (int j=0;j<cols;j++){ //exchange elements in rows one at a time
                            temp=index[i+j];
                            index[i+j]=index[i+cols+j];
                            index[i+cols+j]=temp;
                        }
                        swap=true; //set bool to true to initiate another run-through
                    }
                }
            }
        }while(swap); 
    }
    
    //Copying a[index[i]] to array[i]
    if (ascending) {
        for (int i=0;i<(rows*cols);i++) {
            array[i]=a[index[i]];
        }
    } else {
        for (int i=0;i<(rows*cols);i++) {
            array[i]=a[index[i+16]];
        }
    }
    
    return array;
}


#endif /* PROB2SORT_H */

