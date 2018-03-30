/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 8th, 2017, 1:30 PM
 * Purpose:  Code to test your mode
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
void prntAry(int *,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size=7;
    int *array=fillAry(size,4);
    
    //Output the created array
    prntAry(array,size,4);

    //Delete the array
    delete []array;
    
    //Exit
    return 0;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<(a[i]<10?"  ":" ")<<a[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n,int mod){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i%mod;
    }
    return a;
}

int *fillAry(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    return a;
}