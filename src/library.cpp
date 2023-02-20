#include "common.h"
#include "js.h"
WASM_EXPORT int add(int a, int b)
{
  return a + b;
}
WASM_EXPORT void helloWorld()
{
  // js_print_string("Hello, World!\n");
  
}

// WASM_EXPORT void add1(int size)
// {
//    new char[size];
// }

// WASM_EXPORT char* get_memory_for_char_array(int size)
// {
//    return new char[size];
// }

WASM_EXPORT int *get_memory_for_int_array(int size)
{
  return new int[size];
}
