#include "common.h"
#include "js.h"
WASM_EXPORT int add(int a, int b)
{
  return a + b;
}
WASM_EXPORT void print(const char *str)
{
  js_print_string(str);
}
WASM_EXPORT void helloWorld()
{
  js_print_string("Hello, World!\n");
}
