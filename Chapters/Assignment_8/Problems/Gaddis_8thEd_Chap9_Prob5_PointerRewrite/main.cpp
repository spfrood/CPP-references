
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 11, 2017, 7:12 PM
 * Purpose: 5. Pointer Rewrite
The following function uses reference variables as parameters. Rewrite the 
function so it uses pointers instead of reference variables, and then 
demonstrate the function in a complete program.

int doSomething(int &x, int &y) {
    int temp = x; 
    x = y * 10;
    y = temp * 10; 
    return x + y;
}
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
int doSomething(int *, int *); //Function from book that needs conversion to pointer

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int varOne=0, varTwo=0, varProd=0; //some variables to work with
    int *ptrOne= &varOne; //pointer to variable one
    int *ptrTwo= &varTwo; //pointer to variable two
    
    //Input Values
    cout<<"Input an integer for variable One: "<<endl;
    cin>>*ptrOne; //Sets value of varOne via pointer
    cout<<"Input an integer for variable Two: "<<endl;
    cin>>*ptrTwo; //Sets value of varTwo via pointer
    
    //Process by mapping inputs to outputs
    cout<<"The function output is: "<<varProd<<endl; //variable before function run and output into it
    cout<<"The value of varOne is: "<<varOne<<endl; //value of varOne int variable
    cout<<"ptrOne points at: "<<ptrOne<<endl; //ptrOne memory location
    cout<<"*ptrOne value is: "<<*ptrOne<<endl; //value of memory location ptrOne points at
    cout<<"The value of varTwo is: "<<varTwo<<endl; //value of varTwo int variable
    cout<<"ptrTwo points at: "<<ptrTwo<<endl; //ptrTwo memory location
    cout<<"*ptrTwo value is: "<<*ptrTwo<<endl; //value of memory location ptrTwo points at
    cout<<endl;
    cout<<"After running the function: "<<endl;
    varProd=doSomething(ptrOne, ptrTwo);
    
    //Output values
    cout<<"The function output is: "<<varProd<<endl; //variable before function run and output into it
    cout<<"The value of varOne is: "<<varOne<<endl; //value of varOne int variable
    cout<<"ptrOne points at: "<<ptrOne<<endl; //ptrOne memory location
    cout<<"*ptrOne value is: "<<*ptrOne<<endl; //value of memory location ptrOne points at
    cout<<"The value of varTwo is: "<<varTwo<<endl; //value of varTwo int variable
    cout<<"ptrTwo points at: "<<ptrTwo<<endl; //ptrTwo memory location
    cout<<"*ptrTwo value is: "<<*ptrTwo<<endl; //value of memory location ptrTwo points at
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//function modified to use pointers
int doSomething(int *x, int *y) {
    int temp = *x; 
    *x = *y * 10;
    *y = temp * 10; 
    return *x + *y;
}