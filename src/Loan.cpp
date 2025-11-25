#include "Loan.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Constructor: read defaults from config.txt
Loan::Loan() {
    loan_amount = interest_rate = number_of_years = 0;
    defaultLoan = defaultRate = defaultYears = 0;

    ifstream config("config.txt");
    if (config.is_open()) {
        config >> defaultLoan >> defaultRate >> defaultYears;
        config.close();
    } else {
        cout << "WARNING: config.txt not found. Defaults are 0." << endl;
    }
}

// Safe conversion string -> long double
bool Loan::strToLongDouble(const string& str, long double& value) {
    if (str.empty()) return false;
    try {
        size_t idx;
        value = stold(str, &idx);
        if (idx != str.length()) return false;
        return true;
    } catch (...) {
        return false;
    }
}

// Read loan amount from user
void Loan::readLoanAmount() {
    while (true) {
        cout << "Enter loan amount: ";
        getline(cin, input);

        if (input.empty() && defaultLoan > 0) {
            loan_amount = defaultLoan;
            cout << "Using default loan amount: " << loan_amount << endl;
            break;
        } else if (strToLongDouble(input, loan_amount) && loan_amount > 0) {
            break;
        } else {
            cout << "Invalid input. Please enter a positive number." << endl;
        }
    }
}

// Read interest rate from user
void Loan::readInterestRate() {
    while (true) {
        cout << "Enter interest rate: ";
        getline(cin, input);

        if (input.empty() && defaultRate > 0) {
            interest_rate = defaultRate;
            cout << "Using default interest rate: " << interest_rate << endl;
            break;
        } else if (strToLongDouble(input, interest_rate) && interest_rate > 0) {
            break;
        } else {
            cout << "Invalid input. Please enter a positive number." << endl;
        }
    }
}

// Read number of years from user
void Loan::readNumberOfYears() {
    while (true) {
        cout << "Enter number of years: ";
        getline(cin, input);

        if (input.empty() && defaultYears > 0) {
            number_of_years = defaultYears;
            cout << "Using default number of years: " << number_of_years << endl;
            break;
        } else if (strToLongDouble(input, number_of_years) && number_of_years > 0) {
            break;
        } else {
            cout << "Invalid input. Please enter a positive number." << endl;
        }
    }
}

// Calculate total amount to pay
long double Loan::calculateTotalAmount() const {
    return (loan_amount * number_of_years) + (loan_amount * number_of_years * (interest_rate / 100.0));
}

// Calculate monthly payment
long double Loan::calculateMonthlyAmount(long double total) const {
    return total / (number_of_years * 12);
}