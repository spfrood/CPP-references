/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TxtNum.h"

const int THOSNDS=1000;   //Conversion to   1,000
const int HUNDRDS=100;    //Conversion to     100
const int TENS=10;        //Conversion to      10

//function to return number private data
int TxtNum::getNum() const{
    return number;
}

string TxtNum::txtVal () const { 
    //Declare Variables
    unsigned short tmpNum; //check data and tmp used in calculation 
    char n1000,n100,n10,n1; //The numbers of powers of 10
    string amtText=""; //for converting amount to text
    
    //Parsing the amount into sections for conversion to text
    tmpNum=number; //Setting tmpNum working variable to value of amount
    n1000=(tmpNum-tmpNum%THOSNDS)/THOSNDS;//Determines how many 1000's
    tmpNum=(tmpNum-n1000*THOSNDS);       //Reduce to the 100's digit
    n100=(tmpNum-tmpNum%HUNDRDS)/HUNDRDS;//Determines how many 100's
    tmpNum=(tmpNum-n100*HUNDRDS);        //Reduce to the 10's digit
    n10=(tmpNum-tmpNum%TENS)/TENS;      //Determines how many 10's
    tmpNum=(tmpNum-n10*TENS);           //Reduce to the 1's digit
    n1=tmpNum; //Value for ONES digit
    
    //Convert year to text
    //Calculate thousands output
    
    switch(n1000){
        case 9:amtText+=n1000s[n1000];break;
        case 8:amtText+=n1000s[n1000];break;
        case 7:amtText+=n1000s[n1000];break;
        case 6:amtText+=n1000s[n1000];break;
        case 5:amtText+=n1000s[n1000];break;
        case 4:amtText+=n1000s[n1000];break;
        case 3:amtText+=n1000s[n1000];break;
        case 2:amtText+=n1000s[n1000];break;
        case 1:amtText+=n1000s[n1000];break;
        case 0:break;
        default:cout<<"ERROR SWITCH n1000"<<endl;
    }
    
    //Calculate Hundreds
    switch(n100){
        case 9:amtText+=n100s[n100];break;
        case 8:amtText+=n100s[n100];break;
        case 7:amtText+=n100s[n100];break;
        case 6:amtText+=n100s[n100];break;
        case 5:amtText+=n100s[n100];break;
        case 4:amtText+=n100s[n100];break;
        case 3:amtText+=n100s[n100];break;
        case 2:amtText+=n100s[n100];break;
        case 1:amtText+=n100s[n100];break;
        case 0:break;
        default:cout<<"ERROR SWITCH n100"<<endl;
    }
    
    //Calculate Tens with exception of less than 20
    switch(n10){
        case 9:amtText+=n10s[n10];break;
        case 8:amtText+=n10s[n10];break;
        case 7:amtText+=n10s[n10];break;
        case 6:amtText+=n10s[n10];break;
        case 5:amtText+=n10s[n10];break;
        case 4:amtText+=n10s[n10];break;
        case 3:amtText+=n10s[n10];break;
        case 2:amtText+=n10s[n10];break;
        case 1:break;
        case 0:break;
        default:cout<<"ERROR SWITCH n10"<<endl;
    }
    
    //Calculate Ones if tens are 20 or greater
    if (n10!=1){
        switch(n1){
            case 9:amtText+=n1s[n1];break;
            case 8:amtText+=n1s[n1];break;
            case 7:amtText+=n1s[n1];break;
            case 6:amtText+=n1s[n1];break;
            case 5:amtText+=n1s[n1];break;
            case 4:amtText+=n1s[n1];break;
            case 3:amtText+=n1s[n1];break;
            case 2:amtText+=n1s[n1];break;
            case 1:amtText+=n1s[n1];break;
            case 0:break;
            default:cout<<"ERROR SWITCH n1"<<endl;
        }
    }
    
    //Ones for tens value of less than 20 (teens)
    if (n10==1) {
        switch(n1){ //teens
            case 9:amtText+=nTeen[n1];break;
            case 8:amtText+=nTeen[n1];break;
            case 7:amtText+=nTeen[n1];break;
            case 6:amtText+=nTeen[n1];break;
            case 5:amtText+=nTeen[n1];break;
            case 4:amtText+=nTeen[n1];break;
            case 3:amtText+=nTeen[n1];break;
            case 2:amtText+=nTeen[n1];break;
            case 1:amtText+=nTeen[n1];break;
            case 0:amtText+=nTeen[n1];break;
            default:cout<<"ERROR SWITCH n1"<<endl;
        }
    }
    
    if (amtText=="") amtText="Zero ";
    
    //format data and output check
    cout<<"Text Number: "<<amtText<<endl;
    return amtText;
    
    //Exit stage right!
}