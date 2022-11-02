#pragma once
#include <iostream>
using namespace std;

class SymbolTable
{
public:
  SymbolTable()
  {
    cout << "create SymbolTable" << endl;
  }
  ~SymbolTable()
  {
    cout << "destory SymbolTable" << endl;
  }
};