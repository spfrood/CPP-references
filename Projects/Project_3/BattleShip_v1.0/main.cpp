
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on April 10, 2017, 2:00 PM
 * Purpose: Battleship game Project 1 
 * Notes: In the ship array 0 indicates ocean (cyan O), 1 indicates a ship (black X), 2 indicates
 *     a ship that has been hit (red X)
 *        In the the guess array 0 indicates ocean (cyan O), 1 indicates a miss (black X) and 2
 *     indicates a hit (red X)
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

//User Libraries
#include "colors.h"
#include "player.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const int COLS=26;

//Function Prototypes
void disGame(int [][COLS], int [][COLS], int); //function to display the game board
void setGame(int [][COLS], int [][COLS], int); //function to clear the gameboard
void putShip(int [][COLS], int, int); //Function to place a ship on the gameboard
bool rngFind(int [][COLS], int, int, int, int, char); //Function to see if ship is being placed in valid position
void pAllShp(int [][COLS], int); //Function to place all ships on the gameboard
void disShip(int [][COLS], int); //function to display the ship map only
void newGame(int [][COLS], int [][COLS], int [][COLS], int [][COLS], int); //function to play the game
void clrData(int [][COLS], int [][COLS], int [][COLS], int [][COLS], int); //function to reset all current game data
void pGameH(int [][COLS], int [][COLS], int [][COLS], int [][COLS], int); //Play a game with two human players
void pGameC(int [][COLS], int [][COLS], int [][COLS], int [][COLS], int); //Play a game versus the computer
void pShipC(int [][COLS], int); //function to place all ships for computer player



//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice=0;
    const int ROWS=12;
    int p1guess[ROWS][COLS]={}; //array to hold player 1 guesses
    int p1ship[ROWS][COLS]={}; //array to hold player 1 ship info
    int p2guess[ROWS][COLS]={}; //array to hold player 2 guesses
    int p2ship[ROWS][COLS]={}; //array to hold player 2 ship info
    
    //Process by mapping inputs to outputs
    cout<<"Player 1 layout: "<<endl;
    disGame(p1guess, p1ship, ROWS); //show the current playfield
    cout<<"Player 2 layout: "<<endl;
    disGame(p2guess, p2ship, ROWS); //show the current playfield
    
    //Game menu
    do{
    
        //Input values
        cout<<"Choose from the list <non-numeric data will be ignored>"<<endl;
        cout<<"Enter 1 to resume a saved game"<<endl;
        cout<<"Enter 2 to start a new game"<<endl;
        cout<<"Enter 0 (zero) or a number not listed to exit."<<endl;
        cin>>choice;
        while (cin.fail()) { //Loop to validate input
            cout<<"INPUT INVALID! "<<endl;
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter a valid choice!:"<<endl;
            cin>>choice;
        }

        //Switch to determine the Problem
        switch(choice){
            case 2:{newGame(p1ship, p1guess, p2ship, p2guess, ROWS);break;} //start a new game 
            case 1:{cout<<"Put load game function here"<<endl;break;} //Function to load a saved game
            default:
                cout<<"You are exiting the game"<<endl;
        }
    }while(choice>=1&&choice<=3); //show menu while choices all active
    
    cout<<"Player 1 layout: "<<endl;
    disGame(p1guess, p1ship, ROWS); //show the current playfield
    cout<<"Player 2 layout: "<<endl;
    disGame(p2guess, p2ship, ROWS); //show the current playfield
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}


//Play a game with two human players
void pGameH(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows) {
    
}

//Play a game versus the computer
void pGameC(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows) {
    
}

//function to place all ships for computer player
void pShipC(int ship[][COLS], int rows){
    char verHor='\0';
    int intCol=0;
    int putRow=0;
    bool shipSet=false;
    
    for (int size=5;size>=2;size--) {
        cout<<"PLACING COMPUTER ";
        if (size==2) cout<<"PT BOAT!"<<endl;
        else if (size==3) cout<<"SUBMARINE!"<<endl;
        else if (size==4) cout<<"DESTROYER!"<<endl;
        else if (size==5) cout<<"BATTLESHIP!"<<endl;
        do {
            intCol=rand()%COLS;
            putRow=rand()%rows;
            rand()%2==0?verHor='v':verHor='h';
            if (verHor=='v'){
                if (!rngFind(ship, rows, size, putRow, intCol, verHor)){
                    shipSet=false;
                   cout<<"Invalid location! Try again!"<<endl;
                } else {
                    for (int i=0;i<size;i++){
                        ship[putRow+i][intCol]=1;
                        shipSet=true;
                    }
                }
            } else {
                if (!rngFind(ship, rows, size, putRow, intCol, verHor)){
                    shipSet=false;
                    cout<<"Invalid location! Try again!"<<endl;
                } else {
                    for (int i=0;i<size;i++){
                        ship[putRow][intCol+i]=1;
                        shipSet=true;
                    }
                }
            }
        } while (!shipSet);
    }
}

//function to play the game
void newGame(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows){
    char chooser='\0'; //choice variable
    string pauser=""; //pause input
    cout<<"(H)uman or (C)omputer for player 2? <Enter H or C>"<<endl;
    cin>>chooser; //Choose to play against a human or the computer
    while (cin.fail() || (chooser!='h' && chooser!='H' && chooser!='c' && chooser!='C')) { //validate data 
        cin.clear(); //clear cin flags
        cin.ignore(256, '\n'); //ignore contents of buffer
        cout<<"Please enter 'H' or 'C'!"<<endl; //output available choices
        cin>>chooser; //input choice again until valid
    }
    clrData(p1ship, p1guess, p2ship, p2guess, rows); //clear any game data in memory 
    if (chooser=='h' || chooser=='H') {
        cout<<"<Press enter for Player 1 to place ships>"<<endl; //notify of pause
        cin.ignore(256, '\n');
        getline (cin, pauser);
        pAllShp(p1ship, rows); //Place all ships on for player 1
        cout<<"<Press enter to clear screen>"<<endl; //notify of pause
        cin.ignore(256, '\n');
        getline (cin, pauser);
        for (int i=0;i<1000;i++){
            cout<<endl;
        }
        cout<<"<Press enter for Player 2 to place ships>"<<endl; //notify of pause
        getline (cin, pauser);
        pAllShp(p2ship, rows); //Place all ships on for player 2
        cout<<"<Press enter to clear screen>"<<endl; //notify of pause
        cin.ignore(256, '\n');
        getline (cin, pauser);
        for (int i=0;i<1000;i++){
            cout<<endl;
        }
        cout<<"Starting game..."<<endl;
        pGameH(p1ship, p1guess, p2ship, p2guess, rows); //Play the game with two humans
    } else {
        cout<<"Player 1: Place your ships on the map!"<<endl;
        pAllShp(p1ship, rows); //Place all ships on for player 1
        cout<<"Computer placing ships now..."<<endl;
        pShipC(p2ship, rows); //place all ships for computer player
        pGameC(p1ship, p1guess, p2ship, p2guess, rows); //Play the game vs. computer
    }
} 

//function to reset all current game data
void clrData(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows){
    setGame(p1guess, p1ship, rows);  //Reset playfield for player 1
    setGame(p2guess, p2ship, rows);  //Reset playfield for player 2
} 

//function to display the ship map only
void disShip(int ship[][COLS], int rows){
    cout<<"SHIP POSITIONS"<<endl;
    cout<<"   ABCDEFGHIJKLMNOPQRSTUVWXYZ"<<endl;
    for (int i=0;i<rows;i++){
        cout<<setw(3)<<left<<i;
        for (int j=0;j<COLS;j++){
            if (ship[i][j]==0){
                cout<<CYAN<<"O"<<RESET;
            }
            else if (ship[i][j]==1){
                cout<<BLACK<<"X"<<RESET;
            } else {
                cout<<RED<<"X"<<RESET;
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

//Function to place all ships on the gameboard
void pAllShp(int ships[][COLS], int rows){
    for (int i=5;i>=2;i--){
        cout<<"Choose where to place your ";
        if (i==2) cout<<"PT BOAT!"<<endl;
        else if (i==3) cout<<"SUBMARINE!"<<endl;
        else if (i==4) cout<<"DESTROYER!"<<endl;
        else if (i==5) cout<<"BATTLESHIP!"<<endl;
        else cout<<"ERROR! SHOULD NEVER GET TO THIS MESSAGE!"<<endl;
        putShip(ships, rows, i);
        disShip(ships, rows);
    }
}

//Function to check if the ship will fit on the board and is not placed on top of another ship
bool rngFind(int ships[][COLS], int rows, int size, int putRow, int intCol, char verHor){
    if (verHor=='v' || verHor=='V'){
        if ((putRow+size)>rows){
            cout<<"Ship off the world!"<<endl;
            return false;
        } else {
            for (int i=0;i<size;i++) {
                if (ships[putRow+i][intCol]!=0) {
                    cout<<"Ship collision!"<<endl;
                    return false;
                } else {
                    return true;
                }
            }
        }
    } else {
        if ((intCol+size)>COLS){
            cout<<"Ship off the world!"<<endl;
            return false;
        } else {
            for (int i=0;i<size;i++) {
                if (ships[putRow][intCol+i]!=0) {
                    cout<<"Ship collision!"<<endl;
                    return false;
                } else {
                    return true;
                }
            }
        }
    }
    return false;
}

//Function to place a ship on the gameboard
void putShip(int ships[][COLS], int rows, int size){
    char putCol='\0';
    char verHor='\0';
    int intCol=0;
    int putRow=0;
    bool shipSet=false;
    while (!shipSet){
        cout<<"Which column and row should hold the bow of the ship?"<<endl;
        cout<<"Enter Column (A through Z)"<<endl;
        cin>>putCol;
        while (cin.fail() || !isalpha(putCol)){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"You must enter a letter A to Z..."<<endl;
            cin>>putCol;
        }
        if (isupper(putCol)){
            intCol=(putCol-65);
        } else {
            intCol=(putCol-97);
        }
        cout<<"Enter Row (0 to 11)"<<endl;
        cin>>putRow;
        while (cin.fail() || putRow<0 || putRow>11){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Enter a row from 0 to 11.."<<endl;
            cin>>putRow;
        }
        cout<<"Place the ship vertically or horizontally (V/H)?"<<endl;
        cin>>verHor;
        while (cin.fail() || (verHor!='v' && verHor!='V' && verHor!='h' && verHor!='H')){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Please enter 'V' or 'H'!"<<endl;
            cin>>verHor;
        }
        if (verHor=='v' || verHor=='V'){
            if (!rngFind(ships, rows, size, putRow, intCol, verHor)){
                shipSet=false;
                cout<<"Invalid location! Try again!"<<endl;
            } else {
                for (int i=0;i<size;i++){
                    ships[putRow+i][intCol]=1;
                    shipSet=true;
                }
            }
        } else {
            if (!rngFind(ships, rows, size, putRow, intCol, verHor)){
                shipSet=false;
                cout<<"Invalid location! Try again!"<<endl;
            } else {
                for (int i=0;i<size;i++){
                    ships[putRow][intCol+i]=1;
                    shipSet=true;
                }
            }
        }
    }
}

//function to clear the gameboard and set all values to 0
void setGame(int ship[][COLS], int guess[][COLS], int rows){
    for (int i=0;i<rows;i++){ //run through the rows
        for (int j=0;j<COLS;j++){ //run through the columns
            guess[i][j]=0; //set array for guesses all to false
            ship[i][j]=0; //set array for ships all to false
        }
    }
}

//function to display the game board
void disGame(int guess[][COLS], int ship[][COLS], int rows){
    cout<<"GUESSES"<<endl;
    cout<<"   ABCDEFGHIJKLMNOPQRSTUVWXYZ"<<endl;
    for (int i=0;i<rows;i++){
        cout<<setw(3)<<left<<i;
        for (int j=0;j<COLS;j++){
            if (guess[i][j]==0){
                cout<<CYAN<<"O"<<RESET;
            }
            else if (guess[i][j]==1){
                cout<<BLACK<<"X"<<RESET;
            }
            else cout<<RED<<"X"<<RESET;
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"SHIP POSITIONS"<<endl;
    cout<<"   ABCDEFGHIJKLMNOPQRSTUVWXYZ"<<endl;
    for (int i=0;i<rows;i++){
        cout<<setw(3)<<left<<i;
        for (int j=0;j<COLS;j++){
            if (ship[i][j]==0){
                cout<<CYAN<<"O"<<RESET;
            }
            else if (ship[i][j]==1){
                cout<<BLACK<<"X"<<RESET;
            } else {
                cout<<RED<<"X"<<RESET;
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
