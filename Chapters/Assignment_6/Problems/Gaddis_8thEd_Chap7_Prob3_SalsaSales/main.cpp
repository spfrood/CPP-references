
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 3:15 PM
 * Purpose: 3. Chips and Salsa
Write a program that lets a maker of chips and salsa keep track of sales for 
five different types of salsa: mild, medium, sweet, hot, and zesty. The 
program should use two parallel 5-element arrays: an array of strings that 
holds the five salsa names and an array of integers that holds the number of 
jars sold during the past month for each salsa type. The salsa names should 
be stored using an initialization list at the time the name array is created. 
The program should prompt the user to enter the number of jars sold for each 
type. Once this sales data has been entered, the program should produce a 
report that displays sales for each salsa type, total sales, and the names of 
the highest selling and lowest selling products.
Input Validation: Do not accept negative values for number of jars sold.
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
    int const SIZE=5;
    string typeAry [SIZE]={"Mild", "Medium", "Sweet", "Hot", "Zesty"};
    int saleAry [SIZE]={};
    string lowTyp;
    string highTyp;
    int totSale=0, lowest=0, highest=0;
    int lowTie=1;
    int highTie=1;
    
    //Input Values
    cout<<"Input the sales for each type of salsa... "<<endl;
    for (int i=0;i<SIZE;i++){
        do{
        cout<<typeAry[i]<<" sales was: ";
        cin>>saleAry[i];
        if (saleAry[i]<0) cout<<"Negative sales value not accepted!"<<endl;
        } while (saleAry[i]<0);
    }
    
    //Process by mapping inputs to output
    lowest=saleAry[0];
    highest=saleAry[0];
    lowTyp=typeAry[0];
    highTyp=typeAry[0];
    for (int i=1;i<SIZE;i++){
        if (saleAry[i]<lowest){
            lowest=saleAry[i];
            lowTyp=typeAry[i];
            lowTie=1;
        } 
        else if (saleAry[i]==lowest) {
            lowTie++;
        }
        if (saleAry[i]>highest){
            highest=saleAry[i];
            highTyp=typeAry[i];
            highTie=1;
        } else if (saleAry[i]==highest){
            highTie++;
        }
    }
    for (int i=0;i<SIZE;i++){
        totSale+=saleAry[i];
    }
    
    //Output values
    cout<<setprecision(2)<<fixed;
    cout<<"The lowest sales number was "<<lowest<<" jars for "<<lowTyp<<"."<<endl;
    if (lowTie>1)
        cout<<"     There were "<<lowTie<<" types total with these sales."<<endl;
    cout<<"The highest sales number was "<<highest<<" jars for "<<highTyp<<"."<<endl;
    if (highTie>1)
        cout<<"     There were "<<highTie<<" types total with these sales."<<endl;
    cout<<"The total number of jars sold was "<<totSale<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

