/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on February 8th, 2017, 10:23 AM
  Purpose: Mark Sort Dyn Memory Allocation
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "MyArray.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void filAray(Array &);
void prntAry(Array &,int);
void markSrt(Array &);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=1000000;//Allocate a million
    int utilize=100000;    //Utilize a 100,000, sort takes about 10 seconds
    Array array;
    array.SIZE=utilize;
    array.data=new int[SIZE];
    //int array[SIZE];
    
    //Input values
    filAray(array);
    prntAry(array,10);
    
    //Process by mapping inputs to outputs
    markSrt(array);
    
    //Output values
    prntAry(array,10);
    
    //Exit stage right!
    delete []array.data;
    return 0;
}

void markSrt(Array &a){
    for(int j=0;j<a.SIZE-1;j++){
        for(int i=j+1;i<a.SIZE;i++){
            if(a.data[j]>a.data[i]){
                a.data[j]=a.data[j]^a.data[i];
                a.data[i]=a.data[j]^a.data[i];
                a.data[j]=a.data[j]^a.data[i];
            }
        }        
    }
}

void prntAry(Array &a,int perLine){
    cout<<endl;
    for(int i=0;i<a.SIZE;i++){
        cout<<a.data[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void filAray(Array &a){
    for(int i=0;i<a.SIZE;i++){
        a.data[i]=rand()%90+10;
    }
}