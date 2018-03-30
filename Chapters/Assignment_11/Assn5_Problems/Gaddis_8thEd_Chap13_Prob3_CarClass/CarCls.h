/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CarCls.h
 * Author: scott_r_parker
 *
 * Created on May 3, 2017, 5:04 PM
 */

#ifndef CARCLS_H
#define CARCLS_H

#include <string>
#include <iostream>
using namespace std;

class CarCls {
private:
    int year;
    string make;
    int speed;
    
public:
    CarCls(int a, string b)
        { year=a; make=b; speed=0; }
    void accel() 
        { speed+=5; cout<<"Vroom...  "; }
    void decel()
        { speed-=5; cout<<"Eerrr!!!  "; }
    int getYear() const
        { return year; }
    string getMake() const
        { return make; }
    int getSpd() const
        { return speed; }
};

#endif /* CARCLS_H */

