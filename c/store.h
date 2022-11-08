#include <assert.h>
#include <iostream>

using namespace std;
enum
{
  stNotInit,
  stInit
};
class SymbolTable; // forward declaration
class Store
{
public:
  Store(int size, SymbolTable &symTab);
  ~Store()
  {
    delete[] _cell;
    delete[] _status;
  }
  bool IsInit(int id) const
  {
    return (id < _size && _status[id] != stNotInit);
  }
  double Value(int id) const
  {
    assert(IsInit(id));
    return _cell[id];
  }
  void SetValue(int id, double val)
  {
    if (id < _size)
    {
      _cell[id] = val;
      _status[id] = stInit;
    }
  }

private:
  int _size;
  double *_cell;
  unsigned char *_status;
};