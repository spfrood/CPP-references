
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on April 2, 2017, 6:00 PM
 * Purpose: 3. Punch Line
Write a program that reads and prints a joke and its punch line from two 
different files. The first file contains a joke, but not its punch line. The 
second file has the punch line as its last line, preceded by “garbage.” The main 
function of your program should open the two files and then call two functions, 
passing each one the file it needs. The first function should read and display 
each line in the file it is passed (the joke file). The second function should 
display only the last line of the file it is passed (the punch line file). It 
should find this line by seeking to the end of the file and then backing up to 
the beginning of the last line. Data to test your program can be found in the 
joke.txt and punchline.txt files.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void pJoke07(fstream &); //Function to output contents of ASCII file to screen
void pPnch08(fstream &); //Function to output the last line of a file to screen
void timer (int); //function to create a timer

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    fstream filJ; //fstream to hold joke text file
    fstream filP; //fstream to hold punchline text file
    string pauser=""; //it's all in the timing
    
    //Input Values
    filJ.open("joke.txt", ios::in); //open file with the joke
    filP.open("punchline.txt", ios::in); //open file that has the punchline
    
    //Process by mapping inputs to outputs
    
    //Output values
    pJoke07(filJ); //tell the joke
    cout<<"..."<<endl;
    timer(3);
    //cout<<"<Press enter to continue>"<<endl; //pause for timing
    //cin.clear();
    //cin.ignore(256, '\n'); //clearing buffer because sometimes it causes pause to fail
    //getline(cin, pauser); //input prompt required to pause.
    pPnch08(filP); //output the punchline
    
    //cleanup
    filJ.close(); //close file
    filP.close(); //close file
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to create a brief timer
void timer(int delay){
    int beg=time(0), end=time(0);
    do {
        end=time(0);
    } while (end-beg<delay);
}

//Function to output contents of ASCII file to screen
void pJoke07(fstream &fil) {
    string line=""; //string to hold the data from the file
    while (!fil.eof()){
        getline(fil, line); //Send line of file data to string
        cout<<line<<endl; //output the string
    }
}

//Function to output the last line of a file to screen
void pPnch08(fstream &fil) {
    string line="";
    char ch='\0';
    int n=1;
    
    while (ch!='\n'){ //find the last line by scanning for newline feeds
        fil.seekg(-n, ios::end); //move cursor to end of file
        fil.get(ch); //read character from file
        n++; //move back another character 
    }

    getline(fil, line); //get the last line and put into a string
    cout<<line<<endl; //output the last line of the file
}