#include <iostream>
#include "Sales_Data.h"
#include "header.h"

using namespace std;
class Account
{
public:
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double);

  std::string owner;
  double amount;
  static constexpr int interestRate = 10;
};

// constexpr int Account::interestRate;

int test(const int &i)
{
  cout << "Test " << i << endl;
  return 0;
}

int main()
{
  double r;
  r = Account::rate();
  cout << r << endl;
  Account ac1;
  cout << ac1.rate() << endl;
  test(Account::interestRate);
}