
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 4, 2017, 12:10 PM
 * Purpose: Homework - Gaddis_8thEd_Chap2_Prob17_StockPrice 
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
int main(int argc, char** argv) 
{
    //Declare and initialize Variables
    unsigned char stkPrce = 35; //Unsigned Character 
    unsigned short nShares = 750; //Number of shares purchased
    float comishn = 2.0e-2f; //Percentage commission paid
    unsigned short stkPaid, comPaid, totPaid; //items we find value for
    
    //Input Values combined with declare
    //Process by mapping inputs to outputs
    stkPaid = stkPrce*nShares;
    comPaid = stkPaid*comishn;
    totPaid=stkPaid+comPaid;
    
    //Output values
    cout<<"Stock Price/Share   = $"<<static_cast<int>(stkPrce)<<endl;
    cout<<"Shares Purchased    = $"<<nShares<<endl;
    cout<<"Commission Rate     = " <<comishn<<endl;
    cout<<"Cost of Stock       = $"<<stkPaid<<endl;
    cout<<"Commission Paid     = $"<<comPaid<<endl;
    cout<<"Total Paid          = $"<<totPaid<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

