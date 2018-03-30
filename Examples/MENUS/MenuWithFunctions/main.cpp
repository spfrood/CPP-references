
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Menu Template using functions
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
void prob1();
void prob2();
void prob3();


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop on the menu
    
    do {
        
        //Input Values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for problem with Do-While"<<endl;
        cout<<"Type 2 for problem with While"<<endl;
        cout<<"Type 3 for problem with For"<<endl;
        cout<<"Hit other key to exit"<<endl;
        cin>>choice;
        
        //Switch to determine the problem
        switch(choice){
            case '1':prob1(); break;
            case '2':prob2(); break;
            case '3':prob3(); break;
            default:
               cout<<"You are exiting the program"<<endl;
        }
            
    
    }while(choice>='1' && choice <= '3');
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000001111111111222222222233333333334444444444555555555566666666667777777777
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*********************************  Problem 1  ********************************
//Description:  
//Inputs:    Datatype, Range/Validity, Units, 
//Outputs:
//Data Stuff:


void prob1() {
    cout<<"Output for function for problem 1"<<endl;
}

//000000001111111111222222222233333333334444444444555555555566666666667777777777
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*********************************  Problem 2  ********************************
//Description:  
//Inputs:    Datatype, Range/Validity, Units, 
//Outputs:
//Data Stuff:

void prob2() {
    cout<<"Output for function for problem 2"<<endl;
}

//000000001111111111222222222233333333334444444444555555555566666666667777777777
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*********************************  Problem 3  ********************************
//Description:  
//Inputs:    Datatype, Range/Validity, Units, 
//Outputs:
//Data Stuff:

void prob3() {
    cout<<"Output for function for problem 3"<<endl;
}

