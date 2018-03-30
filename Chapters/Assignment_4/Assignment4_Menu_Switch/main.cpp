
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 19, 2017, 11:30 PM
 * Purpose: Menu to implement programs from Assignment 4
 *  
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
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
    char choice;
    
    //Loop on the menu
    
    do {
        
        //Input Values
        cout<<"Choose a program to execute, 1 through 9."<<endl;
        cout<<"Enter a different value to exit"<<endl;
        cin>>choice;
        cout<<endl;
        
        //Switch to determine the problem
        switch(choice){
            case '1':{        
            // File:   main.cpp
            // Author: Scott Parker
            // Created on January 19, 2017, 1:25 PM
            // Purpose: Gaddis, 8th Edition, Chapter 5, Problem 13, The Greatest 
            // and Least of These
            // Write a program with a loop that lets the user enter a series of integers. 
            // The user should enter −99 to signal the end of the series. After all the 
            // numbers have been entered, the program should display the largest and 
            // smallest numbers entered.               
                int largest=0, least=0, holding=0; 
            //Input Values and check for validations
                cout<<"This program will find the largest and smallest number "
                        <<"entered."<<endl;
                cout<<"Enter integers separated by pressing the enter key."<<endl;
                cout<<"Enter the integer -99 to stop entering input."<<endl;
                do {
                    cout<<"Enter an integer:"<<endl;
                    cin>>holding;
                    largest = holding>largest?holding:largest;
                    least = holding<least?holding:least;
                } while (holding != -99);
                //Output
                cout<<"The largest integer input was: "<<largest<<endl;
                cout<<"The smallest integer input was: "<<least<<endl<<endl;
                //exit switch back to menu
                break;
            }
            case '2':{
            // File:   main.cpp
            // Author: Scott Parker
            // Created on January 17, 2017, 12:19 PM
            // Purpose: Gaddis, 8th Ed, Chap 5, Prob 1, Sum of Numbers
            // Write a program that asks the user for a positive integer value. The 
            // program should use a loop to get the sum of all the integers from 1 up to
            // the number entered. For example, if the user enters 50, the loop will find
            // the sum of 1, 2, 3, 4, ...50.
            // Input Validation: Do not accept a negative starting number.
                //Declare Variables
                long granSum=0;
                int totReps;
                //Input Values
                cout<<"This program will add up the sums of all numbers up to the"
                        <<"number entered."<<endl;
                cout<<"Please enter a positive integer up to a value of 65,000."<<endl;
                cin>>totReps;  //Number to add the sums up to
            //Process by mapping inputs to outputs
                if (totReps < 0) cout<<"You must enter a positive value!"; //Input validation
                else if (totReps > 65000) cout<<"Number too large!"; //More input validation to prevent out of bounds
                else {
                    for (int start = 0; start <= totReps; start++) {
                        granSum += start;   
                        cout<<"Total so far: "<<granSum<<endl;
                    }
                    cout<<"The total value of all numbers is: "<<granSum<<endl;
                }
                cout<<endl;
                //exit switch back to menu
                break;
            }
            case '3':{
// File:   main.cpp
// Author: Scott Parker
// Created on January 19, 2017, 4:30 PM
// Purpose: Gaddis, 8th Ed, Chapter 5, Prob 22, Draw a Square
// Draw a square with user provided info for the side.
// !!Modified program to draw a rectangle with user provided height
// and width. 
                //Declare Variables
                short height=0, width=0;
                //Input Values
                cout<<"This program will draw a rectangle on the screen with X characters"<<endl;
                cout<<"of a height and width entered by the user."<<endl;
                while (height < 1 || height > 15 || width < 1 || width > 15) {
                    cout<<"Please enter the height between 1 and 15: "<<endl;
                    cin>>height;
                    cout<<"Please enter the width between 1 and 15: "<<endl;
                    cin>>width;
                    if (height < 1 || height > 15){
                        cout<<"Invalid Height!"<<endl;
                    }
                    if (width < 1 || width > 15){
                        cout<<"Invalid Width!"<<endl;
                    }
                } 
                cout<<endl;
                //Process by mapping inputs to outputs
                //Output values
                for (int rows = 1; rows <= height; rows++) {
                    for (int cols = 1; cols <= width; cols++) {
                        cout<<" X ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                //exit switch back to menu
                break;
            }
            case '4':{
// File:   main.cpp
// Author: Scott Parker
// Created on January 18, 2017, 1:19 PM
// Purpose: Gaddis, 8th Edition, Chapter 5, Problem 2, ASCII Codes
// Write a program that uses a loop to display the characters for the  
// ASCII codes 0 through 127. Display 16 characters on each line.
                
                for (int counter = 0; counter <= 127; counter++) {
                    cout<<static_cast<char>(counter);
                    if ((counter%16)==0)cout<<endl;
                }
                //Exit back to menu
                cout<<endl;
                break;
            }
            case '5':{
// File:   main.cpp
// Author: Scott Parker
// Created on January 18, 2017, 1:19 PM
// Purpose: Gaddis, 8th Edition, Chapter 5, Problem 3, Ocean Levels
// Assuming the ocean's level is currently rising at about 1.5 millimeters
// per year, write a program that displays a table showing the number of 
// millimeters that the ocean will have risen each year for the next 25
// years.
                
                //Declare Variables
                float oLevel = 0; //initializing ocean level at 0mm
                //Input Values
                cout<<"This program will output the ocean level based on 25 years of"<<endl;
                cout<<"oceans rising at 1.5 millimeters per year."<<endl;
                for (int year = 1; year <= 25; year++) {
                    oLevel += 1.5;
                    cout<<"The ocean level after "<<year<<" years will increase by "<<oLevel
                        <<" millimeters"<<endl;
                }
                cout<<endl;
                //Exit back to menu
                break;
            }
            case '6':{
// File:   main.cpp
// Author: Scott Parker
// Created on January 18, 2017, 10:20 PM
// Purpose: Gaddis, 8th Edition, Chapter 5, Problem 4, Calories Burned
// Running on a particular treadmill you burn 3.6 calories per minute. Write
// a program that uses a loop to display the number of calories burned after 
// 5, 10, 15, 20, 25, and 30 minutes.
                //Declare Variables
                float calBurn = 0; //initializing ocean level at 0mm
                
                cout<<"This program will show how many calories are burned at 5 minute"<<endl;
                cout<<"increments for a period of 30 minutes."<<endl;
                for (int minutes = 0; minutes <= 30; minutes++) {
                    calBurn = minutes * 3.6;
                    if ((minutes % 5)==0) cout<<"You have burned "<<calBurn<<" calories "
                        "after running for "<<minutes<<" minutes."<<endl;
                }
                cout<<endl;
                //Exit back to menu
                break;
            }
            case '7':{
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 10:28 PM
 * Purpose: Gaddis, 8th Edition, Chapter 5, Problem 6, Distance Traveled
 * The distance a vehicle travels can be calculated as follows: 
 * distance = speed * time
 * For example, if a train travels 40 miles per hour for 3 hours, the distance 
 * traveled is 120 miles. Write a program that asks the user for the speed of 
 * a vehicle (in miles per hour) and how many hours it has traveled. The 
 * program should then use a loop to display the distance the vehicle has 
 * traveled for each hour of that time period. Here is an example of the 
 * output:

 * What is the speed of the vehicle in mph? 40 
 * How many hours has it traveled? 3
 * Hour Distance Traveled 
 * --------------------------------
 *   1          40 
 *   2          80 
 *   3         120
 * 
 * Input Validation: Do not accept a negative number for speed and do not 
 * accept any value less than 1 for time traveled.
 */
                //Declare Variables
                int hours = 0, speed = -1, dstnce = 0; 
                
                cout<<"This program will display the distance traveled for user"<<endl;
                cout<<"input time and speed."<<endl;
                //Input Values and check for validations
                do {
                    cout<<"What is the speed of the vehicle in MPH? ";
                    cin>>speed;
                    cout<<"How many hours did the vehicle travel? ";
                    cin>>hours;
                    cout<<endl;
                    if (hours < 1) cout<<"Travel time must be 1 or more hours!"<<endl;
                    if (speed < 0) cout<<"Speed may not be negative!"<<endl;
                } while (hours < 1 || speed < 0);
            //Loop to calculate and display distance
            cout<<"Hour          Distance Traveled"<<endl;
            cout<<"-------------------------------"<<endl;
            for (int time = 1; time <= hours; time++) {
                dstnce = dstnce + speed;
                cout<<" "<<time<<"                  "<<setw(4)<<right<<dstnce<<endl;
                }
                cout<<endl;
                //exit back to menu
                break;
            }
            case '8':{
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 11:08 PM
 * Purpose: Gaddis, 8th Edition, Chapter 5, Problem 7, Pennies for Pay
 * Write a program that calculates how much a person would earn over a 
 * period of time if his or her salary is one penny the first day and 
 * two pennies the second day, and con- tinues to double each day. The 
 * program should ask the user for the number of days. Display a table 
 * showing how much the salary was for each day, and then show the total 
 * pay at the end of the period. The output should be displayed in a dollar 
 * amount, not the number of pennies.
 * 
 * Input Validation: Do not accept a number less than 1 for the number of days 
 * worked.
 */
                //Declare Variables
                short days = 0;
                unsigned long int pennies = 1;
                double salary = 0; //Need double for more than 7 precision digits
                
                //Input Values and check for validations
                do {
                    cout<<"How many days did you work (up to 53)? "<<endl;
                    cin>>days;
                    if (days < 1) cout<<"You must work at least 1 day!"<<endl;
                    if (days > 53) cout<<"Maximum of 53 days!"<<endl;
                } while (days < 1 || days > 53); //Need to many precision digits above 55
                
                //Loop to show salary in dollars on a daily basis
                cout<<"Day Worked                    Salary Paid"<<endl;
                cout<<"-----------------------------------------"<<endl;
                for (int time = 1; time <= days; time++) {
                    pennies = pow(2, (time-1));
                    cout<<" "<<setw(4)<<time<<"             $ "<<setw(21)<<right
                       <<setprecision(2)<<fixed<<static_cast<double>(pennies)*(1e-2)
                        <<endl; //Double because of necessary digits
                    salary += pennies;
                }
                cout<<"\nYour total pay for working "<<days<<" days is $ "<<setprecision(2)
                    <<fixed<<salary*1e-2;
                cout<<endl;
                //Exit back to menu
                break;
            }
            case '9':{
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 18, 2017, 12:12 PM
 * Purpose: Savitch, 8th Ed, Chapter 3, Problem 12
 * Calculate PI using the following formula:
 *    pi = 4 [ 1 - 1/3 + 1/5 - 1/7 + 1/9 ... + ((-1)^n/2n+1) ] 
 * for a value of 100000000 iterations.
 */
                const unsigned int NUM_TERMS = 100000000;
                float pi = 0.0;
                
                //Input Values
                //Process by mapping inputs to outputs
                for (int n=0; n < NUM_TERMS; ++n ) {
                    pi += 4 * pow(-1,n) / (2*n +1); 
                }
                
                //Output values
                cout<<"PI = "<<setprecision(7)<<pi<<endl;
                cout<<"PI = "<<setprecision(12)<<pi<<endl;
                cout<<endl;
                //exit back to menu
                break;
            }
            default:
               cout<<"You are exiting the program"<<endl;
        }
            
    
    }while(choice>='1' && choice <= '9');
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

