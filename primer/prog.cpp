#include <string>
#include <list>
#include <array>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#include <numeric>
#include "words.h"
#include "Sales_item.h"
using namespace std;

bool greatThenFive(string s)
{
  return s.size() >= 5;
}

int main(int argc, char **argv)
{
  string line("FIRST,MIDDLE,LAST");
  auto rcomma = find(line.crbegin(), line.crend(), ',');
  cout << string(rcomma.base(), line.cend()) << endl;


}
