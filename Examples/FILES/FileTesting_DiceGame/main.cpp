/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 18, 2017, 10:35 AM
  Final Version on January 25, 2017, 11:35 AM
  Purpose:  Statistics for Craps version 3
 */

//System Libraries
#include <iostream>//Input Output library
#include <fstream> //File stream library
#include <iomanip> //Format Library
#include <string>  //To work with strings
#include <ctime>   //To set random number seed
#include <cstdlib> //To cast random numbers
using namespace std;//Namespace std of system libraries

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes

//Main -> Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate files
    ifstream in;
    ofstream out;
    in.open("NumberOfGames.dat");
    out.open("ResultsOfGames.dat");
    in.close();
    out.close();
    //Declare Variables
    string perName;
    int bankAmt;
    int gmsPld;
    int numWin;
    int numLoss;
    int numTie;
    int die1;
    int die2;
    char play;
    
    //Input Values
    cout<<"Enter your name"<<endl;
    getline(cin, perName);
    in.open(perName+".dat");
    in>>bankAmt;
    in>>gmsPld;
    in>>numWin;
    in>>numLoss;
    in>>numTie;
    cout<<"Starting Values"<<endl;
    cout<<"Bank Value: "<<bankAmt<<endl;
    cout<<"Games Played "<<gmsPld<<endl;
    cout<<"Number of wins "<<numWin<<endl;
    cout<<"Number of Losses "<<numLoss<<endl;
    cout<<"Number of Ties "<<numTie<<endl;
    
    //Process by mapping inputs to outputs
    do {
    
    die1=rand()%6+1;//Value from 1 to 6
    die2=rand()%6+1;//Value from 1 to 6
    
    if (die1>die2) numWin++;
    if (die2>die1) numLoss++;
    if (die1==die2) numTie++;
    gmsPld++;
    if (die1>die2) bankAmt+=100;
    if (die1<die2) bankAmt-=100;
    cout<<"Bank Value: "<<bankAmt<<endl;
    cout<<"Games Played "<<gmsPld<<endl;
    cout<<"Number of wins "<<numWin<<endl;
    cout<<"Number of Losses "<<numLoss<<endl;
    cout<<"Number of Ties "<<numTie<<endl;
    
    cout<<"Keep Playing? (Y/N)"<<endl;
    cin>>play;
    } while (play=='Y');
    
    //Output all the statistics to a file
    in.close();
    out.open(perName+".dat");
    out<<bankAmt<<endl;
    out<<gmsPld<<endl;
    out<<numWin<<endl;
    out<<numLoss<<endl;
    out<<numTie<<endl;
    out.close();
    cout<<"Bank Value: "<<bankAmt<<endl;
    cout<<"Games Played "<<gmsPld<<endl;
    cout<<"Number of wins "<<numWin<<endl;
    cout<<"Number of Losses "<<numLoss<<endl;
    cout<<"Number of Ties "<<numTie<<endl;
    
    //Close files and Exit stage right!
    return 0;
}