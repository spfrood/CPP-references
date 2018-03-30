
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries
#define CB_BLAC      "\033[1m\033[30m"      /* Bold Black */
#define CB_RED       "\033[1m\033[31m"      /* Bold Red */
#define CB_GREE      "\033[1m\033[32m"      /* Bold Green */
#define CB_YELL      "\033[1m\033[33m"      /* Bold Yellow */
#define CB_BLUE      "\033[1m\033[34m"      /* Bold Blue */
#define CB_MAGE      "\033[1m\033[35m"      /* Bold Magenta */
#define CB_CYAN      "\033[1m\033[36m"      /* Bold Cyan */
#define C_RESET      "\x1b[0m"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //initialize random seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SPINNER=20;
    int spinRec[SPINNER]={};
    unsigned int spin=0;
    bool end=true;
    char endChar='N';
    char choice='X';
    
    //Input Values
    for (int i=0;i<20;i++){
        spinRec[i]=rand()%35; //random 0 to 35
    }
    
    //Process by mapping inputs to outputs
    do {
        for (int i=0;i<20;i++){
            cout<<spinRec[i]<<endl;
        }

        for (int i=19;i>=0;i--){
            spinRec[i+1]=spinRec[i];
        }
        spinRec[0]=rand()%35;

        
        cout<<"Spin Again(Y/N)?"<<endl;
        cin>>endChar;
        if ((endChar=='N')||endChar=='n'){
            end=false;
        }
        else end=true;
    } while (end);
    
    
    
/*  
void swap(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}    
*/ 
    
    //Output values
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

