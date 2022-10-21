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
  Parser(Scanner &scanner, SymbolTable &symTab);
  ~Parser();
  Status Parse();
  Status Eval();

private:
  Scanner &
      _scanner;
  SymbolTable &
      _symTab;
};
Parser::Parser(Scanner &scanner, SymbolTable &symTab)
    : _scanner(scanner), _symTab(symTab)
{
  cout << "Parser created\n";
}
Parser::~Parser()
{
  cout << "Destroying parser\n";
}
Status Parser::Eval()
{
  cout << "Parser eval\n";
  return stQuit;
}

Status Parser::Parse()
{
  for (EToken token = _scanner.Token();
       token != tEnd;
       token = _scanner.Accept())
  {
    char strSymbol[maxSymLen + 1];
    int lenSym = maxSymLen;
    cout << "Token: " << token << endl;
    switch (token)
    {
    case tMult:
      cout << "Times\n";
      break;
    case tPlus:
      cout << "Plus\n";
      break;
    case tNumber:
      cout << "Number: " << _scanner.Number() << "\n";
      break;
    case tIdent:
      // char strSymbol[maxSymLen + 1];
      // int lenSym = maxSymLen;
      _scanner.SymbolName(strSymbol, lenSym);
      cout << "Ident: " << strSymbol << "\n";
      break;
    case tError:
      cout << "tError: " << tError << endl;
      cout << "Error here!\n";
      return stQuit;
    default:
      cout << "Error: bad token\n";
      return stQuit;
    }
  }
  return stOk;
}