
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 10, 2017, 12:58 PM
 * Purpose: 
1. Array Allocator
Write a function that dynamically allocates an array of integers. The function 
should accept an integer argument indicating the number of elements to allocate.
The function should return a pointer to the array. 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
int *aloAray(int); //function to allocate the memory for the array

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    
    //Declare Variables
    int size=0;  //for the size of the dynamic array
    int *aPtr=nullptr;  //creating pointer setting it to null memory area
    
    //Input Values
    cout<<"How large do you want the array? (input a positive integer)"<<endl;
    cin>>size;  //input size of array
    
    //Process by mapping inputs to outputs
    aPtr=aloAray(size); //set pointer = to return value of allocate array function
    
    //Output values
    for (int i=0;i<size;i++){ //Output the array with for statement and size variable
        cout<<"Array Element: "<<i<<" contains a value of "<<aPtr[i]<<endl;
        cout<<"Written in pointer notation *(aPtr+i): "<<*(aPtr + i)<<endl;
        cout<<"Memory location of &aPtr[i] is: "<<&aPtr[i]<<endl;
        cout<<"Output written as (aPtr + i) is: "<<(aPtr + i)<<endl;
    }
    
    //Clean up
    delete [] aPtr; //free up the memory that was reserved for the array
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//Function to create the dynamically allocated array
int *aloAray(int size){
    int *tmpAray=new int [size]; //create new array object
    for (int i=0;i<size;i++){ //fill array with misc. data
        tmpAray[i]=i;
    }
    return tmpAray; //return the array and exit the function
}