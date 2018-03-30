/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   val.h
 * Author: scott_r_parker
 *
 * Created on May 22, 2017, 6:57 PM
 */

 /* //input and validate character (char) data.
        //Up to 5 inputs, each input is an acceptable value for the return value
        //of the function... 
        char inChar(char inA='\0', char inB='\0', char inC='\0', char inD='\0', char inE='\0')
  * 
  * 
*/


#ifndef VAL_H
#define VAL_H

#include <iostream>
#include <cctype>
using namespace std;

namespace val {

//input and validate character (char) data.
    //Up to 4 inputs, each input is an acceptable value for the return value
    //of the function... 
    char inAlpha() {
        char choice='\0';
        cin>>choice;
        while (cin.fail() || !isalpha(choice)) {
            cout<<"Enter an alphabetical character only!"<<endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin>>choice;
        }
        return choice;
    }
    char inAlpha(char low, char high) {
        char choice='\0';
        cin>>choice;
        while (cin.fail() || !isalpha(choice) || (toupper(choice)<low || toupper(choice)>high)) {
            cout<<"Enter a letter from "<<low<<" to "<<high<<"!"<<endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin>>choice;
        }
        return choice;
    }
    
    char inChar(char inA='\0', char inB='\0', char inC='\0', char inD='\0', char inE='\0') {
        char choice='\0';
        cin >> choice;
        if (inA=='\0' && inB=='\0' && inC=='\0' && inD=='\0' && inE=='\0') {
            while (cin.fail()) {
                cout<<"Invalid input! Enter an ASCII character!"<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>choice;
            }
        } else if (inB=='\0' && inC=='\0' && inD=='\0' && inE=='\0'){
            while (cin.fail() || choice!=inA) {
                cout<<"Invalid input! Valid entry is: "<<inA<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>choice;
            }
        } else if (inC=='\0' && inD=='\0' && inE=='\0'){
            while (cin.fail() || (choice!=inA && choice!=inB)) {
                cout<<"Invalid input! Valid entries are: "<<inA<<", "<<inB<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>choice;
            }
        } else if (inD=='\0' && inE=='\0'){
            while (cin.fail() || (choice!=inA && choice!=inB && choice!=inC)) {
                cout<<"Invalid input! Valid entries are: "<<inA<<", "<<inB<<", "<<inC<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>choice;
            }
        } else if (inE=='\0'){
            while (cin.fail() || (choice!=inA && choice!=inB && choice!=inC && choice!=inD)) {
                cout<<"Invalid input! Valid entries are: "<<inA<<", "<<inB<<", "<<inC<<", "<<inD<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>choice;
            }
        } else {
            while (cin.fail() || (choice!=inA && choice!=inB && choice!=inC && choice!=inD && choice!=inE)) {
                cout<<"Invalid input! Valid entries are: "<<inA<<", "<<inB<<", "<<inC<<", "<<inD<<", "<<inE<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>choice;
            }
        }
        return choice;
    }
    
    //input and validate a signed int 
    //first input is minimum value, 2nd input is max value
    //Overloaded (no arguments) only validates input TYPE
    template <class T>
    T inNum(T type, long long int low, long long int high) { //long long int for low/high range
        T x=type; //determines the datatype to use (useful for ranges)
        cin >> x; 
        while (cin.fail() || x<low || x>high) {
            cout<<"Invalid input! Enter number from "<<low<<" to "<<high<<"!"<<endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin>>x;
        }
        return x;
    }
    
    template <class T>
    T inNum(T type) {
        T x=type;
        cin>>x;
        while (cin.fail()) {
            cout<<"Invalid input!"<<endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin>>x;
        }
        return x;
    }
    
}

#endif /* VAL_H */

