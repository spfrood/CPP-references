
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Menu Template using switch, and do/while loop 
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
        cin>>choice;
        
        //Switch to determine the problem
        switch(choice){
            case '1':{
                cout<<"We are in Problem 1"<<endl;
                break;
            }
            case '2':{
                cout<<"We are in Problem 2"<<endl;
                break;
            }
            case '3':{
                cout<<"We are in Problem 3"<<endl;
                break;
            }
            default:
               cout<<"You are exiting the program"<<endl;
        }
            
    
    }while(choice>='1' && choice <= '3');
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

