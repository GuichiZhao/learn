#include <iostream>
#include "node.h"
using namespace std;

NumNode::NumNode(double d) : _num(d){};
double NumNode::Calc()
{
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
  return _left->Calc() + _right->Calc();
}

MultNode::MultNode(Node *left, Node *right) : BinNode(left, right){};
double MultNode::Calc()
{
  return _left->Calc() * _right->Calc();
};