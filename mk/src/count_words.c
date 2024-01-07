#include <stdio.h>
#include <lexer.h>
#include <counter.h>
void counter(int counts[4])
{
  while (yylex())
    ;
  counts[0] = fee_count;
  counts[1] = fie_count;
  counts[2] = foe_count;
  counts[3] = fum_count;
}
int main(int argc, char **argv)
{
  yylex();
  printf("%d %d %d %d\n", fee_count, fie_count, foe_count, fum_count);
  return 0;
}