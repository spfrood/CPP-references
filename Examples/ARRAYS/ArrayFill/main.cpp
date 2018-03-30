
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void filAray(int [],int);
float avgAray(int [],int);
void prntAry(int [],int);


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=200;
    int utilize=SIZE/2;
    int array[SIZE]={}; //Initialize entire array to 0
    
    //Input Values
    filAray(array,utilize);
    
    //Process by mapping inputs to outputs
    float avg=avgAray(array,utilize);
    
    //Output values
    cout<<"The Entire Array "<<endl;
    prntAry(array,SIZE);
    cout<<"The average should be close to "<<(99-10)/2.0f<<endl;
    cout<<"The actual average is "<<avg<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void prntAry(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<(a[i]<=9?' ':'\0')<<a[i]<<" ";
        if(i%10==9)cout<<endl;
    }
}


float avgAray(int a[],int n){
    float sum=0.0f;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum/n;
}


void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10; //Random 10 to 99
    }
}