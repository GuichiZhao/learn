#include <iostream>
#include <cmath>
// #include "hashtable.h"
// #include "list.h"
// #include "stack.h"
// #include "calculator.h"
#include "parser.h"
const int maxBuf = 100;
// #include "input.h"
using namespace std;
int main()
{

  char buf[maxBuf];
  Status status;
  SymbolTable table;
  do
  {
    cout << ">" << endl;
    cin.getline(buf, maxBuf);
    Scanner scanner(buf);
    Parser parser(scanner, table);
    status = parser.Eval();

  } while (status != stQuit);
}