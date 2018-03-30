
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 10:35 AM
 * Purpose: Statistics for Throwing 2 Dice 
 */

//System Libraries
#include <iostream> //input output libraries
#include <ctime> //time for setting random seed
#include <cstdlib> //random number functions
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random number seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned int nThrows=36000; //Number of times to throw pair of dice
    unsigned int n2=0, n3=0, n4=0, n5=0, n6=0, n7=0, n8=0, n9=0, n10=0, n11=0, n12=0;
    
    //Loop and take dice statistics
    for (int toss=1;toss<=nThrows;toss++){
        //call random number generator for each die
        char die1 = rand()%6+1; //value from 1 to 6
        char die2 = rand()%6+1; //value from 1 to 6
        char sum = die1 + die2;
        switch (sum){
            case 2:n2++;break;
            case 3:n3++;break;
            case 4:n4++;break;
            case 5:n5++;break;
            case 6:n6++;break;
            case 7:n7++;break;
            case 8:n8++;break;
            case 9:n9++;break;
            case 10:n10++;break;
            case 11:n11++;break;
            case 12:n12++;break;
            default: cout<<"You are in error"<<endl;
        }
    }
    
    //Output values
    cout<<"2  was trown "<<n2<<" times"<<endl;
    cout<<"3  was trown "<<n3<<" times"<<endl;
    cout<<"4  was trown "<<n4<<" times"<<endl;
    cout<<"5  was trown "<<n5<<" times"<<endl;
    cout<<"6  was trown "<<n6<<" times"<<endl;
    cout<<"7  was trown "<<n7<<" times"<<endl;
    cout<<"8  was trown "<<n8<<" times"<<endl;
    cout<<"9  was trown "<<n9<<" times"<<endl;
    cout<<"10 was trown "<<n10<<" times"<<endl;
    cout<<"11 was trown "<<n11<<" times"<<endl;
    cout<<"12 was trown "<<n12<<" times"<<endl;
    cout<<"The total throws = "<<n2+n3+n4+n5+n6+n7+n8+n9+n10+n11+n12<<endl;
    cout<<"The total throws = "<<nThrows<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

