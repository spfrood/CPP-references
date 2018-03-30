/* 
   File:   main
   Author: Dr. Mark E. Lehr
   Created on September 7th, 2016, 9:47 AM
   Purpose:  
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    char s=' ';//The space character
    char c;    //Character used to create the Big C
    
    //Input values
    cout<<"What character would you like to use to make a Big C, input\n";
    cin>>c;
    
    //Process values -> Map inputs to Outputs
    
    //Display Output -> The Big C
    cout<<s<<s<<c<<c<<c<<endl;
    cout<<s<<c<<s<<s<<c<<endl;
    cout<<c<<s<<s<<s<<s<<endl;
    cout<<c<<s<<s<<s<<s<<endl;
    cout<<c<<s<<s<<s<<s<<endl;
    cout<<c<<s<<s<<s<<s<<endl;
    cout<<c<<s<<s<<s<<s<<endl;
    cout<<s<<c<<s<<s<<c<<endl;
    cout<<s<<s<<c<<c<<c<<endl;

    //Exit Program
    return 0;
}