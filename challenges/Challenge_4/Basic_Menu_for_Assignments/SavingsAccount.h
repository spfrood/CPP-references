/*

6)  The total procedure tells you how much you will have in
     savings given the interest rate and the amount of time.
Total(float savint,int time)  returns Balance*(1+savint)^time.
Utilize a for loop for this calculation.
7)  See if you can write a recursive procedure that does
     the same thing as 6).  Call it TotalRecursive.
 */

/* 
 * File:   SavingsAccount.h
 * Author: scott_r_parker
 *
 * Created on June 8, 2017, 9:10 PM
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

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
    float TotalRecursive(float=0, int=0);
    void  toString();                    //Output Properties
};

#endif /* SAVINGSACCOUNT_H */

