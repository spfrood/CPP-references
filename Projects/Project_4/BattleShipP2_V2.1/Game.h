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
private:
    Map player; //Player map data
    const int cols=10;
    const int rows=10;
    string lstShot="";
    
protected:
    
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    Map getMaps(); //Display data for game
    char getShip(int, int); //display map data for coordinates
    char getGues(int, int); //display map data for coordinates
    short getTurn(); //Display guesses
    short getHits(); //Display number of hits
    bool okShot(Guess); //check to see if shot is hit or miss
    void setMap(Guess); //Update map after a valid shot
    void setShip(int, int, int, char); //Place ships on map
    
    // Friends
    friend ostream &operator << (ostream &, const Game &);
    
};

#endif /* GAME_H */

