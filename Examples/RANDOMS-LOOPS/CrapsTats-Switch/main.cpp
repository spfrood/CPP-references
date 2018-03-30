
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
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random number seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned int nGames=100000; //Number of times to throw pair of dice
    unsigned int wins=0, losses=0, maxThrw=0;
    unsigned int avgThrw=0;
    
    //Loop and take dice statistics
    for (int game=1;game<=nGames;game++){
        //call random number generator for each die
        char die1 = rand()%6+1; //value from 1 to 6
        char die2 = rand()%6+1; //value from 1 to 6
        char sum = die1 + die2;
        unsigned int cntThrw=1;
        avgThrw++;
        //Now determine wins or losses
        switch (sum){
            case 2:case 3:case 12:losses++;break;
            case 7:case 11:wins++;break;
            default:{
            bool kpThrw=true;
                do{
                    die1 = rand()%6+1; //value from 1 to 6
                    die2 = rand()%6+1; //value from 1 to 6
                    char sumAgn=die1+die2;
                    cntThrw++;
                    avgThrw++;
                    if (sumAgn == 7) {
                        losses++;
                        kpThrw=false;
                    }else if (sumAgn==sum){
                        wins++;
                        kpThrw=false;
                    }
                }while(kpThrw);
            }
        }
        if (cntThrw>maxThrw)maxThrw=cntThrw;
    }
    
    //Calculate the average throw
    
    
    //Output values
    cout<<"The total number of crap games played = "<<nGames<<endl;
    cout<<"The total number of wins = "<<wins<<endl;
    cout<<"The total number of losses = "<<losses<<endl;
    cout<<"The total number of Craps games played = "<<wins+losses<<endl;
    cout<<"Percentage of wins = "<<100.0f*wins/nGames<<endl;
    cout<<"Percengage of losses = "<<100.0f*losses/nGames<<endl;
    cout<<"Average number of throws per game = "
            <<static_cast<float>(avgThrw)/nGames<<endl;
    cout<<"Game with most throws required to win or lose: "<<maxThrw<<endl;
    
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

