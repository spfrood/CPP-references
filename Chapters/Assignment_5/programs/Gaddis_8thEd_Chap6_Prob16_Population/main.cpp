
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 1, 2017, 10:01 PM
 * Purpose: 16. Population
In a population, the birth rate is the percentage increase of the population 
due to births, and the death rate is the percentage decrease of the population 
due to deaths. Write a program that displays the size of a population for any 
number of years. The program should ask for the following data:
• The starting size of a population
• The annual birth rate
• The annual death rate
• The number of years to display
Write a function that calculates the size of the population for a year. The 
formula is
    N = P + BP − DP
where N is the new population size, P is the previous population size, B is 
the birth rate, and D is the death rate. 
Input Validation: Do not accept numbers less than 2 for the starting size. 
Do not accept negative numbers for birth rate or death rate. Do not accept 
numbers less than 1 for the number of years.
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
float newPop(float, float, float, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float bornPer=0, diePer=0, popSize=0;
    int nYears;
    
    //Input Values
    do{
    cout<<"Please input the initial population size:"<<endl;
    cin>>popSize;
    if (popSize<2)cout<<"Too low of a starting population!"<<endl;
    } while (popSize<2);
    do{
    cout<<"Please input the birthrate (as a decimal so 10% = 0.10):"<<endl;
    cin>>bornPer;
    if (bornPer<0) cout<<"Birthrate must be a positive number!"<<endl;
    } while (bornPer<0);
    do{
    cout<<"Please enter the deathrate (as a decimal so 10% = 0.10):"<<endl;
    cin>>diePer;
    if (diePer<0) cout<<"Deathrate must be a positive number!"<<endl;
    } while (diePer<0);
    do{
    cout<<"How many years population would you like to see?"<<endl;
    cin>>nYears;
    if (nYears<1) cout<<"You must enter more than 1 years!"<<endl;
    }while (nYears<1);

    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"The population will grow as follows:"<<endl;
    newPop(popSize, bornPer, diePer, nYears);
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float newPop(float pop, float brate, float drate, int years){
    cout<<"Starting   population: "<<setprecision(0)<<fixed<<setw(10)<<pop<<endl;
    for (int starPop=1;starPop<=years;starPop++){
        pop+=((pop*brate)-(pop*drate));
        if (pop<0) pop=0;
        cout<<"Year "<<setprecision(0)<<fixed<<setw(4)<<starPop<<": Population: "<<setw(10)<<pop<<endl;
    }
    return pop;
}