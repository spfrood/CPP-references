/* 
 * File:   Loan.h
 * Author: Dr. Mark E. Lehr
 * Created on November 30, 2012, 5:18 PM
 */

#ifndef LOAN_H
#define	LOAN_H
class Loan{
    private:
        float balance;//Account Balance $'s
        float interest;//Interest Rate % at Recurrence Rate
        int   period;//Recurrence Rate relative to a year
    public:
        Loan(float b,float i,int n){
            setBalance(b);
            setInterest(i);
            setPeriod(n);
        }
        float getBalance(){return balance;}
        float getInterest(){return interest;}
        int   getPeriod(){return period;}
        float getIntRate(){return interest*period;}
        float getIntPaid(){return interest*balance;}
        void  setBalance(float b){
            if(b>0)balance=b;
            else balance=100;
        }
        void  setInterest(float i){
            if(i>0&&i<1)interest=i;
            else interest=0.05f;
        }
        void  setPeriod(int p){
            if(p>0&&p<365)period=p;
            else period=12;
        }
};
#endif	/* LOAN_H */

