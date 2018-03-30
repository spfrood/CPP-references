/* 
  File:   main.cpp
  Author: Scott Parker
  Created on July 31, 2017, 3:50 PM
  Purpose: New sort testing
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
void prntAry(int [],int);
void minMax(int [], int);
void markSrt(int [],int);
void bubble(int [],int);
void copy(int [],int [],int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    const int utilize=SIZE;
    int array[utilize]={};
    int brray[utilize]={};
    int crray[utilize]={};
    
    //Input values
    filAray(array,utilize);
    copy(array,brray,utilize);
    copy(array,crray,utilize);
    //prntAry(array,utilize);
    //prntAry(brray,utilize);
    //prntAry(crray,utilize);
    
    //Process by mapping inputs to outputs
//    unsigned int bega=static_cast<unsigned int>(time(0));
//    cout<<"Mark-sorting..."<<endl;
//    markSrt(array,utilize);
//    unsigned int enda=static_cast<unsigned int>(time(0));
//    cout<<"Total Time for 1 function sort= "<<enda-bega<<" sec"<<endl;
    
    //Process by mapping inputs to outputs
    prntAry(brray, utilize);
    unsigned int begb=static_cast<unsigned int>(time(0));
    cout<<"New-style sorting..."<<endl;
    minMax(brray,utilize);
    unsigned int endb=static_cast<unsigned int>(time(0));
    prntAry(brray, utilize);
    cout<<"Total Time for new sort = "<<endb-begb<<" sec"<<endl;
    
    //Process by mapping inputs to outputs
//    unsigned int begc=static_cast<unsigned int>(time(0));
//    cout<<"Bubble-sorting..."<<endl;
//    bubble(crray,utilize);
//    unsigned int endc=static_cast<unsigned int>(time(0));
//    cout<<"Total Time for bubble sort = "<<endc-begc<<" sec"<<endl;
    
//    cout<<"Results:"<<endl;
//    cout<<"Time savings is = "<<(1.0f*(endb-begb)/(enda-bega)-1)*100<<"%"<<endl;
//    cout<<"Time savings is = "<<(1.0f*(endc-begc)/(enda-bega)-1)*100<<"%"<<endl;
    
    //Output values
    //prntAry(array,utilize);
    //prntAry(brray,utilize);
    //prntAry(crray,utilize);

    //Exit stage right!
    return 0;
}

void minMax(int a[],int n){
    int temp;
    int *tmp=new int[n];
    int min=a[0], max=a[n-1];
    
//    for (int i=0, j=n;i<=j-1;i++, j--) {
    
//    }
    
    for (int i=0, j=n;i<=j-1;i++, j--) {
        for (int k=i; k<=j; k++) {
            if (a[k]<=a[i]) {
                temp=a[i];
                a[i]=a[k];
                a[k]=temp;
            } else if (a[k]>=a[j-1]) {
                temp=a[j-1];
                a[j-1]=a[k];
                a[k]=temp;
            }
        }
    }
    
    
    delete [] tmp;
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

void prntAry(int a[],int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        if (i>0 && i%10==0) cout<<endl;
        cout<<"   "<<a[i]<<" ";
    }
    cout<<endl;
}

void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%999;
    }
}
