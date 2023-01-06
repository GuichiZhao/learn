#include <string>
#include <vector>
#include "Screen.h"
using namespace std;
class Window_mgr
{
private:
  std::vector<Screen> screens{Screen(24, 80, '')};
};