#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

class Value
{
public:
  Value()
  {
    cout << " Default constructor\n";
    _numString = new char[1];
    _numString[0] = '\0';
  }
  Value(int i)
  {
    cout << "Construction /conversion from int " << i << endl;
    stringstream buffer;
    buffer << i << ends; // terminate string
    Init(buffer.str().c_str());
    Display();
  }
  Value(Value const &v)
  {
    cout << " Copy constructor (" << v._numString << " )\n";
    Init(v._numString);
    Display();
  }
  Value &operator=(Value const &v)
  {
    cout << " operator = ( " << v._numString << " )\n";
    if (_numString != v._numString)
    {
      delete _numString;
      Init(v._numString);
    }
    Display();
    return *this;
  }
  friend Value operator+(Value const &v1, Value const &v2);

private:
  void Init(char const *buf)
  {
    int len = strlen(buf);
    _numString = new char[len + 1];
    strcpy(_numString, buf);
  }
  void Display()
  {
    cout << "\t" << _numString << endl;
  }
  char *_numString;
};
int main()
{
}