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

using namespace std;

int i = 0;
class Foo
{
public:
  int value;
  Foo(/* args */)
  {
    this->value = i++;
    cout << "create " << this->value << endl;
  };
  ~Foo()
  {
    cout << "destroy " << this->value << endl;
  };
};

int main()
{
  StrBlobPtr begin, end;
  // {
  StrBlob sb;
  begin = sb.begin(), end = sb.end();
  ifstream input("record.txt");
  string line;
  while (getline(input, line))
  {
    sb.push_back(line);
  }

  // while (begin != end)
  // {
  //   /* code */
  // }

  // }

  cout << begin.incr().deref() << endl;

  cout << "finish" << endl;
  return 0;
}