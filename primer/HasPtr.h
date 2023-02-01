#include <string>
using namespace std;
class HasPtr
{
public:
  HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
  HasPtr(const HasPtr &h) : ps(new string(*(h.ps))), i(h.i) {}

private:
  string *ps;
  int i;
};