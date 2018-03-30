/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   game.h
 * Author: rcc
 *
 * Created on May 17, 2017, 3:29 PM
 */

#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game {

private:
    Player p1;
    Player p2;
    
public:
    Game();
    virtual ~Game();

};

#endif /* GAME_H */

