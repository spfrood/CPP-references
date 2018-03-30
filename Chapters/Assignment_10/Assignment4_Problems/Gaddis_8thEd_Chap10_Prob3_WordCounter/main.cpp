
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 31, 2017, 5:36 PM
 * Purpose: Prob 3) Word Counter
Write a function that accepts a pointer to a C-string as an argument and returns 
the number of words contained in the string. For instance, if the string argument 
is “Four score and seven years ago” the function should return the number 6. 
Demonstrate the function in a program that asks the user to input a string and 
then passes it to the function. The number of words in the string should be 
displayed on the screen. Optional Exercise: Write an overloaded version of this 
function that accepts a string class object as its argument.
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
int cntWd03(char *, int); //function to count the words in a string

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=255; //size is enough to Enter up to a line of characters
    char strng[SIZE]; //array of characters (c-string)
    
    //Input Values
    cout<<"Enter some words, up to "<<SIZE-1<<" total characters (excess will be ignored): "<<endl; //input characters (reserve last one for null)
    cin.getline(strng, SIZE); //get the input of the characters
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"You entered "<<cntWd03(strng, SIZE)<<" words. "<<endl; //count the words 
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to output a reversed string
int cntWd03(char *str, int size){
    int temp=1; //temp since i is local in the for loop
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        if (str[i]==' '&&str[i+1]!=' ') temp++; //sequential whitespaces not counted as more words
    }
    return temp;
}