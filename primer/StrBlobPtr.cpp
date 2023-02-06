#include <memory>
#include <vector>
#include "StrBlobPtr.h"

using namespace std;
shared_ptr<vector<string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
  auto ret = wptr.lock();
  // is the vector still around?
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");
  if (i >= ret->size())
    throw std::out_of_range(msg);
  return ret; // otherwise, return a shared_ptr to the vector
}

std::string &StrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr]; // (*p) is the vector to which this object points
}

// preﬁx: return a reference to the incremented object
StrBlobPtr &StrBlobPtr::incr()
{
  // if curr already points past the end of the container, can’t increment it
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  // advance the current state
  return *this;
}