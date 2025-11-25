#ifndef LOAN_H 
#define LOAN_H

#include <string>
using namespace std;

class Loan {
private:
    long double loan_amount;
    long double interest_rate;
    long double number_of_years;

    long double defaultLoan;
    long double defaultRate;
    long double defaultYears;

    string input; // temporary string input

    // Helper to safely convert string to long double
    bool strToLongDouble(const string& str, long double& value);

public:
    Loan(); // constructor reads config.txt

    void readLoanAmount();
    void readInterestRate();
    void readNumberOfYears();

    long double calculateTotalAmount() const;
    long double calculateMonthlyAmount(long double total) const;

    long double getLoanAmount() const { return loan_amount; }
    long double getInterestRate() const { return interest_rate; }
    long double getYears() const { return number_of_years; }
};

#endif