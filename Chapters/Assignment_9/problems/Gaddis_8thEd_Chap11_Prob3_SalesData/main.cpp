
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 25, 2017, 2:30 PM
 * Purpose: 3. Corporate Sales Data
Write a program that uses a structure to store the following data on a company 
division:
Division Name (such as East, West, North, or South) 
First-Quarter Sales
Second-Quarter Sales
Third-Quarter Sales
Fourth-Quarter Sales 
Total Annual Sales 
Average Quarterly Sales
The program should use four variables of this structure. Each variable should 
represent one of the following corporate divisions: East, West, North, and South. 
The user should be asked for the four quarters’ sales figures for each division. 
Each division’s total and average sales should be calculated and stored in the 
appropriate member of each structure variable. These figures should then be 
displayed on the screen.
Input Validation: Do not accept negative numbers for any sales figures.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
#include "DivData.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void entDa07(DivData &); //function to input the sales data for the DivData structure
void shDiv08(DivData); //function to output the values held in the structure

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    DivData east = {"East Division"}; //East Division data structure
    DivData west = {"West Division"}; //West Division data structure
    DivData north = {"North Division"}; //North Division data structure
    DivData south = {"South Division"}; //South Division data structure
    
    //Input Values
    cout<<"Enter the sales data as prompted"<<endl;
    
    
    //Process by mapping inputs to outputs
    entDa07(east); //Enter data for east division
    entDa07(west); //Enter data for west division
    entDa07(north); //Enter data for north division
    entDa07(south); //Enter data for south division
    
    //Output values
    shDiv08(east); //display data for east division
    shDiv08(west); //display data for west division
    shDiv08(north); //display data for north division
    shDiv08(south); //display data for south division
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to output the values held in the structure
void shDiv08(DivData div){
    cout<<setw(28)<<left;
    cout<<"Sales statistics for "<<div.divName<<endl; //Output the division name
    cout<<setw(28)<<left;
    cout<<"First quarter sales: "<<"$"<<div.qOneSal<<endl; //output quarter one sales
    cout<<setw(28)<<left;
    cout<<"Second quarter sales: "<<"$"<<div.qTwoSal<<endl; //output quarter 2 sales
    cout<<setw(28)<<left;
    cout<<"Third quarter sales: "<<"$"<<div.qThrSal<<endl; //output quarter 3 sales
    cout<<setw(28)<<left;
    cout<<"Fourth quarter sales: "<<"$"<<div.qFouSal<<endl; //output quarter 4 sales
    cout<<setw(28)<<left;
    cout<<"Total annual sales: "<<"$"<<div.totSale<<endl; //output total sales
    cout<<setprecision(2)<<showpoint<<fixed<<setw(28)<<left;
    cout<<"Average quarterly sales: "<<"$"<<div.avgSale<<endl; //output average quarterly sales
    cout<<endl;
}

//function to input the sales data for the DivData structure
void entDa07(DivData &div) {
    cout<<"Enter the quarterly sales for "<<div.divName<<"."<<endl; //output the division requesting data
    cout<<"First quarter sales: $";
    cin>>div.qOneSal; //input q1 sales data
    while (cin.fail()||(div.qOneSal<0)){ //validate data type and range - reinput if invalid
        cin.clear(); //clear input flags
        cin.ignore(256, '\n'); //ignore (clear) the buffer
        cout<<"Error! Must enter a non-negative integer!"<<endl; //output error message 
        cout<<"Enter first quarter sales: $"; //output message 
        cin>>div.qOneSal; //re-enter data
    }
    cout<<"Second Quarter sales: $";
    cin>>div.qTwoSal; //enter q2 sales 
    while (cin.fail()||(div.qTwoSal<0)){ //validate data and reenter if in error
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Error! Must enter a non-negative integer!"<<endl;
        cout<<"Enter second quarter sales: $";
        cin>>div.qTwoSal; //re-enter 2nd quarter data
    }
    cout<<"Third Quarter sales: $";
    cin>>div.qThrSal; //enter q3 sales data
    while (cin.fail()||(div.qThrSal<0)){ //validate data and re-enter if invalid
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Error! Must enter a non-negative integer!"<<endl;
        cout<<"Enter third quarter sales: $";
        cin>>div.qThrSal; //re-enter q3 data
    }
    cout<<"Fourth Quarter sales: $";
    cin>>div.qFouSal; //enter q4 sales data
    while (cin.fail()||(div.qFouSal<0)){ //validate data and re-enter if invalid
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Error! Must enter a non-negative integer!"<<endl;
        cout<<"Enter fourth quarter sales: $";
        cin>>div.qFouSal; //re-enter q4 sales data
    }
    div.totSale=div.qFouSal+div.qOneSal+div.qThrSal+div.qTwoSal; //calculate total sales
    div.avgSale=static_cast<float>(div.totSale)/4; //calculate average sales
    cout<<endl;
}