
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 3, 2017, 6:10 PM
 * Purpose: 4. Personal Information Class
Design a class that holds the following personal data: name, address, age, and 
phone number. Write appropriate accessor and mutator functions. Demonstrate the 
class by writing a program that creates three instances of it. One instance 
should hold your information, and the other two should hold your friends’ 
or family members’ information.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "AddBook.h" //Address book

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int size;
    cout<<"Enter the number of entries in the Address Book"<<endl;
    cin>>size; //Enter size of the address book
    cin.ignore();
    AddBook *book = new AddBook[size]; //initialize dynamic array 
    
    //Input Values for make and year
    for (int i=0;i<size;i++) { //loop to enter address book data
        cout<<"Enter information for entry "<<i+1<<endl;
        book[i].setData();
    }
    //Process by mapping inputs to outputs
    
    //Output values 
    for (int i=0;i<size;i++) { //loop to display address book data
        cout<<"Contact info for entry "<<i+1<<endl;
        book[i].disData();
        cout<<endl;
    }
    
    //Clean up memory
    delete [] book;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

