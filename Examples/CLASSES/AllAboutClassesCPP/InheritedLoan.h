/* 
 * File:   InheritedLoan.h
 * Author: Dr. Mark E. Lehr
 *
 * Created on December 1, 2012, 12:51 PM
 */

#ifndef INHERITEDLOAN_H
#define	INHERITEDLOAN_H
#include "Loan.h"
class InheritedLoan:public Loan{
    private:
        float minPayment;//Derived from the constructor
    public:
        InheritedLoan(float b,float i,int n,float p=0.02f):Loan(b,i,n){
             setMinPayment(p);
        }
        float getMinPayment(){return minPayment;}
        void setMinPayment(float p){
            if(p>0&&p<0.5f){minPayment=getBalance()*p;}
            else minPayment=getBalance()*getInterest();
        }
};
#endif	/* INHERITEDLOAN_H */

