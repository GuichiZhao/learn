#include <iostream>
using namespace std;
class Node;
class Scanner;
class Store;
class FunctionTable;
class SymbolTable;

enum Status
{
  stOk,
  stQuit,
  stError
};

class Parser
{
public:
  Parser(Scanner &scanner, Store &store, SymbolTable &symTab);
  ~Parser();
  Status Eval();

private:
  void Parse();
  Node *Expr();
  Node *Term();
  Node *Factor();
  void Execute();
  Scanner &_scanner;
  Node *_pTree;
  Status _status;
  Store &_store;
  // FunctionTable &_funTab;
  SymbolTable &_symTab;
};