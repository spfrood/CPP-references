
/* 
 * File:   Guess.cpp
 * Author: Scott Parker
 * 
 * Created on May 24, 2017, 2:46 PM
 */

#include "Guess.h"



//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<<(ostream &strm, const Guess &obj)
{
   strm << obj.vert << ", " << obj.horiz;
   return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into FeetInches objects.    *
//********************************************************

istream &operator >> (istream &strm, Guess &obj)
{
   // Prompt the user for the vertical axis (row)
   cout << "Enter row number (0-9): ";
   strm >> obj.vert;
   while (cin.fail() || obj.vert<0 || obj.vert>9) {
       cout<<"Enter row 0-9!";
       cin.clear();
       cin.ignore(256, '\n');
       strm >> obj.vert;
   }

   // Prompt the user for the horizontal axis (column)
   cout << "Enter column: ";
   strm >> obj.horiz;
   while (cin.fail() || obj.horiz<0 || obj.horiz>9) {
       cout<<"Enter row 0-9!";
       cin.clear();
       cin.ignore(256, '\n');
       strm >> obj.horiz;
   }
   
   return strm;
}