
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Problem 2
 * 
Write a program that plays the game "Guess the
Number" as follows.  Your program chooses the
number to be guessed by selecting an unsigned integer
at random in the range 1 to 10^X.  The program
inputs X and displays


I have a number between 1 and 10^X
Can you guess my number?  You will be
given a maximum integer of (log2(10^X)+1) guesses.
Please type your first guess.


The player then types a guess.  The
program responds with one of the following.


1. Congratulations, You guessed the number!
   Would you like to play again(y or n)?
2. Too low.  Try again.
3. Too High. Try again.
4. Too many tries.

Flowchart your code.

Note:  if you type in X=3 then integer of log2(10^3)+1=10;
 * 
 * 
**Unsigned int max 4,294,967,295
**10^9 is 1,000,000,000. Larger than 9 is out of bounds for unsigned int
** for an unsigned int datatype
*/

//System Libraries
#include <iostream>
#include <cstdlib> //to use rand
#include <ctime> //To get time
#include <cmath> //for logs
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned int guessNm=0; //Number to be guessed
    unsigned int maxNum=0; //Upper range of random
    unsigned int plrGues=0; //number entered by player to guess
    short x=0; //input by user to determine number (max value of 9)
    short maxGues=0; //Max number of guesses allowed
    short guesCnt=0; //Guess counter
    bool goGuess = true;
    
    //Input Values
    do {  //Getting the x for 10^x as per assignment instructions
        cout<<"Please input a number from 1 to 9: "<<endl;
        cin>>x;
        if (x<1||x>9) cout<<"Value out of range!"<<endl;
    } while (x<1||x>9);
    
    //Process by mapping inputs to outputs
    maxNum=pow(10,x); //Max number for random function
    guessNm=rand()%maxNum+1; //Number to be guessed
    maxGues=log2(maxNum)+1; //Max number of guesses allowed
    cout<<"I have a number between 1 and "<<maxNum<<endl;
    cout<<"Can you guess my number?  You will be"<<endl;
    cout<<"given a maximum of "<<maxGues<<" guesses."<<endl;
    
    //Output values
    do { //play the game
        goGuess=false;
        cout<<"Please enter guess number "<<++guesCnt<<":"<<endl;  
        if (guesCnt==maxGues){ //Output to warn that this is the last guess
            cout<<"This is your last guess!"<<endl;
        }
        cin>>plrGues;
        if (plrGues==guessNm) {  //Output if guess is correct
            cout<<"You got it! "; 
            goGuess=false;
        } else if (plrGues>guessNm){  //Notify guess too large
            cout<<"Your guess is too large!"<<endl;
            goGuess=true;
        } else if (plrGues<guessNm){  //notify guess too low
            cout<<"Your guess is too low!"<<endl;
           goGuess=true;
        }
        else {
            cout<<"This should not be displayed. Something broke."<<endl;
        }
    } while (goGuess&&(guesCnt<maxGues));
    cout<<"The number was "<<guessNm<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

