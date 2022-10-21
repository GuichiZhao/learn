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