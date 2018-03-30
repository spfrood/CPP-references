/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 15th, 2017, 1:15 PM
 * Purpose:  Static 2D Array
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int COLS=5;

//Function Prototypes Here
void fillAry(int [][COLS],int);
void prntAry(int [][COLS],int);
void prntAds(int [][COLS],int);

//Program Execution Begins Here
int main(int argc, char *argv[]) {
    //Set the random number generator seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and initialize all Variables Here
    const int ROWS=10;
    int table[ROWS][COLS]={};
    
    //Output the Table
    prntAry(table,ROWS);
    
    //Fill the array with trouble
    fillAry(table,ROWS);
    
    //Print out the copied/resized array
     prntAry(table,ROWS);
     prntAds(table,ROWS);

    //Exit
    return 0;
}

void prntAry(int a[][COLS],int rows){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAds(int a[][COLS],int rows){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            cout<<&a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[][COLS],int rows){
    //Fill with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            a[row][col]=rand()%90+10;
        }
    }
}