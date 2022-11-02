#pragma once
#include <iostream>
#include <cstring>
#include "list.h"
using namespace std;
const int idNotFound = -1;
class StringBuffer
{
public:
  StringBuffer() : _offset(0){};
  void Add(char const *str)
  {
    strcpy(_buf + _offset, str);
    _offset = _offset + strlen(str) + 1;
  }
  int GetOffset()
  {
    return _offset;
  }
  const char *GetString(int offset) const
  {
    return _buf + offset;
  }
  bool IsEqual(int offStr, char const *str) const
  {
    // char const * strStored = _buf + offStr;
    char const *strStored = _buf + offStr;
    // strcmp returns 0 when strings are equal
    return strcmp(str, strStored) == 0;
  }

private:
  char _buf[100];
  int _offset;
};
const int sizeHTable = 127;
class HTable
{
public:
  HTable() {}
  void Add(const char *str, int id)
  {
    int bucket = hash(str);
    list[bucket].Add(id);
  }
  List const &Find(const char *str) const
  {
    int bucket = hash(str);
    const List &l = list[bucket];

    return list[bucket];
  }

private:
  List list[sizeHTable];
  int hash(const char *str) const
  {

    unsigned h = 0;
    for (int i = 0; str[i] != 0; i++)
    {
      h = (h << 4) + str[i];
    }
    return h % sizeHTable;
  }
};
class StringTable
{
private:
  StringBuffer _buf;
  int _offset[100];
  int _id;
  HTable _table;

public:
  StringTable() : _id(0){

                  };
  ~StringTable(){};
  int ForceAdd(char const *str)
  {
    _offset[_id] = _buf.GetOffset();
    _buf.Add(str);
    _table.Add(str, _id);
    _id++;
    return _id;
  }
  const char *GetString(int id) const
  {
    int offset = _offset[id];
    return _buf.GetString(offset);
  }
  int Find(char const *str) const
  {
    const List &l = _table.Find(str);
    const Link *head = l.GetHead();
    while (head)
    {
      int i = head->GetId();
      if (_buf.IsEqual(_offset[i], str))
      {
        return i;
      }
      head = head->GetNext();
    }
    return idNotFound;
  }
};