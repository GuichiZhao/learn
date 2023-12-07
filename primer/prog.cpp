#include <iostream>
#include <fstream>
#include <list>
#include <string.h>
#include <vector>
#include <deque>
#include <array>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <map>
#include <memory>
#include "strblob.h"

using namespace std;
struct destination;
struct connection
{
};

connection connect(destination *);
void disconnect(connection);
// close the given connection
shared_ptr<connection> make_connection(destination &d)
{
  return shared_ptr<connection>(&connect(&d), [](connection* c )
                                { disconnect(*c); });
}

void f(destination &d)
{
  // get a connection; must remember to close it when done
  connection c = connect(&d);
  // use the connection
  // if we forget to call disconnect before exiting f, there will be no way to close c
}

int main()
{
  int *pi = new int(42);
  // auto x =
  // process(pi);
  delete pi;
  cout << *pi << endl;
  return 0;
}