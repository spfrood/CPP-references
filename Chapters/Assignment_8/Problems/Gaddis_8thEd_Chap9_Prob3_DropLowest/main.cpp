
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 10, 2017, 10:45 AM
 * Purpose: 3. Drop Lowest Score
Modify Problem 2 above so the lowest test score is dropped. This score should 
not be included in the calculation of the average.
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
int *aloAray3(int); //function to allocate the memory for the array
void srtScor3(int *, int); //Sort function
int avgScor3(int *, int); //function to return the average
void dispAry3(int *, int); //Function to display array

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
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
    return 0;
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