#include <iostream>
#include "parser.h"
#include "stringtable.h"

using namespace std;

const int maxBuf = 100;
int main()
{
  HTable table(13);
  // table=5;
  // cout <<table.size()<<endl;
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