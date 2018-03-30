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

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *fillAry(int);
int *fillAry(int,int);
void fillAry(int *,int *,int,int);
void prntAry(int *,int,int);
void prntAry(int *,int *,int,int);
void markSrt(int *,int);
void markSrt(int *,int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size=100;
    int *array,*indx;
    array=new int[size];
    indx=new int[size];
    fillAry(array,indx,size,10);
    
    //Output the created array
    prntAry(array,size,10);
    prntAry(indx,size,10);
    
    //Sort the array
    markSrt(array,indx,size);
    
    //Printout the sorted array
    prntAry(array,size,10);
    prntAry(indx,size,10);
    prntAry(array,indx,size,10);

    //Delete the array
    delete []array;
    delete []indx;
    
    //Exit
    return 0;
}

void markSrt(int *a, int *indx,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(*(a+ *(indx+i))>*(a+ *(indx+j))){
                int temp=*(indx+i);
                *(indx+i)=*(indx+j);
                *(indx+j)=temp;
            }
        }
    }
}

void markSrt(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(*(a+i)>*(a+j)){
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
}

void prntAry(int *a,int *indx,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<(*(a+ *(indx+i))<10?"  ":" ")<<*(a+ *(indx+i));
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<(*(a+i)<10?"  ":" ")<<*(a+i);
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int *a,int *indx,int n,int mod){
    for(int i=0;i<n;i++){
        *(a+i)=i%mod;
        *(indx+i)=i;
    }
}

int *fillAry(int n,int mod){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        *(a+i)=i%mod;
    }
    return a;
}

int *fillAry(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        *(a+i)=i;
    }
    return a;
}