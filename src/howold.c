int howOld(int currentYear, int yearBorn)
{
  int retValue = -1;
  if (yearBorn <= currentYear)
  {
    retValue = currentYear - yearBorn;
  }
  return retValue;
}

int addArray()
{
  int retValue = 0;
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 10; i++)
  {
    retValue += array[i];
  }
  return retValue;
}
// clang --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all howold.c -o howold.wasm