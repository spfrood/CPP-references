
/* 
 * File:   main.cpp
 * Author: Scott Parker
 * Created on March 11, 2017, 10:07 AM
 * Purpose: Problem 6
// This program shows the donates made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donates in order from lowest to highest
// and in the original order they were received.
 * 6. Case Study Modification #1
Modify Program 9-19 (the United Cause case study program) so it can be used with
any set of donates. The program should dynamically allocate the donates array
and ask the user to input its values.
 */

//System Libraries
#include <iostream>
using namespace std;

// Function prototypes
void arrSelectSort(int *, int);
void showArray(int *, int);
void showArrPtr(int *, int);

int main()
{
   int numDona=0;
   int *arrPtr=nullptr;

   // An array containing the donation amounts.
   cout<<"How many donates were received?"<<endl;
   cin>>numDona;
   while (cin.fail()||numDona<1){
       cin.clear();
       cin.ignore(256, '\n');
       cout<<"There must be 1 or more donates!"<<endl;
       cin>>numDona;
   }
   int *donates=new int [numDona];
   cout<<"Please enter the amount received for: "<<endl;
   for (int i=0;i<numDona;i++){
       cout<<"Donation "<<i<<": "<<endl;
       cin>>*(donates+i);
       while (cin.fail()|| *(donates+i)<1){
           cin.clear();
           cin.ignore(256, '\n');
           cout<<"Donations must be a positive integer!"<<endl;
           cin>>*(donates+i);
       }
   }

   // An array of pointers to int.
   arrPtr = new int [numDona];

   // Each element of arrPtr is a pointer to int. Make each
   // element point to an element in the donates array.
   for (int count = 0; count < numDona; count++)
      arrPtr[count] = donates[count];

   // Sort the elements of the array of pointers.
   arrSelectSort(arrPtr, numDona);

   // Display the donates using the array of pointers. This
   // will display them in sorted order.
   cout << "The donations, sorted in ascending order are: \n";
   showArrPtr(arrPtr, numDona);

   // Display the donates in their original order.
   cout << "The donations, in their original order are: \n";
   showArray(donates, numDona);
   
   delete [] donates;
   delete [] arrPtr;
   
   return 0;
}

//****************************************************************
// Definition of function arrSelectSort.                         *
// This function performs an ascending order selection sort on   *
// arr, which is an array of pointers. Each element of array     *
// points to an element of a second array. After the sort,       *
// arr will point to the elements of the second array in         *
// ascending order.                                              *
//****************************************************************

void arrSelectSort(int *arr, int size)
{
   int startScan, minIndex;
   int *minElem;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minElem = &arr[startScan];
      for(int index = startScan + 1; index < size; index++)
      {
         if (arr[index] < *minElem)
         {
            minElem = &arr[index];
            minIndex = index;
         }
      }
      arr[minIndex] = arr[startScan];
      arr[startScan] = *minElem;
   }
}

//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of arr. size is the    *
// number of elements.                                        *
//*************************************************************

void showArray(int *arr, int size)
{
   for (int count = 0; count < size; count++)
      cout << arr[count] << " ";
   cout << endl;
}

//**************************************************************
// Definition of function showArrPtr.                          *
// This function displays the contents of the array pointed to *
// by arr. size is the number of elements.                     *
//**************************************************************

void showArrPtr(int *arr, int size)
{
   for (int count = 0; count < size; count++)
      cout << arr[count] << " ";
   cout << endl;
}