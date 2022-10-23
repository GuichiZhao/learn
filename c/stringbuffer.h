#pragma once
#include <cstring>
const int maxBufSize = 500;
class StringBuffer
{
public:
  StringBuffer() : _curOffset(0) {}
  bool WillFit(int len) const
  {
    return _curOffset + len + 1 < maxBufSize;
  }
  void Add(char const *str)
  {
    // strcpy (_buf + _curOffset, str);
    strcpy(&_buf[_curOffset], str);
    _curOffset += strlen(str) + 1;
  }
  int GetOffset() const
  {
    return _curOffset;
  }
  bool IsEqual(int offStr, char const *str) const
  {
    // char const * strStored = _buf + offStr;
    char const *strStored = &_buf[offStr];
    // strcmp returns 0 when strings are equal
    return strcmp(str, strStored) == 0;
  }
  char const *GetString(int offStr) const
  {
    // return _buf + offStr;
    return &_buf[offStr];
  }

private:
  char _buf[maxBufSize];
  int _curOffset;
};
