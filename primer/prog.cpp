#include <iostream>
#include <fstream>
#include <list>
#include <string.h>
#include <vector>
#include <deque>
#include <array>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>

#include "Sales_Data.h"
#include "header.h"

using namespace std;

class T
{

  /* data */
public:
  string s;
  T(string s) : s(s)
  {
    cout << "constructor: " + s << endl;
  };

// private:
  T(const T &t) : s(t.s + " copied")
  {

    cout << "Copy constrcutor" << endl;
  }
};
void add(T t)
{
  cout << t.s << endl;
}

int main()
{
  T t = string("aa");
  // T tt = T(string("aa"));
  // add(string("aa"));
}