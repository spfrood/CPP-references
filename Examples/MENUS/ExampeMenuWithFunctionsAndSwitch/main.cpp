
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <iostream>
#include <cstdlib> //Random number generator seed
#include <ctime>   //Time Library
#include <iomanip> //Format Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void prob1 ();
void prob2 ();
void prob3 ();


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    char choice;
    short menOpt=0;
    
    //Loop on the menu
    
    do {
        
        //Input Values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for problem with Do-While"<<endl;
        cout<<"Type 2 for problem with While"<<endl;
        cout<<"Type 3 for problem with For"<<endl;
        cout<<"Type 4 to exit"<<endl;
        cin>>choice;
        menOpt=choice-48;
        
        //Switch to determine the problem
        switch(menOpt){
            case 3:{prob1();break;}
            
            case 2:{prob2();break;}
            
            case 1:{prob3();break;}
            default:
               cout<<"You are exiting the program"<<endl;
        }
            
    
    }while(choice>='1' && choice <= '3');
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void prob1 () {
    cout<<"We are in Problem 1"<<endl;
                char numStd=20,student=1;
                unsigned short average=0;
    
                //Input values
                cout<<"This program assigns the score and outputs the grade for "
                <<static_cast<int>(numStd)<<" students"<<endl;
    
                //Loop for each student
                do{
                    //Assign a grade and add to the average
                    //score and grade are local to the while loop
                    unsigned short score=rand()%50+50;
                    average+=score;
                    //Process by mapping inputs to outputs
                    char grade= (score>=90)?'A':
                                (score>=80)?'B':
                                (score>=70)?'C':
                                (score>=60)?'D':'F';

                    //Output values
                    cout<<"Student "<<setw(2)<<static_cast<int>(student)
                        <<" has score "<<score<<" = "<<grade<<endl;
                }while(++student<=numStd);
    
                //Calculate and output the average
                average/=numStd;
                cout<<"The average test score = "<<average<<endl;
                
}

void prob2 () {
    cout<<"We are in Problem 2"<<endl;
    //Declare and Initialize local Variables to main
    char numStd=20,student=0;
    unsigned short average=0;
    
    //Input values
    cout<<"This program assigns the score and outputs the grade for "
          <<static_cast<int>(numStd)<<" students"<<endl;
    
    //Loop for each student
    while(++student<=numStd){
        //Assign a grade and add to the average
        //score and grade are local to the while loop
        unsigned short score=rand()%50+50;
        average+=score;
        //Process by mapping inputs to outputs
        char grade=(score>=90)?'A':
                   (score>=80)?'B':
                   (score>=70)?'C':
                   (score>=60)?'D':'F';

        //Output values
        cout<<"Student "<<setw(2)<<static_cast<int>(student)
            <<" has score "<<score<<" = "<<grade<<endl;
    }
    
    //Calculate and output the average
    average/=numStd;
    cout<<"The average test score = "<<average<<endl;
    
}

void prob3 () {
                    cout<<"We are in Problem 3"<<endl;
                //Declare and Initialize local Variables to main
                char numStd=20;
                unsigned short average=0;
    
                //Input values
                cout<<"This program assigns the score and outputs the grade for "
                    <<static_cast<int>(numStd)<<" students"<<endl;
    
                //Loop for each student
                for(char student=1;student<=numStd;student++){
                    //Assign a grade and add to the average
                    //score and grade are local to the while loop
                    unsigned short score=rand()%50+50;//Score from 50 to 99
                    average+=score;
                    //Process by mapping inputs to outputs
                    char grade=(score>=90)?'A':
                              (score>=80)?'B':
                              (score>=70)?'C':
                              (score>=60)?'D':'F';

                    //Output values
                    cout<<"Student "<<setw(2)<<static_cast<int>(student)
                      <<" has score "<<score<<" = "<<grade<<endl;
                }
    
                //Calculate and output the average
                average/=numStd;
                cout<<"The average test score = "<<average<<endl;
                
}