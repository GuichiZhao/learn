#pragma once
#include <cstring>
#include <cassert>
#include "htable.h"
#include "stringbuffer.h"
const int idNotFound = -1;
const int maxStrings = 100;
// String table maps strings to ints
// and ints to strings
class StringTable
{
public:
  StringTable();
  int ForceAdd(char const *str);
  int Find(char const *str) const;
  char const *GetString(int id) const;

private:
  HTable _htab;            // string -> short list of id’s
  int _offStr[maxStrings]; // id -> offset
  int _curId;
  StringBuffer _strBuf; // offset -> string
};
StringTable::StringTable() : _curId(0)
{
}

int StringTable::ForceAdd(char const *str)
{
  int len = strlen(str);
  // is there enough space?
  if (_curId == maxStrings || !_strBuf.WillFit(len))
  {
    return idNotFound;
  }
  // point to the place where the string will be stored
  _offStr[_curId] = _strBuf.GetOffset();
  _strBuf.Add(str);
  // add mapping to hash table
  _htab.Add(str, _curId);
  ++_curId;
  return _curId - 1;
}

int StringTable::Find(char const *str) const
{
  // Get a short list from hash table
  List const &list = _htab.Find(str);
  // Iterate over this list
  for (Link const *pLink = list.GetHead();
       pLink != 0;
       pLink = pLink->Next())
  {
    int id = pLink->Id();
    int offStr = _offStr[id];
    if (_strBuf.IsEqual(offStr, str))
    {
      return id;
    }
  }

  return idNotFound;
}

char const *StringTable::GetString(int id) const
{
  assert(id >= 0);
  assert(id < _curId);
  int offStr = _offStr[id];
  return _strBuf.GetString(offStr);
}