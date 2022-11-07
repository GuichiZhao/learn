
#include <iostream>
using namespace std;
class Sequencer;

class Stack
{
  friend class Sequencer;

private:
  int *_arr;
  int _top;
  int _capacity;
  void Grow()
  {
    cout << "Grow the array" << endl;
    _capacity = _capacity * 2;
    int *newArr = new int[_capacity];
    for (int i = 0; i < _top; i++)
    {
      newArr[i] = _arr[i];
    }
    delete[] _arr;
    _arr = newArr;
  }

public:
  Stack();
  ~Stack();
  void Push(int i)
  {

    if (_top == _capacity)
    {
      Grow();
    }
    _arr[_top++] = i;
  }
  int Pop()
  {
    return _arr[--_top];
  }
};

Stack::Stack() : _top(0), _capacity(1)
{
  cout << "Stack created" << endl;
  _arr = new int(_capacity);
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
