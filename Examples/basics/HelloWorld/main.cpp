/* 
   File:   main
   Author: Dr. Mark E. Lehr
   Created on August 29, 2016, 9:41 AM
   Purpose:  First Program -> Hello World
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
    int x;//An integer variable
    
    //Input values
    std::cout<<"Type in an integer variable"<<endl;
    std::cin>>x;
    
    //Process values -> Map inputs to Outputs
    x=2*x;
    
    //Display Output
    cout<<"Hello World 2x = "<<x<<std::endl;

    //Exit Program
    return 0;
}