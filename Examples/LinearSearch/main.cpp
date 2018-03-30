/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on February 6th, 2017, 11:13 AM
  Purpose: Linear Search
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void filAray(int [],int);
void prntAry(int [],int,int);
int linSrch(int [],int,int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=200;
    const int utilize=SIZE/2;
    int array[utilize]={};
    
    //Input values
    filAray(array,utilize);
    
    //Find the element
    int find;
    cout<<"What value to find? type a number between 10 and 99"<<endl;
    cin>>find;
    cout<<find<<" was found at "<<linSrch(array,utilize,find)<<endl;
    
    //Output values
    prntAry(array,utilize,10);

    //Exit stage right!
    return 0;
}

int linSrch(int a[],int n,int val){
    for(int i=0;i<n;i++){
        if(a[i]==val)return i;
    }
    return -1;
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}