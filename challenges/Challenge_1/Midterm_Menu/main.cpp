
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Template to be used for all programming projects 
 */

//System Libraries
#include <iostream> //basic functions cout, etc
#include <iomanip> //Format Library
#include <string> //for working with strings
#include <cmath> //for mathmatical functions
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void prob1 ();
void prob2 ();
void prob3 ();
void prob4 ();
void prob5 ();
void prob6 ();

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    char choice;
    short menOpt=0;
    
    //Loop on the menu
    
    do {
        
        //Input Values
        cout<<endl;
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Midterm Question 1 - Draw an X"<<endl;
        cout<<"Type 2 for Midterm Question 2 - Outputting Characters"<<endl;
        cout<<"Type 3 for Midterm Question 3 - Writing a Check"<<endl;
        cout<<"Type 4 for Midterm Question 4 - ISP Rate-Plan Comparison"<<endl;
        cout<<"Type 5 for Midterm Question 5 - Gross Pay Calculation"<<endl;
        cout<<"Type 6 for Midterm Question 6 - Just Another Sequence"<<endl;
        cout<<"Any other character to exit"<<endl;
        cin>>choice;
        menOpt=choice-48; //Changing to integer to use switch
        
        //Switch to determine the problem
        switch(menOpt){
            case 6:{prob6();break;}
            
            case 5:{prob5();break;}
            
            case 4:{prob4();break;}
            
            case 3:{prob3();break;}
            
            case 2:{prob2();break;}
            
            case 1:{prob1();break;}
            
            default:
               cout<<"You are exiting the program"<<endl;
        }
            
    
    }while(choice>='1' && choice <= '6');
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************** Question 1 - Draw an X **********************************
//Description: 1)  Input the number than make an X in the following way,
//for instance, when you input a 5 you output.
//Note:  Instructor will not type in a number <1 or >50
//       See Midterm question textfile for more details
//Inputs:
//     Width -> How large the X will be drawn
//Outputs:
//     drawing the X on the screen
//******************************************************************************
void prob1 () {
    cout<<endl<<"Question 1 - Draw an X"<<endl;
    //Declare Variables
    int width = 0;  //initializing variable for size of the X to draw
    
    //Input Values //explaining what is being input and showing sample output
    cout<<"This program will draw an X on the screen with a specified"<<endl;
    cout<<"width and height. The X will be drawn with numbers and will"<<endl;
    cout<<"have an output similar to the following for a size of 5."<<endl;
    cout<<"Since the instructions said only a number between 1 and 50"<<endl;
    cout<<"would be entered there is no input validation here since"<<endl;
    cout<<"time is a limiting factor."<<endl;
    cout<<"Sample Output"<<endl;
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
    //But not here because this is a void function
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Question 2 - Character Output ******************************
//Description:  Read a 4 character number.  Output the result in the 
//       as * or ? if not a number.
//       See Midterm question textfile for more details
//Inputs:
//     4-digit number: char1, char2, char3, char4.
//Outputs:
//     * equivalent to the number or a ? if not in reverse order to how the
//       characters were entered
//******************************************************************************
void prob2 () {
    cout<<endl<<"Question 2 - Outputting Characters"<<endl;
    //Declare Variables
    char digit1, digit2, digit3, digit4; //The 4 digits of the number
    
    //Input Values
    cout<<"This program will display output for a 4 digit number."<<endl;
    cout<<"It will change the format of the output based on the digit"<<endl;
    cout<<"that is entered. Please input 4 digits: "<<endl;
    cin>>digit1>>digit2>>digit3>>digit4;
    
    //Process by mapping inputs to outputs
    
    //Output values
    if (static_cast<int>(digit4)<48||static_cast<int>(digit4)>57) 
        cout<<"?"<<endl; //determining if digit4 is number 
    else { //Outputting * equal to value of digit. Looks weird if 0 entered.
        for (int drwLine = 0; drwLine<(digit4-48); drwLine++){
        cout<<"*";
        }
    cout<<endl;
    }
    if (static_cast<int>(digit3)<48||static_cast<int>(digit3)>57) 
        cout<<"?"<<endl; //determining if digit4 is number
    else { //Outputting * equal to value of digit. Looks weird if 0 entered.
        for (int drwLine = 0; drwLine<(digit3-48); drwLine++){
        cout<<"*";
        }
    cout<<endl;
    }
    if (static_cast<int>(digit2)<48||static_cast<int>(digit2)>57) 
        cout<<"?"<<endl; //determining if digit4 is number
    else { //Outputting * equal to value of digit. Looks weird if 0 entered.
        for (int drwLine = 0; drwLine<(digit2-48); drwLine++){
        cout<<"*";
        }
    cout<<endl;
    }
    if (static_cast<int>(digit1)<48||static_cast<int>(digit1)>57) 
        cout<<"?"<<endl; //determining if digit4 is number
    else { //Outputting * equal to value of digit. Looks weird if 0 entered.
        for (int drwLine = 0; drwLine<(digit1-48); drwLine++){
        cout<<"*";
        }
    cout<<endl;
    }
    
    //Exit stage right! - This is the 'return 0' call
    //But not here because this is a void function.
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Question 3 - Write a Check*** ******************************
//Description: We would like to write a check.  
// Input the following: Date, Payee, Amount, and the account holder.  
// Output these in the following format, but the amount needs to be output 
// numerically as well as grammatically just like a check. 
// Range for the check amount = $1 to $1999 (integers, no cents)
//       See Midterm question textfile for more details
//Inputs:
//     Account Holder, Payee, Date, Reason for Check, Amount
//Outputs:
//     Formatted check with fields filled in
//******************************************************************************
void prob3 () {
    cout<<endl<<"Question 3 - Writing a Check"<<endl;
    //Global Constants
    //Such as PI, Vc, -> Math/Science values
    //as well as conversions from system of units to another
    const int THOSNDS=1000;//Conversion to 1,000
    const int HUNDRDS=100; //Conversion to   100
    const int TENS=10;     //Conversion to    10
    
    //Declare Variables
    string date="", holder="", payTo="", payFor=""; //check data
    unsigned short amount, tmpAmnt; //check data and tmp used in calculation
    char n1000,n100,n10,n1; //The numbers of powers of 10
    string amntText=""; //for converting amount to text
    
    //Input values 
    //Information fields for writing the check
    cout<<"Please enter the necessary information to fill out a check."<<endl;
    cout<<"Who owns the bank account?"<<endl;
    cin.ignore();
    getline(cin, holder);
    cout<<"Who are you paying?"<<endl;
    getline(cin, payTo);
    cout<<"When will the check be dated?"<<endl;
    getline(cin, date);
    cout<<"What are you buying?(60 character max)"<<endl;
    getline(cin, payFor);
    cout<<"How much will you pay ($1 to $1999, no change)?"<<endl;
    cin>>amount;
    
    //Parsing the amount into sections for conversion to text
    tmpAmnt=amount; //Setting tmpAmnt working variable to value of amount
    n1000=(tmpAmnt-tmpAmnt%THOSNDS)/THOSNDS;//Determines how many 1000's
    tmpAmnt=(tmpAmnt-n1000*THOSNDS);       //Year without 1000's
    n100=(tmpAmnt-tmpAmnt%HUNDRDS)/HUNDRDS;//Determines how many 100's
    tmpAmnt=(tmpAmnt-n100*HUNDRDS);        //Year without 100's
    n10=(tmpAmnt-tmpAmnt%TENS)/TENS;      //Determines how many 10's
    n1=(tmpAmnt-n10*TENS);            //Year without 10's
    
    //Convert year to text
    //Calculate thousands output
    switch(n1000){
        case 1:amntText+="One Thousand ";break;
        case 0:break;
        default:cout<<"ERROR SWITCH n1000"<<endl;
    }
    
    //Calculate Hundreds
    switch(n100){
        case 9:amntText+="Nine Hundred ";break;
        case 8:amntText+="Eight Hundred ";break;
        case 7:amntText+="Seven Hundred ";break;
        case 6:amntText+="Six Hundred ";break;
        case 5:amntText+="Five Hundred ";break;
        case 4:amntText+="Four Hundred ";break;
        case 3:amntText+="Three Hundred ";break;
        case 2:amntText+="Two Hundred ";break;
        case 1:amntText+="One Hundred ";break;
        case 0:break;
        default:cout<<"ERROR SWITCH n100"<<endl;
    }
    
    //Calculate Tens with exception of less than 20
    switch(n10){
        case 9:amntText+="Ninety ";break;
        case 8:amntText+="Eighty ";break;
        case 7:amntText+="Seventy ";break;
        case 6:amntText+="Sixty ";break;
        case 5:amntText+="Fifty ";break;
        case 4:amntText+="Forty ";break;
        case 3:amntText+="Thirty ";break;
        case 2:amntText+="Twenty ";break;
        case 1:break;
        case 0:break;
        default:cout<<"ERROR SWITCH n10"<<endl;
    }
    
    //Calculate Ones if tens are 20 or greater
    if (n10!=1){
        switch(n1){
            case 9:amntText+="Nine ";break;
            case 8:amntText+="Eight ";break;
            case 7:amntText+="Seven ";break;
            case 6:amntText+="Six ";break;
            case 5:amntText+="Five ";break;
            case 4:amntText+="Four ";break;
            case 3:amntText+="Three ";break;
            case 2:amntText+="Two ";break;
            case 1:amntText+="One ";break;
            case 0:break;
            default:cout<<"ERROR SWITCH n1"<<endl;
        }
    }
    
    //Ones for tens value of less than 20 (teens)
    if (n10==1) {
        switch(n1){
            case 9:amntText+="Nineteen ";break;
            case 8:amntText+="Eighteen ";break;
            case 7:amntText+="Seventeen ";break;
            case 6:amntText+="Sixteen ";break;
            case 5:amntText+="Fifteen ";break;
            case 4:amntText+="Fourteen ";break;
            case 3:amntText+="Thirteen ";break;
            case 2:amntText+="Twelve ";break;
            case 1:amntText+="Eleven ";break;
            case 0:break;
            default:cout<<"ERROR SWITCH n1"<<endl;
        }
    }
    
    //format data and output check
    cout<<holder<<endl<<endl;
    cout<<"123 ABC Street"<<endl;
    cout<<"Beverly Hills, CA 90210                          Date: "
        <<setw(20)<<right<<date<<endl<<endl;
    cout<<"Pay to the order of: "<<setw(25)<<left<<payTo<<setw(21)<<right
        <<"Amount: $"<<setw(5)<<right<<amount<<".00"<<endl<<endl;
    cout<<"The Amount Of: "<<amntText<<"dollars and 00/100 "<<endl<<endl;
    cout<<"Bank of CSC5"<<endl;
    cout<<setw(75)<<right<<holder<<endl;
    cout<<"For: "<<setw(60)<<left<<payFor<<setw(10)<<right<<"Signature"<<endl;
    
    
    //Exit stage right!
    //But not here because this is a void function
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Question 4 - ISP Plan Rate Comparison **********************
//Description:   An ISP has 3 different subscription packages
//	a)  $16.75 per month, 5 hours access.  Additional hours
//	    are $0.75 up to 20 hours then $1 for all additional
//	    hours.
//	b)  $23.75 per month, 15 hours access.  Additional hours
//          are $0.55 up to 25 hours then $0.70 for each
//	    hour above this limit.
//	c)  $29.95 per month unlimited access
// Write a program that calculates a customers monthly bill.  
// Ask which package, and how many hours then display the monthly charge.  
// Also, output when customers should transition to another package and 
// what package that should be to save the most money.  Calculate the 
// money saved. 
// 
//       See Midterm question textfile for more details
//Inputs:
//     ISP Plan, hours used
//Outputs:
//     Savings on various plans, best plan for hours entered,
//     amounts on other plans, amount owed on plan selected
//******************************************************************************
void prob4 () {
    cout<<endl<<"Question 4 - ISP Rate-Plan Comparison"<<endl;
    //Declare Variables
    unsigned int hours;
    float totDueA=0, totDueB=0, totDueC=0, subTot=0;
    char package;
    
    //Input Values
    do{
    cout<<"Please enter your cell phone package, A, B, or C:"<<endl;
    cin>>package;
    } while ((package!='A')&&(package!='a')&&(package!='B')&&(package!='b')&&
            (package!='C')&&(package!='c'));
    cout<<"How many hours did you use?"<<endl;
    cin>>hours;
    
    //Process by mapping inputs to outputs
    if (hours<=5) totDueA=16.75;
        else if (hours>5&&hours<=20) totDueA=(16.75+(hours-5)*0.75);
        else totDueA=(16.75+((hours-20)*1)+(15*0.75));
    if (hours<=15) totDueB=23.75;
        else if (hours>15&&hours<=25) totDueB=(23.75+(hours-15)*0.55);
        else totDueB=(23.75+((hours-25)*0.70)+10*0.55);
    totDueC=29.95;
    
    //Output values
    if ((package == 'A')||(package=='a')) {
        cout<<"Package A Details"<<endl;
        cout<<"Your total due is: $"<<setprecision(2)<<fixed
                <<showpoint<<totDueA<<endl;
    }
    else if ((package == 'B')||(package == 'b')) {
        cout<<"Package B Details"<<endl;
        cout<<"Your total due is: $"<<setprecision(2)<<fixed
                <<showpoint<<totDueB<<endl;
    }
    else if ((package == 'C')||(package == 'c')) {
        cout<<"Package C Details"<<endl;
        cout<<"Your total due is: $"<<setprecision(2)<<fixed
                <<showpoint<<totDueC<<endl;
    }
    else cout<<"If this is displaying something went wrong somewhere"<<endl;
    
    if ((totDueA<totDueB)&&(totDueA<totDueC)) {
        cout<<"Plan A was the cheapest option for this number of hours."<<endl;
        cout<<"It would have saved $"<<setprecision(2)<<fixed
                <<showpoint<<totDueB-totDueA<<" over plan B and $"
                <<setprecision(2)<<fixed <<showpoint<<totDueC-totDueA
                <<" over plan C."<<endl;
    } else if ((totDueB<totDueA)&&(totDueB<totDueC)) {
        cout<<"Plan B was the cheapest option for this number of hours."<<endl;
        cout<<"It would have saved $"<<setprecision(2)<<fixed <<showpoint
                <<totDueA-totDueB<<" over plan A and $"<<setprecision(2)
                <<fixed <<showpoint<<totDueC-totDueB<<" over plan C."<<endl;  
    } else if ((totDueC<totDueA)&&(totDueC<totDueB)) {
        cout<<"Plan C was the cheapest option for this number of hours."<<endl;
        cout<<"It would have saved $"<<setprecision(2)<<fixed <<showpoint
                <<totDueA-totDueC<<" over plan A and $"<<setprecision(2)
                <<fixed <<showpoint<<totDueB-totDueC<<" over plan B."<<endl;  
    }
    cout<<"Your cost on each plan would have been:"<<endl;
    cout<<"Total for Plan A: $"<<setprecision(2)<<fixed <<showpoint
            <<totDueA<<endl;
    cout<<"Total for Plan B: $"<<setprecision(2)<<fixed <<showpoint
            <<totDueB<<endl;
    cout<<"Total for plan C: $"<<setprecision(2)<<fixed <<showpoint
            <<totDueC<<endl;
    //Exit stage right! - This is the 'return 0' call
    //But not here because this is a void function    
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Question 5 - Gross Pay Calculation *************************
//Description:   Develop an application that will determine the gross pay for 
// employees. The company pays "straight-time" for the first 20 hours worked, 
// double time for all hours worked in excess of 20 hours but less than 40 
// hours, and triple time for any hours worked over 40 hours. Inputs to the 
// program would be hours worked and rate of pay.  Output would be gross pay.
//       See Midterm question textfile for more details
//Inputs:
//     Hours worked, Pay rate
//Outputs:
//     Total pay
//     Pay for normal, double, and triple pay hours
//******************************************************************************
void prob5 () {
    cout<<endl<<"Question 5 - Gross Pay Calculation"<<endl;
    //Declare Variables
    float payRate=0;//Pay rate in $'s/hr
    float payChck=0;//Pay check in $'s
    float regPay=0, doubPay=0, tripPay=0;//Pay broken down by type
    int hrsWrkd=0;//Hours worked
    
    //Input values
    cout<<"This program calculates your Paycheck based on the hours"<<endl;
    cout<<"worked and your hourly pay rate."<<endl;
    cout<<"Input how many hours you worked: "<<endl;
    cin>>hrsWrkd;
    cout<<"Input your pay rate in dollars per hour: "<<endl;
    cin>>payRate;
    
    //Process by mapping inputs to outputs
    if (hrsWrkd<=20) {
        payChck=hrsWrkd*payRate;
        regPay=hrsWrkd*payRate;
    }
    else if ((hrsWrkd>20)&&(hrsWrkd<=40)) {
        payChck=((payRate*20)+((payRate*2)*(hrsWrkd-20)));
        doubPay=(payRate*2*(hrsWrkd-20));
        regPay=(payRate*20);
    }
    else if (hrsWrkd>40) {
        payChck=((payRate*20)+(payRate*2*20)+((payRate*3)*(hrsWrkd-40)));
        regPay=(payRate*20);
        doubPay=(payRate*2*20);
        tripPay=(payRate*3*(hrsWrkd-40));
    }
            
    //Output values
    cout<<"Your total paycheck is   $"<<setprecision(2)<<fixed<<showpoint
            <<payChck<<endl;
    cout<<"Your regular hours paid  $"<<setprecision(2)<<fixed<<showpoint
            <<regPay<<endl;
    if (doubPay>0.0) {
    cout<<"Your doubled hours paid  $"<<setprecision(2)<<fixed<<showpoint
            <<doubPay<<endl;
    } else cout<<"You did not work any double pay hours."<<endl;
    if (tripPay>0) {
    cout<<"Your tripled hours paid  $"<<setprecision(2)<<fixed<<showpoint
            <<tripPay<<endl;
    } else cout<<"You did not work any triple pay hours."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    //But not here because this is a void function
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Question 6 - Just Another Sequence *************************
//Description:       Just another sequence, 
// 
// sum = x - x^3/3! + x^5/5! - x^7/7! + ............
// 
// Input x and the number of terms=n, output the result.
// Note:  x^1 = x,   x^2 = x*x,  x^3 = x*x*x
//        3! = 1*2*3  5!=1*2*3*4*5
//       See Midterm question textfile for more details
//Inputs:
//     Number of terms, value of X
//Outputs:
//     Calculation of sequence
//******************************************************************************
void prob6 () {
    cout<<endl<<"Question 6 - Just Another Sequence"<<endl;
    //Declare Variables
    int nTerms=0, facBase=3; //iterations and base number for factorials 
    float valX=0.0, fResult=0.0, fDenom=1.0, answer=0.0;//inputs and calculations
    
    //Input values for number of terms and value of X
    cout<<"Calculate a factorial based on a chosen number of terms and"<<endl;
    cout<<"a chosen value for X"<<endl;
    cout<<"Input the number of Terms"<<endl;
    cin>>nTerms;
    cout<<"Input the value of X"<<endl;
    cin>>valX;
    answer = valX;
    
    //Process by mapping inputs to outputs
    //Set up iteration 
        for (int iter=1; iter<=nTerms; iter++) {
            //Get the value of the factorial denominator for the iteration
            for (int calFact=1; calFact<=facBase; calFact++) {
               fDenom *= calFact;
            }
            //assign cumulative value of equation to fResult for total 
            //iterations so far
            fResult = (pow(-1,iter))*(pow(valX,facBase)/fDenom);
            answer += fResult;
            fDenom=1.0;
            facBase=facBase+2;
        }
    
    //Output values
    cout<<"The answer is: "<<answer<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    //But not here because this is a void function
}