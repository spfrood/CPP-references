/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Tests.h"

//Constructor - enter data
Tests::Tests () {
    cout<<"Enter the scores (no negative values)"<<endl;
    cout<<"Enter score for test 1: ";
    cin>>test1;
    while (cin.fail() || test1<0) {
        cout<<"Error! Enter again!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>test1;
    }
    cout<<"Enter score for test 2: ";
    cin>>test2;
    while (cin.fail() || test2<0) {
        cout<<"Error! Enter again!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>test2;
    }
    cout<<"Enter score for test 3: ";
    cin>>test3;
    while (cin.fail() || test3<0) {
        cout<<"Error! Enter again!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>test3;
    }
}

//Check to see if scores are correct and re-enter if not
void Tests::setTest (){
    char chooser='\0';
    do {
        cout<<"The tests have the following scores: "<<endl;
        cout<<setprecision(3)<<fixed;
        cout<<"Test 1: "<<test1<<endl;
        cout<<"Test 2: "<<test2<<endl;
        cout<<"Test 3: "<<test3<<endl;
        cout<<"Are these scores correct?"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>chooser;
        if (chooser=='n' || chooser=='N') {
            cout<<"Enter the scores (no negative values)"<<endl;
            cout<<"Enter score for test 1: ";
            cin>>test1;
            while (cin.fail() || test1<0) { 
                cout<<"Error! Enter again!"<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>test1;
            }
            cout<<"Enter score for test 2: ";
            cin>>test2;
            while (cin.fail() || test2<0) {
                cout<<"Error! Enter again!"<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>test2;
            }
            cout<<"Enter score for test 3: ";
            cin>>test3;
            while (cin.fail() || test3<0) {
                cout<<"Error! Enter again!"<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>test3;
            }
        }
    } while (chooser=='n' || chooser=='N');
}

//Find the average
float Tests::avgTest () const{
    return (test1+test2+test3)/3.0f;
}