/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   datecls.h
 * Author: Scott Parker
 *
 * Created on May 1, 2017, 11:43 AM
 */

#ifndef DATECLS_H
#define DATECLS_H

#include <iostream>
#include <string>
using namespace std;

class P1DtCls {
    private:
        int month;
        int day;
        int year;
    public:
        void sDate();
        string gMonTxt();
        int gMonI();
        int gDay();
        int gYear();
        void outputs();
};

#endif /* DATECLS_H */

