
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: 4. Tail Program
Write a program that asks the user for the name of a file. The program should 
display the last 10 lines of the file on the screen (the “tail” of the file). 
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
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void pTail09(fstream &, string);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    fstream filJ; //fstream to hold text file
    string fName=""; //to hold the name of the file to open
    
    //Input Values
    cout<<"Input the file name: "<<endl; //ask user for the file name
    cin>>fName; //Input the name of the file to open
    
    //process data
    
    //Output Data
    pTail09(filJ, fName); //Output file tail
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}


//Function to output the last 10 lines of a file to screen
void pTail09(fstream &fil, string name) {
    fil.open(name, ios::in); //Open the file
    if (!fil.fail()){ //check to see if the file opened correctly 
        string line="";  //string to hold data from each line of file
        int cnt=0; //counter to count the lines in the file
        while (fil){ //find the number of lines in the file
            getline(fil, line); //get file line, increment to next line
            cnt++; //increment counter of the number of lines
        }
        cnt-=1; //get rid of "EOF" line
        fil.close(); //closing file to reset input position
        fil.open(name, ios::in); //opening file to output tail
        if (cnt<10){ //if the file is less than 10 lines
            cout<<"<File less than 10 lines. Showing whole file>"<<endl;
            while (!fil.eof()) { //repeat to end of file
                getline(fil, line); //Get line of the file
                cout<<line<<endl; //output file line
            }
        fil.close(); //close file
        } else {
            int i=0; //counter to not print output until end of file
            while (!fil.eof()){ //repeat until end of file
                if (i<(cnt-10)){ //if counter is not within the last 10 lines 
                getline(fil, line); //advance to next line but don't print output
                } else {
                    getline(fil, line); //get data from file and advance to next line
                    cout<<line<<endl; //print the file line
                }
                i++; //increment the counter 
            }
        }
        fil.close(); //close the file
    } else {
        cout<<"ERROR OPENING FILE!"<<endl; //output error message if file did not open correctly
    }
}