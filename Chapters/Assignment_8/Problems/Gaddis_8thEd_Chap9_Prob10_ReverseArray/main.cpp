
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 12, 2017, 11:46 AM
 * Purpose: 10. Reverse Array
Write a function that accepts an int array and the array’s size as arguments. 
The function should create a copy of the array, except that the element values 
should be reversed in the copy. The function should return a pointer to the new 
array. Demonstrate the function in a complete program.
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
int *cpyRvse(int *, int); //function to copy and reverse the original array
void rndFill(int *, int); //function to fill array with random data
void dplyAry(int *, int); //function to display an array


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int size=0; //variable to hold the size of array
    
    //Input Values
    cout<<"How large would you like to make the array?"<<endl;
    cin>>size; //input the size of the array
    
    //Process by mapping inputs to outputs
    int *origAry=new int[size]; //create array
    rndFill(origAry, size); //call function to fill with random data
    int *copyAry=cpyRvse(origAry, size); //create 2nd array that is reversed copy of first
    
    //Output values
    cout<<"Original Array: "<<endl; 
    dplyAry(origAry, size); //Display the original array
    cout<<endl;
    cout<<"Reversed Copy: "<<endl;
    dplyAry(copyAry, size); //display the copied and reversed array
    
    //clean up memory
    delete [] origAry; //delete memory of original array
    delete [] copyAry; //delete memory of copied array
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to copy reversed version of original function
int *cpyRvse(int *array, int size){
    int *a =new int[size];
    int j=0; //To increment counter to for loop decrement
    for (int i=size-1;i>=0;i--){
        *(a+j)= *(array+i); //Set new array = to last element of orig then proceed inversely
        j++; 
    }
    return a;
}

//Function to fill array with random data
void rndFill(int *array, int size) {
    srand(static_cast<unsigned int>(time(0)));
    int rndSize=0; //variable to hold the size of the randoms
    cout<<"What is the range of the random fill numbers?"<<endl;
    cout<<"Enter an integer between 1 and 32000."<<endl;
    cin>>rndSize; //input size of random
    while ((rndSize<=0)||(rndSize>=32000)||cin.fail()){ //validate input size and scope
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Enter an integer between 1 and 32000!"<<endl;
        cin>>rndSize; //input size of random again (if previous attempt invalid)
    }
    for (int i=0;i<size;i++){
        *(array+i)=rand()%rndSize; //fill array with random values
    }
    cout<<"Array filled with random numbers between 0 and "<<rndSize<<endl;
}

//function to display contents of array
void dplyAry(int *array, int size) {
    for (int i=0;i<size;i++){ //loop to display the array elements
        cout<<"Element     "<<i<<":  "<<*(array+i)<<endl; //output the array element
    }
}