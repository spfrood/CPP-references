
/* 
 * File:   Employee.cpp
 * Author: scott_r_parker
 * 
 * Created on June 8, 2017, 6:22 PM
 */

#include <cstring>
#include <iomanip>
#include "Employee.h"

//Constructor - set base values 
Employee::Employee(char *nam, char *tit, float hrlyRte) {
    MyName = new char[strlen(nam) + 1];
    JobTitle = new char [strlen(tit) + 1];
    strcpy(MyName, nam);
    strcpy(JobTitle, tit);
    HourlyRate=hrlyRte; 
    if (HourlyRate>200.0 || HourlyRate<0.0) {
        cout<<"Unacceptable Hourly Rate"<<endl;
        HourlyRate=0.0;
    }
    HoursWorked=0;   
    GrossPay=0.0;     
    NetPay=0.0; 
} 

//Delete dynamic memory used for character arrays
Employee::~Employee() {
    delete [] MyName;
    delete [] JobTitle;
}

//Utility to calculate taxes
float Employee::Tax(float grosPay) {
    float temp=0.0;
    if (grosPay<500) {
        temp=grosPay*0.1;
    } else if (grosPay<1000) {
        temp=((500*0.1)+(0.2*(grosPay-500)));
    } else {
        temp=((500*0.1)+(500*0.2)+(0.3*(grosPay-1000)));
    }
    return temp;
}

//Procedure to return net pay
float  Employee::CalculatePay(float payRate, int hrsWrkd) {
    return getNetPay(getGrossPay(setHourlyRate(payRate), setHoursWorked(hrsWrkd)));
}

//Procedure to set and return gross pay
float  Employee::getGrossPay(float payRate, int hrsWrkd) {
//    6)  The getGrossPay procedure calculates straight time for hours
//    worked < 40, time and 1/2 for hours worked < 50 but greater than
//    40, double time for all hours above 50.  The inputs to this
//    routine are the hourly rate and the hours worked.
    float temp=0.0;
    if (hrsWrkd<40) {
        temp=hrsWrkd*payRate;
    } else if (hrsWrkd<50) {
        temp=((payRate*40)+((payRate*(hrsWrkd-40))*1.5));
    } else {
        temp=((payRate*40)+((payRate*10)*1.5)+((payRate*(hrsWrkd-50))*2));
    }
    GrossPay=temp;
    
    return GrossPay;
}

//Procedure to set and return net pay
float  Employee::getNetPay(float grosPay) {
    float temp=Tax(grosPay);
    NetPay=GrossPay-temp;
    return NetPay;
}

//Procedure to output all data
void   Employee::toString() { 
//Name = Mark Job Title = Boss
// Hourly Rate = 0 Hours Worked = 0 Gross Pay = 0 Net Pay = 0
    cout<<setprecision(2)<<fixed;
    cout<<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl;
    cout<<" Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked
            <<" Gross Pay = "<<GrossPay<<" Net Pay = "<<NetPay<<endl;
}          

//Procedure to set the hours worked and validate range
int    Employee::setHoursWorked(int hrs) {
    //8)  The Hoursworked must be > 0 and < 84 
    if (hrs>0 && hrs<84) {
        HoursWorked=hrs;
    } else {
        cout<<"Unacceptable Hours Worked"<<endl;
        HoursWorked=0;
    }
    return HoursWorked;
}  

//Procedure to set hourly pay rate and validate range
float  Employee::setHourlyRate(float rate) {
    //9)  The Hourlyrate must be > 0 and < 200
    if (rate>200.0 || rate<0.0) {
        cout<<"Unacceptable Hourly Rate"<<endl;
        HourlyRate=0.0;
    } else {
        HourlyRate=rate;
    }
    return HourlyRate;
}  