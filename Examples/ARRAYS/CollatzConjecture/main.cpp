
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 30, 2017, 12:26 PM
 * Purpose: Use an array to calculate the collatz conjecture
 * if n is odd then n=3n+1 
 * if n is even then n/2
 * 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int ARAYVAL=200;
    int stored[ARAYVAL];
    int initNum = 0, count=1;
    int iterate;
    int hiTerm=0, hiNum=0;
    char pause;
    
    //Input Values
    cout<<"How many iterations?"<<endl;
    cin>>iterate;
    
    //Process by mapping inputs to outputs
    for (int cnt=1;cnt<=iterate;cnt++){
        count=1;
        initNum=cnt;
        cout<<initNum<<" ";
        do {
            if (initNum%2!=0){
                initNum=3*initNum+1;
                count++;
                cout<<initNum<<" ";
            }
            if (initNum%2==0){
                initNum/=2;
                cout<<initNum<<" ";
                count++;
            }
            
        }while (initNum!=1);
        cout<<endl;
        if (hiTerm<=count){
            hiTerm=count; 
            hiNum=cnt;
        }
    }
    initNum=hiNum;
    stored[0]=initNum;
    count=1;
    do {
        if (initNum%2!=0){
            initNum=3*initNum+1;
            stored[count]=initNum;
            count++;
            cout<<initNum<<" ";
        }
        if (initNum%2==0){
            initNum/=2;
            stored[count]=initNum;
            cout<<initNum<<" ";
            count++;
        }        
    }while (initNum!=1);
    
    //Output value
    cout<<endl;
    cout<<"Most terms was: "<<hiTerm<<endl;
    cout<<"This was for the number: "<<hiNum<<endl<<endl;

    cout<<"Enter character to output array values for highest sequence"<<endl;
    cout<<"for the array stored[0] through stored["<<(hiTerm-1)<<"]"<<endl;
    cin>>pause;
    
    for (int i=0;i<=(hiTerm-1);i++){
        cout<<stored[i]<<" ";
        if (i%20==0) cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"Full Array Memory Dump"<<endl<<endl;
    
    for (int i=0;i<=ARAYVAL;i++){
        cout<<stored[i]<<" ";
        if (i%20==0) cout<<endl;
    }
    cout<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

