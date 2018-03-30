/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   statsresult.h
 * Author: scott_r_parker
 *
 * Created on April 22, 2017, 6:17 PM
 */

#ifndef STATSRESULT_H
#define STATSRESULT_H

struct StatsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

#endif /* STATSRESULT_H */

