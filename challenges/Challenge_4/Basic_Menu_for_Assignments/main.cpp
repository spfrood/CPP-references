/* 
  File:   main.cpp
  Author: Dr. Scott Parker
  Created on June 5, 2017, 12:28 PM
  Purpose:  CSC17A Final Exam Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "Prob3TableInherited.h"
#include "SavingsAccount.h"
#include "Employee.h"
#include "colors.h"


//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another and for
//2d array columns

//Function Prototypes 
//Delete void functions or add them as needed based on homework problems
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list <non-numeric data will be ignored>"<<endl;
        cout<<"Type 1 for Problem 1: Random Sequence"<<endl;
        cout<<"Type 2 for Problem 2: Nasty Sorting Problem"<<endl;
        cout<<"Type 3 for Problem 3: Spreadsheet"<<endl;
        cout<<"Type 4 for Problem 4: Savings Account"<<endl;
        cout<<"Type 5 for Problem 5: Employee Class"<<endl;
        cout<<"Type 6 for Problem 6: Conversions"<<endl;
        cout<<"Enter 0 (zero) or a number not listed to exit."<<endl;
        cin>>choice;
        while (cin.fail()) //Loop to validate input
            {
            cout<<"INPUT INVALID! "<<endl;
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter a valid choice!:"<<endl;
            cin>>choice;
            }

        //Switch to determine the Problem
        switch(choice){
            case 6:{prob6();break;}
            case 5:{prob5();break;}
            case 4:{prob4();break;}
            case 3:{prob3();break;}
            case 2:{prob2();break;}
            case 1:{prob1();break;}
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>=1&&choice<=6);
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************ Function for Problem 10  ****************************
//Description: Program for Book, Edition, Chapter, Question, Short Description
//
//Inputs: (what inputs passed to function)
//     
//Outputs:  (what is the output of this function)
//
//******************************************************************************
void prob6(){
    cout<<endl;
    cout<<"Entering Problem 6"<<endl;
    cout<<"Conversions:"<<endl;
    cout<<"A: 3.75 Base 10 convert to Base 2, 8, 16"<<endl;
    cout<<"        Base 2:   11.11"<<endl;
    cout<<"        Base 8:   3.6"<<endl;
    cout<<"       Base 16:   3C"<<endl;
    cout<<"     Hex Float:   78000002"<<endl;
    cout<<"    IEEE Float:   40700000"<<endl;
    cout<<endl;
    cout<<"B: 0.7 Base 10 convert to Base 2, 8, 16"<<endl;
    cout<<"        Base 2:   0.10"<<UNDERLINE<<"1100"<<RESET<<endl;
    cout<<"        Base 8:   0.5"<<UNDERLINE<<"4631"<<RESET<<endl;
    cout<<"       Base 16:   0.B"<<UNDERLINE<<"3"<<RESET<<endl;
    cout<<"     Hex Float:   59999900"<<endl;
    cout<<"    IEEE Float:   3F333333"<<endl;
    cout<<endl;
    cout<<"B: 89.9 Base 10 convert to Base 2, 8, 16"<<endl;
    cout<<"        Base 2:   1011001.1"<<UNDERLINE<<"1100"<<RESET<<endl;
    cout<<"        Base 8:   131.71"<<UNDERLINE<<"4631"<<RESET<<endl;
    cout<<"       Base 16:   59.E"<<UNDERLINE<<"6"<<RESET<<endl;
    cout<<"     Hex Float:   59E66607"<<endl;
    cout<<"    IEEE Float:   42B3CCCC"<<endl;
    cout<<endl;
    cout<<"Question 6, Section 3 and Section 4 not completed."<<endl;
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
    
}

void prob5(){
    cout<<endl;
    cout<<"Entering Problem 5!"<<endl;
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
    Mark.toString();
    
    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
    Mary.toString();
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
}

void prob4(){
    cout<<endl;
    srand(static_cast<unsigned int>(time(0)));
    
    SavingsAccount mine(-300);
    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
    
}

void prob3(){
    cout<<endl;
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
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
    
}

void prob2(){
    cout<<endl;
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
    //Exit stage right! - This is the 'return 0' call
}

void prob1(){
    srand(static_cast<unsigned int>(time(0)));
    cout<<endl;
    //Declare Variables
    char n=5;
    char rndseq[]={17,33,56,79,126};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    
    //Input Values
    
    //Process by mapping inputs to outputs
    for(int i=1;i<=ntimes;i++)
    {
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    //Output values
    for(int i=0;i<n;i++)
    {
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    cout<<endl;
    //Clean up memory
    delete [] x;
    delete [] y;
    //Exit stage right! - This is the 'return 0' call
}
