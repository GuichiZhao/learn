#pragma once
#include "list.h"
class HTable
{
public:
  explicit HTable(int size);
  ~HTable();
  int GetSize() const;

private:
  int _size;
  List *alist;
  int hash(const char *str) const;
};