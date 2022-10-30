#pragma once
#include <iostream>
using namespace std;
class Sequencer;
class Stack
{
  friend class Sequencer;

private:
  int _arr[100];
  int _top;

public:
  Stack();
  ~Stack();
  void Push(int i)
  {
    _arr[_top++] = i;
  }
  int Pop()
  {
    return _arr[--_top];
  }
};

Stack::Stack() : _top(0)
{
  cout << "Stack created" << endl;
}

Stack::~Stack()
{
  cout << "Stack destoried" << endl;
}

class Sequencer
{
private:
  Stack const &_stack;
  int _cur;

public:
  Sequencer(Stack const &stack);
  ~Sequencer();
  void Log()
  {
    cout << "The stack:" << endl;
    while (_stack._top - 1 >= _cur)
    {
      cout << _stack._arr[_cur++] << endl;
    }
    cout << "=====" << endl;
  }
};

Sequencer::Sequencer(Stack const &stack) : _stack(stack), _cur(0)
{
  cout << "Sequencer created" << endl;
}

Sequencer::~Sequencer()
{
  cout << "Sequencer destory" << endl;
}
