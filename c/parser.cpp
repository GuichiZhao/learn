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
    cout << "OK" << endl;
    Execute();
  }

  else
  {
    cout << "Quit" << endl;
    _status = stQuit;
  }

  return _status;
}

void Parser::Execute()
{
  if (_pTree)
  {
    double result = _pTree->Calc();
    cout << "Result: " << result << endl;
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
  cout << "Expr" << endl;
  Node *pNode = Term();
  EToken token = _scanner.Token();
  if (token == tPlus)
  {
    _scanner.Accept();
    Node *pRight = Expr();
    pNode = new AddNode(pNode, pRight);
  }
  else if (token == tMinus)
  {
    _scanner.Accept();
    Node *pRight = Expr();
    pNode = new SubNode(pNode, pRight);
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
  else if (_scanner.Token() == tDivide)
  {
    _scanner.Accept();
    Node *pRight = Term();
    pNode = new DivideNode(pNode, pRight);
  }
  return pNode;
}

Node *Parser::Factor()
{
  Node *pNode;
  EToken token = _scanner.Token();
  if (token == tNumber)
  {
    cout << "receive number: " << _scanner.Number() << endl;
    pNode = new NumNode(_scanner.Number());
    _scanner.Accept();
  }
  return pNode;
}