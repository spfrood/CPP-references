
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
#include <fstream>
using namespace std;

//User Libraries
#include "colors.h"
#include "val.h"
#include "Game.h"
#include "Map.h"
#include "Guess.h"
#include "Weirdo.h"


//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes
void newBord(Game &, Game &); //Start a new game
void putShip(Game &); //Places the ships on the game board
bool locTest(int, int, int, char, Game &); //Check to see if ship can be put in location
void putComp(Game &); //Place the computer ships
void savGame(Game, Game); //Function to save the game
void lodGame(Game &, Game &); //Function to load a saved game
void conBord(Game &, Game &); //Function to resume playing a saved game

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
            case 1:{conBord(p1, p2);break;} //Function to load a saved game
            default:
                cout<<"You are exiting the game"<<endl; //default option - exit menu
        }
    }while(choice>=1&&choice<=2); //show menu while choices all active
    
    cout<<"Playing a Bizarro game using derived class for PLAYER only and polymorphism!"<<endl;
    cout<<"Hits are misses and misses are hits!"<<endl;
    cout<<BOLDRED<<BGYELLOW<<"Saved games will NOT be resumable and will crash program when loaded!"<<RESET<<endl;
    Weirdo p3; //Weirdo class Player 3
    newBord(p3, p1); //passing derived class into same game function by reference
    
    
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
            cout<<"Ship is off the world! Vertically!"<<endl;
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
            cout<<"Ship is off the world! Horizontally!"<<endl;
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
//** Purpose:  //function to start a new game (new board)
//** Inputs: Game p1 (player 1), Game p2 (player 2)
//** Outputs: none - will only manipulate the classes
//******************************************************************************
void newBord(Game &p1, Game &p2) {
    char chooser;
    Guess fire;
    p1.mapClr(); //reset player 1 to defaults
    p2.mapClr(); //reset player 2 to defaults
    putShip(p1); //place human player ships
    cout<<"Placing computer ships..."<<endl;
    putComp(p2);
    cout<<"Starting game..."<<endl;
    while (p1.gameOn() && p2.gameOn()) { //Keep going to play game until end, exit or save
        cout<<"Your Maps"<<endl;
        cout<<p1<<endl;
        do {
            cout<<"Player 1, enter your coordinates: "<<endl;
            cin>>fire;
            p2.okShot(fire);
            if (!p2.getShot()) {
                cout<<"Invalid! Try different coordinates!"<<endl;
            }
        } while (!p2.getShot());
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
            p1.okShot(fire);
        } while (!p1.getShot());
        p2.setMap(fire, p1.getShip(fire.getRow(), fire.getCol()));
        cout<<"The computer's shot was a "<<p2.getLast()<<endl;
        cout<<"(C)ontinue, (S)ave, or e(X)it? "<<endl;
        chooser=val::inChar('c', 'C', 's', 'S', 'X');
        chooser=toupper(chooser);
        if (chooser=='S') {
            cout<<"Enter requested data to save the game"<<endl;
            savGame(p1, p2); //function to save the game
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

//*************************   conBord   ****************************************
//234567890123456789012345678901234567890123456789012345678901234567890123456789
//000000001111111111222222222233333333334444444444555555555566666666667777777777
//** Purpose:  //function to resume a saved game (continue board)
//** Inputs: Game p1 (player 1), Game p2 (player 2)
//** Outputs: none - will only manipulate the classes
//******************************************************************************
void conBord(Game &p1, Game &p2) {
    char chooser;
    Guess fire;
    lodGame(p1, p2); //load a saved game
    while (p1.gameOn() && p2.gameOn()) { //Keep going to play game until end, exit or save
        cout<<"Your Maps"<<endl;
        cout<<p1<<endl;
        do {
            cout<<"Player 1, enter your coordinates: "<<endl;
            cin>>fire;
            p2.okShot(fire);
            if (!p2.getShot()) {
                cout<<"Invalid! Try different coordinates!"<<endl;
            }
        } while (!p2.getShot());
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
            p1.okShot(fire);
        } while (!p1.getShot());
        p2.setMap(fire, p1.getShip(fire.getRow(), fire.getCol()));
        cout<<"The computer's shot was a "<<p2.getLast()<<endl;
        cout<<"(C)ontinue, (S)ave, or e(X)it? "<<endl;
        chooser=val::inChar('c', 'C', 's', 'S', 'X');
        chooser=toupper(chooser);
        if (chooser=='S') {
            cout<<"Enter requested data to save the game"<<endl;
            savGame(p1, p2); //function to save the game
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

//***********************   savGame   ******************************************
//234567890123456789012345678901234567890123456789012345678901234567890123456789
//000000001111111111222222222233333333334444444444555555555566666666667777777777
//** Purpose:  //Function to save the game
//** Inputs: Game p1, Game p2;
//** Outputs: none
//******************************************************************************
void savGame(Game p1, Game p2) {
    string line=""; //hold file names from bones file. also used as temp to hold names while counting lines
    string *gName=nullptr; //array of strings to hold file names
    int count=0, temp=0; //count variable and temp variable 
    fstream fil; //create filestream object
    fil.open ("bones.txt", ios::in); //open bones file in input mode
    if (fil.fail()){ //output error if file unable to open
        cout<<"ERROR! Unable to open BONES file!"<<endl;
        cout<<BLUE<<BGGREEN<<"Creating BONES file!"<<RESET<<endl;
        fil.clear();
        fil.open ("bones.txt", ios::out);
        fil.close();
        fil.open("bones.txt", ios::in);
    } else { //otherwise
        while (fil){ //find the number of lines in the file
            getline(fil, line); //get file line, increment to next line
            count++; //increment counter of the number of lines
        }
    }
    fil.close(); //close file
    
    if (count<2) count=2;
    gName=new string [count]; //create dynamic array to hold bones file data
    fil.open ("bones.txt", ios::in); //open bones file in input mode
    if (fil.fail()){ //output error if file fails to open
        cout<<"ERROR! Unable to open bones file!"<<endl;
    } else { //otherwise
        for (int i=0;i<count;i++){ //loop through file line by line
            getline(fil, gName[i]); //get file line, increment to next array element
        }
    }
    fil.close(); //close file
    cout<<"Current Save Files"<<endl;
    for (int i=0;i<count;i++) { //loop through array line by line
        if (gName[i]!=""){ //display array element if not empty line
            cout<<"Save file name: "<<gName[i]<<endl; 
        }
    }
    
    cout<<BOLDRED<<"WARNING! Duplicate names will overwrite!"<<RESET<<endl;
    cout<<BOLDRED<<"WARNING! Only enter alphanumeric characters!"<<RESET<<endl;
    cout<<"Enter the game name to save: "<<endl;
    cin.ignore(256, '\n');
    getline(cin, line); //enter the name of new savefile
    
    temp=0;
    while (gName[temp]!=line && temp<count){
        temp++;
        if (temp == count-1) {
            gName[temp]=line;
        }
    }
    if (temp<count-1){
        cout<<"file "<<line<<" overwritten!"<<endl;
    }
    
    cout<<"file names in array"<<endl;
    for (int i=0;i<count;i++){
        cout<<gName[i]<<endl;
    }
    
    fil.open("bones.txt", ios::out); //open bones file in output mode
    if (fil.fail()) { //output error message if file fails to open
        cout<<"ERROR! Unable to open bones file!"<<endl;
    } else { //otherwise
        for (int i=0;i<count;i++){ //loop through array line by line
            if (gName[i]!=""){ //if line is not blank
                fil<<gName[i]<<endl; //output array element as line in file
            }
        }
    }
    fil.close(); //close file
    delete [] gName; //clean up memory and delete dynamic array
    cout<<"Saving Game Data!"<<endl; 
    fil.open(line+".bin", ios::out | ios::binary); //open binary file in output mode to save game data
    fil.write(reinterpret_cast<char *>(&p1), sizeof(Game)); //write player 1 ship data to file
    fil.write(reinterpret_cast<char *>(&p2), sizeof(Game)); //write player 1 guess data to file
    fil.close(); //close file
}

//*************************   lodGame   ****************************************
//234567890123456789012345678901234567890123456789012345678901234567890123456789
//000000001111111111222222222233333333334444444444555555555566666666667777777777
//** Purpose:  //Function to load a saved game
//** Inputs: Game &p1, Game &p2
//** Outputs: none
//******************************************************************************
void lodGame(Game &p1, Game &p2){
    string line=""; //hold file names from bones file. also used as temp to hold names while counting lines
    fstream fil; //create filestream object
    p1.mapClr(); //reset player 1 to defaults
    p2.mapClr(); //reset player 2 to defaults
    cout<<endl;
    fil.open ("bones.txt", ios::in); //open bones file in input mode
    if (fil.fail()){ //output error if file did not open correctly
        cout<<"ERROR! Unable to open BONES file!"<<endl;
    } else {
        cout<<"List of *Savefiles*: "<<endl;
        while (fil){ //loop through file line by line
            getline(fil, line); //get file line, increment to next line
            cout<<"*"<<line<<"*"<<endl; //output text from that line in file
        }
    }
    fil.close(); //close file
    
    cout<<"Enter name of game to load: <Do not include * characters>"<<endl;
    cin.ignore(256, '\n');
    getline (cin, line); //enter name of savefile to open
    fil.open(line+".bin", ios::in | ios::binary); //open binary file name provided
    if (fil.fail()){
        cout<<"ERROR! Unable to open file!"<<endl;
        cout<<"Randomly creating new game state!"<<endl;
        putComp(p1); //randomly place player 1 ships
        putComp(p2); //randomly place player 2 ships
    } else { //read in binary file data to populate game array data
        fil.read(reinterpret_cast<char *>(&p1), sizeof(Game)); //read file to fill player 1 ship data 
        fil.read(reinterpret_cast<char *>(&p2), sizeof(Game)); //read file to fill player 1 guess data
        fil.close();
    }
    p1.setPlay('C');
    p2.setPlay('C');
} 
