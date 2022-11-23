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

  const char *inputs[] = {"cos(3.14)", "pi"};

  for (int i = 0; i < 1; i++)
  {
    const char *input = inputs[i];
    Scanner scanner(input);
    cout << "Start parse" << endl;
    Parser parser(scanner, store, funtab, symTab);
    status = parser.Eval();
  }
}