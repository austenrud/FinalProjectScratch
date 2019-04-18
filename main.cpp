#include <iostream>
#include<cmath>

// avoid comments when possible, good code is self explanatory in that you can read it as a sentence
// Remember to name variables only when you need them! Not all at the beginning

using namespace std;

void PresentValue()
{
    double r, PMT, temp, PV, n;
    cout << "Please provide " << "PMT: ";
    cin >> PMT;
    cout << "Interest rate in percentage: " << endl;
    cin >> r;
    cout << "Number of compounding periods: " << endl;
    cin >> n;
    temp=(pow((1+r), n))-1; // temp OK
    PV= PMT/(r+(r/temp));
    cout << PV;
}

void Payment()
{
    double r, PMT, temp, PV, n;
    cout << "Please provide " << "PV: ";
    cin >> PV;
    cout << "Interest rate in percentage: " << endl;
    cin >> r;
    cout << "Number of compounding periods: " << endl;
    cin >> n;
    temp=(pow((1+r), n))-1; // temp OK
    PMT= PV*(r+(r/temp));
    cout << PMT;
}






// Cases:

// Case 1 : Fixed principal payments:
// Fixed interest rate


// margin + parameterized nomrlally distributed floating interest rate

// We want to define formauls for PV, PMT, r, and n



int main()
{
    Payment();
    return 0;
}