/* 
  File:   main.cpp
  Author: Scott Parker
  Created on July 31, 2017, 3:50 PM
  Purpose: New sort testing
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries
#define BGRED       "\033[41m"
#define RESET   "\033[0m"


//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void filAray (int *, int);
void prntAry (int *, int);
void minMax (int *, int);
void markSrt (int *, int);
void bubble (int *, int);
void copy (int *, int *, int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=50000;
    int *array=new int[size];
    int *brray=new int[size];
    int *crray=new int[size];
    
    //Input values
    filAray(array,size);
    copy(array,brray,size);
    copy(array,crray,size);
    
    cout<<"Number of integer Elements in arrays: "<<size<<endl;
    cout<<"Array contents generated within range of rand()"<<endl;
    
    //Mark Sort
    unsigned int bega=static_cast<unsigned int>(time(0));
    cout<<"Mark-sorting..."<<endl;
    markSrt(array,size);
    unsigned int enda=static_cast<unsigned int>(time(0));
    cout<<"Total Time for 1 function sort= "<<enda-bega<<" sec"<<endl;
    
    //Dynamic Sort
    unsigned int begb=static_cast<unsigned int>(time(0));
    cout<<"Dynamic sorting..."<<endl;
    minMax(brray,size);
    unsigned int endb=static_cast<unsigned int>(time(0));
    cout<<"Total Time for dynamic sort = "<<endb-begb<<" sec"<<endl;
    
    //Bubble Sort
    unsigned int begc=static_cast<unsigned int>(time(0));
    cout<<"Bubble-sorting..."<<endl;
    bubble(crray,size);
    unsigned int endc=static_cast<unsigned int>(time(0));
    cout<<"Total Time for Bubble sort = "<<endc-begc<<" sec"<<endl;
    
    cout<<"Time savings: Dynamic vs. Mark Sort =   "<<(1.0f*(endb-begb)/(enda-bega)-1)*100<<"%"<<endl;
    cout<<"Time savings: Mark vs. Bubble       =   "<<(1.0f*(enda-bega)/(endc-begc)-1)*100<<"%"<<endl;
    cout<<"Time savings: Dynamic vs. Bubble    =   "<<(1.0f*(endb-begb)/(endc-begc)-1)*100<<"%"<<endl;
    
    //Output array results
//    cout<<"Sorted Arrays side by side..."<<endl;
//    cout<<"Mark Sort      Test Sort      Bubble Sort"<<endl;
    int sortErr=0;
    for (int i=0;i<size;i++) {
        if (array[i]!=brray[i] || brray[i]!=crray[i] || array[i]!=crray[i]) {
//            cout<<BGRED;
            sortErr++;
        }
//        cout<<setw(15)<<left<<array[i]<<setw(15)<<left<<brray[i]<<setw(15)<<left<<crray[i]<<endl;
//        cout<<RESET;
    }
    cout<<"Total sort errors:  "<<sortErr<<endl;

    //Clean up
    delete [] array;
    delete [] brray;
    delete [] crray;
    
    //Exit
    return 0;
}

//dynamic sort function that sorts an array from both ends 
void minMax(int *a, int n){
    int temp;
    int end=n;
    long long int ops = 0; //to count iterations
    
    //dynamic sort
    for (int i=0; i<end; i++, end--) { //run through half as many times for sort
        for (int j=i; j<end; j++) {
            if (a[j]<a[i]) {
//                cout<<"Swapping a["<<j<<"] and a["<<i<<"] because "<<a[j]<<"<"<<a[i]<<endl;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            } else if (a[j]>a[end-1]) {
//                cout<<"Swapping a["<<j<<"] and a["<<end-1<<"] because "<<a[j]<<">"<<a[end-1]<<endl;
                temp=a[end-1];
                a[end-1]=a[j];
                a[j]=temp;
            }
            ops++;
        }
        ops++;
    }
    cout<<"Number of operations: "<<ops<<endl;
}

//bubble sort
void bubble(int *a, int n){
    bool swap;
    int temp;
    long long int ops=0; //To count iterations
    do{
        swap=false;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
            ops++;
        }
        ops++;
    }while(swap);
    cout<<"Number of operations: "<<ops<<endl;
}

//Sort created by Mark Lehr
void markSrt(int *a, int n){
    int temp;
    long long int ops=0; //to count iterations
    
    for(int j=0;j<n-1;j++){
        for(int i=j+1;i<n;i++){
            if(a[j]>a[i]){
                //a[j]=a[j]^a[i];
                //a[i]=a[j]^a[i];
                //a[j]=a[j]^a[i];
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
            ops++;
        }
        ops++;
    }
    cout<<"Number of operations: "<<ops<<endl;
}

//Print the array
void prntAry(int *a, int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<": "<<a[i]<<" "<<endl;
    }
    cout<<endl;
}

//Fill the array
void filAray(int *a, int n){
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
}

//Copy array
void copy(int *a, int *b, int size) {
    for (int i=0;i<size;i++) {
        b[i]=a[i];
    }
}