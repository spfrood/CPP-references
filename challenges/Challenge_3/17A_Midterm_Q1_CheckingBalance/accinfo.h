/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   accinfo.h
 * Author: scott_r_parker
 *
 * Created on April 18, 2017, 6:12 PM
 */

#ifndef ACCINFO_H
#define ACCINFO_H

struct AccInfo {
    string cusName; //string to hold customer name
    string address; //Customer street address
    string city; //customer city
    string state; //customer state
    int zip; //customer zipcode
    string accNum; //use strlen(name) to get length of string
    float strtBal; //starting balance 
    float endBal; //final balance of account
    int outChck; //size of array (checks written)
    float *allChck; //checks written this month
    int inDep; //size of array (deposits made)
    float *allDep; //deposits made this month
};


#endif /* ACCINFO_H */

