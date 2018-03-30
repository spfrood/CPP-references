
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 10, 2017, 11:45 AM
 * Purpose: 4. Test Scores #2
Modify the program of Programming Challenge 2 to allow the user to enter 
name-score pairs. For each student taking a test, the user types the student’s 
name followed by the student’s integer test score. Modify the sorting function 
so it takes an array holding the student names and an array holding the student 
test scores. When the sorted list of scores is displayed, each student’s name 
should be displayed along with his or her score. In stepping through the arrays, 
use pointers rather than array subscripts.
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void rndDat(int *, string *, int); //Function to make up a random first and last name
void entData(int *, string *, int); //Function to enter data into array
void srtScor4(int *, string *, int); //Sort function
void dispAry4(int *, string *, int); //Function to display array

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
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
    return 0;
}

//Function to make up a random student's name
void rndDat(int *aPtr, string *sNames, int size){
    srand(static_cast<unsigned int>(time(0))); //set random seed
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
    srand(static_cast<unsigned int>(time(0))); //Set random seed
    
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
            while (cin.fail()){
                cin.ignore(256, '\n');
                cin.clear();
                cout<<"Something broke. Try entering it again."<<endl;
                getline(cin, *(sNames+i));
            }
            cout<<"Input the value for test score "<<(i+1)<<": "<<endl;
            cin>>*(aPtr+i);
            while (cin.fail()|| *(aPtr+i)<0 || *(aPtr+i)>100) //Loop to validate input
            {
                cin.clear();  //Resetting flags               
                cin.ignore(256, '\n'); //clear contents of buffer 
                cout<<"Scores must be integers from zero to 100!"<<endl;
                cin>>*(aPtr+i);
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
    cout<<setw(25)<<left;
    cout<<"Student Name";
    cout<<setw(10)<<right;
    cout<<"Score"<<endl;
    for (int i=0;i<size;i++){ //Output the current element in the array. Loop for each element
        cout<<setw(25)<<left<<*(names+i)<<setw(10)<<right<<*(array+i)<<endl; //output array data for this element
    }
}