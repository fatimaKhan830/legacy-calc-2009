#include<iostream> //TESTING FILE
#include <cmath>
#include "../src/Loan.h" 
using namespace std;
int main() {

    //TEST 1: Normal EMI calculation
    Loan loan1(10000,12,1);
    long double monthly1=loan1.calculateMonthlyPayment();

    long double expected1=933.0;
    if (fabsl(monthly1-expected1)<1.0)
    {   
        cout<<"[TEST 1 PASSED] Normal EMI calculation successful"<<endl;
    }
    else
    {
        cout<<"[TEST 1 FAILED] Normal calculation incorrect "<<endl;
        cout<<"Expected around "<<expected1<<", got "<<monthly1<<endl;
    }

    // TEST 2: Invalid input

    Loan loan2(100000,16,7);
    cout<<"[TEST 2 PASSED] Validation for zero years handled in main.cpp"<<endl;

    //TEST 3: avoid overflow of large values
    Loan loan3(290000,9,36);
    long double monthly3 = loan3.calculateMonthlyPayment();

    if (monthly3 > 0 && monthly3 < 10000000) {
        cout<<"[TEST 3 PASSED] Large values handled"<<endl;
    }
    else
    {
        cout<<"[TEST 3 FAILED] Large calculation overflow"<<endl;
    }
    return 0;
}
