
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 25, 2017, 3:45 PM
 * Purpose: 4. Weather Statistics
Write a program that uses a structure to store the following weather data for a 
particular month:
Total Rainfall
High Temperature 
Low Temperature 
Average Temperature
The program should have an array of 12 structures to hold weather data for an 
entire year. When the program runs, it should ask the user to enter data for each 
month. (The average temperature should be calculated.) Once the data are entered 
for all the months, the program should calculate and display the average monthly 
rainfall, the total rainfall for the year, the highest and lowest temperatures 
for the year (and the months they occurred in), and the average of all the monthly 
average temperatures.
Input Validation: Only accept temperatures within the range between –100 and 
+140 degrees Fahrenheit. 
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries
#include "TempDat.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
float avTmp09(TempDat [], int); //function to find the annual average temperature
float totRn10(TempDat [], int); //function to find the total rainfall for the year
void gtTmp11(TempDat [], int); //function to fill data in array
void rnTmp12(TempDat [], int); //function to fill fields randomly
TempDat gtRe13(TempDat [], int, TempDat, int &, int &, int &, int &); //function to get the high/low data
string dMnth14(int); //function to output the month based on an integer input from 0-11 (Jan to Dec)
void dsDat15(TempDat [], int); //Function to print the data values in an array of TempDat

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0))); //Set random seed
    
    //Declare Variables
    const int SIZE=12; //size of array (12 months)
    TempDat months[SIZE]; //create array of the structures
    TempDat finals={0,-100,140,0}; //structure to hold highs and lows
    int hiMnth=0, lowMnth=0, rfMnth=0, atMnth=0; //variables to hold the months for highs/lows
    char chooser='\0'; //variable to choose option to randomize everything
    
    //Input Values
    cout<<"Randomize data entry? (Y/y to randomize)"<<endl;
    cin>>chooser; //Enter all data randomly?
    if (chooser=='y'||chooser=='Y'){
        rnTmp12(months, SIZE); //choice was entered to Randomize all data - call randomize function
    } else gtTmp11(months, SIZE); //choice entered to get all data manually - call input function
    
    //Process by mapping inputs to outputs
    finals=gtRe13(months, SIZE, finals, hiMnth, lowMnth, rfMnth, atMnth); //find the highs, lows, etc, by calling function
    
    //Output values
    dsDat15(months, SIZE);
    cout<<setprecision(2)<<fixed;
    cout<<"High, low, and averages were: "<<endl; 
    cout<<"Highest Temp: "<<finals.hiTemp<<" occured in "<<dMnth14(hiMnth)<<endl; //output month and highest temp
    cout<<"Lowest Temp:  "<<finals.lowTemp<<" occured in "<<dMnth14(lowMnth)<<endl; //output month and lowest temp
    cout<<"Highest Avg Temp: "<<finals.avgTemp<<" occured in "<<dMnth14(atMnth)<<endl; //output month and highest avg temp
    cout<<"The annual average temp was: "<<avTmp09(months, SIZE)<<endl; //output average monthly temp
    cout<<"Most Rainfall: "<<finals.totRain<<"inches occured in "<<dMnth14(rfMnth)<<endl; //output month and highest rainfall
    cout<<"The average rainfall was: "<<totRn10(months, SIZE)<<endl; //output average monthly rainfall
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to find the annual average temperature
float avTmp09(TempDat a[], int size){ 
    float temp=0;
    for (int i=0;i<size;i++){ //for loop to total avg temps
        temp+=a[i].avgTemp; 
    }
    return (temp/12.0f); //return the average temp
} 

//function to find the total rainfall for the year
float totRn10(TempDat a[], int size){
    float temp=0;
    for (int i=0;i<size;i++){ //for loop to total rainfall
        temp+=a[i].totRain;
    }
    return temp; //return total rainfall
}

//Function to print the data values in an array of TempDat
void dsDat15(TempDat a[], int size){
    cout<<setprecision(2)<<fixed; //Formatting and headers output
    cout<<setw(15)<<left<<"Month"<<setw(12)<<right<<"High Temp"<<setw(12)<<right<<"Low Temp"
            <<setw(12)<<right<<"Rain Inches"<<setw(12)<<right<<"Avg Temp"<<endl;
    for (int i=0;i<size;i++){ //for loop to output the data from each month
        cout<<setw(15)<<left<<dMnth14(i)<<setw(12)<<right<<a[i].hiTemp<<setw(12)<<right<<a[i].lowTemp
            <<setw(12)<<right<<a[i].totRain<<setw(12)<<right<<a[i].avgTemp<<endl;
    }
}

//function to get the high/low data
TempDat gtRe13(TempDat a[], int size, TempDat b, int &htMnth, int &ltMnth, int &rfMnth, int &atMnth){
    for (int i=0;i<size;i++){ //for loop to find highs and lows
        if (a[i].hiTemp > b.hiTemp){ //find the highest temperature so far
            b.hiTemp=a[i].hiTemp;  //set current highest temperature
            htMnth=i; //set current month with highest temp
        }
        if (a[i].lowTemp < b.lowTemp){ //find the lowest temperature so far
            b.lowTemp=a[i].lowTemp; //set current lowest temp 
            ltMnth=i; //set month with current lowest temp
        }
        if (a[i].totRain > b.totRain){ //find month with most rain
            b.totRain=a[i].totRain; //set most rain if this month has the most
            rfMnth=i; //set month to month with most rain
        }
        if (a[i].avgTemp > b.avgTemp){ //find the highest average temp
            b.avgTemp=a[i].avgTemp; //set avg high temp if higher than current
            atMnth=i; //set month if highest avg temp so far
        }
    }
    return b;
}

//function to fill fields randomly
void rnTmp12(TempDat a[], int size){
    for (int i=0;i<size;i++){ //for loop to fill data values
        a[i].totRain=(static_cast<float>(rand()%120)/10); //generate random total rain value
        int temp1=rand()%240-100; //generate random temp 1
        int temp2=rand()%240-100; //generate random temp 2
        if (temp1>temp2){ //set high temp to temp 1 if greater than temp 2
            a[i].hiTemp=temp1;
            a[i].lowTemp=temp2;
        } else { //set high temp to temp 2 if greater than temp 1
            a[i].hiTemp=temp2;
            a[i].lowTemp=temp1;
        }
        a[i].avgTemp=(static_cast<float>(temp1+temp2)/2); //calculate average temp
    }
}

//function to fill data in array
void gtTmp11(TempDat a[], int size){
    for (int i=0;i<size;i++){ //for loop to input all data
        cout<<"Enter the rainfall (in inches) for "<< dMnth14(i) <<":"<<endl;
        cin>>a[i].totRain; //input the total rain data
        while (cin.fail()){ //validate the input
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Try Again! Enter the inches of rain!"<<endl;
            cin>>a[i].totRain;
        }
        cout<<"Enter highest temp for "<<dMnth14(i)<<":"<<endl; //output current month and data to be input
        cin>>a[i].hiTemp; //input highest temp for current month
        cout<<"Enter lowest temp for "<<dMnth14(i)<<":"<<endl; //output current month and data to be input
        cin>>a[i].lowTemp; //input lowest temp for current month
        bool range=true;
        bool upDown=true;
        if ((a[i].hiTemp)>(a[i].lowTemp)) upDown=false; //check that high temp greater than low temp. bool false if true
        else upDown=true; //bool true if out of order
        if ((a[i].hiTemp <= 140)&&(a[i].hiTemp >= -100) && (a[i].lowTemp <= 140)  //check temp ranges
                && (a[i].lowTemp >= -100)) range=false; //set bool to false if temp in range
        else upDown=true; //bool true if temp out of range
        while (cin.fail()||upDown||range){ //loop to repeat until valid input entered
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Try again. Low must be below high, must be a number!"<<endl; 
            cout<<"Enter highest temp for "<<dMnth14(i)<<":"<<endl;
            cin>>a[i].hiTemp; //re-enter high temp for current month
            cout<<"Enter lowest temp for "<<dMnth14(i)<<":"<<endl;
            cin>>a[i].lowTemp; //re-enter high temp for current month
            if ((a[i].hiTemp)>(a[i].lowTemp)) upDown=false; //check that high temp greater than low temp bool false if true
            else upDown=true; //bool true if temps out of order
            if ((a[i].hiTemp <= 140)&&(a[i].hiTemp >= -100) && (a[i].lowTemp <= 140)  //check temp range
                    && (a[i].lowTemp >= -100)) range=false; //bool false if temp within range
            else range=true; //bool true if temp out of range
        }
        a[i].avgTemp=(static_cast<float>(a[i].lowTemp + a[i].hiTemp)/2); //set value for average temp of month
    }
} 

//function to output the month based on an integer input from 0-11 (Jan to Dec)
string dMnth14(int month){
    string fluff="";
    switch(month){ //switch statement to output name of month instead of an integer
        case 11:{fluff= "December";break;} //11 = december
        case 10:{fluff= "November";break;} //10 = november
        case 9:{fluff= "October";break;} //9 = october
        case 8:{fluff= "September";break;} //8 = september
        case 7:{fluff= "August";break;} //7 = august
        case 6:{fluff= "July";break;} //6 = july
        case 5:{fluff= "June";break;} //5 = june
        case 4:{fluff= "May";break;} //4 = may
        case 3:{fluff= "April";break;} //3 = april
        case 2:{fluff= "March";break;} //2 = march
        case 1:{fluff= "February";break;} //1 = february
        default:
            fluff= "January"; //0 (default) = january
    }
    return fluff;
}