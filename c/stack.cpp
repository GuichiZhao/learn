
#include "stack.h"
#include <iostream>
#include <cassert>

using namespace std;

Stack::Stack()
    : _top(0), _capacity(initStack)
{
  _arr = new int[initStack]; // allocate memory
}
Stack::~Stack()
{
  delete[] _arr; // free memory
}
void Stack::Push(int i)
{
  assert(_top <= _capacity);
  if (_top == _capacity)
    Grow();
  _arr[_top] = i;
  ++_top;
}

void Stack::Grow()
{
  cout << "Doubling stack from " << _capacity << ".\n";
  // allocate new array
  int *arrNew = new int[2 * _capacity];
  // copy all entries
  for (int i = 0; i < _capacity; ++i)
    arrNew[i] = _arr[i];
  _capacity = 2 * _capacity;
  // free old memory
  delete[] _arr;
  // substitute new array for old array
  _arr = arrNew;
}

int Stack::Pop()
{
  // Do not Pop an empty stack
  assert(_top > 0);
  --_top;
  return _arr[_top];
}
int Stack::Top() const
{
  // Don't call Top on an empty stack
  assert(_top > 0);
  return _arr[_top - 1];
}
bool Stack::IsEmpty() const
{
  assert(_top >= 0);
  return _top == 0;
}