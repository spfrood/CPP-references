
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 24, 2017, 10:56 AM
 * Purpose: Convert to Roman Numerals 
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const int THOSNDS=1000; //conversion to 1000
const int HUNDRDS=100;  //conversion to  100
const int TENS=10;      //Conversion to   10 

//Function Prototypes
string cnvrtRN(unsigned short);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short year;
    
    //Input Values
    cout<<"This program converts years to Roman Numerals"<<endl;
    cout<<"Input a year from 1000AD to 3000AD"<<endl;
    cin>>year;
    
    //Process by mapping inputs to outputs
    string dummy=cnvrtRN(year);
    
    //Output values 

    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************  Roman Numeral Conversion ***************************
//Description:  Convert numbers from 1000 to 3000
//Inputs:  
//      year from 1000 to 3000
//Outputs: 
//      romanYr -> Output to Screen
//******************************************************************************
string cnvrtRN(unsigned short year){
    //Declare Variables
    char n1000,n100,n10,n1; //The number of powers of 10
    string roman = "";
    
    //Parsing year information 
    n1000 = (year-year%THOSNDS)/THOSNDS; //Determines how many thousands
    year = (year-n1000*THOSNDS); //Will return the year without 1000's
    n100 = (year-year%HUNDRDS)/HUNDRDS; //Determines how many hundreds
    year = (year-n100*HUNDRDS); //Will return the year without 100's
    n10 = (year-year%TENS)/TENS; //Determines how many tens
    n1 = (year-n10*TENS); //Will return the year without 10's
    
    //Fill the string with M's
    switch (n1000){
        case 3:roman+='M';
        case 2:roman+='M';
        case 1:roman+='M';break;
        case 0:break;
        default:cout<<"Bad Year"<<endl;
    }
    
    //Fill the string with C's
    switch (n100){
        case 3:roman+='M';
        case 2:roman+='M';
        case 1:roman+='M';break;
        case 0:break;
        default:cout<<"Bad Year"<<endl;
    }    
    //Fill the string with X's
    switch (n10){
        case 3:roman+='M';
        case 2:roman+='M';
        case 1:roman+='M';break;
        case 0:break;
        default:cout<<"Bad Year"<<endl;
    }
    
    //Fill the string with I's
    switch (n1){
        case 9:roman+="IX";break;
        case 8:roman+="VIII";break;
        case 7:roman+="VII";break;
        case 6:roman+="VI";break
        case 5:roman+='V';break;
        case 4:roman+='M';break;        case 6:
        case 3:roman+='M';
        case 2:roman+='M';
        case 1:roman+='M';break;
        case 0:break;
        default:cout<<"Bad Year"<<endl;
    }    
    
    
    //Dummy String
    return roman;
}

