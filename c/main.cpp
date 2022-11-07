#include <iostream>
#include <cmath>
#include "symboltable.h"
#include "store.h"
const int maxBuf = 100;
using namespace std;

int main()
{
  SymbolTable table;
  Store store(100, table);

  cout << store.Value(0) << endl;

  // char buf[maxBuf];
  // Status status;
  // SymbolTable table;
  // do
  // {
  //   cout << ">" << endl;
  //   cin.getline(buf, maxBuf);
  //   Scanner scanner(buf);
  //   Parser parser(scanner, table);
  //   status = parser.Eval();

  // } while (status != stQuit);
}