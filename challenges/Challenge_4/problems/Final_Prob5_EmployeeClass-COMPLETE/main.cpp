
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on June 5, 2017, 9:56 AM
 * Purpose: Problem #5  (Employee Class)
	Create an Employee class with the following specification

private:
    double Tax(float);      //Utility Procedure
    char   MyName[20];      //Property
    char   JobTitle[20];    //Property
    float  HourlyRate;      //Property
    int    HoursWorked;     //Property
    float  GrossPay;        //Property
    float  NetPay;          //Property
public:
    Employee(char[],char[],float);  //Constructor
    float  CalculatePay(float,int); //Procedure
    float  getGrossPay(float,int);  //Procedure
    float  getNetPay(float);        //Procedure
    void   toString();              //Procedure
    int    setHoursWorked(int);     //Procedure
    float  setHourlyRate(float);    //Procedure


1)  The constructor inputs the Name, Job Title and Hourly rate of
the employee.
2)  All other properties are initialized to zero in the constructor.
3)  The Tax utility routine calculates the tax based on 
.1 for GrossPay < 500,
.2 for GrossPay<1000 but greater than 500, and 
.3 for anything above 1000.
4)  The Set procedures simply write and return the obvious
properties.
5)  The toString procedure prints all the properties.
6)  The getGrossPay procedure calculates straight time for hours
worked < 40, time and 1/2 for hours worked < 50 but greater than
40, double time for all hours above 50.  The inputs to this
routine are the hourly rate and the hours worked.
7)  The net pay routine returns the gross pay subtracting
off any taxes.  Realize that the Tax procedure is utilized
but these taxes are progressive rates for income above the
cutoff limit as described in 3).  Taxes are calculated for
10% below 500, 20% for amounts between 500 and 1000 and
finally anything above 1000 is calculated at the 30% rate.
8)  The Hoursworked must be > 0 and < 84
9)  The Hourlyrate must be > 0 and < 200
10) The calculate pay routine returns the net pay.
	return getNetPay(getGrossPay(setHourlyRate(x)
		,setHoursWorked(y)));

Example Input
1	Employee Mark("Mark","Boss",215.50);
2	Mark.setHoursWorked(-3);
3	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(20.0),
		Mark.setHoursWorked(25));
4	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(40.0),
		Mark.setHoursWorked(25));
5	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(60.0),
		Mark.setHoursWorked(25));
6	Mark.toString();

	Employee Mary("Mary","VP",50.0);
7	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(40));
8	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(50));
9	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(60));
10	Mary.toString();

Example Output
1  Unacceptable Hourly Rate
2  Unacceptable Hours Worked
3  Name = Mark Job Title = Boss
    Hourly Rate = 0 Hours Worked = 0 Gross Pay = 0 Net Pay = 0
4  Name = Mark Job Title = Boss
    Hourly Rate = 20 Hours Worked = 25 Gross Pay = 500 Net Pay = 450
5  Name = Mark Job Title = Boss
    Hourly Rate = 40 Hours Worked = 25 Gross Pay = 1000 Net Pay = 850
6  Name = Mark Job Title = Boss
    Hourly Rate = 60 Hours Worked = 25 Gross Pay = 1500 Net Pay = 1200
7  Name = Mary Job Title = VP
    Hourly Rate = 50 Hours Worked = 0 Gross Pay = 0 Net Pay = 0
8  Name = Mary Job Title = VP
    Hourly Rate = 50 Hours Worked = 40 Gross Pay = 2000 Net Pay = 1550
9  Name = Mary Job Title = VP
    Hourly Rate = 50 Hours Worked = 50 Gross Pay = 2750 Net Pay = 2075
10 Name = Mary Job Title = VP
    Hourly Rate = 50 Hours Worked = 60 Gross Pay = 3750 Net Pay = 2775
 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Employee.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another
//or columns for 2D arrays

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
    Mark.toString();
    
    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
    Mary.toString();
    
    //Process by mapping inputs to outputs
    
    //Output values
    
    //Clean up memory
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

