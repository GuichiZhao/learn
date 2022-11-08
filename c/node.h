#include <iostream>
using namespace std;

class Node
{
public:
  double virtual Calc() = 0;
  Node(){};
  virtual ~Node(){};
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