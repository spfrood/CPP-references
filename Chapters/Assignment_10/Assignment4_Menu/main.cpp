/* 
  File:   main.cpp
  Author: Dr. Scott Parker
  Created on April 5, 2017, 5:35 PM
  Purpose:  Assignment 4 Homework Menu
 */

//System Libraries
#include <iostream>
#include <cctype> //for character library functions
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another and for
//2d array columns

//Function Prototypes 
//Delete void functions or add them as needed based on homework problems
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

int cntSt01(char [], int); //function to count the length of a c-string
void revSt02(char *, int); //function to output the reverse of a string
int cntWd03(char *, int); //function to count the words in a string
int cntWd04(char *, int); //function to count the words in a string
float avgLt05(char *, int); //function to return the avg number of letters per word in a string
void capWd06(char [], int); //function to convert first word of sentence to upper case
void pJoke07(fstream &); //Function to output contents of ASCII file to screen
void pPnch08(fstream &); //Function to output the last line of a file to screen
void timer (int); //function to create a timer
void pTail09(fstream &, string); //Function to display file tail



//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list <non-numeric data will be ignored>"<<endl;
        cout<<"Type 1 for Chap. 10 Prob 1: StringLength "<<endl;
        cout<<"Type 2 for Chap. 10 Prob 2: ReverseString"<<endl;
        cout<<"Type 3 for Chap. 10 Prob 3: WordCounter "<<endl;
        cout<<"Type 4 for Chap. 10 Prob 4: AvgLetters "<<endl;
        cout<<"Type 5 for Chap. 10 Prob 5: SentenceCapitalizer "<<endl;
        cout<<"Type 6 for Chap. 12 Prob 1: FileHeadProgram "<<endl;
        cout<<"Type 7 for Chap. 12 Prob 2: FileDisplayProgram "<<endl;
        cout<<"Type 8 for Chap. 12 Prob 3: Punchline "<<endl;
        cout<<"Type 9 for Chap. 12 Prob 4: TailProgram "<<endl;
        cout<<"Type 10 for Chap. 12 Prob 5: LineNumbers "<<endl;
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
//************************ Function for Problem 10  ****************************
//Description: Program for Book, Edition, Chapter, Question, Short Description
//
//Inputs: (what inputs passed to function)
//     
//Outputs:  (what is the output of this function)
//
//******************************************************************************
void prob10(){
    //Declare Variables
    int count=0;
    char pauser='\0'; //Character to pause screen output
    string fName=""; //string to hold file name
    string fData=""; //string to hold data from the file
    fstream fil; //Create filestream object 
    
    //Input Values
    cout<<"Enter the name of the file: (dataA.txt, dataB.txt, dataC.txt,"<<endl;
    cout<<"                     dataD.txt, and dataE.txt were used in testing)"<<endl;
    cin>>fName;
    fil.open(fName, ios::in); //Open file for input
    
    //Process by mapping inputs to outputs
    
    //Output values
    if (!fil.fail()) { //if can not open file then break program
        while (!fil.eof()) { //loop first 10 lines and not fil.eof
            getline(fil, fData); //Get line i of the file
            cout<<count+1<<":"<<fData<<endl; //output file line with line number and a: at the beginning
            count++; //increment count until next line
            if (count%24==0){ //Pause after 24 lines of text output
                cout<<"<Press enter to continue>"<<endl; //notify of pause
                cin.ignore(256, '\n');
                cin.get(pauser);
            }
        }
        fil.close(); //close file
    }
    else cout << "ERROR: Cannot open the file."<<endl; //Else output if unable to open file
    
    //Clean up and close files
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob9(){
    //Declare Variables
    fstream filJ; //fstream to hold text file
    string fName=""; //to hold the name of the file to open
    
    //Input Values
    cout<<"Input the file name: "<<endl; //ask user for the file name
    cin>>fName; //Input the name of the file to open
    
    //process data
    
    //Output Data
    pTail09(filJ, fName); //Output file tail
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob8(){
    //Declare Variables
    fstream filJ; //fstream to hold joke text file
    fstream filP; //fstream to hold punchline text file
    string pauser=""; //it's all in the timing
    
    //Input Values
    filJ.open("joke.txt", ios::in); //open file with the joke
    filP.open("punchline.txt", ios::in); //open file that has the punchline
    
    //Process by mapping inputs to outputs
    
    //Output values
    pJoke07(filJ); //tell the joke
    cout<<"..."<<endl;
    int beg=time(0);
    int end=time(0);
    timer(3);
    pPnch08(filP); //output the punchline
    
    //cleanup
    filJ.close(); //close file
    filP.close(); //close file
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob7(){ 
    //Declare Variables
    int count=0;
    string pauser=""; //Character to pause screen output
    string fName=""; //string to hold file name
    string fData=""; //string to hold data from the file
    fstream fil; //Create filestream object 
    
    //Input Values
    cout<<"Enter the name of the file: (dataA.txt, dataB.txt, dataC.txt,"<<endl;
    cout<<"                     dataD.txt, and dataE.txt were used in testing)"<<endl;
    cin>>fName;
    fil.open(fName, ios::in); //Open file for input
    
    //Process by mapping inputs to outputs
    
    //Output values
    if (!fil.fail()) { //if can not open file then break program
        while (!fil.eof()) { //loop first 10 lines and not fil.eof
            getline(fil, fData); //Get line i of the file
            cout<<fData<<endl; //output file line
            count++; //increment count until next line
            if (count%24==0){ //Pause after 24 lines of text output
                cout<<"<Press enter to continue>"<<endl; //notify of pause
                cin.ignore(256, '\n');
                getline (cin, pauser);
            }
        }
        fil.close(); //close file
    }
    else cout << "ERROR: Cannot open the file."<<endl; //Else output if unable to open file
    
    //Clean up and close files
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob6(){
    //Declare Variables
    int count=0;
    string temp=""; //string to hold file data
    fstream fil; //Create filestream object 
    fil.open("dataC.txt", ios::in); //Open file for input
    if (fil.fail()) { //if can not open file then break program
        cout << "ERROR: Cannot open the file.\n";
        return;
    }
    
    //Input Values
    
    cout<<"<BEGIN FILEHEAD>"<<endl; //Output beginning of filehead
    while (!fil.eof() && count<10) { //loop first 10 lines and not fil.eof
        getline(fil, temp); //Get line i of the file
        cout<<temp<<endl; //output file line
        count++; //increment count until next line
    }
    if (fil.eof()) cout<<"<EOF> END OF FILE"<<endl; //if end of file hit then notify EOF
    else cout<<"<END FILEHEAD>"<<endl; //Else output end of filehead
    
    //Process by mapping inputs to outputs
    
    //Output values
    
    //Clean up and close files
    
    fil.close(); //close file
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob5(){
    //Declare Variables
    const int SIZE=255; //size is enough to Enter up to a line of characters
    char strng[SIZE]; //array of characters (c-string)
    
    //Input Values
    cout<<"Enter some words, up to "<<SIZE-1<<" total characters (excess will be ignored): "<<endl; //input characters (reserve last one for null)
    cin.clear();
    cin.ignore(256, '\n');
    cin.getline(strng, SIZE); //get the input of the characters
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"Here is the string with first word of a sentence capitalized: "<<endl;
    capWd06(strng, SIZE); //call function to capitalize the first words of sentence
    cout<<strng<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob4(){
    //Declare Variables
    const int SIZE=255; //size is enough to Enter up to a line of characters
    char strng[SIZE]; //array of characters (c-string)
    
    //Input Values
    cout<<"Enter some words, up to "<<SIZE-1<<" total characters (excess will be ignored): "<<endl; //input characters (reserve last one for null)
    cin.clear();
    cin.ignore(256, '\n');
    cin.getline(strng, SIZE); //get the input of the characters
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"You entered "<<cntWd04(strng, SIZE)<<" words. "<<endl; //count the words 
    cout<<setprecision(2)<<fixed; //format output 2 decimal points fixed
    cout<<"They contained "<<avgLt05(strng, SIZE)<<" letters each on average."<<endl; //output avg letters per word
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob3(){
    //Declare Variables
    const int SIZE=255; //size is enough to Enter up to a line of characters
    char strng[SIZE]; //array of characters (c-string)
    
    //Input Values
    cout<<"Enter some words, up to "<<SIZE-1<<" total characters (excess will be ignored): "<<endl; //input characters (reserve last one for null)
    cin.clear();
    cin.ignore(256, '\n');
    cin.getline(strng, SIZE); //get the input of the characters
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"You entered "<<cntWd03(strng, SIZE)<<" words. "<<endl; //count the words 
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
    
}

void prob2(){
    //Declare Variables
    const int SIZE=75; //size is enough to Enter up to a line of characters
    char strng[SIZE]; //array of characters (c-string)
    
    //Input Values
    cout<<"Input up to "<<SIZE-1<<" characters (excess will be ignored): "<<endl; //input characters (reserve last one for null)
    cin.clear();
    cin.ignore(256, '\n');
    cin.getline(strng, SIZE); //get the input of the characters
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"You entered: "<<strng<<endl; //SHow what the user entered
    cout<<"Reversed is "; 
    revSt02(strng, SIZE); //output the reversed string
    cout<<endl; 
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}

void prob1(){
    //Declare Variables
    const int SIZE=75; //size is enough to Enter up to a line of characters
    char strng[SIZE]; //array of characters (c-string)
    
    //Input Values
    cout<<"Input up to "<<SIZE-1<<" characters (excess will be ignored): "<<endl; //input characters (reserve last one for null)
    cin.clear();
    cin.ignore(256, '\n');
    cin.getline(strng, SIZE); //get the input of the characters
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"You entered: "<<strng<<endl;
    cout<<"The string is " <<cntSt01(strng, SIZE)<<" characters long (not including '\\0')."<<endl; //output the number of characters in the string
    
    //Exit stage right! - This is the 'return 0' call
    //Exit stage right! - This is the 'return 0' call
}




void pTail09(fstream &fil, string name) {
    fil.open(name, ios::in); //Open the file
    if (!fil.fail()){ //check to see if the file opened correctly 
        string line="";  //string to hold data from each line of file
        int cnt=0; //counter to count the lines in the file
        while (fil){ //find the number of lines in the file
            getline(fil, line); //get file line, increment to next line
            cnt++; //increment counter of the number of lines
        }
        cnt-=1; //get rid of "EOF" line
        fil.close(); //closing file to reset input position
        fil.open(name, ios::in); //opening file to output tail
        if (cnt<10){ //if the file is less than 10 lines
            cout<<"<File less than 10 lines. Showing whole file>"<<endl;
            while (!fil.eof()) { //repeat to end of file
                getline(fil, line); //Get line of the file
                cout<<line<<endl; //output file line
            }
        fil.close(); //close file
        } else {
            int i=0; //counter to not print output until end of file
            while (!fil.eof()){ //repeat until end of file
                if (i<(cnt-10)){ //if counter is not within the last 10 lines 
                getline(fil, line); //advance to next line but don't print output
                } else {
                    getline(fil, line); //get data from file and advance to next line
                    cout<<line<<endl; //print the file line
                }
                i++; //increment the counter 
            }
        }
        fil.close(); //close the file
    } else {
        cout<<"ERROR OPENING FILE!"<<endl; //output error message if file did not open correctly
    }
}

//function to create a brief timer
void timer(int delay){
    int beg=time(0);
    int end=time(0);
    do {
        end=time(0);
    } while (end-beg<delay);
}

//Function to output contents of ASCII file to screen
void pJoke07(fstream &fil) {
    string line=""; //string to hold the data from the file
    while (!fil.eof()){
        getline(fil, line); //Send line of file data to string
        cout<<line<<endl; //output the string
    }
}

//Function to output the last line of a file to screen
void pPnch08(fstream &fil) {
    string line="";
    char ch='\0';
    int n=1;
    
    while (ch!='\n'){ //find the last line by scanning for newline feeds
        fil.seekg(-n, ios::end); //move cursor to end of file
        fil.get(ch); //read character from file
        n++; //move back another character 
    }

    getline(fil, line); //get the last line and put into a string
    cout<<line<<endl; //output the last line of the file
}

//function to output a reversed string
void capWd06(char str[], int size){
    int c=0;
    while (!isalnum(str[c])){ //find first character of string 
        c++;
    }
    if (islower(str[c])){ //capitalize first character if it's a lower case letter
        str[c]-=32;
    } //capitalize first letter of string if not already
    
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        if (str[i]=='.'||str[i]=='!'||str[i]==':'||str[i]=='?'||str[i]==';') { //find punctuation that requires capitalization
            int j=i;
            do {
                j++;
            } while (!isalpha(str[j])); //find the next character after punctuation mark
            if (islower(str[j])){ //capitalize it if it's a lower case letter
                str[j]-=32;
            }
            i=j; //pick up in loop from here
        }
    }
}

//function to return the avg number of letters per word in a string
float avgLt05(char *str, int size){
    int temp=1; //temp since i is local in the for loop
    int totChar=0;
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        if (str[i]==' '&&str[i+1]!=' ') temp++; //count whitespace after each word but not multiples
        if (str[i]!=' ') totChar++; //add to character count if not a whitespace
    } 
    return (static_cast<float>(totChar)/static_cast<float>(temp));
} 

//function to output a reversed string
int cntWd04(char *str, int size){
    int temp=1; //temp since i is local in the for loop
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        if (str[i]==' '&&str[i+1]!=' ') temp++; //whitespace after each word
    }
    return temp;
}

//function to output a reversed string
int cntWd03(char *str, int size){
    int temp=1; //temp since i is local in the for loop
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        if (str[i]==' '&&str[i+1]!=' ') temp++; //sequential whitespaces not counted as more words
    }
    return temp;
}

//function to output a reversed string
void revSt02(char *str, int size){
    int temp=0; //temp since i is local in the for loop
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        temp=i; //counter set to i 
    }
    for (int i=temp;i>=0;i--){
        cout<<str[i];
    }
    cout<<endl;
}

//function to count the length of a c-string
int cntSt01(char str[], int size){
    int temp=0; //temp since i is local in the for loop
    for (int i=0; str[i]!='\0'&&i<size;i++){ //go through loop until either max array size or hit null char
        temp=i+1; //counter set to i 
    }
    if (str[0]=='\0') temp=0;
    return temp; //return the value of the for loop
}