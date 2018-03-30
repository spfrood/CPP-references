
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 11:46 PM
 * Purpose: 13. Grade Book Modification
Modify the grade book application in Programming Challenge 13 so it drops each
student’s lowest score when determining the test score averages and letter 
grades.
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
    const int SIZE=5;
    const int COLS=4;
    string names[SIZE]={};
    char lGrade [SIZE]={};
    float scores [SIZE][COLS]={};
    float avScore [SIZE]={};
    float avgScor=0.00, totScor=0.00, lowScor=0.00; 
    
    //Input Values
    cout<<"Please input the student's names."<<endl;
    for (int i=0;i<SIZE;i++){
        cout<<"Please enter the name of Student "<<(i+1)<<": ";
        getline(cin, names[i]);
    }
    cout<<"Please input the student's grades."<<endl;
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<COLS;j++){
            do {
                cout<<"Please enter test score "<<(j+1)<<" for student "<<(i+1)
                    <<" as a score from 0 to 100."<<endl;
                cin>>scores[i][j];
                if ((scores[i][j]<0)^(scores[i][j]>100)) cout<<"Score must be between 0 and 100!"<<endl;
            } while ((scores[i][j]<0)^(scores[i][j]>100));
        }
    }
    
    //Process by mapping inputs to outputs
    for (int i=0;i<SIZE;i++){
        avgScor=0.00;
        totScor=0.00;
        lowScor=scores[i][0];
        for (int j=0;j<COLS;j++){
            totScor+=scores[i][j];
            if (lowScor>scores[i][j]){
                lowScor=scores[i][j];
            }
        }
        cout<<"Dropping lowest score of "<<lowScor<<endl;
        totScor-=lowScor;
        avgScor=totScor/3.0f;
        avScore[i]=avgScor;
        if (avgScor>90) lGrade[i]='A';
        else if (avgScor>80) lGrade[i]='B';
        else if (avgScor>70) lGrade[i]='C';
        else if (avgScor>60) lGrade[i]='D';
        else lGrade[i]='F';
    }
    
    //Output values
    cout<<setw(25)<<"NAME"<<setw(15)<<"AVERAGE"<<setw(10)<<"GRADE"<<endl;
    cout<<setprecision(2)<<fixed;
    for (int i=0;i<SIZE;i++){
        cout<<setw(25)<<names[i]<<setw(15)<<avScore[i]<<setw(10)<<lGrade[i]<<endl;
    }
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

