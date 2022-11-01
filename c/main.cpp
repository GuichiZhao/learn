#include <iostream>
#include "stack.h"
// #include "calculator.h"
// #include "input.h"
using namespace std;

int StrLen(char const pStr[])
{
  char const *p = pStr;
  while (*p++)
    ;
  return p - pStr - 1;
}

int main()
{

  Stack stack;
  for (int i = 0; i < 5; ++i)
  {
    cout << "Push " << i << endl;
    stack.Push(i);
  }
  Sequencer seq(stack);
  seq.Log();
  // Stack *aStack = new Stack[4];
  // delete [] aStack;
  // Stack s;
}