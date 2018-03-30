/* 
  File:   main.cpp
  Author: Dr. Scott Parker
  Created on April 24, 2017, 9:36 PM
  Purpose:  Assignment 5 Homework Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <string>
#include <iomanip> //manipulate output and formatting
#include <ctime> //for random seed
#include <cstdlib> //for rand() function
using namespace std;

//User Libraries
#include "accinfo.h"
#include "comdata.h"
#include "empdata.h"
#include "statsresult.h"
#include "encrypt.h"
#include "colors.h"
#include "primes.h"


//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another and for 2d array columns
const int THOSNDS=1000;//Conversion to 1,000
const int HUNDRDS=100; //Conversion to   100
const int TENS=10;     //Conversion to    10

//Function Prototypes 
//Delete void functions or add them as needed based on homework problems
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();

AccInfo *filSt01(int, int); //Function to return structure and pass in #checks written and #checks deposited
void getCh01(float *, int); //Function to input the number of checks 
void testB01(AccInfo *); //Output contents of structure and Check to see if overdrawn 
void destr01(AccInfo *); //function to delete pointers, arrays, and clean up memory
void prnCh02(EmpData, ComData); //Function to print the paycheck
EmpData *addLi02(EmpData *, EmpData, int); //Function to add additional entry to array
void pEmpC10(EmpData *, int); //display contents of array (all workers and checks cut)
StatsResult *avgMedMo03(int *,int);  //Function to fill structure 
void srtMa03(int *, int); //Sort function
void filMa03(int *, int); //function to fill array with random ints
int fndMo03(int *, int &, int); //function to find mode and return the number of modes
void disMa03(int *, int); //Function to display array
void filMo03(int *, int *, int, int, int); //function to fill the array with the mode frequencies
float fndMe03(int *, int); //function to find the mean of an array
float fndMi03(int *, int); //function to find the median of an array
void pStaS03(StatsResult *); //function to print the contents of a StatsResult structure
Encrypt getN04(); //function to convert a 4 digit short into 4 separate 1-digit numbers
Encrypt runCr04(Encrypt); //function to encrypt the 4 digit number
Encrypt decry04(Encrypt); //function to decry04 an encrypted structure
short conSh04(Encrypt); //function to convert a structure to a short
short swapV04(short); //function to return the original value of an encrypted digit
void outA06(); //function to output the answers for question 6 in a simple cout


//Executable code begins here!!!
int main(int argc, char** argv) {
    //set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list <non-numeric data will be ignored>"<<endl;
        cout<<"Type 1 for Problem 1: CheckingBalance"<<endl;
        cout<<"Type 2 for Problem 2: PayScales"<<endl;
        cout<<"Type 3 for Problem 3: MeanMedianMode"<<endl;
        cout<<"Type 4 for Problem 4: Encryption"<<endl;
        cout<<"Type 5 for Problem 5: Factorial"<<endl;
        cout<<"Type 6 for Problem 6: Conversions"<<endl;
        cout<<"Type 7 for Problem 7: Primes"<<endl;
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
            case 7:{prob7();break;}
            case 6:{prob6();break;}
            case 5:{prob5();break;}
            case 4:{prob4();break;}
            case 3:{prob3();break;}
            case 2:{prob2();break;}
            case 1:{prob1();break;}
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>=1&&choice<=7);
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************ Function for Problem X  ****************************
//Description: Program for Book, Edition, Chapter, Question, Short Description
//
//Inputs: (what inputs passed to function)
//     
//Outputs:  (what is the output of this function)
//
//******************************************************************************

void prob7(){ 
    //Declare Variables
    unsigned short number=0, powCtr=0, numPrm=0;
    Primes values;
    values.prime=nullptr;
    
    //Input Values
    cout<<"Enter a number between 2 and 10000"<<endl;
    cin>>number; //input number to find the prime factors
    while (cin.fail() || number<2 || number>10000) { //validate input range
        cout<<"ERROR! Invalid Entry! Try Again!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>number;
    }
    values.prime=new Prime[number/2]; //set array to half the size of input number
    //Process by mapping inputs to outputs
    
    for (int i=2;i<=number;i++) { //loop through to find factors
        while (number%i==0) { //check to see how many times the value can be factored
            number/=i; //new value for number
            powCtr++; //power of factor
        }
        values.prime[numPrm].power=powCtr; //set value in array
        values.prime[numPrm].prime=i; //set value in array
        if (powCtr>0) numPrm++; //increment number of primes (move to next array element)
        powCtr=0; //reset power counter
    }
    
    for (int i=0;i<numPrm;i++) { //output the values in the array
        cout<<"Prime: "<<values.prime[i].prime<<"   Power: "<<values.prime[i].power<<endl;
    }
    
    //Output values and clean up memory
    delete [] values.prime;
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob6(){
    //Declare Variables
    
    
    //Input Values
    
    
    //Process by mapping inputs to outputs
    
    //Output values
    outA06();
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob5(){
    //Declare Variables
    bool ovFlw=false;
    char ch=1, tCh=1, mChF=0;
    unsigned char uCh=1, tUch=1, mUchF=0;
    short sh=1, tSh=1, mShF=0;
    unsigned short uSh=1, tUsh=1, mUshF=0;
    int in=1, tIn=1, mInF=0;
    unsigned int uIn=1, tUin=1, mUinF=0;
    long lo=1, tLo=1, mLoF=0;
    unsigned long uLo=1, tUlo=1, mUloF=0;
    float flt=1, tFlt=1, mFltF=0;
    double dub=1, tDub=1, mDubF=0;
    
    //Input Values
    
    //Process by mapping inputs to outputs
    //test for Char overflow
    for (char i=1;!ovFlw;i++){
        ovFlw=false;
        tCh=ch;
        ch*=i;
        if (ch/i != tCh) {
            ovFlw=true;
        } else mChF=i;
    }
    cout<<"Max Fact char: "<<static_cast<int>(mChF)<<endl;
    
    //Test for unsigned char overflow
    ovFlw=false;
    for (unsigned char i=1;!ovFlw;i++){
        ovFlw=false;
        tUch=uCh;
        uCh*=i;
        if (uCh/i != tUch) {
            ovFlw=true;
        } else mUchF=i;
    }
    cout<<"Max Fact unsigned char: "<<static_cast<int>(mUchF)<<endl;
    
    //Test for Short overflow
    sh=1;
    tSh=1;
    mShF=0;
    ovFlw=false;
    for (short i=1;!ovFlw;i++){
        ovFlw=false;
        tSh=sh;
        sh*=i;
        if (sh/i != tSh) {
            ovFlw=true;
        } else mShF=i;
    }
    cout<<"Max Fact short: "<<mShF<<endl;
    
    //Test for Unsigned Short overflow
    uSh=1;
    tUsh=1;
    mUshF=0;
    ovFlw=false;
    for (unsigned short i=1;!ovFlw;i++){
        ovFlw=false;
        tUsh=uSh;
        uSh*=i;
        if (uSh/i != tUsh) {
            ovFlw=true;
        } else mUshF=i;
    }
    cout<<"Max Fact unsigned short:"<<mUshF<<endl;
    
    //test for int overflow
//Data type method **DOESN"T WORK
//Endless loop. WHy???
/*
    for (int i=1;i*tIn<=2147483647;i++) {
        cout<<tIn<<endl;
        tIn*=i;
        cout<<"Count "<<i<<": "<<tIn<<endl;
        mInF=i;
    }
    cout<<"Max Factorial for int: "<<mInF<<endl;
*/
    
    in=1;
    tIn=1;
    mInF=0;
    ovFlw=false;
    for (int i=1;!ovFlw;i++){
        ovFlw=false;
        tIn=in;
        in*=i;
        if (in/i != tIn) {
            ovFlw=true;
        } else mInF=i;
    }
    cout<<"Max Fact int:"<<mInF<<endl;
    
    //test for unsigned int overflow
    uIn=1;
    tUin=1;
    mUinF=0;
    ovFlw=false;
    for (unsigned int i=1;!ovFlw;i++){
        ovFlw=false;
        tUin=uIn;
        uIn*=i;
        if (uIn/i != tUin) {
            ovFlw=true;
        } else mUinF=i;
    }
    cout<<"Max Fact unsigned int: "<<mUinF<<endl;
    
    //Test for long int
    lo=1;
    tLo=1;
    mLoF=0;
    ovFlw=false;
    for (long i=1;!ovFlw;i++){
        ovFlw=false;
        tLo=lo;
        lo*=i;
        if (lo/i != tLo) {
            ovFlw=true;
        } else mLoF=i;
    }
    cout<<"Max Fact long: "<<mLoF<<endl;
    
    //test for unsigned long int
    uLo=1;
    tUlo=1;
    mUloF=0;
    ovFlw=false;
    for (unsigned long i=1;!ovFlw;i++){
        ovFlw=false;
        tUlo=uLo;
        uLo*=i;
        if (uLo/i != tUlo) {
            ovFlw=true;
        } else mUloF=i;
    }
    cout<<"Max Fact unsigned long: "<<mUloF<<endl;
    
    //test for float overflow
    flt=1;
    tFlt=1;
    mFltF=0;
    ovFlw=false;
    for (float i=1;!ovFlw;i++){
        ovFlw=false;
        cout<<setprecision(0)<<fixed;
        tFlt=flt;
        flt*=i;
        if (flt/i != tFlt) {
            ovFlw=true;
        } else mFltF=i;
    }
    cout<<"Max Fact float - precision: "<<setprecision(0)<<fixed<<mFltF<<endl;
    
    float testrng=1;
    int maxFlt=0;
    for (int i=1;testrng<=3.402823466e38f;i++){
        testrng*=i;
        cout<<setprecision(0)<<fixed;
        maxFlt=i-1;
    }
    cout<<"Max Fact float - range: "<<maxFlt<<endl;
    
    //test for double overflow
    dub=1;
    tDub=1;
    mDubF=0;
    ovFlw=false;
    for (double i=1;!ovFlw;i++){
        ovFlw=false;
        tDub=dub;
        dub*=i;
        if (dub/i != tDub) {
            ovFlw=true;
        } else mDubF=i;
    }
    cout<<"Max Fact double - precision: "<<setprecision(0)<<fixed<<mDubF<<endl;
    
    double testDub=1;
    int maxDub=0;
    for (int i=1;testDub<=1.757e308;i++){
        testDub*=i;
        maxDub=i-1;
    }
    cout<<"Max Fact double - range: "<<maxDub<<endl;

    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob4(){
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
    //Exit stage right! - This is the 'return 0' call
    
}

void prob3(){
    //Declare Variables
    int size=0;
    int *intAry=nullptr; //pointer to be assigned to array 
    cout<<"How large would you like to make the array?"<<endl;
    cin>>size; //input the size of the array
    while (cin.fail()||size<1){ //validate input
        cin.clear(); //reset cin flags
        cin.ignore(256, '\n'); //clear buffer contents
        cout<<"Enter an integer of 1 or larger!"<<endl;
        cin>>size; //input size again
    }
    intAry=new int [size]; //create array with size input
    StatsResult *arStat=avgMedMo03(intAry, size); 
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
    pStaS03(arStat); //function to print the contents of a StatsResult structure
    
    //clean up memory
    delete [] arStat->mode; 
    delete [] intAry; 
    delete [] arStat; 
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob2(){
    //Declare Variables
    ComData company; //company info for the check data 
    EmpData worker; //worker data for getting paid
    int size=0; //counter for array
    EmpData *worList=nullptr; //array to hold all values
    
    //Input data on the company
    cout<<"Please enter the necessary information to fill out a check."<<endl;
    cout<<"Which company is this payroll for?"<<endl;
    cin.ignore(256, '\n');
    getline (cin, company.comName);
    cout<<"Enter the street address of company:"<<endl;
    getline (cin, company.street);
    cout<<"Enter the city:"<<endl;
    getline(cin, company.city);
    cout<<"Enter the state:"<<endl;
    getline (cin, company.state);
    cout<<"Enter company zipcode:"<<endl;
    getline (cin, company.zip);
    cout<<"Enter the date this payrole is to be paid:"<<endl;
    getline (cin, company.date);
    
    //Input first round of employee data. MUST enter data for eat least one employee
    cout<<"Enter the employee's name: "<<endl;
    getline(cin, worker.empName);
    cout<<"Enter the hours worked this week (Max of 80):"<<endl;
    cin>>worker.hrsWrkd;
    while (cin.fail() || worker.hrsWrkd>80 || worker.hrsWrkd<=0){ //validate data type and range
        cout<<"Entry not valid! Enter a non-zero positive integer less than 80!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>worker.hrsWrkd;
    }
    cout<<"Enter the rate of pay for this employee (Max of $133/hr) (0 or less to exit):"<<endl;
    cin>>worker.payRate;
    while (cin.fail() || worker.payRate>133 || worker.payRate<=0) { //validate data type and range
        cout<<"Entry not valid! Enter a non-zero positive integer of 133 or less!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>worker.payRate;
    }
    size++; //We officially have the data to create an array of (size) elements (1 in this case)
    while (worker.hrsWrkd >0 && worker.payRate>0) { //keep looping until negative pay or hours value
        prnCh02(worker, company); //print the employee's check
        cout<<endl;
        worList=addLi02(worList, worker, size); //Add a line to the array and write the employee data to array
        
        //Repeat process until a check for $0 or less would be cut
        cout<<"Enter the employee's name: "<<endl;
        cin.ignore(256, '\n');
        getline(cin, worker.empName);
        cout<<"Enter the hours worked this week (Max of 80) (0 or less to exit):"<<endl;
        cin>>worker.hrsWrkd;
        while (cin.fail() || worker.hrsWrkd>80){ //validate range and data type
            cout<<"Entry not valid! Enter a non-zero positive integer less than 80!"<<endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin>>worker.hrsWrkd;
        }
        cout<<"Enter the rate of pay for this employee (Max of $133/hr):"<<endl;
        cin>>worker.payRate;
        while (cin.fail() || worker.payRate>133) { //validate range and data type
            cout<<"Entry not valid! Enter a non-zero positive integer of 133 or less!"<<endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin>>worker.payRate;
        }
        size++; //Increment number of employees
    }
    
    pEmpC10(worList, size); //display contents of array (all workers and checks cut)
    
    //Clean up memory
    delete [] worList;
    
    //Exit stage right!
    //Exit stage right! - This is the 'return 0' call
}

void prob1(){
    //Declare Variables
    int checks=0, deposit=0; //vars to set size of arrays
    
    //create and initialize structure - Get data for array sizes
    cout<<"How many checks did you write this month (at least 1)?"<<endl;
    cin>>checks; 
    while (cin.fail() || checks<1) { //Loop to validate input
        cin.clear();  //Resetting flags               
        cin.ignore(256, '\n'); //ignore contents of buffer
        cout<<"Please enter a valid number!:"<<endl;
        cin>>checks;
    }
    cout<<"How many deposits did you make this month (at least 1)?"<<endl;
    cin>>deposit;
    while (cin.fail() || deposit<1) { //Loop to validate input
        cin.clear();  //Resetting flags               
        cin.ignore(256, '\n'); //ignore contents of buffer
        cout<<"Please enter a valid number!:"<<endl;
        cin>>deposit;
    }
    AccInfo *account=filSt01(checks, deposit); //dynamically create structure 
    
    //Process by mapping inputs to outputs
    testB01(account); //check account balances
    
    //Output values
    
    
    //Clean up memory
    destr01(account); 
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

//function to output the answers for question 6 in a simple cout
void outA06() {
    cout<<"Convert 2.325 from base 10 to base 2, 8, and 16."<<endl;
    cout<<"Also output in float notation."<<endl;
    cout<<"Base 16: 2.AC"<<endl;
    cout<<"Base 8: 2.246"<<endl;
    cout<<"Base 2: 10.0101"<<UNDERLINE<<"0011"<<RESET<<endl;
    cout<<"Float Notation: 4A666602"<<endl;
    cout<<"Negative Float Value: B5999A02"<<endl;
    cout<<endl;
    cout<<"Convert 0.1453125 from base 10 to base 2, 8, and 16."<<endl;
    cout<<"Also output in float notation."<<endl;
    cout<<"Base 16: 0.4AC"<<endl;
    cout<<"Base 8: 0.4426"<<endl;
    cout<<"Base 2: 0.00100101"<<UNDERLINE<<"0011"<<RESET<<endl;
    cout<<"Float Notation: 4A6666FE"<<endl;
    cout<<"Negative Float Value: B5999AFE"<<endl;
    cout<<endl;
    cout<<"Convert 59999901 from Float Notation to Decimal"<<endl;
    cout<<"010110011001100110011001|00000001"<<endl;
    cout<<"Decimal value: 1.66101074"<<endl;
    cout<<"Convert 59999902 from Float Notation to Decimal"<<endl;
    cout<<"010110011001100110011001|00000010"<<endl;
    cout<<"Decimal value: 2.79998779"<<endl;
    cout<<"Convert 59999901 from Float Notation to Decimal"<<endl;
    cout<<"101001100110011001100111|11111110"<<endl;
    cout<<"Decimal value: -0.006000061"<<endl;
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

//function to print the contents of a StatsResult structure
void pStaS03(StatsResult *a){
    cout<<setprecision(4);
    //output the values stored in the structure
    cout<<"The average value stored in the structure is: "<<a->avg<<endl;
    cout<<"The median value stored in the structure is: "<<a->median<<endl;
    cout<<"The frequency of the modes in this array is: "<<a->maxFreq<<endl;
    if (a->maxFreq==1){
        cout<<"     This means no elements repeated themselves."<<endl;
    } 
    cout<<"The total number of values stored in the array are: "<<a->nModes<<endl;
    cout<<"     The values stored in the array in this structure: "<<endl;
    for (int i=0;i<a->nModes;i++){
        cout<<setw(12)<<a->mode[i];
        if (i%6==0 && i!=0) cout<<endl;
    }
    cout<<endl;
    cout<<"No further data stored in structure."<<endl;
} 

//Function to fill structure 
StatsResult *avgMedMo03(int *intAry, int size) {
    //Declare Variables
    int mode=0, freq=0, mean=0, median=0; //size of array, mode of array
    int *modAry=nullptr; //WIll be assigned to array to output the mode (modes) data
    StatsResult *stats= new StatsResult;
    
    //Input Values
    filMa03(intAry, size); //call function to fill array
    disMa03(intAry, size); //display contents of the array
    cout<<endl; 
    
    //Process by mapping inputs to outputs
    cout<<"Sorting array..."<<endl;
    srtMa03(intAry, size); //call function to sort array
    disMa03(intAry, size); //display contents of the array
    cout<<endl;
    
    freq=fndMo03(intAry, mode, size); //call function to find mode and set variable mode value
    
    modAry= new int [mode];
    filMo03(intAry, modAry, mode, size, freq); //fill mode values in modAry
    
    //Set values in structure
    stats->nModes=mode;
    stats->maxFreq=freq;
    stats->mode=new int[stats->nModes];
    for (int i=0;i<stats->nModes;i++){
        stats->mode[i]=modAry[i];
    }
    stats->avg=fndMe03(intAry, size);
    stats->median=fndMi03(intAry, size);
    
    //clean up unneeded arrays
    delete [] modAry; //free memory reserved by this pointer
    
    return stats;
} 

//function to find the median of an array
float fndMi03(int *ary, int size){
    float median=0.0f;
    if (size%2==0){
        median= (static_cast<float>(*(ary+size/2))+ static_cast<float>(*(ary+size/2-1)))/2;
    } else {
        median= static_cast<float>(*(ary+size/2));
    }
    return median;
}


//Function to find the mean of the array values
float fndMe03(int *ary, int size){
    float runtot=0;
    for (int i=0;i<size;i++){
        runtot+= static_cast<float>(*(ary+i));
    }
    
    return runtot/size;
}

//function to fill the array with the mode frequencies
void filMo03(int *ary, int *mAry, int modes, int size, int highest) {
    int count=0;
    int modeCnt=0;
    for (int i=0;i<size;i++){ //run through array to see how often elements occur at frequency
        count++;
        if (i==size-1){
            if (count==highest) {
                *(mAry+modeCnt) = *(ary+i);
                modeCnt++;
            }
        } else if (*(ary+i)!= *(ary+i+1)) {
            if (count==highest){
                *(mAry+modeCnt)= *(ary+i);
                modeCnt++;
            }
            count=0;
        } 
    }
} 

//Function to print array contents
void disMa03(int *array, int size){
    for (int i=0;i<size;i++){ //Output the current element in the array. Loop for each element
        if (i%10==0) cout<<endl;
        cout<<setw(7)<<right;
        cout<<*(array+i);
    }
    cout<<endl;
}

//Function to find the number of modes, write mode values and mode frequency to an array
//Will return the frequency of the mode (or modes)
int fndMo03(int *ary, int &modes, int size){
    int count=0, highest=0; //count and record of occurances

    for (int i=0;i<size;i++){ //run though array to find the mode frequency
        count++;
        if (i==size-1){
            if (count>highest) {
                highest=count;
            }
        } else if (*(ary+i)!= *(ary+i+1)) {
            if (count>highest){
                highest=count;
            }
            count=0;
        } 
    }
    count=0;
    
    for (int i=0;i<size;i++){ //run through array to see how often elements occur at frequency
        count++;
        if (i==size-1){
            if (count==highest) {
                modes++;
            }
        } else if (*(ary+i)!= *(ary+i+1)) {
            if (count==highest){
                modes++;
            }
            count=0;
        } 
    }
    
    return highest; //return the mode 
}

//function to fill array with random data
void filMa03(int *array, int size){
    char chooser='\0';
    cout<<"Fill with random values (Y/y for random)?"<<endl;
    cin>>chooser;
    if (chooser=='Y' || chooser=='y'){
        int rndSize=0; //variable for user-selected size random number
        cout<<"How large of a range for the random fill numbers? "<<endl;
        cout<<"Up to 10000 (and greater than 0)"<<endl;
        cin>>rndSize; //Input size range of random (0 to rndSize)
        while (cin.fail()||rndSize<=0||rndSize>=10001){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Enter a positive integer up to 10000!"<<endl;
            cin>>rndSize;
        }
        for (int i=0;i<size;i++){
            *(array+i)=rand()%rndSize; //fill array element with random number
        }
        cout<<"Array filled with random values between 0 and "<<rndSize<<"ish."<<endl;
    } else {
        cout<<"Okay, time to enter the values manually!"<<endl;
        for (int i=0;i<size;i++){
            cout<<"Enter value for array element "<<i<<": ";
            cin>>array[i];
        }
    }
}

//Function to sort the array in ascending order
void srtMa03(int *array, int size){
    bool swap; //create variable to keep swapping
    int temp; //Variable to hold values for swaps
    do {
        swap=false; //Set swap condition to false. Will exit swap if nothing exchanged
        for (int i=0;i<(size-1);i++) { //run through the array and see if anything needs swapping
            if (*(array+i)> *(array+(i+1))) { //swap if next element is smaller value
                temp= *(array+i); //set temp value to current element
                *(array+i) = array[i+1]; //set current element to next element
                *(array+(i+1))=temp; //set next element to temp
                swap=true; //Swap was performed so swap = true and run loop again
            }
        }
    } while (swap); //keep doing this until array is run through without a swap being done
}

//display contents of array (all workers and checks cut)
void pEmpC10(EmpData *a, int size){ 
    //format... make it look pretty
    cout<<setw(10)<<left<<"Emp. Num"<<setw(25)<<left<<"Name"<<setw(10)<<left<<"Hours"<<setw(10)<<left<<"Rate"<<endl;
    for (int i=0;i<size-1;i++){ //loop through the array and output the info from each item
        cout<<setw(7)<<right<<i+1<<":  ";
        cout<<setw(25)<<left<<a[i].empName;
        cout<<setw(10)<<left<<a[i].hrsWrkd;
        cout<<setw(10)<<left<<a[i].payRate<<endl; 
    }
}

//Function to add additional entry to array
EmpData *addLi02(EmpData *a, EmpData e, int size) {
    EmpData *tmp= new EmpData[size]; //create temp array
    if (size==1){ //first time around no need to copy arrays
        a=new EmpData[size]; //create array of 1 element 
        a[size-1].empName=e.empName; //write emp data from single element to the array
        a[size-1].hrsWrkd=e.hrsWrkd;
        a[size-1].payRate=e.payRate;
    } else { //Do this after the first time
        for (int i=0;i<size;i++){ //assign current array to new array
            tmp[i]=a[i]; //copy array
        }
        delete [] a; //delete old array
        a=new EmpData[size]; //re-create array 1 element larger
        for (int i=0;i<size;i++){ //loop through array
            a[i]=tmp[i]; //copy data back to the main array
        } 
        //add the data from the new employee to the array
        a[size-1].empName=e.empName; 
        a[size-1].hrsWrkd=e.hrsWrkd;
        a[size-1].payRate=e.payRate;
    }
    delete [] tmp; //delete the temp array used in copying
    return a; //Return the new larger array and exit function
}


//Function to print a paycheck when passed employee information
void prnCh02(EmpData e, ComData c) { 
    //Declare Variables
    string date=c.date, holder=c.comName, payTo=e.empName, payFor="Payroll for hours worked"; 
    unsigned short amount, tmpAmnt; //check data and tmp used in calculation 
    char n1000,n100,n10,n1; //The numbers of powers of 10
    string amtText=""; //for converting amount to text
    
    //Input values 
    if (e.hrsWrkd<=40) amount=e.hrsWrkd*e.payRate; //if no overtime
    else if (e.hrsWrkd<=50) amount=(e.payRate*40+((e.hrsWrkd-40)*2*e.payRate)); //if overtime (41-50 hours)
    else amount=(e.payRate*40+e.payRate*20+(((e.hrsWrkd-50)*3)*e.payRate)); //if tripletime (51+ hours)
    
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
        case 19:amtText+="Nineteen Thousand ";break;
        case 18:amtText+="Eighteen Thousand ";break;
        case 17:amtText+="Seventeen Thousand ";break;
        case 16:amtText+="Sixteen Thousand ";break;
        case 15:amtText+="Fifteen Thousand ";break;
        case 14:amtText+="Fourteen Thousand ";break;
        case 13:amtText+="Thirteen Thousand ";break;
        case 12:amtText+="Twelve Thousand ";break;
        case 11:amtText+="Eleven Thousand ";break;
        case 10:amtText+="Ten Thousand ";break;
        case 9:amtText+="Nine Thousand ";break;
        case 8:amtText+="Eight Thousand ";break;
        case 7:amtText+="Seven Thousand ";break;
        case 6:amtText+="Six Thousand ";break;
        case 5:amtText+="Five Thousand ";break;
        case 4:amtText+="Four Thousand ";break;
        case 3:amtText+="Three Thousand ";break;
        case 2:amtText+="Two Thousand ";break;
        case 1:amtText+="One Thousand ";break;
        case 0:break;
        default:cout<<"ERROR SWITCH n1000"<<endl;
    }
    
    //Calculate Hundreds
    switch(n100){
        case 9:amtText+="Nine Hundred ";break;
        case 8:amtText+="Eight Hundred ";break;
        case 7:amtText+="Seven Hundred ";break;
        case 6:amtText+="Six Hundred ";break;
        case 5:amtText+="Five Hundred ";break;
        case 4:amtText+="Four Hundred ";break;
        case 3:amtText+="Three Hundred ";break;
        case 2:amtText+="Two Hundred ";break;
        case 1:amtText+="One Hundred ";break;
        case 0:break;
        default:cout<<"ERROR SWITCH n100"<<endl;
    }
    
    //Calculate Tens with exception of less than 20
    switch(n10){
        case 9:amtText+="Ninety ";break;
        case 8:amtText+="Eighty ";break;
        case 7:amtText+="Seventy ";break;
        case 6:amtText+="Sixty ";break;
        case 5:amtText+="Fifty ";break;
        case 4:amtText+="Forty ";break;
        case 3:amtText+="Thirty ";break;
        case 2:amtText+="Twenty ";break;
        case 1:;break;
        case 0:break;
        default:cout<<"ERROR SWITCH n10"<<endl;
    }
    
    //Calculate Ones if tens are 20 or greater
    if (n10!=1){
        switch(n1){
            case 9:amtText+="Nine ";break;
            case 8:amtText+="Eight ";break;
            case 7:amtText+="Seven ";break;
            case 6:amtText+="Six ";break;
            case 5:amtText+="Five ";break;
            case 4:amtText+="Four ";break;
            case 3:amtText+="Three ";break;
            case 2:amtText+="Two ";break;
            case 1:amtText+="One ";break;
            case 0:break;
            default:cout<<"ERROR SWITCH n1"<<endl;
        }
    }
    
    //Ones for tens value of less than 20 (teens)
    if (n10==1) {
        switch(n1){
            case 9:amtText+="Nineteen ";break;
            case 8:amtText+="Eighteen ";break;
            case 7:amtText+="Seventeen ";break;
            case 6:amtText+="Sixteen ";break;
            case 5:amtText+="Fifteen ";break;
            case 4:amtText+="Fourteen ";break;
            case 3:amtText+="Thirteen ";break;
            case 2:amtText+="Twelve ";break;
            case 1:amtText+="Eleven ";break;
            case 0:amtText+="Ten ";break;
            default:cout<<"ERROR SWITCH n1"<<endl;
        }
    }
    
    //format data and output check
    cout<<"Printing Check!"<<endl<<endl;
    cout<<setw(50)<<left<<holder<<setw(10)<<right<<"Date: "<<c.date<<endl;
    cout<<c.street<<endl;
    cout<<c.city+", "<<c.state+"  "<<c.zip<<endl;
    cout<<"Pay to the order of: "<<setw(25)<<left<<payTo<<setw(21)<<right
        <<"Amount: $"<<setw(5)<<right<<amount<<".00"<<endl<<endl;
    cout<<"The Amount Of: "<<amtText<<"dollars and 00/100 "<<endl<<endl;
    cout<<"Bank of CSC17A"<<setw(61)<<right<<holder<<endl;
    cout<<"Memo: "<<setw(59)<<left<<payFor<<setw(10)<<right<<"Signature"<<endl;
    
    //Exit stage right!
}

//Function to return structure and pass in #checks written and #checks deposited
AccInfo *filSt01(int checks, int deps){
    string temp=""; //string to hold temporary data
    float tmpFlt=0.0f; //float to hold temporary data
    AccInfo *a=new AccInfo; //initialize new array
    a->outChck=checks; //set checks array size
    a->inDep=deps; //set deposit array size
    a->allChck=new float[a->outChck]; //create checks array
    a->allDep=new float[a->inDep]; //create deposits array
    cout<<"Enter customer's name:"<<endl;
    cin.ignore(256, '\n');
    getline(cin, temp); //get customer name
    a->cusName=temp;
    cout<<"Enter the customer's street address:"<<endl;
    getline(cin, temp); //get customer street address
    a->address=temp;
    cout<<"Enter the customer's city:"<<endl;
    getline(cin, temp); //get customer city
    a->city=temp;
    cout<<"Enter the customer's state: "<<endl;
    getline(cin, temp); //get customer state
    a->state=temp;
    cout<<"Enter the customer's postal code: "<<endl;
    cin>>a->zip; //get cusotmer postal code
    while (cin.fail() || a->zip<10000 || a->zip>99999){
        cout<<"Enter a 5-digit zip code from 10000 to 99999"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>a->zip;
    }
    cin.ignore(255, '\n');
    cout<<"Enter the customer's 5-digit account number:"<<endl;
    getline(cin, temp); //Get customer account number
    while(cin.fail() || temp.length()!=5){ //make sure account number 5 digits long
        cout<<"Account numbers must be 5 digits!"<<endl;
        cin.clear();
        getline(cin, temp);
    }
    a->accNum=temp; 
    cout<<"Enter the starting balance of the account (-1 for random 5000-9999)"<<endl;
    cin>>tmpFlt; //enter starting balance or choose random
    tmpFlt<=0?a->strtBal=rand()%4999+5000:a->strtBal=tmpFlt;
    cout<<"Starting account balance: $"<<a->strtBal<<endl;
    cout<<"Enter the values for the "<<a->outChck<<" checks written this month."<<endl;
    getCh01(a->allChck, a->outChck); //call function to get the checks written values
    cout<<"Enter the values for the "<<a->inDep<<" depsoits made this month."<<endl;
    getCh01 (a->allDep, a->inDep); //call function to get the deposits made values
    return a; //return a (the structure)
}

//Function to input the number of checks 
void getCh01(float *a, int size) {
    char choice='\0';
    cout<<"Randomize data with values from 1-1000? (Y/N)"<<endl;
    cin.ignore(256, '\n');
    cin>>choice; //randomize or not...
    while (choice!='Y' && choice!='y' && choice!='N' && choice !='n') {
        cout<<"Enter Y or N!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>choice;
    }
    for (int i=0;i<size;i++){ //loop through size of array
        cout<<setprecision(2)<<showpoint<<fixed; 
        if (choice=='y' || choice=='Y'){
            a[i]=rand()%999+1; //set and display random value if this option chosen
            cout<<"Entry number "<<i+1<<": $"<<a[i]<<endl;
        }
        else { //assign values manually if random not chosen
            int tmpFlt=0.0f;
            cout<<"Enter the amount for entry number "<<i+1<<": $";
            cin>>tmpFlt; //enter values manually if random not chosen
            while (cin.fail() || tmpFlt<=0){ //validate data range and type
                cout<<"Must enter a positive number!"<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>tmpFlt;
            }
            a[i]=tmpFlt;
        }
    }
} 

//Output contents of structure and Check to see if overdrawn 
void testB01(AccInfo *a) {
    bool paidFee=false; //boolean false for overdraft fee
    cout<<setprecision(2)<<showpoint<<fixed; 
    a->endBal=a->strtBal; //set the end balance to start balance
    for (int i=0;i<a->outChck;i++) { //loop through checks written
        a->endBal-=a->allChck[i]; //debit from end balance
    }
    for (int i=0;i<a->inDep;i++){ //loop through deposits
        a->endBal+=a->allDep[i]; //add to end balance
    }
    if (a->endBal<=0) { //check for overdraft
        cout<<"Your current balance is: $"<<a->endBal<<endl; 
        cout<<"Your balance is negative! You will be accessed a $15 overdraft fee!"<<endl;
        a->endBal-=15; //debit fee if overdraft
        cout<<"Your new balance is: $"<<a->endBal<<endl; //notify new balance
        paidFee=true; //bool to true for overdraft
    } else {
        cout<<"Your current balance is: $"<<a->endBal<<endl;
    }
    cout<<"Your total account activity is as follows: "<<endl;
    cout<<"Account Holder:  "<<a->cusName<<endl; //output structure data
    cout<<"                 "<<a->address<<endl;
    cout<<"                 "<<a->city<<", "<<a->state<<" "<<a->zip<<endl;
    cout<<endl;
    cout<<"Starting balance; $"<<a->strtBal<<"    Final balance: $"<<a->endBal<<endl;
    cout<<"Checks written: "<<endl;
    float temp=0.0f;
    for (int i=0;i<a->outChck;i++){ //loop through and output checks written
        if (i%3==0 && i!=0) cout<<endl;
        cout<<"  Check "<<setw(3)<<i+1<<": $"<<setw(8)<<right<<setprecision(2)<<showpoint<<fixed<<a->allChck[i];
        temp+=a->allChck[i];
    }
    cout<<endl;
    if (paidFee) cout<<"You were also debited a $15 overdraft fee."<<endl; //notify of fee paid
    cout<<"Total value of checks written: $"<<temp<<endl;
    cout<<endl;
    temp=0.0f;
    cout<<"Deposits made:"<<endl;
    for (int i=0;i<a->inDep;i++){ //loop through and output deposits made
        if (i%3==0 && i!=0) cout<<endl;
        cout<<"  Deposit "<<setw(3)<<i+1<<": $"<<setw(8)<<right<<setprecision(2)<<showpoint<<fixed<<a->allDep[i];
        temp+=a->allDep[i];
    }
    cout<<endl;
    cout<<"Total of all deposits made: $"<<temp<<endl;
}

//function to delete pointers, arrays, and clean up memory
void destr01(AccInfo *a) {
    delete []a->allChck;
    delete []a->allDep;
    delete a;
}