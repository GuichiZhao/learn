#include <iostream>
#include "node.h"
#include "store.h"
using namespace std;

NumNode::NumNode(double d) : _num(d){};
double NumNode::Calc()
{
  cout << "Nun " << _num << endl;
  return _num;
}
BinNode::BinNode(Node *left, Node *right) : _left(left), _right(right) {}

BinNode::~BinNode()
{
  delete _left;
  delete _right;
  cout << "Destory BinNode " << endl;
};

AddNode::AddNode(Node *left, Node *right) : BinNode(left, right) {}
double AddNode::Calc()
{
  cout << "Add" << endl;
  return _left->Calc() + _right->Calc();
}

MultNode::MultNode(Node *left, Node *right) : BinNode(left, right){};
double MultNode::Calc()
{
  cout << "Mul" << endl;
  return _left->Calc() * _right->Calc();
};

SubNode::SubNode(Node *left, Node *right) : BinNode(left, right){};
double SubNode::Calc()
{
  cout << "Sub" << endl;
  return _left->Calc() - _right->Calc();
}

DivideNode::DivideNode(Node *left, Node *right) : BinNode(left, right){};
double DivideNode::Calc()
{
  cout << "Div" << endl;
  return _left->Calc() / _right->Calc();
}

double VarNode::Calc()
{
  double x = 0.0;
  if (_store.IsInit(_id))
    x = _store.Value(_id);
  else
    cout << "Use of uninitialized variable\n";
  return x;
}
bool VarNode::IsLvalue() const
{
  return true;
}
void VarNode::Assign(double val)
{
  _store.SetValue(_id, val);
}

double AssignNode::Calc()
{
  double x = _right->Calc();
  _left->Assign(x);
  return x;
}