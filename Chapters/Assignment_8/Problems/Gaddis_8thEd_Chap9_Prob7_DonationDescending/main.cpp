
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 14, 2017, 10:07 AM
 * Purpose: Problem 7
// This program shows the donates made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donates in order from lowest to highest
// and in the original order they were received.
 * 6. Case Study Modification #1
Modify Program 9-19 (the United Cause case study program) so it can be used with
any set of donates. The program should dynamically allocate the donates array
and ask the user to input its values.
 * 
7. Case Study Modification #2
Modify Program 9-19 (the United Cause case study program) so the arrptr array 
is sorted in descending order instead of ascending order.
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void filDAry2(int *,int *,int,int); //FUnction to fill the donations array
void prnDAry2(int *,int,int); //Function to print out an array 
void prnDAry2(int *,int *,int,int); //Function to print out Array based on values of a 2nd array (index)
void srtDAry2(int *,int *,int); //Sort function passed 2 arrays (sort index based on array values)

//Program Execution Begins Here
int main(int argc, char** argv) {
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
    
    //Exit
    return 0;
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
    srand(static_cast<unsigned int>(time(0)));
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
