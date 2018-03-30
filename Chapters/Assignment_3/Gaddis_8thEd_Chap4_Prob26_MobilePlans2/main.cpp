
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Template to be used for all programming projects 
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
    unsigned int minutes;
    float totDue, subTot;
    char package;
    
    
    //Input Values
    cout<<"Please enter your cell phone package, A, B, or C:"<<endl;
    cin>>package;
    cout<<"How many minutes did you use?"<<endl;
    cin>>minutes;
    
    //Process by mapping inputs to outputs
    
    //Output values
    if (package == 'A') {
        totDue = (minutes <= 450) ? 39.99 :
            (39.99 + ((minutes-450) * 0.45));
        cout<<"Package A Details"<<endl;
        cout<<"Your total due is: $"<<totDue<<endl;
        float totB = (minutes <= 900) ? 59.99 :
            (59.99 + ((minutes-900) * 0.40));
        if (totDue > totB) cout<<"You would have saved $"<<(totDue-totB)<<
            " if you were using Plan B."<<endl;
        float totC = 69.99;
        if (totDue > totC) cout<<"You would have saved $"<<(totDue-totC)<<
            " if you were using Plan C."<<endl;
    }
    else if (package == 'a') {
        totDue = (minutes <= 450) ? 39.99 :
            (39.99 + ((minutes-450) * 0.45));
        cout<<"Package A Details"<<endl;
        cout<<"Your total due is: $"<<totDue<<endl;
        float totB = (minutes <= 900) ? 59.99 :
            (59.99 + ((minutes-900) * 0.40));
        if (totDue > totB) cout<<"You would have saved $"<<(totDue-totB)<<
            " if you were using Plan B."<<endl;
        float totC = 69.99;
        if (totDue > totC) cout<<"You would have saved $"<<(totDue-totC)<<
            " if you were using Plan C."<<endl;
    }
    else if (package == 'B') {
        totDue = (minutes <= 900) ? 59.99 :
            (59.99 + ((minutes-900) * 0.40));
        cout<<"Package B Details"<<endl;
        cout<<"Your total due is: $"<<totDue<<endl;
        float totC = 69.99;
        if (totDue > totC) cout<<"You would have saved $"<<(totDue-totC)<<
            " if you were using Plan C."<<endl;
    }
    else if (package == 'b') {
        totDue = (minutes <= 900) ? 59.99 :
            (59.99 + ((minutes-900) * 0.40));
        cout<<"Package B Details"<<endl;
        cout<<"Your total due is: $"<<totDue<<endl;
        float totC = 69.99;
        if (totDue > totC) cout<<"You would have saved $"<<(totDue-totC)<<
            " if you were using Plan C."<<endl;
    }
    else if (package == 'C') {
        totDue = 69.99;
        cout<<"Package C Details"<<endl;
        cout<<"Your total due is: $"<<totDue<<endl;
    }
    else if (package == 'c') {
        totDue = 69.99;
        cout<<"Package C Details"<<endl;
        cout<<"Your total due is: $"<<totDue<<endl;
    }
    else cout<<"You may only choose package A, B, or C!"<<endl;
    
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

