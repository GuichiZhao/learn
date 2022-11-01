#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class StringTable
{
private:
  /* data */
public:
  StringTable(/* args */);
  ~StringTable();
  int ForceAdd(char const *str)
  {
    // str = "asd";
    str = new char('a');
    cout << "Inside: " << str << endl;
    return 1;
  }
};

StringTable::StringTable(/* args */)
{
}

StringTable::~StringTable()
{
}

class StringBuffer
{
public:
  StringBuffer() : _offset(0){};
  void Add(char const *str)
  {
    // strcpy()
  }

private:
  char _buf[100];
  int _offset;
};
