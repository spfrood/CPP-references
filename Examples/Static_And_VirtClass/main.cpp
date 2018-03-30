
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on June 28, 2017, 5:00 PM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values as well as conversions from one system 
//of measurements to another

//Function Prototypes

class Person {
protected: 
    string name;
    int age;
    static int profCount;
    static int stuCount;
public: 
    Person () {};
    virtual void getdata ()=0;
    virtual void putdata ()=0;
};

class Professor : public Person {
private:
    int publications;
    int cur_id;
public: 
    Professor () : Person () {
        cur_id=profCount;
        profCount++;
    };
    void getdata () {
        cin>>name;
        cin>>age;
        cin>>publications;
    }; 
    void putdata () { 
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    };
};

class Student : public Person {
private:
    int marks[6];
    int cur_id;
public: 
    Student () : Person () {
        cur_id=stuCount;
        stuCount++;
    };
    void getdata () {
        cin>>name;
        cin>>age;
        for (int i=0;i<6;i++) {
            cin>>marks[i];
        }
        
    }; 
    void putdata () { 
        int temp=0;
        for (int i=0;i<6;i++) {
            temp+=marks[i];
        }
        cout << name << " " << age << " " << temp << " " << cur_id << endl;
    };
};

int Person::profCount=1;
int Person::stuCount=1;

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

