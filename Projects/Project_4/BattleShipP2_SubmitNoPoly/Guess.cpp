
/* 
 * File:   Guess.cpp
 * Author: Scott Parker
 * 
 * Created on May 24, 2017, 2:46 PM
 */


#include <cctype>
#include "Guess.h"

Guess::Guess() {
    targRow=-1;
    targCol=-1;
}

void Guess::setRow(int a) {
    targRow=a;
}

void Guess::setCol(int a) {
    targCol=a;
}

int Guess::getCol() {
    return targCol;
}
    
int Guess::getRow() {
    return targRow;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<<(ostream &strm, const Guess &obj)
{
   strm << obj.targRow << ", " << obj.targCol;
   return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into FeetInches objects.    *
//********************************************************

istream &operator >> (istream &strm, Guess &obj)
{
    char temp='\0';
    // Prompt the user for the vertical axis (row)
    cout << "Enter target Row (A-J): ";
    strm >> temp;
    temp=toupper(temp);
    while (cin.fail() || !isalpha(temp) || (temp<65 || temp>74)) {
        cout<<"Enter target Row A-J only! ";
        cin.clear();
        cin.ignore(256, '\n');
        strm >> temp;
        temp=toupper(temp);
    }
    int conTemp=0;
    conTemp=temp-65; //convert character to int
    obj.targRow=conTemp;

    // Prompt the user for the horizontal axis (column)
    cout << "Enter target Column (0-9): ";
    strm >> obj.targCol;
    while (cin.fail() || obj.targCol<0 || obj.targCol>9) {
        cout<<"Enter target Column 0-9 only! ";
        cin.clear();
        cin.ignore(256, '\n');
        strm >> obj.targCol;
    }
   
   return strm;
}