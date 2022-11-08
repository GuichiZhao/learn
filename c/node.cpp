#include <iostream>
#include "node.h"
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