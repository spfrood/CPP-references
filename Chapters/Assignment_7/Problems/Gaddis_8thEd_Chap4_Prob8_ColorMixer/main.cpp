
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on February 23, 2017, 9:30 PM
 * Purpose: 8. Color Mixer
 * The colors red, blue, and yellow are known as the primary colors because they 
 * cannot be made by mixing other colors. When you mix two primary colors, you 
 * get a secondary color, as shown here:
 * When you mix red and blue, you get purple. 
 * When you mix red and yellow, you get orange. 
 * When you mix blue and yellow, you get green.
 * Write a program that prompts the user to enter the names of two primary 
 * colors to mix. If the user enters anything other than “red,” “blue,” or 
 * “yellow,” the program should display an error message. Otherwise, the program 
 * should display the name of the secondary color that results by mixing two 
 * primary colors.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const string red="red";  //primary color
    const string blue="blue";  //primary color
    const string yellow="yellow";  //primary color
    string color1="";  //user base color
    string color2="";  //user additive color
    
    //Input Values
    cout<<"What is your base primary color?"<<endl;
    getline(cin, color1); //user enter baser primary color
    while (color1!=red&&color1!=blue&&color1!=yellow){  //input validation for base color
        cout<<"You need to enter red, blue, or yellow!"<<endl;
        cout<<"Please enter your base primary color:"<<endl;
        getline(cin, color1);
    }
    cout<<"What primary color do you wish to mix with your base color?"<<endl;
    getline(cin, color2);  //user input for color to add to base
    while (color2!=red&&color2!=blue&&color2!=yellow){  //input validation for additive color
        cout<<"You need to enter red, blue, or yellow!"<<endl;
        cout<<"Please enter your the primary color to add:"<<endl;
        getline(cin, color2);
    }
    
    
    //Process by mapping inputs to outputs
    
    //Output values
    //if colors are the same no change
    if (color2==color1) cout<<"It's kind of weird to do that but your color is still "<<color2<<"."<<endl;
    else if (color1==red){ //red base
        if (color2==blue){  //red and blue = purple
            cout<<"Your new color is purple."<<endl;
        }
        else if (color2==yellow){ //red and yellow = orange
            cout<<"Your new color is orange."<<endl;
        }
        else cout<<"ERROR! Something broke here! Base Red"<<endl; //Something didn't work
    }
    else if (color1==blue){ //blue base
        if (color2==red){  //blue and red = purple
            cout<<"Your new color is purple."<<endl;
        }
        else if (color2==yellow){ //blue and yellow = green
            cout<<"Your new color is green."<<endl;
        }
        else cout<<"ERROR! Something broke here! Base Blue"<<endl; //Something didn't work
    }
    else if (color1==yellow){ //yellow base
        if (color2==red){ //yellow and red = orange
            cout<<"Your new color is orange."<<endl;
        }
        else if (color2==blue){ //yellow and blue = green
            cout<<"Your new color is green."<<endl;
        }
        else cout<<"ERROR! Something broke here! Base Yellow"<<endl; //something didn't work
    }    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

