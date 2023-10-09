#include <iostream>
#include <string>
#include <math.h>

using namespace std;

extern "C"
{
  const int *int_sqrt(const int *input)
  {
    cout << "first element " << input[0] << endl;
    cout << "second element " << input[1] << endl;
    cout << "third element " << input[2] << endl;
    cout << sizeof(int) << endl;
    int result[10];

    result[0] = 00;
    result[1] = 11;
    result[2] = 22;
    result[3] = 33;
    return result;
  }
}
int main()
{
  cout << "emscription\n";
  return 0;
}