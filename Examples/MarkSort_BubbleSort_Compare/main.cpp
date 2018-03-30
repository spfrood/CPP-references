/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on February 6th, 2017, 10:23 PM
  Purpose: Mark Sort in 1 functions
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
void bubble(int [],int);
void smalst(int [],int,int);
void swap(int &,int &);
void copy(int [],int [],int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    cout<<"Output 1"<<endl;
    const int SIZE=50000;
    const int utilize=SIZE;
    int array[utilize]={};
    int brray[utilize]={};
    int crray[utilize]={};
    
    cout<<"Output 2"<<endl;
    //Input values
    filAray(array,utilize);
    copy(array,brray,utilize);
    copy(array,crray,utilize);
    //prntAry(array,utilize,10);
    //prntAry(brray,utilize,10);
    //prntAry(crray,utilize,10);
    
    cout<<"Output 3"<<endl;
    //Process by mapping inputs to outputs
    unsigned int bega=static_cast<unsigned int>(time(0));
    cout<<"Mark-sorting..."<<endl;
    markSrt(array,utilize);
    unsigned int enda=static_cast<unsigned int>(time(0));
    cout<<"Total Time for 1 function sort= "<<enda-bega<<" sec"<<endl;
    
    cout<<"Output 4"<<endl;
    //Process by mapping inputs to outputs
    unsigned int begb=static_cast<unsigned int>(time(0));
    cout<<"Mark-sorting with 3 functions..."<<endl;
    mrkSrt3(brray,utilize);
    unsigned int endb=static_cast<unsigned int>(time(0));
    cout<<"Total Time for 3 function sort = "<<endb-begb<<" sec"<<endl;
    
    cout<<"Output 5"<<endl;
    //Process by mapping inputs to outputs
    unsigned int begc=static_cast<unsigned int>(time(0));
    cout<<"Bubble-sorting..."<<endl;
    bubble(crray,utilize);
    unsigned int endc=static_cast<unsigned int>(time(0));
    cout<<"Total Time for bubble sort = "<<endc-begc<<" sec"<<endl;
    
    cout<<"Output 6"<<endl;
    cout<<"Time savings is = "<<(1.0f*(endb-begb)/(enda-bega)-1)*100<<"%"<<endl;
    cout<<"Time savings is = "<<(1.0f*(endc-begc)/(enda-bega)-1)*100<<"%"<<endl;
    
    //Output values
    //prntAry(array,utilize,10);
    //prntAry(brray,utilize,10);
    //prntAry(crray,utilize,10);

    //Exit stage right!
    return 0;
}
void bubble(int a[],int n){
    bool swap;
    int temp;
    do{
        swap=false;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}

void copy(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}

void markSrt(int a[],int n){
    int temp;
    for(int j=0;j<n-1;j++){
        for(int i=j+1;i<n;i++){
            if(a[j]>a[i]){
                //a[j]=a[j]^a[i];
                //a[i]=a[j]^a[i];
                //a[j]=a[j]^a[i];
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
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
    int temp=a;
    a=b;
    b=temp;
    //a=a^b;
    //b=a^b;
    //a=a^b;
}