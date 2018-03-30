
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Problem #5  (All Kinds of Sorting)
Sort a 10x15 array of characters.  Largest located
at index [0][0-14] and smallest at index [9][0-14].  
Create a procedure that passes the array to a print routine, 
then a procedure that sorts the array and returns the sorted array 
to the original procedure, and finish by using the same print routine.  
Fill the array with


Lcekoeddhoffbme
Lkcmggjcdhhglif
Cgldjhcekjigcde
Cgldjhcekjigcdz
Bfgmdbkcenlafjk
Fggdijijegfblln
Jjlncnimjldfedj
Amliglfohajcdmm
Balgfcaelhfkgeb
Kmlhmhcddfoeild


Note:  This is a character array
The output would be


Lkcmggjcdhhglif
Lcekoeddhoffbme
Kmlhmhcddfoeild
Jjlncnimjldfedj
Fggdijijegfblln
Cgldjhcekjigcdz
Cgldjhcekjigcde
Bfgmdbkcenlafjk
Balgfcaelhfkgeb
Amliglfohajcdmm

Full credit will be given if a file is used to read in the array.
Name the file input.dat

*/

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const int COLS=15;  //number of columns for array

//Function Prototypes
void prChAry(char [][COLS],int); //Function to print 2D array
void compRow(char [][COLS],int); //Function to sort 2D array
void swapRow(char [][COLS],int); //Swap row with one higher up

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //instantiate and/or open files
    ifstream in;
    ofstream out;

    //Declare Variables
    in.open("input.dat"); //opening data file
    const int ROWS=10;  //Number of rows for array
    char charray [ROWS][COLS]={};  //10x15 character array
    
    //Input Values
    for (int i=0;i<ROWS;i++){  //inputting data from file
        for (int j=0;j<COLS;j++){
            in>>charray[i][j];
        }
    }
    in.close();  //closing data file
    
    //Process by mapping inputs to outputs
    prChAry(charray,ROWS); //Printing current array contents
    compRow(charray,ROWS); //Sorting array descending alpha order
    cout<<endl;
    //Output values
    prChAry(charray,ROWS); //printing sorted array
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Print 2D array ********************************
//Description: Prints the array data to screen
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void prChAry(char a[][COLS],int row){
    for (int i=0;i<row;i++){  //Row data for array
        for (int j=0;j<COLS;j++){//print each column data 
            cout<<a[i][j];
        }
        cout<<endl; //only output endline at end of row
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Swap Row ********************************
//Description: Swaps row of array with one below it
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void swapRow(char a[][COLS], int now){  //swap row with row below it
    char temp=126;  //set initial temp value to one not used in the alpha array
    for (int j=0;j<COLS;j++){ //exchange elements in rows one at a time
        temp=a[now][j];
        a[now][j]=a[now+1][j];
        a[now+1][j]=temp;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Sort 2D array ********************************
//Description: Bubble sorts the array in descending alphabetical order
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void compRow(char a[][COLS],int row){
    bool swap;
    int h=0;

    do{
        swap=false;
        for(int i=0;i<row-1;i++){
            if(a[i][h]<a[i+1][h]){ //compare 1st element and swap row if true
                swapRow(a,i);
                swap=true; //set bool to true to initiate another run-through
            }
            else if (a[i][h]==a[i+1][h]){ //if first element is same in both rows
                int f=h;
                do{ //increment to next element until elements are not same
                    f++;
                } while (a[i][f]==a[i+1][f]);
                if (a[i][f]<a[i+1][f]){ //if current row less than next swap row
                    swapRow(a,i);
                    swap=true; //set bool to true to initiate another run-through
                }
            }
        }
    }while(swap);      
}
