#pragma once
#include "list.h"
class HTable
{
public:
  explicit HTable(int size) : _size(size)
  {
    alist = new List[size];
  }
  ~HTable()
  {
    delete[] alist;
  };
  int GetSize() const
  {
    return _size;
  };

private:
  int _size;
  List *alist;
};