/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: scott_r_parker
 *
 * Created on April 13, 2017, 2:36 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

struct Player{
    int guesses=0;
    int hits=0;
    const int ROWS=10;
    const int COLS=10;
    int guess[10][10]={};
    int ship[10][10]={};
};

#endif /* PLAYER_H */

