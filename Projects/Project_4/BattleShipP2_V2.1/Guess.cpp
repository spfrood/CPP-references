
/* 
 * File:   Guess.cpp
 * Author: Scott Parker
 * 
 * Created on May 24, 2017, 2:46 PM
 */


#include <cctype>
#include "Guess.h"


int Guess::getCol() {
    return targcol;
}
    
int Guess::getRow() {
    return targrow;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<<(ostream &strm, const Guess &obj)
{
   strm << obj.targcol << ", " << obj.targrow;
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
    cout << "Enter target column (A-J): ";
    strm >> temp;
    temp=toupper(temp);
    while (cin.fail() || !isalpha(temp) || (temp<65 || temp>74)) {
        cout<<"Enter target column A-J only! ";
        cin.clear();
        cin.ignore(256, '\n');
        strm >> temp;
        temp=toupper(temp);
    }
    int conTemp=0;
    conTemp=temp-65;
    obj.targcol=conTemp;

    // Prompt the user for the horizontal axis (column)
    cout << "Enter target row (0-9): ";
    strm >> obj.targrow;
    while (cin.fail() || obj.targrow<0 || obj.targrow>9) {
        cout<<"Enter target row 0-9 only! ";
        cin.clear();
        cin.ignore(256, '\n');
        strm >> obj.targrow;
    }
   
   return strm;
}