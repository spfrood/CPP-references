/* 
  File:   main.cpp
  Author: Dr. Scott Parker
  Created on February 5, 2017, 12:28 PM
  Purpose:  Assignment 5 Homework Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <iomanip>  //Format Library
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const int COLDAY=5;
const int COLS19=5;
const int ROWS19=5;

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();

void display (int [],int,int);
int getTotal(int[][COLS19]);
float getAverage(int[][COLS19]);
int getRowTotal(int[][COLS19],int); 
int getColumnTotal(int[][COLS19],int); 
int getHighestInRow(int[][COLS19],int); 
int getLowestInRow(int[][COLS19],int); 

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Problem 1: Largest and Smallest "<<endl;
        cout<<"Type 2 for Problem 2: Rainfall Stats "<<endl;
        cout<<"Type 3 for Problem 3: Salsa Sales "<<endl;
        cout<<"Type 4 for Problem 4: Greater than N "<<endl;
        cout<<"Type 5 for Problem 5: Monkey Food "<<endl;
        cout<<"Type 6 for Problem 10: Drivers License "<<endl;
        cout<<"Type 7 for Problem 12: Grade Book "<<endl;
        cout<<"Type 8 for Problem 13: Grade Book Plus "<<endl;
        cout<<"Type 9 for Problem 19: 2D Array Ops "<<endl;
        cout<<"Enter a number not listed to exit."<<endl;
        cin>>choice;

        //Switch to determine the Problem
        switch(choice){
            case 9:{prob9();break;}
            case 8:{prob8();break;}
            case 7:{prob7();break;}
            case 6:{prob6();break;}
            case 5:{prob5();break;}
            case 4:{prob4();break;}
            case 3:{prob3();break;}
            case 2:{prob2();break;}
            case 1:{prob1();break;}
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>=1&&choice<=9);
    
    //Exit stage right!
    return 0;
}

void prob9(){
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 5, 2017, 12:09 AM
 * Purpose: 19. 2D Array Operations
Write a program that creates a two-dimensional array initialized with test 
data. Use any data type you wish. The program should have the following 
functions:
• getTotal. This function should accept a two-dimensional array as its argument
  and return the total of all the values in the array.
• getAverage. This function should accept a two-dimensional array as its 
  argument and return the average of all the values in the array.
• getRowTotal. This function should accept a two-dimensional array as its first
  argument and an integer as its second argument. The second argument should be
  the subscript of a row in the array. The function should return the total of 
  the values in the specified row.
• getColumnTotal. This function should accept a two-dimensional array as its 
  first argument and an integer as its second argument. The second argument 
  should be the subscript of a column in the array. The function should return 
  the total of the values in the specified column.
• getHighestInRow. This function should accept a two-dimensional array as its 
  first argument and an integer as its second argument. The second argument 
  should be the subscript of a row in the array. The function should return 
  the highest value in the specified row of the array.
• getLowestInRow. This function should accept a two-dimensional array as its 
  first argument and an integer as its second argument. The second argument 
  should be the subscript of a row in the array. The function should return 
  the lowest value in the specified row of the array.
Demonstrate each of the functions in this program. 
 */
    //initialize random number seed
    srand(static_cast<int>(time(0)));
    
    //Declare Variables
    
    int tstAray[ROWS19][COLS19]={};
    int subRow=0, subCol=0;
    
    //Input Values
    for (int i=0;i<ROWS19;i++){ //cycling through rows
        for (int j=0;j<COLS19;j++){ //cycling through columns
            tstAray[i][j]=rand()%100+1; //fill array value with random number between 1 and 100
            cout<<setw(6)<<tstAray[i][j];
        }
        cout<<endl;
    }
    do{ //inputting row value to pass to functions later
        cout<<"Please input the row number that will be passed to the functions."<<endl;
        cout<<"Must be less than the total number of rows (1 to "<<ROWS19<<")."<<endl;
        cin>>subRow;
        if ((subRow<1)^(subRow>ROWS19)) cout<<"Not a valid value!"<<endl;
    } while ((subRow<1)^(subRow>ROWS19));
    subRow-=1;
    do{ //inputting column value to pass to functions later
        cout<<"Please input the column number that will be passed tot he functions."<<endl;
        cout<<"Must be less than the total number of columns (0 to "<<COLS19<<")."<<endl;
        cin>>subCol;
        if ((subCol<0)^(subCol>4)) cout<<"Not a valid value!"<<endl;
    } while ((subCol<0)^(subCol>4));
    subCol-=1;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"The total of all values in this array is: "<<getTotal(tstAray)<<endl;
    cout<<"The average value of this array is: "<<getAverage(tstAray)<<endl;
    cout<<"The total of row "<<subRow+1<<" is: "<<getRowTotal(tstAray,subRow)<<endl; 
    cout<<"The total of column "<<subCol+1<<" is: "<<getColumnTotal(tstAray,subCol)<<endl; 
    cout<<"The highest value in row "<<subRow+1<<" is: "<<getHighestInRow(tstAray,subRow)<<endl; 
    cout<<"The lowest value in row "<<subRow+1<<" is: "<<getLowestInRow(tstAray,subRow)<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob8(){
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 11:46 PM
 * Purpose: 13. Grade Book Modification
Modify the grade book application in Programming Challenge 13 so it drops each
student’s lowest score when determining the test score averages and letter 
grades.
 */
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
    cin.ignore();
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
    
}

void prob7(){ 
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 10:25 PM
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
    //Declare Variables
    const int SIZE=5;
    const int COLS=4;
    string names[SIZE]={};
    char lGrade [SIZE]={};
    float scores [SIZE][COLS]={};
    float avScore [SIZE]={};
    float avgScor=0.00, totScor=0.00;
    
    //Input Values
    cout<<"Please input the student's names."<<endl;
    cin.ignore();
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
        for (int j=0;j<COLS;j++){
            totScor+=scores[i][j];
        }
        avgScor=totScor/4.0f;
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
    
}

void prob6(){
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
    
}

void prob5(){
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 8:16 PM
 * Purpose: 5. Monkey Business
A local zoo wants to keep track of how many pounds of food each of its three 
monkeys eats each day during a typical week. Write a program that stores this 
information in a two-dimensional 3 × 5 array, where each row represents a 
different monkey and each column represents a different day of the week. The 
program should first have the user input the data for each monkey. Then it 
should create a report that includes the following information:
• Average amount of food eaten per day by the whole family of monkeys.
• The least amount of food eaten during the week by any one monkey.
• The greatest amount of food eaten during the week by any one monkey.
Input Validation: Do not accept negative numbers for pounds of food eaten.
 */
    //Declare Variables
    const int MKYROW=3;
    int foodAte[MKYROW][COLDAY]={};
    float avgFood=0.0;
    int totEat=0, mostAte=0, mstEatR=0, mstEatC=0,lestAte=0, lstEatR=0, lstEatC=0;
    //Input Values
    cout<<"Please enter the amount eaten each day by each monkey (pounds):"<<endl;
    for (int i=0;i<MKYROW;i++){
        for (int j=0;j<COLDAY;j++){
            do { 
                cout<<"Please input the food eaten by Monkey "<<(i+1)<<" on day "<<(j+1)<<": ";
                cin>>foodAte[i][j];
                if (foodAte[i][j]<0)cout<<"Must be zero or more pounds!"<<endl;
            } while (foodAte[i][j]<0);
        }
    }
    mostAte=foodAte[0][0];
    mstEatR=1;
    mstEatC=1;
    lestAte=foodAte[0][0];
    lstEatR=1;
    lstEatC=1;
    
    //Process by mapping inputs to outputs
    cout<<"The average food eaten per day per monkey s:"<<endl;
    for (int i=0;i<COLDAY;i++){
        totEat=0;
        for (int j=0;j<MKYROW;j++){
            totEat+=foodAte[j][i];
        }
        avgFood=totEat/3.00f;
        cout<<setprecision(2)<<fixed<<showpoint;
        cout<<"The average food eaten on day "<<(i+1)<<" per monkey was "
            <<avgFood<<" pounds."<<endl;
        cout<<setprecision(0)<<fixed;
    }
    
    for (int i=0;i<MKYROW;i++){
        for (int j=0;j<COLDAY;j++){
            if (mostAte<foodAte[i][j]){
                mostAte=foodAte[i][j];
                mstEatR=i+1;
                mstEatC=j+1;
            }
        }
    }
    cout<<"The most eaten was by monkey "<<mstEatR<<", who ate "<<mostAte<<
            " pounds on day "<<mstEatC<<"."<<endl;
    
    for (int i=0;i<MKYROW;i++){
        for (int j=0;j<COLDAY;j++){
            if (lestAte>foodAte[i][j]){
                lestAte=foodAte[i][j];
                lstEatR=i+1;
                lstEatC=j+1;
            }
        }
    }
    cout<<"The least eaten was by monkey "<<lstEatR<<", who ate "<<lestAte<<
            " pounds on day "<<lstEatC<<"."<<endl;
    
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
}

void prob4(){
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: 4. Larger Than n
In a program, write a function that accepts three arguments: an array, the 
size of the array, and a number n. Assume that the array contains integers. 
The function should display all of the numbers in the array that are greater 
than the number n.
 */
    
    //Randomize random number seed
    srand(static_cast<int>(time(0)));
    
    //Declare Variables
    const int SIZE=1000;
    int arayNum [SIZE]={};
    int testNum=0;
    
    //Input Values   
    cout<<"Filling array with random numbers 0-99"<<endl;
    for (int i=1;i<SIZE;i++) {
        arayNum[i]=(rand()%SIZE); //Fill array with random numbers up to size of array
        cout<<".";
        if ((i%70)==0)cout<<endl;
    }
    cout<<endl;
    
    testNum=rand()%SIZE; //Random number for the test value number
    cout<<"Random number for testing... "<<testNum<<endl;
    
    //Process by mapping inputs to outputs
    
    //Output values
    display (arayNum, SIZE, testNum);
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob3(){
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 3:15 PM
 * Purpose: 3. Chips and Salsa
Write a program that lets a maker of chips and salsa keep track of sales for 
five different types of salsa: mild, medium, sweet, hot, and zesty. The 
program should use two parallel 5-element arrays: an array of strings that 
holds the five salsa names and an array of integers that holds the number of 
jars sold during the past month for each salsa type. The salsa names should 
be stored using an initialization list at the time the name array is created. 
The program should prompt the user to enter the number of jars sold for each 
type. Once this sales data has been entered, the program should produce a 
report that displays sales for each salsa type, total sales, and the names of 
the highest selling and lowest selling products.
Input Validation: Do not accept negative values for number of jars sold.
 */
    //Declare Variables
    int const SIZE=5;
    string typeAry [SIZE]={"Mild", "Medium", "Sweet", "Hot", "Zesty"};
    int saleAry [SIZE]={};
    string lowTyp;
    string highTyp;
    int totSale=0, lowest=0, highest=0;
    int lowTie=1;
    int highTie=1;
    
    //Input Values
    cout<<"Input the sales for each type of salsa... "<<endl;
    for (int i=0;i<SIZE;i++){
        do{
        cout<<typeAry[i]<<" sales was: ";
        cin>>saleAry[i];
        if (saleAry[i]<0) cout<<"Negative sales value not accepted!"<<endl;
        } while (saleAry[i]<0);
    }
    
    //Process by mapping inputs to output
    lowest=saleAry[0];
    highest=saleAry[0];
    lowTyp=typeAry[0];
    highTyp=typeAry[0];
    for (int i=1;i<SIZE;i++){
        if (saleAry[i]<lowest){
            lowest=saleAry[i];
            lowTyp=typeAry[i];
            lowTie=1;
        } 
        else if (saleAry[i]==lowest) {
            lowTie++;
        }
        if (saleAry[i]>highest){
            highest=saleAry[i];
            highTyp=typeAry[i];
            highTie=1;
        } else if (saleAry[i]==highest){
            highTie++;
        }
    }
    for (int i=0;i<SIZE;i++){
        totSale+=saleAry[i];
    }
    
    //Output values
    cout<<setprecision(2)<<fixed;
    cout<<"The lowest sales number was "<<lowest<<" jars for "<<lowTyp<<"."<<endl;
    if (lowTie>1)
        cout<<"     There were "<<lowTie<<" types total with these sales."<<endl;
    cout<<"The highest sales number was "<<highest<<" jars for "<<highTyp<<"."<<endl;
    if (highTie>1)
        cout<<"     There were "<<highTie<<" types total with these sales."<<endl;
    cout<<"The total number of jars sold was "<<totSale<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob2(){
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 2:06 PM
 * Purpose: 2. Rainfall Statistics
Write a program that lets the user enter the total rainfall for each of 12 
months into an array of doubles. The program should calculate and display the 
total rainfall for the year, the average monthly rainfall, and the months 
with the highest and lowest amounts.
Input Validation: Do not accept negative numbers for monthly rainfall figures.
 */
    //Declare Variables
    int const SIZE=12;
    string mnthAry [SIZE]={"January", "February", "March", "April", "May", 
        "June", "July", "August", "September", "October", "November", "December"};
    float rainAry [SIZE]={};
    float lowest=0.000f, highest=0.000f, avgRain=0.0000f, totRain=0.0000f;
    string lowMon;
    string highMon;
    int lowTie=1;
    int highTie=1;
    
    //Input Values
    cout<<"Input the monthly rainfall amounts in inches... "<<endl;
    for (int i=0;i<12;i++){
        do{
        cout<<mnthAry[i]<<" rainfall was: ";
        cin>>rainAry[i];
        if (rainAry[i]<0) cout<<"Negative rainfall not possible! Re-enter month!"<<endl;
        } while (rainAry[i]<0);
    }
    
    //Process by mapping inputs to output
    lowest=rainAry[0];
    highest=rainAry[0];
    lowMon=mnthAry[0];
    highMon=mnthAry[0];
    for (int i=1;i<12;i++){
        if (rainAry[i]<lowest){
            lowest=rainAry[i];
            lowMon=mnthAry[i];
            lowTie=1;
        } 
        else if (rainAry[i]==lowest) {
            lowTie++;
        }
        if (rainAry[i]>highest){
            highest=rainAry[i];
            highMon=mnthAry[i];
            highTie=1;
        } else if (rainAry[i]==highest){
            highTie++;
        }
    }
    for (int i=0;i<12;i++){
        totRain+=rainAry[i];
    }
    avgRain=totRain/12;
    
    //Output values
    cout<<setprecision(2)<<fixed;
    cout<<"The lowest amount of rainfall was "<<lowest<<" inches in "<<lowMon<<"."<<endl;
    if (lowTie>1)
        cout<<"     There were "<<lowTie<<" months with this value."<<endl;
    cout<<"The highest amount of rainfall was "<<highest<<" inches in "<<highMon<<"."<<endl;
    if (highTie>1)
        cout<<"     There were "<<highTie<<" months with this value."<<endl;
    cout<<"The average rainfall for the year was "<<avgRain<<endl;
    cout<<"The total rainfall for the year was "<<totRain<<endl;
    
    //Exit stage right! - This is the 'return 0' call
}

void prob1(){
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 4, 2017, 1:00 PM
 * Purpose: 1. Largest/Smallest Array Values
 * Write a program that lets the user enter 10 values into an array. The 
 * program should then display the largest and smallest values stored in 
 * the array.
 */
    
    //Declare Variables
    int const SIZE=20;
    int cntAray [20]={};
    int lowest;
    int highest;
    int lowTie=1;
    int highTie=1;
    
    //Input Values
    cout<<"Input 20 values... "<<endl;
    for (int i=0;i<20;i++){
        cin>>cntAray[i];
    }
    
    //Process by mapping inputs to output
    lowest=cntAray[0];
    highest=cntAray[0];
    for (int i=1;i<20;i++){
        if (cntAray[i]<lowest){
            lowest=cntAray[i];
            lowTie=1;
        } else if (cntAray[i]==lowest){
            lowTie++;
        }
        if (cntAray[i]>highest){
            highest=cntAray[i];
            highTie=1;
        } else if (cntAray[i]==highest){
            highTie++;
        }
    }
    
    //Output values
    cout<<"The lowest value entered was "<<lowest<<endl;
    if (lowTie>1)
        cout<<"     There were "<<lowTie<<" numbers with this value."<<endl;
    cout<<"The highest value entered was "<<highest<<endl;
    if (highTie>1)
        cout<<"     There were "<<highTie<<" numbers with this value."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
}

//Function to display values of array that are greater than N
void display (int array[],int SIZE,int nVal){
    int sameAs=0;
    int valCntr=0;
    for (int i=0;i<SIZE;i++){
        if (array[i]>nVal) {
            cout<<"Spot "<<i<<" in array is value "<<array[i]
                <<" and is larger than "<<nVal<<endl;
            valCntr++;
        }
        if (array[i]==nVal) sameAs++;
    }
    cout<<"The array has "<<nVal<<" occur "<<sameAs<<" times."<<endl;
    cout<<"The function output "<<valCntr<<" lines."<<endl;
}

//This function should accept a two-dimensional array as its argument
//  and return the total of all the values in the array.
int getTotal(int array[][COLS19]){
    int sumAll=0;
    for (int i=0;i<ROWS19;i++){
        for (int j=0;j<COLS19;j++){
            sumAll+=array[i][j];
        }
    }
    return sumAll;
}

//This function should accept a two-dimensional array as its 
//  argument and return the average of all the values in the array.
float getAverage(int array[][COLS19]){
    float avgAll=0;
    int sumAll=0;
    for (int i=0;i<ROWS19;i++){
        for (int j=0;j<COLS19;j++){
            sumAll+=array[i][j];
        }
    }
    avgAll=(sumAll/(static_cast<float>(ROWS19)*COLS19));
    return avgAll;
} 

//This function should accept a two-dimensional array as its first
//  argument and an integer as its second argument. The second argument should be
//  the subscript of a row in the array. The function should return the total of 
//  the values in the specified row.
int getRowTotal(int array[][COLS19],int rowVal){
    int sumRow=0;
    for (int i=0;i<COLS19;i++){
        sumRow+=array[rowVal][i];
    }
    return sumRow;
} 

//This function should accept a two-dimensional array as its 
//  first argument and an integer as its second argument. The second argument 
//  should be the subscript of a column in the array. The function should return 
//  the total of the values in the specified column.
int getColumnTotal(int array[][COLS19],int colVal){
    int sumCol=0;
    for (int i=0;i<ROWS19;i++){
        sumCol+=array[i][colVal];
    }
    return sumCol;
} 

//This function should accept a two-dimensional array as its 
//  first argument and an integer as its second argument. The second argument 
//  should be the subscript of a row in the array. The function should return 
//  the highest value in the specified row of the array.
int getHighestInRow(int array[][COLS19],int rowVal){
    int rowHigh=array[rowVal][0];
    for (int i=0;i<COLS19;i++){
        if (rowHigh<array[rowVal][i])rowHigh=array[rowVal][i];
    }
    return rowHigh;
}

//This function should accept a two-dimensional array as its 
//  first argument and an integer as its second argument. The second argument 
//  should be the subscript of a row in the array. The function should return 
//  the lowest value in the specified row of the array.
int getLowestInRow(int array[][COLS19],int rowVal){
    int rowLow=array[rowVal][0];
    for (int i=0;i<COLS19;i++){
        if (rowLow>array[rowVal][i])rowLow=array[rowVal][i];
    }
    return rowLow;
} 