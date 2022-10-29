#pragma once
const int idNotFound = -1;
class SymbolTable
{
public:
  explicit SymbolTable(int size);
  ~SymbolTable();
  int ForceAdd(char const *str, int len);
  int Find(char const *str, int len) const;
  char const *GetString(int id) const;

private:
  HTable _htab;
  int *_offStr; // offsets of strings in buffer
  int _size;
  int _curId;
  char *_strBuf;
  int _bufSize;
  int _curStrOff;
};

SymbolTable::SymbolTable(int size)
    : _size(size), _curId(0), _curStrOff(0), _htab(size + 1)
{
  _offStr = new int[size];
  _bufSize = size * 10;
  _strBuf = new char[_bufSize];
}

SymbolTable::~SymbolTable()
{
  delete[] _offStr;
  delete[] _strBuf;
}
