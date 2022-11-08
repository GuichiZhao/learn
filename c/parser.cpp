#include "parser.h"

Parser::Parser(Scanner &scanner,
               Store &store,
               FunctionTable &funTab,
               SymbolTable &symTab)
    : _scanner(scanner),
      _pTree(0),
      _status(stOk),
      _funTab(funTab),
      _store(store),
      _symTab(symTab)
{
}
Parser::~Parser()
{
  delete _pTree;
}
Status Parser::Eval()
{
  Parse();
  if (_status == stOk)
    Execute();
  else
    _status = stQuit;
  return _status;
}

void Parser::Execute()
{
  if (_pTree)
  {
    // double result = _pTree->Calc();
    cout << " " << result << endl;
  }
}