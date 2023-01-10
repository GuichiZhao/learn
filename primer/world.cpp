#include "hello.h"
#include "world.h"
#include <iostream>

using namespace std;

void world()
{
  Hello h;
  int i = h.hello();
  cout << i << endl;
}