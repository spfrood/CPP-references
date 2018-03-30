
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
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const int COLS=15;  //number of columns for array

//Function Prototypes
void prChAry(char *, int); //Function to print 2D array
void compRow(char *, int, int); //Function to sort 2D array
void swapRow(char *, int); //Swap row with one higher up

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //instantiate and/or open files

    //Declare Variables
        cout<<"Creating/writing text file for sort..."<<endl;
    fstream fil;
    fil.open ("input.dat",ios::out);
    fil<<"Lbekoeddhoffbmg"<<endl;
    fil<<"Lkcmggjcdhhglif"<<endl;
    fil<<"Cgldjhcekjigcdd"<<endl;
    fil<<"Cgldjhcekjigcdm"<<endl;
    fil<<"Bffmdbkcenlafjk"<<endl;
    fil<<"Fggdijijegfblln"<<endl;
    fil<<"Jjlncnimjldfedj"<<endl;
    fil<<"Amliglfohajcdmn"<<endl;
    fil<<"Balgfcaelhfkgeb"<<endl;
    fil<<"Kmlhmhcddfoeilc"<<endl;
    fil.close();
    cout<<"File created and closed."<<endl;
    
    const int ROWS=10;  //Number of rows for array
      
    //Input Values
    ifstream in;
    in.open("input.dat"); //opening data file
    char *ch2=new char[ROWS*COLS];  //10x15 character array
    
    //Input Values
    for (int i=0;i<ROWS*COLS;i++){  //inputting data from file
        in>>ch2[i];
    }
    in.close();  //closing data file
    
//    ifstream infile;
//    infile.open("input.dat",ios::in);
//    char *ch2=new char[10*16];
//    char *ch2p=ch2;
//    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
//    infile.close();
//    cout<<endl;
    
    //Process by mapping inputs to outputs
    cout<<"Printing array"<<endl;
    prChAry(ch2,ROWS); //Printing current array contents
    compRow(ch2, ROWS, 7); //Sorting array descending alpha order
    cout<<endl;
    //Output values
    prChAry(ch2,ROWS); //printing sorted array
    
    
    delete [] ch2;
    //Exit stage right! - This is the 'return 0' call
    cout<<"Everything Done! Exiting!"<<endl;
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
void prChAry(char *a,int row){
    cout<<"Print 1"<<endl;
    for (int i=0;i<row*COLS;i++){  //Row data for array
            if (i>0 && i%15==0) {
                cout<<endl;
            }
            cout<<a[i];
    }
    cout<<endl;
    cout<<"Print 2"<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            cout<<a[i*COLS+j];
        }
        cout<<endl;
    }
    cout<<"End Print"<<endl;
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
void swapRow(char *a, int now){  //swap row with row below it
    char temp='\0';  //set initial temp value to one not used in the alpha array
    for (int j=0;j<COLS;j++){ //exchange elements in rows one at a time
        temp=a[now+j];
        a[now+j]=a[now+COLS+j];
        a[now+COLS+j]=temp;
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
void compRow(char *a,int row, int sortBy){
    bool swap;
    int h=0;
    if (sortBy>=COLS) {
        h=(COLS-1);
    } else if (sortBy<0) {
        h=0;
    } else {
        h=sortBy;
    }
    do{
        swap=false;
        for(int i=0;i<row*COLS-1;i+=COLS){
            int f=0;
            int k=i+h;
            cout<<"Setting sort-by column"<<endl;
            if(a[k]<a[k+COLS]){ //compare 1st element and swap row if true
                cout<<"swapping row because "<<a[k]<<" < "<<a[k+COLS]<<endl;
                swapRow(a,i);
                swap=true; //set bool to true to initiate another run-through
            } else if (a[k]==a[k+COLS]){ //if first element is same in both rows
                do{ //increment to next element until elements are not same
                    f++;
                    cout<<"adding to F because "<<a[k]<<" == "<<a[k+COLS]<<endl;
                    if ((k+f)%(COLS)==0) {
                        cout<<"Going back, last element in row!"<<endl;
                        f-=COLS;
                    }
                } while (a[k+f]==a[k+COLS+f]);
                
                if (a[k+f]<a[k+COLS+f]){ //if current row less than next swap row
                    cout<<"swapping row because "<<a[k+f]<<" < "<<a[k+COLS+f]<<endl;
                    swapRow(a,i);
                    swap=true; //set bool to true to initiate another run-through
                }
            }
        }
    }while(swap);  
}
