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

void f(HasPtr h){};

int main()
{

  StrBlob sb{"aa", "bb", "cc"};
  StrBlob sb1(sb);
  sb1 = sb;
  sb1.push_back("x11x");
  auto itr = sb.begin();
  for (StrBlob::size_type i = 0; i < sb.size(); i++)
  {
    cout << itr.deref() << endl;
    itr.incr();
  }

  cout << "Finish" << endl;
  return 0;
}