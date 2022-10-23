#include <iostream>
#include "parser.h"
#include "stringtable.h"

using namespace std;

const int maxBuf = 100;

int main()
{
  StringTable strTable;
  strTable.ForceAdd("One");
  strTable.ForceAdd("Two");
  strTable.ForceAdd("Three");
  int id = strTable.Find("One");
  cout << "One at " << id << endl;
  id = strTable.Find("Two");
  cout << "Two at " << id << endl;
  id = strTable.Find("Three");
  cout << "Three at " << id << endl;
  id = strTable.Find("Minus one");
  cout << "Minus one at " << id << endl;
  cout << "String 0 is " << strTable.GetString(0) << endl;
  cout << "String 1 is " << strTable.GetString(1) << endl;
  cout << "String 2 is " << strTable.GetString(2) << endl;
}
// int main()
// {
//   char buf[maxBuf];
//   Status status;
//   SymbolTable symTab;
//   do
//   {
//     cout << "> "; // prompt
//     cin.getline(buf, maxBuf);
//     Scanner scanner(buf);
//     Parser parser(scanner, symTab);
//     status = parser.Parse();
//   } while (status != stQuit);
// }