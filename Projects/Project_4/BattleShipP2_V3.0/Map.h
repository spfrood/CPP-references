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

#ifndef MAP_H
#define MAP_H

struct Map{
    short hits;
    short guesses;
    char guess[10][10]={}; //Map to keep track of guesses (hits and misses)
    char ship[10][10]={}; //Map to keep track of player's ships (undamaged, placements, and hit)
};

#endif /* MAP_H */

