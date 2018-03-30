
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on April 1, 2017, 5:29 PM
 * Purpose: 2. File Display Program
Write a program that asks the user for the name of a file. The program should 
display the contents of the file on the screen. If the file’s contents won’t fit 
on a single screen, the program should display 24 lines of output at a time, 
and then pause. Each time the program pauses, it should wait for the user to 
strike a key before the next 24 lines are displayed.
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
    string pauser=""; //Character to pause screen output
    string fName=""; //string to hold file name
    string fData=""; //string to hold data from the file
    fstream fil; //Create filestream object 
    
    //Input Values
    cout<<"Enter the name of the file: (dataA.txt, dataB.txt, dataC.txt,"<<endl;
    cout<<"                     dataD.txt, and dataE.txt were used in testing)"<<endl;
    cin>>fName;
    fil.open(fName, ios::in); //Open file for input
    
    //Process by mapping inputs to outputs
    
    //Output values
    if (!fil.fail()) { //if can not open file then break program
        while (!fil.eof()) { //loop first 10 lines and not fil.eof
            getline(fil, fData); //Get line i of the file
            cout<<fData<<endl; //output file line
            count++; //increment count until next line
            if (count%24==0){ //Pause after 24 lines of text output
                cout<<"<Press enter to continue>"<<endl; //notify of pause
                cin.ignore(256, '\n');
                getline (cin, pauser);
            }
        }
        fil.close(); //close file
    }
    else cout << "ERROR: Cannot open the file."<<endl; //Else output if unable to open file
    
    //Clean up and close files
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

