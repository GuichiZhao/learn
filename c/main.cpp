#include <iostream>
#include <cmath>
#include "htable.h"
const int maxBuf = 100;
using namespace std;

void Log(const HTable &h)
{
  cout << "size " << h.GetSize() << endl;
}
int main()
{
  HTable h(5);
  Log(h);
  // double (*pFun)(double x);
  // pFun=sin;

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