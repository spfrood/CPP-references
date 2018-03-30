
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on May 10, 2017, 6:20 PM
 * Purpose: 9. FeetInches Modification
Modify the FeetInches class discussed in this chapter so it overloads the 
following operators:
<= 
>= 
!=
Demonstrate the class’s capabilities in a simple program.
 * 
 * **NOTE!!!  Code imported from Gaddis book pre-made code so names too long!
 * 
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries
#include "FeetInches.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    FeetInches first, second;  // Define two objects.

   // Get a distance for the first object.
   cout << "Enter a distance in feet and inches.\n";
   cin >> first;

   // Get a distance for the second object.
   cout << "Enter another distance in feet and inches.\n";
   cin >> second;

   // Display the values in the objects.
   cout << "The values you entered are:\n";
   cout << first << " and " << second << endl;
   
   for (int i=0;i<100;i++) {
       first.setFeet(0);
       first.setInches(rand()%25);
       second.setFeet(0);
       second.setInches(rand()%25);
       cout<<"Round "<<i+1<<"!"<<endl;
       cout<<first<<" ***** "<<second<<endl;
       if (first>=second) cout<<first<<" is >= "<<second<<endl;
       if (first<=second) cout<<first<<" is <= "<<second<<endl;
       if (first!=second) cout<<first<<" is != "<<second<<endl;
       if (first>second) cout<<first<<" is  > "<<second<<endl;
       if (first<second) cout<<first<<" is  < "<<second<<endl;
       if (first==second) cout<<first<<" is == "<<second<<endl;
       cout<<endl;
   }
   return 0;
}

