#include "parser.h"
#include "scanner.h"
#include "symboltable.h"
#include "node.h"
#include <iostream>
using namespace std;
const int maxSymLen = 10;
Parser::Parser(Scanner scanner,
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
  cout << "Parse constructor " << _scanner.Token() << endl;
}
Parser::~Parser()
{
  delete _pTree;
}
Status Parser::Eval()
{
  cout << "Parse Eval token " << _scanner.Token() << endl;
  cout << "Parse Eval str " << _scanner._buf << endl;
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
  cout << "Execute" << endl;
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
  else if (token == tAssign)
  {
    _scanner.Accept();
    Node *pRight = Expr();
    if (pNode->IsLvalue())
    {
      pNode = new AssignNode(pNode, pRight);
    }
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
  cout << "EToken token " << token << endl;

  if (token == tNumber)
  {
    cout << "receive number: " << _scanner.Number() << endl;
    pNode = new NumNode(_scanner.Number());
    _scanner.Accept();
  }
  else if (token == tLParen)
  {
    cout << " token (" << endl;
    _scanner.Accept();
    pNode = Expr();
    if (_scanner.Token() != tRParen)
    {
      _status = stError;
    }
    _scanner.Accept();
  }
  else if (token == tIdent)
  {
    char strSymbol[maxSymLen + 1];
    int lenSym = maxSymLen;
    // copy the symbol into strSymbol
    _scanner.SymbolName(strSymbol, lenSym);
    int id = _symTab.Find(strSymbol, lenSym);
    _scanner.Accept();
    if (_scanner.Token() == tLParen) // function call
    {
      _scanner.Accept(); // accept '('
      pNode = Expr();
      if (_scanner.Token() == tRParen)
        _scanner.Accept(); // accept ')'
      else
        _status = stError;
      if (id != idNotFound && id < _funTab.Size())
      {
        pNode = new FunNode(_funTab.GetFun(id), pNode);
      }
      else
      {
        cout << "Unknown function \"";
        cout << strSymbol << "\"\n";
      }
    }
    else
    {
      if (id == idNotFound)
      {
        id = _symTab.ForceAdd(strSymbol, lenSym);
      }
      pNode = new VarNode(id, _store);
    }
  }
  return pNode;
}