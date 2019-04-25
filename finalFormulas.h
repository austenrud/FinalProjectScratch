//
// Created by Austen on 24/04/2019.
//

#ifndef CASECOMBINE_FINALFORMULAS_H
#define CASECOMBINE_FINALFORMULAS_H

// formulas for Binary Search and Box Muller
#include <iostream>
#include<cmath>
#include <fstream>
#include <chrono>
#include <random>
#include<cstdlib>
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


 // Enter the CSV code here
 int variableChoice;

char listSeparator=',';
ofstream csvFile;
// The below works as a function***
int openingMonth;
double r;
void csvFixed(int tempMonth, int tempYear, int frequency, double openingBalance, double principal, double periodicInterestRate, double interest, double installment, double closingBalance)
{

    csvFile<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<endl;
    csvFile<<"input"<<listSeparator<<"PV"<<listSeparator<<PV<<endl;
    csvFile<<""<<listSeparator<<"frequency"<<listSeparator<<frequency<<endl;
    csvFile<<""<<listSeparator<<"# of periods"<<listSeparator<<n<<endl;
    csvFile<<""<<listSeparator<<"interest rate"<<listSeparator<<r<<endl;
    csvFile<<""<<listSeparator<<"start month"<<listSeparator<<openingMonth<<endl;
    csvFile<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<endl;


    csvFile<<"Period Number"<<listSeparator<<"Date"<<listSeparator<<"Opening Balance"<<listSeparator<<"Principal"<<listSeparator<<"r"<<listSeparator<<"Interest"<<listSeparator<<"Installments"<<listSeparator<<"Closing Balance"<<endl;


    for (int i = 1; i <= n; i++)
    {
        csvFile<<i<<listSeparator<<tempMonth<<"/"<<tempYear<<listSeparator<<openingBalance<<listSeparator<<principal<<listSeparator<<periodicInterestRate<<listSeparator<<interest<<listSeparator<<installment<<listSeparator<<closingBalance<<endl;
        // temporary month value to be recalculated after each iteration
        // at each iteration increase month value by frequency
        tempMonth += frequency;
        // if the end of year
        if (tempMonth > 12)
        {
            // reset month value to january
            tempMonth = (tempMonth-12);
            // increase year
            tempYear++;
        }
        openingBalance = closingBalance;
        interest = openingBalance*periodicInterestRate;
        principal=installment-interest;

        closingBalance = openingBalance-principal;
    }
}
double p, desiredMean, desiredVar, margin, floatRateMean, floatRateStd;
void csvFloat(int tempMonth, int tempYear, int frequency, double openingBalance, double principal, double periodicInterestRate, double interest, double installment, double closingBalance)
{
    csvFile<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<endl;
    csvFile<<"input"<<listSeparator<<"PV"<<listSeparator<<PV<<endl;
    csvFile<<""<<listSeparator<<"frequency"<<listSeparator<<frequency<<endl;
    csvFile<<""<<listSeparator<<"# of periods"<<listSeparator<<n<<endl;
    csvFile<<""<<listSeparator<<"margin"<<listSeparator<<margin<<endl;
    csvFile<<""<<listSeparator<<"floating rate mean"<<listSeparator<<floatRateMean<<endl;
    csvFile<<""<<listSeparator<<"floating rate st dev"<<listSeparator<<floatRateStd<<endl;
    csvFile<<""<<listSeparator<<"start month"<<listSeparator<<openingMonth<<endl;
    csvFile<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<endl;

    for (int i = 1; i <= n; i++)
    {
        csvFile<<i<<listSeparator<<tempMonth<<"/"<<tempYear<<listSeparator<<openingBalance<<listSeparator<<principal<<listSeparator<<periodicInterestRate<<listSeparator<<interest<<listSeparator<<installment<<listSeparator<<closingBalance<<endl;
        // temporary month value to be recalculated after each iteration
        // at each iteration increase month value by frequency
        tempMonth += frequency;
        // if the end of year
        if (tempMonth > 12)
        {
            // reset month value to january
            tempMonth = (tempMonth-12);
            // increase year
            tempYear++;
        }
        p=boxMuller(desiredMean,desiredVar);
        r=margin+p;
        periodicInterestRate=r/(12/frequency);
        openingBalance = closingBalance;
        interest = openingBalance*periodicInterestRate;
        principal=installment-interest;

        closingBalance = openingBalance-principal;
    }
}

#endif //CASECOMBINE_FINALFORMULAS_H




