#include <iostream>
#include "list.h"
// #include "stack.h"
// #include "calculator.h"
// #include "input.h"
using namespace std;

int main()
{
  List *l = new List();
  l->Add(1);
  l->Add(2);
  delete l;
}