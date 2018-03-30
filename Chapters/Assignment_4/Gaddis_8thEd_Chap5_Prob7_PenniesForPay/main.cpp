
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 11:08 PM
 * Purpose: Gaddis, 8th Edition, Chapter 5, Problem 7, Pennies for Pay
 * Write a program that calculates how much a person would earn over a 
 * period of time if his or her salary is one penny the first day and 
 * two pennies the second day, and con- tinues to double each day. The 
 * program should ask the user for the number of days. Display a table 
 * showing how much the salary was for each day, and then show the total 
 * pay at the end of the period. The output should be displayed in a dollar 
 * amount, not the number of pennies.
 * 
 * Input Validation: Do not accept a number less than 1 for the number of days 
 * worked.
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>

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
    short days = 0;
    unsigned long int pennies = 1;
    double salary = 0; //Need double for more than 7 precision digits
    
    //Input Values and check for validations
    do {
    cout<<"How many days did you work (up to 53)? "<<endl;
    cin>>days;
    if (days < 1) cout<<"You must work at least 1 day!"<<endl;
    if (days > 53) cout<<"Maximum of 53 days!"<<endl;
    } while (days < 1 || days > 53); //Need to many precision digits above 55
    
    //Loop to show salary in dollars on a daily basis
    
    cout<<"Day Worked                    Salary Paid"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for (int time = 1; time <= days; time++) {
        pennies = pow(2, (time-1));
        cout<<" "<<setw(4)<<time<<"             $ "<<setw(21)<<right
                <<setprecision(2)<<fixed<<static_cast<double>(pennies)*(1e-2)
                <<endl; //Double because of necessary digits
        salary += pennies;
    }
    
    cout<<"\nYour total pay for working "<<days<<" days is $ "<<setprecision(2)
            <<fixed<<salary*1e-2;
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

