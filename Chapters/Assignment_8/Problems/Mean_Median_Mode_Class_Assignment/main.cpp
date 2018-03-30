
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 11, 2017, 10:19 PM
 * Purpose: In-Class Assignment
 * Asisgnment 2 03/14/17

Class assignment -> Mean Median Mode

Input an array, return the mean,median,and mode array.  Array -> number of 
modes, frequency of modes, then modes' values.

Submit your code here and copy yourself on an email to mark.lehr@rcc.edu with
Subject: Lastname, Firstname - Assignment 2 - 44051 or 42636
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void srtMary(int *, int); //Sort function
void filMary(int *, int); //function to fill array with random ints
int fndMode(int *, int &, int); //function to find mode and return the number of modes
void disMary(int *, int); //Function to display array
void filMode(int *, int *, int, int, int); //function to fill the array with the mode frequencies
int fndMean(int *, int); //function to find the mean of an array
int fndMidi(int *, int); //function to find the median of an array

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int size=0, mode=0, freq=0, mean=0, median=0; //size of array, mode of array
    int *intAry=nullptr; //pointer to be assigned to array 
    int *modAry=nullptr; //WIll be assigned to array to output the mode (modes) data
    
    //Input Values
    cout<<"How large would you like to make the array?"<<endl;
    cin>>size; //input the size of the array
    while (cin.fail()||size<1){ //validate input
        cin.clear(); //reset cin flags
        cin.ignore(256, '\n'); //clear buffer contents
        cout<<"Enter an integer of 1 or larger!"<<endl;
        cin>>size; //input size again
    }
    intAry=new int [size]; //create array with size input
    filMary(intAry, size); //call function to fill array
    disMary(intAry, size); //display contents of the array
    cout<<"Array filled with random integer values: "<<endl;
    cout<<endl; 
    
    //Process by mapping inputs to outputs
    cout<<"Sorting array..."<<endl;
    srtMary(intAry, size); //call function to sort array
    disMary(intAry, size); //display contents of the array
    cout<<endl;
    cout<<"Finding Modes..."<<endl;
    freq=fndMode(intAry, mode, size); //call function to find mode and set variable mode value
    
    modAry= new int [mode];
    filMode(intAry, modAry, mode, size, freq); //fill mode values in modAry
    
    //Output values
    if (freq!=1){
        cout<<"The array has "<<mode<<" mode(s)."<<endl;
        cout<<"The modes occur with "<<freq<<" frequency."<<endl;
        cout<<"The modes are: ";
        disMary(modAry, mode);
    } else {
        cout<<"The frequency returned for this array was 1 which means that no "<<endl;
        cout<<"single element repeated itself."<<endl;
    }
    cout<<"The mean of the array values is: "<<fndMean(intAry, size)<<endl;
    cout<<"The median of the array is: "<<fndMidi(intAry, size)<<endl;
    
    //clean up arrays
    delete [] intAry; //free memory reserved by this pointer
    delete [] modAry; //free memory reserved by this pointer
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to find the median of an array
int fndMidi(int *ary, int size){
    int median=0;
    if (size%2==0){
        median= (*(ary+size/2)+ *(ary+size/2-1))/2;
    } else {
        median= *(ary+size/2);
    }
    return median;
}


//Function to find the mean of the array values
int fndMean(int *ary, int size){
    unsigned int runtot=0;
    for (int i=0;i<size;i++){
        runtot+= *(ary+i);
    }
    
    return runtot/size;
}

//function to fill the array with the mode frequencies
void filMode(int *ary, int *mAry, int modes, int size, int highest) {
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
void disMary(int *array, int size){
    for (int i=0;i<size;i++){ //Output the current element in the array. Loop for each element
        if (i%10==0) cout<<endl;
        cout<<setw(7)<<right;
        cout<<*(array+i);
    }
    cout<<endl;
}

//Function to find the number of modes, write mode values and mode frequency to an array
//Will return the frequency of the mode (or modes)
int fndMode(int *ary, int &modes, int size){
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
void filMary(int *array, int size){
    //set random seed
    srand (static_cast<unsigned int>(time(0)));
    
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
}

//Function to sort the array in ascending order
void srtMary(int *array, int size){
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