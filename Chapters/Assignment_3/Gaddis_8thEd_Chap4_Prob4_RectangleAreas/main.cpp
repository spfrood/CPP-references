
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 12, 2017
 * Purpose: Gaddis, 8thEd, Chap4, Prob4
 *  This program will calculate the area of two rectangles and decide which
 * rectangle has a larger area or if the areas are the same.
 * 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    short rec1Len, rec1Wid, rec2Len, rec2Wid;
    int areaR1, areaR2;
        
    //Input Values
    cout<<"Please input the length and width for two rectangles."<<endl;
    cout<<"Input values between 1 and 500 units."<<endl;
    cout<<"Please enter the length of rectangle 1:"<<endl;
    cin>>rec1Len;
    cout<<"Please enter the width of rectangle 1:"<<endl;
    cin>>rec1Wid;
    cout<<"Please enter the length of rectangle 2:"<<endl;
    cin>>rec2Len;
    cout<<"Please enter the width of rectangle 2:"<<endl;
    cin>>rec2Wid;
    
    //Process by mapping inputs to outputs
    areaR1 = rec1Len*rec1Wid;  //calculating areas
    areaR2 = rec2Len*rec2Wid;
    
    //Output values
    //Check to see if values were input within range.
    if (rec1Len > 500 || rec1Wid > 500 || rec2Len > 500 || rec2Wid > 500
            || rec1Len < 1 || rec1Wid < 1 || rec2Len < 1 || rec2Wid < 1)
        cout<<"You entered a value that was out of bounds."<<endl;
    else {  //determining which rectangle is larger.
            if (areaR1>areaR2)
            cout<<"The first rectangle has a larger area."<<endl;
        else if (areaR2>areaR1)
            cout<<"The second rectangle has a larger area."<<endl;
        else cout<<"The areas are the same."<<endl;
    }
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

