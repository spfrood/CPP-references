
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 3, 2017, 4:39 PM
 * Purpose: Menu with problems for Final Project 
 */

//System Libraries
#include <iostream> //basic functions cout, etc
#include <cstdlib> //to use rand
#include <ctime> //To get time
#include <cmath> //for logs
#include <vector> //for vectors
#include <fstream> //working with files
#include <iomanip> //For formatting output
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const int ARYCOLS=2;  //number of columns in 2D array
const int COLS=15;  //number of columns for array
const int COLSB=7; //number of columns in array with totals

//Function Prototypes
void prob1 ();
void prob2 ();
void prob3 ();
void prob4 ();
void prob5 ();
void prob6 ();
short numRvse(unsigned short); 
void fillVec (vector<int>&, vector<int>&, int);  //fill vectors 
void prntVec (vector<int>, vector<int>, int);   //Print vectors
void fillAry (int [][ARYCOLS], int, vector<int>, vector<int>);  //fill array (with vector data)
void prntAry (int [][ARYCOLS], int); //print array
int retRand(); //Function to return 1 of 5 values
void prChAry(char [][COLS],int); //Function to print 2D array
void compRow(char [][COLS],int); //Function to sort 2D array
void swapRow(char [][COLS],int); //Swap row with one higher up
void prAry(int [][COLSB], int); //Function to print array
void sumAry(int [][COLSB], int); //Function to sum up rows and columns

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
        cout<<endl;
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Midterm Question 1 - Number Reversal"<<endl;
        cout<<"Type 2 for Midterm Question 2 - Number Guess"<<endl;
        cout<<"Type 3 for Midterm Question 3 - Odd Even Vectors"<<endl;
        cout<<"Type 4 for Midterm Question 4 - Random Sequence "<<endl;
        cout<<"Type 5 for Midterm Question 5 - Sorting 2D Char Array"<<endl;
        cout<<"Type 6 for Midterm Question 6 - Spreadsheet Row/Column Sums"<<endl;
        cout<<"Any other character to exit"<<endl;
        cin>>choice;
        menOpt=choice-48; //Changing to integer to use switch
        
        //Switch to determine the problem
        switch(menOpt){
            case 6:{prob6();break;}
            
            case 5:{prob5();break;}
            
            case 4:{prob4();break;}
            
            case 3:{prob3();break;}
            
            case 2:{prob2();break;}
            
            case 1:{prob1();break;}
            
            default:
               cout<<"You are exiting the program"<<endl;
        }
            
    
    }while(choice>='1' && choice <= '6');
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************** Question 1 - Draw an X **********************************
//Description: 1)  Write a function that takes an unsigned
//short integer and returns a signed short
//number in reverse.  For instance 106 
//reversed would be 601.  Another would be 
//30000 gives 3.  Subtract the largest 3
//digit number you can without going negative.  
//Check to make sure the 
//conversion falls within the range for a
//signed short. If it doesn't then output
//no conversion possible else output the result.
//******************************************************************************
void prob1 () {
    //Declare Variables
    int inpuNum=0;  //Number input by user to be processed and converted
    unsigned short num=0;  //to assign user number if within bounds
    short outNum=0;  //Signed short for function to return value 
    
    //Input Values
    do {  //Validating input to make sure it can be an unsigned short
        cout<<"Please input a number from 0 to 65,535"<<endl;
        cin>>inpuNum;
        if (inpuNum<0||inpuNum>65535) {
            cout<<"Not a valid input!"<<endl;
        }
    } while (inpuNum<0||inpuNum>65535);
    num=inpuNum;  //assigning input number to be unsigned short
    
    //Process by mapping inputs to outputs
    
    //Output values
    outNum=numRvse(num); //Running function to reverse input and return unsigned short
    if (outNum==0){ //Conversion was not possible... reversed number out of bounds
        cout<<"Conversion not possible in bounds of question."<<endl;
    }else {  //Outputting reversed number
        cout<<"Reversed number = "<<outNum<<endl;
        if (outNum<100) { //Check to see if possible to subtract 3 digit number
            cout<<"Not possible to subtract a 3 digit number."<<endl;
        } else if (outNum>=999) { //999 is largest poss 3 digit num
            cout<<"Subtracting 999 so new number = "<<(outNum-999)<<endl; 
        }
        else { //Largest possible 3-digit number is the number itself
            cout<<"The largest 3-digit value that can be subtracted is "<<outNum<<endl;
            cout<<"Which puts the result at: "<<(outNum=outNum-outNum)<<endl;
        }
    }
    //Exit stage right! - This is the 'return 0' call
    //But not here because this is a void function
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Question 2 - Character Output ******************************
//Description:  Write a program that plays the game "Guess the
//Number" as follows.  Your program chooses the
//number to be guessed by selecting an unsigned integer
//at random in the range 1 to 10^X.  The program
//inputs X and displays
//******************************************************************************
void prob2 () {
    //Set random number seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned int guessNm=0; //Number to be guessed
    unsigned int maxNum=0; //Upper range of random
    unsigned int plrGues=0; //number entered by player to guess
    short x=0; //input by user to determine number (max value of 9)
    short maxGues=0; //Max number of guesses allowed
    short guesCnt=0; //Guess counter
    bool goGuess = true;
    
    //Input Values
    do {  //Getting the x for 10^x as per assignment instructions
        cout<<"Please input a number from 1 to 9: "<<endl;
        cin>>x;
        if (x<1||x>9) cout<<"Value out of range!"<<endl;
    } while (x<1||x>9);
    
    //Process by mapping inputs to outputs
    maxNum=pow(10,x); //Max number for random function
    guessNm=rand()%maxNum+1; //Number to be guessed
    maxGues=log2(maxNum)+1; //Max number of guesses allowed
    cout<<"I have a number between 1 and "<<maxNum<<endl;
    cout<<"Can you guess my number?  You will be"<<endl;
    cout<<"given a maximum of "<<maxGues<<" guesses."<<endl;
    
    //Output values
    do { //play the game
        goGuess=false;
        cout<<"Please enter guess number "<<++guesCnt<<":"<<endl;  
        if (guesCnt==maxGues){ //Output to warn that this is the last guess
            cout<<"This is your last guess!"<<endl;
        }
        cin>>plrGues;
        if (plrGues==guessNm) {  //Output if guess is correct
            cout<<"You got it! "; 
            goGuess=false;
        } else if (plrGues>guessNm){  //Notify guess too large
            cout<<"Your guess is too large!"<<endl;
            goGuess=true;
        } else if (plrGues<guessNm){  //notify guess too low
            cout<<"Your guess is too low!"<<endl;
           goGuess=true;
        }
        else {
            cout<<"This should not be displayed. Something broke."<<endl;
        }
    } while (goGuess&&(guesCnt<maxGues));
    cout<<"The number was "<<guessNm<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    //But not here because this is a void function.
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Question 3 - Create a function that 
//fills one vector with even
//random 2 digit numbers and another vector with
//odd random numbers.  Prompt the user for the size
//of these vectors.  Both will be the same size.
//Output the results in 2 column format.
//******************************************************************************
void prob3 () {
    //Set random seed
    srand (static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=0; //will be set to size of vectors
    const int arows=250000;  //setting max size of array rows
    vector <int> vecOne; //initialize vector 1
    vector <int> vecTwo; //initialize vector 2
    int array2D[arows][ARYCOLS]={};
    //Input Values
    cout<<"How large should the vectors be?"<<endl;
    cin>>size; //How many numbers will the vectors hold?

    
    //Process by mapping inputs to outputs
    fillVec (vecOne, vecTwo, size);  //Fill the vectors with even and odd numbers
    prntVec (vecOne, vecTwo, size);  //print the vectors
    
    fillAry (array2D, size, vecOne, vecTwo);  //Fill the array with the data from each vector
    prntAry (array2D, size);  //Print the array
            
    //Output values

    //Exit stage right!
    //But not here because this is a void function
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Question 4 
//Create a function/method/procedure that
//returns a random number from the following set,
//{9,52,78,101,119}.  Loop 10000 times with this 
//procedure and print the frequency of each of 
//the 5 numbers obtained.  Hint: Use an array for 
//the sequence and frequency.  
//******************************************************************************
void prob4 () {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int ntimes=10000, n=5; //How many times to run it, number of options
    int array[ntimes]={}; //Array to hold the values
    int freqAry[n]={}; //Array to hold the number of times for each value
    int rndseq[n]={9,52,78,101,119}; //Array holding the 5 diff values
    
    //Input Values
    for (int i=0;i<ntimes;i++){
        array[i]=retRand(); //Assigning random values to array
        if (array[i]==9){ 
            freqAry[0]++; //increment if element == 9
        }
        if (array[i]==52){
            freqAry[1]++; //increment if element == 52
        }
        if (array[i]==78){
            freqAry[2]++; //increment if element == 78
        }
        if (array[i]==101){
            freqAry[3]++; //increment if element == 101
        }
        if (array[i]==119){
            freqAry[4]++; //increment if element == 119
        }
    }
    
    //Output values
    cout<<"The numbers came up with the following frequencies: "<<endl;
    for (int i=0;i<n;i++){  //Output how many times each value occured
        cout<<rndseq[i]<<" occurred "<<
        freqAry[i]<<" times"<<endl;
    }
    cout<<"Total of all occurances: "<<freqAry[0]+freqAry[1]+freqAry[2]+freqAry[3]+freqAry[4]<<endl;

    //Exit stage right! - This is the 'return 0' call
    //But not here because this is a void function    
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Question 5 Sort a 10x15 array of characters.  
//Largest located
//at index [0][0-14] and smallest at index [9][0-14].  
//Create a procedure that passes the array to a print routine, 
//then a procedure that sorts the array and returns the sorted array 
//to the original procedure, and finish by using the same print routine.  
//Fill the array with
//******************************************************************************
void prob5 () {
    //instantiate and/or open files
    ifstream in;
    ofstream out;

    //Declare Variables
    in.open("input.dat"); //opening data file
    const int ROWS=10;  //Number of rows for array
    char charray [ROWS][COLS]={};  //10x15 character array
    
    //Input Values
    for (int i=0;i<ROWS;i++){  //inputting data from file
        for (int j=0;j<COLS;j++){
            in>>charray[i][j];
        }
    }
    in.close();  //closing data file
    
    //Process by mapping inputs to outputs
    prChAry(charray,ROWS); //Printing current array contents
    compRow(charray,ROWS); //Sorting array descending alpha order
    cout<<endl;
    //Output values
    prChAry(charray,ROWS); //printing sorted array
    
    
    //Exit stage right! - This is the 'return 0' call
    //But not here because this is a void function
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Question 6 -         Create the following input tables. 
//Output
//the sum of the rows, columns and grand total.  You
//will need to create procedures that print the table,
//then sum rows, columns and grand total, then pass
//that information to the same print routine.  Note:
//the 2 procedures printTable,SumTable and finally a
//call to printTable again are all invoked from subroutine 
//main.  I want to see each number formatted to 6 spaces.  
//Print the table out exactly as below.
//******************************************************************************
void prob6 () {
    //instantiate and/or open files
    ifstream in;
    ofstream out;

    //Declare Variables
    const int ROWSB=6;  //Number of rows for array with totals
    int bArray [ROWSB][COLSB]={};  //6x7 integer array all value set to 0
    
    //Input Values
    in.open("table.dat"); //opening data file
    for (int i=0;i<ROWSB-1;i++){  //inputting data without "sum" row
        for (int j=0;j<COLSB-1;j++){  //Inputting without "sum" column
            in>>bArray[i][j];
        }
    }
    in.close();  //closing data file
    
    //Process by mapping inputs to outputs
    cout<<"Your data shows: "<<endl;
    prAry(bArray, ROWSB);
    cout<<endl;
    sumAry(bArray, ROWSB); 
    cout<<"Table with Rows and Columns summed: "<<endl;
    cout<<"Data being written to file 'augtable.dat' "<<endl;
    prAry(bArray, ROWSB);
    //Output values
    
    //Exit stage right! - This is the 'return 0' call
    //But not here because this is a void function
}


//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Sum Array ********************************
//Description: Sum the rows and columns of the array
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void sumAry(int a[][COLSB], int row){
    for (int i=0;i<row;i++){ 
        for (int j=0;j<COLSB-1;j++){ //Sum the columns
                a[i][COLSB-1]+=a[i][j];
            }
    }
    for (int i=0;i<COLSB;i++){ 
        for (int j=0;j<row-1;j++){ //Sum the rows
                a[row-1][i]+=a[j][i];
            }
    }
    
}


//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Print 2D array ********************************
//Description: Prints the array data to screen and to file
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void prAry(int a[][COLSB], int row){
    for (int i=0;i<row;i++){  //Print array info 
        for (int j=0;j<COLSB;j++){ 
            if (a[i][j]!=0){  //print data if value not = zero
                cout<<setw(6)<<a[i][j];
            }
            else if (a[i][j]==0){  //Print whitespace if value is zero
                cout<<setw(6)<<" ";
            }
        }
        cout<<endl;
    }
    
    ofstream out;
    out.open("augtable.dat");
    for (int i=0;i<row;i++){
        for (int j=0;j<COLSB;j++){
            if (a[i][j]!=0){
                out<<setw(6)<<a[i][j];
            }
            else if (a[i][j]==0){
                out<<setw(6)<<" ";
            }
        }
        out<<endl;
    }
    out.close();
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Print 2D array ********************************
//Description: Prints the array data to screen
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void prChAry(char a[][COLS],int row){
    for (int i=0;i<row;i++){  //Row data for array
        for (int j=0;j<COLS;j++){//print each column data 
            cout<<a[i][j];
        }
        cout<<endl; //only output endline at end of row
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Swap Row ********************************
//Description: Swaps row of array with one below it
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void swapRow(char a[][COLS], int now){  //swap row with row below it
    char temp=126;  //set initial temp value to one not used in the alpha array
    for (int j=0;j<COLS;j++){ //exchange elements in rows one at a time
        temp=a[now][j];
        a[now][j]=a[now+1][j];
        a[now+1][j]=temp;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Sort 2D array ********************************
//Description: Bubble sorts the array in descending alphabetical order
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void compRow(char a[][COLS],int row){
    bool swap;
    int h=0;

    do{
        swap=false;
        for(int i=0;i<row-1;i++){
            if(a[i][h]<a[i+1][h]){ //compare 1st element and swap row if true
                swapRow(a,i);
                swap=true; //set bool to true to initiate another run-through
            }
            else if (a[i][h]==a[i+1][h]){ //if first element is same in both rows
                int f=h;
                do{ //increment to next element until elements are not same
                    f++;
                } while (a[i][f]==a[i+1][f]);
                if (a[i][f]<a[i+1][f]){ //if current row less than next swap row
                    swapRow(a,i);
                    swap=true; //set bool to true to initiate another run-through
                }
            }
        }
    }while(swap);      
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Return random ********************************
//Description: returns one of the required elements in a random manner
//
//Inputs: 
//     
//Outputs: none
//******************************************************************************
int retRand(){  //Filling random sequence to fill array with sequence values
    int temp;
    int rndNum=rand()%5;
    if (rndNum==0)temp=9;
    if (rndNum==1)temp=52;
    if (rndNum==2)temp=78;
    if (rndNum==3)temp=101;
    if (rndNum==4)temp=119;
    return temp;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Fill Vectors ********************************
//Description: Fills two vectors, one with even numbers and other with odd
//
//Inputs: Vector one, vector two, size of vectors
//     
//Outputs: none
//******************************************************************************
void fillVec (vector<int>& vOne, vector<int>& vTwo, int size){
    cout<<"Filling the Vectors"<<endl;
    srand (static_cast<unsigned int>(time(0))); //Set random seed
    int even=1,odd=0,temp=0;
    for (int i=0;i<size;i++){ //fill the vector up to the size entered above
        temp=rand()%89+10; //random number from 10-99
        if (temp%2==0) { //if random is even
            even=temp; //set even to temp 
            odd=temp+1; //set odd to temp + 1
        }
        else {
            even=temp-1; //set even to temp - 1
            odd=temp;  //set odd to temp
        }
        vOne.push_back(even);  //set vector One element to even
        vTwo.push_back(odd);  //set vector two element to odd
    }
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Print Vectors ********************************
//Description: Prints the array data to screen and to file
//
//Inputs: Vector one, Vector two, size of vectors
//     
//Outputs: none
//******************************************************************************
void prntVec (vector<int> vOne, vector<int> vTwo, int size){
    cout<<"Printing the Vectors"<<endl;
    cout<<"Even  Odd"<<endl;
    for (int i=0;i<size;i++){  //for loop to print the vectors up to the size entered
        cout<<vOne[i]<<"    "<<vTwo[i]<<endl;
    }
    cout<<"Leaving Vector Print Function"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Fill 2D array ********************************
//Description: Fills 2D array with the values of the vectors
//
//Inputs: array, number of rows, vector one, vector two
//     
//Outputs: none
//******************************************************************************
void fillAry (int a[][ARYCOLS],int rows,vector<int> vOne, vector<int> vTwo){
    cout<<"Filling the 2D Array"<<endl;
    for (int i=0;i<rows;i++) {  //filling the array with the data from the vectors
        for (int j=0;j<ARYCOLS;j++){
            if (j==0)a[i][j]=vOne[i];  //column 1 filled with data from vector One
            if (j==1)a[i][j]=vTwo[i];  //Column 2 filled with data from vector Two
        }
    }
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Print 2D array ********************************
//Description: Prints the array data to screen
//
//Inputs: Array, rows in array
//     
//Outputs: none
//******************************************************************************
void prntAry (int a[][ARYCOLS],int rows){
    cout<<"Printing the 2D Array"<<endl;
    cout<<"Even  Odd"<<endl;
    for (int i=0;i<rows;i++){  //Print the array up to the size entered abobe
        for (int j=0;j<ARYCOLS;j++){
            cout<<a[i][j]<<"    ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Reverse and Convert ********************************
//Description: Reverses an unsigned short number and converts it to a positive
//         signed short
//
//Inputs: Unsigned short number
//     
//Outputs: Positive signed short
//******************************************************************************
short numRvse(unsigned short orig){
    
    const int TENTHOS=10000; //Conversion to 10,000
    const int THOSNDS=1000;  //Conversion to 1,000
    const int HUNDRDS=100;   //Conversion to   100
    const int TENS=10;       //Conversion to    10
    
    int tmpAmnt; //Using int because reverse value may exceed max short value
    short n10000,n1000,n100,n10,n1; //The numbers of powers of 10
    short tenKs, oneKs, hunds, tens, ones;
    
    tmpAmnt=orig; //Setting tmpAmnt working variable to value of amount
    n10000=(tmpAmnt-tmpAmnt%TENTHOS)/TENTHOS;//Determines how many 10000's
    tmpAmnt=(tmpAmnt-n10000*TENTHOS);       //value without 10000's
    n1000=(tmpAmnt-tmpAmnt%THOSNDS)/THOSNDS;//Determines how many 1000's
    tmpAmnt=(tmpAmnt-n1000*THOSNDS);       //Value without 1000's
    n100=(tmpAmnt-tmpAmnt%HUNDRDS)/HUNDRDS;//Determines how many 100's
    tmpAmnt=(tmpAmnt-n100*HUNDRDS);        //Value without 100's
    n10=(tmpAmnt-tmpAmnt%TENS)/TENS;      //Determines how many 10's
    n1=(tmpAmnt-n10*TENS);            //Value without 10's (just ones)
    
    if (n10000>=1){ //assigning value to 10000 if it applies
        tmpAmnt=n1*TENTHOS+n10*THOSNDS+n100*HUNDRDS+n1000*TENS+n10000;
    } else if (n1000>=1){ //assigning value to 1000 if it applies
        tmpAmnt=n1*THOSNDS+n10*HUNDRDS+n100*TENS+n1000;
    } else if (n100>=1){ //assigning value to 100 if it applies
        tmpAmnt=n1*HUNDRDS+n10*TENS+n100;    
    } else if (n10>=1){ //assigning value to 10 if it applies
        tmpAmnt=n1*TENS+n10;  
    } else if(n1>=1){ //assigning value to 1 if it applies
        tmpAmnt=n1;
    }
    if (tmpAmnt>32767) {
        tmpAmnt=0;
    }
    return tmpAmnt; //return the reversed value or 0 if out of bounds
}