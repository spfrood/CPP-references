/* 
 * Author: Dr. Mark E. Lehr
 * Created on March 20th, 2017, 1:30 PM
 * Purpose:  Specification for the Array structure
 */

#ifndef ARRAY_H
#define ARRAY_H

struct Array{
    int size;  //Size of the array
    int *data; //Data in the array
    int *index;//Index used in sorting the array
};

#endif /* ARRAY_H */