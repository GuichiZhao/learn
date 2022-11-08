#include "parser.h"
#include "scanner.h"
#include "node.h"

Parser::Parser(Scanner &scanner,
               Store &store,
               //  FunctionTable &funTab,
               SymbolTable &symTab)
    : _scanner(scanner),
      _pTree(0),
      _status(stOk),
      // _funTab(funTab),
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
  {
    Execute();
  }

  else
  {
    _status = stQuit;
  }

  return _status;
}

void Parser::Execute()
{
  if (_pTree)
  {
    double result = _pTree->Calc();
  }
  else
  {
    cout << "Where is _pTree?" << endl;
  }
}
void Parser::Parse()
{
  _pTree = Expr();
}

Node *Parser::Expr()
{
  Node *pNode = Term();
  EToken token = _scanner.Token();
  if (token == tPlus)
  {
    _scanner.Accept();
    Node *pRight = Expr();
    pNode = new AddNode(pNode, pRight);
  }
  return pNode;
}

Node *Parser::Term()
{
  Node *pNode = Factor();
  if (_scanner.Token() == tMult)
  {
    _scanner.Accept();
    Node *pRight = Term();
    pNode = new MultNode(pNode, pRight);
  }
  return pNode;
}

Node *Parser::Factor()
{
  Node *pNode;
  EToken token = _scanner.Token();
  if (token == tNumber)
  {
    pNode = new NumNode(_scanner.Number());
    _scanner.Accept();
  }
  return pNode;
}