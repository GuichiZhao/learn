#include <iostream>
using namespace std;
int i = 0;

class Bar
{
public:
  int value;
  Bar(/* args */)
  {
    this->value = i++;
    cout << "create Bar " << this->value << endl;
  };
  Bar(const Bar &bar)
  {
    this->value = bar.value;
    cout << "Copy bar " << this->value << endl;
  };
  ~Bar()
  {
    cout << "destroy Bar " << this->value << endl;
  };
};

Bar creare()
{
  Bar bar;
  return bar;
}
class Foo
{
public:
  int value;
  Bar bars[2];
  Foo(/* args */)
  {
    this->value = i++;
    cout << "create Foo " << this->value << endl;
  };
  ~Foo()
  {
    cout << "destroy Foo " << this->value << endl;
  };
};
