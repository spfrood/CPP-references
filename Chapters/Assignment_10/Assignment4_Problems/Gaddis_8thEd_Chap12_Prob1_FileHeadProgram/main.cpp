
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on April 1, 2017, 5:29 PM
 * Purpose: 
1. File Head Program
Write a program that asks the user for the name of a file. The program should 
display the first 10 lines of the file on the screen (the “head” of the file). 
If the file has fewer than 10 lines, the entire file should be displayed, with 
a message indicating the entire file has been displayed.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int count=0;
    string temp=""; //string to hold file data
    fstream fil; //Create filestream object 
    fil.open("dataC.txt", ios::in); //Open file for input
    if (fil.fail()) { //if can not open file then break program
        cout << "ERROR: Cannot open the file.\n";
        return 0;
    }
    
    //Input Values
    
    cout<<"<BEGIN FILEHEAD>"<<endl; //Output beginning of filehead
    while (!fil.eof() && count<10) { //loop first 10 lines and not fil.eof
        getline(fil, temp); //Get line i of the file
        cout<<temp<<endl; //output file line
        count++; //increment count until next line
    }
    if (fil.eof()) cout<<"<EOF> END OF FILE"<<endl; //if end of file hit then notify EOF
    else cout<<"<END FILEHEAD>"<<endl; //Else output end of filehead
    
    //Process by mapping inputs to outputs
    
    //Output values
    
    //Clean up and close files
    
    fil.close(); //close file
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

