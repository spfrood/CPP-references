/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AddBook.h
 * Author: scott_r_parker
 *
 * Created on May 3, 2017,6:16 PM
 */

#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <string>
#include <iostream>
using namespace std;

class AddBook {
private:
    string name;
    string address;
    string  phone;
    short age;
    
public:
    AddBook();
    AddBook(string, string, string, short);
    void setData();
    void disData() const;
    string gName() const;
    string gAdd() const;
    string gPhone() const;
    short gAge() const;
};

#endif /* ADDBOOK_H */

