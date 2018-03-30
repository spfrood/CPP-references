
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries
#define CB_BLAC      "\033[1m\033[30m"      /* Bold Black */
#define CB_RED       "\033[1m\033[31m"      /* Bold Red */
#define CB_GREE      "\033[1m\033[32m"      /* Bold Green */
#define CB_YELL      "\033[1m\033[33m"      /* Bold Yellow */
#define CB_BLUE      "\033[1m\033[34m"      /* Bold Blue */
#define CB_MAGE      "\033[1m\033[35m"      /* Bold Magenta */
#define CB_CYAN      "\033[1m\033[36m"      /* Bold Cyan */
#define C_RESET      "\x1b[0m"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
//Also used for 2-dimensional array column numbers
const int BETCOLS=3;

//Function Prototypes
float sNumWin(float , int , int);
void spnHist(int [], int, int);
void fNumBet(int [][BETCOLS]); //To enable betting more than 1 number per spin
float sNumWin (int [][BETCOLS], int); //Determine winning numbers

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //initialize random seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SPINNER=200;
    int spinRec[SPINNER]={};
    int numBets[37][BETCOLS]={};
    int curSpin=38;
    bool end=true;
    char endChar='N';
    char choice='X';
    float bank=0.0f;
    
    //Input Values
    for (int i=0;i<SPINNER;i++){
        spinRec[i]=rand()%37; //random 0 to 36
    }
    for (int i=0;i<SPINNER;i++){
        if (i%20==0) cout<<endl;
        cout<<setw(3);
        cout<<spinRec[i];
    }
    cout<<endl;
    curSpin=rand()%37;
    
    //Process by mapping inputs to outputs
    do {
        spnHist(spinRec,SPINNER,curSpin);
        cout<<"Spin Again(Y/N)?"<<endl;
        cin>>endChar;
        if ((endChar=='N')||(endChar=='n')){
            end=false;
        }
        else {
            end=true;
            curSpin=rand()%37;
        }
        for (int i=0;i<SPINNER;i++){
            if (i%20==0) cout<<endl;
            cout<<setw(3);
            cout<<spinRec[i];
        }
        fNumBet(numBets);
        bank+= sNumWin(numBets, curSpin);
        cout<<"Your bank total is: $"<<bank<<endl;
    } while (end);
    
/*    do{
        cout<<"What number would you like to bet on?"<<endl;
        cin>>betNum; //getting the number to bet on
        if (betNum<0^betNum>36) { //making sure number in range of wheel
        cout<<"That number isn't an option for roulette bets!"
            <<"Choose another number between 0 and 36!"<<endl;
        }
    } while (betNum<0^betNum>36);  //Keep doing until number in valid range
    cout<<"How much do you want to bet on "<<betNum<<"?"<<endl;
    cin>>betSNUM;break;}
*/
    
    //Output values
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}


//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************** Fill Number Bets *********************************
//Description: Takes the bets for Single Number bets
//
//Inputs: Single Number bet array, number of bets made
//     
//Outputs: None
//******************************************************************************
void fNumBet(int singBet[][BETCOLS]){
    int rowCnt=0, betCnt=0;
    char choice='y';
    bool betting=true;
    cout<<endl;
    cout<<"Please enter your bets for single numbers: "<<endl;
    cout<<"You can only bet up to 34 different times."<<endl;
    cout<<"If you bet the same number more than once it will be"<<endl;
    cout<<"be treated as if you placed two bets on the same number."<<endl;
    cout<<"Bet amounts must be positive integers!"<<endl;
    do {
        cout<<"What number would you like to bet on?"<<endl;
        cin>>singBet[rowCnt][0];
        cout<<"How much would you like to bet?"<<endl;
        cin>>singBet[rowCnt][1];
        rowCnt++;
        singBet[0][2]= ++betCnt;
        cout<<"Would you like to bet on another number?"<<endl;
        cin>>choice;
        if ((choice=='y')||(choice=='Y')) {
            betting=true;
        }
        else {
            cout<<"Exiting Betting"<<endl;
            betting=false;
        }
        if (betCnt>=34){
            cout<<"Exiting Betting"<<endl;
            betting=false;
        }
    }while (betting);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************ Rotate Array Values *********************************
//Description: Rotates the array so that each number is moved down a slot
//
//Inputs: spin history array, current spin value
//     
//Outputs: None
//******************************************************************************
void spnHist(int spinRec[],int SPINNER, int thisSpn){
    for (int i=(SPINNER-1);i>0;i--){
        spinRec[i]=spinRec[i-1];
    }
    spinRec[0]=thisSpn;
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
float sNumWin(int singBet[][BETCOLS], int spinNum){
    float winLoss;
    float subtot=0.0f;
    for (int i=0;i<singBet[0][2];i++) {
        (singBet[i][0]==spinNum)?winLoss=singBet[i][1]*35:winLoss=singBet[i][1]*(-1);
        subtot+=winLoss;
        cout<<"Your winnings so far = $"<<subtot<<endl;
    }
    if (subtot>0) cout<<"Good win! $"<<subtot<<endl;
    return subtot;
}