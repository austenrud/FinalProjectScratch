#include <iostream>
#include<cmath>

using namespace std;

// Definition of Schedule class
class Schedule { 
    // class parameters to be calculated
    int periodNumber;
    double openingBalance;
    double principal;
    float interestRate;
    double installment;
    double closingBalance;
};

// present value is substructed from the opening value for each period
double PMT(double r, double PMT, double temp, double PV, double n) {
    temp=(pow((1+r), n))-1; // temp OK
    PMT= PV*(r+(r/temp));
    return PMT;
}

int main(int argc, char *argv[]) {
    double r, PMT, temp, PV, n;
    int frequency;
    int openingMonth, openingYear;
    cout << "Please provide " << "PV: ";
    cin >> PV;
    cout << "Interest rate in percentage: " << endl;
    cin >> r;
    cout << "Number of compounding periods: " << endl;
    cin >> n;
    cout << "Current month" << endl;
    cin >> openingMonth;
    cout << "Current year" << endl;
    cin >> openingYear;
    cout << "Frequency (1: monthly, 3: quarterly, 6: semi-annually, 12: annually)" << endl;
    cin >> frequency;
    double openingBalance = PV;
    double principal = PV/n;
    double periodicInterestRate = r/(12/frequency);
    double interest = openingBalance*periodicInterestRate;
    double installment = principal+interest;
    double closingBalance = openingBalance-principal;
    // variables holding current month and year values (at each row)
    int tempMonth = openingMonth;
    int tempYear = openingYear;

    cout<<"PN"<<"\t"<<"Date"<<"\t"<<"OB"<<"\t"<<"Princ"<<"\t"<<"r"<<"\t"<<"inter"<<"\t"<<"install"<<"\t"<<"CB"<<endl;
    for (int i = 1; i <= n; i++) {
        cout<<i<<"\t"<<tempMonth<<"/"<<tempYear<<"\t"<<openingBalance<<"\t"<<principal<<"\t"<<periodicInterestRate<<"\t"<<interest<<"\t"<<installment<<"\t"<<closingBalance<<endl;
        // temporary month value to be recalculated after each iteration
        // at each iteration increase month value by frequency
        tempMonth += frequency;
        // if the end of year
        if (tempMonth > 12) {
            // reset month value to january
            tempMonth = 1;
            // increase year
            tempYear++; 
        }       
        openingBalance = closingBalance;
        interest = openingBalance*periodicInterestRate;
        installment = principal+interest;
        closingBalance = openingBalance-principal;
        
    }
    
    return 0;
}
