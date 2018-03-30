
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

//Function Prototypes
void resData(float &, float &, float &, float &, int &, int &, int &, int &);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //initialize random seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    float bank=0.0f;
    float totLoss=0.0f;
    float totWin=0.0f;
    float totBet=0.0f;
    int resetBK=0;
    int resetL=0;
    int resetW=0;
    int resetBT=0;
    
    //Input values
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Bank:  $"<<bank<<endl;
    cout<<"Total Loss:  $"<<totLoss<<endl;
    cout<<"Total Wins:  $"<<totWin<<endl;
    cout<<"Total Bet:   $"<<totBet<<endl;
    cout<<"Bank Account resets: "<<resetBK<<endl;
    cout<<"Loss amount resets:  "<<resetL<<endl;
    cout<<"Win amount resets:   "<<resetW<<endl;
    cout<<"Bet totals reset:    "<<resetBT<<endl;
    
    for (int i=0;i<=10000;i++){
        bank+=(rand()%10000*(-1.0f));
        totLoss+=(rand()%10000*(-1.0f));
        totWin+=rand()%10000;
        totBet+=rand()%10000;
        resData(bank,totLoss,totWin,totBet,resetBK,resetL,resetW,resetBT);
    }
    
    //Output values
    cout<<"Bank:  $"<<bank<<endl;
    cout<<"Total Loss:  $"<<totLoss<<endl;
    cout<<"Total Wins:  $"<<totWin<<endl;
    cout<<"Total Bet:   $"<<totBet<<endl;
    cout<<"Bank Account resets: "<<resetBK<<endl;
    cout<<"Loss amount resets:  "<<resetL<<endl;
    cout<<"Win amount resets:   "<<resetW<<endl;
    cout<<"Bet totals reset:    "<<resetBT<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void resData(float &bnkVal, float &lossVal, float &winVal, float &betVal, int &reBnk, int &reLoss, int &reWin, int &reBet){
    //Editing player data. No reason really other than to do it and have an
    //excuse to increment counters.
    if (bnkVal<=-5.0e6) {
        cout<<"Your bank value is too low!"<<endl;
        cout<<"Resetting bank to $100.00!"<<endl;
        bnkVal=1.0e2;
        reBnk++;
    }
    if (lossVal<=-5.0e6) {
        cout<<"Your total losses are too large!"<<endl;
        cout<<"Resetting your total losses to $0.00!"<<endl;
        lossVal=0.0e2;
        reLoss++;
    }
    if (winVal>=5.0e6) {
        cout<<"Your winnings are getting too high!"<<endl;
        cout<<"Taking out some taxes! (resetting total to $0.00)"<<endl;
        winVal=0.0e2;
        reWin++;
    }
    if (betVal>=5.0e6) {
        cout<<"Your total bets are getting a little too high!"<<endl;
        cout<<"Reducing bet totals to $0.00!"<<endl;
        betVal=0.0e2;
        reBet++;
    }
}
