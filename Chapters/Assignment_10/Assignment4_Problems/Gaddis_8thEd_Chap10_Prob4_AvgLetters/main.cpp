
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 31, 2017, 5:36 PM
 * Purpose: Prob 4) Average Number of Letters
Modify the program you wrote for Problem 3 (Word Counter), so it also displays 
the average number of letters in each word.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
int cntWd04(char *, int); //function to count the words in a string
float avgLt05(char *, int); //function to return the avg number of letters per word in a string

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
    cout<<"You entered "<<cntWd04(strng, SIZE)<<" words. "<<endl; //count the words 
    cout<<setprecision(2)<<fixed; //format output 2 decimal points fixed
    cout<<"They contained "<<avgLt05(strng, SIZE)<<" letters each on average."<<endl; //output avg letters per word
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to return the avg number of letters per word in a string
float avgLt05(char *str, int size){
    int temp=1; //temp since i is local in the for loop
    int totChar=0;
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        if (str[i]==' '&&str[i+1]!=' ') temp++; //count whitespace after each word but not multiples
        if (str[i]!=' ') totChar++; //add to character count if not a whitespace
    } 
    return (static_cast<float>(totChar)/static_cast<float>(temp));
} 

//function to output a reversed string
int cntWd04(char *str, int size){
    int temp=1; //temp since i is local in the for loop
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        if (str[i]==' '&&str[i+1]!=' ') temp++; //whitespace after each word
    }
    return temp;
}