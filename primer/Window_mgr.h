#include <string>
#include <vector>
#include "Screen.h"
using namespace std;
class Window_mgr
{
  using ScreenIndex = std::vector<Screen>::size_type;

public:
  ScreenIndex addScreen(const Screen &s);

private:
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
  screens.push_back(s);
  return screens.size() - 1;
}