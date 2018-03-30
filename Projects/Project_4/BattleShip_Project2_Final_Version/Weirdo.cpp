/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weirdo.cpp
 * Author: scott_r_parker
 * 
 * Created on June 3, 2017, 2:33 PM
 */

#include "Weirdo.h"

void Weirdo::setMap(Guess shot, char dat) { //update the map after a valid shot - hits counted as misses 
    if (dat=='o') {
        player.guess[shot.getRow()][shot.getCol()]='M';
        lstShot="HIT!       ";
        player.guesses++;
        player.hits++;
    } else {
        player.guess[shot.getRow()][shot.getCol()]=dat;
        lstShot="MISS!      ";
        player.guesses++;
    }
}