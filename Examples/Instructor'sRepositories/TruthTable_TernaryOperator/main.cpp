/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on January 11, 2017, 10:45 AM
  Purpose:  Truth Table
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    bool x,y;

    //Output the Header
    cout<<"X Y !X !Y  X&&Y  X||Y  X^Y  X^Y^Y  X^Y^X  !(X&&Y) !X||!Y  !(X||Y)  !X&&!Y"
            <<endl;
    
    //Process and Output values for the first row
    x=true;
    y=true;
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<"  ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"    ";
    cout<<(x&&y?'T':'F')<<"     ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x^y?'T':'F')<<"     ";
    cout<<(x^y^y?'T':'F')<<"      ";
    cout<<(x^y^x?'T':'F')<<"       ";
    cout<<(!(x&&y)?'T':'F')<<"       ";
    cout<<(!x||!y?'T':'F')<<"        ";
    cout<<(!(x||y)?'T':'F')<<"       ";
    cout<<(!x&&!y?'T':'F')<<endl;
    
    //Process and Output values for the first row
    y=false;
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<"  ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"    ";
    cout<<(x&&y?'T':'F')<<"     ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x^y?'T':'F')<<"     ";
    cout<<(x^y^y?'T':'F')<<"      ";
    cout<<(x^y^x?'T':'F')<<"       ";
    cout<<(!(x&&y)?'T':'F')<<"       ";
    cout<<(!x||!y?'T':'F')<<"        ";
    cout<<(!(x||y)?'T':'F')<<"       ";
    cout<<(!x&&!y?'T':'F')<<endl;
    
    //Process and Output values for the first row
    x=false;
    y=true;
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<"  ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"    ";
    cout<<(x&&y?'T':'F')<<"     ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x^y?'T':'F')<<"     ";
    cout<<(x^y^y?'T':'F')<<"      ";
    cout<<(x^y^x?'T':'F')<<"       ";
    cout<<(!(x&&y)?'T':'F')<<"       ";
    cout<<(!x||!y?'T':'F')<<"        ";
    cout<<(!(x||y)?'T':'F')<<"       ";
    cout<<(!x&&!y?'T':'F')<<endl;
    
    //Process and Output values for the first row
    y=false;
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<"  ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"    ";
    cout<<(x&&y?'T':'F')<<"     ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x^y?'T':'F')<<"     ";
    cout<<(x^y^y?'T':'F')<<"      ";
    cout<<(x^y^x?'T':'F')<<"       ";
    cout<<(!(x&&y)?'T':'F')<<"       ";
    cout<<(!x||!y?'T':'F')<<"        ";
    cout<<(!(x||y)?'T':'F')<<"       ";
    cout<<(!x&&!y?'T':'F')<<endl;
    
    //Exit stage right!
    return 0;
}