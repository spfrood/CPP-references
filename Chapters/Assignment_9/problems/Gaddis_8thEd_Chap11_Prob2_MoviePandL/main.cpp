
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 25, 2017, 1:14 PM
 * Purpose: 2. Movie Profit
Modify the Movie Data program written for Programming Challenge 1 to include two
additional members that hold the movie’s production costs and first-year revenues. 
Modify the function that displays the movie data to display the title, director, 
release year, running time, and first year’s profit or loss.
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
void shMo06(MovieR); //Function to display data in a Movie structure

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    MovieR movie1 = {"Blockbuster Movie One", "Alan Smythe", 1991, 175, 1653000, 24500000}; //Movie structure filled with data
    MovieR movie2 = {"Flopbuster Move Two point Three", "Bert Twythe", 2004, 88, 4555000, 3352000}; //Movie structure filled with data
    
    //Input Values
    
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    shMo06(movie1); //Call function to output structure data values
    shMo06(movie2); //Call function to output structure data values
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}


//Function to display data stored in a Movie structure
void shMo06(MovieR a){
    cout<<"Movie Information"<<endl; 
    cout<<setw(22)<<left; //format output
    cout<<"Title: "; //output data label for field value (what is stored in the data)
    cout<<a.title<<endl; //output the data value in the structure element
    cout<<setw(22)<<left;//format output
    cout<<"Director: ";//output data label for field value (what is stored in the data)
    cout<<a.direct<<endl;//output the data value in the structure element
    cout<<setw(22)<<left;//format output
    cout<<"Release Date: ";//output data label for field value (what is stored in the data)
    cout<<a.relDate<<endl;//output the data value in the structure element
    cout<<setw(22)<<left;//format output
    cout<<"Running Time: ";//output data label for field value (what is stored in the data)
    cout<<a.runTime<<" minutes."<<endl;//output the data value in the structure element
    cout<<setw(22)<<left;
    cout<<"Fist Year Earnings: "<<"$"<<(a.relEarn)-(a.proCost)<<endl; //Output the (earnings minus cost) = (profit)
    cout<<endl;
}