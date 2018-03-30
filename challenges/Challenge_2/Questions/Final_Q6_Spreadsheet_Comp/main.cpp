
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Problem #6  (Spreadsheet Stuff)
 * 
        Create the following input tables.  Output
the sum of the rows, columns and grand total.  You
will need to create procedures that print the table,
then sum rows, columns and grand total, then pass
that information to the same print routine.  Note:
the 2 procedures printTable,SumTable and finally a
call to printTable again are all invoked from subroutine 
main.  I want to see each number formatted to 6 spaces.  
Print the table out exactly as below.


Example Input Table
   136   101   102   103   104   105
   106   107   108   109   110   111
   112   113   114   115   116   117
   118   119   120   121   122   123
   124   125   126   127   129   130
Example Output Augmented Table with rows summed,
columns summed and the grand total printed.
   136   101   102   103   104   105   651
   106   107   108   109   110   111   651
   112   113   114   115   116   117   687
   118   119   120   121   122   123   723
   124   125   126   127   129   130   761
   596   565   570   575   581   587  3474


More credit will be given if you read the input and write 
the results to a file.  However, if you can't do this in 
a procedure then embed in the program.  But full credit 
will not be given for the problem if files
are not utilized. Name the files table.dat and augtable.dat

Flowchart your code

*/

//System Libraries
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const int COLSB=7; //number of columns in array with totals

//Function Prototypes
void prAry(int [][COLSB], int); //Function to print array
void sumAry(int [][COLSB], int); //Function to sum up rows and columns

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //instantiate and/or open files
    ifstream in;
    ofstream out;

    //Declare Variables
    const int ROWSB=6;  //Number of rows for array with totals
    int bArray [ROWSB][COLSB]={};  //6x7 integer array all value set to 0
    
    //Input Values
    in.open("table.dat"); //opening data file
    for (int i=0;i<ROWSB-1;i++){  //inputting data without "sum" row
        for (int j=0;j<COLSB-1;j++){  //Inputting without "sum" column
            in>>bArray[i][j];
        }
    }
    in.close();  //closing data file
    
    //Process by mapping inputs to outputs
    cout<<"Your data shows: "<<endl;
    prAry(bArray, ROWSB);
    cout<<endl;
    sumAry(bArray, ROWSB); 
    cout<<"Table with Rows and Columns summed: "<<endl;
    cout<<"Data being written to file 'augtable.dat' "<<endl;
    prAry(bArray, ROWSB);
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Sum Array ********************************
//Description: Sum the rows and columns of the array
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void sumAry(int a[][COLSB], int row){
    for (int i=0;i<row;i++){ 
        for (int j=0;j<COLSB-1;j++){ //Sum the columns
                a[i][COLSB-1]+=a[i][j];
            }
    }
    for (int i=0;i<COLSB;i++){ 
        for (int j=0;j<row-1;j++){ //Sum the rows
                a[row-1][i]+=a[j][i];
            }
    }
    
}


//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Print 2D array ********************************
//Description: Prints the array data to screen and to file
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void prAry(int a[][COLSB], int row){
    for (int i=0;i<row;i++){  //Print array info 
        for (int j=0;j<COLSB;j++){ 
            if (a[i][j]!=0){  //print data if value not = zero
                cout<<setw(6)<<a[i][j];
            }
            else if (a[i][j]==0){  //Print whitespace if value is zero
                cout<<setw(6)<<" ";
            }
        }
        cout<<endl;
    }
    
    ofstream out;
    out.open("augtable.dat");
    for (int i=0;i<row;i++){
        for (int j=0;j<COLSB;j++){
            if (a[i][j]!=0){
                out<<setw(6)<<a[i][j];
            }
            else if (a[i][j]==0){
                out<<setw(6)<<" ";
            }
        }
        out<<endl;
    }
    out.close();
}