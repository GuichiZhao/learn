#include <string>
using namespace std;
class HasPtr
{
public:
  HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
  HasPtr(const HasPtr &h) : ps(new string(*(h.ps))), i(h.i) {}
  HasPtr &operator=(const HasPtr &rhs)
  {
    *ps = *(rhs.ps);
    i = rhs.i;
    return *this;
  }

private:
  string *ps;
  int i;
};