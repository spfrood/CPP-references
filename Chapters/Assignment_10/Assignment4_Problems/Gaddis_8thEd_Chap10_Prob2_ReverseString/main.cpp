
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 31, 2017, 5:36 PM
 * Purpose: Prob 2) Backward String
Write a function that accepts a pointer to a C-string as an argument and displays
its contents backward. For instance, if the string argument is “Gravity” the 
function should display “ytivarG”. Demonstrate the function in a program that 
asks the user to input a string and then passes it to the function.
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
void revSt02(char *, int); //function to output the reverse of a string

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
    cout<<"You entered: "<<strng<<endl; //SHow what the user entered
    cout<<"Reversed is "; 
    revSt02(strng, SIZE); //output the reversed string
    cout<<endl; 
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to output a reversed string
void revSt02(char *str, int size){
    int temp=0; //temp since i is local in the for loop
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        temp=i; //counter set to i 
    }
    for (int i=temp;i>=0;i--){
        cout<<str[i];
    }
    cout<<endl;
}