
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: 7) Factor an input integer into it's prime numbers.  Create a 
structure to hold the array of prime numbers.  Any number between
[2,10000] where n is not a prime > 100 will be a valid number to
check for prime factors.

struct Prime{
	unsigned char prime;
	unsigned char power;
};
struct Primes{
	Prime *prime;
	unsigned char nPrimes;
};
Output the number and it's primes -> 120 = 2^3*3^1*5^1
So create a function 
Primes *factor(int);-> Input an integer, return all prime factors
void prntPrm(Primes *); -> Output all prime factors
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "primes.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short number=0, powCtr=0, numPrm=0;
    Primes values;
    values.prime=nullptr;
    
    //Input Values
    cout<<"Enter a number between 2 and 10000"<<endl;
    cin>>number; //input number to find the prime factors
    while (cin.fail() || number<2 || number>10000) { //validate input range
        cout<<"ERROR! Invalid Entry! Try Again!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>number;
    }
    values.prime=new Prime[number/2]; //set array to half the size of input number
    //Process by mapping inputs to outputs
    
    for (int i=2;i<=number;i++) { //loop through to find factors
        while (number%i==0) { //check to see how many times the value can be factored
            number/=i; //new value for number
            powCtr++; //power of factor
        }
        values.prime[numPrm].power=powCtr; //set value in array
        values.prime[numPrm].prime=i; //set value in array
        if (powCtr>0) numPrm++; //increment number of primes (move to next array element)
        powCtr=0; //reset power counter
    }
    
    for (int i=0;i<numPrm;i++) { //output the values in the array
        cout<<"Prime: "<<values.prime[i].prime<<"   Power: "<<values.prime[i].power<<endl;
    }
    
    //Output values and clean up memory
    delete [] values.prime;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

