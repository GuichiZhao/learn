#pragma once
#include <iostream>
using namespace std;
class Node
{
public:
  double virtual Calc() = 0;
  Node()
  {
    cout << "Create Node" << endl;
  }
  virtual ~Node()
  {
    cout << "Destory Node" << endl;
  }
};

class NumNode : public Node
{
public:
  NumNode(double d) : _num(d) {}

  double Calc()
  {
    return _num;
  }

private:
  double _num;
};

class BinNode : public Node
{
public:
  BinNode(Node *left, Node *right) : _left(left), _right(right)
  {
    cout << "Create BinNode" << endl;
  }
  ~BinNode()
  {
    delete _left;
    delete _right;
    cout << "Destory BinNode " << endl;
  };

protected:
  Node *_left;
  Node *_right;
};

class AddNode : public BinNode
{
public:
  AddNode(Node *left, Node *right) : BinNode(left, right)
  {
    cout << "Create Plus Node" << endl;
  };
  ~AddNode()
  {
    cout << "Destory Plus Node" << endl;
  }
  double Calc()
  {
    return _left->Calc() + _right->Calc();
  }
};

class MultNode : public BinNode
{
public:
  MultNode(Node *left, Node *right) : BinNode(left, right)
  {
    cout << "Create Mul Node" << endl;
  };
  ~MultNode()
  {
    cout << "Destory Plus Node" << endl;
  }
  double Calc()
  {
    return _left->Calc() * _right->Calc();
  }
};