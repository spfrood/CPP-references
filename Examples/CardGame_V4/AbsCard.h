/* 
  File:   main.cpp
  Author: Dr. Mark E. Lehr
  Created on May 5th, 2017, 1:15 PM
  Purpose:  AbsCard Class Specification
 */

#ifndef ABSCARD_H
#define	ABSCARD_H

class AbsCard{
    public:
        virtual char getSuit()=0;
        virtual char getFVal()=0;
        virtual char getCNum()=0;
};

#endif	/* ABSCARD_H */