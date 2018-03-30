/* 
 * File:   Financial.h
 * Author: Dr. Mark E. Lehr
 *
 * Created on December 1, 2012, 2:11 PM
 */

#ifndef FINANCIAL_H
#define	FINANCIAL_H
#include "AbstractFinancial.h"
#include "Loan.h"
template<class T>
class Financial:public AbstractFinancial{
    private:
        T **loans;
        int numLoans;
    public:
        Financial(float,float,float,int);
        ~Financial();
        int getNumLoans(){return numLoans;}
        float getBalance(int);
        T *getLoan(int);
};

template<class T>
Financial<T>::Financial(float b,float istrt,float istop,int n){
    //Determine the number of Loans
    if(istop>istrt&&istrt>0&&istop<1){}else{istop=.1f;istrt=0.05f;}
    numLoans=static_cast<int>((istop-istrt)*n*100);
    //Create the Loan array
    loans=new T*[numLoans];
    for(int i=0;i<numLoans;i++){
        float interest=istrt*n+.01f*i;
        loans[i]=new T(b,interest/n,n);
    }
}

template<class T>
Financial<T>::~Financial(){
    for(int i=0;i<numLoans;i++){
        delete loans[i];
    }
    delete []loans;
}

template<class T>
float Financial<T>::getBalance(int i){
    return loans[i]->getBalance();
}

template<class T>
T *Financial<T>::getLoan(int i){
    if(i>=0&&i<numLoans){return loans[i];}
    else {return loans[0];}
}
#endif	/* FINANCIAL_H */

