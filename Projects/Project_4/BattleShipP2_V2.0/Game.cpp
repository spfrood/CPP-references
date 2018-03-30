/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: Scott Parker
 * 
 * Created on May 24, 2017, 2:46 PM
 */

#include "Game.h"
#include "colors.h"

Game::Game() {
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            player.guess[i][j]='~';
            player.ship[i][j]='~';
        }
    }
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

Map Game::getMaps() {
    return player; //return the whole gamestate for the player
}

short Game::getTurn() { //return the total number of guesses
    return player.guesses;
}

short Game::getHits() { //return the number of successful shots
    return player.hits;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<<(ostream &strm, const Game &obj)
{
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            if (obj.player.guess[i][j]=='~') {
                strm << BGBLUE << CYAN << obj.player.guess[i][j] << RESET;
            } else if (obj.player.guess[i][j]=='H') {
                strm << BGRED << YELLOW << obj.player.guess[i][j] << RESET;
            } else if (obj.player.guess[i][j]=='M') {
                strm << BGWHITE << MAGENTA << obj.player.guess[i][j] << RESET;
            } else {
                strm << BGBLACK << WHITE << obj.player.guess[i][j] << RESET;
            }
        }
        strm << '\n';
    }
   return strm;
}