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

FunctionEntry funArr[maxIdFun] =
    {
        log,
        "log",
        log10, "log10",
        exp,
        "exp",
        sqrt,
        "sqrt",
        sin,
        "sin",
        cos,
        "cos",
        tan,
        "tan",
        sinh,
        "sinh",
        cosh,
        "cosh",
        tanh,
        "tanh",
        asin,
        "asin",
        acos,
        "acos",
        atan,
        "atan",
        0,
        ""};

int main()
{

  char buf[maxBuf];
  Status status;
  SymbolTable symTab(maxSymbols);
  FunctionTable funtab(symTab, funArr);

  Store store(maxSymbols, symTab);

  const char *inputs[] = {"1+2", "pi"};

  for (int i = 0; i < 2; i++)
  {
    const char* input=inputs[i];
    Scanner scanner(input);
    cout << "Start parse" << endl;
    Parser parser(scanner, store, symTab);
    status = parser.Eval();
  }

  // {
  //   Scanner scanner("(x=5)");
  //   cout << "Start parse" << endl;
  //   Parser parser(scanner, store, symTab);
  //   status = parser.Eval();
  // }

  // {
  //   Scanner scanner("x+8");
  //   cout << "Start parse" << endl;
  //   Parser parser(scanner, store, symTab);
  //   status = parser.Eval();
  // }
}