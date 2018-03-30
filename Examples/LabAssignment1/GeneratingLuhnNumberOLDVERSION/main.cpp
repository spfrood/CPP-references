/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 21, 2017, 8:35 AM
 * Revised by Scott Parker
 * February 22, 2017, 11:30 AM
 * Purpose: Luhn number for credit card generation
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();
void prpLuhn(char[],int);
void Luhn(char[],int);
bool valLuhn(char[],int);

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=12;
    char crdCard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    cout<<"The random number with Luhn Encoding, Output Here!"<<endl;
    Luhn(crdCard,SIZE-1); //function to fill last digit
    cout<<"Final Luhn number is: "<<endl;
    cout<<crdCard<<endl; //Output the final Luhn
    cout<<"Validating Luhn Sequence: "<<endl;
    //Test the final number to see if it's a valid Luhn
    if (valLuhn(crdCard,SIZE-1)) cout<<crdCard<<" is a valid Luhn!"<<endl;
    else cout<<crdCard<<" is not a valid Luhn!"<<endl;
    
    
    //Exit Stage Right
    return 0;
}

bool valLuhn(char cc[],int n){
    short temp=0;
    bool result=false;
    //Sum the numbers adjusting for char
    for (int i=0;i<n;i++){
        temp+=(cc[i]-48);
        cout<<temp<<" "; //output the sum so far
    }
    cout<<endl;
    //test to see if Luhn is valid
    if (temp%10==0) result=true; //Luhn is valid if sum of digits mod 10 is 0
    else result=false; //Luhn is not valid otherwise
    return result; //return the result value (true or false)
}

void Luhn(char cc[],int n){
    for (int i=1;i<=(n-2);i+=2){ //Double every 2nd digit
        cc[i]=(cc[i]-48)*2;
        if (cc[i]>9){ //if doubled digit > 9 then add the two digits together
            cc[i]=(cc[i]%10+cc[i]/10);
        }
        cc[i]=cc[i]+48; //restore value in array to the numerical value not int value
    }
    short temp=0; 
    //Sum all of the digits
    for (int i=0;i<=(n-2);i++){
        temp+=(cc[i]-48);
    }
    cout<<"Every other digit doubled and summed if greater than 9: "<<endl;
    //Output the current working Luhn
    cout<<cc<<endl;
    temp=temp*9; //Multiply sum by 9
    temp=temp%10; //Obtain final digit value by modding sum by 10
    cout<<"summing digits, multiply by 9, mod by 10. Result is final digit."<<endl;
    cc[n-1]=(temp+48); //add the final digit to the Luhn number
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;
}



