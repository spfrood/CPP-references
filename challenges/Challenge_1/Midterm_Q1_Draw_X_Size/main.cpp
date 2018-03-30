
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 25, 2017, 6:55 PM
 * Purpose: 1)  Input the number than make an X in the following way, for 
 * instance, when you input a 5 you output. 
 * Note:  Instructor will not type in a number <1 or >50
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
    int width = 0;  //initializing variable for size of the X to draw
    
    //Input Values //explaining what is being input and showing sample output
    cout<<"This program will draw an X on the screen with a specified"<<endl;
    cout<<"width and height. The X will be drawn with numbers and will"<<endl;
    cout<<"have an output similar to the following for a size of 5."<<endl;
    cout<<"Since the instructions said only a number between 1 and 50"<<endl;
    cout<<"would be entered there is no input validation here since"<<endl;
    cout<<"time is a limiting factor."<<endl;
    cout<<"5   1"<<endl;
    cout<<" 4 2"<<endl;
    cout<<"  3"<<endl;
    cout<<" 4 2"<<endl;
    cout<<"5   1"<<endl;
    cout<<"Please enter the size of the X:"<<endl;
    cin>>width; //getting size of the X to draw from user
    cout<<endl;
    //Process by mapping inputs to outputs
    
    //Output values
    for (int drwRow=width; drwRow>0; drwRow--){ //iteration for rows
        for (int drwCol=width; drwCol>0; drwCol--){ //iteration to fill rows
            if (drwCol==drwRow) cout<<drwCol; //output initial point
            else if (drwRow==((width+1)-drwCol)) cout<<drwCol; //output end point
            else if (drwCol>0) cout<<" "; //filler space
        }
        cout<<endl; //output end of line when finished with row
    }
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

