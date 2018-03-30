
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Problem #4  (Random Sequence)
 * 
        Create a function/method/procedure that
returns a random number from the following set,
{9,52,78,101,119}.  Loop 10000 times with this 
procedure and print the frequency of each of 
the 5 numbers obtained.  Hint: Use an array for 
the sequence and frequency.  


The following is a brief hint on items that might 
be helpful in obtaining the results.  This is not 
direct code but more pseudo code related.  Don't 
try and run the following directly and more code 
will be needed.


Setup
        const int n=5,ntimes=10000;
        int freq[n]={0};
        short int rndseq[]={9,52,78,101,119};


Call to the routine to return a random sequence
        retrand(rndseq,freq,n,ntimes);


Results
        cout<<rndseq[i]<<" occurred "<<
                freq[i]<<" times"<<endl;


Sample Output
         9 occurred 2055 times
        52 occurred 1986 times
        78 occurred 1962 times
        101 occurred 2079 times
        119 occurred 1919 times


Note:  Your results are not expected to be exactly
the same!  After all these are pseudo-random 
number sequences with different seeds.  
*/

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
int retRand(); //Function to return 1 of 5 values


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int ntimes=10000, n=5; //How many times to run it, number of options
    int array[ntimes]={}; //Array to hold the values
    int freqAry[n]={}; //Array to hold the number of times for each value
    int rndseq[n]={9,52,78,101,119}; //Array holding the 5 diff values
    
    //Input Values
    for (int i=0;i<ntimes;i++){
        array[i]=retRand(); //Assigning random values to array
        if (array[i]==9){ 
            freqAry[0]++; //increment if element == 9
        }
        if (array[i]==52){
            freqAry[1]++; //increment if element == 52
        }
        if (array[i]==78){
            freqAry[2]++; //increment if element == 78
        }
        if (array[i]==101){
            freqAry[3]++; //increment if element == 101
        }
        if (array[i]==119){
            freqAry[4]++; //increment if element == 119
        }
    }
    
    //Output values
    cout<<"The numbers came up with the following frequencies: "<<endl;
    for (int i=0;i<n;i++){  //Output how many times each value occured
        cout<<rndseq[i]<<" occurred "<<
        freqAry[i]<<" times"<<endl;
    }
    cout<<"Total of all occurances: "<<freqAry[0]+freqAry[1]+freqAry[2]+freqAry[3]+freqAry[4]<<endl;

    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Return random ********************************
//Description: returns one of the required elements in a random manner
//
//Inputs: 
//     
//Outputs: none
//******************************************************************************
int retRand(){  //Filling random sequence to fill array with sequence values
    int temp;
    int rndNum=rand()%5;
    if (rndNum==0)temp=9;
    if (rndNum==1)temp=52;
    if (rndNum==2)temp=78;
    if (rndNum==3)temp=101;
    if (rndNum==4)temp=119;
    return temp;
}
