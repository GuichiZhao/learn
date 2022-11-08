#include <iostream>
#include <cmath>
#include "symboltable.h"
#include "parser.h"
#include "scanner.h"
#include "funtab.h"
#include "store.h"
const int maxBuf = 100;
using namespace std;
const int maxSymbols = 100;

int main()
{

  char buf[maxBuf];
  Status status;
  SymbolTable symTab(maxSymbols);
  Store store(maxSymbols, symTab);

  Scanner scanner("1.2 +2.5");
  cout << "Start parse" << endl;
  Parser parser(scanner, store, symTab);
  status = parser.Eval();
}