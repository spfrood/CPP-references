
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 3, 2017, 9:56 AM
 * Purpose: 2. Employee Class
Write a class named Employee that has the following member variables:
• name. A string that holds the employee’s name.
• idNumber. An int variable that holds the employee’s ID number.
• department. A string that holds the name of the department where the employee
works.
• position. A string that holds the employee’s job title.
The class should have the following constructors:
• A constructor that accepts the following values as arguments and assigns them 
to the appropriate member variables: employee’s name, employee’s ID number, 
department, and position.
• A constructor that accepts the following values as arguments and assigns them 
to the appropriate member variables: employee’s name and ID number. The 
department and position fields should be assigned an empty string ("").
• A default constructor that assigns empty strings ("") to the name, department, 
and position member variables, and 0 to the idNumber member variable.
Write appropriate mutator functions that store values in these member variables 
and accessor functions that return the values in these member variables. Once 
you have written the class, write a separate program that creates three Employee 
objects to hold the following data.
Name                    ID Number     Department      Position
Susan Meyers            47899         Accounting      Vice President
Mark Jones              39119         IT              Programmer
Joy Rogers              81774         Manufacturing   Engineer


     The program should store this data in the three objects and then display 
the data for each employee on the screen.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Worker.h" //worker class

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    Worker Emp1, Emp2, Emp3; //create worker objects
    string a, b, c; //data for input testing methods (experimentation)
    int n; //data for input testing methods (experimentation)
    
    //Input Values
    a="Susan Meyers"; //For testing. Not necessary to do this way.
    n=47899; //For testing. Not necessary to do this way.
    b="Accounting"; //For testing. Not necessary to do this way.
    c="Vice President"; //For testing. Not necessary to do this way.
    Emp1.setVals(a, n, b, c); 
    Emp2.setVals("Mark Jones", 39119, "IT", "Programmer"); //for sake of homework passing literals
    Emp3.setVals("Joy Rogers", 81774, "Manufacturing", "Engineer"); //for sake of homework passing literals
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    cout<<"Employee 1:"<<endl;
    Emp1.dWorker(); //output employee 1 values
    cout<<endl;
    cout<<"Employee 2:"<<endl;
    Emp2.dWorker(); //output employee 2 values
    cout<<endl;
    cout<<"Employee 3:"<<endl;
    Emp3.dWorker(); //output employee 3 values
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

