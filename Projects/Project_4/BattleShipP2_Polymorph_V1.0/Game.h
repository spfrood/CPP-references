/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Scott Parker
 *
 * Created on May 24, 2017, 2:46 PM
 */

#ifndef GAME_H
#define GAME_H

#include "AbsGame.h"
#include "Map.h"
#include "Guess.h"

class Game; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const Game &);

//All the elements for a game of battleship... 2 maps for each player
// the number of hits and number of total shots fired
class Game {
protected:
    Map player; //Player map data
    string lstShot;
    bool playing;
    bool shot;
    const int cols=10;
    const int rows=10;
    
public:
    Game();
    virtual ~Game();
    
    string getLast(); //return lstShot
    void setPlay(char); //set status of playing... 
    void mapClr(); //Reset entire game state to empty
    void okShot(Guess); //check to see if shot is hit or miss
    virtual void setMap(Guess, char); //Update map after a valid shot
    void setShip(int, int, int, char); //Place ships on map
    char getShip(int, int) const; //display map data for coordinates
    char getGues(int, int) const; //display map data for coordinates
    short getTurn() const; //Display total number of guesses
    short getHits() const; //Display number of hits
    bool gameOn() const; //return status of playing... if true game in progress, false to exit
    bool getShot() const; //return value of shot
    
    // Friends
    friend ostream &operator << (ostream &, const Game &);
    
};

#endif /* GAME_H */

