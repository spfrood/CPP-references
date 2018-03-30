
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 1, 2017, 9:41 AM
 * Purpose: 12. Grade Book
A teacher has five students who have taken four tests. The teacher uses the 
following grading scale to assign a letter grade to a student, based on the 
average of his or her four test scores.
 Test Score     Letter Grade
   90–100           A
   80–89            B
   70–79            C
   60–69            D
    0–59            F

Write a program that uses an array of string objects to hold the five student 
names, an array of five characters to hold the five students’ letter grades, 
and five arrays of four doubles to hold each student’s set of test scores.
The program should allow the user to enter each student’s name and his or her 
four test scores. It should then calculate and display each student’s average 
test score and a letter grade based on the average.
Input Validation: Do not accept test scores less than 0 or greater than 100.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    // **** Note that ALL ARRAYS ARE PARALLEL ARRAYS
    const int SIZE=5; //Rows in the array
    const int COLS=4; //columns in the array
    string names[SIZE]={}; //array of strings for student names
    char lGrade [SIZE]={};  //Array of chars for letter grades
    float scores [SIZE][COLS]={}; //2d array for all scores for each student
    float avScore [SIZE]={}; //array to store the average score of each student
    float avgScor=0.00, totScor=0.00; //temp variables used in calculations
    
    //Input Values
    cout<<"Please input the student's names."<<endl;
    for (int i=0;i<SIZE;i++){ //Input names of the students 
        cout<<"Please enter the name of Student "<<(i+1)<<": ";
        getline(cin, names[i]);
    }
    cout<<"Please input the student's grades."<<endl;
    for (int i=0;i<SIZE;i++){ //input the grades of the students
        for (int j=0;j<COLS;j++){
            do {
                cout<<"Please enter test score "<<(j+1)<<" for student "<<(i+1)
                    <<" as a score from 0 to 100."<<endl;
                cin>>scores[i][j];
                if ((scores[i][j]<0)^(scores[i][j]>100)) cout<<"Score must be between 0 and 100!"<<endl;
            } while ((scores[i][j]<0)^(scores[i][j]>100)); //validate data range
        }
    }
    
    //Process by mapping inputs to outputs
    for (int i=0;i<SIZE;i++){
        avgScor=0.00;
        totScor=0.00;
        for (int j=0;j<COLS;j++){
            totScor+=scores[i][j]; //Getting the total of the scores
        }
        avgScor=totScor/4.0f; //calculating the average
        avScore[i]=avgScor; //assigning average score to the array element
        if (avgScor>90) lGrade[i]='A'; //assigning letter grade to average with switch
        else if (avgScor>80) lGrade[i]='B';
        else if (avgScor>70) lGrade[i]='C';
        else if (avgScor>60) lGrade[i]='D';
        else lGrade[i]='F';
    }
    
    //Output values
    cout<<setw(25)<<"NAME"<<setw(15)<<"AVERAGE"<<setw(10)<<"GRADE"<<endl;
    cout<<setprecision(2)<<fixed;
    for (int i=0;i<SIZE;i++){ //outputting data in set format
        cout<<setw(25)<<names[i]<<setw(15)<<avScore[i]<<setw(10)<<lGrade[i]<<endl;
    }
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

