#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>
#include "StrBlob.h"
using namespace std;
using namespace std::placeholders;
using int3 = int[3];

class Value
{
public:
  int v;
  Value() : v(100)
  {
    cout << "create default " << v << endl;
  };
  Value(int u) : v(u)
  {
    cout << "create  " << u << endl;
  };
  Value(const Value &v) : v(v.v)
  {
    // Value(v.)
    cout << "copy " << v.v << endl;
  };
  ~Value()
  {
    cout << "Destory " << v << endl;
  }
  void print()
  {
    cout << "v: " << v << endl;
  };
};

class HasPtr
{
public:
  HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
  HasPtr(const HasPtr &h) : ps(new string(*(h.ps))), i(h.i) {}

private:
  string *ps;
  int i;
};
int main()
{
  StrBlob blob = {"xx", "bb"};
  shared_ptr<string> ptr = make_shared<string>("hello");
  cout << ptr << endl;
  cout << &ptr << endl;
}