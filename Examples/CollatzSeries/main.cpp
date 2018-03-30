/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 30, 2017, 12:23 PM
  Purpose:  Collatz Series
            Added Bonus -> Bit shifting and MVC pattern with arrays
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    int SIZE=1000;
    int array[SIZE]={22,};//Initialize the entire array to zero except first
    int series=array[0],cnt=1;//Initialize the series and the counter
    
    //Empirically prove the Collatz Conjecture
    cout<<"Output without using the array, have to calculate as you go"<<endl;
    cout<<series<<" ";
    //Change the value of the series as you go
    do{
        if(series%2){
            series=1+series+(series<<1);//3*series+1
        }else{
            series>>=1;//divide by 2
        }
        cout<<series<<" ";  //Output the present value of the series
        array[cnt++]=series;//Fill the array
    }while(series>1);
    cout<<endl<<"Length of the series = "<<cnt<<endl;
    
    //Output the array
    cout<<endl<<"Output an array with a for-loop after calculations"<<endl;
    for(int i=0;i<cnt;i++){
        cout<<array[i]<<" ";
    }

    //Exit stage right!
    return 0;
}