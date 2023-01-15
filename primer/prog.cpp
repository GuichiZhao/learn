#include <string>
#include <list>
#include <array>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include "Sales_data.h"
using namespace std;
typedef string::size_type sz;

class Value
{
public:
  Value(int i) : i(i)
  {
    cout << "Value created: " << i << endl;
  }
  void print() const
  {
    cout << "The value is: " << i << endl;
  }
  int i;
};

int main(int argc, char **argv)
{

}
