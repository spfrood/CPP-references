/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 15th, 2017, 1:15 PM
 * Purpose:  Dynamic 2D Array
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int **fillAry(int,int);
void prntAry(int **,int,int);
void prntAds(int **,int,int);
void destroy(int **,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number generator seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and initialize all Variables Here
    int row1=10,row2=20,col1=5,col2=10;
    int **array=fillAry(row1,col1);
    int **brray=fillAry(row2,col2);
    
    //Print out the copied/resized array
    cout<<"Array array "<<array<<endl;
    prntAry(array,row1,col1);
    cout<<"Array brray "<<brray<<endl;
    prntAry(brray,row2,col2);

    //Delete the array
    destroy(array,row1);
    destroy(brray,row2);
    
    //Exit
    return 0;
}

void destroy(int **a,int rows){
    for(int row=0;row<rows;row++){
        delete []a[row];
    }
    delete []a;
}

void prntAry(int **a,int rows,int cols){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAds(int **a,int rows,int cols){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<&a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int **fillAry(int rows,int cols){
    //Memory Allocation
    int **a=new int*[rows];
    for(int row=0;row<rows;row++){
        a[row]=new int[cols];
    }
    
    //Fill with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            a[row][col]=rand()%90+10;
        }
    }
    return a;
}