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
#include <iterator>
#include <map>
#include <memory>
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "HasPtr.h"

using namespace std;

int main()
{
  HasPtr s{"s"}, a{"a"}, c{"c"};
  std::vector<HasPtr> v{s, a, c};

  // swap(v[0], v[1]);
  std::sort(v.begin(), v.end());

  for_each(v.begin(), v.end(), [](HasPtr &x)
           { cout << *x.ps << endl; });

  // HasPtr hp1("aa");
  // HasPtr hp2("bb");
  // swap(hp1, hp2);

  // cout << *hp1.ps << endl;

  cout << "Finish" << endl;
  return 0;
}
