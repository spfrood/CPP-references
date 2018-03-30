/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 18, 2017, 10:35 AM
  Final Version on January 25, 2017, 11:35 AM
  Purpose:  Statistics for Craps version 3
 */

//System Libraries
#include <iostream>//Input Output library
#include <cstdlib> //Random numbers
#include <ctime>   //Time to set the Seed
#include <fstream> //File stream library
#include <iomanip> //Format Library
using namespace std;//Namespace std of system libraries

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const short PERCENT=100;//Percentage Conversion
const int   MILLION=1e6;//Million
const int   HUNTHSD=1e5;//100,000

//Function Prototypes

//Main -> Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate and Open files
    ifstream in;
    ofstream out;
    in.open("NumberOfGames.dat");
    out.open("ResultsOfGames.dat");
    
    //Declare Variables and Initialize
    unsigned int nGames=100000;//Number of throws for the pair of dice
    unsigned int wins=0,losses=0,maxThrw=0;//Counters/indicators
    unsigned int avgThrw=0;//Average number of Throws per game
    
    //Input the number of games
    //Last line will be number of games from file
    while(in>>nGames);//Loop to end
    nGames=nGames>MILLION?HUNTHSD:nGames;//Limit the number of Games
    
    //Play the game by -> Looping and take Dice statistics
    for(int game=1;game<=nGames;game++){
        //Call random number generator for the dice
        char die1=rand()%6+1;//Value from 1 to 6
        char die2=rand()%6+1;//Value from 1 to 6
        char sum=die1+die2;  //Sum the dice
        avgThrw++;//Increment the average throw counter
        unsigned int cntThrw=1;//Initialize the game throw count
        //Now determine wins or losses
        switch(sum){
            case 2:case 3:case 12:losses++;break;//2,3,12 is a win
            case 7:case 11:wins++;break;         //7,11 is a loss
            //Any other throw requires repetition
            default:{
            bool kpThrw=true;//Initialize the boolean for repeating
                do{
                    die1=rand()%6+1;//Value from 1 to 6
                    die2=rand()%6+1;//Value from 1 to 6
                    avgThrw++;cntThrw++;//Increment counters
                    char sumAgn=die1+die2;//Sum the dice
                    //Record win,loss or repeat
                    if(sumAgn==7){
                        losses++;
                        kpThrw=false;
                    }else if(sumAgn==sum){
                        wins++;
                        kpThrw=false;
                    }
                }while(kpThrw);
            }
        }
        if(maxThrw<cntThrw)maxThrw=cntThrw;//Find max throws
    }
    
    //Output all the statistics to a file
    out<<fixed<<setprecision(2)<<showpoint<<endl;
    out<<"The total number of Crap games played = "<<nGames<<endl;
    out<<"The total wins = "<<wins<<endl;
    out<<"The total losses = "<<losses<<endl;
    out<<"The total number of Crap games played = "<<wins+losses<<endl;
    out<<"Percentage wins = "
            <<static_cast<float>(PERCENT)*wins/nGames<<"%"<<endl;
    out<<"Percentage losses = "
            <<static_cast<float>(PERCENT)*losses/nGames<<"%"<<endl;
    out<<"Average number of throws per game = "
            <<static_cast<float>(avgThrw)/nGames<<endl;
    out<<"Maximum number of throws in a game = "<<maxThrw<<endl;
    
    //Close files and Exit stage right!
    in.close();
    out.close();
    return 0;
}