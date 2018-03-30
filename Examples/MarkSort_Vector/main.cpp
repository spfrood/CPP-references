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
#include <vector>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void filAray(vector<int> &);
void prntAry(vector<int> &,int);
void markSrt(vector<int> &);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=1000000;//Allocate a million
    int utilize=100000;    //Utilize a 100,000, sort takes about 10 seconds
    vector<int> array(utilize);
    
    //Input values
    filAray(array);
    prntAry(array,10);
    
    //Process by mapping inputs to outputs
    markSrt(array);
    
    //Output values
    prntAry(array,10);
    
    //Exit stage right!
    return 0;
}

void markSrt(vector<int> &a){
    for(int j=0;j<a.size()-1;j++){
        for(int i=j+1;i<a.size();i++){
            if(a[j]>a[i]){
                //a[j]=a[j]^a[i];
                //a[i]=a[j]^a[i];
                //a[j]=a[j]^a[i];
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }        
    }
}

void prntAry(vector<int> &a,int perLine){
    cout<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void filAray(vector<int> &a){
    for(int i=0;i<a.size();i++){
        a[i]=rand()%90+10;
    }
}