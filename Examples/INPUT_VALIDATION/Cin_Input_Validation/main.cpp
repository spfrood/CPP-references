
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 11, 2017
 * Purpose: Write a program that inserts various input from the user
 * into appropriate sections of a short story.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    string perName, citName, colName, jobName, aniType, petName;
    short age;
    
    
    //Input Values
    cout<<"Please provide the details requested at each prompt in order"<<endl;
    cout<<"to complete the story."<<endl<<endl;
    cout<<"Please enter your name:"<<endl;
    getline(cin, perName);
    cout<<"Please enter your age:"<<endl;
    cin>>age;
    
    while (cin.fail()) //Loop to validate input
    {
        cout<<"cin Flags: "<<endl;
        cout << cin.fail() << endl;  //output the cin.fail condition
        cout << cin.bad() << endl; //output the cin.bad condition
        cout << cin.good() << endl; //output the cin.good condition
        cout << cin.eof() << endl; //output the cin.eof conditions
        cin.clear();  //Resetting flags               
        cin.ignore(256, '\n'); //ignore contents of buffer
        cout<<"cin Flags after cin.clear(): "<<endl;
        cout << cin.fail() << endl;  //output the cin.fail condition
        cout << cin.bad() << endl; //output the cin.bad condition
        cout << cin.good() << endl; //output the cin.good condition
        cout << cin.eof() << endl; //output the cin.eof conditions
        
        cout<<"Please enter your age:"<<endl;
        cin>>age;
        //cout<<age;
    }
    
    cin.ignore();
    cout<<"Please enter the name of a city:"<<endl;
    getline(cin, citName);
    cout<<"Please enter the name of a college:"<<endl;
    getline(cin, colName);
    cout<<"Please enter the name of a profession:"<<endl;
    getline(cin, jobName);
    cout<<"Please enter the name of a type of animal"<<endl;
    getline(cin, aniType);
    cout<<"Please enter the name for a pet:"<<endl;
    getline(cin, petName);
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"There once was a person named "<<perName<<" who lived in "<<
            citName<<"."<<endl;
    cout<<"At the age of "<<age<<" "<<perName<<" went to "
            "college at "<<colName<<". "<<perName<<endl;
    cout<<"graduated and went to work as a "<<jobName<<". Then "<<perName<<
            " adopted"<<endl;
    cout<<"a(n) "<<aniType<<" named "<<petName<<". They both lived happily "
            "ever after!"<<endl;
            
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

