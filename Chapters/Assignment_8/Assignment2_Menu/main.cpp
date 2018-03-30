/* 
  File:   main.cpp
  Author: Dr. Scott Parker
  Created on March 14, 2017, 7:51 PM
  Purpose:  Asisgnment 2 03/14/17
 * 8 Problems from Chapter 9, Flowchart 2.
 * Do the 3 suggested, another will be assigned in class.  Then do any left that 
 * interest you.
 * Class assignment -> Mean Median Mode
 * Input an array, return the mean, median, and mode array.  
 * Array -> number of modes, frequency of modes, then modes.
 * 
 * Submit your code here and copy yourself on an email to mark.lehr@rcc.edu with
 * Subject: Lastname, Firstname - Assignment 2 - 44051 or 42636
 */

//System Libraries
#include <iostream> //Input Output Library
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
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

int *cpyRvse(int *, int); //function to copy and reverse the original array
void rndFill(int *, int); //function to fill array with random data
void dplyAry(int *, int); //function to display an array
int *aloAray(int); //function to allocate the memory for the array
int *aloAray2(int); //function to allocate the memory for the array
void srtScor(int *, int); //Sort function
int avgScor(int *, int); //function to return the average
void dispAry(int *, int); //Function to display array
int *aloAray3(int); //function to allocate the memory for the array
void srtScor3(int *, int); //Sort function
int avgScor3(int *, int); //function to return the average
void dispAry3(int *, int); //Function to display array
void rndDat(int *, string *, int); //Function to make up a random first and last name
void entData(int *, string *, int); //Function to enter data into array
void srtScor4(int *, string *, int); //Sort function
void dispAry4(int *, string *, int); //Function to display array
int doSomething(int *, int *); //Function from book that needs conversion to pointer
void filDAry(int *,int *,int,int); //FUnction to fill the donations array
void prnDAry(int *,int,int); //Function to print out an array 
void prnDAry(int *,int *,int,int); //Function to print out Array based on values of a 2nd array (index)
void srtDAry(int *,int *,int); //Sort function passed 2 arrays (sort index based on array values)
void filDAry2(int *,int *,int,int); //FUnction to fill the donations array
void prnDAry2(int *,int,int); //Function to print out an array 
void prnDAry2(int *,int *,int,int); //Function to print out Array based on values of a 2nd array (index)
void srtDAry2(int *,int *,int); //Sort function passed 2 arrays (sort index based on array values)
void srtMary(int *, int); //Sort function
void filMary(int *, int); //function to fill array with random ints
int fndMode(int *, int &, int); //function to find mode and return the number of modes
void disMary(int *, int); //Function to display array
void filMode(int *, int *, int, int, int); //function to fill the array with the mode frequencies
int fndMean(int *, int); //function to find the mean of an array
int fndMidi(int *, int); //function to find the median of an array

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice;
    
    //Loop on the menu
    do{
        //Input values
        cout<<"Choose from the list <non-numeric data will be ignored>"<<endl;
        cout<<"Type 1 for Problem 1: Chap9_Prob10_ReverseArray"<<endl;
        cout<<"Type 2 for Problem 2: Chap9_Prob1_ArrayOfInts"<<endl;
        cout<<"Type 3 for Problem 3: Chap9_Prob2_ArrayOfScores"<<endl;
        cout<<"Type 4 for Problem 4: Chap9_Prob3_DropLowest"<<endl;
        cout<<"Type 5 for Problem 5: Chap9_Prob4_WithNames"<<endl;
        cout<<"Type 6 for Problem 6: Chap9_Prob5_PointerRewrite"<<endl;
        cout<<"Type 7 for Problem 7: Chap9_Prob6_DonationContinuation"<<endl;
        cout<<"Type 8 for Problem 8: Chap9_Prob7_DonationDescending"<<endl;
        cout<<"Type 9 for Problem 9: Mean_Median_Mode_Class_Assignment"<<endl;
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

void prob9(){
    //Declare Variables
    int size=0, mode=0, freq=0, mean=0, median=0; //size of array, mode of array
    int *intAry=nullptr; //pointer to be assigned to array 
    int *modAry=nullptr; //WIll be assigned to array to output the mode (modes) data
    
    //Input Values
    cout<<"How large would you like to make the array?"<<endl;
    cin>>size; //input the size of the array
    while (cin.fail()||size<1){ //validate input
        cin.clear(); //reset cin flags
        cin.ignore(256, '\n'); //clear buffer contents
        cout<<"Enter an integer of 1 or larger!"<<endl;
        cin>>size; //input size again
    }
    intAry=new int [size]; //create array with size input
    filMary(intAry, size); //call function to fill array
    disMary(intAry, size); //display contents of the array
    cout<<"Array filled with random integer values: "<<endl;
    cout<<endl; 
    
    //Process by mapping inputs to outputs
    cout<<"Sorting array..."<<endl;
    srtMary(intAry, size); //call function to sort array
    disMary(intAry, size); //display contents of the array
    cout<<endl;
    cout<<"Finding Modes..."<<endl;
    freq=fndMode(intAry, mode, size); //call function to find mode and set variable mode value
    
    modAry= new int [mode];
    filMode(intAry, modAry, mode, size, freq); //fill mode values in modAry
    
    //Output values
    if (freq!=1){
        cout<<"The array has "<<mode<<" mode(s)."<<endl;
        cout<<"The modes occur with "<<freq<<" frequency."<<endl;
        cout<<"The modes are: ";
        disMary(modAry, mode);
    } else {
        cout<<"The frequency returned for this array was 1 which means that no "<<endl;
        cout<<"single element repeated itself."<<endl;
    }
    cout<<"The mean of the array values is: "<<fndMean(intAry, size)<<endl;
    cout<<"The median of the array is: "<<fndMidi(intAry, size)<<endl;
    
    //clean up arrays
    delete [] intAry; //free memory reserved by this pointer
    delete [] modAry; //free memory reserved by this pointer
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob8(){
    //Declare all Variables Here
    int size=0; //Size of the array (Number of donations)
    int *array=nullptr, *indx=nullptr; //Array containing donations in order, array for indexing donations

    
    //Input Values
    cout<<"How many donations were received? "<<endl;
    cin>>size; //Input the number of donations received
    while (cin.fail()||size<1){ //validate the input range and type
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Need to have received at least 1 donation!"<<endl;
        cin>>size;
    }
    array=new int[size]; //initialize array to store values of donations
    indx=new int[size]; //initialize array to index the donations 
    filDAry2(array,indx,size,10); //Call function to input the values of the donations
    
    //Sort the array
    srtDAry2(array,indx,size); //Call function to sort the array
    
    //Printout the sorted array
    cout<<"The donations received sorted by value: "<<endl;
    prnDAry2(array,indx,size,10); //Call function to display sorted array values (sorted with index)
    cout<<"The donations in the order they were received: "<<endl;
    prnDAry2(array,size,10); //Call function to display original array values as input

    //Delete the array
    delete []array; //Delete original array with stored donation values
    delete []indx; //Delete array that holds index values
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob7(){ 
    //Declare all Variables Here
    int size=0; //Size of the array (Number of donations)
    int *array=nullptr, *indx=nullptr; //Array containing donations in order, array for indexing donations

    
    //Input Values
    cout<<"How many donations were received? "<<endl;
    cin>>size; //Input the number of donations received
    while (cin.fail()||size<1){ //validate the input range and type
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Need to have received at least 1 donation!"<<endl;
        cin>>size;
    }
    array=new int[size]; //initialize array to store values of donations
    indx=new int[size]; //initialize array to index the donations 
    filDAry(array,indx,size,10); //Call function to input the values of the donations
    
    //Sort the array
    srtDAry(array,indx,size); //Call function to sort the array
    
    //Printout the sorted array
    cout<<"The donations received sorted by value: "<<endl;
    prnDAry(array,indx,size,10); //Call function to display sorted array values (sorted with index)
    cout<<"The donations in the order they were received: "<<endl;
    prnDAry(array,size,10); //Call function to display original array values as input

    //Delete the array
    delete []array; //Delete original array with stored donation values
    delete []indx; //Delete array that holds index values
    //Exit stage right! - This is the 'return 0' call
    
}

void prob6(){
    //Declare Variables
    int varOne=0, varTwo=0, varProd=0; //some variables to work with
    int *ptrOne= &varOne; //pointer to variable one
    int *ptrTwo= &varTwo; //pointer to variable two
    
    //Input Values
    cout<<"Input an integer for variable One: "<<endl;
    cin>>*ptrOne; //Sets value of varOne via pointer
    cout<<"Input an integer for variable Two: "<<endl;
    cin>>*ptrTwo; //Sets value of varTwo via pointer
    
    //Process by mapping inputs to outputs
    cout<<"The function output is: "<<varProd<<endl; //variable before function run and output into it
    cout<<"The value of varOne is: "<<varOne<<endl; //value of varOne int variable
    cout<<"ptrOne points at: "<<ptrOne<<endl; //ptrOne memory location
    cout<<"*ptrOne value is: "<<*ptrOne<<endl; //value of memory location ptrOne points at
    cout<<"The value of varTwo is: "<<varTwo<<endl; //value of varTwo int variable
    cout<<"ptrTwo points at: "<<ptrTwo<<endl; //ptrTwo memory location
    cout<<"*ptrTwo value is: "<<*ptrTwo<<endl; //value of memory location ptrTwo points at
    cout<<endl;
    cout<<"After running the function: "<<endl;
    varProd=doSomething(ptrOne, ptrTwo);
    
    //Output values
    cout<<"The function output is: "<<varProd<<endl; //variable before function run and output into it
    cout<<"The value of varOne is: "<<varOne<<endl; //value of varOne int variable
    cout<<"ptrOne points at: "<<ptrOne<<endl; //ptrOne memory location
    cout<<"*ptrOne value is: "<<*ptrOne<<endl; //value of memory location ptrOne points at
    cout<<"The value of varTwo is: "<<varTwo<<endl; //value of varTwo int variable
    cout<<"ptrTwo points at: "<<ptrTwo<<endl; //ptrTwo memory location
    cout<<"*ptrTwo value is: "<<*ptrTwo<<endl; //value of memory location ptrTwo points at
    
    //Exit stage right! - This is the 'return 0' call
    
}

void prob5(){
    //Set random seed in main
    
    //Declare Variables
    int size=0;  //for the size of the dynamic array
    int *aPtr=nullptr;  //creating pointer setting it to null memory area
    string *sNames=nullptr;
    bool inpFail=true;
    
    //Input Values
    cout<<"How many students took the test?"<<endl;
    cin>>size;
    while (cin.fail()||size<1){
        cout<<"Need at least one student."<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>size;
    }
    aPtr=new int [size]; //New array of ints
    sNames=new string [size]; //new array of strings
    entData(aPtr, sNames, size);
    cout<<"The Student and Score Data is: "<<endl;
    dispAry4(aPtr, sNames, size); //Display the array with scores input
    cout<<endl; 
    
    //Process by mapping inputs to outputs
    srtScor4(aPtr, sNames, size); //Sort the array lowest to highest
    cout<<"Sorted Scores List: "<<endl;
    dispAry4(aPtr, sNames, size); //display sorted array
    
    //Output values
    
    //Clean up
    delete [] aPtr; //free up the memory that was reserved for the array
    delete [] sNames; //Free up memory from the dynamic array allocation
    
    //Exit stage right! - This is the 'return 0' call
}

void prob4(){
    //Set random seed in main
    
    //Declare Variables
    int size=0;  //for the size of the dynamic array
    int *aPtr=nullptr;  //creating pointer setting it to null memory area
    char yesNo='N'; //chooser variable
    
    //Input Values
    cout<<"How many test scores are there (input a positive integer)?"<<endl;
    cin>>size;  //input size of array
    aPtr=aloAray3(size); //set pointer = to return value of allocate array function
    cout<<"Please enter the test scores: "<<endl;
    cout<<"(Randomize with values 45-99?) (Y/N)?"<<endl;
    cin>>yesNo; //Let user choose to enter scores or assign randomly
    if ((yesNo=='y')||(yesNo=='Y')){ //Randomize the scores with value 45-99
        for (int i=0;i<size;i++){
            *(aPtr + i) = rand()%55+45;
        }
        cout<<"Scores now set to random values."<<endl;
        yesNo='N'; //reset chooser variable to default
    } else { //User has to input scores in correct range
        for (int i=0;i<size;i++){
            bool inpFail=true; //Default boolean is validation fail condition
            cout<<"Input the value for test score "<<(i+1)<<": "<<endl;
            while (cin.fail()||inpFail) //Loop to validate input
            {
                cin.clear();  //Resetting flags               
                cin.ignore(256, '\n'); //clear contents of buffer 
                cout<<"Scores must be integers from zero to 100!"<<endl;
                cin>>*(aPtr+i);
                if ((*(aPtr+i)>=0)&&(*(aPtr+i)<=100)) inpFail=false; //set fail condition false
            }
        }
    }
    cout<<"The score values are: "<<endl;
    dispAry3(aPtr, size); //Display the array with scores input
    cout<<endl; 
    
    //Process by mapping inputs to outputs
    srtScor3(aPtr, size); //Sort the array lowest to highest
    cout<<"Sorted Scores List: "<<endl;
    dispAry3(aPtr, size); //display sorted array
    cout<<endl;
    cout<<"The average of all the scores is: "<<avgScor3(aPtr, size)<<endl; //calculate and display average
    
    //Output values
    
    //Clean up
    delete [] aPtr; //free up the memory that was reserved for the array
        
    //Exit stage right! - This is the 'return 0' call
    
}

void prob3(){
    //Set random seed in main
    
    //Declare Variables
    int size=0;  //for the size of the dynamic array
    int *aPtr=nullptr;  //creating pointer setting it to null memory area
    char yesNo='N'; //chooser variable
    
    //Input Values
    cout<<"How many test scores are there (input a positive integer)?"<<endl;
    cin>>size;  //input size of array
    aPtr=aloAray2(size); //set pointer = to return value of allocate array function
    cout<<"Please enter the test scores: "<<endl;
    cout<<"(Randomize with values 45-99?) (Y/N)?"<<endl;
    cin>>yesNo; //Let user choose to enter scores or assign randomly
    if ((yesNo=='y')||(yesNo=='Y')){ //Randomize the scores with value 45-99
        for (int i=0;i<size;i++){
            *(aPtr + i) = rand()%55+45;
        }
        cout<<"Scores now set to random values."<<endl;
        yesNo='N'; //reset chooser variable to default
    } else { //User has to input scores in correct range
        for (int i=0;i<size;i++){
            bool inpFail=true; //Default boolean is validation fail condition
            cout<<"Input the value for test score "<<(i+1)<<": "<<endl;
            while (cin.fail()||inpFail) //Loop to validate input
            {
                cin.clear();  //Resetting flags               
                cin.ignore(256, '\n'); //clear contents of buffer 
                cout<<"Scores must be integers from zero to 100!"<<endl;
                cin>>*(aPtr+i);
                if ((*(aPtr+i)>=0)&&(*(aPtr+i)<=100)) inpFail=false; //set fail condition false
            }
        }
    }
    cout<<"The score values are: "<<endl;
    dispAry(aPtr, size); //Display the array with scores input
    cout<<endl; 
    
    //Process by mapping inputs to outputs
    srtScor(aPtr, size); //Sort the array lowest to highest
    cout<<"Sorted Array: "<<endl;
    dispAry(aPtr, size); //display sorted array
    cout<<endl;
    cout<<"The average of all the scores is: "<<avgScor(aPtr, size)<<endl; //calculate and display average
    
    //Output values
    
    //Clean up
    delete [] aPtr; //free up the memory that was reserved for the array
    //Exit stage right! - This is the 'return 0' call
    
}

void prob2(){
    //Declare Variables
    int size=0;  //for the size of the dynamic array
    int *aPtr=nullptr;  //creating pointer setting it to null memory area
    
    //Input Values
    cout<<"How large do you want the array? (input a positive integer)"<<endl;
    cin>>size;  //input size of array
    
    //Process by mapping inputs to outputs
    aPtr=aloAray(size); //set pointer = to return value of allocate array function
    
    //Output values
    for (int i=0;i<size;i++){ //Output the array with for statement and size variable
        cout<<"Array Element: "<<i<<" contains a value of "<<aPtr[i]<<endl;
        cout<<"Written in pointer notation *(aPtr+i): "<<*(aPtr + i)<<endl;
        cout<<"Memory location of &aPtr[i] is: "<<&aPtr[i]<<endl;
        cout<<"Output written as (aPtr + i) is: "<<(aPtr + i)<<endl;
    }
    
    //Clean up
    delete [] aPtr; //free up the memory that was reserved for the array

    //Exit stage right! - This is the 'return 0' call
}

void prob1(){
    //Declare Variables
    int size=0; //variable to hold the size of array
    
    //Input Values
    cout<<"How large would you like to make the array?"<<endl;
    cin>>size; //input the size of the array
    
    //Process by mapping inputs to outputs
    int *origAry=new int[size]; //create array
    rndFill(origAry, size); //call function to fill with random data
    int *copyAry=cpyRvse(origAry, size); //create 2nd array that is reversed copy of first
    
    //Output values
    cout<<"Original Array: "<<endl; 
    dplyAry(origAry, size); //Display the original array
    cout<<endl;
    cout<<"Reversed Copy: "<<endl;
    dplyAry(copyAry, size); //display the copied and reversed array
    
    //clean up memory
    delete [] origAry; //delete memory of original array
    delete [] copyAry; //delete memory of copied array
    
    //Exit stage right! - This is the 'return 0' call
}

//function to find the median of an array
int fndMidi(int *ary, int size){
    int median=0;
    if (size%2==0){
        median= (*(ary+size/2)+ *(ary+size/2-1))/2;
    } else {
        median= *(ary+size/2);
    }
    return median;
}


//Function to find the mean of the array values
int fndMean(int *ary, int size){
    unsigned int runtot=0;
    for (int i=0;i<size;i++){
        runtot+= *(ary+i);
    }
    
    return runtot/size;
}

//function to fill the array with the mode frequencies
void filMode(int *ary, int *mAry, int modes, int size, int highest) {
    int count=0;
    int modeCnt=0;
    for (int i=0;i<size;i++){ //run through array to see how often elements occur at frequency
        count++;
        if (i==size-1){
            if (count==highest) {
                *(mAry+modeCnt) = *(ary+i);
                modeCnt++;
            }
        } else if (*(ary+i)!= *(ary+i+1)) {
            if (count==highest){
                *(mAry+modeCnt)= *(ary+i);
                modeCnt++;
            }
            count=0;
        } 
    }
} 

//Function to print array contents
void disMary(int *array, int size){
    for (int i=0;i<size;i++){ //Output the current element in the array. Loop for each element
        if (i%10==0) cout<<endl;
        cout<<setw(7)<<right;
        cout<<*(array+i);
    }
    cout<<endl;
}

//Function to find the number of modes, write mode values and mode frequency to an array
//Will return the frequency of the mode (or modes)
int fndMode(int *ary, int &modes, int size){
    int count=0, highest=0; //count and record of occurances

    for (int i=0;i<size;i++){ //run though array to find the mode frequency
        count++;
        if (i==size-1){
            if (count>highest) {
                highest=count;
            }
        } else if (*(ary+i)!= *(ary+i+1)) {
            if (count>highest){
                highest=count;
            }
            count=0;
        } 
    }
    count=0;
    
    for (int i=0;i<size;i++){ //run through array to see how often elements occur at frequency
        count++;
        if (i==size-1){
            if (count==highest) {
                modes++;
            }
        } else if (*(ary+i)!= *(ary+i+1)) {
            if (count==highest){
                modes++;
            }
            count=0;
        } 
    }
    
    return highest; //return the mode 
}

//function to fill array with random data
void filMary(int *array, int size){
    //set random seed in main
    
    int rndSize=0; //variable for user-selected size random number
    cout<<"How large of a range for the random fill numbers? "<<endl;
    cout<<"Up to 10000 (and greater than 0)"<<endl;
    cin>>rndSize; //Input size range of random (0 to rndSize)
    while (cin.fail()||rndSize<=0||rndSize>=10001){
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Enter a positive integer up to 10000!"<<endl;
        cin>>rndSize;
    }

    for (int i=0;i<size;i++){
        *(array+i)=rand()%rndSize; //fill array element with random number
    }
}

//Function to sort the array in ascending order
void srtMary(int *array, int size){
    bool swap; //create variable to keep swapping
    int temp; //Variable to hold values for swaps
    do {
        swap=false; //Set swap condition to false. Will exit swap if nothing exchanged
        for (int i=0;i<(size-1);i++) { //run through the array and see if anything needs swapping
            if (*(array+i)> *(array+(i+1))) { //swap if next element is smaller value
                temp= *(array+i); //set temp value to current element
                *(array+i) = array[i+1]; //set current element to next element
                *(array+(i+1))=temp; //set next element to temp
                swap=true; //Swap was performed so swap = true and run loop again
            }
        }
    } while (swap); //keep doing this until array is run through without a swap being done
}

//Function to sort the array on value using an index
void srtDAry2(int *a, int *indx,int n){
    for(int i=0;i<n-1;i++){ //Loop through the array to sort
        for(int j=i+1;j<n;j++){ //Loop through array to sort
            if(a[indx[i]]<a[indx[j]]){ //Swap row if value less than next
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
            }
        }
    }
}

//Function to print the array using the index values
void prnDAry2(int *a,int *indx,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){ //Output the value of the array linked to the index
        cout<<"$"<<setw(7)<<left;
        cout<<a[indx[i]];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Function to output value of an array
void prnDAry2(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){ //Output the value of the array
        cout<<"$"<<setw(7)<<left;
        cout<<a[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Function to fill an array and link inputvalue to a 2nd indexed array
void filDAry2(int *a,int *indx,int n,int mod){
    //set random seed in main
    char yesNo='n';
    cout<<"Fill with random amounts? (Y/N)"<<endl;
    cin>>yesNo;
    cout<<"Enter the value of the donations ($1 to $999999): "<<endl;
    if (yesNo=='y'||yesNo=='Y'){
        for(int i=0;i<n;i++){
            a[i]=rand()%999998+1; //Input random value for the donation 
            indx[i]=i;
        }
        cout<<"Donations filled with random values."<<endl;
    } else {
        for(int i=0;i<n;i++){
            cout<<"Donation Number "<<i+1<<": $";
            cin>>a[i]; //Input value of the donation 
            while (cin.fail()||a[i]>999999||a[i]<1){ //Validate the input for range and type
                cin.clear();
                cin.ignore(256, '\n');
                cout<<"Donation must be an integer from 1 to 999999!"<<endl;
                cin>>a[i];
            }
            indx[i]=i;
        }
    }
}

//Function to sort the array on value using an index
void srtDAry(int *a, int *indx,int n){
    for(int i=0;i<n-1;i++){ //Loop through the array to sort
        for(int j=i+1;j<n;j++){ //Loop through array to sort
            if(a[indx[i]]>a[indx[j]]){ //Swap row if value greater than next
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
            }
        }
    }
}

//Function to print the array using the index values
void prnDAry(int *a,int *indx,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){ //Output the value of the array linked to the index
        cout<<"$"<<setw(7)<<left;
        cout<<a[indx[i]];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Function to output value of an array
void prnDAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){ //Output the value of the array
        cout<<"$"<<setw(7)<<left;
        cout<<a[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Function to fill an array and link inputvalue to a 2nd indexed array
void filDAry(int *a,int *indx,int n,int mod){
    //set random seed in main
    char yesNo='n';
    cout<<"Fill with random amounts? (Y/N)"<<endl;
    cin>>yesNo;
    cout<<"Enter the value of the donations ($1 to $999999): "<<endl;
    if (yesNo=='y'||yesNo=='Y'){
        for(int i=0;i<n;i++){
            a[i]=rand()%999998+1; //Input random value for the donation 
            indx[i]=i;
        }
        cout<<"Donations filled with random values."<<endl;
    } else {
        for(int i=0;i<n;i++){
            cout<<"Donation Number "<<i+1<<": $";
            cin>>a[i]; //Input value of the donation 
            while (cin.fail()||a[i]>999999||a[i]<1){ //Validate the input for range and type
                cin.clear();
                cin.ignore(256, '\n');
                cout<<"Donation must be an integer from 1 to 999999!"<<endl;
                cin>>a[i];
            }
            indx[i]=i;
        }
    }
}

//function modified to use pointers
int doSomething(int *x, int *y) {
    int temp = *x; 
    *x = *y * 10;
    *y = temp * 10; 
    return *x + *y;
}

//Function to make up a random student's name
void rndDat(int *aPtr, string *sNames, int size){
    //set random seed in main
    for (int i=0;i<size;i++){
        char temp='\n';
        string name="";
        int length=rand()%3+4; //Determine length of name
        temp=rand()%26+65; //Get a capital letter for first name first letter
        name+=temp;
        for (int i=0;i<length;i++){ //Fill first name with letters
            temp=rand()%26+97;
            name+=temp;
        }
        name+=" ";
        length=rand()%3+4;
        temp=rand()%26+65; //Get a capital letter for last name first letter
        name+=temp;
        for (int i=0;i<length;i++){ //fill last name with letters
            temp=rand()%26+97;
            name+=temp;
        }
        *(sNames+i)=name; //Assign random name to array element
        *(aPtr+i)=rand()%101; //Assign random score to array element
    }
}

//Function to fill the array with data
void entData(int *aPtr, string *sNames,int size){
    //Set random seed in main
    
    char yesNo='N'; //chooser variable
    cout<<"Randomize names and scores? (Y/N)?"<<endl;               
    cin>>yesNo; //Let user choose to enter scores or assign randomly
    if ((yesNo=='y')||(yesNo=='Y')){ //Randomize the scores with value 45-99
        rndDat(aPtr, sNames, size);
    cout<<"Scores and names now set to random values."<<endl;
    yesNo='N'; //reset chooser variable to default
    cin.ignore(256, '\n');
    } else { //User has to input scores in correct range
        cin.ignore(256, '\n');
        for (int i=0;i<size;i++){
            cout<<"Input the student's name: "<<endl;
            getline(cin, *(sNames+i));  
            bool inpFail=true; //Default boolean is validation fail condition
            cout<<"Input the value for test score "<<(i+1)<<": "<<endl;
            cin>>*(aPtr+i);
            if ((*(aPtr+i)>=0)&&(*(aPtr+i)<=100)) inpFail=false;
            else while (cin.fail()||inpFail) //Loop to validate input
            {
                cin.clear();  //Resetting flags               
                cin.ignore(256, '\n'); //clear contents of buffer 
                cout<<"Scores must be integers from zero to 100!"<<endl;
                cin>>*(aPtr+i);
                if ((*(aPtr+i)>=0)&&(*(aPtr+i)<=100)) inpFail=false; //set fail condition false
            }
            cin.ignore(256, '\n');
        }
    }
}

//Function to sort the scores in ascending order
void srtScor4(int *array, string *names, int size){
    bool swap; //create variable to keep swapping
    int temp; //Variable to hold values for swaps
    string sTemp; //String variable for name swap
    do {
        swap=false; //Set swap condition to false. Will exit swap if nothing exchanged
        for (int i=0;i<(size-1);i++) { //run through the array and see if anything needs swapping
            if (*(array+i)> *(array+(i+1))) { //swap if next element is smaller value
                temp= *(array+i); //set temp value to current element
                sTemp= *(names+i); //set names temp to current element
                *(array+i) = array[i+1]; //set current element to next element
                *(names+i) = names[i+1]; //set current names to next names
                *(array+(i+1))=temp; //set next element to temp
                *(names+(i+1))=sTemp; //set next names to sTemp
                swap=true; //Swap was performed so swap = true and run loop again
            }
        }
    } while (swap); //keep doing this until array is run through without a swap being done
}

//Function to print array contents
void dispAry4(int *array, string *names, int size){
    cout<<setw(20)<<left<<"Student Name"<<setw(10)<<right<<"Score"<<endl;
    for (int i=0;i<size;i++){ //Output the current element in the array. Loop for each element
        cout<<setw(20)<<left<<*(names+i)<<setw(10)<<right<<*(array+i)<<endl; //output array data for this element
    }
}

//Function to calculate the average of the test scores
int avgScor3(int *array, int size){
    int temp=0;
    for (int i=1;i<size;i++){ //Start at element 1 since element 0 is lowest score
        temp+= *(array+i); //Adding up all elements of array
    }
    temp=temp/(size-1); //calculating integer average wiht one less score (lowest dropped off)
    cout<<"Not including lowest score of "<<*(array+0)<<" in the calculation."<<endl;
    return temp; //return the average score
}

//Function to sort the scores in ascending order
void srtScor3(int *array, int size){
    bool swap; //create variable to keep swapping
    int temp; //Variable to hold values for swaps
    do {
        swap=false; //Set swap condition to false. Will exit swap if nothing exchanged
        for (int i=0;i<(size-1);i++) { //run through the array and see if anything needs swapping
            if (*(array+i)> *(array+(i+1))) { //swap if next element is smaller value
                temp= *(array+i); //set temp value to current element
                *(array+i) = array[i+1]; //set current element to next element
                *(array+(i+1))=temp; //set next element to temp
                swap=true; //Swap was performed so swap = true and run loop again
            }
        }
    } while (swap); //keep doing this until array is run through without a swap being done
}

//Function to create the dynamically allocated array
int *aloAray3(int size){
    int *tmpAray=new int [size]; //create new array object
    for (int i=0;i<size;i++){ //fill array with misc. data
        tmpAray[i]=i;
    }
    return tmpAray; //return the array and exit the function
}

//Function to print array contents
void dispAry3(int *array, int size){
    for (int i=0;i<size;i++){ //Output the current element in the array. Loop for each element
        cout<<"Score number  "<<(i+1)<<":  "<<*(array+i)<<endl;
    }
}

//Function to create the dynamically allocated array
int *aloAray(int size){
    int *tmpAray=new int [size]; //create new array object
    for (int i=0;i<size;i++){ //fill array with misc. data
        tmpAray[i]=i;
    }
    return tmpAray; //return the array and exit the function
}

//function to copy reversed version of original function
int *cpyRvse(int *array, int size){
    int *a =new int[size];
    int j=0; //To increment counter to for loop decrement
    for (int i=size-1;i>=0;i--){
        *(a+j)= *(array+i); //Set new array = to last element of orig then proceed inversely
        j++; 
    }
    return a;
}

//Function to calculate the average of the test scores
int avgScor(int *array, int size){
    int temp=0;
    for (int i=0;i<size;i++){
        temp+= *(array+i); //Adding up all elements of array
    }
    temp=temp/size; //calculating integer average
    return temp; //return the average score
}

//Function to sort the scores in ascending order
void srtScor(int *array, int size){
    bool swap; //create variable to keep swapping
    int temp; //Variable to hold values for swaps
    do {
        swap=false; //Set swap condition to false. Will exit swap if nothing exchanged
        for (int i=0;i<(size-1);i++) { //run through the array and see if anything needs swapping
            if (*(array+i)> *(array+(i+1))) { //swap if next element is smaller value
                temp= *(array+i); //set temp value to current element
                *(array+i) = array[i+1]; //set current element to next element
                *(array+(i+1))=temp; //set next element to temp
                swap=true; //Swap was performed so swap = true and run loop again
            }
        }
    } while (swap); //keep doing this until array is run through without a swap being done
}

//Function to create the dynamically allocated array
int *aloAray2(int size){
    int *tmpAray=new int [size]; //create new array object
    for (int i=0;i<size;i++){ //fill array with misc. data
        tmpAray[i]=i;
    }
    return tmpAray; //return the array and exit the function
}

//Function to print array contents
void dispAry(int *array, int size){
    for (int i=0;i<size;i++){ //Output the current element in the array. Loop for each element
        cout<<"Score number  "<<(i+1)<<":  "<<*(array+i)<<endl;
    }
}

//Function to fill array with random data
void rndFill(int *array, int size) {
    //set random seed in main
    int rndSize=0; //variable to hold the size of the randoms
    cout<<"What is the range of the random fill numbers?"<<endl;
    cout<<"Enter an integer between 1 and 32000."<<endl;
    cin>>rndSize; //input size of random
    while ((rndSize<=0)||(rndSize>=32000)||cin.fail()){ //validate input size and scope
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Enter an integer between 1 and 32000!"<<endl;
        cin>>rndSize; //input size of random again (if previous attempt invalid)
    }
    for (int i=0;i<size;i++){
        *(array+i)=rand()%rndSize; //fill array with random values
    }
    cout<<"Array filled with random numbers between 0 and "<<rndSize<<endl;
}

//function to display contents of array
void dplyAry(int *array, int size) {
    for (int i=0;i<size;i++){ //loop to display the array elements
        cout<<"Element     "<<i<<":  "<<*(array+i)<<endl; //output the array element
    }
}