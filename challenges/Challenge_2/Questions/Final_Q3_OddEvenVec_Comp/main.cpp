
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 10, 2017, 12:19 PM
 * Purpose: Problem 3
 * 
Create a function that fills one vector with even
random 2 digit numbers and another vector with
odd random numbers.  Prompt the user for the size
of these vectors.  Both will be the same size.
Output the results in 2 column format.
Even   Odd  

These should be done
with 2 functions, fillVec and prntVec.

Then do the same with a 2-Dim array where the
first column has even numbers and the second
column has the odd numbers.

These should be done
with 2 functions, fillAry and prntAry.
Fill the 2-Dim array with the odd and even vectors
previously filled.

I want to see how you pass the arrays and vectors
in and out of the functions.

*/

//System Libraries
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const int ARYCOLS=2;  //number of columns in 2D array

//Function Prototypes
void fillVec (vector<int>&, vector<int>&, int);  //fill vectors 
void prntVec (vector<int>, vector<int>, int);   //Print vectors
void fillAry (int [][ARYCOLS], int, vector<int>, vector<int>);  //fill array (with vector data)
void prntAry (int [][ARYCOLS], int); //print array

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=0; //will be set to size of vectors
    const int arows=250000;  //setting max size of array rows
    vector <int> vecOne; //initialize vector 1
    vector <int> vecTwo; //initialize vector 2
    int array2D[arows][ARYCOLS]={};
    //Input Values
    cout<<"How large should the vectors be?"<<endl;
    cin>>size; //How many numbers will the vectors hold?

    
    //Process by mapping inputs to outputs
    fillVec (vecOne, vecTwo, size);  //Fill the vectors with even and odd numbers
    prntVec (vecOne, vecTwo, size);  //print the vectors
    
    fillAry (array2D, size, vecOne, vecTwo);  //Fill the array with the data from each vector
    prntAry (array2D, size);  //Print the array
            
    //Output values
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Fill Vectors ********************************
//Description: Fills two vectors, one with even numbers and other with odd
//
//Inputs: Vector one, vector two, size of vectors
//     
//Outputs: none
//******************************************************************************
void fillVec (vector<int>& vOne, vector<int>& vTwo, int size){
    cout<<"Filling the Vectors"<<endl;
    srand (static_cast<unsigned int>(time(0))); //Set random seed
    int even=1,odd=0,temp=0;
    for (int i=0;i<size;i++){ //fill the vector up to the size entered above
        temp=rand()%89+10; //random number from 10-99
        if (temp%2==0) { //if random is even
            even=temp; //set even to temp 
            odd=temp+1; //set odd to temp + 1
        }
        else {
            even=temp-1; //set even to temp - 1
            odd=temp;  //set odd to temp
        }
        vOne.push_back(even);  //set vector One element to even
        vTwo.push_back(odd);  //set vector two element to odd
    }
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Print Vectors ********************************
//Description: Prints the array data to screen and to file
//
//Inputs: Vector one, Vector two, size of vectors
//     
//Outputs: none
//******************************************************************************
void prntVec (vector<int> vOne, vector<int> vTwo, int size){
    cout<<"Printing the Vectors"<<endl;
    cout<<"Even  Odd"<<endl;
    for (int i=0;i<size;i++){  //for loop to print the vectors up to the size entered
        cout<<vOne[i]<<"    "<<vTwo[i]<<endl;
    }
    cout<<"Leaving Vector Print Function"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Fill 2D array ********************************
//Description: Fills 2D array with the values of the vectors
//
//Inputs: array, number of rows, vector one, vector two
//     
//Outputs: none
//******************************************************************************
void fillAry (int a[][ARYCOLS],int rows,vector<int> vOne, vector<int> vTwo){
    cout<<"Filling the 2D Array"<<endl;
    for (int i=0;i<rows;i++) {  //filling the array with the data from the vectors
        for (int j=0;j<ARYCOLS;j++){
            if (j==0)a[i][j]=vOne[i];  //column 1 filled with data from vector One
            if (j==1)a[i][j]=vTwo[i];  //Column 2 filled with data from vector Two
        }
    }
    cout<<endl;
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
void prntAry (int a[][ARYCOLS],int rows){
    cout<<"Printing the 2D Array"<<endl;
    cout<<"Even  Odd"<<endl;
    for (int i=0;i<rows;i++){  //Print the array up to the size entered abobe
        for (int j=0;j<ARYCOLS;j++){
            cout<<a[i][j]<<"    ";
        }
        cout<<endl;
    }
    cout<<endl;
}