#include <iostream>
#include "hashtable.h"
// #include "list.h"
#include "stack.h"
// #include "calculator.h"
// #include "input.h"
using namespace std;

int main()
{
  StringTable st;
  st.ForceAdd("hello");
  st.ForceAdd("world");
  st.ForceAdd("guichi");

  // cout << st.GetString(2) << endl;
  // cout << st.GetString(1) << endl;
  // cout << st.GetString(0) << endl;
  cout << st.Find("guichi") << endl;
  // cout << st.Find("zhao") << endl;
}