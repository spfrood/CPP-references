
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 25, 2017, 3:19 PM
 * Purpose: 11. Monthly Budget
A student has established the following monthly budget:
Housing                 500.00
Utilities               150.00
Household Expenses      65.00
Transportation          50.00
Food                    250.00
Medical                 30.00
Insurance               100.00
Entertainment           150.00
Clothing                75.00
Miscellaneous           50.00

Write a program that has a MonthlyBudget structure designed to hold each of 
these expense categories. The program should pass the structure to a function 
that asks the user to enter the amounts spent in each budget category during a 
month. The program should then pass the structure to a function that displays 
a report indicating the amount over or under in each category, as well as the 
amount over or under for the entire monthly budget.
 * 
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries
struct MonthlyBudget {
    float housing; //Housing
    float util; //Utilities
    float housExp; //Household Expenses
    float transpo; //Transportation
    float food; //Food
    float medical; //Medical
    float insur; //Insurance
    float enterta; //Entertainment
    float cloth;  //Clothing
    float misc; //Miscellaneous
};

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
MonthlyBudget rnBd01(MonthlyBudget); //Randomize budget input data
MonthlyBudget inBd02 (MonthlyBudget); //Input budget spending data manually
void cpBg03(MonthlyBudget, MonthlyBudget); //Compare actual spending to budget
void prBg04(MonthlyBudget); //Output values stored in a MonthlyBudget structure

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const MonthlyBudget BUDGET = {500.00, 150.00, 65.00, 50.00, 250.00,  //constant to hold projected budget values
                                  30.00, 100.00, 150.00, 75.00, 50.00};
    char chooser='N'; //variable used to make yes/no choices
    MonthlyBudget spnding; //Actual spending to be compared to budget
    
    //Input Values
    cout<<"Randomize data? (Y/y to randomize)"<<endl;
    cin>>chooser; //Randomize the budget if Y or y
    if (chooser=='Y' || chooser=='y') spnding=rnBd01(spnding); //fill with random data if Y
    else spnding=inBd02(spnding); //else enter data manually
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"Budget Allowances: "<<endl;
    prBg04(BUDGET); //Output the budget 
    cout<<endl;
    cout<<"Budget Spending: "<<endl;
    prBg04(spnding); //output the spending
    cout<<endl;
    cout<<"Budget Analysis: "<<endl;
    cpBg03(spnding, BUDGET); //compare spending to budget
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//Output values stored in a MonthlyBudget structure
void prBg04(MonthlyBudget x){
    cout<<setprecision(2)<<fixed;
    cout<<"Housing: $"<<x.housing<<endl; //output value of housing
    cout<<"Utilities: $"<<x.util<<endl; //output value of Utilities
    cout<<"Household Expenses: $"<<x.housExp<<endl; //output value of Household Expenses
    cout<<"Transportation: $"<<x.transpo<<endl; //output value of Transportation
    cout<<"Food: $"<<x.food<<endl; //output value of Food
    cout<<"Medical: $"<<x.medical<<endl; //output value of Medical
    cout<<"Insurance: $"<<x.insur<<endl; //output value of Insurance
    cout<<"Entertainment: $"<<x.enterta<<endl; //output value of Entertainment
    cout<<"Clothing: $"<<x.cloth<<endl; //output value of Clothing
    cout<<"Miscellaneous: $"<<x.misc<<endl; //output value of Miscellaneous
} 

//Randomize budget input data
MonthlyBudget rnBd01(MonthlyBudget x){
    x.housing=rand()%80000/100.00f; //Housing
    x.util=rand()%20000/100.00f; //Utilities
    x.housExp=rand()%8000/100.00f; //Household Expenses
    x.transpo=rand()%6500/100.00f; //Transportation
    x.food=rand()%30000/100.00f; //Food
    x.medical=rand()%4000/100.00f; //Medical
    x.insur=rand()%12000/100.00f; //Insurance
    x.enterta=rand()%17500/100.00f; //Entertainment
    x.cloth=rand()%9000/100.00f;  //Clothing
    x.misc=rand()%6500/100.00f; //Miscellaneous
    return x;
} 

//Input budget spending data manually
MonthlyBudget inBd02 (MonthlyBudget x){
    cout<<"Enter housing expenses: "<<endl;
    cin>>x.housing; //Housing
    cout<<"Enter utilities expenses: "<<endl;
    cin>>x.util; //Utilities
    cout<<"Enter household expenses: "<<endl;
    cin>>x.housExp; //Household Expenses
    cout<<"Enter transportation expenses: "<<endl;
    cin>>x.transpo; //Transportation
    cout<<"Enter food expenses: "<<endl;
    cin>>x.food; //Food
    cout<<"Enter medical expenses: "<<endl;
    cin>>x.medical; //Medical
    cout<<"Enter insurance expenses: "<<endl;
    cin>>x.insur; //Insurance
    cout<<"Enter entertainment expenses: "<<endl;
    cin>>x.enterta; //Entertainment
    cout<<"Enter clothing expenses: "<<endl;
    cin>>x.cloth;  //Clothing
    cout<<"Enter miscellaneous expenses: "<<endl;
    cin>>x.misc; //Miscellaneous
    return x;
} 

//Compare actual spending to budget
void cpBg03(MonthlyBudget x, MonthlyBudget b){
    float temp=0, totX=0, totBase=0;
    cout<<setprecision(2)<<fixed;
    temp=b.housing-x.housing; //over/under for housing
    if (temp>=0) cout<<"Housing had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Housing had a $"<<temp<<" deficit."<<endl;
    temp=b.util-x.util;
    if (temp>=0) cout<<"Utilities had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Utilities had a $"<<temp<<" deficit."<<endl;
    temp=b.housExp-x.housExp;
    if (temp>=0) cout<<"Household expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Household expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.transpo-x.transpo;
    if (temp>=0) cout<<"Transportation expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Transportation expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.food-x.food;
    if (temp>=0) cout<<"Food expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Food expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.medical-x.medical;
    if (temp>=0) cout<<"Medical expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Medical expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.insur-x.insur;
    if (temp>=0) cout<<"Insurance expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Insurance expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.enterta-x.enterta;
    if (temp>=0) cout<<"Entertainment expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Entertainment expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.cloth-x.cloth;
    if (temp>=0) cout<<"Clothing expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Clothing expenses had a $"<<temp<<" deficit."<<endl;
    temp=b.misc-x.misc;
    if (temp>=0) cout<<"Miscellaneous expenses had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if neg
    else cout<<"Miscellaneous expenses had a $"<<temp<<" deficit."<<endl;
    totX=x.cloth+x.enterta+x.food+x.housExp+x.housing+x.insur+x.medical+x.misc+x.transpo+x.util; //Total spending
    totBase=b.cloth+b.enterta+b.food+b.housExp+b.housing+b.insur+b.medical+b.misc+b.transpo+b.util; //Budget base allowance
    temp=totBase-totX;
    if (temp>=0) cout<<"Total budget had a $"<<temp<<" surplus."<<endl; //output surplus if positive, deficit if negative
    else cout<<"Total budget had a $"<<temp<<" deficit."<<endl;
}