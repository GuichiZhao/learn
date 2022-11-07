#include "string.h"
#include "symboltable.h"

using namespace std;

SymbolTable ::SymbolTable() : SymbolTable(127){};
SymbolTable::SymbolTable(int size) : _size(size), _curId(0), _curStrOff(0), _htab(size + 1)
{
  _offStr = new int[size];
  _strBuf = new char[size * 10];
}

SymbolTable::~SymbolTable()
{
  delete[] _offStr;
  delete[] _strBuf;
}
int SymbolTable::ForceAdd(const char *str)
{
  return ForceAdd(str, strlen(str));
}
int SymbolTable::ForceAdd(const char *str, int len)
{
  _offStr[_curId] = _curStrOff;
  strcpy(_strBuf + _curStrOff, str);
  _curStrOff = _curStrOff + len + 1;
  _htab.Add(str, _curId);
  _curId++;
  return _curId - 1;
}

int SymbolTable::Find(char const *str, int len) const
{
  const Link *l = _htab.Find(str).GetHead();
  while (l)
  {
    int id = l->GetId();
    if (strcmp(_strBuf + _offStr[id], str) == 0)
    {
      return id;
    };
    l = l->GetNext();
  }

  return idNotFound;
}

char const *SymbolTable::GetString(int id) const
{
  cout << "_offStr[id] " << _offStr[id] << endl;
  return _strBuf + _offStr[id];
}