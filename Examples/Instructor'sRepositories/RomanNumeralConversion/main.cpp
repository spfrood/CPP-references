/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 24, 2017, 10:53 AM
  Purpose:  Convert to Roman Numerals
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const int THOSNDS=1000;//Conversion to 1,000
const int HUNDRDS=100; //Conversion to   100
const int TENS=10;     //Conversion to    10

//Function Prototypes
string cnvrtRN(unsigned short);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short year;
    
    //Input values
    cout<<"This program converts years to Roman numerals"<<endl;
    cout<<"Input a year between 1000AD to 3000AD"<<endl;
    cin>>year;
    
    //Output the Roman Numeral
    cout<<year<<" = "<<cnvrtRN(year)<<endl;    

    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************** Roman Numeral Conversion ********************************
//Description:  Convert numbers from 1000 to 3000
//Inputs:
//     year -> Year from 1000 to 3000
//Outputs:
//     romanYr ->  Output to the 
//******************************************************************************
string cnvrtRN(unsigned short year){
    //Declare variables
    char n1000,n100,n10,n1;//The number of powers of 10
    string roman="";
    
    //Parsing the year information
    n1000=(year-year%THOSNDS)/THOSNDS;//Determines how many 1000's
    year =(year-n1000*THOSNDS);       //Year without 1000's
    n100 =(year-year%HUNDRDS)/HUNDRDS;//Determines how many 100's
    year =(year-n100*HUNDRDS);        //Year without 100's
    n10  =(year-year%TENS)/TENS;      //Determines how many 10's
    n1   =(year-n10*TENS);            //Year without 10's
    
    //Fill the string with M's
    switch(n1000){
        case 3:roman+='M';
        case 2:roman+='M';
        case 1:roman+='M';break;
        default:cout<<"Bad Year"<<endl;
    }
    
    //Fill the string with C's
    switch(n100){
        case 9:roman+="CM";break;
        case 8:roman+="DCCC";break;
        case 7:roman+="DCC";break;
        case 6:roman+="DC";break;
        case 5:roman+="D";break;
        case 4:roman+="CD";break;
        case 3:roman+='C';
        case 2:roman+='C';
        case 1:roman+='C';break;
        case 0:break;
        default:cout<<"Bad Year"<<endl;
    }
    
    //Fill the string with X's
    switch(n10){
        case 9:roman+="XC";break;
        case 8:roman+="LXXX";break;
        case 7:roman+="LXX";break;
        case 6:roman+="LX";break;
        case 5:roman+="L";break;
        case 4:roman+="XL";break;
        case 3:roman+='X';
        case 2:roman+='X';
        case 1:roman+='X';break;
        case 0:break;
        default:cout<<"Bad Year"<<endl;
    }
    
    //Fill the string with I's
    switch(n1){
        case 9:roman+="IX";break;
        case 8:roman+="VIII";break;
        case 7:roman+="VII";break;
        case 6:roman+="VI";break;
        case 5:roman+="V";break;
        case 4:roman+="IV";break;
        case 3:roman+='I';
        case 2:roman+='I';
        case 1:roman+='I';break;
        case 0:break;
        default:cout<<"Bad Year"<<endl;
    }
    
    //Return the String
    return roman;
}