
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 21, 2017, 11:30 AM
 * Purpose: This brief program shows an example of pausing the screen
 * until the "enter" key is pressed without using system level commands.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    char pauser='X'; //Need a variable to use with the cin
    string pauseb=""; //This variable not integral to pausing. Used to check 
    //contents of buffer
    
    //Input Values
    cout<<"Press enter to continue"<<endl;
    cin.get(pauser); //input prompt required to pause.
    //cin.ignore(); //Only ignores one character
    //Can be used but is not reliable if more than one character was entered
    cin.ignore(256, '\n');  //Clear the buffer if user input more than just enter key
    //This basically ignores the entire contents of the buffer 
    cin.clear();  //resets flags for cin to avoid conflict with future input
    getline(cin, pauseb);  //getline stores the enter key at the end of the string
    //The getline is only used during testing to see what was in the contents of the
    //buffer after the pause.
    
    
    //system("pause");  //"Hit any key to continue" for windows machines
    //The above option gives an error in C++ 11 on Windows 10... Returns the error
    //returns "sh: pause: command not found" error 
    //DO NOT USE THE ABOVE METHOD OF PAUSING
    
    //cout<<"Press <ENTER> to continue"<<endl;
    //system("read");  //"Hit any key to continue" for MAC and Unix machines
    //Even though the above is supposed to be for *unix machines it works on
    //windows 10 with C++ 11
    //EVEN THOUGH THIS SEEMS TO WORK DO NOT USE AS IT IS SYSTEM DEPENDENT
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"pauser is "<<pauser<<endl; //no output if nothing entered during pause
    cout<<"buffer holds: "<<pauseb<<endl; //no output if buffer clear successful
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

