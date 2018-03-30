/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 8th, 2017, 1:30 PM
 * Purpose:  Dynamic memory with copy/resize.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *fillAry(int);
int *copyAry(int *,int,int);
void prntAry(int *,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size=50;
    int *array=fillAry(size);
    
    //Output the created array
    cout<<"Address of first array allocation = "<<array<<endl;
    prntAry(array,size,10);
    
    //Resize the array
    array=copyAry(array,size,2*size);
    
    //Print out the copied/resized array
    cout<<"Address of second copied/resized array allocation = "<<array<<endl;
    prntAry(array,2*size,10);

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

int *copyAry(int *a,int n,int m){
    int *b=new int[m];
    for(int i=0;i<m;i++){
        if(i<n)b[i]=a[i];
        else b[i]=i;
    }
    delete []a;
    return b;
}

int *fillAry(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    return a;
}