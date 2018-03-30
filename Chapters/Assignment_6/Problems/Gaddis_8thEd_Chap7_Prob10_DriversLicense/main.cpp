
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 5, 2017, 2:22 PM
 * Purpose: 10. Driver’s License Exam
The local Driver’s License Office has asked you to write a program that grades 
the writ- ten portion of the driver’s license exam. The exam has 20 multiple 
choice questions. Here are the correct answers:
     1. A    6. B   11. A   16. C
     2. D    7. A   12. C   17. C
     3. B    8. B   13. D   18. A
     4. B    9. C   14. B   19. D
     5. C   10. D   15. D   20. B
Your program should store the correct answers shown above in an array. It 
should ask the user to enter the student’s answers for each of the 20 
questions, and the answers should be stored in another array. After the 
student’s answers have been entered, the program should display a message 
indicating whether the student passed or failed the exam. (A student must 
correctly answer 15 of the 20 questions to pass the exam.) It should then 
display the total number of correctly answered questions, the total number of 
incorrectly answered questions, and a list showing the question numbers of the
incorrectly answered questions.
Input Validation: Only accept the letters A, B, C, or D as answers.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
//Also use for multi-dimensional array column sizes

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=20;
    char corAnsw [SIZE]={'A','D','B','B','C',
                         'B','A','B','C','D',
                         'A','C','D','B','D',
                         'C','C','A','D','B'};
    char answTst [SIZE]={};
    int corrAns=0;
    
    //Input Values
    cout<<"Please input your answer for the questions. Only A, B, C, D are "<<endl;
    cout<<"valid answers."<<endl;
    for (int i=0;i<SIZE;i++){
        do{
            cout<<"Question "<<i+1<<": ";
            cin>>answTst[i];
            if (!((answTst[i]=='A')||(answTst[i]=='B')||(answTst[i]=='C')||(answTst[i]=='D'))){
                cout<<"Invalid answer. A, B, C, or D only!"<<endl;
            }
        } while (!((answTst[i]=='A')||(answTst[i]=='B')||(answTst[i]=='C')||(answTst[i]=='D')));
    }
    
    //Process by mapping inputs to outputs
    for (int i=0;i<SIZE;i++){
        if (corAnsw[i]==answTst[i]) corrAns++;
    }
    
    //Output values
    if (corrAns>=15)cout<<"You passed the test! You answered "<<corrAns<<" questions right!"<<endl;
    else cout<<"Looks like you failed to pass the test! You only answered "<<corrAns<<" questions right!"<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

