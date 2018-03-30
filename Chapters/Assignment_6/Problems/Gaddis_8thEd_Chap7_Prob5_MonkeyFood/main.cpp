
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 8:16 PM
 * Purpose: 5. Monkey Business
A local zoo wants to keep track of how many pounds of food each of its three 
monkeys eats each day during a typical week. Write a program that stores this 
information in a two-dimensional 3 × 5 array, where each row represents a 
different monkey and each column represents a different day of the week. The 
program should first have the user input the data for each monkey. Then it 
should create a report that includes the following information:
• Average amount of food eaten per day by the whole family of monkeys.
• The least amount of food eaten during the week by any one monkey.
• The greatest amount of food eaten during the week by any one monkey.
Input Validation: Do not accept negative numbers for pounds of food eaten.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
const int COLDAY = 5;

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int MKYROW=3;
    int foodAte[MKYROW][COLDAY]={};
    float avgFood=0.0;
    int totEat=0, mostAte=0, mstEatR=0, mstEatC=0,lestAte=0, lstEatR=0, lstEatC=0;
    //Input Values
    cout<<"Please enter the amount eaten each day by each monkey (pounds):"<<endl;
    for (int i=0;i<MKYROW;i++){
        for (int j=0;j<COLDAY;j++){
            do { 
                cout<<"Please input the food eaten by Monkey "<<(i+1)<<" on day "<<(j+1)<<": ";
                cin>>foodAte[i][j];
                if (foodAte[i][j]<0)cout<<"Must be zero or more pounds!"<<endl;
            } while (foodAte[i][j]<0);
        }
    }
    mostAte=foodAte[0][0];
    mstEatR=1;
    mstEatC=1;
    lestAte=foodAte[0][0];
    lstEatR=1;
    lstEatC=1;
    
    //Process by mapping inputs to outputs
    cout<<"The average food eaten per day per monkey s:"<<endl;
    for (int i=0;i<COLDAY;i++){
        totEat=0;
        for (int j=0;j<MKYROW;j++){
            totEat+=foodAte[j][i];
        }
        avgFood=totEat/3.00f;
        cout<<setprecision(2)<<fixed<<showpoint;
        cout<<"The average food eaten on day "<<(i+1)<<" per monkey was "
            <<avgFood<<" pounds."<<endl;
        cout<<setprecision(0)<<fixed;
    }
    
    for (int i=0;i<MKYROW;i++){
        for (int j=0;j<COLDAY;j++){
            if (mostAte<foodAte[i][j]){
                mostAte=foodAte[i][j];
                mstEatR=i+1;
                mstEatC=j+1;
            }
        }
    }
    cout<<"The most eaten was by monkey "<<mstEatR<<", who ate "<<mostAte<<
            " pounds on day "<<mstEatC<<"."<<endl;
    
    for (int i=0;i<MKYROW;i++){
        for (int j=0;j<COLDAY;j++){
            if (lestAte>foodAte[i][j]){
                lestAte=foodAte[i][j];
                lstEatR=i+1;
                lstEatC=j+1;
            }
        }
    }
    cout<<"The least eaten was by monkey "<<lstEatR<<", who ate "<<lestAte<<
            " pounds on day "<<lstEatC<<"."<<endl;
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

