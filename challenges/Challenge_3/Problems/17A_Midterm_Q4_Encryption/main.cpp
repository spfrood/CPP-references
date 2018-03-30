
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on April 23, 2017, 8:12 PM
 * Purpose: 4) A company wants to transmit data over the telephone, but they are 
concerned that their phones may be tapped. All of their data is 
transmitted as four-digit integers. However, they utilize the digits 
0,1,2,3,4,5,6,7 only. They have asked you to write a program that 
will encrypt their data so that it may be transmitted more securely.
Your application should read a four-digit integer with the numbers 
0 to 7 entered by the user in an input dialog and encrypt it as 
follows: Replace each digit by (the sum of that digit plus 3) modulus 8. 
Then swap the first digit with the second, and swap the third digit 
with the fourth. Then print the encrypted integer. Write a separate 
application that inputs an encrypted four-digit integer and decry04s 
it to form the original number.
Note:  sometimes errors occur and the digits 8, and 9 might appear.  
Detect this condition and flag the error.  Can't read in numbers 
individually.  All the digits must be read with one cin statement.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "encrypt.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const int THOSNDS=1000;//Conversion to 1,000
const int HUNDRDS=100; //Conversion to   100
const int TENS=10;     //Conversion to    10

//Function Prototypes
Encrypt getN04(); //function to convert a 4 digit short into 4 separate 1-digit numbers
Encrypt runCr04(Encrypt); //function to encrypt the 4 digit number
Encrypt decry04(Encrypt); //function to decry04 an encrypted structure
short conSh04(Encrypt); //function to convert a structure to a short
short swapV04(short); //function to return the original value of an encrypted digit

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    Encrypt digs, cDigs, dDigs;
    
    //Input Values
    digs=getN04();
    
    //Process by mapping inputs to outputs
    cDigs=runCr04(digs);
    dDigs=decry04(cDigs);
    
    //Output values
    cout<<"Original value:  "<<conSh04(digs)<<endl;
    cout<<"Encrypted value: "<<conSh04(cDigs)<<endl;
    cout<<"Decrypted value: "<<conSh04(dDigs)<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function to return the original value of an encrypted digit
short swapV04(short a) {
    short tmp=0;
    
    //Decryption matrix for the encrypted value
    switch(a){
        case 9:cout<<"ERROR!"<<endl;break;
        case 8:cout<<"ERROR!"<<endl;break;
        case 7:tmp=4;break;
        case 6:tmp=3;break;
        case 5:tmp=2;break;
        case 4:tmp=1;break;
        case 3:tmp=0;break;
        case 2:tmp=7;break;
        case 1:tmp=6;break;
        case 0:tmp=5;break;
        default:cout<<"ERROR SWITCH n1"<<endl;
    }
    return tmp;
}

//function to decry04 digits
Encrypt decry04(Encrypt a) {
    Encrypt tmp=a;
    short swap=0;
    
    //swap first and second digits
    swap=tmp.dig1;
    tmp.dig1=tmp.dig2;
    tmp.dig2=swap;
    
    //swap third and fourth
    swap=tmp.dig3;
    tmp.dig3=tmp.dig4;
    tmp.dig4=swap;
    
    //Decrypt structure
    tmp.dig1=swapV04(tmp.dig1);
    tmp.dig2=swapV04(tmp.dig2);
    tmp.dig3=swapV04(tmp.dig3);
    tmp.dig4=swapV04(tmp.dig4);
    
    //Exit and return tmp
    return tmp;
} 

//function to convert a structure to a short
short conSh04(Encrypt a) {
    short tmp=0;
    tmp+=a.dig1*1000; //1000's column
    tmp+=a.dig2*100; //100's column
    tmp+=a.dig3*10; //10's column
    tmp+=a.dig4; //1's column
    
    return tmp;
    
} 

//function to encrypt the 4 digit number
Encrypt runCr04(Encrypt a) {
    Encrypt tmp;
    short swap;
    
    //encrypt each digit of the structure
    tmp.dig1=((a.dig1+3)%8); 
    tmp.dig2=((a.dig2+3)%8);
    tmp.dig3=((a.dig3+3)%8);
    tmp.dig4=((a.dig4+3)%8);
    
    //swap first and second digits
    swap=tmp.dig1;
    tmp.dig1=tmp.dig2;
    tmp.dig2=swap;
    
    //swap third and fourth
    swap=tmp.dig3;
    tmp.dig3=tmp.dig4;
    tmp.dig4=swap;
    
    return tmp;
} 

//Function to print a paycheck when passed employee information
Encrypt getN04() { 
    //Declare Variables
    bool checker=false;
    short tmpAmnt; //check data and tmp used in calculation 
    short n1000,n100,n10,n1; //The numbers of powers of 10
    Encrypt a;
    
    //input values
    do { //validate range of 
        checker=false;
        cout<<"Enter a 4 digit number."<<endl;
        cout<<"Do not enter any digits larger than 7!"<<endl;
        cin>>tmpAmnt;
        //Parsing the amount into sections for conversion to text
        n1000=(tmpAmnt-tmpAmnt%THOSNDS)/THOSNDS;//Determines how many 1000's
        if (n1000>7) {
            cout<<"1000's digit too large!"<<endl;
            checker=true;
        }
        tmpAmnt=(tmpAmnt-n1000*THOSNDS);       //get rid of the thousands column
        n100=(tmpAmnt-tmpAmnt%HUNDRDS)/HUNDRDS;//Determines how many 100's
        if (n100>7) {
            cout<<"100's digit too large!"<<endl;
            checker=true;
        }
        tmpAmnt=(tmpAmnt-n100*HUNDRDS);        //Get rid of the 100's column
        n10=(tmpAmnt-tmpAmnt%TENS)/TENS;      //Determines how many 10's
        if (n10>7) {
            cout<<"10's digit too large!"<<endl;
            checker=true;
        }
        n1=(tmpAmnt-n10*TENS);            //what's left is the 1's
        if (n1>7) {
            cout<<"1's digit too large!"<<endl;
            checker=true;
        }
        
    } while (checker);
    cout<<"You entered: "<<n1000<<" "<<n100<<" "<<n10<<" "<<n1<<endl;
    
    //Set structure items = to the digitis
    a.dig1=n1000;
    a.dig2=n100;
    a.dig3=n10;
    a.dig4=n1;
    
    //Exit stage right! return the structure
    return a;
}