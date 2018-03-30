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
    player.guesses=0;
    player.hits=0;
    playing=true;
    shot=false;
    lstShot="No Shots!  ";
}

Game::~Game() {
}

void Game::mapClr() { //reset to default status
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            player.guess[i][j]='~';
            player.ship[i][j]='~';
        }
    }
    player.guesses=0;
    player.hits=0;
    playing=true;
    shot=false;
    lstShot="No Shots!  ";
}

string Game::getLast() { //return value of lstShot (last shot) text results
    return lstShot;
}

bool Game::gameOn() const { //return value of playing... if false then game ends
    return playing;
}

bool Game::getShot() const { //return value of playing... if false then game ends
    return shot;
}

char Game::getShip(int col, int row) const { //return map value for listed coordinate
    return player.ship[col][row];
}

char Game::getGues(int col, int row) const { //return map value for listed coordinate
    return player.guess[col][row];
}

short Game::getTurn() const { //return the total number of guesses
    return player.guesses;
}

short Game::getHits() const { //return the number of hits
    return player.hits;
}

void Game::setMap(Guess shot, char dat) { //update the map after a valid shot
    if (dat=='o') {
        player.guess[shot.getRow()][shot.getCol()]='M';
        lstShot="MISS!      ";
        player.guesses++;
    } else {
        player.guess[shot.getRow()][shot.getCol()]=dat;
        lstShot="HIT!       ";
        player.guesses++;
        player.hits++;
    }
}

void Game::setPlay(char choice) { //Set the boolean value of playing
    bool retVal=false;
    if (choice=='C') {
        retVal=true;
    } else retVal=false;
    playing=retVal;
}


void Game::okShot(Guess fire) { //Check to see if shot is valid (hit, miss, on map, not duplicate)
    bool tmpShot=false;
    if (player.ship[fire.getRow()][fire.getCol()]=='S') {
        tmpShot=true;
        player.ship[fire.getRow()][fire.getCol()]='H';
    } else if (player.ship[fire.getRow()][fire.getCol()]=='~') {
        tmpShot=true;
        player.ship[fire.getRow()][fire.getCol()]='o';
    } else {
        tmpShot=false;
    }
    shot=tmpShot;
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
    strm << BGBLACK << UNDERLINE << "         " << WHITE << "S" << " SHIP   " << RESET << UNDERLINE << BGWHITE << MAGENTA 
            << "o" << RESET << UNDERLINE << BGBLACK << WHITE << " ENEMY GUESS        " << RESET << endl;
    strm << BGBLACK << GREEN << "   GUESSES                SHIPS        " << endl;
    strm << BGBLACK << WHITE << "   " << UNDERLINE << "0123456789" << RESET << BGBLACK << WHITE 
            << "             " << UNDERLINE "0123456789" << RESET << BGBLACK << WHITE << "   " << RESET << endl;
    for (int i=0;i<10;i++) { //display the maps and score data
        strm << BGBLACK << WHITE << static_cast<char>(i+65) << ": ";
        for (int j=0;j<10;j++) {
            if (obj.player.guess[i][j]=='~') {
                strm << BGBLUE << CYAN << obj.player.guess[i][j] << RESET;
            } else if (obj.player.guess[i][j]=='#') {
                strm << BGYELLOW << GREEN << obj.player.guess[i][j] << RESET;
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
            } else if (obj.player.guess[i][j]=='#') {
                strm << BGYELLOW << GREEN << obj.player.guess[i][j] << RESET;
            } else if (obj.player.ship[i][j]=='H') {
                strm << BGRED << YELLOW << obj.player.ship[i][j] << RESET;
            } else if (obj.player.ship[i][j]=='o') {
                strm << BGWHITE << MAGENTA << obj.player.ship[i][j] << RESET;
            } else {
                strm << BGBLACK << WHITE << obj.player.ship[i][j] << RESET;
            }
        }
        strm  << BGBLACK << "   "<< '\n';
    }
    strm << BGBLACK << WHITE << " HITS: " << obj.player.hits << "   " << "SHOTS: " 
            << obj.player.guesses << "   " << "Last: " << obj.lstShot << RESET;
    return strm;
}