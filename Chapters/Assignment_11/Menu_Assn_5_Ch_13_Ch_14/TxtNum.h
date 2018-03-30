/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TxtNum.h
 * Author: Scott Parker
 * Created on May 8th, 2017, 12:05 PM
 */

#ifndef TXTNUM_H
#define TXTNUM_H

#include <iostream>
#include <string>
using namespace std;

class TxtNum {
private:
    unsigned short number;
    string n1s[10] = {"ERR!", " One", " Two", " Three", " Four", " Five", " Six",
                      " Seven", " Eight", " Nine"};
    string nTeen[10] = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", 
                        " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string n10s[10] = {"ERR!", "ERR!", " Twenty", " Thirty", " Forty", " Fifty",
                       " Sixty", " Seventy", " Eighty", " Ninety"};
    string n100s[10] = {"ERR!", " One Hundred", " Two Hundred", " Three Hundred", 
                        " Four Hundred", " Five Hundred", " Six Hundred", " Seven Hundred",
                        " Eight Hundred", " Nine Hundred"};
    string n1000s[10] = {"ERR!", " One Thousand", " Two Thousand", " Three Thousand",
                         " Four Thousand", " Five Thousand", " Six Thousand", " Seven Thousand",
                         " Eight Thousand", " Nine Thousand"};
    
public: 
    TxtNum (int a) {number=a; }
    int getNum() const; //function to return number
    string txtVal() const; //Function to return the text value of an int
    
};


#endif /* TXTNUM_H */

