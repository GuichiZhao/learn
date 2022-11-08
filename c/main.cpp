#include <iostream>
#include <cmath>
// #include "symboltable.h"
// #include "store.h"
#include "parser.h"
const int maxBuf = 100;
using namespace std;

int main()
{

  char buf[maxBuf];
  Status status;
  SymbolTable table;

  Scanner scanner("1+2.5");
  Parser parser(scanner, table);
  status = parser.Eval();
  // do
  // {
  //   // cout << ">" << endl;
  //   // cin.getline(buf, maxBuf);
  //   Scanner scanner(buf);
  //   Parser parser(scanner, table);
  //   status = parser.Eval();

  // } while (status != stQuit);
}