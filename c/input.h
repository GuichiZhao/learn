#pragma once
#include <iostream>
#include <cctype>
using namespace std;

const int tokNumber = 1;
const int tokError = 2;
class Input
{
private:
  char _buf[100];
  int _token;
  /* data */
public:
  Input();
  ~Input();
  int Token() const
  {
    return _token;
  }
  int Number() const
  {
    return atoi(_buf);
  }
};

Input ::Input(/* args */)
{
  cout << "Input here >" << endl;
  cin >> _buf;
  int c = _buf[0];
  if (isdigit(c))
  {
    _token = tokNumber;
  }
  else if (c == '+' || c == '*' || c == '/')
  {
    _token = c;
  }
  else if (c == '-')
  {
    if (isdigit(_buf[1])) // peek at next char
      _token = tokNumber;
    else
      _token = c;
  }
  else
  {
    _token = tokError;
  }
}
Input::~Input()
{
  cout << "Input destoried" << endl;
}
