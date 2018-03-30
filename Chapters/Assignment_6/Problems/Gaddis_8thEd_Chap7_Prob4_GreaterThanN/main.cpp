
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: 4. Larger Than n
In a program, write a function that accepts three arguments: an array, the 
size of the array, and a number n. Assume that the array contains integers. 
The function should display all of the numbers in the array that are greater 
than the number n.
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes
void display (int [],int,int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Randomize random number seed
    srand(static_cast<int>(time(0)));
    
    //Declare Variables
    const int SIZE=1000;
    int arayNum [SIZE]={};
    int testNum=0;
    
    //Input Values   
    cout<<"Filling array with random numbers 0-99"<<endl;
    for (int i=1;i<SIZE;i++) {
        arayNum[i]=(rand()%SIZE); //Fill array with random numbers up to size of array
        cout<<".";
        if ((i%70)==0)cout<<endl;
    }
    cout<<endl;
    
    testNum=rand()%SIZE; //Random number for the test value number
    cout<<"Random number for testing... "<<testNum<<endl;
    
    //Process by mapping inputs to outputs
    
    //Output values
    display (arayNum, SIZE, testNum);
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//Function to display values of array that are greater than N
void display (int array[],int SIZE,int nVal){
    int sameAs=0;
    int valCntr=0;
    for (int i=0;i<SIZE;i++){
        if (array[i]>nVal) {
            cout<<"Spot "<<i<<" in array is value "<<array[i]
                <<" and is larger than "<<nVal<<endl;
            valCntr++;
        }
        if (array[i]==nVal) sameAs++;
    }
    cout<<"The array has "<<nVal<<" occur "<<sameAs<<" times."<<endl;
    cout<<"The function output "<<valCntr<<" lines."<<endl;
}

