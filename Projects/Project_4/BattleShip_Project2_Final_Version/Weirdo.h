/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weirdo.h
 * Author: scott_r_parker
 *
 * Created on June 3, 2017, 2:33 PM
 */

#ifndef WEIRDO_H
#define WEIRDO_H
#include "Game.h"

class Weirdo : public Game
{
private: 
    
public:
    Weirdo() : Game() {};
    void setMap(Guess, char);

};

#endif /* WEIRDO_H */

