/* 
  File:   main.cpp
  Author: Dr. Scott Parker
  Created on March 27, 2017, 2:35 PM
  Purpose:  Assignment 3 Homework Menu
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "MyHeaders.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another and for
//2d array columns

enum Month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, 
             SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER }; //enumerated data type to step through months

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

MonthlyBudget rnBd01(MonthlyBudget); //Randomize budget input data
MonthlyBudget inBd02 (MonthlyBudget); //Input budget spending data manually
void cpBg03(MonthlyBudget, MonthlyBudget); //Compare actual spending to budget
void prBg04(MonthlyBudget); //Output values stored in a MonthlyBudget structure
void shMo05(Movie); //Function to display data in a Movie structure
void shMo06(MovieR); //Function to display data in a Movie structure
void entDa07(DivData &); //function to input the sales data for the DivData structure
void shDiv08(DivData); //function to output the values held in the structure
float avTmp09(TempDat [], int); //function to find the annual average temperature
float totRn10(TempDat [], int); //function to find the total rainfall for the year
void gtTmp11(TempDat [], int); //function to fill data in array
void rnTmp12(TempDat [], int); //function to fill fields randomly
TempDat gtRe13(TempDat [], int, TempDat, int &, int &, int &, int &); //function to get the high/low data
string dMnth14(int); //function to output the month based on an integer input from 0-11 (Jan to Dec)
void dsDat15(TempDat [], int); //Function to print the data values in an array of TempDat
float avTmp16(TempDat [], int); //function to find the annual average temperature
float totRn17(TempDat [], int); //function to find the total rainfall for the year
void gtTmp18(TempDat [], int); //function to fill data in array
void rnTmp19(TempDat [], int); //function to fill fields randomly
TempDat gtRec20(TempDat [], int, TempDat, int &, int &, int &, int &); //function to get the high/low data
string dMon21(int); //function to output the month based on an integer input from 0-11 (Jan to Dec)
void dsDat22(TempDat [], int); //Function to print the data values in an array of TempDat
string rnNam23(); //function to generate random player name
void filTm24(Pstats [], int); //Function to fill the array data manually
void flRnd25(Pstats [], int); //Function to fill the array data randomly
void tpScr26(Pstats [], int); //Function that prints highest scoring player name and number
void dsTem27(Pstats [], int); //Function to output the entire team roster
int toScr28(Pstats [], int); //Function to return the total points scored
void enDat29(Speaker *, int); //Function to enter data into array
void dsDat30(Speaker *, int); //Function to print out the array
void edDat31(Speaker *, int); //function to edit an array element


//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice;
    
    //Loop on the menu
    do{
    
        //Display switch options (menu choise options)
        cout<<"Choose from the list <non-numeric data will be ignored>"<<endl;
        cout<<"Type 1 for Problem 1. Movie Data: "<<endl;
        cout<<"Type 2 for Problem 2. Movie Profit: "<<endl;
        cout<<"Type 3 for Problem 3. Corporate Sales Data: "<<endl;
        cout<<"Type 4 for Problem 4. Weather Statistics: "<<endl;
        cout<<"Type 5 for Problem 5. Weather Statistics Modification: "<<endl;
        cout<<"Type 6 for Problem 6. Soccer Scores "<<endl;
        cout<<"Type 7 for Problem 9. Speakers’ Bureau: "<<endl;
        cout<<"Type 8 for Problem 11. Monthly Budget: "<<endl;
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
//************************ Function for Problem xx  ****************************
//Description: Program for Book, Edition, Chapter, Question, Short Description
//
//Inputs: (what inputs passed to function)
//     
//Outputs:  (what is the output of this function)
//
//******************************************************************************
void prob8(){
    //Declare Variables
    const MonthlyBudget BUDGET = {500.00, 150.00, 65.00, 50.00, 250.00,  //constant to hold projected budget values
                                  30.00, 100.00, 150.00, 75.00, 50.00};
    char chooser='N'; //variable used to make yes/no choices
    MonthlyBudget spnding; //Actual spending to be compared to budget
    
    //Input Values
    cout<<"Randomize data? (Y/y to randomize)"<<endl;
    cin>>chooser; //Randomize the budget if Y or y
    if (chooser=='Y' || chooser=='y') spnding=rnBd01(spnding); //fill with random data if Y
    else spnding=inBd02(spnding); //else enter data manually
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"Budget Allowances: "<<endl;
    prBg04(BUDGET); //Output the budget 
    cout<<endl;
    cout<<"Budget Spending: "<<endl;
    prBg04(spnding); //output the spending
    cout<<endl;
    cout<<"Budget Analysis: "<<endl;
    cpBg03(spnding, BUDGET); //compare spending to budget
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob7(){ 
    //Declare Variables
    int size=0, chooser=0; //size = number of speakers, chooser=menu variable
    Speaker *list=nullptr; //pointer array will be assigned after size entered
    
    //Input Values
    cout<<"Enter number of speakers (minimum of 10)"<<endl;
    cin>>size; //input number of speakers
    while (cin.fail()||size<10){ //validate input type and range
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Must be 10 or more speakers! Enter number of speakers: "<<endl;
        cin>>size; //input number of speakers if type and range were wrong
    }
    list=new Speaker[size]; //create array to hold the speaker's info
    
    
    //Process by mapping inputs to outputs
    
    
    //Menu for options
    do{
        //Output the menu choices
        cout<<"Choose from the list <non-numeric data will be ignored>"<<endl; 
        cout<<"Type 3 to enter Speaker data (for all speakers): "<<endl; //choice 1 enter array data
        cout<<"Type 2 to display all speaker info: "<<endl; //choice 2 print array data
        cout<<"Type 1 to modify a speaker's info: "<<endl; //choice 3 edit array element
        cout<<"Enter 0 (zero) or a number not listed to exit."<<endl;
        cin>>chooser;
        while (cin.fail()) //Loop to validate input
            {
            cout<<"INPUT INVALID! "<<endl;
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter a valid choice!:"<<endl;
            cin>>chooser; //re-enter a valid menu choice
            }
        //Switch to determine the Problem
        switch(chooser){
            case 3:{enDat29(list, size);break;} //for 3 enter data for whole array
            case 2:{dsDat30(list, size);break;} //for 2 display all array data
            case 1:{edDat31(list, size);break;} //for 1 edit single unit of array
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(chooser>=1&&chooser<=3);
    
    //Output values
    
    
    //clean up memory
    delete [] list;
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob6(){
    //Declare Variables
    const int SIZE=12; //size of array
    Pstats team[SIZE]; //array for team data
    char chooser='N'; //variable for choices
    
    //Input Values
    cout<<"Enter the information for each player."<<endl;
    cout<<"Randomize data? (Y/y) to randomize."<<endl;
    cin>>chooser; //Randomize the data or enter manually?
    if (chooser=='y'||chooser=='Y') flRnd25(team, SIZE); //call function to randomize data if this
    else filTm24(team, SIZE); //enter data manually if this
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<endl;
    dsTem27(team, SIZE); //display the array data values
    cout<<endl;
    cout<<"Top scoring player(s): "<<endl;
    tpScr26(team, SIZE); //display top scoring players
    cout<<endl;
    cout<<"Total points scored by team: "<<toScr28(team, SIZE)<<endl; //output total points scored
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob5(){
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
        rnTmp19(months, SIZE); //choice was entered to Randomize all data - call randomize function
    } else gtTmp18(months, SIZE); //choice entered to get all data manually - call input function
    
    //Process by mapping inputs to outputs
    finals=gtRec20(months, SIZE, finals, hiMnth, lowMnth, rfMnth, atMnth); //find the highs, lows, etc, by calling function
    
    //Output values
    dsDat22(months, SIZE);
    cout<<setprecision(2)<<fixed;
    cout<<"High, low, and averages were: "<<endl; 
    cout<<"Highest Temp: "<<finals.hiTemp<<" occured in "<<dMon21(hiMnth)<<endl; //output month and highest temp
    cout<<"Lowest Temp:  "<<finals.lowTemp<<" occured in "<<dMon21(lowMnth)<<endl; //output month and lowest temp
    cout<<"Highest Avg Temp: "<<finals.avgTemp<<" occured in "<<dMon21(atMnth)<<endl; //output month and highest avg temp
    cout<<"The annual average temp was: "<<avTmp16(months, SIZE)<<endl; //output average monthly temp
    cout<<"Most Rainfall: "<<finals.totRain<<"inches occured in "<<dMon21(rfMnth)<<endl; //output month and highest rainfall
    cout<<"The average rainfall was: "<<totRn17(months, SIZE)<<endl; //output average monthly rainfall
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob4(){
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
    //Exit stage right! - This is the 'return 0' call
    
}

void prob3(){
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
    //Exit stage right! - This is the 'return 0' call
    
}

void prob2(){
    //Declare Variables
    MovieR movie1 = {"Blockbuster Movie One", "Alan Smythe", 1991, 175, 1653000, 24500000}; //Movie structure filled with data
    MovieR movie2 = {"Flopbuster Move Two point Three", "Bert Twythe", 2004, 88, 4555000, 3352000}; //Movie structure filled with data
    
    //Input Values
    
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    shMo06(movie1); //Call function to output structure data values
    shMo06(movie2); //Call function to output structure data values
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob1(){
    //Declare Variables
    Movie movie1 = {"Blockbuster Movie One", "Alan Smythe", 1991, 175}; //Movie structure filled with data
    Movie movie2 = {"Flopbuster Move Two point Three", "Bert Twythe", 2004, 88}; //Movie structure filled with data
    
    //Input Values
    
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    shMo05(movie1); //Call function to output structure data values
    shMo05(movie2); //Call function to output structure data values
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

//Function to enter data into array
void enDat29(Speaker *list, int size){
    for (int i=0;i<size;i++){
        list[i].spkrNum=i; //assign an ID number to array element
        cout<<"Enter name of speaker key number "<<list[i].spkrNum<<":"<<endl;
        cin.ignore(256, '\n');
        getline(cin, list[i].name); //enter the name of the array element
        while (list[i].name.size()<1){ //validate data 
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Enter a name! "<<endl;
            getline(cin, list[i].name); //re-enter data if invalid
        }
        cout<<"Enter "<<list[i].name<<"'s telephone number: "<<endl;
        getline(cin, list[i].telNum); //enter the telephone number of array element
        while (list[i].telNum.size()<1){ //validate data 
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Enter a telephone number! "<<endl;
            getline(cin, list[i].telNum); //re-enter data if invalid
        }
        cout<<"Enter the topic "<<list[i].name<<" will speak about: "<<endl;
        getline(cin, list[i].topic); //enter speaking topic of array element
        while (list[i].topic.size()<1){ //validate data
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Enter a topic! "<<endl;
            getline(cin, list[i].topic); //re-enter data if invalid
        }
        cout<<"Enter "<<list[i].name<<"'s minimum engagement fee: "<<endl;
        cin>>list[i].minFee; //inter speaking fee of array element
        while (cin.fail()||(list[i].minFee)<0){ //validate data 
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Enter a positive integer as the minimum fee!"<<endl;
            cin>>list[i].minFee; //re-enter data if invalid or out of range
        }
    }
    cout<<endl;
}

//Function to print out the array
void dsDat30(Speaker *list, int size){
    cout<<setw(6)<<left<<"ID #"<<setw(20)<<left<<"Name"<<setw(18)<<left<<"Telephone"
            <<setw(20)<<left<<"Topic"<<setw(8)<<right<<"Min Fee"<<endl; //Output the topic headers (array element details)
    for (int i=0;i<size;i++){ //Loop through array to output the contents
        cout<<setw(6)<<left<<list[i].spkrNum<<setw(20)<<left<<list[i].name<<setw(18)<<left<<list[i].telNum
                <<setw(20)<<left<<list[i].topic<<setw(8)<<right<<list[i].minFee<<endl;
    }
    cout<<endl;
}

//function to edit an array element
void edDat31(Speaker *list, int size){
    int edit=0;
    cout<<setw(6)<<left<<"ID #"<<setw(20)<<left<<"Name"<<setw(18)<<left<<"Telephone"
            <<setw(20)<<left<<"Topic"<<setw(8)<<right<<"Min Fee"<<endl; //Output the topic headers (array element details)
    for (int i=0;i<size;i++){ //Loop through array to output the contents
        cout<<setw(6)<<left<<list[i].spkrNum<<setw(20)<<left<<list[i].name<<setw(18)<<left<<list[i].telNum
                <<setw(20)<<left<<list[i].topic<<setw(8)<<right<<list[i].minFee<<endl;
    }
    cout<<"Which entry would you like to edit (ID #)?"<<endl;
    cin>>edit; //enter array element to edit
    while (cin.fail()||edit>=size){ //validate data for type and range
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Please enter a valid ID # to edit!"<<endl;
        cin>>edit; //re-enter if not valid type or range
    }
    cout<<"Enter new name for: "<<list[edit].name<<endl;
    cin.ignore(256, '\n');
    getline(cin, list[edit].name); //enter new array element's name
    while (list[edit].name.size()<1){ //validate data for size
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Enter a name! "<<endl;
        getline(cin, list[edit].name); //Re-enter if invalid
    }
    cout<<"Enter a new telephone number for "<<list[edit].name<<":"<<endl;
    getline(cin, list[edit].telNum); //validate data for size
    while (list[edit].telNum.size()<1){ //enter array element's new telephone
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Enter a telephone number! "<<endl;
        getline(cin, list[edit].telNum); //Re-enter if invalid
    }
    cout<<"Enter a new speaking topic for "<<list[edit].name<<":"<<endl;
    getline(cin, list[edit].topic); //Enter array elements new speaking topic
    while (list[edit].telNum.size()<1){ //validate data for size
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Enter a telephone number! "<<endl;
        getline(cin, list[edit].topic); //Re-enter if invalid
    }
    cout<<"Enter a new speaking fee for "<<list[edit].name<<":"<<endl;
    cin>>list[edit].minFee; //input array element's speaking fee
    while (cin.fail()||(list[edit].minFee)<0){ //validate data for type and range
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Enter a positive integer as the minimum fee!"<<endl;
        cin>>list[edit].minFee; //Re-enter if invalid
    }
} 

//Function to return the total points scored
int toScr28(Pstats a[], int size){
    int total=0;
    for (int i=0;i<size;i++){ //loop through the array
        total+=a[i].points; //sum points in each element
    }
    return total; //return the points total
} 

//Function to output the entire team roster
void dsTem27(Pstats a[], int size){
    cout<<"Team Roster"<<endl;
    cout<<setw(17)<<left<<"Name"<<setw(8)<<right<<"Number"<<setw(8)<<right<<"Points"<<endl;
    for (int i=0;i<size;i++){ //loop through array and output elements values each time
        cout<<setw(17)<<left<<a[i].name<<setw(8)<<right<<a[i].number<<setw(8)<<right<<a[i].points<<endl;
    }
}

//Function that returns the total points scored and highest scoring player name and number
void tpScr26(Pstats a[], int size){
    int hiScor=0;
    for (int i=0;i<size;i++){ //loop through array to find highest scoreer
        if (a[i].points>hiScor) hiScor=a[i].points;
    }
    cout<<"Highest Scoring Player(s)"<<endl;
    cout<<setw(17)<<left<<"Name"<<setw(8)<<right<<"Number"<<setw(8)<<right<<"Points"<<endl;
    for (int i=0;i<size;i++){ //output players stats if points equal to highest points scorer
        if (a[i].points==hiScor){
            cout<<setw(17)<<left<<a[i].name<<setw(8)<<right<<a[i].number<<setw(8)<<right<<a[i].points<<endl;
        }
    }
} 

//Function to fill the array data manually
void filTm24(Pstats a[], int size){
    for (int i=0;i<size;i++){ //loop through array elements to fill with data
        cout<<"Enter the player's name: ";
        cin.ignore(256, '\n');
        getline(cin, a[i].name); //Get player's name
        cout<<"Enter "<<a[i].name<<"'s number: ";
        cin>>a[i].number; //Input player's number
        while (cin.fail()||a[i].number<0){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Enter a number greater than zero! Player Number: ";
            cin>>a[i].number;
        }
        cout<<"Enter the points scored by "<<a[i].name<<": ";
        cin>>a[i].points; //input points scored by player
        while (cin.fail()||a[i].points<0){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Enter a number greater than zero! Points Scored: ";
            cin>>a[i].points;
        }
    }
}

//Function to fill the array data randomly
void flRnd25(Pstats a[], int size){
    for (int i=0;i<size;i++){
        a[i].number=i+1; //Assign player number
        a[i].name=rnNam23(); //Assign a random name
        a[i].points=rand()%10; //assign random number of points scored
    }
}

//Function to generate a random player name and return it 
string rnNam23(){
    string name="";
    char temp='\n';
    int length=rand()%3+2; //Determine length of name
    temp=rand()%26+65; //Get a capital letter for first name first letter
    name+=temp; //Assign first letter of first name
    for (int i=0;i<length;i++){ //Fill first name with letters
        temp=rand()%26+97;
        name+=temp;
    }
    name+=" ";
    length=rand()%3+3;
    temp=rand()%26+65; //Get a capital letter for last name first letter
    name+=temp; //assign first letter of last name
    for (int i=0;i<length;i++){ //fill last name with letters
        temp=rand()%26+97;
        name+=temp;
    }
    return name;
}

//function to find the annual average temperature
float avTmp16(TempDat a[], int size){ 
    float temp=0;
    for (int i=JANUARY;i<=DECEMBER;i++){ //for loop to total avg temps
        temp+=a[i].avgTemp; 
    }
    return (temp/12.0f); //return the average temp
} 

//function to find the total rainfall for the year
float totRn17(TempDat a[], int size){
    float temp=0;
    for (int i=JANUARY;i<=DECEMBER;i++){ //for loop to total rainfall
        temp+=a[i].totRain;
    }
    return temp; //return total rainfall
}

//Function to print the data values in an array of TempDat
void dsDat22(TempDat a[], int size){
    cout<<setprecision(2)<<fixed; //Formatting and headers output
    cout<<setw(15)<<left<<"Month"<<setw(12)<<right<<"High Temp"<<setw(12)<<right<<"Low Temp"
            <<setw(12)<<right<<"Rain Inches"<<setw(12)<<right<<"Avg Temp"<<endl;
    for (int i=JANUARY;i<=DECEMBER;i++){ //for loop to output the data from each month
        cout<<setw(15)<<left<<dMon21(i)<<setw(12)<<right<<a[i].hiTemp<<setw(12)<<right<<a[i].lowTemp
            <<setw(12)<<right<<a[i].totRain<<setw(12)<<right<<a[i].avgTemp<<endl;
    }
}

//function to get the high/low data
TempDat gtRec20(TempDat a[], int size, TempDat b, int &htMnth, int &ltMnth, int &rfMnth, int &atMnth){
    for (int i=JANUARY;i<=DECEMBER;i++){ //for loop to find highs and lows
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
void rnTmp19(TempDat a[], int size){
    for (int i=JANUARY;i<=DECEMBER;i++){ //for loop to fill data values
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
void gtTmp18(TempDat a[], int size){
    for (int i=JANUARY;i<=DECEMBER;i++){ //for loop to input all data
        cout<<"Enter the rainfall (in inches) for "<< dMon21(i) <<":"<<endl;
        cin>>a[i].totRain; //input the total rain data
        while (cin.fail()){ //validate the input
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Try Again! Enter the inches of rain!"<<endl;
            cin>>a[i].totRain;
        }
        cout<<"Enter highest temp for "<<dMon21(i)<<":"<<endl; //output current month and data to be input
        cin>>a[i].hiTemp; //input highest temp for current month
        cout<<"Enter lowest temp for "<<dMon21(i)<<":"<<endl; //output current month and data to be input
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
            cout<<"Enter highest temp for "<<dMon21(i)<<":"<<endl;
            cin>>a[i].hiTemp; //re-enter high temp for current month
            cout<<"Enter lowest temp for "<<dMon21(i)<<":"<<endl;
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
string dMon21(int month){
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

//Function to display data stored in a Movie structure
void shMo06(MovieR a){
    cout<<"Movie Information"<<endl; 
    cout<<setw(22)<<left; //format output
    cout<<"Title: "; //output data label for field value (what is stored in the data)
    cout<<a.title<<endl; //output the data value in the structure element
    cout<<setw(22)<<left;//format output
    cout<<"Director: ";//output data label for field value (what is stored in the data)
    cout<<a.direct<<endl;//output the data value in the structure element
    cout<<setw(22)<<left;//format output
    cout<<"Release Date: ";//output data label for field value (what is stored in the data)
    cout<<a.relDate<<endl;//output the data value in the structure element
    cout<<setw(22)<<left;//format output
    cout<<"Running Time: ";//output data label for field value (what is stored in the data)
    cout<<a.runTime<<" minutes."<<endl;//output the data value in the structure element
    cout<<setw(22)<<left;
    cout<<"Fist Year Earnings: "<<"$"<<(a.relEarn)-(a.proCost)<<endl; //Output the (earnings minus cost) = (profit)
    cout<<endl;
}

//Function to display data stored in a Movie structure
void shMo05(Movie a){
    cout<<"Movie Information"<<endl; 
    cout<<setw(20)<<left; //format output
    cout<<"Title: "; //output data label for field value (what is stored in the data)
    cout<<a.title<<endl; //output the data value in the structure element
    cout<<setw(20)<<left;//format output
    cout<<"Director: ";//output data label for field value (what is stored in the data)
    cout<<a.direct<<endl;//output the data value in the structure element
    cout<<setw(20)<<left;//format output
    cout<<"Release Date: ";//output data label for field value (what is stored in the data)
    cout<<a.relDate<<endl;//output the data value in the structure element
    cout<<setw(20)<<left;//format output
    cout<<"Running Time: ";//output data label for field value (what is stored in the data)
    cout<<a.runTime<<" minutes."<<endl;//output the data value in the structure element
    cout<<endl;
}

//Output values stored in a MonthlyBudget structure
void prBg04(MonthlyBudget x){
    cout<<setprecision(2)<<fixed;
    cout<<"Housing: $"<<x.housing<<endl; //output value of housing
    cout<<"Utilities: $"<<x.util<<endl; //output value of Utilities
    cout<<"Household Expenses: $"<<x.housExp<<endl; //output value of Household Expenses
    cout<<"Transportation: $"<<x.transpo<<endl; //output value of Transportation
    cout<<"Food: $"<<x.food<<endl; //output value of Food
    cout<<"Medical: $"<<x.medical<<endl; //output value of Medical
    cout<<"Insurance: $"<<x.insur<<endl; //output value of Insurance
    cout<<"Entertainment: $"<<x.enterta<<endl; //output value of Entertainment
    cout<<"Clothing: $"<<x.cloth<<endl; //output value of Clothing
    cout<<"Miscellaneous: $"<<x.misc<<endl; //output value of Miscellaneous
} 

//Randomize budget input data
MonthlyBudget rnBd01(MonthlyBudget x){
    x.housing=rand()%80000/100.00f; //Housing
    x.util=rand()%20000/100.00f; //Utilities
    x.housExp=rand()%8000/100.00f; //Household Expenses
    x.transpo=rand()%6500/100.00f; //Transportation
    x.food=rand()%30000/100.00f; //Food
    x.medical=rand()%4000/100.00f; //Medical
    x.insur=rand()%12000/100.00f; //Insurance
    x.enterta=rand()%17500/100.00f; //Entertainment
    x.cloth=rand()%9000/100.00f;  //Clothing
    x.misc=rand()%6500/100.00f; //Miscellaneous
    return x;
} 

//Input budget spending data manually
MonthlyBudget inBd02 (MonthlyBudget x){
    cout<<"Enter housing expenses: "<<endl;
    cin>>x.housing; //Housing
    cout<<"Enter utilities expenses: "<<endl;
    cin>>x.util; //Utilities
    cout<<"Enter household expenses: "<<endl;
    cin>>x.housExp; //Household Expenses
    cout<<"Enter transportation expenses: "<<endl;
    cin>>x.transpo; //Transportation
    cout<<"Enter food expenses: "<<endl;
    cin>>x.food; //Food
    cout<<"Enter medical expenses: "<<endl;
    cin>>x.medical; //Medical
    cout<<"Enter insurance expenses: "<<endl;
    cin>>x.insur; //Insurance
    cout<<"Enter entertainment expenses: "<<endl;
    cin>>x.enterta; //Entertainment
    cout<<"Enter clothing expenses: "<<endl;
    cin>>x.cloth;  //Clothing
    cout<<"Enter miscellaneous expenses: "<<endl;
    cin>>x.misc; //Miscellaneous
    return x;
} 

//Compare actual spending to budget
void cpBg03(MonthlyBudget x, MonthlyBudget b){
    float temp=0, totX=0, totBase=0;
    cout<<setprecision(2)<<fixed;
    temp=b.housing-x.housing; //over/under for housing
    if (temp>=0) cout<<"Housing had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Housing had a $"<<temp<<" deficit."<<endl;
    temp=b.util-x.util;
    if (temp>=0) cout<<"Utilities had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Utilities had a $"<<temp<<" deficit."<<endl;
    temp=b.housExp-x.housExp;
    if (temp>=0) cout<<"Household expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Household expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.transpo-x.transpo;
    if (temp>=0) cout<<"Transportation expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Transportation expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.food-x.food;
    if (temp>=0) cout<<"Food expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Food expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.medical-x.medical;
    if (temp>=0) cout<<"Medical expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Medical expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.insur-x.insur;
    if (temp>=0) cout<<"Insurance expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Insurance expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.enterta-x.enterta;
    if (temp>=0) cout<<"Entertainment expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Entertainment expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.cloth-x.cloth;
    if (temp>=0) cout<<"Clothing expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Clothing expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.misc-x.misc;
    if (temp>=0) cout<<"Miscellaneous expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Miscellaneous expenses had a $"<<temp<<" deficit."<<endl;
    totX=x.cloth+x.enterta+x.food+x.housExp+x.housing+x.insur+x.medical+x.misc+x.transpo+x.util; //Total spending
    totBase=b.cloth+b.enterta+b.food+b.housExp+b.housing+b.insur+b.medical+b.misc+b.transpo+b.util; //Budget base allowance
    temp=totBase-totX;
    if (temp>=0) cout<<"Total budget had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if negative
    else cout<<"Total budget had a $"<<temp<<" deficit."<<endl;
}