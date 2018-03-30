
/*
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 20, 2017, 11:30 AM
 * Purpose: Battleship game Project 2 
 * Notes: Revised version for Project 2 to include features from later
 * chapters
 */

//System Libraries
#include <iostream> 
using namespace std;

//User Libraries
#include "colors.h"
#include "val.h"
#include "Game.h"
#include "Map.h"


//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes



//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    
    //Declare Variables
    int choice=0;
    Game p1; //Player 1
    Game p2; //Player 1
    Guess fire;
    cin>>fire;
    cout<<fire<<endl;
    
    //Game menu
    do{
        //Output switch menu screen
        cout<<"Choose from the list <non-numeric data will be ignored>"<<endl; 
        cout<<"Enter 1 to resume a saved game"<<endl; //enter 1 to resume saved game
        cout<<"Enter 2 to start a new game"<<endl; //enter 2 for a new game
        cout<<"Enter 0 (zero) or a number not listed to exit."<<endl; //0 or unlisted number to exit
        choice=val::inNum(choice); //Using template for data input and validation 

        //Switch to determine the Problem
        switch(choice){
            case 2:{cout<<"This will start a new game"<<endl;break;} //start a new game 
            case 1:{cout<<"This will resume a saved game"<<endl;break;} //Function to load a saved game
            default:
                cout<<"You are exiting the game"<<endl; //default option - exit menu
        }
    }while(choice>=1&&choice<=2); //show menu while choices all active
    
    cout<< p1 <<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

