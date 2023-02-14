#include <iostream>
#define WASM_EXPORT __attribute__((visibility("default"))) extern "C"
extern "C" int *get_memory_for_int_array(int size)
{
  return new int[size];
}

extern "C" __attribute__((visibility("default")))  int *get_memory_for_int_array11(int size)
{
  return new int[size];
}

using namespace std;

int main()
{
  cout << "WASM_EXPORT" << endl;
  get_memory_for_int_array(10);
}