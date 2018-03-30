/* 
  File:   main.cpp
  Author: Dr. Scott Parker
  Created on February 2, 2017, 12:28 PM
  Purpose:  Assignment 5 Homework Menu
 */

//System Libraries
#include <iostream>//Input Output Library
#include <iomanip> //Format Library
#include <cmath> //For math functions
#include <string> //working with strings
#include <cstdlib> //for random function
#include <ctime> //set random seed
using namespace std;

//User Libraries
#define C_RED     "\x1b[31m"  //For red text
#define C_GREEN   "\x1b[32m"  //for green text
#define C_CYAN    "\x1b[36m"  //for cyan text
#define C_RESET   "\x1b[0m"   //rest color to black

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();


float calculateRetail(float, float); //Name is specified in book! 
float futValu(float,float,int);
float newPop(float, float, float, int);
int getSales(string);
void findHighest(float, float, float, float);
int getNumAccidents(string);
void findLowest(int, int, int, int, int);
float kinEner(float, float);
float celsius(float);
int coinToss();
float prValue(float,float,int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Problem 1: Wholesale Markup"<<endl;
        cout<<"Type 2 for Problem 2: Future Value "<<endl;
        cout<<"Type 3 for Problem 3: Population Growth "<<endl;
        cout<<"Type 4 for Problem 4: Winning Division "<<endl;
        cout<<"Type 5 for Problem 5: Safest Driving Area "<<endl;
        cout<<"Type 6 for Problem 6: Kinetic Energy "<<endl;
        cout<<"Type 7 for Problem 7: Celsius Temperature Table "<<endl;
        cout<<"Type 8 for Problem 8: Coin Toss "<<endl;
        cout<<"Type 9 for Problem 9: Present Value (future savings calc) "<<endl;
        cout<<"Enter a number not listed to exit."<<endl;
        cin>>choice;

        //Switch to determine the Problem
        switch(choice){
            case 9:{prob9();break;}
            case 8:{prob8();break;}
            case 7:{prob7();break;}
            case 6:{prob6();break;}
            case 5:{prob5();break;}
            case 4:{prob4();break;}
            case 3:{prob3();break;}
            case 2:{prob2();break;}
            case 1:{prob1();break;}
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>=1&&choice<=9);
    
    //Exit stage right!
    return 0;
}

void prob9(){
    //Declare Variables
    float futrVal,iRate,iRatPer;
    int nYears;
    
    //Input values
    cout<<"Please enter your desired future savings value:"<<endl;
    cin>>futrVal;
    cout<<"Please enter the interest rate (percentage):"<<endl;
    cin>>iRatPer;
    iRate=iRatPer*0.01;
    cout<<"Please enter the number of years this will compound:"<<endl;
    cin>>nYears;
 
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"If you deposit : $"<<setprecision(2)<<fixed<<showpoint
            <<prValue(futrVal,iRate,nYears)<<" right now"<<endl;
    cout<<"you will have $"<<setprecision(2)<<fixed<<showpoint<<futrVal
            <<" after "<<nYears<<" years at "<<iRatPer<<"% interest."<<endl;

    //Exit stage right!
    cout<<endl;
}

void prob8(){
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 1, 2017, 7:04 PM
 * Purpose: 8. Coin Toss
Write a function named coinToss that simulates the tossing of a coin. When 
you call the function, it should generate a random number in the range of 1 
through 2. If the random number is 1, the function should display “heads.” 
If the random number is 2, the function should display “tails.” Demonstrate 
the function in a program that asks the user how many times the coin should 
be tossed and then simulates the tossing of the coin that number of times. 
 */
    //Set random number seed
    //Random seed set in MAIN already
    
    //Declare Variables
    int heads=0, tails=0, flip=0, toss=0;
    
    //Input Values
    
    //Process by mapping inputs to outputs
    cout<<"How many times would you like to flip the coin?"<<endl;
    cin>>flip;
    for (int i=1;i<=flip;i++){
        cout<<i<<".  ";
        toss=coinToss();
        if (toss==1)heads++;
        if (toss==2)tails++; 
    }
    
    //Output values
    cout<<"Your coin came up heads "<<heads<<" times."<<endl;
    cout<<"Your coin came up tails "<<tails<<" times."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    cout<<endl;
}

void prob7(){   
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 11, 2017
 * Purpose: Problem 7 Celsius Temperature Table
The formula for converting a temperature from Fahrenheit to Celsius is
C   59(F   32)
where F is the Fahrenheit temperature and C is the Celsius temperature. Write 
a function named celsius that accepts a Fahrenheit temperature as an 
argument. The function should return the temperature, converted to Celsius. 
Demonstrate the function by calling it in a loop that displays a table of the 
Fahrenheit temperatures 0 through 20 and their Celsius equivalents.
 */
    //Declare Variables
    float fahTemp=0.0f;
    //Input Values
    cout<<"This program accepts a Fahrenheit temperature as input and will"<<endl;
    cout<<"Convert it to Celsius. It will also give the conversions of the"<<endl;
    cout<<"temperatures 10 degrees Fahrenheit below the provided temperature"<<endl;
    cout<<"and conversions for temperatures 10 degrees above the provided"<<endl;
    cout<<"temperature. What temperature would you like to convert to Celsius?"<<endl;
    cin>>fahTemp;
    
    //Process by mapping inputs to outputs
    
    //Output values
    for (int i=(fahTemp-10);i<=(fahTemp+10);i++){
        if (i<fahTemp){
            cout<<C_CYAN<<setprecision(2)<<fixed<<showpoint<<i
                    <<" F  =  "<<celsius(i)<<" C"<<C_RESET<<endl;
        }
        else if (i==fahTemp){
            cout<<C_GREEN<<setprecision(2)<<fixed<<showpoint<<i
                    <<" F  =  "<<celsius(i)<<" C"<<C_RESET<<endl;
        }
        else {
            cout<<C_RED<<setprecision(2)<<fixed<<showpoint<<i
                    <<" F  =  "<<celsius(i)<<" C"<<C_RESET<<endl;
        }
    }
    
    //Exit stage right! - This is the 'return 0' call
    cout<<endl;
}

void prob6(){

/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 2, 2017, 9:47 AM
 * Purpose: 6. Kinetic Energy
In physics, an object that is in motion is said to have kinetic energy. The
following formula can be used to determine a moving object’s kinetic energy:
 *   KE = 1/2 m v^2
The variables in the formula are as follows: KE is the kinetic energy, m is 
the object’s mass in kilograms, and v is the object’s velocity, in meters per 
second. Write a function named kineticEnergy that accepts an object’s mass 
(in kilograms) and velocity (in meters per second) as arguments. The function 
should return the amount of kinetic energy that the object has. Demonstrate 
the function by calling it in a program that asks the user to enter values 
for mass and velocity.
 */
    //Declare Variables
    float mass=0.0f, velo=0.0f;
    
    //Input Values
    do{
    cout<<"Please input the mass of the object (kilograms):"<<endl;
    cin>>mass;
    if (mass<=0)cout<<"An object has to have mass to be an object!"<<endl;
    } while (mass<=0);
    do{
    cout<<"Please input the velocity of the object (meters per second):"<<endl;
    cin>>velo;
    if (velo<0) cout<<"Velocity must be a positive value!"<<endl;
    } while (velo<0);
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"The kinetic energy of the object is:"<<endl;
    cout<<setprecision(2)<<fixed<<kinEner(mass, velo)<<" joules."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    cout<<endl;;
}

void prob5(){

/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 1, 2017, 12:05 PM
 * Purpose: 4. Safest Driving Area 
Write a program that determines which of five geographic regions within a 
major city (north, south, east, west, and central) had the fewest reported 
automobile accidents last year. It should have the following two functions, 
which are called by main .
• int getNumAccidents() is passed the name of a region. It asks the user for 
the number of automobile accidents reported in that region during the last 
year, validates the input, then returns it. It should be called once for each 
city region.
• void findLowest() is passed the five accident totals. It determines which 
is the smallest and prints the name of the region, along with its accident 
figure.
 
Input Validation: Do not accept an accident number that is less than 0. 
 */ 
    //Declare Variables
    string nortRiv="North Riverside";
    string eastRiv="East Riverside";
    string soutRiv="South Riverside";
    string westRiv="West Riverside";
    string centRiv="Central Riverside";
    int noRiv, eaRiv, soRiv, weRiv, ceRiv;
    
    //Input Values
    noRiv=getNumAccidents(nortRiv);
    eaRiv=getNumAccidents(eastRiv);
    soRiv=getNumAccidents(soutRiv);
    weRiv=getNumAccidents(westRiv);
    ceRiv=getNumAccidents(centRiv);
    
    //Process by mapping inputs to outputs
    findLowest(noRiv,eaRiv,soRiv,weRiv,ceRiv);
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    cout<<endl;
}

void prob4(){
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 1, 2017, 12:05 PM
 * Purpose: 3. Winning Division
Write a program that determines which of a company’s four divisions (Northeast,
Southeast, Northwest, and Southwest) had the greatest sales for a quarter. It 
should include the following two functions, which are called by main .
• double getSales() is passed the name of a division. It asks the user for a 
division’s quarterly sales figure, validates the input, then returns it. It 
should be called once for each division.
 ** USING FLOAT NOT DOUBLE
• void findHighest() is passed the four sales totals. It determines which is 
the largest and prints the name of the high grossing division, along with its 
sales figure. 

Input Validation: Do not accept dollar amounts less than $0.00.
 */
    //Declare Variables
    string noeaRiv="Northeast Division";
    string soeaRiv="Southeast Riverside";
    string soweRiv="Southwest Riverside";
    string noweRiv="Northwest Riverside";
    float neRiv, seRiv, swRiv, nwRiv;
    
    //Input Values
    neRiv=getSales(noeaRiv);
    seRiv=getSales(soeaRiv);
    swRiv=getSales(soweRiv);
    nwRiv=getSales(noweRiv);
    
    //Process by mapping inputs to outputs
    findHighest(neRiv,seRiv,swRiv,nwRiv);
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    cout<<endl;
}

void prob3(){
    
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
    cout<<endl;
}


void prob1(){
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 31, 2017, 1:02 PM
 * Purpose: Gaddis, 8thEd, Chap6, Prob1
 * Problem 1. Markup
 * Write a program that asks the user to enter an item’s wholesale cost and 
 * its markup percentage. It should then display the item’s retail price. For 
 * example:
 * • If an item’s wholesale cost is 5.00 and its markup percentage is 100%, then
 * the item’s retail price is 10.00.
 * • If an item’s wholesale cost is 5.00 and its markup percentage is 50%, then
 * the item’s retail price is 7.50.
 * The program should have a function named calculateRetail that receives the 
 * wholesale cost and the markup percentage as arguments and returns the retail
 * price of the item.
 * Input Validation: Do not accept negative values for either the wholesale 
 * cost of the item or the markup percentage.
 */
    //Declare Variables
    float wholCst=0.00f, markUp=0.00f;
    
    //Input Values
    do{
        cout<<"Enter the item's wholesale price: "<<endl;
        cin>>wholCst;
        cout<<"Enter the item's markup percentage (enter percentage value,"<<endl;
        cout<<"no decimal. Value less than 1.0 will return less than 1%)"<<endl;
        cin>>markUp;
        //Outputting instructions if negative value entered
        if (wholCst<0||markUp<0) cout<<"Do not enter negative values!"<<endl;
    } while (wholCst<0||markUp<0);
    
    //Process by mapping inputs to outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The retail price is $"<<calculateRetail(wholCst, markUp)<<endl;
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    cout<<endl;
}

void prob2(){
/* 
  File:   main.cpp
  Author: Scott Parker
  Created on February 1, 2017, 9:45 PM
  Purpose:  Problem 10. Future Value
Suppose you have a certain amount of money in a savings account that earns 
compound monthly interest, and you want to calculate the amount that you will 
have after a specific number of months. The formula, which is known as the 
future value formula, is:
 * FV = PV * (1 + i)^t
The terms in the formula are as follows:
• F is the future value of the account after the specified time period.
• P is the present value of the account.
• i is the monthly interest rate.
• t is the number of months.
Write a program that prompts the user to enter the account’s present value, 
monthly interest rate, and the number of months that the money will be left 
in the account. The program should pass these values to a function named 
futureValue that returns the future value of the account, after the specified 
number of months. The program should display the account’s future value.
 */
    
    //Declare Variables
    float presVal,iRate,iRatPer;
    int nMonth;
    
    //Input values
    cout<<"Please enter your present value:"<<endl;
    cin>>presVal;
    cout<<"Please enter the monthly interest rate (percentage):"<<endl;
    cin>>iRatPer;
    iRate=iRatPer*0.01;
    cout<<"Please enter the number of months this will compound:"<<endl;
    cin>>nMonth;
 
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"If you deposit : $"<<setprecision(2)<<fixed<<showpoint
            <<presVal<<" right now"<<endl;
    cout<<"you will have $"<<setprecision(2)<<fixed<<showpoint<<futValu(presVal,iRate,nMonth)
            <<" after "<<nMonth<<" months at "<<iRatPer<<"% interest."<<endl;

    //Exit stage right!
    cout<<endl;
}

float calculateRetail(float cost, float margin){
    //Convert the markup value to a percentage
    float marPer=margin/100;
    return (cost*marPer+cost);
}

float futValu(float value,float intRate,int months){
    //Formula is FV = PV * (1 + i)^t
    return (value*(pow((1+intRate),months)));
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

void findHighest(float neRi, float seRi, float swRi, float nwRi){
    float highSle=neRi;
    string noeaRiv="Northeast Division";
    string soeaRiv="Southeast Riverside";
    string soweRiv="Southwest Riverside";
    string noweRiv="Northwest Riverside";
    string highReg=noeaRiv;
    if (highSle<seRi){
        highReg=soeaRiv;
        highSle=seRi;
    }
    if (highSle<swRi){
        highReg=soeaRiv;
        highSle=swRi;
    }
    if (highSle<nwRi){
        highReg=noweRiv;
        highSle=nwRi;
    }
    cout<<highReg<<" had the most sales with $"<<setprecision(2)<<fixed<<showpoint
            <<highSle<<endl;
    
}

int getSales(string region){
    float saleNum;
    do {
    cout<<"Input the total sales for "<<region<<endl;
    cin>>saleNum;
    if (saleNum<0) cout<<"Invalid Sales Data!"<<endl;
    }while (saleNum<0);
    return saleNum;
}

void findLowest(int nRiv, int eRiv, int sRiv, int wRiv, int cRiv){
    int lowAcc=nRiv;
    string nortRiv="North Riverside";
    string eastRiv="East Riverside";
    string soutRiv="South Riverside";
    string westRiv="West Riverside";
    string centRiv="Central Riverside";
    string lowReg=nortRiv;
    if (lowAcc>eRiv){
        lowReg=eastRiv;
        lowAcc=eRiv;
    }
    if (lowAcc>sRiv){
        lowReg=soutRiv;
        lowAcc=sRiv;
    }
    if (lowAcc>wRiv){
        lowReg=westRiv;
        lowAcc=wRiv;
    }
    if (lowAcc>cRiv) {
        lowReg=centRiv;
        lowAcc=cRiv;
    }
    cout<<lowReg<<" had the lowest number at "<<lowAcc<<" accidents."<<endl;
    
}

//Input the number of accidents
int getNumAccidents(string region){
    int numAcc;
    do {
    cout<<"Input the number of accidents for "<<region<<endl;
    cin>>numAcc;
    if (numAcc<0) cout<<"Invalid Number of Accidents!"<<endl;
    }while (numAcc<0);
    return numAcc;
}

float kinEner(float objMass, float objVelo){
    //Formula is  *   KE = 1/2 m v^2
    return ((objMass*(objVelo*objVelo))/2);
}

float celsius(float fahTemp){
    float celTemp;
    celTemp = ((fahTemp-32)*5)/9;
    return celTemp;
}

int coinToss(){
    int coin = rand()%2+1; //value from 1 to 2
    if (coin==1)cout<<C_RED<<"Heads"<<C_RESET<<endl;
    if (coin==2)cout<<C_CYAN<<"Tails"<<C_RESET<<endl;
    return coin;
}

float prValue(float futVal,float intRate,int years){
    return (futVal/(pow((1+intRate),years)));
}