#include <stdio.h>
int *calc_sum() __attribute__((cdecl));
void view_arr(int *) __attribute__((cdecl));
void f(int a[][2]);
int main()
{

  int n = 10, sum;
  printf("%X\n", (unsigned)&sum);
  int a[3][2];
  a[0][0] = 0;
  a[0][1] = 1;
  a[1][0] = 2;
  a[1][1] = 3;
  a[2][0] = 4;
  a[2][1] = 5;

  printf("%p\n", a);
  // printf("%p\n", &a[0][0]);
  // view_arr(a);
  // view_arr(&a[0][0]);

  // printf("a[5]=%d\n", *(&a[0][0] + 5));
  // int *result = calc_sum();
  // printf("result = %d\n", result);
  // for (int i = 0; i < 100; i++)
  // {
  //   printf("%d ", *(result+i));
  // }

  // int a = -1;
  // unsigned char b = 255;
  // unsigned int x = a;
  // printf("a==b? %d\n", b);
  // asm_main();

  return 0;
}
