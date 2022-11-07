#include <iostream>
#include <cmath>
#include "symboltable.h"
const int maxBuf = 100;
using namespace std;

void Log(const HTable &h)
{
  cout << "size " << h.GetSize() << endl;
}
int main()
{
  SymbolTable table(127);
  table.ForceAdd("Hello");
  table.ForceAdd("World");
  table.ForceAdd("Guichi");

  // cout << table.GetString(0) << endl;
  // cout << table.GetString(1) << endl;
  // cout << table.GetString(2) << endl;
  cout << "table.GetString(2) " << table.GetString(2) << endl;
  cout << "table.Find(Guichi,1) " << table.Find("Guichi") << endl;
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