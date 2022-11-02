#include <iostream>
#include "hashtable.h"
// #include "list.h"
#include "stack.h"
#include "calculator.h"
// #include "input.h"
using namespace std;

int main()
{
  Node *pNode1 = new NumNode(20.0);
  Node *pNode2 = new NumNode(-10.0);
  Node *pNode3 = new AddNode(pNode1, pNode2);
  Node *pNode4 = new NumNode(21);
  Node *pNode5 = new MultNode(pNode3, pNode4);
  cout << "Calculating the tree\n";
  // tell the root to calculate itself
  double x = pNode5->Calc();
  cout << x << endl;
  delete pNode5; // and all children
}