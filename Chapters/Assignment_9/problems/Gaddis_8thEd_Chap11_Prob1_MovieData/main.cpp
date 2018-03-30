
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 25, 2017, 11:30 AM
 * Purpose: 
1. Movie Data
Write a program that uses a structure named MovieData to store the following 
information about a movie:
    Title
    Director
    Year Released
    Running Time (in minutes)
The program should create two MovieData variables, store values in their members, 
and pass each one, in turn, to a function that displays the information about 
the movie in a clearly formatted manner.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
#include "MovData.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another


//Function Prototypes
void shMo05(Movie); //Function to display data in a Movie structure

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    Movie movie1 = {"Blockbuster Movie One", "Alan Smythe", 1991, 175}; //Movie structure filled with data
    Movie movie2 = {"Flopbuster Move Two point Three", "Bert Twythe", 2004, 88}; //Movie structure filled with data
    
    //Input Values
    
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    shMo05(movie1); //Call function to output structure data values
    shMo05(movie2); //Call function to output structure data values
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}


//Function to display data stored in a Movie structure
void shMo05(Movie a){
    cout<<"Movie Information"<<endl; 
    cout<<setw(20)<<left; //format output
    cout<<"Title: "; //output data label for field value (what is stored in the data)
    cout<<a.title<<endl; //output the data value in the structure element
    cout<<setw(20)<<left;//format output
    cout<<"Director: ";//output data label for field value (what is stored in the data)
    cout<<a.direct<<endl;//output the data value in the structure element
    cout<<setw(20)<<left;//format output
    cout<<"Release Date: ";//output data label for field value (what is stored in the data)
    cout<<a.relDate<<endl;//output the data value in the structure element
    cout<<setw(20)<<left;//format output
    cout<<"Running Time: ";//output data label for field value (what is stored in the data)
    cout<<a.runTime<<" minutes."<<endl;//output the data value in the structure element
    cout<<endl;
}