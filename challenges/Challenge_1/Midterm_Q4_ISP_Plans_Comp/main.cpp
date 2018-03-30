
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 25, 2017, 11:35 PM
 * Purpose: 4) An ISP has 3 different subscription packages
 *	a)  $16.75 per month, 5 hours access.  Additional hours
 *	    are $0.75 up to 20 hours then $1 for all additional
 *	    hours.
 *	b)  $23.75 per month, 15 hours access.  Additional hours
 *          are $0.55 up to 25 hours then $0.70 for each
 *	    hour above this limit.
 *	c)  $29.95 per month unlimited access
 * Write a program that calculates a customers monthly bill.  
 * Ask which package, and how many hours then display the monthly charge.  
 * Also, output when customers should transition to another package and 
 * what package that should be to save the most money.  Calculate the 
 * money saved. 
 */


//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int hours;
    float totDueA=0, totDueB=0, totDueC=0, subTot=0;
    char package;
    
    //Input Values
    do{
    cout<<"Please enter your cell phone package, A, B, or C:"<<endl;
    cin>>package;
    } while ((package!='A')&&(package!='a')&&(package!='B')&&(package!='b')&&
            (package!='C')&&(package!='c'));
    cout<<"How many hours did you use?"<<endl;
    cin>>hours;
    
    //Process by mapping inputs to outputs
    if (hours<=5) totDueA=16.75;
        else if (hours>5&&hours<=20) totDueA=(16.75+(hours-5)*0.75);
        else totDueA=(16.75+((hours-20)*1)+(15*0.75));
    if (hours<=15) totDueB=23.75;
        else if (hours>15&&hours<=25) totDueB=(23.75+(hours-15)*0.55);
        else totDueB=(23.75+((hours-25)*0.70)+10*0.55);
    totDueC=29.95;
    
    //Output values
    if ((package == 'A')||(package=='a')) {
        cout<<"Package A Details"<<endl;
        cout<<"Your total due is: $"<<setprecision(2)<<fixed
                <<showpoint<<totDueA<<endl;
    }
    else if ((package == 'B')||(package == 'b')) {
        cout<<"Package B Details"<<endl;
        cout<<"Your total due is: $"<<setprecision(2)<<fixed
                <<showpoint<<totDueB<<endl;
    }
    else if ((package == 'C')||(package == 'c')) {
        cout<<"Package C Details"<<endl;
        cout<<"Your total due is: $"<<setprecision(2)<<fixed
                <<showpoint<<totDueC<<endl;
    }
    else cout<<"If this is displaying something went wrong somewhere"<<endl;
    
    if ((totDueA<totDueB)&&(totDueA<totDueC)) {
        cout<<"Plan A was the cheapest option for this number of hours."<<endl;
        cout<<"It would have saved $"<<setprecision(2)<<fixed
                <<showpoint<<totDueB-totDueA<<" over plan B and $"
                <<setprecision(2)<<fixed <<showpoint<<totDueC-totDueA
                <<" over plan C."<<endl;
    } else if ((totDueB<totDueA)&&(totDueB<totDueC)) {
        cout<<"Plan B was the cheapest option for this number of hours."<<endl;
        cout<<"It would have saved $"<<setprecision(2)<<fixed <<showpoint
                <<totDueA-totDueB<<" over plan A and $"<<setprecision(2)
                <<fixed <<showpoint<<totDueC-totDueB<<" over plan C."<<endl;  
    } else if ((totDueC<totDueA)&&(totDueC<totDueB)) {
        cout<<"Plan C was the cheapest option for this number of hours."<<endl;
        cout<<"It would have saved $"<<setprecision(2)<<fixed <<showpoint
                <<totDueA-totDueC<<" over plan A and $"<<setprecision(2)
                <<fixed <<showpoint<<totDueB-totDueC<<" over plan B."<<endl;  
    }
    cout<<"Your cost on each plan would have been:"<<endl;
    cout<<"Total for Plan A: $"<<setprecision(2)<<fixed <<showpoint
            <<totDueA<<endl;
    cout<<"Total for Plan B: $"<<setprecision(2)<<fixed <<showpoint
            <<totDueB<<endl;
    cout<<"Total for plan C: $"<<setprecision(2)<<fixed <<showpoint
            <<totDueC<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}
