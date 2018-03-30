/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Worker.h
 * Author: scott_r_parker
 *
 * Created on May 3, 2017, 10:16 AM
 */

#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <iostream>
using namespace std;

class Worker {
private:
    string name;
    int idNum;
    string dept;
    string postn;
    
public:
    Worker();
    Worker(string, int, string, string);
    void setVals();
    void setVals(string, int, string, string);
    void dWorker(); //function to display the data stored in this object
    string getName() const
        { return name; }
    int getNum() const
        { return idNum; }
    string getDept() const
        { return dept; }
    string getPost() const
        { return postn; }
};

#endif /* WORKER_H */

