/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 8th, 2017, 1:30 PM
 * Purpose:  Database sort
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Array.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
Array *fillAry(int,int);
void prntAry(Array *,int);
void markSrt(Array *);
void destroy(Array *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size=100;
    Array *array=fillAry(size,10);
    
    //Output the created array
    prntAry(array,10);
    
    //Sort the array
    markSrt(array);
    
    //Printout the sorted array
    prntAry(array,10);

    //Delete the array
    destroy(array);
    
    //Exit
    return 0;
}

void destroy(Array *a){
    delete []a->data;
    delete []a->index;
    delete a;
}

void markSrt(Array *a){
    for(int i=0;i<a->size-1;i++){
        for(int j=i+1;j<a->size;j++){
            if(*(a->data+ *(a->index+i))>*(a->data+ *(a->index+j))){
                int temp=*(a->index+i);
                *(a->index+i)= *(a->index+j);
                *(a->index+j)=temp;
            }
        }
    }
}


void prntAry(Array *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<*(a->data+ *(a->index+i));
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}


Array *fillAry(int n,int mod){
    //Declare the array and its components
    Array *a=new Array;
    a->size=n>1?n:2;
    a->data=new int[a->size];
    a->index=new int[a->size];
    //Fill the components with data
    for(int i=0;i<a->size;i++){
        *(a->data+i)=i%mod;
        *(a->index+i)=i;
    }
    //Return the Array
    return a;
}