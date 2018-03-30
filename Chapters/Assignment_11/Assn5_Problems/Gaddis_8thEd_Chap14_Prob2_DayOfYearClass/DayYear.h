/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayYear.h
 * Author: scott_r_parker
 *
 * Created on May 9, 2017, 4:55 PM
 */

#ifndef DAYYEAR_H
#define DAYYEAR_H

#include <string>
using namespace std;

class DayYear {
private:
    unsigned short number;
    
public:
    DayYear(unsigned short);
    string print ();
};

#endif /* DAYYEAR_H */

