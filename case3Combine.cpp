
#include <iostream>
#include<cmath>
#include <fstream>
#include "finalFormulas.h"


using namespace std;


int main(int argc, char *argv[])
{
    int frequency;
    int openingMonth, openingYear;
    int lBound = 0, uBound = 1, lBoundMonth = 1, uBoundMonth = 12;

    cout << "Welcome to the Loan Payment Schedule Program!" << endl;
    cout << "Please enter the current year" << endl;
    cin >> openingYear;

    do
    {
        cout << "Current month in number within the range " <<lBoundMonth<<" to "<<uBoundMonth<< endl;
        cin >> openingMonth;
    } while (openingMonth<1 || openingMonth>12);

    do
    {
        cout << "Please enter Payment Frequency: \n 1: monthly \n 3: quarterly \n 6: semi-annually \n 12: annually \n";
        cin >> frequency;
    } while (!(frequency==1 || frequency==3 || frequency==6 || frequency==12));


  //  bool choice;
  //  cout << "Would you like to consider cases with variable interest rates (0) or fixed interest rates (1)?" << endl;
  //  // enter a do while statement here to get user to type 0 or 1 - if we do this, will always get true? do we need to prevent other numbers?
  //  cin >> choice;


    // Case Three Code

    int variableChoice;
    do {
        cout << "What variable would you like to determine? \n 1. Installment \n 2. Present value \n 3. Number of compounding periods \n 4. r" << endl;
        cin >> variableChoice;
    }while (!(variableChoice==1 || variableChoice==2 || variableChoice==3 || variableChoice==4));

    // create nested if/ifelse statements here
    // Payment, PresentValue, N R
    double r=0;
    // PV=0, n=0, installment; <- these are defined in the header

    int t1=0, t2=0, t3=0, t4=0;
    while (!(variableChoice == 1 || t1!=0))
    {
        do {
            cout << "Please provide an installment equal or bigger than " <<lBound<<endl;
            cin >> installment;
        }while (installment<0);
        t1++;
    }

    while (!(variableChoice == 2 || t2!=0))
    {
        do {
            cout << "Please provide a Present Value equal or bigger than " <<lBound<<endl;
            cin >> PV;
        }while (PV<=0); // Does this work if PV = 0 ?
        t2++;
    }

    while (!(variableChoice == 3 || t3!=0))
    {
        do {
            cout << "Number of compounding periods bigger than " <<lBound<<endl;
            cin >> n;
        } while(n<=0); // Does this work if n = 0 ?
        t3++;
    }

    while (!(variableChoice == 4 || t4!=0))
    {
        do {
            cout << "Enter an Interest rate (in decimal form) bigger than "<<lBound<< endl;
            cin >> r;
        } while (r<=0);
        t4++;
    }


    //double periodicInterestRate; defined in the header

    if (variableChoice ==1) // installment
    {
        periodicInterestRate = r/(12/frequency);
        double temp=(pow((1+periodicInterestRate), n))-1; // temp OK
        installment=(PV*periodicInterestRate)*(1+(1/temp));
    }
    else if (variableChoice==2) // present value
    {
        periodicInterestRate = r/(12/frequency);
        double temp=(pow((1+periodicInterestRate), n))-1; // temp OK
        PV=installment/(periodicInterestRate*(1+(1/temp)));
    }
    else if (variableChoice==3) // n
    {
        periodicInterestRate = r/(12/frequency);
        n=log((installment/PV)/((installment/PV)-periodicInterestRate))/(log(1+periodicInterestRate))+1; // added +1 here, file terminated at period 119
    }
    else // r
    {
        binarySearch(lBound, uBound);
        r=periodicInterestRate*(12 / frequency);
    }


    double openingBalance = PV;
    double interest = openingBalance*periodicInterestRate;
    double principal = installment-interest;
    double closingBalance = openingBalance-principal;
    // variables holding current month and year values (at each row)
    int tempMonth = openingMonth; // defined as double in some cases?
    int tempYear = openingYear;

    cout << "Testing output" << periodicInterestRate << endl;
    cout << "r rate " << r << endl;

    char listSeparator=',';
    ofstream csvFile;

    if (variableChoice==1)
    {
        csvFile.open("case3_1.csv");
    }
    else if (variableChoice==2)
    {
        csvFile.open("case3_2.csv");
    }
    else if (variableChoice==3)
    {
        csvFile.open("case3_3.csv");
    }
    else
    {
        csvFile.open("case3_4.csv");
    }


//for (int j=1;j<9;j++)
//{
    csvFile<<"Case 3: "<<listSeparator<<"Fixed principal interest payments and instalments given three variables"<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<listSeparator<<""<<endl;
//}

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

    csvFile.close();
    cout << "File saved as case3_x.csv!" << endl;





    return 0;
}
