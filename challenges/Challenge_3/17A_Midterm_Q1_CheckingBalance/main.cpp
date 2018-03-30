
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on April 18, 2017, 12:19 PM
 * Purpose: 1)  Develop an application using structures for a customer
that will determine if he/she has exceeded his/her checking 
account balance. For each customer, the following 
facts are available:

a. Name
b. Address
c. Account number (Five digits only, i.e. test for this) **use strlen(name) to get length of string
d. Balance at the beginning of the month 
e. Total of all checks written by this customer this month 
     Loop until customer is through entering checks.
f. Total of all deposits credited to this customer's account this 
     month.  Loop until customer is through entering deposits.

Dynamically create the structure.
The program should input each of these facts from input dialogs,
store in a structure, calculate the new balance, 
display the new balance and debit the account $15 if overdrawn. 
Also, if overdrawn, tell the customer the additional $15 fee 
has been accessed and what the balance would be with this fee included.
Make sure to output the contents of the structure.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip> //manipulate output and formatting
#include <ctime> //for random seed
#include <cstdlib> //for rand() function


using namespace std;

//User Libraries
#include "accinfo.h" 

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes
AccInfo *filStrt(int, int); //Function to return structure and pass in #checks written and #checks deposited
void getChks(float *, int); //Function to input the number of checks 
void testBal(AccInfo *); //Output contents of structure and Check to see if overdrawn 
void destroy(AccInfo *); //function to delete pointers, arrays, and clean up memory


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int checks=0, deposit=0; //vars to set size of arrays
    
    //create and initialize structure - Get data for array sizes
    cout<<"How many checks did you write this month (at least 1)?"<<endl;
    cin>>checks; 
    while (cin.fail() || checks<1) { //Loop to validate input
        cin.clear();  //Resetting flags               
        cin.ignore(256, '\n'); //ignore contents of buffer
        cout<<"Please enter a valid number!:"<<endl;
        cin>>checks;
    }
    cout<<"How many deposits did you make this month (at least 1)?"<<endl;
    cin>>deposit;
    while (cin.fail() || deposit<1) { //Loop to validate input
        cin.clear();  //Resetting flags               
        cin.ignore(256, '\n'); //ignore contents of buffer
        cout<<"Please enter a valid number!:"<<endl;
        cin>>deposit;
    }
    AccInfo *account=filStrt(checks, deposit); //dynamically create structure 
    
    //Process by mapping inputs to outputs
    testBal(account); //check account balances
    
    //Output values
    
    
    //Clean up memory
    destroy(account); 
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}


//Function to return structure and pass in #checks written and #checks deposited
AccInfo *filStrt(int checks, int deps){
    string temp=""; //string to hold temporary data
    float tmpFlt=0.0f; //float to hold temporary data
    AccInfo *a=new AccInfo; //initialize new array
    a->outChck=checks; //set checks array size
    a->inDep=deps; //set deposit array size
    a->allChck=new float[a->outChck]; //create checks array
    a->allDep=new float[a->inDep]; //create deposits array
    cout<<"Enter customer's name:"<<endl;
    cin.ignore(256, '\n');
    getline(cin, temp); //get customer name
    a->cusName=temp;
    cout<<"Enter the customer's street address:"<<endl;
    getline(cin, temp); //get customer street address
    a->address=temp;
    cout<<"Enter the customer's city:"<<endl;
    getline(cin, temp); //get customer city
    a->city=temp;
    cout<<"Enter the customer's state: "<<endl;
    getline(cin, temp); //get customer state
    a->state=temp;
    cout<<"Enter the customer's postal code: "<<endl;
    cin>>a->zip; //get cusotmer postal code
    while (cin.fail() || a->zip<10000 || a->zip>99999){
        cout<<"Enter a 5-digit zip code from 10000 to 99999"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>a->zip;
    }
    cin.ignore(255, '\n');
    cout<<"Enter the customer's 5-digit account number:"<<endl;
    getline(cin, temp); //Get customer account number
    while(cin.fail() || temp.length()!=5){ //make sure account number 5 digits long
        cout<<"Account numbers must be 5 digits!"<<endl;
        cin.clear();
        getline(cin, temp);
    }
    a->accNum=temp; 
    cout<<"Enter the starting balance of the account (-1 for random 5000-9999)"<<endl;
    cin>>tmpFlt; //enter starting balance or choose random
    tmpFlt<=0?a->strtBal=rand()%4999+5000:a->strtBal=tmpFlt;
    cout<<"Starting account balance: $"<<a->strtBal<<endl;
    cout<<"Enter the values for the "<<a->outChck<<" checks written this month."<<endl;
    getChks(a->allChck, a->outChck); //call function to get the checks written values
    cout<<"Enter the values for the "<<a->inDep<<" depsoits made this month."<<endl;
    getChks (a->allDep, a->inDep); //call function to get the deposits made values
    return a; //return a (the structure)
}

//Function to input the number of checks 
void getChks(float *a, int size) {
    char choice='\0';
    cout<<"Randomize data with values from 1-1000? (Y/N)"<<endl;
    cin.ignore(256, '\n');
    cin>>choice; //randomize or not...
    for (int i=0;i<size;i++){ //loop through size of array
        cout<<setprecision(2)<<showpoint<<fixed; 
        if (choice=='y' || choice=='Y'){
            a[i]=rand()%999+1; //set and display random value if this option chosen
            cout<<"Entry number "<<i+1<<": $"<<a[i]<<endl;
        }
        else { //assign values manually if random not chosen
            int tmpFlt=0.0f;
            cout<<"Enter the amount for entry number "<<i+1<<": $";
            cin>>tmpFlt; //enter values manually if random not chosen
            while (cin.fail() || tmpFlt<=0){ //validate data range and type
                cout<<"Must enter a positive number!"<<endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin>>tmpFlt;
            }
            a[i]=tmpFlt;
        }
    }
} 

//Output contents of structure and Check to see if overdrawn 
void testBal(AccInfo *a) {
    bool paidFee=false; //boolean false for overdraft fee
    cout<<setprecision(2)<<showpoint<<fixed; 
    a->endBal=a->strtBal; //set the end balance to start balance
    for (int i=0;i<a->outChck;i++) { //loop through checks written
        a->endBal-=a->allChck[i]; //debit from end balance
    }
    for (int i=0;i<a->inDep;i++){ //loop through deposits
        a->endBal+=a->allDep[i]; //add to end balance
    }
    if (a->endBal<=0) { //check for overdraft
        cout<<"Your current balance is: $"<<a->endBal<<endl; 
        cout<<"Your balance is negative! You will be accessed a $15 overdraft fee!"<<endl;
        a->endBal-=15; //debit fee if overdraft
        cout<<"Your new balance is: $"<<a->endBal<<endl; //notify new balance
        paidFee=true; //bool to true for overdraft
    } else {
        cout<<"Your current balance is: $"<<a->endBal<<endl;
    }
    cout<<"Your total account activity is as follows: "<<endl;
    cout<<"Account Holder:  "<<a->cusName<<endl; //output structure data
    cout<<"                 "<<a->address<<endl;
    cout<<"                 "<<a->city<<", "<<a->state<<" "<<a->zip<<endl;
    cout<<endl;
    cout<<"Starting balance; $"<<a->strtBal<<"    Final balance: $"<<a->endBal<<endl;
    cout<<"Checks written: "<<endl;
    float temp=0.0f;
    for (int i=0;i<a->outChck;i++){ //loop through and output checks written
        if (i%3==0 && i!=0) cout<<endl;
        cout<<"  Check "<<setw(3)<<i+1<<": $"<<setw(8)<<right<<setprecision(2)<<showpoint<<fixed<<a->allChck[i];
        temp+=a->allChck[i];
    }
    cout<<endl;
    if (paidFee) cout<<"You were also debited a $15 overdraft fee."<<endl; //notify of fee paid
    cout<<"Total value of checks written: $"<<temp<<endl;
    cout<<endl;
    temp=0.0f;
    cout<<"Deposits made:"<<endl;
    for (int i=0;i<a->inDep;i++){ //loop through and output deposits made
        if (i%3==0 && i!=0) cout<<endl;
        cout<<"  Deposit "<<setw(3)<<i+1<<": $"<<setw(8)<<right<<setprecision(2)<<showpoint<<fixed<<a->allDep[i];
        temp+=a->allDep[i];
    }
    cout<<endl;
    cout<<"Total of all deposits made: $"<<temp<<endl;
}


//function to delete pointers, arrays, and clean up memory
void destroy(AccInfo *a) {
    delete []a->allChck;
    delete []a->allDep;
    delete a;
}