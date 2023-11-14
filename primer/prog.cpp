#include <iostream>
#include <fstream>
#include <list>
#include <string.h>
#include <vector>
#include <deque>
#include <array>
#include <sstream>

#include "Sales_Data.h"
#include "header.h"

int main()
{
  list<const char *> from{"aa", "bb"};
  vector<string> to;

  to.assign(from.begin(), from.end());

  for (auto s : to)
  {
    cout << s << endl;
  }
}