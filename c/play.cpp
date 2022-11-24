#include <iostream>
#include <math.h>
using namespace std;

enum T
{
  one,
  two,
  three
};

class Scanner
{
public:
  Scanner()
  {
    addValue();
    cout << "create v: " << _v << endl;
  }
  T getV(){
    return _v;
  }
  void addValue()
  {
    _v = two;
  }
  ~Scanner()
  {
    cout << "destory v: " << _v << endl;
  }
  T _v;
};

class Parser
{
public:
  Parser(Scanner v) : _v(v){};
  void log()
  {
    cout << "Value: " << _v.getV() << endl;
  };
  Scanner &_v;
};
int main()
{
  Scanner v1;
  Parser c(v1);
  c.log();
}