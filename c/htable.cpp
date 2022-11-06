#pragma once
#include "htable.h"

HTable ::HTable(int size) : _size(size)
{
  alist = new List[size];
}
HTable::~HTable()
{
  delete[] alist;
}

int HTable::GetSize() const
{
  return _size;
}