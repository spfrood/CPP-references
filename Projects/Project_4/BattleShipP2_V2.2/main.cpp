
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
#include <cctype>
#include <ctime>
#include <cstdlib>
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
void newBord(Game &, Game &); //Start a new game
void putShip(Game &); //Places the ships on the game board
bool locTest(int, int, int, char, Game &); //Check to see if ship can be put in location
void putComp(Game &); //Place the computer ships
//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice=0;
    Game p1; //Player 1
    Game p2; //Player 1
    
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
            case 2:{newBord(p1, p2);break;} //start a new game 
            case 1:{cout<<"This will resume a saved game"<<endl;break;} //Function to load a saved game
            default:
                cout<<"You are exiting the game"<<endl; //default option - exit menu
        }
    }while(choice>=1&&choice<=2); //show menu while choices all active
    
    cout << p1 << endl;
    cout << endl;
    cout << p2 << endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}


//*************************   locTest   ****************************************
//234567890123456789012345678901234567890123456789012345678901234567890123456789
//000000001111111111222222222233333333334444444444555555555566666666667777777777
//** Purpose:  //Returns true if location is bad
//** Inputs: column, row, size of ship, verticle or horiz, player object
//** Outputs: return true if a bad location is encountered 
//******************************************************************************
bool locTest(int putRow, int putCol, int size, char verHor, Game &p) {
    bool retVal=true;
    if (verHor=='v' || verHor=='V') {
        if (putRow+size>10) {
            cout<<"Ship is off the world!"<<endl;
            retVal=true; 
        } else {
            cout<<"Rows within range for vertical placement."<<endl;
            cout<<"Checking overlap!"<<endl;
            for (int i=0;i<size;i++) {
                if (p.getShip(putRow+i, putCol)=='~') {
                    retVal=false;
                } else {
                    retVal=true;
                    cout<<"Ship collision!"<<endl;
                    break;
                }
            }
        }
    } else {
        if (putCol+size>10) {
            cout<<"Ship is off the world!"<<endl;
            retVal=true; 
        } else {
            cout<<"Rows within range for horizontal placement."<<endl;
            cout<<"Checking overlap!"<<endl;
            for (int i=0;i<size;i++) {
                if (p.getShip(putRow, putCol+i)=='~') {
                    retVal=false;
                } else {
                    retVal=true;
                    cout<<"Ship collision!"<<endl;
                    break;
                }
            }
        }
    }
    return retVal;
}

//*************************   putShip   ****************************************
//234567890123456789012345678901234567890123456789012345678901234567890123456789
//000000001111111111222222222233333333334444444444555555555566666666667777777777
//** Purpose:  //function to place human player's ships
//** Inputs: Game p1 (player 1)
//** Outputs: none - will only manipulate the classes
//******************************************************************************
void putShip(Game &p) {
    int putRow=0, putCol=0;
    char verHor='\0';
    cout<<p<<endl;
    cout<<"Player 1, place your ships!"<<endl;
    for (int i=5;i>=2;i--) {
        cout<<"Place your ";
        if (i==5) cout<<"Battleship!"<<endl;
        else if (i==4) cout<<"Destroyer!"<<endl;
        else if (i==3) cout<<"Submarine!"<<endl;
        else cout<<"PT Boat!"<<endl;
        bool badLoc=true;
        while (badLoc) {
            cout<<"Choose the row to place the bow of the ship: "<<endl;
            char tmprow=val::inAlpha('A', 'J');
            tmprow=toupper(tmprow);
            putRow=tmprow-65;
            cout<<"choose the column to place the bow of the ship: "<<endl;
            putCol=val::inNum(putRow, 0, 9);
            cout<<"Enter V to place Vertially or H to place Horizontally!"<<endl;
            verHor=val::inChar('v', 'V', 'h', 'H');
            verHor=toupper(verHor);
            cout<<"You entered "<<verHor<<endl;
            badLoc=locTest(putRow, putCol, i, verHor, p);
        }
        p.setShip(putRow, putCol, i, verHor);
        cout<<p<<endl;
    }
}

//*************************   putComp   ****************************************
//234567890123456789012345678901234567890123456789012345678901234567890123456789
//000000001111111111222222222233333333334444444444555555555566666666667777777777
//** Purpose:  //function to place computer's ships
//** Inputs: Game p2 (player 2)
//** Outputs: none - will only manipulate the classes
//******************************************************************************
void putComp(Game &p) {
    int putRow=0, putCol=0;
    char verHor='\0';
    for (int i=5;i>=2;i--) {
        cout<<"Placing computer's ";
        if (i==5) cout<<"Battleship!"<<endl;
        else if (i==4) cout<<"Destroyer!"<<endl;
        else if (i==3) cout<<"Submarine!"<<endl;
        else cout<<"PT Boat!"<<endl;
        bool badLoc=true;
        while (badLoc) {
            putRow=rand()%10;
            putCol=rand()%10;
            if (rand()%2==0) {
                verHor='V';
            } else {
                verHor='H';
            }
            badLoc=locTest(putRow, putCol, i, verHor, p);
            badLoc?cout<<"Oops! Trying again!"<<endl:cout<<"Ship Placed!"<<endl;
        }
        p.setShip(putRow, putCol, i, verHor);
    }
}

//*************************   newBord   ****************************************
//234567890123456789012345678901234567890123456789012345678901234567890123456789
//000000001111111111222222222233333333334444444444555555555566666666667777777777
//** Purpose:  //function to start a new game
//** Inputs: Game p1 (player 1), Game p2 (player 2)
//** Outputs: none - will only manipulate the classes
//******************************************************************************
void newBord(Game &p1, Game &p2) {
    char chooser;
    Guess fire;
    putShip(p1); //place human player ships
    cout<<"Placing computer ships..."<<endl;
    putComp(p2);
    cout<<"Starting game..."<<endl;
    while (p1.gameOn() && p2.gameOn()) { //Keep going to play game until end or saved
        //This is to play the game... function to guess, score, etc.
        //pass guess. 
        cout<<"Your Maps"<<endl;
        cout<<p1<<endl;
        do {
            cout<<"Player 1, enter your coordinates: "<<endl;
            cin>>fire;
        } while (!p2.okShot(fire));
        p1.setMap(fire, p2.getShip(fire.getRow(), fire.getCol()));
        cout<<"You "<<p1.getLast()<<endl;
        
        if (p1.getHits()==14) {
            cout<<"Computer taking final shot!"<<endl;
        } else {
            cout<<"Computer taking a shot!"<<endl;
        }
        do {
            int tmpRow=rand()%10;
            int tmpCol=rand()%10;
            fire.setRow(tmpRow);
            fire.setCol(tmpCol);
        } while (!p1.okShot(fire));
        p2.setMap(fire, p1.getShip(fire.getRow(), fire.getCol()));
        cout<<"The computer's shot was a "<<p2.getLast()<<endl;
        cout<<"(C)ontinue, (S)ave, or e(X)it?";
        chooser=val::inChar('c', 'C', 's', 'S', 'X');
        chooser=toupper(chooser);
        if (chooser=='S') {
            cout<<"This will be the save game function!"<<endl;
            //call save game functions
            p1.setPlay(chooser);
        } else if (chooser=='X') {
            cout<<"Exiting without saving!"<<endl;
            p1.setPlay(chooser);
        }
        if (p1.getHits()==14) {
            cout<<"You have sank all of the enemy ships!"<<endl;
            p1.setPlay('X');
        }
        else if (p2.getHits()==14) {
            cout<<"The enemy sank all of your ships!"<<endl;
            p2.setPlay('X');
        }
    }
}


