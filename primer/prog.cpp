#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "StrBlob.h"
#include "StrBlobPtr.h"
using namespace std;
using int3 = int[3];

// class Value
// {
// public:
//   int i;
//   Value(int i) : i(i)
//   {
//     cout << " : " << i << endl;
//     new string(1000, '1');

//   }
//   ~Value()
//   {
//     cout << " delete " << i << endl;
//   }
// };

int main()
{

  string a("1");
  string b("2");
  string *c = &a;
  a = b;
  cout << a << endl;
  cout << b << endl;
  cout << *c << endl;

  // *s = Value(2);
  // // cout << "xx" << endl;

  // Value a = Value(1);
  // a = Value(2);

  // std::string *a = new std::string(10000, 'x');
  // *a = "u";
}