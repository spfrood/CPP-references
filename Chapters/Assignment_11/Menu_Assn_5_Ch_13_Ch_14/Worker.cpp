/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Worker.cpp
 * Author: scott_r_parker
 * 
 * Created on May 3, 2017, 10:16 AM
 */

#include "Worker.h"

Worker::Worker() {
    name="";
    idNum=0;
    dept="";
    postn="";
}

void Worker::setVals() {
    string n, d, p;
    int num;
    cout<<"Enter the employee name: ";
    getline(cin, n);
    cout<<"Enter the employee ID number: ";
    cin>>num;
    cin.ignore(256, '\n');
    cout<<"Enter the department: ";
    getline(cin, d);
    cout<<"Enter the position: ";
    getline(cin, p);
    name=n;
    idNum=num;
    dept=d;
    postn=p;
}

void Worker::setVals(string n, int num, string d, string p) {
    name=n;
    idNum=num;
    dept=d;
    postn=p;
}

void Worker::dWorker () {
    cout<<"Employee name: "<<getName()<<endl;
    cout<<"ID Number: "<<getNum()<<endl;
    cout<<"Department: "<<getDept()<<endl;
    cout<<"Position: "<<getPost()<<endl;
}