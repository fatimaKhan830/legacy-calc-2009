#include <iostream>
#include "Loan.h"
using namespace std;

int main() {
    Loan loan;

    loan.readLoanAmount();
    loan.readInterestRate();
    loan.readNumberOfYears();

    long double total = loan.calculateTotalAmount();
    long double monthly = loan.calculateMonthlyAmount(total);

    cout << "Total amount to be paid: " << total << endl;
    cout << "Total interest: " 
         << total - (loan.getLoanAmount() * loan.getYears()) << endl;
    cout << "Monthly payment: " << monthly << endl;

    return 0;
}