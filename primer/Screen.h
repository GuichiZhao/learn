#ifndef SCREEN_H
// we're here only if SALESITEM_H has not yet been defined
#define SCREEN_H

#include <string>
#include <iostream>
class Screen
{
  friend class Window_mgr11;

public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                   contents(ht * wd, c) {}
  char get() const // get the character at the cursor
  {
    return contents[cursor];
  }
  inline char get(pos ht, pos wd) const;
  Screen &display(std::ostream &os)
  {
    do_display(os);
    return *this;
  }
  const Screen &display(std::ostream &os) const
  {
    do_display(os);
    return *this;
  }
  Screen &move(pos r, pos c);
  Screen &set(char);
  Screen &set(pos, pos, char);

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  mutable size_t access_ctr;
  void do_display(std::ostream &os) const
  {
    for (pos r = 0; r < height; r++)
    {
      for (pos c = 0; c < width; c++)
      {
        os << contents[r * width + c];
      }
      os << std::endl;
    }
    os << std::endl;
  }
};

inline Screen &Screen::move(pos r, pos c)
{
  pos row = r * width;
  cursor = row + c;
  return *this;
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
#endif