/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   primes.h
 * Author: scott_r_parker
 *
 * Created on April 23, 2017, 10:22 PM
 */

#ifndef PRIMES_H
#define PRIMES_H

struct Prime{
	unsigned short prime;
	unsigned short power;
};

struct Primes{
	Prime *prime;
	unsigned short nPrimes;
};

#endif /* PRIMES_H */

