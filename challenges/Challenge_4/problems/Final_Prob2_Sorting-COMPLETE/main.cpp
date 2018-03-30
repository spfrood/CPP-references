
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on June 5, 2017, 9:56 AM
 * Purpose: Problem #2  (All Kinds of Sorting)
Sort a single column array and/or sort a 2 dimensional array 
of characters given any column.  Here is what I used as my
template specification.

//This class sorts arrays either ascending or descending
template<class T>
class Prob2Sort
{
	private:
		int *index;                                 //Index that is utilized in the sort
	public:
		Prob2Sort(){index=NULL;};                   //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		T * sortArray(const T*,int,bool);           //Sorts a single column array
		T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 

Driver program for the above class.  Create your own file to read.

	cout<<"The start of Problem 2, the sorting problem"<<endl;
	Prob2Sort<char> rc;
	bool ascending=true;
	ifstream infile;
	infile.open("Problem2.txt",ios::in);
	char *ch2=new char[10*16];
	char *ch2p=ch2;
	while(infile.get(*ch2)){cout<<*ch2;ch2++;}
	infile.close();
	cout<<endl;
	cout<<"Sorting on which column"<<endl;
	int column;
	cin>>column;
	char *zc=rc.sortArray(ch2p,10,16,column,ascending);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<16;j++)
		{
			cout<<zc[i*16+j];
		}
	}
	delete []zc;
	cout<<endl;

The output from this problem.

The start of Problem 2, the sorting problem
Lbekoeddhoffbmg
Lkcmggjcdhhglif
Cgldjhcekjigcdd
Cgldjhcekjigcdm
Bffmdbkcenlafjk
Fggdijijegfblln
Jjlncnimjldfedj
Amliglfohajcdmn
Balgfcaelhfkgeb
Kmlhmhcddfoeilc

Sorting on column 15
Cgldjhcekjigcdm
Fggdijijegfblln
Amliglfohajcdmn
Bffmdbkcenlafjk
Jjlncnimjldfedj
Lbekoeddhoffbmg
Lkcmggjcdhhglif
Cgldjhcekjigcdd
Kmlhmhcddfoeilc
Balgfcaelhfkgeb


 
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Prob2Sort.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
//or columns for 2D arrays

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    
    //Declare Variables
    cout<<"Creating/writing text file for sort..."<<endl;
    fstream fil;
    fil.open ("Problem2.txt",ios::out); //Open file and write txt values to file
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
    cout<<"File created and closed."<<endl<<endl;
    
    //Input Values
	cout<<"The start of Problem 2, the sorting problem"<<endl;
	Prob2Sort<char> rc;
	bool ascending=true;
	ifstream infile;
	infile.open("Problem2.txt",ios::in);
	char *ch2=new char[10*16];
	char *ch2p=ch2;
	while(infile.get(*ch2)){cout<<*ch2;ch2++;}
	infile.close();
	cout<<endl;
	cout<<"Sorting on which column"<<endl;
	int column;
	cin>>column;
	char *zc=rc.sortArray(ch2p,10,16,column,ascending);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<16;j++)
		{
			cout<<zc[i*16+j];
		}
	}
	delete []zc;
	cout<<endl;
    
    //Output values
    
    //Clean up memory
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

