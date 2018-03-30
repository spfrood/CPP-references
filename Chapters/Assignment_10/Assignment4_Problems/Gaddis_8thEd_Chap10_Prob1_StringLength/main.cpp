
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 31, 2017, 5:36 PM
 * Purpose: Prob 1) String Length
Write a function that returns an integer and accepts a pointer to a C-string as 
an argument. The function should count the number of characters in the string 
and return that number. Demonstrate the function in a simple program that asks 
the user to input a string, passes it to the function, and then displays the 
function’s return value. 
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
int cntSt01(char [], int); //function to count the length of a c-string

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=75; //size is enough to Enter up to a line of characters
    char strng[SIZE]; //array of characters (c-string)
    
    //Input Values
    cout<<"Input up to "<<SIZE-1<<" characters (excess will be ignored): "<<endl; //input characters (reserve last one for null)
    cin.getline(strng, SIZE); //get the input of the characters
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"You entered: "<<strng<<endl;
    cout<<"The string is " <<cntSt01(strng, SIZE)<<" characters long (not including '\\0')."<<endl; //output the number of characters in the string
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to count the length of a c-string
int cntSt01(char str[], int size){
    int temp=0; //temp since i is local in the for loop
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        temp=i+1; //counter set to i 
    }
    if (str[0]=='\0') temp=0;
    return temp; //return the value of the for loop
}