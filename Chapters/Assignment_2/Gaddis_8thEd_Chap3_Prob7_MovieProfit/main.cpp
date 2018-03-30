
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 11, 2017
 * Purpose: Gaddis, Ch3, Prob 7, 
 *      Movie Theater profit calculations for a movie.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const float adltPrc = 1.0e1;
const float chldPrc = 6.00;

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    string movName; //Name of the movie
    short adltTic, chldTic;  
    float totSale, netPro, distPay;  //currency
    
    //Input Values
    cout<<"This program will calculate the profits for a movie theater"<<endl;
    cout<<"based on the number of adult and child tickets sold for a "<<endl;
    cout<<"given movie."<<endl;
    cout<<"Please enter the name of the Move:"<<endl;
    getline(cin, movName);
    cout<<"Please enter the number of Adult tickets sold:"<<endl;
    cin>>adltTic;
    cout<<"Please enter the number of Child tickets sold:"<<endl;
    cin>>chldTic;
    
    //Process by mapping inputs to outputs
    totSale = ((adltTic*adltPrc)+(chldTic*chldPrc));
    netPro = totSale*2.0e-1;
    distPay = totSale*8.0e-1;
    
    //Output values
    cout<<"Movie Name:                   \""<<movName<<"\""<<endl;
    cout<<"Adult Tickets Sold:            "<<adltTic<<endl;
    cout<<"Child Tickets Sold:            "<<chldTic<<endl;
    cout<<setprecision(2)<<fixed; //formatting for dollars and cents
    cout<<"Total Box Office Sales:       $"<<totSale<<endl;
    cout<<"Total Theater Profit:         $"<<netPro<<endl;
    cout<<"Total Paid to Distributors    $"<<distPay<<endl;
    
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

