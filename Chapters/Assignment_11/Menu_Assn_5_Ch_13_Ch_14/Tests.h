/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tests.h
 * Author: scott_r_parker
 *
 * Created on May 3, 2017, 5:04 PM
 */

#ifndef TESTS_H
#define TESTS_H

#include <iomanip>
#include <iostream>
using namespace std;

class Tests {
private:
    float test1;
    float test2;
    float test3;
    
public:
    Tests ();
    void setTest ();
    float avgTest () const;
};

#endif /* TESTS_H */

