/* 
 * File:   main.cpp
 * Author: Revised by Scott Parker
 * Created on: March 18, 2017, 2:27 PM
 * Purpose: Lab 3 Luhn Algorithm
 * Luhn number for credit card generation
You will use the concepts from your previous program and the reference to create
your next program.
Very similar to last assignment. 
For each, 1) transpose 2 numbers, 2) flip 2 numbers 
Loop 10,000 times and record how many valid vs. invalid Credit Cards are 
detected for 1) and 2)
Submit here, copy yourself on an email to: mark.lehr@rcc.edu 
subject: Lastname, Firstname - Lab 3 Luhn Algorithm  - 42645
 * Check the following website for more reference on credit card numbers
       http://www.getcreditcardnumbers.com/
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit(); //Generate random digit (character in range of 0-9)
void prpLuhn(char *,int); //Prepare a random number to use for LUHN conversion
void conLuhn(char *,int); //convert the prepared number to a LUHN number
bool valLuhn(char *,int); //Validate to see if the number is a valid LUHN
int rndCard(int &); //Function to randomly choose credit card type
void swapPre(char *,int); //Function to replace random digits with CC MII digits
void tstLuhn(char *,int); //Function to swap digits and test result 10000 times
void tst2Lun(char *,int); //Function to run 2 different tests on the Luhn card number

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int size=0; //set credit card size to base of zero
    int prefix=0; //set prefix to unused value
    int choice=0; //set choice for exit value 
    
    //Inputs
    cout<<"What type of card would you like to make?"<<endl;
    cout<<"Choose credit card simulation type? <non-numeric data will be ignored>"<<endl;
    cout<<"Type 1 for American Express: "<<endl;
    cout<<"Type 2 for Visa: "<<endl;
    cout<<"Type 3 for Mastercard: "<<endl;
    cout<<"Type 4 for Discover Card: "<<endl;
    cout<<"Type 5 for a random card: "<<endl;
    cin>>choice;
    while (cin.fail()||choice<1||choice>5) //Loop to validate input
        {
        cout<<"INPUT INVALID! "<<endl;
        cin.clear();  //Resetting flags               
        cin.ignore(256, '\n'); //ignore contents of buffer
        cout<<"Please enter a valid choice!:"<<endl;
        cin>>choice;
        }

    //Switch to determine the Problem
    switch(choice){
        case 5:{size=rndCard(prefix);break;}
        case 4:{size=17; prefix=4;break;}
        case 3:{size=17; prefix=3;break;}
        case 2:{size=17; prefix=2;break;}
        case 1:{size=16; prefix=1;break;}
        default:
            cout<<"You are exiting the program! Something broke!"<<endl;
        }
    
    char *crdCard=new char[size]; //Array that contains the random LUHN'ed card digits without prefix
    
    //Prepare for Luhn encoding
    prpLuhn(crdCard,size-2);
    cout<<"Generating random card number: "<<crdCard<<endl;
    
    //Output the preLuhn credit card with inserted prefix
    cout<<"Inserting "; 
    if (prefix==1) cout<<"American Express";
    if (prefix==2) cout<<"Visa";
    if (prefix==3) cout<<"Mastercard";
    if (prefix==4) cout<<"Discover Card";
    cout<<" prefix: ";
    swapPre(crdCard, prefix);
    cout<<crdCard<<endl;
    
    //Now call function that fills the last digit using the Luhn Algorithm
    cout<<"Converting to LUHN and adding last digit: ";
    conLuhn(crdCard,size-1); //function to fill last digit
    cout<<crdCard<<endl; //Output the final Luhn
    
    //Call function to check to see if valid Luhn
    cout<<"Validating Luhn Sequence: ";
    if (valLuhn(crdCard,size-1)) cout<<crdCard<<" is a valid Luhn!"<<endl;
    else cout<<crdCard<<" is not a valid Luhn!"<<endl;
    cout<<endl;
    
    //Test 10000 times with one digit randomly changed
    cout<<"Testing card with various mods: "<<endl;
    tstLuhn(crdCard,size-1);
    cout<<endl;
    //Test 10000 times with 2 digits randomly changed
    //Also test 10000 times with 2 digits transposed
    tst2Lun(crdCard,size-1);
    
    //clean up memory
    delete [] crdCard;
    
    //Exit Stage Right
    return 0;
}

//Function that runs 2 different tests on the Luhn
void tst2Lun(char *cc,int n){
    int tests=10000;
    int temp=0, flip=0;
    int counter=0;
    int sze=n;
    char *ccc=new char[sze];
    
    for (int loop=0;loop<tests;loop++){ //Test LUHN after randomly replacing 2 digits
        temp=0, flip=0;
        for (int j=0;j<n;j++){
            ccc[j]=cc[j];
        }
        flip=rand()%n; //Determine which digit to flip
        ccc[flip]=rand()%9+48; //replace digit with random value
        flip=rand()%n; //Determine which digit to flip
        ccc[flip]=rand()%9+48; //replace digit with random value
        //Sum the numbers adjusting for char
        for (int i=0;i<n;i++){
            temp+=(ccc[i]-48);
        }
        //test to see if Luhn is valid
        if (temp%10==0) counter++; //Luhn is valid if sum of digits mod 10 is 0
    }
    cout<<setprecision(4)<<showpoint;
    cout<<"Twice flipped Luhn was valid: "<<(((static_cast<float>(counter))/tests)*100)<<"% of the time"<<endl;
    cout<<"Twice flipped Luhn had "<<counter<<"/"<<tests<<" valid returns."<<endl;
    cout<<endl;
    counter=0;
    for (int loop=0;loop<tests;loop++){ //Test LUHN after transposing 2 digits
        int dig1=0, dig2=0;
        temp=0;
        for (int j=0;j<n;j++){
            ccc[j]=cc[j];
        }
        dig1=rand()%n; //Determine transposition spot 1
        dig2=rand()%n; //Determine transposition spot 2
        char swap='\0';
        swap=ccc[dig1];
        ccc[dig1]=ccc[dig2];
        ccc[dig2]=swap;
        //Sum the numbers adjusting for char
        for (int i=0;i<n;i++){
            temp+=(ccc[i]-48);
        }
        //test to see if Luhn is valid
        if (temp%10==0) counter++; //Luhn is valid if sum of digits mod 10 is 0
    }
    cout<<setprecision(4)<<showpoint;
    cout<<"Transposed Luhn was valid: "<<(((static_cast<float>(counter))/tests)*100)<<"% of the time"<<endl;
    cout<<"Transposed Luhn had "<<counter<<"/"<<tests<<" valid returns."<<endl;
    
    //clean up memory
    delete [] ccc;
}

//Function to randomize one digit then test Luhn and repeat 10000 times
void tstLuhn(char *cc,int n){
    int tests=10000;
    int temp=0, flip=0;
    int counter=0;
    int sze=n;
    char *ccc=new char[sze];
    
    for (int loop=0;loop<tests;loop++){
        temp=0, flip=0;
        for (int j=0;j<n;j++){
            ccc[j]=cc[j];
        }
        flip=rand()%n; //Determine which digit to flip
        ccc[flip]=rand()%9+48; //replace random digit
        //Sum the numbers adjusting for char
        for (int i=0;i<n;i++){
            temp+=(ccc[i]-48);
        }
        //test to see if Luhn is valid
        if (temp%10==0) counter++; //Luhn is valid if sum of digits mod 10 is 0
    }
    cout<<setprecision(4)<<showpoint;
    cout<<"Flipped Luhn was valid: "<<(((static_cast<float>(counter))/tests)*100)<<"% of the time"<<endl;
    cout<<"Flipped Luhn had "<<counter<<"/"<<tests<<" valid returns."<<endl;
    
    //clean up memory
    delete [] ccc;
}

//Function to replace first digits of card with correct digits for that card 
//type
void swapPre(char *cc,int pref){
    int digs=0;
    switch(pref){ //Insert different possible card prefixes
        case 4:{ //Prefixes for Discover
            int types=rand()%4; //Does not matter because only one Discover prefix used
            switch(types){
                default:{
                    cc[0]='6';cc[1]='0';cc[2]='1';cc[3]='1';
                }
            }
            break;
        }
        case 3:{ //Prefixes for MasterCard
            int types=rand()%5; //determine which of the 5 possible MasterCard prefixes to use
            switch(types){
                case 4:{cc[0]='5';cc[1]='1';break;}
                case 3:{cc[0]='5';cc[1]='2';break;}
                case 2:{cc[0]='5';cc[1]='3';break;}
                case 1:{cc[0]='5';cc[1]='4';break;}
                default:{
                    cc[0]='5';cc[1]='5';
                }
            }
            break;
        }
        case 2:{ //Prefixes for Visa
            int types=rand()%7; //Determine which of the 7 possible Visa prefixes to use
            switch(types){
                case 6:{cc[0]='4';cc[1]='5';cc[2]='3';cc[3]='9';break;}
                case 5:{cc[0]='4';cc[1]='5';cc[2]='5';cc[3]='6';break;}
                case 4:{cc[0]='4';cc[1]='9';cc[2]='1';cc[3]='6';break;}
                case 3:{cc[0]='4';cc[1]='5';cc[2]='3';cc[3]='2';break;}
                case 2:{cc[0]='4';cc[1]='9';cc[2]='2';cc[3]='9';break;}
                case 1:{cc[0]='4';cc[1]='4';cc[2]='8';cc[3]='5';break;}
                default:{
                    cc[0]='4';cc[1]='7';cc[2]='1';cc[3]='6';
                }
            }
            break;
        }
        case 1:{ //Prefixes for American Express
            int types=rand()%2; //Determine which of the 2 possible American Express prefixes to use
            switch(types){
                case 1:{cc[0]='3';cc[1]='7';break;}
                default:{
                    cc[0]='3';cc[1]='4';
                }
            }
            break;
        }
        default:{
            cout<<"Something wrong! Something Broke!"<<endl; //Should never have this output. It means something broke
        }
    }
    
}

//Function to randomly determine card type
int rndCard(int &prefix){
    int cType=0, temp=0;
    prefix=rand()%4+1;
    if (prefix==1){
        cType=16;
    } else {
        cType=17;
    }

    return cType;
}

//Function to check to see if number is valid Luhn
bool valLuhn(char *cc,int n){
    short temp=0;
    bool result=false;
    //Sum the numbers adjusting for char
    cout<<"temp+ = ";
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

//Function to convert random number to a Luhn number
void conLuhn(char *cc,int n){
    for (int i=n-2;i>=0;i-=2){ //Double every 2nd digit
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
    temp=temp*9; //Multiply sum by 9
    temp=temp%10; //Obtain final digit value by modding sum by 10
    cc[n-1]=(temp+48); //add the final digit to the Luhn number
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

//function to prepare a random number to use in creating a Luhn number
void prpLuhn(char *cc,int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

//Generate a random character that is in the 0-9 range on ASCII table
char rndDgit(){
    return rand()%10+48;
}


