#pragma once
#include <iostream>
#include "input.h"
#include "stack.h"
using namespace std;
class Calculator
{
private:
  Stack _stack;
  int Calculate(int n1, int n2, int token)
  {
    cout << n1 << ":" << n2 << ":" << token << endl;
    if (token == '+')
    {
      return n1 + n2;
    }
  }

public:
  Calculator();
  ~Calculator();
  bool Execute(Input const &input)
  {
    int token = input.Token();
    if (token == tokNumber)
    {
      _stack.Push(input.Number());
      return true;
    }
    else if (token == tokError)
    {
      return false;
    }
    else
    {
      int n1 = _stack.Pop();
      int n2 = _stack.Pop();

      _stack.Push(Calculate(n1, n2, token));
      return true;
    }
  }
  Stack const &GetStack() const
  {
    return _stack;
  }
};

Calculator::Calculator()
{
  cout << "Calculator created" << endl;
}

Calculator::~Calculator()
{
  cout << "Calculator destoried" << endl;
}
