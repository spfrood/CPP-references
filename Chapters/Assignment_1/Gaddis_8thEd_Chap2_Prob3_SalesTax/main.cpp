
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 8, 2017
 * Purpose: Gaddis Chap2 Prob3 Calculate the sales tax
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    short price;  //short for purchases at most stores, markets, etc
    float cntTax=4.0e-2, stTax=2.0e-2, cntPaid, stPaid, totPaid;
    
    
    //Input Values
    cout<<"How much is the total taxable amount (dollars only)?"<<endl;
    cin>>price;
    
    //Process by mapping inputs to outputs
    cntPaid=cntTax*price;
    stPaid=stTax*price;
    totPaid=price+cntPaid+stPaid;
    
    //Output values
    cout<<"Your county tax amounted to:           $"<<cntPaid<<endl;
    cout<<"Your state tax amounted to:            $"<<stPaid<<endl;
    cout<<"The total price for your purchase is:  $"<<totPaid<<endl;
    
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

