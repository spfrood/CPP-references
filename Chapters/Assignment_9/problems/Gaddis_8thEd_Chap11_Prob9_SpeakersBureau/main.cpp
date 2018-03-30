
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 25, 2017, 10:39 AM
 * Purpose: 9. Speakers’ Bureau
Write a program that keeps track of a speakers’ bureau. The program should use a 
structure to store the following data about a speaker:
Name
Telephone Number 
Speaking Topic 
Fee Required
The program should use an array of at least 10 structures. It should let the user 
enter data into the array, change the contents of any element, and display all 
the data stored in the array. The program should have a menu-driven user interface.
Input Validation: When the data for a new speaker is entered, be sure the user 
enters data for all the fields. No negative amounts should be entered for a 
speaker’s fee.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
#include "Speaker.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void enDat29(Speaker *, int); //Function to enter data into array
void dsDat30(Speaker *, int); //Function to print out the array
void edDat31(Speaker *, int); //function to edit an array element


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
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
    return 0;
}

//Function to enter data into array
void enDat29(Speaker *list, int size){
    for (int i=0;i<size;i++){
        list[i].spkrNum=i; //assign an ID number to array element
        cout<<"Enter name of speaker number "<<list[i].spkrNum<<":"<<endl;
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