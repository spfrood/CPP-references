
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on June 5, 2017, 9:56 AM
 * Purpose: Problem #3  (Spreadsheet Stuff)
Class Specifications

template<class T>
class Prob3Table
{
protected:
    int rows;                                 //Number of rows in the table
    int cols;                                 //Number of cols in the table
    T *rowSum;                                //RowSum array
    T *colSum;                                //ColSum array
    T *table;                                 //Table array
    T grandTotal;                             //Grand total
    void calcTable(void);                     //Calculate all the sums
public:
    Prob3Table(char *,int,int);               //Constructor then Destructor
    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
    const T *getTable(void){return table;};
    const T *getRowSum(void){return rowSum;};
    const T *getColSum(void){return colSum;};
    T getGrandTotal(void){return grandTotal;};
};

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
    protected:
    T *augTable;                                  //Augmented Table with sums
public:
    Prob3TableInherited(char *,int,int);          //Constructor
    ~Prob3TableInherited(){delete [] augTable;};  //Destructor
    const T *getAugTable(void){return augTable;}; 
};

Driver code
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }


Example Input Table
   100   101   102   103   104   105
   106   107   108   109   110   111
   112   113   114   115   116   117
   118   119   120   121   122   123
   124   125   126   127   128   128
Example Output Table with rows summed,
columns summed and the grand total printed.
   100   101   102   103   104   105   615
   106   107   108   109   110   111   651
   112   113   114   115   116   117   687
   118   119   120   121   122   123   723
   124   125   126   127   128   128   758
   560   565   570   575   580   584  3434

 */

//System Libraries
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//User Libraries
#include "Prob3TableInherited.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
//or columns for 2D arrays

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    
    //Declare Variables
    
    //Input Values
    cout<<"Creating/writing text table file..."<<endl;
    fstream fil;
    fil.open ("Problem3.txt",ios::out); //Open file and write txt values to file
    fil<<"100   101   102   103   104   105"<<endl;
    fil<<"106   107   108   109   110   111"<<endl;
    fil<<"112   113   114   115   116   117"<<endl;
    fil<<"118   119   120   121   122   123"<<endl;
    fil<<"124   125   126   127   128   128"<<endl;

    fil.close();
    cout<<"File created and closed."<<endl<<endl;
    //Process by mapping inputs to outputs
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    
    //Output values
    
    //Clean up memory
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

