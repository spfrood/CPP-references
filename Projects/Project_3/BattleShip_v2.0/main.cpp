
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
#include <cctype>
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
int entGues(int [][COLS], int [][COLS], int); //function for player to enter a guess
int comGues(int [][COLS], int [][COLS], int, int); //function for computer to enter a guess
void savGame(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows); //Function to save the game
void lodGame(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows); //Function to load a saved game
void resGame(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows); //Function to resume a saved game 



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
            case 1:{resGame(p1ship, p1guess, p2ship, p2guess, ROWS);break;} //Function to load a saved game
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

//Function to resume a saved game
void resGame(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows){
    char chooser='\0';
    
    lodGame(p1ship, p1guess, p2ship, p2guess, rows); //Load a saved game
    cout<<"Playing versus (C)omputer or (H)uman?"<<endl;
    cout<<"**Player 1 always Human in vs. computer!!!**"<<endl;
    cout<<"Enter C/H now!"<<endl;
    cin>>chooser;
    chooser=toupper(chooser);
    while (cin.fail() || chooser!='C'){
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Enter 'C' or 'H' to continue!"<<endl;
        cin>>chooser;
        chooser=toupper(chooser);
    }
} 

//Function to load a saved game
void lodGame(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows){
    string line=""; //hold file names from bones file. also used as temp to hold names while counting lines
    fstream fil;
    clrData(p1ship, p1guess, p2ship, p2guess, rows); //clear any game data in memory 
    cout<<endl;
    fil.open ("bones.txt", ios::in);
    if (fil.fail()){
        cout<<"ERROR! Unable to open BONES file!"<<endl;
    } else {
        cout<<"List of *Savefiles*: "<<endl;
        while (fil){ //find the number of lines in the file
            getline(fil, line); //get file line, increment to next line
            cout<<"*"<<line<<"*"<<endl;
        }
    }
    fil.close();
    
    cout<<"Enter name of game to load: <Do not include * characters>"<<endl;
    cin.ignore(256, '\n');
    getline (cin, line);
    fil.open(line+".bin", ios::in | ios::binary);
    //int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows
    fil.read(reinterpret_cast<char *>(p1ship), (rows*COLS)*sizeof(int));
    fil.read(reinterpret_cast<char *>(p1guess), (rows*COLS)*sizeof(int));
    fil.read(reinterpret_cast<char *>(p2ship), (rows*COLS)*sizeof(int));
    fil.read(reinterpret_cast<char *>(p2guess), (rows*COLS)*sizeof(int));
    fil.close();
} 

//Function to save the game
void savGame(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows){
    string line=""; //hold file names from bones file. also used as temp to hold names while counting lines
    string *gName=nullptr; //array of strings to hold file names
    int count=0, temp=0;
    fstream fil;
    fil.open ("bones.txt", ios::in);
    if (fil.fail()){
        cout<<"ERROR! Unable to open BONES file!"<<endl;
    } else {
        while (fil){ //find the number of lines in the file
            getline(fil, line); //get file line, increment to next line
            count++; //increment counter of the number of lines
        }
    }
    fil.close();
    
    gName=new string [count];
    fil.open ("bones.txt", ios::in);
    if (fil.fail()){
        cout<<"ERROR! Unable to open bones file!"<<endl;
    } else {
        for (int i=0;i<count;i++){
            getline(fil, gName[i]); //get file line, increment to next line
        }
    }
    fil.close();
    cout<<"Current Save Files"<<endl;
    for (int i=0;i<count;i++) {
        if (gName[i]!=""){
            cout<<"Save file name: "<<gName[i]<<endl;
        }
    }
    
    cout<<BOLDRED<<"WARNING! Duplicate names will overwrite!"<<RESET<<endl;
    cout<<BOLDRED<<"WARNING! Only enter alphanumeric characters!"<<RESET<<endl;
    cout<<"Enter the game name to save: ";
    getline(cin, line);
    temp=0;
    while (line!=gName[temp] && temp<count){
        temp++;
    }
    if (temp==count) gName[temp-1]=line;
    else {
        cout<<"Overwriting existing game name: "<<gName[temp]<<endl;
        gName[temp]=line;
    }

    fil.open("bones.txt", ios::out);
    if (fil.fail()) {
        cout<<"ERROR! Unable to open bones file!"<<endl;
    } else {
        for (int i=0;i<count;i++){
            if (gName[i]!=""){
                fil<<gName[i]<<endl;
            }
        }
    }
    fil.close();
    delete [] gName;
    cout<<"Saving Game!"<<endl;
    fil.open(line+".bin", ios::out | ios::binary);
    //int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows
    fil.write(reinterpret_cast<char *>(p1ship), (rows*COLS)*sizeof(int));
    fil.write(reinterpret_cast<char *>(p1guess), (rows*COLS)*sizeof(int));
    fil.write(reinterpret_cast<char *>(p2ship), (rows*COLS)*sizeof(int));
    fil.write(reinterpret_cast<char *>(p2guess), (rows*COLS)*sizeof(int));
    fil.close();
} 

//function for player to enter a guess
int entGues(int pGuess[][COLS], int opShip[][COLS], int rows){
    char putCol='\0';
    int intCol=0;
    int putRow=0;
    int hitMiss=0;
    bool shipSet=false;
    while (!shipSet){
        cout<<"Enter Column (A through Z)"<<endl;
        cin>>putCol;
        while (cin.fail() || !isalpha(putCol)){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"CHEAT ACTIVATED! SHOWING COMPUTER SHIPS!"<<endl;
            disShip(opShip, rows);
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
        while (cin.fail() || putRow<0 || putRow>=rows){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Enter a row from 0 to 11.."<<endl;
            cin>>putRow;
        }
        if (pGuess[putRow][intCol]!=0) {
            cout<<"Position already guessed!"<<endl;
        } else if (opShip[putRow][intCol]==1) {
            pGuess[putRow][intCol]=2;
            cout<<"Hit!"<<endl;
            opShip[putRow][intCol]=2;
            hitMiss=1;
            shipSet=true;
        } else {
            pGuess[putRow][intCol]=1;
            opShip[putRow][intCol]=-1;
            cout<<"Miss!"<<endl;
            hitMiss=0;
            shipSet=true;
        }
    } 
    return hitMiss; 
}

//function for computer to enter a guess
int comGues(int pGuess[][COLS], int opShip[][COLS], int rows, int gues){
    int intCol=rand()%COLS;
    int putRow=rand()%rows;
    int hitMiss=0;
    bool shipSet=false;
    while (!shipSet){
        if (gues>0 && gues%11==0){
            for (int i=0;i<rows && !shipSet;i++) {
                for (int j=0;j<COLS && !shipSet;j++){
                    if (pGuess[i][j]==0){
                        if (opShip[i][j]==1){
                            cout<<"Lucky Hit!"<<endl;
                            pGuess[i][j]=2;
                            opShip[i][j]=2;
                            shipSet=true;
                            hitMiss=1;
                        }
                    }
                }
            } 
        } else if (pGuess[putRow][intCol]!=0) {
            cout<<"Position already guessed!"<<endl;
            intCol=rand()%COLS;
            putRow=rand()%rows;
        } else if (opShip[putRow][intCol]==1) {
            pGuess[putRow][intCol]=2;
            cout<<"Hit!"<<endl;
            opShip[putRow][intCol]=2;
            hitMiss=1;
            shipSet=true;
        } else {
            pGuess[putRow][intCol]=1;
            opShip[putRow][intCol]=-1;
            cout<<"Miss!"<<endl;
            hitMiss=0;
            shipSet=true;
        }
    } 
    return hitMiss; ;
}

//Play a game with two human players
void pGameH(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows) {
    Player p1score, p2score;
    string pauser="";
    do {
        cin.clear();
        cout<<"Beginning round: "<<p1score.guesses+1<<endl;
        cout<<"Player 1 enter coordinates, Player 2 turn your back:"<<endl;
        cout<<"<Press enter to clear screen>"<<endl; //notify of pause
        getline (cin, pauser);
        for (int i=0;i<1000;i++){
            cout<<endl;
        }
        disGame(p1guess, p1ship, rows);
        p1score.hits+=entGues(p1guess, p2ship, rows);
        p1score.guesses++;
        cout<<"<Press enter to clear screen>"<<endl; //notify of pause
        cin.ignore(256, '\n');
        getline (cin, pauser);
        for (int i=0;i<1000;i++){
            cout<<endl;
        }
        cout<<"Player 2 enter coordinates, Player 1 turn your back:"<<endl;
        cout<<"<Press enter to clear screen>"<<endl; //notify of pause
        getline (cin, pauser);
        for (int i=0;i<1000;i++){
            cout<<endl;
        }
        disGame(p2guess, p2ship, rows);
        p2score.hits+=entGues(p2guess, p1ship, rows);
        p2score.guesses++;
        cout<<"<Press enter to clear screen>"<<endl; //notify of pause
        cin.ignore(256, '\n');
        getline (cin, pauser);
        for (int i=0;i<1000;i++){
            cout<<endl;
        }
        cout<<"Current Game Status:"<<endl;
        cout<<"Player 1 hits: "<<p1score.hits<<" guesses: "<<p1score.guesses<<endl;
        cout<<"Player 2 hits: "<<p2score.hits<<" guesses: "<<p1score.guesses<<endl;
        cout<<"<Press enter to continue, 'N' or 'n' to save and exit>"<<endl; //notify of pause
        cin.ignore(256, '\n');
        getline (cin, pauser);
    } while (p1score.hits<14 && p2score.hits<14 && pauser!="n" && pauser!="N");
    if (pauser=="n" || pauser=="N") savGame(p1ship, p1guess, p2ship, p2guess, rows);
    cout<<"Exiting Game!"<<endl;
}

//Play a game versus the computer
void pGameC(int p1ship[][COLS], int p1guess[][COLS], int p2ship[][COLS], int p2guess[][COLS], int rows) {
    Player p1score, p2score;
    string pauser="";
    do {
        cout<<"Player 1 please enter your guess:"<<endl;
        p1score.hits+=entGues(p1guess, p2ship, rows);
        p1score.guesses++;
        cout<<"Computer guessing now:"<<endl;
        p2score.hits+=comGues(p2guess, p1ship, rows, p2score.guesses);
        p2score.guesses++;
        cout<<"Current Status: "<<endl;
        disGame(p1guess, p1ship, rows);
        cout<<"Player 1 hits: "<<p1score.hits<<" guesses: "<<p1score.guesses<<endl;
        cout<<"Player 2 hits: "<<p2score.hits<<" guesses: "<<p1score.guesses<<endl;
        cout<<"<Press enter to continue, 'N' or 'n' to save and exit>"<<endl; //notify of pause
        cin.ignore(256, '\n');
        getline (cin, pauser);
    } while (p1score.hits<14 && p2score.hits<14 && pauser!="n" && pauser!="N");
    if (pauser=="n" || pauser=="N") savGame(p1ship, p1guess, p2ship, p2guess, rows);
    cout<<"Exiting Game!"<<endl;
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
    cout<<"YOUR SHIP POSITIONS"<<endl;
    cout<<"   ABCDEFGHIJKLMNOPQRSTUVWXYZ"<<endl;
    for (int i=0;i<rows;i++){
        cout<<setw(3)<<left<<i;
        for (int j=0;j<COLS;j++){
            if (ship[i][j]==0){
                cout<<CYAN<<"O"<<RESET;
            }
            else if (ship[i][j]==1){
                cout<<BLACK<<"X"<<RESET;
            } else if (ship[i][j]==2) {
                cout<<RED<<INVERSE<<"H"<<RESET;
            } else {
                cout<<MAGENTA<<"o"<<RESET;
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
    bool shipOk=false;
    if ((verHor=='v') || (verHor=='V')){
        if ((putRow+size)>rows){
            cout<<"Ship off the world!"<<endl;
            shipOk=false;
        } else {
            for (int i=0;i<size;i++) {
                if (ships[putRow+i][intCol]!=0) {
                    cout<<"Ship collision!"<<endl;
                    shipOk=false;
                    break;
                } else {
                    shipOk=true;
                }
            }
        }
    } else {
        if ((intCol+size)>COLS){
            cout<<"Ship off the world!"<<endl;
            shipOk=false;
        } else {
            for (int i=0;i<size;i++) {
                if (ships[putRow][intCol+i]!=0) {
                    cout<<"Ship collision!"<<endl;
                    shipOk=false;
                    break;
                } else {
                    shipOk=true;
                }
            }
        }
    }
    return shipOk;
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
    cout<<"Your GUESS Map   Ocean="<<CYAN<<"O"<<RESET<<"  Miss="<<BLACK<<"M"<<RESET
            <<"  Hit="<<RED<<INVERSE<<"H"<<RESET<<endl;
    cout<<"   ABCDEFGHIJKLMNOPQRSTUVWXYZ"<<endl;
    for (int i=0;i<rows;i++){
        cout<<setw(3)<<left<<i;
        for (int j=0;j<COLS;j++){
            if (guess[i][j]==0){
                cout<<CYAN<<"O"<<RESET;
            }
            else if (guess[i][j]==1){
                cout<<BLACK<<"M"<<RESET;
            }
            else cout<<RED<<INVERSE<<"H"<<RESET;
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Your SHIPS   Ocean="<<CYAN<<"O"<<RESET<<"  Enemy Miss="<<MAGENTA<<"o"
            <<RESET<<"  Hit Ship="<<RED<<INVERSE<<"H"<<RESET<<"  Ship Position="
            <<BLACK<<"X"<<RESET<<endl;
    cout<<"   ABCDEFGHIJKLMNOPQRSTUVWXYZ"<<endl;
    for (int i=0;i<rows;i++){
        cout<<setw(3)<<left<<i;
        for (int j=0;j<COLS;j++){
            if (ship[i][j]==0){
                cout<<CYAN<<"O"<<RESET;
            }
            else if (ship[i][j]==1){
                cout<<BLACK<<"X"<<RESET;
            } else if (ship[i][j]==2) {
                cout<<RED<<INVERSE<<"H"<<RESET;
            } else {
                cout<<MAGENTA<<"o"<<RESET;
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
