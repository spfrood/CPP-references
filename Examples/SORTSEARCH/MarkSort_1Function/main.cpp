
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 6, 2017, 10:30 AM
 * Purpose: Mark Lehr style sort using 1 function and 3 function
 *          Time Comparison too
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
void mrkSrt3(int [],int);
void smalst(int [],int,int);
void swap(int &,int &);
void copy(int [],int [],int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=200000;
    const int utilize=SIZE/2;
    int array[utilize]={};
    int brray[utilize]={};
    
    //Input values
    filAray(array,utilize);
    copy(array,brray,utilize);
    //prntAry(array,utilize,10);
    //prntAry(brray,utilize,10);
    
    //Process by mapping inputs to outputs
    unsigned int bega=static_cast<unsigned int>(time(0));
    markSrt(array,utilize);
    unsigned int enda=static_cast<unsigned int>(time(0));
    cout<<"Total Time for 1 function sort= "<<enda-bega<<" sec"<<endl;
    
    //Process by mapping inputs to outputs
    unsigned int begb=static_cast<unsigned int>(time(0));
    mrkSrt3(brray,utilize);
    unsigned int endb=static_cast<unsigned int>(time(0));
    cout<<"Total Time for 3 function sort = "<<endb-begb<<" sec"<<endl;
    
    cout<<"Time savings is = "<<(1.0f*(endb-begb)/(enda-bega)-1)*100<<"%"<<endl;
    
    //Output values
    //prntAry(array,utilize,10);
    //prntAry(brray,utilize,10);

    //Exit stage right!
    return 0;
}

void copy(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
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
        a[i]=rand();
    }
}

void mrkSrt3(int a[],int n){
    for(int i=0;i<n-1;i++){
        smalst(a,n,i);
    }    
}

void smalst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i])swap(a[pos],a[i]);
    }
}

void swap(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}