#include "store.h"
#include "symboltable.h"
#include <stdio.h>
#include <math.h>

using namespace std;

Store::Store(int size, SymbolTable &symTab) : _size(size)
{
  _cell = new double[size];
  _status = new unsigned char[size];
  for (int i = 0; i < size; ++i)
    _status[i] = stNotInit;
  // add predefined constants
  // Note: if more needed, do a more general job
  int id = symTab.ForceAdd("e", 1);
  SetValue(id, exp(1));
  id = symTab.ForceAdd("pi", 2);
  SetValue(id, 2.0 * acos(0.0));
}