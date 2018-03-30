
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on April 22, 2017, 6:09 PM
 * Purpose: 3) Write a function using the following structure and prototype.

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

statsResult *avgMedMode(int *,int); 

The function takes in an integer array and the size of the array.
Then returns a pointer to a structure containing the average, median
and mode.  You will then write a printStat() function that will print
the results contained in the stats structure.  I will input a small 
array to test this out so ask for how many inputs to fill the array, 
then the values to place into the array.  Make sure you delete the 
dynamic array creation for the mode when you exit the problem.
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries
#include "statsresult.h" 

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
StatsResult *avgMedMo03(int *,int);  //Function to fill structure 

void srtMa03(int *, int); //Sort function
void filMa03(int *, int); //function to fill array with random ints
int fndMo03(int *, int &, int); //function to find mode and return the number of modes
void disMa03(int *, int); //Function to display array
void filMo03(int *, int *, int, int, int); //function to fill the array with the mode frequencies
float fndMe03(int *, int); //function to find the mean of an array
float fndMi03(int *, int); //function to find the median of an array
void pStaS03(StatsResult *); //function to print the contents of a StatsResult structure

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //set random seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=0;
    int *intAry=nullptr; //pointer to be assigned to array 
    cout<<"How large would you like to make the array?"<<endl;
    cin>>size; //input the size of the array
    while (cin.fail()||size<1){ //validate input
        cin.clear(); //reset cin flags
        cin.ignore(256, '\n'); //clear buffer contents
        cout<<"Enter an integer of 1 or larger!"<<endl;
        cin>>size; //input size again
    }
    intAry=new int [size]; //create array with size input
    StatsResult *arStat=avgMedMo03(intAry, size); 
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
    pStaS03(arStat); //function to print the contents of a StatsResult structure
    
    //clean up memory
    delete [] arStat->mode; 
    delete [] intAry; 
    delete [] arStat; 
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to print the contents of a StatsResult structure
void pStaS03(StatsResult *a){
    cout<<setprecision(4);
    //output the values stored in the structure
    cout<<"The average value stored in the structure is: "<<a->avg<<endl;
    cout<<"The median value stored in the structure is: "<<a->median<<endl;
    cout<<"The frequency of the modes in this array is: "<<a->maxFreq<<endl;
    if (a->maxFreq==1){
        cout<<"     This means no elements repeated themselves."<<endl;
    } 
    cout<<"The total number of values stored in the array are: "<<a->nModes<<endl;
    cout<<"     The values stored in the array in this structure: "<<endl;
    for (int i=0;i<a->nModes;i++){
        cout<<setw(12)<<a->mode[i];
        if (i%6==0 && i!=0) cout<<endl;
    }
    cout<<endl;
    cout<<"No further data stored in structure."<<endl;
} 

//Function to fill structure 
StatsResult *avgMedMo03(int *intAry, int size) {
    //Declare Variables
    int mode=0, freq=0, mean=0, median=0; //size of array, mode of array
    int *modAry=nullptr; //WIll be assigned to array to output the mode (modes) data
    StatsResult *stats= new StatsResult;
    
    //Input Values
    filMa03(intAry, size); //call function to fill array
    disMa03(intAry, size); //display contents of the array
    cout<<endl; 
    
    //Process by mapping inputs to outputs
    cout<<"Sorting array..."<<endl;
    srtMa03(intAry, size); //call function to sort array
    disMa03(intAry, size); //display contents of the array
    cout<<endl;
    
    freq=fndMo03(intAry, mode, size); //call function to find mode and set variable mode value
    
    modAry= new int [mode];
    filMo03(intAry, modAry, mode, size, freq); //fill mode values in modAry
    
    //Set values in structure
    stats->nModes=mode;
    stats->maxFreq=freq;
    stats->mode=new int[stats->nModes];
    for (int i=0;i<stats->nModes;i++){
        stats->mode[i]=modAry[i];
    }
    stats->avg=fndMe03(intAry, size);
    stats->median=fndMi03(intAry, size);
    
    //clean up unneeded arrays
    delete [] modAry; //free memory reserved by this pointer
    
    return stats;
} 

//function to find the median of an array
float fndMi03(int *ary, int size){
    float median=0.0f;
    if (size%2==0){
        median= (static_cast<float>(*(ary+size/2))+ static_cast<float>(*(ary+size/2-1)))/2;
    } else {
        median= static_cast<float>(*(ary+size/2));
    }
    return median;
}


//Function to find the mean of the array values
float fndMe03(int *ary, int size){
    float runtot=0;
    for (int i=0;i<size;i++){
        runtot+= static_cast<float>(*(ary+i));
    }
    
    return runtot/size;
}

//function to fill the array with the mode frequencies
void filMo03(int *ary, int *mAry, int modes, int size, int highest) {
    int count=0;
    int modeCnt=0;
    for (int i=0;i<size;i++){ //run through array to see how often elements occur at frequency
        count++;
        if (i==size-1){
            if (count==highest) {
                *(mAry+modeCnt) = *(ary+i);
                modeCnt++;
            }
        } else if (*(ary+i)!= *(ary+i+1)) {
            if (count==highest){
                *(mAry+modeCnt)= *(ary+i);
                modeCnt++;
            }
            count=0;
        } 
    }
} 

//Function to print array contents
void disMa03(int *array, int size){
    for (int i=0;i<size;i++){ //Output the current element in the array. Loop for each element
        if (i%10==0) cout<<endl;
        cout<<setw(7)<<right;
        cout<<*(array+i);
    }
    cout<<endl;
}

//Function to find the number of modes, write mode values and mode frequency to an array
//Will return the frequency of the mode (or modes)
int fndMo03(int *ary, int &modes, int size){
    int count=0, highest=0; //count and record of occurances

    for (int i=0;i<size;i++){ //run though array to find the mode frequency
        count++;
        if (i==size-1){
            if (count>highest) {
                highest=count;
            }
        } else if (*(ary+i)!= *(ary+i+1)) {
            if (count>highest){
                highest=count;
            }
            count=0;
        } 
    }
    count=0;
    
    for (int i=0;i<size;i++){ //run through array to see how often elements occur at frequency
        count++;
        if (i==size-1){
            if (count==highest) {
                modes++;
            }
        } else if (*(ary+i)!= *(ary+i+1)) {
            if (count==highest){
                modes++;
            }
            count=0;
        } 
    }
    
    return highest; //return the mode 
}

//function to fill array with random data
void filMa03(int *array, int size){
    char chooser='\0';
    cout<<"Fill with random values (Y/y for random)?"<<endl;
    cin>>chooser;
    if (chooser=='Y' || chooser=='y'){
        int rndSize=0; //variable for user-selected size random number
        cout<<"How large of a range for the random fill numbers? "<<endl;
        cout<<"Up to 10000 (and greater than 0)"<<endl;
        cin>>rndSize; //Input size range of random (0 to rndSize)
        while (cin.fail()||rndSize<=0||rndSize>=10001){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Enter a positive integer up to 10000!"<<endl;
            cin>>rndSize;
        }
        for (int i=0;i<size;i++){
            *(array+i)=rand()%rndSize; //fill array element with random number
        }
        cout<<"Array filled with random values between 0 and "<<rndSize<<"ish."<<endl;
    } else {
        cout<<"Okay, time to enter the values manually!"<<endl;
        for (int i=0;i<size;i++){
            cout<<"Enter value for array element "<<i<<": ";
            cin>>array[i];
        }
    }
}

//Function to sort the array in ascending order
void srtMa03(int *array, int size){
    bool swap; //create variable to keep swapping
    int temp; //Variable to hold values for swaps
    do {
        swap=false; //Set swap condition to false. Will exit swap if nothing exchanged
        for (int i=0;i<(size-1);i++) { //run through the array and see if anything needs swapping
            if (*(array+i)> *(array+(i+1))) { //swap if next element is smaller value
                temp= *(array+i); //set temp value to current element
                *(array+i) = array[i+1]; //set current element to next element
                *(array+(i+1))=temp; //set next element to temp
                swap=true; //Swap was performed so swap = true and run loop again
            }
        }
    } while (swap); //keep doing this until array is run through without a swap being done
}