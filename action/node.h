#include <iostream>
#include <cassert>
#include "funtab.h"
using namespace std;

class Store;

class Node
{
public:
  Node(){};
  double virtual Calc() = 0;
  virtual ~Node(){};
  bool virtual IsLvalue() const
  {
    return 0;
  }
  virtual void Assign(double value) {}
};

class NumNode : public Node
{
public:
  NumNode(double d);
  double Calc();

private:
  double _num;
};

class BinNode : public Node
{
public:
  BinNode(Node *left, Node *right);
  ~BinNode();

protected:
  Node *_left;
  Node *_right;
};

class AddNode : public BinNode
{
public:
  AddNode(Node *left, Node *right);
  ~AddNode(){};
  double Calc();
};

class MultNode : public BinNode
{
public:
  MultNode(Node *left, Node *right);
  ~MultNode(){};
  double Calc();
};

class SubNode : public BinNode
{
public:
  SubNode(Node *left, Node *right);
  ~SubNode(){};
  double Calc();
};

class DivideNode : public BinNode
{
public:
  DivideNode(Node *left, Node *right);
  ~DivideNode(){};
  double Calc();
};

class VarNode : public Node
{
public:
  VarNode(int id, Store &store) : _id(id), _store(store)
  {
  }
  ~VarNode(){};
  double Calc();
  bool IsLvalue() const;
  void Assign(double val);

private:
  int _id;
  Store &_store;
};

class AssignNode : public BinNode
{
public:
  AssignNode(Node *pLeft, Node *pRight)
      : BinNode(pLeft, pRight)
  {
    assert(_left->IsLvalue());
  }
  double Calc();
};

class FunNode : public Node
{
public:
  FunNode(PtrFun pFun, Node *pNode)
      : _pNode(pNode), _pFun(pFun)
  {
  }
  ~FunNode() { delete _pNode; }
  double Calc();

private:
  Node *const _pNode;
  PtrFun _pFun;
};


// FunctionEntry funArr[maxIdFun] =
//     {
//         log,
//         "log",
//         log10, "log10",
//         exp,
//         "exp",
//         sqrt,
//         "sqrt",
//         sin,
//         "sin",
//         cos,
//         "cos",
//         tan,
//         "tan",
//         sinh,
//         "sinh",
//         cosh,
//         "cosh",
//         tanh,
//         "tanh",
//         asin,
//         "asin",
//         acos,
//         "acos",
//         atan,
//         "atan",
//         0,
//         ""};
