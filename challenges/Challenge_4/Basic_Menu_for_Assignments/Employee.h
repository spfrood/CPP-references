

/* 
 * File:   Employee.h
 * Author: scott_r_parker
 *
 * Created on June 8, 2017, 6:22 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee {
private:
    float Tax(float);      //Utility Procedure
    char   *MyName;      //Property
    char   *JobTitle;    //Property
    float  HourlyRate;      //Property
    int    HoursWorked;     //Property
    float  GrossPay;        //Property
    float  NetPay;          //Property
public:
    Employee(char[],char[],float);  //Constructor
    virtual ~Employee();            //Destructor
    float  CalculatePay(float,int); //Procedure
    float  getGrossPay(float,int);  //Procedure
    float  getNetPay(float);        //Procedure
    void   toString();              //Procedure
    int    setHoursWorked(int);     //Procedure
    float  setHourlyRate(float);    //Procedure

};

#endif /* EMPLOYEE_H */

