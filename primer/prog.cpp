#include <iostream>
#include "fn.h"
#include "help.h"
using namespace std;

constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
int main()
{
  cout << new_sz() << " and " << value() << endl;
}