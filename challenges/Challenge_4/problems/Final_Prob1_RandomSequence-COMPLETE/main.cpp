
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on June 5, 2017, 9:56 AM
 * Purpose: Problem #1  (Random Sequence)
	Create a class that
returns a random number from the following set,
{16,33,56,78,126}.  Loop 100,000 times with this 
procedure and print the frequency of each of the 
5 numbers obtained.  The following is the 
specification for the class.

 * Extra Credit: 2.5 pts->Convert Problem 1 by using templates in place of the 
	character arrays.

Specification

class Prob1Random
{
	private:
		char *set;      //The set of numbers to draw random numbers from
		char  nset;     //The number of variables in the sequence
		int  *freq;     //Frequency of all the random numbers returned
		int   numRand;  //The total number of times the random number function is called
	public:
		Prob1Random(const char,const char *);     //Constructor
		~Prob1Random(void);                       //Destructor
		char randFromSet(void);                   //Returns a random number from the set
		int *getFreq(void) const;                 //Returns the frequency histogram
		char *getSet(void) const;                 //Returns the set used
		int getNumRand(void) const;               //Gets the number of times randFromSet has
		                                          //been called
};

Driver program to return a random sequence
    char n=5;
    char rndseq[]={17,33,56,79,126};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
        cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;

Sample Output

17 occured 20045 times
33 occured 19952 times
56 occured 20035 times
79 occured 20039 times
126 occured 19929 times
The total number of random numbers is 100000

Note:  Your results are not expected to be exactly the
same!  After all these are pseudo-random number sequences
with different seeds.

 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//User Libraries
#include "Prob1Random.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
//or columns for 2D arrays

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char n=5;
    char rndseq[]={17,33,56,79,126};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    
    //Input Values
    
    //Process by mapping inputs to outputs
    for(int i=1;i<=ntimes;i++)
    {
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    //Output values
    for(int i=0;i<n;i++)
    {
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
//
//    x[3]=4;
//    y[3]=99;
//    char *z=a.getSet();
//    int *w=a.getFreq();
//    for(int i=0;i<n;i++)
//    {
//        cout<<int(z[i])<<" occurred "<<x[i]<<" times"<<endl;
//    }
    
    //Clean up memory
    delete [] x;
    delete [] y;
//    delete [] z;
//    delete [] w;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

