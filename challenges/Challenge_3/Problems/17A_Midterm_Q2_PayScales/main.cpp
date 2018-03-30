
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on April 22, 2017, 12:19 PM
 * Purpose: 2)  Develop an application using an array of structures that will 
determine the gross pay for any number of employees input. The company pays 
"straight-time" for the first 40 hours worked, double time for 
all hours worked in excess of 40 hours but less than 50 hours, 
and triple time for any hours worked over 50 hours.

The program should be able to loop and input the employee's name, 
hours worked, and the rate of pay.  Once this has been done then output
this information including the gross pay in the form of a paycheck.
The process starts all over 
again until you input an invalid rate of pay or hours worked.  This
means a negative rate of pay or negative number of hours worked is
not acceptable.

Paycheck
Company
Address
Name:	Amount: numerical
Amount: English
Signature:

***Implementation note! Dynamic array of structure, copy to alternate, delete 
first array, recreate one size larger, copy back to new array, delete second 
array, input new data into first array.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
#include "comdata.h"
#include "empdata.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const int THOSNDS=1000;//Conversion to 1,000
const int HUNDRDS=100; //Conversion to   100
const int TENS=10;     //Conversion to    10

//Function Prototypes
void prnCh02(EmpData, ComData); //Function to print the paycheck
EmpData *addLi02(EmpData *, EmpData, int); //Function to add additional entry to array
void pEmpC10(EmpData *, int); //display contents of array (all workers and checks cut)

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    ComData company; //company info for the check data 
    EmpData worker; //worker data for getting paid
    int size=0; //counter for array
    EmpData *worList=nullptr; //array to hold all values
    
    //Input data on the company
    cout<<"Please enter the necessary information to fill out a check."<<endl;
    cout<<"Which company is this payroll for?"<<endl;
    getline (cin, company.comName);
    cout<<"Enter the street address of company:"<<endl;
    getline (cin, company.street);
    cout<<"Enter the city:"<<endl;
    getline(cin, company.city);
    cout<<"Enter the state:"<<endl;
    getline (cin, company.state);
    cout<<"Enter company zipcode:"<<endl;
    getline (cin, company.zip);
    cout<<"Enter the date this payrole is to be paid:"<<endl;
    getline (cin, company.date);
    
    //Input first round of employee data. MUST enter data for eat least one employee
    cout<<"Enter the employee's name: "<<endl;
    getline(cin, worker.empName);
    cout<<"Enter the hours worked this week (Max of 80):"<<endl;
    cin>>worker.hrsWrkd;
    while (cin.fail() || worker.hrsWrkd>80 || worker.hrsWrkd<=0){ //validate data type and range
        cout<<"Entry not valid! Enter a non-zero positive integer less than 80!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>worker.hrsWrkd;
    }
    cout<<"Enter the rate of pay for this employee (Max of $133/hr) (0 or less to exit):"<<endl;
    cin>>worker.payRate;
    while (cin.fail() || worker.payRate>133 || worker.payRate<=0) { //validate data type and range
        cout<<"Entry not valid! Enter a non-zero positive integer of 133 or less!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>worker.payRate;
    }
    size++; //We officially have the data to create an array of (size) elements (1 in this case)
    while (worker.hrsWrkd >0 && worker.payRate>0) { //keep looping until negative pay or hours value
        prnCh02(worker, company); //print the employee's check
        cout<<endl;
        worList=addLi02(worList, worker, size); //Add a line to the array and write the employee data to array
        
        //Repeat process until a check for $0 or less would be cut
        cout<<"Enter the employee's name: "<<endl;
        cin.ignore(256, '\n');
        getline(cin, worker.empName);
        cout<<"Enter the hours worked this week (Max of 80) (0 or less to exit):"<<endl;
        cin>>worker.hrsWrkd;
        while (cin.fail() || worker.hrsWrkd>80){ //validate range and data type
            cout<<"Entry not valid! Enter a non-zero positive integer less than 80!"<<endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin>>worker.hrsWrkd;
        }
        cout<<"Enter the rate of pay for this employee (Max of $133/hr):"<<endl;
        cin>>worker.payRate;
        while (cin.fail() || worker.payRate>133) { //validate range and data type
            cout<<"Entry not valid! Enter a non-zero positive integer of 133 or less!"<<endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin>>worker.payRate;
        }
        size++; //Increment number of employees
    }
    
    pEmpC10(worList, size); //display contents of array (all workers and checks cut)
    
    //Clean up memory
    delete [] worList;
    
    //Exit stage right!
    return 0;
}


//display contents of array (all workers and checks cut)
void pEmpC10(EmpData *a, int size){ 
    //format... make it look pretty
    cout<<setw(10)<<left<<"Emp. Num"<<setw(25)<<left<<"Name"<<setw(10)<<left<<"Hours"<<setw(10)<<left<<"Rate"<<endl;
    for (int i=0;i<size-1;i++){ //loop through the array and output the info from each item
        cout<<setw(7)<<right<<i+1<<":  ";
        cout<<setw(25)<<left<<a[i].empName;
        cout<<setw(10)<<left<<a[i].hrsWrkd;
        cout<<setw(10)<<left<<a[i].payRate<<endl; 
    }
}

//Function to add additional entry to array
EmpData *addLi02(EmpData *a, EmpData e, int size) {
    EmpData *tmp= new EmpData[size]; //create temp array
    if (size==1){ //first time around no need to copy arrays
        a=new EmpData[size]; //create array of 1 element 
        a[size-1].empName=e.empName; //write emp data from single element to the array
        a[size-1].hrsWrkd=e.hrsWrkd;
        a[size-1].payRate=e.payRate;
    } else { //Do this after the first time
        for (int i=0;i<size;i++){ //assign current array to new array
            tmp[i]=a[i]; //copy array
        }
        delete [] a; //delete old array
        a=new EmpData[size]; //re-create array 1 element larger
        for (int i=0;i<size;i++){ //loop through array
            a[i]=tmp[i]; //copy data back to the main array
        } 
        //add the data from the new employee to the array
        a[size-1].empName=e.empName; 
        a[size-1].hrsWrkd=e.hrsWrkd;
        a[size-1].payRate=e.payRate;
    }
    delete [] tmp; //delete the temp array used in copying
    return a; //Return the new larger array and exit function
}


//Function to print a paycheck when passed employee information
void prnCh02(EmpData e, ComData c) { 
    //Declare Variables
    string date=c.date, holder=c.comName, payTo=e.empName, payFor="Payroll for hours worked"; 
    unsigned short amount, tmpAmnt; //check data and tmp used in calculation 
    char n1000,n100,n10,n1; //The numbers of powers of 10
    string amtText=""; //for converting amount to text
    
    //Input values 
    if (e.hrsWrkd<=40) amount=e.hrsWrkd*e.payRate; //if no overtime
    else if (e.hrsWrkd<=50) amount=(e.payRate*40+((e.hrsWrkd-40)*2*e.payRate)); //if overtime (41-50 hours)
    else amount=(e.payRate*40+e.payRate*20+(((e.hrsWrkd-50)*3)*e.payRate)); //if tripletime (51+ hours)
    
    //Parsing the amount into sections for conversion to text
    tmpAmnt=amount; //Setting tmpAmnt working variable to value of amount
    n1000=(tmpAmnt-tmpAmnt%THOSNDS)/THOSNDS;//Determines how many 1000's
    tmpAmnt=(tmpAmnt-n1000*THOSNDS);       //Year without 1000's
    n100=(tmpAmnt-tmpAmnt%HUNDRDS)/HUNDRDS;//Determines how many 100's
    tmpAmnt=(tmpAmnt-n100*HUNDRDS);        //Year without 100's
    n10=(tmpAmnt-tmpAmnt%TENS)/TENS;      //Determines how many 10's
    n1=(tmpAmnt-n10*TENS);            //Year without 10's
    
    //Convert year to text
    //Calculate thousands output 
    switch(n1000){
        case 19:amtText+="Nineteen Thousand ";break;
        case 18:amtText+="Eighteen Thousand ";break;
        case 17:amtText+="Seventeen Thousand ";break;
        case 16:amtText+="Sixteen Thousand ";break;
        case 15:amtText+="Fifteen Thousand ";break;
        case 14:amtText+="Fourteen Thousand ";break;
        case 13:amtText+="Thirteen Thousand ";break;
        case 12:amtText+="Twelve Thousand ";break;
        case 11:amtText+="Eleven Thousand ";break;
        case 10:amtText+="Ten Thousand ";break;
        case 9:amtText+="Nine Thousand ";break;
        case 8:amtText+="Eight Thousand ";break;
        case 7:amtText+="Seven Thousand ";break;
        case 6:amtText+="Six Thousand ";break;
        case 5:amtText+="Five Thousand ";break;
        case 4:amtText+="Four Thousand ";break;
        case 3:amtText+="Three Thousand ";break;
        case 2:amtText+="Two Thousand ";break;
        case 1:amtText+="One Thousand ";break;
        case 0:break;
        default:cout<<"ERROR SWITCH n1000"<<endl;
    }
    
    //Calculate Hundreds
    switch(n100){
        case 9:amtText+="Nine Hundred ";break;
        case 8:amtText+="Eight Hundred ";break;
        case 7:amtText+="Seven Hundred ";break;
        case 6:amtText+="Six Hundred ";break;
        case 5:amtText+="Five Hundred ";break;
        case 4:amtText+="Four Hundred ";break;
        case 3:amtText+="Three Hundred ";break;
        case 2:amtText+="Two Hundred ";break;
        case 1:amtText+="One Hundred ";break;
        case 0:break;
        default:cout<<"ERROR SWITCH n100"<<endl;
    }
    
    //Calculate Tens with exception of less than 20
    switch(n10){
        case 9:amtText+="Ninety ";break;
        case 8:amtText+="Eighty ";break;
        case 7:amtText+="Seventy ";break;
        case 6:amtText+="Sixty ";break;
        case 5:amtText+="Fifty ";break;
        case 4:amtText+="Forty ";break;
        case 3:amtText+="Thirty ";break;
        case 2:amtText+="Twenty ";break;
        case 1:;break;
        case 0:break;
        default:cout<<"ERROR SWITCH n10"<<endl;
    }
    
    //Calculate Ones if tens are 20 or greater
    if (n10!=1){
        switch(n1){
            case 9:amtText+="Nine ";break;
            case 8:amtText+="Eight ";break;
            case 7:amtText+="Seven ";break;
            case 6:amtText+="Six ";break;
            case 5:amtText+="Five ";break;
            case 4:amtText+="Four ";break;
            case 3:amtText+="Three ";break;
            case 2:amtText+="Two ";break;
            case 1:amtText+="One ";break;
            case 0:break;
            default:cout<<"ERROR SWITCH n1"<<endl;
        }
    }
    
    //Ones for tens value of less than 20 (teens)
    if (n10==1) {
        switch(n1){
            case 9:amtText+="Nineteen ";break;
            case 8:amtText+="Eighteen ";break;
            case 7:amtText+="Seventeen ";break;
            case 6:amtText+="Sixteen ";break;
            case 5:amtText+="Fifteen ";break;
            case 4:amtText+="Fourteen ";break;
            case 3:amtText+="Thirteen ";break;
            case 2:amtText+="Twelve ";break;
            case 1:amtText+="Eleven ";break;
            case 0:amtText+="Ten ";break;
            default:cout<<"ERROR SWITCH n1"<<endl;
        }
    }
    
    //format data and output check
    cout<<"Printing Check!"<<endl<<endl;
    cout<<setw(50)<<left<<holder<<setw(10)<<right<<"Date: "<<c.date<<endl;
    cout<<c.street<<endl;
    cout<<c.city+", "<<c.state+"  "<<c.zip<<endl;
    cout<<"Pay to the order of: "<<setw(25)<<left<<payTo<<setw(21)<<right
        <<"Amount: $"<<setw(5)<<right<<amount<<".00"<<endl<<endl;
    cout<<"The Amount Of: "<<amtText<<"dollars and 00/100 "<<endl<<endl;
    cout<<"Bank of CSC17A"<<setw(61)<<right<<holder<<endl;
    cout<<"Memo: "<<setw(59)<<left<<payFor<<setw(10)<<right<<"Signature"<<endl;
    
    //Exit stage right!
}