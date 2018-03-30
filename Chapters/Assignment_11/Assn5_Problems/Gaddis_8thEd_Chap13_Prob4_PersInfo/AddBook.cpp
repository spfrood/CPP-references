/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AddBook.cpp
 * Author: scott_r_parker
 *
 * Created on May 3, 2017,6:16 PM
 */

#include "AddBook.h"

AddBook::AddBook() {
    name="";
    address="";
    phone="";
    age=0;
}
void AddBook::setData() {
    cout<<"Enter name"<<endl;
    getline(cin, name);
    cout<<"Enter address"<<endl;
    getline(cin, address);
    cout<<"Enter phone"<<endl;
    getline(cin, phone);
    cout<<"Enter age"<<endl;
    cin>>age;
    cin.ignore(256, '\n');
}
void AddBook::disData() const{
    cout<<"Name: "<<gName()<<"    Age: "<<gAge()<<endl;
    cout<<"Address: "<<gAdd()<<endl;
    cout<<"Phone: "<<gPhone()<<endl;
}
string AddBook::gName() const{
    return name;
}
string AddBook::gAdd() const{
    return address;
}
string AddBook::gPhone() const{
    return phone;
}
short AddBook::gAge() const{
    return age;
}