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

Game::Game() { //initialize game to all ocean spaces
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

char Game::getShip(int col, int row) { //return map value for listed coordinate
    return player.ship[col][row];
}

char Game::getGues(int col, int row) { //return map value for listed coordinate
    return player.guess[col][row];
}

short Game::getTurn() { //return the total number of guesses
    return player.guesses;
}

short Game::getHits() { //return the number of successful shots
    return player.hits;
}

void Game::setMap(Guess shot) { //update the map after a valid shot
    if (player.ship[shot.getCol()][shot.getRow()]=='S') {
        player.ship[shot.getCol()][shot.getRow()]='H';
    } else if (player.ship[shot.getCol()][shot.getRow()]=='~') {
        player.ship[shot.getCol()][shot.getRow()]='M';
    } else { 
        lstShot="ERROR! ERROR!";
    }
}

bool Game::okShot(Guess shot) { //return the number of successful shots
    bool temp=false;
    if (player.ship[shot.getCol()][shot.getRow()]=='S') {
        temp=true;
        lstShot="HIT!";
        player.hits++;
        player.guesses++;
        setMap(shot);
    } else if (player.ship[shot.getCol()][shot.getRow()]=='~') {
        temp=true;
        lstShot="MISS!";
        player.guesses++;
        setMap(shot);
    } else {
        temp=false;
        lstShot="Invalid! TRY AGAIN!";
    }
    return temp;
}

//Edit map data to place a ship.
void Game::setShip(int row, int col, int size, char verHor) {
    if (verHor=='v' || verHor=='V') {
        for (int i=0;i<size;i++) {
            player.ship[row+i][col]='S';
        } 
    } else {
        for (int i=0;i<size;i++) {
            player.ship[row][col+i]='S';
        } 
    }
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<<(ostream &strm, const Game &obj)
{
    strm << BGBLACK << WHITE << "Legend:  " << BGBLUE << CYAN << "~" << RESET << BGBLACK << WHITE
            << " OCEAN   " << BGRED << YELLOW << "H" << RESET << BGBLACK << WHITE << " HIT   " 
            << BGWHITE << MAGENTA << "M" << RESET << BGBLACK << WHITE << " MISS      " << endl;
    strm << BGBLACK << WHITE << "S" << BGBLACK << WHITE << " UNDAMAGED SHIP                       " << endl;
    strm << BGBLACK << "                                       " << endl;
    strm << BGBLACK << GREEN << "   GUESSES                SHIPS        " << endl;
    strm << BGBLACK << WHITE << "   0123456789             0123456789   " << RESET << endl;
    for (int i=0;i<10;i++) {
        strm << BGBLACK << WHITE << static_cast<char>(i+65) << ": ";
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
        strm << BGBLACK << WHITE << "          " << BGBLACK << WHITE << static_cast<char>(i+65) << ": ";
        for (int j=0;j<10;j++) {
            if (obj.player.ship[i][j]=='~') {
                strm << BGBLUE << CYAN << obj.player.ship[i][j] << RESET;
            } else if (obj.player.ship[i][j]=='H') {
                strm << BGRED << YELLOW << obj.player.ship[i][j] << RESET;
            } else if (obj.player.ship[i][j]=='M') {
                strm << BGWHITE << MAGENTA << obj.player.ship[i][j] << RESET;
            } else {
                strm << BGBLACK << WHITE << obj.player.ship[i][j] << RESET;
            }
        }
        strm  << BGBLACK << "   "<< '\n';
    }
    strm << BGBLACK << "                                       " << RESET;
    return strm;
}