
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 1, 2017, 12:05 PM
 * Purpose: 3. Winning Division
Write a program that determines which of a company’s four divisions (Northeast,
Southeast, Northwest, and Southwest) had the greatest sales for a quarter. It 
should include the following two functions, which are called by main .
• double getSales() is passed the name of a division. It asks the user for a 
division’s quarterly sales figure, validates the input, then returns it. It 
should be called once for each division.
 ** USING FLOAT NOT DOUBLE
• void findHighest() is passed the four sales totals. It determines which is 
the largest and prints the name of the high grossing division, along with its 
sales figure. 

Input Validation: Do not accept dollar amounts less than $0.00.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes
int getSales(string);
void findHighest(float, float, float, float);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    string noeaRiv="Northeast Division";
    string soeaRiv="Southeast Riverside";
    string soweRiv="Southwest Riverside";
    string noweRiv="Northwest Riverside";
    float neRiv, seRiv, swRiv, nwRiv;
    
    //Input Values
    neRiv=getSales(noeaRiv);
    seRiv=getSales(soeaRiv);
    swRiv=getSales(soweRiv);
    nwRiv=getSales(noweRiv);
    
    //Process by mapping inputs to outputs
    findHighest(neRiv,seRiv,swRiv,nwRiv);
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//Determine and output the lowest number 
void findHighest(float neRi, float seRi, float swRi, float nwRi){
    float highSle=neRi;
    string noeaRiv="Northeast Division";
    string soeaRiv="Southeast Riverside";
    string soweRiv="Southwest Riverside";
    string noweRiv="Northwest Riverside";
    string highReg=noeaRiv;
    if (highSle<seRi){
        highReg=soeaRiv;
        highSle=seRi;
    }
    if (highSle<swRi){
        highReg=soeaRiv;
        highSle=swRi;
    }
    if (highSle<nwRi){
        highReg=noweRiv;
        highSle=nwRi;
    }
    cout<<highReg<<" had the most sales with $"<<setprecision(2)<<fixed<<showpoint
            <<highSle<<endl;
    
}

//Input the number of accidents
int getSales(string region){
    float saleNum;
    do {
    cout<<"Input the total sales for "<<region<<endl;
    cin>>saleNum;
    if (saleNum<0) cout<<"Invalid Sales Data!"<<endl;
    }while (saleNum<0);
    return saleNum;
}