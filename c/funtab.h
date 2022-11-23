#include <math.h>
typedef double (*PtrFun)(double);
const int maxIdFun = 16;
class SymbolTable;
class FunctionEntry
{
public:
  PtrFun pFun;
  const char *strFun;
};

class FunctionTable
{
public:
  FunctionTable(SymbolTable &symTab, FunctionEntry funArr[]);
  int Size() const { return _size; }
  PtrFun GetFun(int id) { return _pFun[id]; }

private:
  PtrFun _pFun[maxIdFun];
  int _size;
};
