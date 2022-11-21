#include "funtab.h"
#include "symboltable.h"
#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;



FunctionTable::FunctionTable(SymbolTable &symTab, FunctionEntry funArr[])
    : _size(0)
{
  for (int i = 0; i < maxIdFun; ++i)
  {
    int len = strlen(funArr[i].strFun);
    if (len == 0)
      break;
    _pFun[i] = funArr[i].pFun;
    int j = symTab.ForceAdd(funArr[i].strFun, len);
    assert(i == j);
    ++_size;
  }
}