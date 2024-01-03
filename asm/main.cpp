#include <iostream>
using namespace std;

int main()
{
  // unsigned short word = 0x1234;
  // cout << (((char)((&word)[0])) == 0x34) << endl;
  int x = 0x1122ff11;
  short int y = x;
  cout << y << endl;
  // printf("%d\n", y);
  return 0;
}