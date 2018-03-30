
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 5, 2017, 12:09 AM
 * Purpose: 19. 2D Array Operations
Write a program that creates a two-dimensional array initialized with test 
data. Use any data type you wish. The program should have the following 
functions:
• getTotal. This function should accept a two-dimensional array as its argument
  and return the total of all the values in the array.
• getAverage. This function should accept a two-dimensional array as its 
  argument and return the average of all the values in the array.
• getRowTotal. This function should accept a two-dimensional array as its first
  argument and an integer as its second argument. The second argument should be
  the subscript of a row in the array. The function should return the total of 
  the values in the specified row.
• getColumnTotal. This function should accept a two-dimensional array as its 
  first argument and an integer as its second argument. The second argument 
  should be the subscript of a column in the array. The function should return 
  the total of the values in the specified column.
• getHighestInRow. This function should accept a two-dimensional array as its 
  first argument and an integer as its second argument. The second argument 
  should be the subscript of a row in the array. The function should return 
  the highest value in the specified row of the array.
• getLowestInRow. This function should accept a two-dimensional array as its 
  first argument and an integer as its second argument. The second argument 
  should be the subscript of a row in the array. The function should return 
  the lowest value in the specified row of the array.
Demonstrate each of the functions in this program. 
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
//Also use for multi-dimensional array column sizes
const int COLS=5;
const int ROWS=5;

//Function Prototypes
int getTotal(int[][COLS]);
float getAverage(int[][COLS]);
int getRowTotal(int[][COLS],int); 
int getColumnTotal(int[][COLS],int); 
int getHighestInRow(int[][COLS],int); 
int getLowestInRow(int[][COLS],int); 

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //initialize random number seed
    srand(static_cast<int>(time(0)));
    
    //Declare Variables
    
    int tstAray[ROWS][COLS]={};
    int subRow=0, subCol=0;
    
    //Input Values
    for (int i=0;i<ROWS;i++){ //cycling through rows
        for (int j=0;j<COLS;j++){ //cycling through columns
            tstAray[i][j]=rand()%100+1; //fill array value with random number between 1 and 100
            cout<<setw(6)<<tstAray[i][j];
        }
        cout<<endl;
    }
    do{ //inputting row value to pass to functions later
        cout<<"Please input the row number that will be passed to the functions."<<endl;
        cout<<"Must be less than the total number of rows (1 to "<<ROWS<<")."<<endl;
        cin>>subRow;
        if ((subRow<1)^(subRow>ROWS)) cout<<"Not a valid value!"<<endl;
    } while ((subRow<1)^(subRow>ROWS));
    subRow-=1;
    do{ //inputting column value to pass to functions later
        cout<<"Please input the column number that will be passed tot he functions."<<endl;
        cout<<"Must be less than the total number of columns (0 to "<<COLS<<")."<<endl;
        cin>>subCol;
        if ((subCol<0)^(subCol>4)) cout<<"Not a valid value!"<<endl;
    } while ((subCol<0)^(subCol>4));
    subCol-=1;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"The total of all values in this array is: "<<getTotal(tstAray)<<endl;
    cout<<"The average value of this array is: "<<getAverage(tstAray)<<endl;
    cout<<"The total of row "<<subRow+1<<" is: "<<getRowTotal(tstAray,subRow)<<endl; 
    cout<<"The total of column "<<subCol+1<<" is: "<<getColumnTotal(tstAray,subCol)<<endl; 
    cout<<"The highest value in row "<<subRow+1<<" is: "<<getHighestInRow(tstAray,subRow)<<endl; 
    cout<<"The lowest value in row "<<subRow+1<<" is: "<<getLowestInRow(tstAray,subRow)<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//This function should accept a two-dimensional array as its argument
//  and return the total of all the values in the array.
int getTotal(int array[][COLS]){
    int sumAll=0;
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLS;j++){
            sumAll+=array[i][j];
        }
    }
    return sumAll;
}

//This function should accept a two-dimensional array as its 
//  argument and return the average of all the values in the array.
float getAverage(int array[][COLS]){
    float avgAll=0;
    int sumAll=0;
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLS;j++){
            sumAll+=array[i][j];
        }
    }
    avgAll=(sumAll/(static_cast<float>(ROWS)*COLS));
    return avgAll;
} 

//This function should accept a two-dimensional array as its first
//  argument and an integer as its second argument. The second argument should be
//  the subscript of a row in the array. The function should return the total of 
//  the values in the specified row.
int getRowTotal(int array[][COLS],int rowVal){
    int sumRow=0;
    for (int i=0;i<COLS;i++){
        sumRow+=array[rowVal][i];
    }
    return sumRow;
} 

//This function should accept a two-dimensional array as its 
//  first argument and an integer as its second argument. The second argument 
//  should be the subscript of a column in the array. The function should return 
//  the total of the values in the specified column.
int getColumnTotal(int array[][COLS],int colVal){
    int sumCol=0;
    for (int i=0;i<ROWS;i++){
        sumCol+=array[i][colVal];
    }
    return sumCol;
} 

//This function should accept a two-dimensional array as its 
//  first argument and an integer as its second argument. The second argument 
//  should be the subscript of a row in the array. The function should return 
//  the highest value in the specified row of the array.
int getHighestInRow(int array[][COLS],int rowVal){
    int rowHigh=array[rowVal][0];
    for (int i=0;i<COLS;i++){
        if (rowHigh<array[rowVal][i])rowHigh=array[rowVal][i];
    }
    return rowHigh;
}

//This function should accept a two-dimensional array as its 
//  first argument and an integer as its second argument. The second argument 
//  should be the subscript of a row in the array. The function should return 
//  the lowest value in the specified row of the array.
int getLowestInRow(int array[][COLS],int rowVal){
    int rowLow=array[rowVal][0];
    for (int i=0;i<COLS;i++){
        if (rowLow>array[rowVal][i])rowLow=array[rowVal][i];
    }
    return rowLow;
} 