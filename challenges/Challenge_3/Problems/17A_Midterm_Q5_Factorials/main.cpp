
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on April 19, 2017  4:56 PM
 * Purpose: 5)  a) Using a byte variable, what is the largest factorial that can 
be calculated.  A factorial is simply 

n! = 1 * 2 * 3 * 4 ... * (n-2) * (n-1) * n

For instance, 1! = 1,  2! = 2,  3! = 6,  4! = 24,  5! = 120 etc....

b)  What would be the largest factorial using short, int, long, float, 
double, etc...  Use all the primitive data types that you are familiar 
with signed as well as unsigned.

Note:  I want you to have fun investigating this and the program you 
turn in should just print "cout" the final results.  You don't know 
how to capture errors yet so run each till it overflows then back off by 1.
Don't need the program that tests for this.
 */

//System Libraries
#include <iostream>
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
    bool ovFlw=false;
    char ch=1, tCh=1, mChF=0;
    unsigned char uCh=1, tUch=1, mUchF=0;
    short sh=1, tSh=1, mShF=0;
    unsigned short uSh=1, tUsh=1, mUshF=0;
    int in=1, tIn=1, mInF=0;
    unsigned int uIn=1, tUin=1, mUinF=0;
    long lo=1, tLo=1, mLoF=0;
    unsigned long uLo=1, tUlo=1, mUloF=0;
    float flt=1, tFlt=1, mFltF=0;
    double dub=1, tDub=1, mDubF=0;
    
    //Input Values
    
    //Process by mapping inputs to outputs
    //test for Char overflow
    for (char i=1;!ovFlw;i++){
        ovFlw=false;
        tCh=ch;
        ch*=i;
        if (ch/i != tCh) {
            ovFlw=true;
        } else mChF=i;
    }
    cout<<"Max Fact char: "<<static_cast<int>(mChF)<<endl;
    
    //Test for unsigned char overflow
    ovFlw=false;
    for (unsigned char i=1;!ovFlw;i++){
        ovFlw=false;
        tUch=uCh;
        uCh*=i;
        if (uCh/i != tUch) {
            ovFlw=true;
        } else mUchF=i;
    }
    cout<<"Max Fact unsigned char: "<<static_cast<int>(mUchF)<<endl;
    
    //Test for Short overflow
    sh=1;
    tSh=1;
    mShF=0;
    ovFlw=false;
    for (short i=1;!ovFlw;i++){
        ovFlw=false;
        tSh=sh;
        sh*=i;
        if (sh/i != tSh) {
            ovFlw=true;
        } else mShF=i;
    }
    cout<<"Max Fact short: "<<mShF<<endl;
    
    //Test for Unsigned Short overflow
    uSh=1;
    tUsh=1;
    mUshF=0;
    ovFlw=false;
    for (unsigned short i=1;!ovFlw;i++){
        ovFlw=false;
        tUsh=uSh;
        uSh*=i;
        if (uSh/i != tUsh) {
            ovFlw=true;
        } else mUshF=i;
    }
    cout<<"Max Fact unsigned short:"<<mUshF<<endl;
    
    //test for int overflow
//Data type method **DOESN"T WORK
//Endless loop. WHy???
/*
    for (int i=1;i*tIn<=2147483647;i++) {
        cout<<tIn<<endl;
        tIn*=i;
        cout<<"Count "<<i<<": "<<tIn<<endl;
        mInF=i;
    }
    cout<<"Max Factorial for int: "<<mInF<<endl;
*/
    
    in=1;
    tIn=1;
    mInF=0;
    ovFlw=false;
    for (int i=1;!ovFlw;i++){
        ovFlw=false;
        tIn=in;
        in*=i;
        if (in/i != tIn) {
            ovFlw=true;
        } else mInF=i;
    }
    cout<<"Max Fact int:"<<mInF<<endl;
    
    //test for unsigned int overflow
    uIn=1;
    tUin=1;
    mUinF=0;
    ovFlw=false;
    for (unsigned int i=1;!ovFlw;i++){
        ovFlw=false;
        tUin=uIn;
        uIn*=i;
        if (uIn/i != tUin) {
            ovFlw=true;
        } else mUinF=i;
    }
    cout<<"Max Fact unsigned int: "<<mUinF<<endl;
    
    //Test for long int
    lo=1;
    tLo=1;
    mLoF=0;
    ovFlw=false;
    for (long i=1;!ovFlw;i++){
        ovFlw=false;
        tLo=lo;
        lo*=i;
        if (lo/i != tLo) {
            ovFlw=true;
        } else mLoF=i;
    }
    cout<<"Max Fact long: "<<mLoF<<endl;
    
    //test for unsigned long int
    uLo=1;
    tUlo=1;
    mUloF=0;
    ovFlw=false;
    for (unsigned long i=1;!ovFlw;i++){
        ovFlw=false;
        tUlo=uLo;
        uLo*=i;
        if (uLo/i != tUlo) {
            ovFlw=true;
        } else mUloF=i;
    }
    cout<<"Max Fact unsigned long: "<<mUloF<<endl;
    
    //test for float overflow
    flt=1;
    tFlt=1;
    mFltF=0;
    ovFlw=false;
    for (float i=1;!ovFlw;i++){
        ovFlw=false;
        cout<<setprecision(0)<<fixed;
        tFlt=flt;
        flt*=i;
        if (flt/i != tFlt) {
            ovFlw=true;
        } else mFltF=i;
    }
    cout<<"Max Fact float - precision: "<<setprecision(0)<<fixed<<mFltF<<endl;
    
    float testrng=1;
    int maxFlt=0;
    for (int i=1;testrng<=3.402823466e38f;i++){
        testrng*=i;
        cout<<setprecision(0)<<fixed;
        maxFlt=i-1;
    }
    cout<<"Max Fact float - range: "<<maxFlt<<endl;
    
    //test for double overflow
    dub=1;
    tDub=1;
    mDubF=0;
    ovFlw=false;
    for (double i=1;!ovFlw;i++){
        ovFlw=false;
        tDub=dub;
        dub*=i;
        if (dub/i != tDub) {
            ovFlw=true;
        } else mDubF=i;
    }
    cout<<"Max Fact double - precision: "<<setprecision(0)<<fixed<<mDubF<<endl;
    
    double testDub=1;
    int maxDub=0;
    for (int i=1;testDub<=1.757e308;i++){
        testDub*=i;
        maxDub=i-1;
    }
    cout<<"Max Fact double - range: "<<maxDub<<endl;

    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

