
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 10:35 AM
 * Purpose: Statistics for Craps
 */

//System Libraries
#include <iostream> //input output libraries
#include <ctime> //time for setting random seed
#include <cstdlib> //random number functions
#include <fstream> //filestream to write to/from files
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const short PERCENT=100; //percentage conversion
const int   MILLION=1e6; //Million
const int   HUNTHSD=1e5; //Hundred Thousand

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random number seed
    srand (static_cast<unsigned int>(time(0)));
    
    //instantiate and open files
    ifstream in;
    ofstream out;
    in.open ("NumberOfGames.dat");
    out.open ("ResultsOfGames.dat");
    
    
    //Declare Variables
    unsigned int nGames=100000; //Number of times to throw pair of dice
    unsigned int wins=0, losses=0, maxThrw=0;
    unsigned int avgThrw=0;
    
    //Input the number of games
    //Last line will be number of games
    while(in>>nGames);
    nGames = nGames > MILLION?HUNTHSD:nGames;
        
    //Loop and take dice statistics
    for (int game=1;game<=nGames;game++){
        //call random number generator for each die
        char die1 = rand()%6+1; //value from 1 to 6
        char die2 = rand()%6+1; //value from 1 to 6
        char sum = die1 + die2;
        avgThrw++;
        unsigned int cntThrw=1;
        //Now determine wins or losses
        switch (sum) {
            case 2:case 3:case 12:losses++;break;
            case 7:case 11:wins++;break;
            default:{
                bool kpThrw=true;
                do{  
                    die1 = rand()%6+1; //value from 1 to 6
                    die2 = rand()%6+1; //value from 1 to 6
                    char sumAgn=die1+die2;
                    cntThrw++; avgThrw++;
                if (sumAgn == 7) {
                    losses++;
                    kpThrw=false;
                }else if (sumAgn==sum){
                    wins++;
                    kpThrw=false;
                    }
                }while(kpThrw);
            }  
        if (cntThrw>maxThrw)maxThrw=cntThrw;
        }  
    }
    //Calculate the average throw
    
    
    //Output values to screen
    cout<<"The total number of crap games played = "<<nGames<<endl;
    cout<<"The total number of wins = "<<wins<<endl;
    cout<<"The total number of losses = "<<losses<<endl;
    cout<<"The total number of Craps games played = "<<wins+losses<<endl;
    cout<<"Percentage of wins = "
            <<static_cast<float>(PERCENT)*wins/nGames<<"%"<<endl;
    cout<<"Percentage of losses = "
            <<static_cast<float>(PERCENT)*losses/nGames<<"%"<<endl;
    cout<<"Average number of throws per game = "
            <<static_cast<float>(avgThrw)/nGames<<endl;
    cout<<"Game with most throws required to win or lose: "<<maxThrw<<endl;
    
    //output values to file
    out<<"The total number of crap games played = "<<nGames<<endl;
    out<<"The total number of wins = "<<wins<<endl;
    out<<"The total number of losses = "<<losses<<endl;
    out<<"The total number of Craps games played = "<<wins+losses<<endl;
    out<<"Percentage of wins = "
            <<static_cast<float>(PERCENT)*wins/nGames<<"%"<<endl;
    out<<"Percentage of losses = "
            <<static_cast<float>(PERCENT)*losses/nGames<<"%"<<endl;
    out<<"Average number of throws per game = "
            <<static_cast<float>(avgThrw)/nGames<<endl;
    out<<"Game with most throws required to win or lose: "<<maxThrw<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    in.close(); //close input file
    out.close(); //close output file
    return 0;
}

