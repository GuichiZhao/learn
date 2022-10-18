#include "sequencer.h"
#include "stack.h"
#include <iostream>

using namespace std;
Sequencer::Sequencer(Stack & stack) : _stack(stack), cur(0) {}
bool Sequencer::atEnd() const
{
  return _stack.top == cur;
}
void Sequencer::advance()
{
  cur++;
}

int Sequencer::getNun()
{
  return _stack._arr[cur];
}

void Sequencer::log()
{
  cur = 0;
  cout << "log" << endl;
  while (!atEnd())
  {
    cout << _stack._arr[cur] << endl;
    advance();
  }
}