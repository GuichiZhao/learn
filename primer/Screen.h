#include <string>
using namespace std;
class Screen
{
public:
  typedef string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                   contents(ht * wd, c) {}
  char get() const // get the character at the cursor
  {
    return contents[cursor];
  }                                      // implicitlyinline
  inline char get(pos ht, pos wd) const; // explicitly inline
  Screen &move(pos r, pos c);
  Screen &set(char);
  Screen &set(pos, pos, char);

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  string contents;
  mutable size_t access_ctr;
};