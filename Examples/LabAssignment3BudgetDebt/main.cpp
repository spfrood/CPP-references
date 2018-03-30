/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 16, 2017, 7:00 PM
  Purpose:  Percentage budget and Debt/Person
  Write a program to calculate the percentage of the federal budget that the 
  Military and NASA are funded.  You might be surprised.
  Here are your references to use for 2016
  3.54 Trillion       US total spending -->  
  http://federal-budget.insidegov.com/l/119/2016-Estimate  ->  3.54 trillion
  $580 Billion       Military Budget -> 
  https://cit.com/thought-leadership/us-defense-spending-industry-outlook/
  ?cmp=paidsearch&gclid=CPmllfC1uNECFQRsfgodj-cAEA&jcpid=8a8ae4cd56581431015659
  d1200a185b&jsf=5ec7b876-08cf-488f-876c-21ae0d1e84e9:35584
  18.5 Billion       NASA Budget ->  
  https://www.nasa.gov/sites/default/files/files
  /NASA_FY2016_Summary_Brief_corrected.pdf
  2)  Calculate the Debt per person given the following years.
  Here are your references to use
  Population 2008  -> 304 Million
  Population 2016  -> 322 Million
  http://www.tradingeconomics.com/united-states/population
  Federal Debt as of  2008  ->  9.7 Trillion
  Federal Debt as of  2016  ->   20 Trillion
  http://www.usdebtclock.org/    and    http://www.usdebtclock.org/2008.html
 */

//System Libraries
#include <iostream> //Input - Output stream library
#include <iomanip>  //Format Library
using namespace std;//Standard namespace

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const char  PERCENT = 100;    //Conversion to a percentage
const float THOUSND = 1.0e3f; //1 Thousand =             1,000
const float MILLION = 1.0e6f; //1 Million  =         1,000,000
const float BILLION = 1.0e9f; //1 Billion  =     1,000,000,000
const float TRILION = 1.0e12f;//1 Trillion = 1,000,000,000,000

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    float  usBdgt = 3.54e12f,//Federal  Budget $3.54 Trillion
          milBdgt = 5.80e11f,//Military Budget $580  Billion
          nsaBdgt = 1.85e10f,//NASA     Budget $18.5 Billion
          pop2008 = 3.04e8f, //US       Population in 2008  304 Million people
          pop2016 = 3.22e8f, //US       Population in 2016  322 Million people
          dbt2008 = 9.70e12f,//US       Debt in 2008 $'s owed by all citizens
          dbt2016 = 2.00e13f;//US       Debt in 2016 $'s owed by all citizens
    float pcntMil,pcntNSA;   //Percentage Military and NASA Budget
    float psnDt08,psnDt16;   //Per person debt in 2008 and 2016
    float incPP,incDbt;      //Percentage increase of debt from 2008 to 2016
    
    //Calculate from the knowns then convert
    pcntMil=milBdgt/usBdgt*PERCENT;  //Department of Defense Budget percentage
    pcntNSA=nsaBdgt/usBdgt*PERCENT;  //NASA percentage budget
    psnDt08=dbt2008/pop2008/THOUSND; //Debt $/person in thousands for 2008
    psnDt16=dbt2016/pop2016/THOUSND; //Debt $/person in thousands for 2016
    incPP=psnDt16/psnDt08*PERCENT;   //Percentage increase in per person debt
    incDbt=dbt2016/dbt2008*PERCENT;  //Percentage increase in total debt
    
    //Output values
    cout<<fixed<<setprecision(2)<<showpoint<<endl;
    cout<<"Budgets given in the problem and documented."<<endl;
    cout<<"US   Budget 2016 = $"<<setw(6)<<usBdgt/TRILION<<" Trillion"<<endl;
    cout<<"DOD  Budget 2016 = $"<<setw(6)<<milBdgt/BILLION<<" Billion"<<endl;
    cout<<"NASA Budget 2016 = $"<<setw(6)<<nsaBdgt/BILLION<<" Billion"<<endl;
    cout<<endl;
    cout<<"Military \"DOD\" percentage = "<<pcntMil<<"%"<<endl;
    cout<<"NASA           percentage =  "<<pcntNSA<<"%"<<endl<<endl;
    cout<<"Are you surprised???"<<endl<<endl;
    cout<<"Yearly Budgets not covered by taxes increase our debt!"<<endl;
    cout<<"Debt as of 2008 = $  "<<dbt2008/TRILION<<" Trillion"<<endl;
    cout<<"Debt as of 2016 = $ "<<dbt2016/TRILION<<" Trillion"<<endl<<endl;
    cout<<"2008 debt/person = $ "<<psnDt08<<" Thousand/Person"<<endl;
    cout<<"2016 debt/person = $ "<<psnDt16<<" Thousand/Person"<<endl;
    cout<<"The increase in per person debt is = "<<incPP<<"%"<<endl;
    cout<<"The increase in total debt is      = "<<incDbt<<"%"<<endl;
    
    //Exit stage right!
    return 0;
}