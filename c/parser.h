#pragma once
#include <iostream>
#include "scanner.h"
#include "symboltable.h"
using namespace std;
enum Status
{
  stOk,
  stQuit,
  stError
};

class Parser
{
public:
  Parser(Scanner &scanner, SymbolTable &table) : _scanner(scanner), _table(table)
  {
    cout << "Create parser" << endl;
  };
  ~Parser()
  {
    cout << "Destory parser" << endl;
  }
  Status Eval()
  {
    cout << "Parser eval\n";
    return stQuit;
  }

private:
  Scanner &_scanner;
  SymbolTable &_table;
};
