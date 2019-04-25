//
// Created by Austen on 25/04/2019.
//

#ifndef UNTITLED4_FINALFORMULAS_H
#define UNTITLED4_FINALFORMULAS_H


// formulas for Binary Search

#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

double installment, PV, ftemp;
double f(double installment,double PV,double periodicInterestRate, double n){
    double temp;
    temp=periodicInterestRate * (1 + (1 / ((pow(1 + periodicInterestRate, n)) - 1)));
    temp-= installment / PV;
    return temp;

}

//Binary Search
double periodicInterestRate;
int n;

double binarySearch(double lBound, double uBound)
{
    do {
        periodicInterestRate = lBound + (uBound - lBound)/2;
        ftemp = f(installment,PV,periodicInterestRate,n);

        if (ftemp > 0)
        {
            uBound = periodicInterestRate;
        }
        else
        {
            lBound = periodicInterestRate;
        }

    } while (fabs(uBound-lBound) > 0.00000000000001); // need fabs here, not abs (abs only for integers)

    return periodicInterestRate;
}

// BoxMuller Code in BoxMullerCase2.h

double boxMuller(double pmean, double pvar){

    double x, y, s, z, p;

    do {
        x = ((double) rand() * 2 / RAND_MAX) - 1;
        y = ((double) rand() * 2 / RAND_MAX) - 1;
        s = x * x + y * y;
    } while (s > 1);

    z = x * sqrt(-2 * log(s) / s);
    p = sqrt(pvar) * z + pmean;

    return p;
}



#endif //UNTITLED4_FINALFORMULAS_H

