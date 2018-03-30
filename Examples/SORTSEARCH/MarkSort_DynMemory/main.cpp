
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 8, 2017, 10:30 AM
 * Purpose: Mark Lehr style sort using dynamic memory allocation
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
void markSrt(int [],int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=1000000; //Maximum allowable static array size is 515314
    int utilize=100000;
    int *array=new int[utilize];  //allocating a dynamic array
    //int array[SIZE]={};  //Old style array (static array)
    
    //Input values
    filAray(array,utilize);
    prntAry(array,utilize,10);
    
    //Process by mapping inputs to outputs
    markSrt(array,utilize);
    prntAry(array,utilize,10);
    
    delete []array; //this deletes the dynamic array preventing memory leak
    
    //Exit stage right!
    return 0;
}

void markSrt(int a[],int n){
    for(int j=0;j<n-1;j++){
        for(int i=j+1;i<n;i++){
            if(a[j]>a[i]){
                a[j]=a[j]^a[i];
                a[i]=a[j]^a[i];
                a[j]=a[j]^a[i];
            }
        }        
    }
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




