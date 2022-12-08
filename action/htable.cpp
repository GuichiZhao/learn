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

int HTable::hash(const char *str) const
{
  unsigned h = 0;
  for (int i = 0; str[i] != 0; i++)
  {
    h = (h << 4) + str[i];
  }
  return h % _size;
}

void HTable::Add(const char *str, int id)
{
  int bucket = hash(str);
  alist[bucket].Add(id);
}

List &HTable::Find(const char *str) const
{
  int bucket = hash(str);
  return alist[bucket];
}