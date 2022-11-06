#pragma once
#include "list.h"
class HTable
{
public:
  explicit HTable(int size);
  ~HTable();
  int GetSize() const;
  void Add(const char *str,int id);
  List &Find(const char *str) const;

private:
  int _size;
  List *alist;
  int hash(const char *str) const;
};