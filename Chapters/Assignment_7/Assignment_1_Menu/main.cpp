/* 
  File:   main.cpp
  Author: Dr. Scott Parker
  Created on March 1, 2017, 10:17 AM
  Purpose:  17SPR CSC-17A-42636 Assignment 1 Homework Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <iomanip> //To format output
#include <cstdlib>  //For random
#include <ctime> //for random seed
#include <string> //for working with string variables
#include <fstream> //For using files
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another and for
//2d array columns
const int COLS=30; //Number of columns in a 2d array

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
void prob10();

void inWait(); //Call this to pause until enter key is pressed
float celsius(float); //Convert Fahrenheit temp to Celsius
void fillAry(char [][COLS], int);  //Fill array with random data
void prntAry(char [][COLS], int);  //Print the contents of array to screen
void compAry(char [][COLS], int);  //Compare array data
void prnSAry(string [], int);  //Print the array
void sorSAry (string [], int); //Sort the array by least to most (alpha order)
void swaSRow (string [], int); //Swap items in the array 

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list <invalid data will be ignored>"<<endl;
        cout<<"Type 1 for Problem 1: Celsius to Fahrenheit Conversion "<<endl;
        cout<<"Type 2 for Problem 2: Currency Exchange "<<endl;
        cout<<"Type 3 for Problem 3: Math Tutor "<<endl;
        cout<<"Type 4 for Problem 4: Days in Month "<<endl;
        cout<<"Type 5 for Problem 5: Color Mixers "<<endl;
        cout<<"Type 6 for Problem 6 Organism Population "<<endl;
        cout<<"Type 7 for Problem 7: Celsius Temperature Table "<<endl;
        cout<<"Type 8 for Problem 8: Grade Book "<<endl;
        cout<<"Type 9 for Problem 9: Rain or Shine "<<endl;
        cout<<"Type 10 for problem 10: Binary String Search "<<endl;
        cout<<"Enter 0 (zero) or a number not listed to exit."<<endl;
        cin>>choice;
        while (cin.fail()) //Loop to validate input
            {
            cout<<"INPUT INVALID! "<<endl;
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter a valid choice!:"<<endl;
            cin>>choice;
            }

        //Switch to determine the Problem
        switch(choice){
            case 10:{prob10();break;}
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
    }while(choice>=1&&choice<=10);
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Function for Problem 10 ****************************
//Description: Gaddis_8thEd_Chap8_Prob7_BinStringSearch
//  
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void prob10(){
    //Declare Variables
    const int NUMNAM = 20; //Size of the array
    string names[NUMNAM] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri", 
                               "Taylor, Terri", "Johnson, Jill","Allison, Jeff", 
                               "Looney, Joe", "Wolfe, Bill", "James, Jean", 
                               "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", 
                               "Javens, Renee", "Harrison, Rose", 
                               "Setzer, Cathy", "Pike, Gordon", "Holland, Beth" };
    
    //Input Values
    
    //Process by mapping inputs to outputs
    prnSAry(names, NUMNAM);
    sorSAry(names, NUMNAM);
    prnSAry(names, NUMNAM);
    cout<<endl;
    //Output Values
    //Exit stage right! - This is the 'return 0' call
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Function for Problem 9 ****************************
//Description: Gaddis_8thEd_Chap7_Prob6_RainOrShine
//  
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void prob9(){
    //Instantiate and Open files
    ifstream in;  //assigns file input operator
    ofstream out; //assigns file output operator

    //Declare Variables
    const int ROWS=3;  //Number of rows for array
    char monData [ROWS][COLS]={'\n'};  //3x30 character array
    char yesNo='N';
    
    //Input Values
    in.open("RainOrShine.txt"); //opening data file
    for (int i=0;i<ROWS;i++){  //inputting data from file
        for (int j=0;j<COLS;j++){
            in>>monData[i][j];
        }
    }
    in.close();  //closing file
    
    //Input Values
    cout<<"Would you like to generate random data before proceeding?"<<endl;
    cin>>yesNo; //Fill array with random data?
    if (yesNo=='y'||yesNo=='Y'){
        fillAry(monData, ROWS);
    } else cout<<"Not generating random data."<<endl;
    cin.ignore(256, '\n'); //ignore contents of buffer in case more than one char entered
    cout<<"Printing array contents: "<<endl;
    prntAry(monData, ROWS);
    
    //Process by mapping inputs to outputs
    compAry(monData, ROWS);
    
    //Output values
    out.open("RainOrShine.txt"); //Save most recently used data to file
    for (int i=0;i<ROWS;i++){  //to output data to file
        for (int j=0;j<COLS;j++){
            out<<monData[i][j]<<" ";
        }
    }
    out.close();  //closing file
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
    
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Function for Problem 8 ****************************
//Description: Gaddis_8thEd_Chap7_Prob12_GradeBook
//  
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void prob8(){
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
    cin.clear();  //Resetting flags               
    cin.ignore(256, '\n'); //ignore contents of buffer
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
        if (avgScor>=90) lGrade[i]='A'; //assigning letter grade to average with switch
        else if (avgScor>=80) lGrade[i]='B';
        else if (avgScor>=70) lGrade[i]='C';
        else if (avgScor>=60) lGrade[i]='D';
        else lGrade[i]='F';
    }
    
    //Output values
    cout<<setw(25)<<"NAME"<<setw(15)<<"AVERAGE"<<setw(10)<<"GRADE"<<endl;
    cout<<setprecision(2)<<fixed;
    for (int i=0;i<SIZE;i++){ //outputting data in set format
        cout<<setw(25)<<names[i]<<setw(15)<<avScore[i]<<setw(10)<<lGrade[i]<<endl;
    }
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
    
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Function for Problem 7 ****************************
//Description: Gaddis, 8thEd, Chapter 6, Problem 7, Celsius Temp Table
//  
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void prob7(){ 
#define C_RED     "\x1b[31m"  //For red text
#define C_GREEN   "\x1b[32m"  //for green text
#define C_CYAN    "\x1b[36m"  //for cyan text
#define C_RESET   "\x1b[0m"   //rest color to black

    //Declare Variables
    float fahTemp=0.0f;
    //Input Values
    cout<<"This program accepts a Fahrenheit temperature as input and will"<<endl;
    cout<<"Convert it to Celsius. It will also give the conversions of the"<<endl;
    cout<<"temperatures 10 degrees Fahrenheit below the provided temperature"<<endl;
    cout<<"and conversions for temperatures 10 degrees above the provided"<<endl;
    cout<<"temperature. What temperature would you like to convert to Celsius?"<<endl;
    cin>>fahTemp;
    
    //Process by mapping inputs to outputs
    
    //Output values
    for (int i=(fahTemp-10);i<=(fahTemp+10);i++){
        if (i<fahTemp){
            cout<<C_CYAN<<setprecision(2)<<fixed<<showpoint<<i
                    <<" F  =  "<<celsius(i)<<" C"<<C_RESET<<endl;
        }
        else if (i==fahTemp){
            cout<<C_GREEN<<setprecision(2)<<fixed<<showpoint<<i
                    <<" F  =  "<<celsius(i)<<" C"<<C_RESET<<endl;
        }
        else {
            cout<<C_RED<<setprecision(2)<<fixed<<showpoint<<i
                    <<" F  =  "<<celsius(i)<<" C"<<C_RESET<<endl;
        }
    }
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
    
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Function for Problem 6 ****************************
//Description: Gaddis_8thEd_Chap5_Prob11_OrganismPopulation
//  
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void prob6(){
    //Declare Variables
    unsigned short dayMult=0; //How many days will the population grow
    float popSize=0.0f;  //Initial population size
    float incrPer=0.0f;  //percentage of daily population growth
    
    //Input Values
    cout<<"This program will output the daily population growth of a group of"<<endl;
    cout<<"organisms. Please provide the following relevant details: "<<endl;
    cout<<"What is the starting population size? (minimum of 2)"<<endl;
    cin>>popSize; //get initial population from user
    while (cin.fail()||popSize<2) //validate input type and range
        {
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter a number! (minimum of 2)"<<endl;
            cin>>popSize;
        }
    cout<<"What is the daily population increase? (1% minimum)"<<endl;
    cin>>incrPer; //input percentage of growth
    while (cin.fail()||incrPer<1) //validate input type and range
        {
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter the percentage! (minimum of 1)"<<endl;
            cin>>incrPer;
        }
    cout<<"How many days will the population breed? (whole number 1 or larger)"<<endl;
    cin>>dayMult; //input days of growth
    while (cin.fail()||dayMult<1) //validate input type and range
        {
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter the days! (whole number 1 or larger)"<<endl;
            cin>>dayMult;
        }
    
    //Process by mapping inputs to outputs
    incrPer=incrPer*1.0e-2f; //convert input percentage to decimal
    for (int i=1;i<=dayMult;i++){
        popSize=(popSize+popSize*incrPer); //calculate new daily population
        cout<<setprecision(1)<<fixed; //format output
        cout<<"After "<<i<<" days the new population is: "<<popSize<<endl;
    }
    cout<<endl;
    //Output values
    
    //Exit stage right! - This is the 'return 0' call
    
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Function for Problem 5 ****************************
//Description: Gaddis_8thEd_Chap4_Prob8_ColorMixer
//  
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void prob5(){
    //Declare Variables
    const string red="red";  //primary color
    const string blue="blue";  //primary color
    const string yellow="yellow";  //primary color
    string color1="";  //user base color
    string color2="";  //user additive color
    
    //Input Values
    cin.clear();  //Resetting flags               
    cin.ignore(256, '\n'); //ignore contents of buffer
    cout<<"What is your base primary color?"<<endl;
    getline(cin, color1); //user enter baser primary color
    while (color1!=red&&color1!=blue&&color1!=yellow){  //input validation for base color
        cout<<"You need to enter red, blue, or yellow!"<<endl;
        cout<<"Please enter your base primary color:"<<endl;
        getline(cin, color1);
    }
    cout<<"What primary color do you wish to mix with your base color?"<<endl;
    getline(cin, color2);  //user input for color to add to base
    while (color2!=red&&color2!=blue&&color2!=yellow){  //input validation for additive color
        cout<<"You need to enter red, blue, or yellow!"<<endl;
        cout<<"Please enter your the primary color to add:"<<endl;
        getline(cin, color2);
    }
    
    
    //Process by mapping inputs to outputs
    
    //Output values
    //if colors are the same no change
    if (color2==color1) cout<<"It's kind of weird to do that but your color is still "<<color2<<"."<<endl;
    else if (color1==red){ //red base
        if (color2==blue){  //red and blue = purple
            cout<<"Your new color is purple."<<endl;
        }
        else if (color2==yellow){ //red and yellow = orange
            cout<<"Your new color is orange."<<endl;
        }
        else cout<<"ERROR! Something broke here! Base Red"<<endl; //Something didn't work
    }
    else if (color1==blue){ //blue base
        if (color2==red){  //blue and red = purple
            cout<<"Your new color is purple."<<endl;
        }
        else if (color2==yellow){ //blue and yellow = green
            cout<<"Your new color is green."<<endl;
        }
        else cout<<"ERROR! Something broke here! Base Blue"<<endl; //Something didn't work
    }
    else if (color1==yellow){ //yellow base
        if (color2==red){ //yellow and red = orange
            cout<<"Your new color is orange."<<endl;
        }
        else if (color2==blue){ //yellow and blue = green
            cout<<"Your new color is green."<<endl;
        }
        else cout<<"ERROR! Something broke here! Base Yellow"<<endl; //something didn't work
    }
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Function for Problem 4 ****************************
//Description: Gaddis_8thEd_Chap4_Prob10_DaysInMonth
//      Also accounts for leap-years
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void prob4(){
    //Declare Variables
    int month, year, days;
    
    //Input Values
    cout<<"Enter a month as a number from 1-12: ";
    cin>>month;
    cout<<"Enter a year: ";
    cin>>year;
    
    //Process by mapping inputs to outputs
    days =  (month == 1)?31:
            (month == 3)?31:
            (month == 5)?31:
            (month == 7)?31:
            (month == 8)?31:
            (month == 10)?31:
            (month == 12)?31:
            (month == 4)?30:
            (month == 6)?30:
            (month == 9)?30:
            (month == 11)?30:
            (!(year % 100)&&!(year % 400))?29: //Check for leap year
            (!(year % 100)&&!(year % 400))&&(!(year % 4))?29:28; //Check for leap year
    
    
    //Output values
    cout<<"That month had "<<days<<" days"<<endl;
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
    
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Function for Problem 3 ****************************
//Description: Gaddis_8thEd_Chap3_Prob17_MathTutor
//
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void prob3(){
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned short numOne=0, numTwo=0, sumNum=0; //Two numbers to be added, sum 
    unsigned short userNum=0; //Chance for user to enter a number
    
    //Input Values
    
    //Process by mapping inputs to outputs
    numOne=rand()%899+100; //assign 3 digit number to numOne
    numTwo=rand()%899+100; //assign 3 digit number to numTwo
    sumNum=numOne+numTwo;  //Sum of numOne and numTwo  
    
    //Output values
    //Display the numbers to be added
    cout<<"Find the sum of the following numbers: "<<endl;
    cout<<"   "<<numOne<<endl; //number one
    cout<<"  +"<<numTwo<<endl; //Number two
    cout<<"  ----"<<endl;
    cin.clear();  //Resetting flags               
    cin.ignore(256, '\n'); //ignore contents of buffer 
    inWait(); //Pause while user calculates problem
    cout<<"Enter your solution: "<<endl;
    cin>>userNum; //Get user's number 
    while (cin.fail()) //Loop to validate input type
        {
            cin.clear();  //Resetting flags               
            cin.ignore(256, '\n'); //ignore contents of buffer
            cout<<"Please enter your solution as a number!"<<endl;
            cin>>userNum;
        }
    if (userNum==sumNum) cout<<"Your answer is correct!"<<endl; //If user is correct
    else cout<<"Incorrect! The correct answer is: "<<sumNum<<endl; //User entered wrong answer
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
    
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Function for Problem 2 ****************************
//Description: Gaddis_8thEd_Chap3_Prob13_CurrencyExchange
//
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void prob2(){
    //Declare Variables
    const float EURRATE=0.95f; //Exchange rate 1 dollar for Euro 2/21/2017
    const float YENRATE=113.55f; //Exchange rate 1 dollar to Jpy Yen 2/21/2017
    float usValY=0.0f;
    float usValE=0.0f;
    float eurVal=0.0f;
    float yenVal=0.0f;
    
    //Input Values
    cout<<"How much US currency would you like to convert to Japanese Yen? "<<endl;
    cin>>usValY;  //Get amount of US currency to convert to Yen
    cout<<"How much US currency would you like to convert to Euro currency? "<<endl;
    cin>>usValE; //Get amount of US currency to converto to Euro
    
    //Process by mapping inputs to outputs
    yenVal=usValY*YENRATE; //Amount of Yen for the US amount
    eurVal=usValE*EURRATE; //Amount of Euro for US amount
    
    //Output values
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"$"<<usValY<<" is worth ¥"<<yenVal<<endl; //output the US->YEN conversion
    cout<<"$"<<usValE<<" is worth €"<<eurVal<<endl; //output the US->EURO conversion
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Function for Problem 1 ****************************
//Description: Gaddis, 8thEd, Chapter 3, Problem 12, Celsius to Fahrenheit
//
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void prob1(){
    //Declare Variables
    float fahTemp, celTemp; //Fahrenheit temperature, Celsius temperature
    
    //Input Values
    cout<<"This program will convert Celsius to Fahrenheit."<<endl;
    cout<<"What is the temperature in Celsius?"<<endl;
    cin>>celTemp; //input the temp in Celsius
    
    //Process by mapping inputs to outputs
    fahTemp = celTemp * 9 / 5 + 32; //convert Celsius to Fahrenheit
    
    //Output values
    cout<<setprecision(2)<<fixed;
    cout<<celTemp<<" degrees Celsius is the same as"<<endl;
    cout<<fahTemp<<" degrees in Fahrenheit."<<endl<<endl;
    cout<<endl;
    //Exit stage right! - This is the 'return 0' call
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*********************** Pause until Enter pressed ****************************
//Description: Pause function to halt output until user presses ENTER key
//
//Inputs: none
//     
//Outputs: none
//
//******************************************************************************
void inWait(){
    char pauser=0;
    cout<<"Press <ENTER> to continue"<<endl;
    //cin.get(pauser); //inputting character or something to pause
    cin.ignore(256, '\n');  //ignore entire buffer in case multiple keys pressed
    cin.clear();  //resetting flags for cin to avoid conflict with future input
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*********************   Convert Fahrenheit to Celsius ************************
//Description: Convert temperature from Fahrenheit to Celsius
//  
//Inputs: Fahrenheit temperature
//     
//Outputs: Celsius temperature
//
//******************************************************************************
float celsius(float fahTemp){
    float celTemp;
    celTemp = ((fahTemp-32)*5)/9;
    return celTemp;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Compare Array Rows ****************************
//Description: Compare the rows in an array checking data
//  
//Inputs: 2d character array of months, number of rows in array
//     
//Outputs: none
//
//******************************************************************************
void compAry(char months[][COLS], int rows){
    int junS=0, julS=0, augS=0; //Sunny day info
    int junC=0, julC=0, augC=0; //Cloudy day info
    int junR=0, julR=0, augR=0; //Rainy day info
    
    for (int i=0;i<rows;i++){  //to output data to file
        for (int j=0;j<COLS;j++){
            if (i==0){ //Get statistical info for June
                if (months[i][j]=='C'){
                    junC++;
                }
                else if(months[i][j]=='R'){
                    junR++;
                }
                else junS++;
            }else if (i==1){ //Get statistical info for July
                if (months[i][j]=='C'){
                    julC++;
                }
                else if(months[i][j]=='R'){
                    julR++;
                }
                else julS++;
            }else { //Get statistical info for August
                if (months[i][j]=='C'){
                    augC++;
                }
                else if(months[i][j]=='R'){
                    augR++;
                }
                else augS++;
            }
        }
    }
    cout<<"                June    July    August  "<<endl;
    cout<<setw(16)<<left<<"Rainy Days"<<setw(8)<<left<<junR<<setw(8)<<left<<julR<<setw(8)<<left<<augR<<endl; //Total rainy days for each month
    cout<<setw(16)<<left<<"Cloudy Days"<<setw(8)<<left<<junC<<setw(8)<<left<<julC<<setw(8)<<left<<augC<<endl; //Total cloudy days for each month
    cout<<setw(16)<<left<<"Sunny Days"<<setw(8)<<left<<junS<<setw(8)<<left<<julS<<setw(8)<<left<<augS<<endl;  //Total sunny days for each month
    cout<<"Total Rainy Days:  "<<junR+julR+augR<<endl; //Overall rainy days
    cout<<"Total Cloudy Days: "<<junC+julC+augC<<endl; //overall cloudy days
    cout<<"Total Sunny Days:  "<<junS+julS+augS<<endl; //overall sunny days
    
    if (junR>=julR&&junR>=augR){ 
        cout<<"June "; //output June if most rainy days in June
    } else if (julR>=junR&&julR>=augR){
        cout<<"July "; //output July if most rainy days in July
    } else cout<<"August ";  //else most rainy days in August
    cout<<"had the most rainy days, not considering ties."<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Print Array Rows ****************************
//Description: Print the data in a 2d array 
//  
//Inputs: 2d character array of months, number of rows in array
//     
//Outputs: none
//
//******************************************************************************
void prntAry(char months[][COLS], int rows){
    cout<<"Day    ";  
    for (int i=0;i<COLS;i++){  //Output the day of the month
        cout<<setw(3)<<left<<i+1;
    }
    cout<<endl;
    for (int i=0;i<rows;i++){  //output the data for that day
        i==0?cout<<"June  ":i==1?cout<<"July  ":cout<<"August";
        for (int j=0;j<COLS;j++){
            cout<<setw(2)<<right<<months[i][j]<<" ";
        }
        cout<<endl;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Fill Array  ****************************
//Description: Fill 2D array with random character data of C, R, or S values
//  
//Inputs: 2d character array of months, number of rows in array
//     
//Outputs: none
//
//******************************************************************************
void fillAry(char months[][COLS], int rows){
    srand(static_cast<unsigned int>(time(0)));
    int temp=0;
    char rcs='\n';
    for (int i=0;i<rows;i++){  //Run once for each month
        for (int j=0;j<COLS;j++){ //fill data for each day
            temp = rand()%3;
            if (temp==0){
                rcs='R';
            } else if (temp==1){
                rcs='C';
            } else rcs='S';
            months[i][j]=rcs;
        }
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Sort String Array****************************
//Description: Sort data in an array of strings
//  
//Inputs: string array, number of rows
//     
//Outputs: none
//
//******************************************************************************
void sorSAry (string nam[], int size){
    bool swap;
    do{
        swap=false; //will remain false if nothing swapped in for loop
        for(int i=0;i<size-1;i++){
            if(nam[i]>nam[i+1]){ //compare element and swap if true
                swaSRow(nam,i); //Swap the current element with next element
                swap=true; //set bool to true to initiate another run-through
            }
        }
    }while(swap); 
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Swap Array Row ****************************
//Description: Swap row with one row down in array 
//  
//Inputs: string array, number of rows
//     
//Outputs: none
//
//******************************************************************************
void swaSRow (string nam[], int now){
    string temp="";  //temp string used in swapping
    temp=nam[now];  //temp = current item
    nam[now]=nam[now+1];  //current item = next item
    nam[now+1]=temp;  //next item = temp
} 

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************   Print Array of Strings ****************************
//Description: Print data in an array of strings
//  
//Inputs: string array, number of rows
//     
//Outputs: none
//
//******************************************************************************
void prnSAry (string nam[], int size){
    cout<<"Num    Name"<<endl;
    for (int i=0;i<size;i++){
        cout<<setw(3)<<i+1<<"    "<<nam[i]<<endl;  //Output the element number and array value
    }
    cout<<endl;;
}