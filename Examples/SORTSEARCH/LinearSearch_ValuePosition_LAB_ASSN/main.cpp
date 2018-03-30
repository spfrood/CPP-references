
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 6, 2017, 11:08 AM
 * Purpose: Linear Search to find all duplicate positions of a number.
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
int linSrch(int [],int [],int,int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=400;
    const int utilize=SIZE/2;
    int array[utilize]={};
    int posAray[utilize]={};
    int reps=0;
    
    //Input values
    filAray(array,utilize);
    
    //Find the element
    int find;
    cout<<"What value to find? type a number between 10 and 99"<<endl;
    cin>>find;
    reps=linSrch(array,posAray,utilize,find);
    cout<<find<<" occurs "<<reps<<" times."<<endl;
    cout<<"It is found in positions: ";
    for (int i=0;i<reps;i++){
        cout<<(posAray[i]+1)<<"  ";
    }
    cout<<endl;
    for (int i=0;i<reps;i++){
        cout<<array[posAray[i]]<<"  ";
    }
    cout<<endl;
    
    //Output values
    prntAry(array,utilize,10);

    //Exit stage right!
    return 0;
}

int linSrch(int a[],int pos[],int n,int val){
    int occur=0;
    for(int i=0;i<n;i++){
        if(a[i]==val){
            pos[occur]=i;
            occur++;
        }
    }
    return occur;
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