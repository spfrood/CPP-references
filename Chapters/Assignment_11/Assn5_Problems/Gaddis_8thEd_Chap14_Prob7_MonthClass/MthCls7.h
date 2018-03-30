/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MthCls7.h
 * Author: Scott Parker
 *
 * Created on May 10, 2017, 11:25 AM
 */

#ifndef MTHCLS7_H
#define MTHCLS7_H

#include <string>
#include <iostream>
using namespace std;

class MthCls7 {
private:
    string mName;
    int mNumber;
public:  
    //Constructors
    MthCls7();
    MthCls7(string);
    MthCls7(int);
    
    //Setters / Mutators
    void setData ();
    void setData (string);
    void setData (int);
    
    //data checker
    bool badTxt(string);
    
    //Getters
    string getName () const;
    int getNumb () const;
    
    //Operator overloads
    MthCls7 operator ++ ();
    MthCls7 operator ++ (int);
    MthCls7 operator -- ();
    MthCls7 operator -- (int);
    
    // Friends (to overload cin and cout)
    friend ostream &operator << (ostream &, const MthCls7 &);
    friend istream &operator >> (istream &, MthCls7 &);
};

#endif /* MTHCLS7_H */
