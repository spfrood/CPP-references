
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 27, 2017, 12:19 PM
 * Purpose: 6. Rain or Shine
 * An amateur meteorologist wants to keep track of weather conditions during the
 * past year’s three-month summer season and has designated each day as either 
 * rainy (‘R’), cloudy (‘C’), or sunny (‘S’). Write a program that stores this 
 * information in a 3 × 30 array of characters, where the row indicates the 
 * month (0 = June, 1 = July, 2 = August) and the column indicates the day of 
 * the month. Note that data are not being collected for the 31st of any month. 
 * The program should begin by reading the weather data in from a file. Then it 
 * should create a report that displays, for each month and for the whole three-
 * month period, how many days were rainy, how many were cloudy, and how many 
 * were sunny. It should also report which of the three months had the largest 
 * number of rainy days. Data for the program can be found in the 
 * RainOrShine.txt file.
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const int COLS=30; //Number of columns in a 2d array

//Function Prototypes
void fillAry(char [][COLS], int);  //Fill array with random data
void prntAry(char [][COLS], int);  //Print the contents of array to screen
void compAry(char [][COLS], int);  //Compare array data

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Instantiate and Open files
    ifstream in;  //assigns file input operator
    ofstream out; //assigns file output operator

    //Declare Variables
    const int ROWS=3;  //Number of rows for array
    char monData [ROWS][COLS]={'\n'};  //3x30 character array
    char yesNo='N';
    
    //Input Values
    in.open("RainOrShine.txt"); //opening data file
    for (int i=0;i<ROWS;i++){  //inputting data from file
        for (int j=0;j<COLS;j++){
            in>>monData[i][j];
        }
    }
    in.close();  //closing file
    
    //Input Values
    cout<<"Would you like to generate random data before proceeding?"<<endl;
    cin>>yesNo; //Fill array with random data?
    if (yesNo=='y'||yesNo=='Y'){
        fillAry(monData, ROWS);
    } else cout<<"Not generating random data."<<endl;
    cin.ignore(256, '\n'); //ignore contents of buffer in case more than one char entered
    cout<<"Printing array contents: "<<endl;
    prntAry(monData, ROWS);
    
    //Process by mapping inputs to outputs
    compAry(monData, ROWS);
    
    //Output values
    out.open("RainOrShine.txt"); //Save most recently used data to file
    for (int i=0;i<ROWS;i++){  //to output data to file
        for (int j=0;j<COLS;j++){
            out<<monData[i][j]<<" ";
        }
    }
    out.close();  //closing file
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//Function to compare the array data and output statistics
void compAry(char months[][COLS], int rows){
    int junS=0, julS=0, augS=0; //Sunny day info
    int junC=0, julC=0, augC=0; //Cloudy day info
    int junR=0, julR=0, augR=0; //Rainy day info
    
    for (int i=0;i<rows;i++){  //to output data to file
        for (int j=0;j<COLS;j++){
            if (i==0){ //Get statistical info for June
                if (months[i][j]=='C'){
                    junC++;
                }
                else if(months[i][j]=='R'){
                    junR++;
                }
                else junS++;
            }else if (i==1){ //Get statistical info for July
                if (months[i][j]=='C'){
                    julC++;
                }
                else if(months[i][j]=='R'){
                    julR++;
                }
                else julS++;
            }else { //Get statistical info for August
                if (months[i][j]=='C'){
                    augC++;
                }
                else if(months[i][j]=='R'){
                    augR++;
                }
                else augS++;
            }
        }
    }
    cout<<"                June    July    August  "<<endl;
    cout<<setw(16)<<left<<"Rainy Days"<<setw(8)<<left<<junR<<setw(8)<<left<<julR<<setw(8)<<left<<augR<<endl; //Total rainy days for each month
    cout<<setw(16)<<left<<"Cloudy Days"<<setw(8)<<left<<junC<<setw(8)<<left<<julC<<setw(8)<<left<<augC<<endl; //Total cloudy days for each month
    cout<<setw(16)<<left<<"Sunny Days"<<setw(8)<<left<<junS<<setw(8)<<left<<julS<<setw(8)<<left<<augS<<endl;  //Total sunny days for each month
    cout<<"Total Rainy Days:  "<<junR+julR+augR<<endl; //Overall rainy days
    cout<<"Total Cloudy Days: "<<junC+julC+augC<<endl; //overall cloudy days
    cout<<"Total Sunny Days:  "<<junS+julS+augS<<endl; //overall sunny days
    
    if (junR>julR&&junR>augR){ 
        cout<<"June "; //output June if most rainy days in June
    } else if (julR>junR&&julR>augR){
        cout<<"July "; //output July if most rainy days in July
    } else cout<<"August ";  //else most rainy days in August
    cout<<"had the most rainy days, not considering ties."<<endl;
}

//Function to print the array contents
void prntAry(char months[][COLS], int rows){
    cout<<"Day    ";  
    for (int i=0;i<COLS;i++){  //Output the day of the month
        cout<<setw(3)<<left<<i+1;
    }
    cout<<endl;
    for (int i=0;i<rows;i++){  //output the data for that day
        i==0?cout<<"June  ":i==1?cout<<"July  ":cout<<"August";
        for (int j=0;j<COLS;j++){
            cout<<setw(2)<<right<<months[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Function to fill the array with random statistics
void fillAry(char months[][COLS], int rows){
    srand(static_cast<unsigned int>(time(0)));
    int temp=0;
    char rcs='\n';
    for (int i=0;i<rows;i++){  //Run once for each month
        for (int j=0;j<COLS;j++){ //fill data for each day
            temp = rand()%3;
            if (temp==0){
                rcs='R';
            } else if (temp==1){
                rcs='C';
            } else rcs='S';
            months[i][j]=rcs;
        }
    }
}