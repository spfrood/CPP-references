/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsAccount.cpp
 * Author: scott_r_parker
 * 
 * Created on June 8, 2017, 9:10 PM
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#include "SavingsAccount.h"

//Constructor
SavingsAccount::SavingsAccount(float initBal) {
    if (initBal>=0) {
        Balance=initBal;
    } else {
        Balance=0.0f;
    }
    FreqWithDraw=0; 
    FreqDeposit=0; 
}

//Procedure to determine deposit or withdraw
void  SavingsAccount::Transaction(float money) {
    if ((Balance+money)<0) {
        cout<<"WithDraw not Allowed"<<endl;
    } else if (money<0) {
        Balance=Withdraw(money);
    } else {
        Balance=Deposit(money);
    }
}

//Utility Procedure
float SavingsAccount::Withdraw(float cashOut) {
    FreqWithDraw++;
    return (Balance+cashOut);
} 

//Utility Procedure
float SavingsAccount::Deposit(float cashIn) {
    FreqDeposit++;
    return (Balance+cashIn);
}                

//Savings Procedure
float SavingsAccount::Total(float interest, int time) {
//    6)  The total procedure tells you how much you will have in
//     savings given the interest rate and the amount of time.
//Total(float savint,int time)  returns Balance*(1+savint)^time.
//Utilize a for loop for this calculation.
    float temp=0.0;
    temp=(Balance*(pow(1+interest, time)));
    
    return temp;
}	 

//float SavingsAccount::TotalRecursive(float interest, int time) {
//    float newBal=Balance;
//    for (int i=0;i<time;i++) {
//        newBal+=(newBal*interest);
//    }
//    return newBal;
//}

float SavingsAccount::TotalRecursive(float interest, int time) {
    if(time<=0)return Balance;
    return TotalRecursive(interest,time-1)*(1+interest);
}

void  SavingsAccount::toString() {
    cout<<"Balance="<<Balance<<endl;
    cout<<"WithDraws="<<FreqWithDraw<<endl;
    cout<<"Deposits="<<FreqDeposit<<endl;
}
