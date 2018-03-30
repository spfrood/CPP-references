
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 25, 2017, 10:10 PM
 * Purpose: 6. Soccer Scores
Write a program that stores the following data about a soccer player in a 
structure:
Player’s Name
Player’s Number
Points Scored by Player
The program should keep an array of 12 of these structures. Each element is for 
a different player on a team. When the program runs it should ask the user to 
enter the data for each player. It should then show a table that lists each 
player’s number, name, and points scored. The program should also calculate and 
display the total points earned by the team. The number and name of the player 
who has earned the most points should also be displayed.
Input Validation: Do not accept negative values for players’ numbers or points 
scored.
 */

//System Libraries
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries
#include "Pstats.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
string rnNam23(); //function to generate random player name
void filTm24(Pstats [], int); //Function to fill the array data manually
void flRnd25(Pstats [], int); //Function to fill the array data randomly
void tpScr26(Pstats [], int); //Function that prints highest scoring player name and number
void dsTem27(Pstats [], int); //Function to output the entire team roster
int toScr28(Pstats [], int); //Function to return the total points scored

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0))); //set random seed
    
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
    return 0;
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