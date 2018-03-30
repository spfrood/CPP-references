
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 28, 2017, 2:30 PM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <iostream> //cin, cout, basic math, etc
#include <ctime> //used to set random seed to spin roulette wheel
#include <cstdlib> //used for the random number function to play roulette
#include <fstream> //used to input/output player records
#include <string> //Used for player name (in conjunction with fstream)
#include <iomanip> //used to format output to be like currency
#include <cmath> //This program really doesn't use CMATH but it's here for 
                 //the grade. SQRT and POW at end of program. Otherwise unused.
using namespace std;

//Unsure if the following will work on WINDOWS machines. Test in class before
//submitting project.
#define C_RED     "\x1b[31m"  //For red text
#define C_GREEN   "\x1b[32m"  //for green text
#define C_CYAN    "\x1b[36m"  //for cyan text
#define C_RESET   "\x1b[0m"   //rest color to black

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const int ODDSNUM = 35; //Odds payout for betting single number
const int ODDODD = 1; //Odds payout for betting ODD numbers
const int ODDEVEN = 1; //Odds payout for betting EVEN numbers
const int ODDBLCK = 1; //Odds payout for betting BLACK numbers
const int ODDRED = 1; //Odds payout for betting RED
const int ODDTOPH = 1; //Odds payout for betting TOP HALF of field (1-18)
const int ODDBOTH = 1; //Odds payout for betting BOTTOM HALF of field (19-36)
const int ODDFSTT = 2; //Odds payout for betting FIRST THRID of field (1-12)
const int ODDSNDT = 2; //Odds payout for betting SECOND THIRD of field (13-24)
const int ODDTRDT = 2; //Odds payout for betting THIRD THIRD of field (25-36)
const int CONVBET = -1; //To convert a bet amount into negative number (loss)

//Function Prototypes (for returning the amounts of the bets)
float sNumWin(float, int, int); //returning value of single number win
float oddWin(float, int); //return value of win betting ODD
float evenWin(float, int); //return value of win betting EVEN
float blckWin(float, int); //return value of win betting BLACK
float redWin(float, int); //return value of win betting RED
float topHWin(float, int); //return value of win betting 1-18
float botHWin(float, int); //return value of win betting 19-36
float fstTWin(float, int); //return value of win betting 1-12
float sndTWin(float, int); //return value of win betting 13-24
float trdTWin(float, int); //return value of win betting 25-36

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate files - they are opened and used later
    ifstream in;
    ofstream out;
    
    //Declare Variables

    float betSNUM=0; //betting amount on single number
    float betODD=0; //betting amount on ODD numbers
    float betEVEN=0; //betting amount on EVEN numbers
    float betBLCK=0; //betting amount on BLACK numbers
    float betRED=0; //betting amount on RED
    float betTHLF=0; //betting amount on TOP HALF of field (1-18)
    float betBHLF=0; //betting amount on BOTTOM HALF of field (19-36)
    float betFSTT=0; //betting amount on FIRST THRID of field (1-12)
    float betSNDT=0; //betting amount on SECOND THIRD of field (13-24)
    float betTRDT=0; //betting amount on THIRD THIRD of field (25-36)
    int betNum=99; //set start value of betNum outside spin range
    //These could technically all be unsigned shorts unless the player plays a 
    //LOT of roulette
    int gmsPlyd=0, spinVal=0, spinWin=0, betWin=0, gmsWon=0, gmsLost=0; 
    unsigned short gmsPush=0, resetBK=0, resetL=0, resetW=0, resetBT=0, switMen=0; 
    string playerN;  //player name used in saving stats and loading stats 
    char menuOpt, yesNo;  //menu option choices that get reused
    float bank=100.00, totBet=0.00, totWin=0.00, totLoss=0.00, hiWin=0.00, 
            mostBet=0.00, betSpin=0.00, winPcnt=0.00;  //currency values 
    bool playMor=true; //boolean used in menu choices later on
    
    //Input Values 
    //Displaying instructions for program
    cout<<"Welcome to the CSC5 French Riviera Style Casino Roulette!"<<endl;
    cout<<"Please view the instructions on French style roulette if you"<<endl;
    cout<<"have not seen them before. Would you like to view the"<<endl;
    cout<<"instructions? <enter 'Y' for instructions>"<<endl;
    cin>>yesNo; //Giving option to skip instructions and information
    while (yesNo=='Y'^yesNo=='y'){
        cout<<"European roulette is very similar to American roulette."<<endl;
        cout<<"The main difference is that European roulette only uses"<<endl;
        cout<<"A single '0' rather than '0' and '00' like you will see"<<endl;
        cout<<"on American roulette tables. This means that you have a"<<endl;
        cout<<"better chance of winning when you play European roulette!"<<endl;
        cout<<"(enter a character to continue)"<<endl;
        cin>>yesNo;
        cout<<"To play this roulette game there is no playfield. Instead"<<endl;
        cout<<"you will be offered bets you can make sequentially. If you"<<endl;
        cout<<"would like to place a bet when offered an option just enter"<<endl;
        cout<<"the amount you would like to bet. Otherwise just enter '0'"<<endl;
        cout<<"as the amount you want to bet."<<endl;
        cout<<"<enter a character to continue>"<<endl;
        cin>>yesNo;
        cout<<"Once you have finished placing your bets the dealer will"<<endl;
        cout<<"announce that there are no more bets allowed and will then"<<endl;
        cout<<"spin the wheel. Once the wheel has determined a number the"<<endl;
        cout<<"dealer will process the bets and issue winnings (or claim"<<endl;
        cout<<"the amount you bet if you lose). Good luck and have fun!"<<endl;
        cout<<"And please remember to GAMBLE RESPONSIBLY!"<<endl;
        cout<<"<enter 'Y' or 'y' to repeat, any other character exits>"<<endl;
        cin>>yesNo;
        cout<<endl;
    }
    yesNo='X';
    cout<<"Please enter your name"<<endl;
    cin.ignore();
    getline(cin, playerN); //This will load a data file with the player's name
                           //if such exits. It will then populate the fields based
                           //on previous wins, losses, etc, unless they were reset
    cout<<"Welcome to CSC5 Casino, "<<playerN<<"."<<endl;
    cout<<"Good Luck!"<<endl;
    in.open(playerN+".dat"); //Getting data from player file if available
    in>>gmsPlyd; //total games played
    in>>gmsWon;  //number of games won
    in>>gmsLost; //number of games lost
    in>>gmsPush; //Games with no win or los
    in>>resetBK; //Counter of bank value resets
    in>>resetL; //counter of loss amount resets
    in>>resetW; //counter of win amount resets
    in>>resetBT; //counter of total money bet resets
    in>>bank;  //Amount of money player has 
    in>>totBet; //Total amount player has bet
    in>>totWin; //Total amount player has won
    in>>totLoss; //Total amount player has lost
    in>>mostBet; //THe most the player has ever bet on a single spin
    in>>hiWin; //The most a player has ever won on a single bet
    in.close(); //closing the data file
    if (gmsPlyd>0) { //displaying the players info if it existed previously
        cout<<"Welcome Back "<<playerN<<"!"<<endl;
        cout<<"You have played "<<gmsPlyd<<" so far!"<<endl;
        cout<<"You have won money in "<<gmsWon<<" games so far!"<<endl;
        cout<<"You have lost money in "<<gmsLost<<" games so far!"<<endl;
        cout<<"You neither won or loss in "<<gmsPush<<" games to date."<<endl;
        cout<<"You have been saved from bankruptcy "<<resetBK<<" times so far."<<endl;
        cout<<"This is how many times your bank value has been reset to $-10,000."<<endl;
        cout<<"You have been saved from organ harvesting "<<resetL
                <<" times so far."<<endl;
        cout<<"This is how many times your total losses have been reset to $-10,000."<<endl;
        cout<<"You have been saved from the IRS "<<resetW<<" times so far."<<endl;
        cout<<"This is how many times your winnings have been reset to $10,000."<<endl;
        cout<<"You have been saved from yourself "<<resetBT<<" times so far."<<endl;
        cout<<"This is how often your total money gambled has been reset to $10,000."<<endl;
        cout<<"Your bank currently has $"<<setprecision(2)<<fixed
            <<showpoint<<bank<<" in it."<<endl;
        cout<<"Your total bets are $"<<setprecision(2)<<fixed
            <<showpoint<<totBet<<" as of now."<<endl;
        cout<<"Your winnings come to $"<<setprecision(2)<<fixed
            <<showpoint<<totWin<<" as of now."<<endl;
        cout<<"Your total losses are $"<<setprecision(2)<<fixed
            <<showpoint<<totLoss<<" as of now."<<endl;
        cout<<"$"<<setprecision(2)<<fixed<<showpoint<<mostBet<<" is the most"
                <<" you have ever bet on a game."<<endl;
        cout<<"Your biggest win was $"<<setprecision(2)<<fixed
            <<showpoint<<hiWin<<" on a single game."<<endl;
        cout<<"<enter any character to continue>"<<endl;
        cin>>yesNo;
    }
    yesNo='X';
    //Process by mapping inputs to outputs
    do {
        do { //Drawing the roulette table in ASCII with colors if possible on your machine
            cout<<C_CYAN<<" -----------------------------------------------------"
                <<"--------------------"<<C_CYAN<<endl;
            cout<<C_CYAN<<"|  |"<<C_RED<<" 3r  "<<C_RESET<<C_CYAN<<"|"<<C_RESET
                <<" 6b  "<<C_CYAN<<"|"<<C_RED<<" 9r "<<C_CYAN<<"|"<<C_RED
                <<" 12r "<<C_CYAN<<"|"<<C_RESET<<" 15b "<<C_CYAN<<"|"<<C_RED
                <<" 18r "<<C_CYAN<<"|"<<C_RED<<" 21r "<<C_CYAN<<"|"<<C_RESET
                <<" 24b "<<C_CYAN<<"|"<<C_RED<<" 27r "<<C_CYAN<<"|"<<C_RED
                <<" 30r "<<C_CYAN<<"|"<<C_RESET<<" 33b "<<C_CYAN<<"|"<<C_RED
                <<" 36r "<<C_CYAN<<"|"<<C_RESET<<endl;
            cout<<C_CYAN<<"|  |-------------------------------------------------"
                <<"---------------------|"<<C_CYAN<<endl;
            cout<<C_CYAN<<"|"<<C_GREEN<<"0g"<<C_CYAN<<"|"<<C_RESET<<" 2b  "<<C_CYAN
                <<"|"<<C_RED<<" 5r  "<<C_CYAN<<"|"<<C_RESET<<" 8b "<<C_CYAN
                <<"|"<<C_RESET<<" 11b"<<C_CYAN<<" |"<<C_RED<<" 14r "<<C_CYAN
                <<"|"<<C_RESET<<" 17b "<<C_CYAN<<"|"<<C_RESET<<" 20b "<<C_CYAN
                <<"|"<<C_RED<<" 23r "<<C_RESET<<"| 26b | 29b |"<<C_RED<<" 32r "
                <<C_RESET<<"| 35b |"<<endl;
            cout<<C_CYAN<<"|  |--------------------------------------------------"
                <<"--------------------|"<<C_CYAN<<endl;
            cout<<C_CYAN<<"|  |"<<C_RED<<" 1r  "<<C_RESET<<"| 4b  |"<<C_RED<<" 7r "
                <<C_RESET<<"| 10b | 13b |"<<C_RED<<" 16r "<<C_RESET<<"|"<<C_RED
                <<" 19r "<<C_CYAN<<"|"<<C_RESET<<" 22b "<<C_CYAN<<"|"<<C_RED
                <<" 25r "<<C_CYAN<<"|"<<C_RESET<<" 28b "<<C_CYAN<<"|"<<C_RESET
                <<" 31b "<<C_CYAN<<"|"<<C_RED<<" 34r "<<C_CYAN<<"|"<<C_RESET
                <<endl;
            cout<<C_CYAN<<" ---------------------------------------------------"
                <<"---------------------- "<<C_CYAN<<endl;
            cout<<C_CYAN<<"   |     First Third      |      Second Third     |     "
                <<"Third  Third     |"<<endl;
            cout<<C_CYAN<<"    ---------------------- ----------------------- ----"
                <<"------------------- "<<C_CYAN<<endl;
            cout<<C_CYAN<<"   |  1 to 18  |   EVEN   |"<<C_RED<<"    RED    "
                <<C_CYAN<<"|"<<C_RESET<<"   BLACK   "<<C_CYAN<<"|    ODD   "
                <<"| 19 to 36  |"<<C_RESET<<endl;
            cout<<C_CYAN<<"    -------------------------------------------------"
                <<"---------------------"<<C_RESET<<endl;
            cout<<endl;
            cout<<"You have $"<<setprecision(2)<<fixed
                <<showpoint<<bank<<" in your bank."<<endl<<endl;
        //This is the betting options. Displayed for player to choose bet type
            cout<<"Choose from the list to place your bet:"<<endl;
            cout<<"Please note: Subsequent bets for same type will overwrite."<<endl;
            cout<<"Type 1 to bet a single number (Only one bet accepted)"<<endl;
            cout<<"Type 2 to bet on ODD numbers"<<endl;
            cout<<"Type 3 to bet on EVEN numbers"<<endl;
            cout<<"Type 4 to bet on RED numbers"<<endl;
            cout<<"Type 5 to bet on BLACK numbers"<<endl;
            cout<<"Type 6 to bet on Top Half of field (1-18)"<<endl;
            cout<<"Type 7 to bet on Bottom Half of field (19-36)"<<endl;
            cout<<"Type 8 to bet on Top Third of field (1-12)"<<endl;
            cout<<"Type 9 to bet on Second Third of field (13-24)"<<endl;
            cout<<"Type 10 to bet on Third Third of field (25-36)"<<endl;
            cout<<"enter 0 to exit"<<endl;
            cin>>switMen;
            //Switch menu to place the bets of each type
            switch(switMen){
                case 10:{ //betting THIRD THIRD of field (25-36)
                    cout<<"Enter the amount you would like to bet on THIRD 25-36?"<<endl;
                    cin>>betTRDT;break;}
            
                case 9:{ //betting SECOND THIRD of field (13-24)
                    cout<<"Enter the amount you would like to bet on THIRD 13-24?"<<endl;
                    cin>>betSNDT;break;}
            
                case 8:{ //betting FIRST THRID of field (1-12)
                    cout<<"Enter the amount you would like to bet on THIRD 1-12?"<<endl;
                    cin>>betFSTT;break;}
            
                case 7:{ //betting BOTTOM HALF of field (19-36)
                    cout<<"Enter the amount you would like to bet on HALF 19-36?"<<endl;
                    cin>>betBHLF;break;}
            
                case 6:{ //betting TOP HALF of field (1-18)
                    cout<<"Enter the amount you would like to bet on HALF 1-18?"<<endl;
                    cin>>betTHLF;break;}
            
                case 5:{ //betting BLACK numbers
                   cout<<"Enter the amount you would like to bet on BLACK?"<<endl;
                   cin>>betBLCK;break;}
            
                case 4:{//betting RED
                    cout<<"Enter the amount you would like to bet on RED?"<<endl;
                    cin>>betRED;break;}
        
                case 3:{//betting EVEN numbers
                    cout<<"Enter the amount you would like to bet on EVEN?"<<endl;
                    cin>>betEVEN;break;}
            
                case 2:{ //betting ODD numbers
                    cout<<"Enter the amount you would like to bet on ODD?"<<endl;
                    cin>>betODD;break;}
            
                case 1:{ //Info for betting a single number on the wheel
                    do{
                        cout<<"What number would you like to bet on?"<<endl;
                        cin>>betNum; //getting the number to bet on
                        if (betNum<0^betNum>36) { //making sure number in range of wheel
                            cout<<"That number isn't an option for roulette bets!"
                                <<"Choose another number between 0 and 36!"<<endl;
                        }
                    } while (betNum<0^betNum>36);  //Keep doing until number in valid range
                    cout<<"How much do you want to bet on "<<betNum<<"?"<<endl;
                    cin>>betSNUM;break;}
                case 0: cout<<"All finished betting?"<<endl;break;
                default:
                    cout<<"You entered an invalid choice!"<<endl;
            }       
        cout<<"Do you want to place another bet?"<<endl;
        cin>>yesNo;
        } while (yesNo=='Y'^yesNo=='y');
        yesNo='X'; //always reset to unused value after an input is done being used
        
        cout<<"Betting is now closed. No more bets! No more bets!"<<endl;
        cout<<"Round and round and round she goes, where she stops, "<<endl;
        cout<<"nobody knows!"<<endl;
        spinVal=rand()%37; //random value from 0 to 36 for roulette wheel spin
        cout<<"And the ball came to rest on "<<spinVal<<endl;
        cout<<"Lets see if we have any winners..."<<endl;
        //Editing player data. No reason really other than to do it and have an
        //excuse to increment counters.
        if (bank<=-1.0e6) {
            cout<<"Your bank value is too low!"<<endl;
            cout<<"Reducing your debt to $10,000."<<endl;
            bank=-1.0e4;
            resetBK++;
        }
        if (totLoss<=-1.0e6) {
            cout<<"Your total losses are too larget!"<<endl;
            cout<<"Reducing your total losses to $10,000."<<endl;
            totLoss=-1.0e4;
            resetL++;
        }
        if (totWin>=5.0e6) {
            cout<<"Your total wins are getting too high!"<<endl;
            cout<<"Reducing total winnings to $10,000."<<endl;
            totWin=1.0e4;
            resetW++;
        }
        if (totBet>=5.0e6) {
            cout<<"Your total bets are getting a little too high!"<<endl;
            cout<<"Reducing total bets to $10,000."<<endl;
            totBet=1.0e4;
            resetBT++;
        }
        
        //Find win or loss for single number bet
        betWin=sNumWin(betSNUM, betNum, spinVal); 
        betSpin+=betSNUM;  //Increment with every bet amount
        spinWin+=betWin;  
        if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
        betWin=0; //reset the win variable for this bet to zero.
        
        //Find win or loss for ODD bet
        betWin=oddWin(betODD, spinVal);
        betSpin+=betODD;  //Increment with every bet amount
        spinWin+=betWin;  
        if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
        betWin=0; //reset the win variable for this bet to zero.
        
        //Find win or loss for EVEN bet
        betWin=evenWin(betEVEN, spinVal);
        betSpin+=betEVEN;  //Increment with every bet amount
        spinWin+=betWin;  
        if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
        betWin=0; //reset the win variable for this bet to zero.
        
        //Find win or loss for BLACK bet
        betWin=blckWin(betBLCK, spinVal);
        betSpin+=betBLCK;  //Increment with every bet amount
        spinWin+=betWin;  
        if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
        betWin=0; //reset the win variable for this bet to zero.
        
        //Find win or loss for RED bet
        betWin=redWin(betRED, spinVal);
        betSpin+=betRED;  //Increment with every bet amount
        spinWin+=betWin;  
        if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
        betWin=0; //reset the win variable for this bet to zero.
        
        //Find win or loss for TOP HALF (1-18) bet
        betWin=topHWin(betTHLF, spinVal);
        betSpin+=betTHLF;  //Increment with every bet amount
        spinWin+=betWin;  
        if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
        betWin=0; //reset the win variable for this bet to zero.
        
        //Find win or loss for BOTTOM HALF (19-36) bet
        betWin=botHWin(betBHLF, spinVal);
        betSpin+=betBHLF;  //Increment with every bet amount
        spinWin+=betWin;  
        if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
        betWin=0; //reset the win variable for this bet to zero.
        
        //Find win or loss for FIRST THIRD (1-12) bet
        betWin=fstTWin(betFSTT, spinVal);
        betSpin+=betFSTT;  //Increment with every bet amount
        spinWin+=betWin;  
        if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
        betWin=0; //reset the win variable for this bet to zero.
        
        //Find win or loss for SECOND THIRD (13-24) bet
        betWin=sndTWin(betSNDT, spinVal);
        betSpin+=betSNDT;  //Increment with every bet amount
        spinWin+=betWin;  
        if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
        betWin=0; //reset the win variable for this bet to zero.
        
        //Find win or loss for SECOND THIRD (13-24) bet
        betWin=trdTWin(betTRDT, spinVal);
        betSpin+=betTRDT;  //Increment with every bet amount
        spinWin+=betWin;  
        if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
        betWin=0; //reset the win variable for this bet to zero.
        
        //settling variables to end this round of bets. Updating data for 
        //player profile info
        if (mostBet<betSpin) mostBet=betSpin;
        (spinWin>0)?totWin+=spinWin:totLoss+=spinWin; //ternary operator test
        bank+=spinWin;
        gmsPlyd++;
        if (spinWin>0) gmsWon++;
        if (spinWin<0) gmsLost++;
        if (spinWin==0) gmsPush++;
        totBet+=betSpin;
        
        //Put the game on auto-play for a while for a user chosen number of games
        cout<<endl<<"Would you like to repeat the last series of bets?"<<endl;
        cin>>yesNo;
        if (yesNo=='Y'^yesNo=='y') {
            cout<<"How many times would you like to repeat the last bets?"<<endl;
            int iteration=0;
            cin>>iteration;
            for (int i=1; i<=iteration; i++){
                //Editing player data. No reason really other than to do it and have an
                //excuse to increment counters.
                if (bank<=-1.0e6) {
                    cout<<"Your bank value is too low!"<<endl;
                    cout<<"Reducing your debt to $10,000."<<endl;
                    bank=-1.0e4;
                    resetBK++;
                }
                if (totLoss<=-1.0e6) {
                    cout<<"Your total losses are too larget!"<<endl;
                    cout<<"Reducing your total losses to $10,000."<<endl;
                    totLoss=-1.0e4;
                    resetL++;
                }
                if (totWin>=5.0e6) {
                    cout<<"Your total wins are getting too high!"<<endl;
                    cout<<"Reducing total winnings to $10,000."<<endl;
                    totWin=1.0e4;
                    resetW++;
                }
                if (totBet>=5.0e6) {
                    cout<<"Your total bets are getting a little too high!"<<endl;
                    cout<<"Reducing total bets to $10,000."<<endl;
                    totBet=1.0e4;
                    resetBT++;
                }
                spinVal=rand()%37; //random value from 0 to 36 for roulette wheel spin
                cout<<"And the ball came to rest on "<<spinVal<<endl;
                
                //Find win or loss for single number bet
                betWin=sNumWin(betSNUM, betNum, spinVal); 
                betSpin+=betSNUM;  //Increment with every bet amount
                spinWin+=betWin;  
                if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
                betWin=0; //reset the win variable for this bet to zero.
        
                //Find win or loss for ODD bet
                betWin=oddWin(betODD, spinVal);
                betSpin+=betODD;  //Increment with every bet amount
                spinWin+=betWin;  
                if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
                betWin=0; //reset the win variable for this bet to zero.
        
                //Find win or loss for EVEN bet
                betWin=evenWin(betEVEN, spinVal);
                betSpin+=betEVEN;  //Increment with every bet amount
                spinWin+=betWin;  
                if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
                betWin=0; //reset the win variable for this bet to zero.
        
                //Find win or loss for BLACK bet
                betWin=blckWin(betBLCK, spinVal);
                betSpin+=betBLCK;  //Increment with every bet amount
                spinWin+=betWin;  
                if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
                betWin=0; //reset the win variable for this bet to zero.
        
                //Find win or loss for RED bet
                betWin=redWin(betRED, spinVal);
                betSpin+=betRED;  //Increment with every bet amount
                spinWin+=betWin;  
                if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
                betWin=0; //reset the win variable for this bet to zero.
        
                //Find win or loss for TOP HALF (1-18) bet
                betWin=topHWin(betTHLF, spinVal);
                betSpin+=betTHLF;  //Increment with every bet amount
                spinWin+=betWin;  
                if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
                betWin=0; //reset the win variable for this bet to zero.
        
                //Find win or loss for BOTTOM HALF (19-36) bet
                betWin=botHWin(betBHLF, spinVal);
                betSpin+=betBHLF;  //Increment with every bet amount
                spinWin+=betWin;  
                if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
                betWin=0; //reset the win variable for this bet to zero.
        
                //Find win or loss for FIRST THIRD (1-12) bet
                betWin=fstTWin(betFSTT, spinVal);
                betSpin+=betFSTT;  //Increment with every bet amount
                spinWin+=betWin;  
                if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
                betWin=0; //reset the win variable for this bet to zero.
        
                //Find win or loss for SECOND THIRD (13-24) bet
                betWin=sndTWin(betSNDT, spinVal);
                betSpin+=betSNDT;  //Increment with every bet amount
                spinWin+=betWin;  
                if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
                betWin=0; //reset the win variable for this bet to zero.
        
                //Find win or loss for SECOND THIRD (13-24) bet
                betWin=trdTWin(betTRDT, spinVal);
                betSpin+=betTRDT;  //Increment with every bet amount
                spinWin+=betWin;  
                if (hiWin<=betWin) hiWin=betWin; //testing and setting highest win
                betWin=0; //reset the win variable for this bet to zero.
        
                //settling variables to end this round of bets. Updating data for 
                //player profile info
                if (mostBet<betSpin) mostBet=betSpin;
                (spinWin>0)?totWin+=spinWin:totLoss+=spinWin; //ternary operator test
                bank+=spinWin;
                gmsPlyd++;
                if (spinWin>0) {
                    gmsWon++;
                }
                else if (spinWin<0) {
                    gmsLost++;
                }
                else gmsPush++;
                totBet+=betSpin;
            }
        }
        yesNo='X';
        
        spinWin=0;//Reset spin to zero
        betSNUM=0;//Reset bets to defaults
        betNum=99;//Set number selector to out of bounds number
        betODD=0;//Reset bet for ODD to zero
        betEVEN=0;//Reset bet for EVEN to zero
        betBLCK=0;//Reset bet for BLACK to zero
        betRED=0;//reset bet for RED to zero
        betTHLF=0;//Reset bet for TOP HALF (1-18) to zero
        betBHLF=0;//Reset bet for BOTTOM HALF (19-36) to zero
        betFSTT=0;//Reset bet for FIRST THIRD (1-12) to zero
        betSNDT=0;//Reset bet for SECOND THIRD (13-24) to zero
        betTRDT=0;//Reset bet for THIRD THIRD (25-36) to zero
        
        cout<<"Would you like to play again?"<<endl;
        cin>>menuOpt;
        if (menuOpt=='Y'^menuOpt=='y') playMor=true;
        else playMor=false;
    }while (playMor);
    //Outputting player info and statistics
    cout<<"You have played "<<gmsPlyd<<" games so far!"<<endl;
    cout<<"You have won money in "<<gmsWon<<" games so far!"<<endl;
    cout<<"You have lost money in "<<gmsLost<<" games so far!"<<endl;
    cout<<"You neither won or loss in "<<gmsPush<<" games to date."<<endl;
    cout<<"You have been saved from bankruptcy "<<resetBK<<" times so far."<<endl;
    cout<<"     This is your bank value reset counter"<<endl;
    cout<<"You have been saved from organ harvesting "<<resetL
        <<" times so far."<<endl;
    cout<<"     This is your total losses reset counter"<<endl;
    cout<<"You have been saved from the IRS "<<resetW<<" times so far."<<endl;
    cout<<"     This is your total winnings reset counter"<<endl;
    cout<<"You have been saved from yourself "<<resetBT<<" times so far."<<endl;
    cout<<"     This is your total bet amount reset counter"<<endl;
    cout<<"Your bank currently has $"<<setprecision(2)<<fixed
        <<showpoint<<bank<<" in it."<<endl;
    cout<<"Your total bets are $"<<setprecision(2)<<fixed
        <<showpoint<<totBet<<" as of now."<<endl;
    cout<<"Your winnings come to $"<<setprecision(2)<<fixed
        <<showpoint<<totWin<<" as of now."<<endl;
    cout<<"Your total losses are $"<<setprecision(2)<<fixed
        <<showpoint<<totLoss<<" as of now."<<endl;
    cout<<"$"<<setprecision(2)<<fixed<<showpoint<<mostBet<<" is the most"
        <<" you have ever bet on a game."<<endl;
    cout<<"Your biggest win was $"<<setprecision(2)<<fixed
        <<showpoint<<hiWin<<" on a single game."<<endl;
    winPcnt=static_cast<float>(gmsWon)/gmsPlyd;
    cout<<"Your win ratio is: "<<setprecision(1)<<fixed<<showpoint<<winPcnt*100
            <<"%"<<endl;
    //asking to reset the values in player data file to defaults
    cout<<"Would you like to reset all values to defaults?"<<endl;
    cin>>yesNo;
    if (yesNo=='Y'^yesNo=='y'){
        gmsPlyd=0;
        gmsWon=0;
        gmsLost=0;
        gmsPush=0;
        resetBK=0;
        resetL=0;
        resetW=0;
        resetBT=0;
        bank=100.00;
        totBet=0.00;
        totWin=0.00;
        totLoss=0.00;
        mostBet=0.00;
        hiWin=0.00;
        cout<<"Resetting all values to defaults."<<endl;
    }
    yesNo='X'; //restoring menu default to an unused value
    //Output values to file - save player profile
    out.open(playerN+".dat");
    out<<gmsPlyd<<endl;
    out<<gmsWon<<endl;
    out<<gmsLost<<endl;
    out<<gmsPush<<endl;
    out<<resetBK<<endl;
    out<<resetL<<endl;
    out<<resetW<<endl;
    out<<resetBT<<endl;
    out<<bank<<endl;
    out<<totBet<<endl;
    out<<totWin<<endl;
    out<<totLoss<<endl;
    out<<mostBet<<endl;
    out<<hiWin<<endl;
    out.close();
    //Few things that require <cmath> since this program really doesn't need it
    cout<<"This program doesn't really need the <cmath> library so here"<<endl;
    cout<<"are some <cmath> functions to play with."<<endl<<endl;
    cout<<"Find the square root of a number. Enter a number:"<<endl;
    cin>>bank;
    cout<<setprecision(2)<<fixed<<showpoint<<sqrt(bank)<<endl;
    cout<<"Lets find the power of a number."<<endl;
    cout<<"Please enter your base number:"<<endl;
    cin>>bank;
    cout<<"Please enter the exponent value (ie squared, cubed, etc)"<<endl;
    cin>>hiWin;
    cout<<setprecision(2)<<fixed<<showpoint<<pow(bank, hiWin);
    
    //Exit stage right! - This is the 'return 0' call
    //DONT FORGET TO CLOSE FILES if they were not closed already
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//********************* Pay for Single Number Bet ******************************
//Description: Determines single-number win and returns winnings value
//
//Inputs: amount bet, number chosen, winning number (spin results)
//     
//Outputs: The amount of winnings for the individual bet or the amount lost
//         if bet did not win (loss is only the amount bet, wins can be a 
//         multiple of amount bet depending on the type of bet
//******************************************************************************
float sNumWin(float betAmnt, int pickNum, int spinNum){
    float winLoss;
    (pickNum==spinNum)?winLoss=betAmnt*ODDSNUM:winLoss=betAmnt*CONVBET;
    if (betAmnt>0){
        cout<<"Single Number Bet results:"<<endl;
        (winLoss<0)?cout<<"You Lost $"<<winLoss<<endl:cout
                <<"Good win! You won $"<<winLoss<<endl;
    }
    return winLoss;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//********************* Pay for ODD number bet ******************************
//Description: Determines ODD number win and returns winnings value
//
//Inputs: amount bet, winning number (spin results)
//     
//Outputs: The amount of winnings for the odd number bet or the amount lost
//         if bet did not win (loss is only the amount bet, wins can be a 
//         multiple of amount bet depending on the type of bet
//******************************************************************************
float oddWin(float betAmnt, int spinNum){
    float winLoss;
    (spinNum%2!=0)?winLoss=betAmnt*ODDODD:winLoss=betAmnt*CONVBET;
    if (betAmnt>0){
        cout<<"Results for betting ODD!"<<endl;
        (winLoss<0)?cout<<"You Lost $"<<winLoss<<endl:cout
                <<"Good win! You won $"<<winLoss<<endl;
    }
    return winLoss;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//********************* Pay for EVEN number bet ******************************
//Description: Determines EVEN number win and returns winnings value
//
//Inputs: amount bet, winning number (spin results)
//     
//Outputs: The amount of winnings for the even number bet or the amount lost
//         if bet did not win (loss is only the amount bet, wins can be a 
//         multiple of amount bet depending on the type of bet
//******************************************************************************
float evenWin(float betAmnt, int spinNum){
    float winLoss;
    (spinNum%2==0)?winLoss=betAmnt*ODDEVEN:winLoss=betAmnt*CONVBET;
    if (betAmnt>0){
        cout<<"Results for betting EVEN!"<<endl;
        (winLoss<0)?cout<<"You Lost $"<<winLoss<<endl:cout
                <<"Good win! You won $"<<winLoss<<endl;
    }
    return winLoss;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//********************* Pay for BLACK number bet ******************************
//Description: Determines BLACK number win and returns winnings value
//
//Inputs: amount bet, winning number (spin results)
//     
//Outputs: The amount of winnings for the black number bet or the amount lost
//         if bet did not win (loss is only the amount bet, wins can be a 
//         multiple of amount bet depending on the type of bet
//******************************************************************************
float blckWin(float betAmnt, int spinNum){
    float winLoss;
    bool blckNum=false;
    if(spinNum==2||spinNum==4||spinNum==6||spinNum==8||spinNum==10||spinNum==11
            ||spinNum==13||spinNum==15||spinNum==17||spinNum==20||spinNum==22
            ||spinNum==24||spinNum==26||spinNum==28||spinNum==29||spinNum==31
            ||spinNum==33||spinNum==35)blckNum=true;
    else blckNum=false;
    blckNum?winLoss=betAmnt*ODDBLCK:winLoss=betAmnt*CONVBET;
    if (betAmnt>0){
        cout<<"Results for betting BLACK!"<<endl;
        (winLoss<0)?cout<<"You Lost $"<<winLoss<<endl:cout
                <<"Good win! You won $"<<winLoss<<endl;
    }
    return winLoss;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//********************* Pay for RED number bet ******************************
//Description: Determines RED number win and returns winnings value
//
//Inputs: amount bet, winning number (spin results)
//     
//Outputs: The amount of winnings for the red number bet or the amount lost
//         if bet did not win (loss is only the amount bet, wins can be a 
//         multiple of amount bet depending on the type of bet
//******************************************************************************
float redWin(float betAmnt, int spinNum){
    float winLoss;
    bool redNum=false;
    if(spinNum==1||spinNum==3||spinNum==5||spinNum==7||spinNum==9||spinNum==12
            ||spinNum==14||spinNum==16||spinNum==18||spinNum==19||spinNum==21
            ||spinNum==23||spinNum==25||spinNum==27||spinNum==30||spinNum==32
            ||spinNum==34||spinNum==36)redNum=true;
    else redNum=false;
    redNum?winLoss=betAmnt*ODDRED:winLoss=betAmnt*CONVBET;
    if (betAmnt>0){
        cout<<"Results for betting RED!"<<endl;
        (winLoss<0)?cout<<"You Lost $"<<winLoss<<endl:cout
                <<"Good win! You won $"<<winLoss<<endl;
    }
    return winLoss;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//********************* Pay for TOP HALF number bet ****************************
//Description: Determines Top Half (1-18) number win and returns winnings value
//
//Inputs: amount bet, winning number (spin results)
//     
//Outputs: The amount of winnings for the top half (1-18) number bet or the 
//         amount lost if bet did not win (loss is only the amount bet, wins 
//         can be a multiple of amount bet depending on the type of bet
//******************************************************************************
float topHWin(float betAmnt, int spinNum){
    float winLoss;
    (spinNum>=1&&spinNum<=18)?winLoss=betAmnt*ODDTOPH:winLoss=betAmnt*CONVBET;
    if (betAmnt>0){
        cout<<"Results for betting 1-18!"<<endl;
        (winLoss<0)?cout<<"You Lost $"<<winLoss<<endl:cout
                <<"Good win! You won $"<<winLoss<<endl;
    }
    return winLoss;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Pay for BOTTOM HALF number bet **************************
//Description: Determines Bottom Half (19-36) number win and returns winnings 
//             value
//Inputs: amount bet, winning number (spin results)
//     
//Outputs: The amount of winnings for the bottom half (19-36) number bet or the 
//         amount lost if bet did not win (loss is only the amount bet, wins 
//         can be a multiple of amount bet depending on the type of bet
//******************************************************************************
float botHWin(float betAmnt, int spinNum){
    float winLoss;
    (spinNum>=19&&spinNum<=36)?winLoss=betAmnt*ODDBOTH:winLoss=betAmnt*CONVBET;
    if (betAmnt>0){
        cout<<"Results for betting 19-36!"<<endl;
        (winLoss<0)?cout<<"You Lost $"<<winLoss<<endl:cout
                <<"Good win! You won $"<<winLoss<<endl;
    }
    return winLoss;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Pay for FIRST THIRD number bet **************************
//Description: Determines First Third (1-12) number win and returns winnings 
//             value
//Inputs: amount bet, winning number (spin results)
//     
//Outputs: The amount of winnings for the First Third (1-12) number bet or the 
//         amount lost if bet did not win (loss is only the amount bet, wins 
//         can be a multiple of amount bet depending on the type of bet
//******************************************************************************
float fstTWin(float betAmnt, int spinNum){
    float winLoss;
    (spinNum>=1&&spinNum<=12)?winLoss=betAmnt*ODDFSTT:winLoss=betAmnt*CONVBET;
    if (betAmnt>0){
        cout<<"Results for betting 1-12!"<<endl;
        (winLoss<0)?cout<<"You Lost $"<<winLoss<<endl:cout
                <<"Good win! You won $"<<winLoss<<endl;
    }
    return winLoss;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Pay for SECOND THIRD number bet **************************
//Description: Determines Second Third (13-24) number win and returns winnings 
//             value
//Inputs: amount bet, winning number (spin results)
//     
//Outputs: The amount of winnings for the Second Third (13-24) number bet or the 
//         amount lost if bet did not win (loss is only the amount bet, wins 
//         can be a multiple of amount bet depending on the type of bet
//******************************************************************************
float sndTWin(float betAmnt, int spinNum){
    float winLoss;
    (spinNum>=13&&spinNum<=24)?winLoss=betAmnt*ODDFSTT:winLoss=betAmnt*CONVBET;
    if (betAmnt>0){
        cout<<"Results for betting 13-24!"<<endl;
        (winLoss<0)?cout<<"You Lost $"<<winLoss<<endl:cout
                <<"Good win! You won $"<<winLoss<<endl;
    }
    return winLoss;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Pay for THIRD THIRD number bet **************************
//Description: Determines Third Third (25-36) number win and returns winnings 
//             value
//Inputs: amount bet, winning number (spin results)
//     
//Outputs: The amount of winnings for the Third Third (25-36) number bet or the 
//         amount lost if bet did not win (loss is only the amount bet, wins 
//         can be a multiple of amount bet depending on the type of bet
//******************************************************************************
float trdTWin(float betAmnt, int spinNum){
    float winLoss;
    (spinNum>=25&&spinNum<=36)?winLoss=betAmnt*ODDFSTT:winLoss=betAmnt*CONVBET;
    if (betAmnt>0){
        cout<<"Results for betting 25-36!"<<endl;
        (winLoss<0)?cout<<"You Lost $"<<winLoss<<endl:cout
                <<"Good win! You won $"<<winLoss<<endl;
    }
    return winLoss;
}

