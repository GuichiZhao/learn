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
    EToken t;
    int len;
    do
    {
      switch (t = _scanner.Accept())
      {
      case tPlus:
        cout << "Plus" << endl;
        break;
      case tMult:
        cout << "Mul" << endl;
        break;
      case tNumber:
        cout << "Num " << _scanner.GetNum() << endl;
        break;
      case tIdent:
        char symbol[maxSymLen];
        len = maxSymLen;
        _scanner.SymbolName(symbol, len);
        cout << "Symbol " << symbol << endl;
      default:
        break;
      }
    } while (t != tEnd);
    return stQuit;
  }

private:
  Scanner &_scanner;
  SymbolTable &_table;
};
