/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 26, 2017, 1:26 PM
 * Purpose:  5)  Develop an application that will determine the gross pay for 
 * employees. The company pays "straight-time" for the first 20 hours worked, 
 * double time for all hours worked in excess of 20 hours but less than 40 
 * hours, and triple time for any hours worked over 40 hours. Inputs to the 
 * program would be hours worked and rate of pay.  Output would be gross pay.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float payRate=0;//Pay rate in $'s/hr
    float payChck=0;//Pay check in $'s
    float regPay=0, doubPay=0, tripPay=0;//Pay broken down by type
    int hrsWrkd=0;//Hours worked
    
    //Input values
    cout<<"This program calculates your Paycheck based on the hours"<<endl;
    cout<<"worked and your hourly pay rate."<<endl;
    cout<<"Input how many hours you worked: "<<endl;
    cin>>hrsWrkd;
    cout<<"Input your pay rate in dollars per hour: "<<endl;
    cin>>payRate;
    
    //Process by mapping inputs to outputs
    if (hrsWrkd<=20) {
        payChck=hrsWrkd*payRate;
        regPay=hrsWrkd*payRate;
    }
    else if ((hrsWrkd>20)&&(hrsWrkd<=40)) {
        payChck=((payRate*20)+((payRate*2)*(hrsWrkd-20)));
        doubPay=(payRate*2*(hrsWrkd-20));
        regPay=(payRate*20);
    }
    else if (hrsWrkd>40) {
        payChck=((payRate*20)+(payRate*2*20)+((payRate*3)*(hrsWrkd-40)));
        regPay=(payRate*20);
        doubPay=(payRate*2*20);
        tripPay=(payRate*3*(hrsWrkd-40));
    }
            
    //Output values
    cout<<"Your total paycheck is   $"<<setprecision(2)<<fixed<<showpoint
            <<payChck<<endl;
    cout<<"Your regular hours paid  $"<<setprecision(2)<<fixed<<showpoint
            <<regPay<<endl;
    if (doubPay>0.0) {
    cout<<"Your doubled hours paid  $"<<setprecision(2)<<fixed<<showpoint
            <<doubPay<<endl;
    } else cout<<"You did not work any double pay hours."<<endl;
    if (tripPay>0) {
    cout<<"Your tripled hours paid  $"<<setprecision(2)<<fixed<<showpoint
            <<tripPay<<endl;
    } else cout<<"You did not work any triple pay hours."<<endl;
    
    //Exit stage right!
    return 0;
}