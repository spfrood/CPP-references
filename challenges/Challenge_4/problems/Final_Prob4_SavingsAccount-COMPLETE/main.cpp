
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on June 5, 2017, 9:56 AM
 * Purpose: Problem #4  (Savings Account Class)
	Create a SavingsAccount class with the following specification

class SavingsAccount {
private:
    float Withdraw(float);               //Utility Procedure
    float Deposit(float);                //Utility Procedure
    float Balance;                       //Property
    int   FreqWithDraw;                  //Property
    int   FreqDeposit;                   //Property
public:
    SavingsAccount(float);               //Constructor
    void  Transaction(float);            //Procedure
    float Total(float=0,int=0);	         //Savings Procedure
    float TotalRecursive(float=0,int=0);
    void  toString();                    //Output Properties
}

1)  The constructor initilizes the balance if greater than
     0 and sets the other properties to 0.
2)  If the transaction is greater than 0 then a Deposit is
     made else a Withdraw is made.
3)  The balance is increased with a deposit but decreased
     if a Withdrawal.  This assumes the Withdrawal is less than
     the balance.  Can't have a negative balance.  Tell the user
     that he is trying to make a withdrawal that exceeds his
     balance.
4)  When a WithDrawal is made increment FreqWithDraw else
     if a Deposit is made increment FreqDeposit.
5)  The toString procedure outputs all properties.
6)  The total procedure tells you how much you will have in
     savings given the interest rate and the amount of time.
Total(float savint,int time)  returns Balance*(1+savint)^time.
Utilize a for loop for this calculation.
7)  See if you can write a recursive procedure that does
     the same thing as 6).  Call it TotalRecursive.
8)  Think of what follows as pseudocode.  The random number
     generator below produces a number between 0 and 32,767.  If
     you fashion a random number that will do the same then you
     will get positive and negative transactions (-500,500).  
     The output simply calculates the current balance with a 10 
     percent interest rate and 7 years worth of compounding.  
     Also, you tried to start out with a negative balance which 
     should have been initialized to 0.

    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;

Example Output:
    WithDraw not Allowed
    WithDraw not Allowed
    Balance=1056
    WithDraws=4
    Deposit=5
    Balance after 7 years given 10% interest = 2057.85
    Balance after 7 years given 10% interest = 2057.85 Recursive Calculation
 
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "SavingsAccount.h"
//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
//or columns for 2D arrays

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    SavingsAccount mine(-300);
    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
    
    //Output values
    
    //Clean up memory
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

