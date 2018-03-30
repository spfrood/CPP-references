/* 
  File:   main.cpp
  Author: Scott Parker
  Created on January 25, 2017, 8:55 PM
  Purpose:  We would like to write a check.  
 * Input the following: Date, Payee, Amount, and the account holder.  
 * Output these in the following format, but the amount needs to be output 
 * numerically as well as grammatically just like a check. 
 * Range for the check amount = $1 to $1999 (integers, no cents)
 * 
 * Input the following 4 values 
 * Date:            01/01/15 
 * Payee:           John Doe 
 * Amount:          $811
 * Account Holder:  Jane Doe
 * 
 * Output a written check
 * 
 * Jane Doe
 * STREET ADDRESS
 * CITY, STATE  ZIP                            Date:  01/01/15
 * 
 * Pay to the Order of:  John Doe              $ 811.00
 * 
 * Eight Hundred Eleven and no/100s Dollars
 * 
 * BANK OF CSC5
 * 
 * FOR:  GOTTA PAY THE RENT	               Jane Doe	
 * 
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const int THOSNDS=1000;//Conversion to 1,000
const int HUNDRDS=100; //Conversion to   100
const int TENS=10;     //Conversion to    10

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    string date="", holder="", payTo="", payFor=""; //check data
    unsigned short amount, tmpAmnt; //check data and tmp used in calculation
    char n1000,n100,n10,n1; //The numbers of powers of 10
    string amntText=""; //for converting amount to text
    
    //Input values 
    //Information fields for writing the check
    cout<<"Please enter the necessary information to fill out a check."<<endl;
    cout<<"Who owns the bank account?"<<endl;
    getline(cin, holder);
    cout<<"Who are you paying?"<<endl;
    getline(cin, payTo);
    cout<<"When will the check be dated?"<<endl;
    getline(cin, date);
    cout<<"What are you buying?(60 character max)"<<endl;
    getline(cin, payFor);
    cout<<"How much will you pay ($1 to $1999, no change)?"<<endl;
    cin>>amount;
    
    //Parsing the amount into sections for conversion to text
    tmpAmnt=amount; //Setting tmpAmnt working variable to value of amount
    n1000=(tmpAmnt-tmpAmnt%THOSNDS)/THOSNDS;//Determines how many 1000's
    tmpAmnt=(tmpAmnt-n1000*THOSNDS);       //Year without 1000's
    n100=(tmpAmnt-tmpAmnt%HUNDRDS)/HUNDRDS;//Determines how many 100's
    tmpAmnt=(tmpAmnt-n100*HUNDRDS);        //Year without 100's
    n10=(tmpAmnt-tmpAmnt%TENS)/TENS;      //Determines how many 10's
    n1=(tmpAmnt-n10*TENS);            //Year without 10's
    
    //Convert year to text
    //Calculate thousands output
    switch(n1000){
        case 1:amntText+="One Thousand ";break;
        case 0:break;
        default:cout<<"ERROR SWITCH n1000"<<endl;
    }
    
    //Calculate Hundreds
    switch(n100){
        case 9:amntText+="Nine Hundred ";break;
        case 8:amntText+="Eight Hundred ";break;
        case 7:amntText+="Seven Hundred ";break;
        case 6:amntText+="Six Hundred ";break;
        case 5:amntText+="Five Hundred ";break;
        case 4:amntText+="Four Hundred ";break;
        case 3:amntText+="Three Hundred ";break;
        case 2:amntText+="Two Hundred ";break;
        case 1:amntText+="One Hundred ";break;
        case 0:break;
        default:cout<<"ERROR SWITCH n100"<<endl;
    }
    
    //Calculate Tens with exception of less than 20
    switch(n10){
        case 9:amntText+="Ninety ";break;
        case 8:amntText+="Eighty ";break;
        case 7:amntText+="Seventy ";break;
        case 6:amntText+="Sixty ";break;
        case 5:amntText+="Fifty ";break;
        case 4:amntText+="Forty ";break;
        case 3:amntText+="Thirty ";break;
        case 2:amntText+="Twenty ";break;
        case 1:break;
        case 0:break;
        default:cout<<"ERROR SWITCH n10"<<endl;
    }
    
    //Calculate Ones if tens are 20 or greater
    if (n10!=1){
        switch(n1){
            case 9:amntText+="Nine ";break;
            case 8:amntText+="Eight ";break;
            case 7:amntText+="Seven ";break;
            case 6:amntText+="Six ";break;
            case 5:amntText+="Five ";break;
            case 4:amntText+="Four ";break;
            case 3:amntText+="Three ";break;
            case 2:amntText+="Two ";break;
            case 1:amntText+="One ";break;
            case 0:break;
            default:cout<<"ERROR SWITCH n1"<<endl;
        }
    }
    
    //Ones for tens value of less than 20 (teens)
    if (n10==1) {
        switch(n1){
            case 9:amntText+="Nineteen ";break;
            case 8:amntText+="Eighteen ";break;
            case 7:amntText+="Seventeen ";break;
            case 6:amntText+="Sixteen ";break;
            case 5:amntText+="Fifteen ";break;
            case 4:amntText+="Fourteen ";break;
            case 3:amntText+="Thirteen ";break;
            case 2:amntText+="Twelve ";break;
            case 1:amntText+="Eleven ";break;
            case 0:break;
            default:cout<<"ERROR SWITCH n1"<<endl;
        }
    }
    
    //format data and output check
    cout<<holder<<endl;
    cout<<"123 ABC Street"<<endl;
    cout<<"Beverly Hills, CA 90210                          Date: "
        <<setw(20)<<right<<date<<endl<<endl;
    cout<<"Pay to the order of: "<<setw(25)<<left<<payTo<<setw(21)<<right
        <<"Amount: $"<<setw(5)<<right<<amount<<".00"<<endl<<endl;
    cout<<"The Amount Of: "<<amntText<<"dollars and 00/100 "<<endl<<endl;
    cout<<"Bank of CSC5"<<endl;
    cout<<setw(75)<<right<<holder<<endl;
    cout<<"For: "<<setw(60)<<left<<payFor<<setw(10)<<right<<"Signature"<<endl;
    
    
    //Exit stage right!
    return 0;
}
