
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Problem 1
 * 
Write a function that takes an unsigned
short integer and returns a signed short
number in reverse.  For instance 106 
reversed would be 601.  Another would be 
30000 gives 3.  Subtract the largest 3
digit number you can without going negative.  
Check to make sure the 
conversion falls within the range for a
signed short. If it doesn't then output
no conversion possible else output the result.
*/

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes
short numRvse(unsigned short);  //Function to reverse number entered

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int inpuNum=0;  //Number input by user to be processed and converted
    unsigned short num=0;  //to assign user number if within bounds
    short outNum=0;  //Signed short for function to return value 
    
    //Input Values
    do {  //Validating input to make sure it can be an unsigned short
        cout<<"Please input a number from 0 to 65,535"<<endl;
        cin>>inpuNum;
        if (inpuNum<0||inpuNum>65535) {
            cout<<"Not a valid input!"<<endl;
        }
    } while (inpuNum<0||inpuNum>65535);
    num=inpuNum;  //assigning input number to be unsigned short
    
    //Process by mapping inputs to outputs
    
    //Output values
    outNum=numRvse(num); //Running function to reverse input and return unsigned short
    if (outNum==0){ //Conversion was not possible... reversed number out of bounds
        cout<<"Conversion not possible in bounds of question."<<endl;
    }else {  //Outputting reversed number
        cout<<"Reversed number = "<<outNum<<endl;
        if (outNum<100) { //Check to see if possible to subtract 3 digit number
            cout<<"Not possible to subtract a 3 digit number."<<endl;
        } else if (outNum>=999) { //999 is largest poss 3 digit num
            cout<<"Subtracting 999 so new number = "<<(outNum-999)<<endl; 
        }
        else { //Largest possible 3-digit number is the number itself
            cout<<"The largest 3-digit value that can be subtracted is "<<outNum<<endl;
            cout<<"Which puts the result at: "<<(outNum=outNum-outNum)<<endl;
        }
    }
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Reverse and Convert ********************************
//Description: Reverses an unsigned short number and converts it to a positive
//         signed short
//
//Inputs: Unsigned short number
//     
//Outputs: Positive signed short
//******************************************************************************
short numRvse(unsigned short orig){
    
    const int TENTHOS=10000; //Conversion to 10,000
    const int THOSNDS=1000;  //Conversion to 1,000
    const int HUNDRDS=100;   //Conversion to   100
    const int TENS=10;       //Conversion to    10
    
    int tmpAmnt; //Using int because reverse value may exceed max short value
    short n10000,n1000,n100,n10,n1; //The numbers of powers of 10
    short tenKs, oneKs, hunds, tens, ones;
    
    tmpAmnt=orig; //Setting tmpAmnt working variable to value of amount
    n10000=(tmpAmnt-tmpAmnt%TENTHOS)/TENTHOS;//Determines how many 10000's
    tmpAmnt=(tmpAmnt-n10000*TENTHOS);       //value without 10000's
    n1000=(tmpAmnt-tmpAmnt%THOSNDS)/THOSNDS;//Determines how many 1000's
    tmpAmnt=(tmpAmnt-n1000*THOSNDS);       //Value without 1000's
    n100=(tmpAmnt-tmpAmnt%HUNDRDS)/HUNDRDS;//Determines how many 100's
    tmpAmnt=(tmpAmnt-n100*HUNDRDS);        //Value without 100's
    n10=(tmpAmnt-tmpAmnt%TENS)/TENS;      //Determines how many 10's
    n1=(tmpAmnt-n10*TENS);            //Value without 10's (just ones)
    
    if (n10000>=1){ //assigning value to 10000 if it applies
        tmpAmnt=n1*TENTHOS+n10*THOSNDS+n100*HUNDRDS+n1000*TENS+n10000;
    } else if (n1000>=1){ //assigning value to 1000 if it applies
        tmpAmnt=n1*THOSNDS+n10*HUNDRDS+n100*TENS+n1000;
    } else if (n100>=1){ //assigning value to 100 if it applies
        tmpAmnt=n1*HUNDRDS+n10*TENS+n100;    
    } else if (n10>=1){ //assigning value to 10 if it applies
        tmpAmnt=n1*TENS+n10;  
    } else if(n1>=1){ //assigning value to 1 if it applies
        tmpAmnt=n1;
    }
    if (tmpAmnt>32767) {
        tmpAmnt=0;
    }
    return tmpAmnt; //return the reversed value or 0 if out of bounds
}