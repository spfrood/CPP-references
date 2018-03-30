/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbsGame.h
 * Author: rcc
 *
 * Created on May 24, 2017, 2:42 PM
 */

#ifndef ABSGAME_H
#define ABSGAME_H

class AbsGame{
public:
    virtual char getShip()=0;
    virtual char getGues()=0;
    virtual short getTurn()=0;
    virtual short getHits()=0;
};

#endif /* ABSGAME_H */

