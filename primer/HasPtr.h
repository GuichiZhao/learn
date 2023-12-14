#include <string>
using namespace std;
class HasPtr
{
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0)
  {
    cout << "HasPtr(const std::string &s = std::string())" << endl;
  }
  HasPtr(const HasPtr &s)
  {
    cout << "HasPtr(const HasPtr &s)" << endl;
    this->i = s.i;
    this->ps = new string(*s.ps);
  }
  HasPtr operator=(HasPtr const &s)
  {
    cout << "operator=(HasPtr const &s)" << endl;
    if (this != &s)
    {
      delete this->ps;
      this->ps = new string(*s.ps);
      this->i = s.i;
    }
    return *this;
  }
  ~HasPtr()
  {
    cout << "~HasPtr()" << endl;
    delete this->ps;
  }
  // ~HasPtr() = delete;
  std::string *ps;
  int i;
};