#include "Screen.h"
inline Screen &Screen::move(pos r, pos c)
{
  pos row = r * width;
  cursor = row + c;
  return *this;
}
char Screen::get(pos r, pos c) const // declared as inline in the class
{
  pos row = r * width;      // compute row location
  return contents[row + c]; // return character at the given column
}
inline Screen &Screen::set(char c)
{
  contents[cursor] = c; // set the new value at the current cursor location
  return *this;         // return this object as an lvalue
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
  contents[r * width + col] = ch; // set specified location to given value
  return *this;                   // return this object as an lvalue
}