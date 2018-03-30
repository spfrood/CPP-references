/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 30, 2012, 5:16 PM
 * Illustrate
 *      Classes
 *      Inherited Class
 *      Abstract Class
 *      Templated Class
 *      Polymorphic Utilization
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "InheritedLoan.h"
#include "Financial.h"
int main(int argc, char** argv) {
    //Test the loan class
    cout<<"Testing the Loan Class"<<endl;
    InheritedLoan il(100.0f,0.005,12,-0.05);
    cout<<"Balance=$"<<il.getBalance()<<endl;
    cout<<"Interest Rate="<<il.getIntRate()*100<<"%"<<endl;
    cout<<"for a period of "<<il.getPeriod()<<"/Year"<<endl;
    cout<<"Minimum Payment =$"<<il.getMinPayment()<<" per period"<<endl;
    cout<<endl;
    //Test the Financial class with the Loan
    cout<<"Testing the Financial Class with the original loan"<<endl;
    Financial<Loan> f(100.0f,0.05f,0.10f,1);
    cout<<"Number of Financial Loans = "<<f.getNumLoans()<<endl;
    Loan *ill=f.getLoan(0);
    cout<<"Balance=$"<<ill->getBalance()<<endl;
    cout<<"Interest Rate="<<ill->getIntRate()*100<<"%"<<endl;
    cout<<"for a period of "<<ill->getPeriod()<<"/Year"<<endl;
    cout<<endl;
    //Test the Financial class with the Loan
    //Note the polymorphic nature of this
    cout<<"Testing the Financial Class with the inherited loan"<<endl;
    Financial<InheritedLoan> fi(100.0f,0.05f,0.10f,1);
    cout<<"Number of Financial Loans = "<<fi.getNumLoans()<<endl;
    Loan *illi=fi.getLoan(2);
    cout<<"Balance=$"<<illi->getBalance()<<endl;
    cout<<"Interest Rate="<<illi->getIntRate()*100<<"%"<<endl;
    cout<<"for a period of "<<illi->getPeriod()<<"/Year"<<endl;
    return 0;
}

