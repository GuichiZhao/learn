#include <string>
#include <vector>
#include <iostream>
#include "Sales_data.h"
using namespace std;
typedef string::size_type sz;

int main(int argc, char **argv)
{
  Sales_data s;
  s = string("xxz11z");
  // s.combine(string("aa"));
  auto i = s.isbn();
  cout << i << endl;
}
