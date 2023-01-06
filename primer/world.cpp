#include "hello.h"
#include "world.h"
#include <iostream>

using namespace std;

void world()
{
  hello();
  cout << "world" << endl;
}