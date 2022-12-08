#include "htable.h"
const int idNotFound = -1;

class SymbolTable
{
public:
  SymbolTable(int size);
  SymbolTable();
  ~SymbolTable();
  int ForceAdd(char const *str, int len);
  int ForceAdd(const char *str);
  int Find(char const *str, int len = 0) const;
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