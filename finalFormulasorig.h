//
// Created by Austen on 25/04/2019.
//

#ifndef UNTITLED4_FINALFORMULAS_H
#define UNTITLED4_FINALFORMULAS_H


// formulas for Binary Search

#include <iostream>
#include <cmath>
#include <fstream>

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

// Enter the CSV code here





#endif //UNTITLED4_FINALFORMULAS_H
