/* 
  File:   main.cpp
  Author: Dr. Scott Parker
  Created on February 5, 2017, 12:28 PM
  Purpose:  Assignment 5 Homework Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "P1DtCls.h"
#include "Worker.h" //worker class
#include "CarCls.h" //car class
#include "AddBook.h" //Address book
#include "Tests.h" //test scores class
#include "TxtNum.h"
#include "DayYear.h"
#include "DayYer2.h"
#include "MthCls7.h"
#include "FeetInches.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another and for 2d array columns
const int THOSNDS=1000;   //Conversion to   1,000
const int HUNDRDS=100;    //Conversion to     100
const int TENS=10;        //Conversion to      10

//Function Prototypes 
//Delete void functions or add them as needed based on homework problems
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();

bool badTxt(string); //function to determine if text input is a month name

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list <non-numeric data will be ignored>"<<endl;
        cout<<"Type 1 for Problem 1: Date Class Print"<<endl;
        cout<<"Type 2 for Problem 2: Worker Class"<<endl;
        cout<<"Type 3 for Problem 3: Car Class"<<endl;
        cout<<"Type 4 for Problem 4: Address Book"<<endl;
        cout<<"Type 5 for Problem 5: Test Scores"<<endl;
        cout<<"Type 6 for Problem 6: Number to Text"<<endl;
        cout<<"Type 7 for Problem 7: Day of the Year"<<endl;
        cout<<"Type 8 for Problem 8: Day of Year Revised"<<endl;
        cout<<"Type 9 for Problem 9: Month Class"<<endl;
        cout<<"Type 10 for problem 10: Feed and Inches Operator Overloads"<<endl;
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
        cin.ignore(256, '\n');
        
        //Switch to determine the Problem
        switch(choice){
            case 10:{prob10();break;}
            case 9:{prob9();break;}
            case 8:{prob8();break;}
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
    }while(choice>=1&&choice<=10);
    
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
void prob10(){
    
    FeetInches first, second;  // Define two objects.

   // Get a distance for the first object.
   cout << "Enter a distance in feet and inches.\n";
   cin >> first;

   // Get a distance for the second object.
   cout << "Enter another distance in feet and inches.\n";
   cin >> second;

   // Display the values in the objects.
   cout << "The values you entered are:\n";
   cout << first << " and " << second << endl;
   
   cout<<"How many iterations to loop for comparing feet/inches objects?"<<endl;
   int tmpVar=0;
   cin>>tmpVar;
   while (cin.fail() || tmpVar<1) {
       cout<<"Enter an integer please!"<<endl;
       cin.clear();
       cin.ignore(256, '\n');
       cin>>tmpVar;
   } 
   for (int i=0;i<tmpVar;i++) {
       first.setFeet(0);
       first.setInches(rand()%17+1);
       second.setFeet(0);
       second.setInches(rand()%17+1);
       cout<<"Round "<<i+1<<"!"<<endl;
       cout<<first<<" ***** "<<second<<endl;
       if (first>=second) cout<<first<<" is >= "<<second<<endl;
       if (first<=second) cout<<first<<" is <= "<<second<<endl;
       if (first!=second) cout<<first<<" is != "<<second<<endl;
       if (first>second) cout<<first<<" is  > "<<second<<endl;
       if (first<second) cout<<first<<" is  < "<<second<<endl;
       if (first==second) cout<<first<<" is == "<<second<<endl;
       cout<<endl;
   }
   cout<<endl;
    //Exit stage right! - This is the 'return 0' call
}

void prob9(){
    //Declare Variables
    int mNum=0;
    string mName="";
    MthCls7 month;
    
    //Input values
    cout<<"Enter the month as a value from 1 to 12: "<<endl;
    cin>>mNum;
    while (cin.fail() || mNum<1 || mNum>12) {
        cout<<"Error! Enter a number from 1 - 12!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>mNum;
    }
    
    cout<<"Enter the month as a text value (January, February, etc):"<<endl;
    cin.ignore(256, '\n');
    getline(cin, mName);
    while (badTxt(mName)) {
        cout<<"Not a month! Try again!"<<endl;
        cin.clear();
//        cin.ignore(256, '\n');
        getline(cin, mName);
    }
    
    //Process by mapping inputs to outputs
    cout<<"Setting month info using the integer "<<mNum<<" as the month."<<endl;
    month.setData(mNum); //Set class data with the month integer input earlier
    cout<<month<<endl; //output with overloaded cout
    cout<<"Incrementing with month++"<<endl;
    month++; //test month++ overload * 
    cout<<month<<endl;
    cout<<"Incrementing with ++month"<<endl;
    ++month; //test ++month overload
    cout<<month<<endl;
    cout<<"Decrementing with month--"<<endl;
    month--;
    cout<<month<<endl;
    cout<<"Decrementing with --month"<<endl;
    --month;
    cout<<month<<endl<<endl;
    cout<<"Resetting values with the input: "<<mName<<" input as a text value."<<endl;
    month.setData(mName);
    cout<<month<<endl;
    cout<<"Incrementing with month++"<<endl;
    month++;
    cout<<month<<endl;
    cout<<"Incrementing with ++month"<<endl;
    ++month;
    cout<<month<<endl;
    cout<<"Decrementing with month--"<<endl;
    month--;
    cout<<month<<endl;
    cout<<"Decrementing with --month"<<endl;
    --month;
    cout<<month<<endl<<endl;
    
    cout<<"Enter the month using direct cin:"<<endl;
    cin>>month;
    while (cin.fail() || month.getNumb()<1 || month.getNumb()>12) {
        cout<<"Enter a month number from 1 to 12!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>month;
    }
    cout<<month<<endl;
    cout<<"Incrementing with month++"<<endl;
    cout<<month++<<endl;
    cout<<"Incrementing with ++month"<<endl;
    cout<<++month<<endl;
    cout<<"Decrementing with month--"<<endl;
    cout<<month--<<endl;
    cout<<"Decrementing with --month"<<endl;
    cout<<--month<<endl;
    cout<<"Outputting plain old month"<<endl;
    cout<<month<<endl;
    
    //Output values
    
    
    //Clean up memory
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob8(){
    //Declare Variables
    unsigned short day;
    string month="";
    
    //Input Values
    cout<<"Enter the month (January, February, etc):"<<endl;
    getline(cin, month);
    cout<<"Enter the day of the month:"<<endl;
    cin>>day; //input number to convert to day
    while (cin.fail()) {
        cout<<"Error! Enter a positive number!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>day;
    }
    
    //Process by mapping inputs to outputs
    DayYer2 date(month, day); //create object 
    if (!date.getValid()) {
        cout<<date.pStatus()<<endl;
        cout<<date.pMonDay()<<endl;
        exit(0); //The question specified this! Terminate program after reporting bad input
    }
    
    //Output values
    cout<<"That is day: "<<date.pStatus()<<endl;
    cout<<"Date is: "<<date.pMonDay()<<endl<<endl;
    date++;
    cout<<"After date++ number: "<<date.pStatus()<<endl;
    cout<<"After date++ is: "<<date.pMonDay()<<endl<<endl;
    ++date; 
    cout<<"After ++date number: "<<date.pStatus()<<endl;
    cout<<"After ++date is: "<<date.pMonDay()<<endl<<endl;
    date--;
    cout<<"After date-- number: "<<date.pStatus()<<endl;
    cout<<"After date-- is: "<<date.pMonDay()<<endl<<endl;
    --date; 
    cout<<"After --date number: "<<date.pStatus()<<endl;
    cout<<"After --date is: "<<date.pMonDay()<<endl<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob7(){ 
    //Declare Variables
    unsigned short number;
    
    //Input Values
    cout<<"Enter a number from 1 to 365"<<endl;
    cin>>number; //input number to convert to day
    while (cin.fail() || number<1 || number>365) {
        cout<<"Error! Enter correct input!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>number;
    }
    
    //Process by mapping inputs to outputs
    DayYear date(number); //create object 
    
    
    //Output values
    cout<<date.print()<<endl; //output conversion
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob6(){
    //Declare Variables
    int conNum; 
    string numText="";
    //Input data on the company
    
    cout<<"Enter the number to convert to text (0 to 9999): "<<endl;
    cin>>conNum;
    while (cin.fail() || conNum<0 || conNum>9999){ //validate data type and range
        cout<<"Entry not valid! Enter a number from 0 to 9999!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>conNum;
    }
    
    TxtNum a(conNum);
    
    //Process the data
    numText = a.txtVal();
    //Outputs
    cout<<"The text returned for "<<a.getNum()<<" is: "<<numText<<endl;
    
    //Clean up memory
    
    //Exit stage right!
    //Exit stage right! - This is the 'return 0' call
}

void prob5(){
    //Declare Variables
    Tests scores; //create object
    
    //Input Values 
    scores.setTest(); //check score values
    //Process by mapping inputs to outputs
    cout<<"The average is: "<<scores.avgTest()<<endl; //output average
    
    //Output values 
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob4(){
    //Declare Variables
    int size;
    cout<<"Enter the number of entries in the Address Book"<<endl;
    cin>>size; //Enter size of the address book
    cin.ignore();
    AddBook *book = new AddBook[size]; //initialize dynamic array 
    
    //Input Values for make and year
    for (int i=0;i<size;i++) { //loop to enter address book data
        cout<<"Enter information for entry "<<i+1<<endl;
        book[i].setData();
    }
    //Process by mapping inputs to outputs
    
    //Output values 
    for (int i=0;i<size;i++) { //loop to display address book data
        cout<<"Contact info for entry "<<i+1<<endl;
        book[i].disData();
        cout<<endl;
    }
    
    //Clean up memory
    delete [] book;
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob3(){
    //Declare Variables
    int year;
    string make;
    
    //Input Values for make and year
    cout<<"Enter the make: ";
    getline(cin, make);
    cin.ignore(256, '\n');
    cout<<"Enter the year: ";
    cin>>year;
    CarCls car(year, make);
    
    //Process by mapping inputs to outputs
    
    //Output values 
    //call getter member functions to ouptout class data
    cout<<"Your "<<car.getYear()<<" "<<car.getMake()<<" is moving "<<car.getSpd()<<" MPH."<<endl;
    for (int i=0;i<5;i++) {
        car.accel(); //call accel member function
    }
    cout<<endl;
    cout<<"Your car is now traveling at: "<<car.getSpd()<<" MPH."<<endl;
    for (int i=0;i<5;i++) {
        car.decel(); //call decel member function
    }
    cout<<endl;
    cout<<"Your car is now traveling at: "<<car.getSpd()<<" MPH."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob2(){
    //Declare Variables
    Worker Emp1, Emp2, Emp3; //create worker objects
    string a, b, c; //data for input testing methods (experimentation)
    int n; //data for input testing methods (experimentation)
    
    //Input Values
    a="Susan Meyers"; //For testing. Not necessary to do this way.
    n=47899; //For testing. Not necessary to do this way.
    b="Accounting"; //For testing. Not necessary to do this way.
    c="Vice President"; //For testing. Not necessary to do this way.
    Emp1.setVals(a, n, b, c); 
    Emp2.setVals("Mark Jones", 39119, "IT", "Programmer"); //for sake of homework passing literals
    Emp3.setVals("Joy Rogers", 81774, "Manufacturing", "Engineer"); //for sake of homework passing literals
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    cout<<"Employee 1:"<<endl;
    Emp1.dWorker(); //output employee 1 values
    cout<<endl;
    cout<<"Employee 2:"<<endl;
    Emp2.dWorker(); //output employee 2 values
    cout<<endl;
    cout<<"Employee 3:"<<endl;
    Emp3.dWorker(); //output employee 3 values
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob1(){
    //Declare Variables
    P1DtCls today;
    
    //Input Values
    today.sDate(); //Set the date value
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    today.outputs(); //output the dates 
    
    //Clean up memory
    

    //Exit stage right! - This is the 'return 0' call
}

//Function to detect bad or invalid text inputs for month
bool badTxt(string mText) {
    bool retVal=true;
    if (mText=="January" || mText=="Jan" || mText=="january" || mText=="jan") {
        retVal=false;
    } else if (mText=="February" || mText=="Feb" || mText=="february" || mText=="feb") {
        retVal=false;
    } else if (mText=="March" || mText=="Mar" || mText=="march" || mText=="mar") {
        retVal=false;
    } else if (mText=="April" || mText=="Apr" || mText=="april" || mText=="apr") {
        retVal=false;
    } else if (mText=="May" || mText=="may") {
        retVal=false;
    } else if (mText=="June" || mText=="Jun" || mText=="june" || mText=="jun") {
        retVal=false;
    } else if (mText=="July" || mText=="Jul" || mText=="july" || mText=="jul") {
        retVal=false;
    } else if (mText=="August" || mText=="Aug" || mText=="august" || mText=="aug") {
        retVal=false;
    } else if (mText=="September" || mText=="Sept" || mText=="september" || mText=="sept" || mText=="Sep" || mText=="sep") {
        retVal=false;
    } else if (mText=="October" || mText=="Oct" || mText=="october" || mText=="oct") {
        retVal=false;
    } else if (mText=="November" || mText=="Nov" || mText=="november" || mText=="nov") {
        retVal=false;
    } else if (mText=="December" || mText=="Dec" || mText=="december" || mText=="dec") {
        retVal=false;
    } else {
        retVal=true;
    }
    return retVal;
}